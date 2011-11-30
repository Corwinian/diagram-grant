#include "TableWindow.h"
#include "ui_TableWindow.h"

TableWindow::TableWindow(QString table,QSqlDatabase *db, QWidget *parent) :
	QDialog(parent),
	mTable(table),
	model(this, *db),
	selectRow(-1),
	//selection(&model),
	ui(new Ui::TableWindow)
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

void TableWindow::selectItem(int row)
{
	if (row < 0)
		row = 0;
	if (row > model.query().size()-1)
		row = model.query().size()-1;

	selectRow = row;
	ui->tableView->selectRow(row);
	ui->ePos->setText(QString("%1 из %2").arg(row +1).arg(model.query().size()));
}


void TableWindow::on_tableView_clicked(const QModelIndex &index)
{
  selectItem(index.row());
}
