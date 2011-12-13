#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

#include <QSqlQuery>

#include "CardWiew.h"
#include "ui_CardWiew.h"



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

QWidget *CardView::createSimpleItem(Table::Column::TColumnType type)
{
	switch(type)
	{
		case Table::Column::TCOLUMN_TYPE_BOOL:
		case Table::Column::TCOLUMN_TYPE_DATE:
		case Table::Column::TCOLUMN_TYPE_INT:
		case Table::Column::TCOLUMN_TYPE_STRING:
			return new QLineEdit(this);
	}
}

QWidget *CardView::createForeingLinkItem(Table::Column column)
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
	}

	return box;
}


CardView::~CardView()
{
	delete ui;
}
