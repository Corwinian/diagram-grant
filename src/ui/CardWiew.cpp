#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QComboBox>

#include <QSqlQuery>
#include <QDate>
#include <QSqlError>
#include <QSqlIndex>

#include <qalgorithms.h>

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

CardView::CardView(Table table, QSqlRelationalTableModel &model, int row)
	:ui(new Ui::CardView),
	mTable(table),
	mModel(model),
	mRow(row),
	isInsert(row == -1)
{
	ui->setupUi(this);



	for (int i=0; i < mTable.colums().size(); ++i)
	{
		auto column = mTable.colums()[i];

		QWidget* widget = column.isForeingKey()
						? createForeingLinkItem(column, mModel.data(mModel.index(row, i)))
						: createSimpleItem(column.columnType(), mModel.data(mModel.index(row, i)));

		if(!isInsert && column.isPrimaryKey())
			widget->setEnabled(false);

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
	if(isInsert)
		  mModel.insertRows(0, 1);

   for (int i =0; i < ui->formLayout->rowCount(); ++i)
   {
		auto column = mTable.colums()[i];

		mModel.setData(mModel.index(0, i),
					   getValue(ui->formLayout->itemAt(i, QFormLayout::FieldRole)->widget(), mTable.colums()[i]));
   }


   mModel.submitAll() ? mModel.database().commit() : mModel.database().rollback();
}
