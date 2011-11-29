#include "TableWindow.h"
#include "ui_TableWindow.h"

TableWindow::TableWindow(QString table,QSqlDatabase *db, QWidget *parent) :
	QDialog(parent),
	mTable(table),
	ui(new Ui::TableWindow),
	model(this, *db)
{
	ui->setupUi(this);

	qDebug()<<model.database().isOpen();
	model.setTable(mTable);

	model.select();

	ui->tableView->setModel(&model);
	ui->tableView->show();
}

TableWindow::~TableWindow()
{
	delete ui;
}
