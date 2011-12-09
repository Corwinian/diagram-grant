#include "TableWindow.h"
#include "ui_TableWindow.h"

#include "FilterWidget.h"

TableWindow::TableWindow(Table table,QSqlDatabase *db, QWidget *parent) :
	QDialog(parent),
	mTable(table),
	model(this, *db),
	selectRow(-1),
	//selection(&model),
	ui(new Ui::TableWindow)
{
	ui->setupUi(this);

	on_btnAddFiltr_clicked();

	qDebug()<<model.database().isOpen();
	model.setTable(mTable.name());

	static_cast<FilterWidget *>(ui->FilterLayout->itemAt(0)->widget())->on_checkBox_clicked(false);
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

void TableWindow::on_btnDelRow_clicked()
{
	model.removeRow(selectRow);
	model.submitAll();
}

void TableWindow::on_btnOk_clicked()
{
	if(model.submitAll())
	{
		model.database().commit();
	}
	else
	{
		model.database().rollback();
	}
}

void TableWindow::on_btnCansel_clicked()
{
	model.database().rollback();
}



void TableWindow::on_btnAddFiltr_clicked()
{
	FilterWidget *it = new FilterWidget(table().colums(), this);
	ui->FilterLayout->insertWidget(ui->FilterLayout->count()-1, it);
	connect(it, SIGNAL(updateFilter()), SLOT(startFilter()));
}

void TableWindow::startFilter()
{
	FilterWidget::FilteringParams param
			= static_cast<FilterWidget *> (ui->FilterLayout->itemAt(0)->widget())->getParams();

	model.setFilter(QString("%1 %2 %3").arg(param.column).arg(param.op).arg(param.param));
	model.select();
	ui->tableView->show();
}
