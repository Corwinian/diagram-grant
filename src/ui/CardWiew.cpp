#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>

#include <QSqlQuery>
#include <QDate>


#include "CardWiew.h"
#include "ui_CardWiew.h"


#include <QDebug>
/*
CardView::CardView(Table table, const QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardView),
    mTable(table),
    mModel(this, db)
{
     ui->setupUi(this);

     for (auto column : table.colums())
    {
         ui->formLayout->addRow(column.caption(),  column.isForeingKey()  ?
                                       createForeingLinkItem(column) : createSimpleItem(column.columnType())) ;
    }
}
*/

CardView::CardView(Table table, QSqlRelationalTableModel &model, QSqlRecord record)
    :ui(new Ui::CardView),
    mTable(table),
    mModel(model)
{
    ui->setupUi(this);

    for (auto column : mTable.colums())
    {
    #warning понять что значит цифра 2 (ну просто она в названии колонки есть а логичного объяснения не нашел)
        QWidget* widget = column.isForeingKey()
                        ? createForeingLinkItem(column, record.value(QString("%1_%2_2")
                                    .arg(column.link().tableName()).arg(column.link().displayColumn())))
                        : createSimpleItem(column.columnType(), record.value(column.name()));

        if(column.isAutoInc())
            widget->setEnabled(false);

        ui->formLayout->addRow(column.caption(), widget);
    }
}

QWidget *CardView::createSimpleItem(Table::Column::TColumnType type, QVariant value)
{
    switch(type)
    {
        case Table::Column::TCOLUMN_TYPE_DATE:
            return new QDateEdit(value.toDate(), this);
        case Table::Column::TCOLUMN_TYPE_BOOL:
        case Table::Column::TCOLUMN_TYPE_INT:
        case Table::Column::TCOLUMN_TYPE_STRING:
            return new QLineEdit(value.toString(), this);
    }
}

QWidget *CardView::createForeingLinkItem(Table::Column column, QVariant value)
{
    QComboBox *box = new QComboBox(this);

    QSqlQuery query( QString("Select %1, %2 from %3")
                        .arg(column.link().displayColumn())
                        .arg(column.link().indexColumn())
                        .arg(column.link().tableName()),
                     mModel.database());

    query.exec();

    while(query.next())
    {
        box->addItem(query.value(0).toString(), query.value(1).toString());
        if (query.value(0).toString() ==  value.toString())
            box->setCurrentIndex(box->count()-1);
    }

    return box;
}


CardView::~CardView()
{
    delete ui;
}

QVariant CardView::getValue(QWidget *widget, Table::Column column)
{
    if (column.isForeingKey())
        return	static_cast <QComboBox *>(widget)->itemData(static_cast <QComboBox *>(widget)->currentIndex());

    switch(column.columnType())
    {
        case Table::Column::TCOLUMN_TYPE_DATE:
            return static_cast <QDateEdit *>(widget)->date();
        case Table::Column::TCOLUMN_TYPE_BOOL:
        case Table::Column::TCOLUMN_TYPE_INT:
            return	static_cast <QLineEdit *>(widget)->text().toInt();
        case Table::Column::TCOLUMN_TYPE_STRING:
            return	static_cast <QLineEdit *>(widget)->text();
    }
}


void CardView::on_buttonBox_accepted()
{
    int row = 0;
    mModel.insertRows(row, 1);

    for (int i =0; i < ui->formLayout->rowCount(); ++i)
    {
        mModel.setData(mModel.index(row, i),
                       getValue(ui->formLayout->itemAt(i, QFormLayout::FieldRole)->widget(), mTable.colums()[i]));
    }

    mModel.submitAll() ? mModel.database().commit() : mModel.database().rollback();
}
