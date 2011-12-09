#include "FilterWidget.h"
#include "ui_FilterWidget.h"
#include <QDebug>


FilterWidget::FilterWidget(Table::TColumns columns, QWidget *parent) :
	QFrame(parent),
	mColumns(columns),
	ui(new Ui::FilterWidget)
{
	ui->setupUi(this);

	for (auto column : mColumns)
	{
		ui->cbColumns->addItem(column.caption(), column.name());
	}

	mFilParam.column = ui->cbColumns->itemData(0).toString();
	mFilParam.op = ui->cbOp->itemText(0);
}

FilterWidget::~FilterWidget()
{
	delete ui;
}

void FilterWidget::on_cbColumns_currentIndexChanged(int index)
{
	mFilParam.column = ui->cbColumns->itemData(index).toString();
	emit updateFilter();
}

void FilterWidget::on_coOp_currentIndexChanged(int index)
{
	mFilParam.op = ui->cbOp->itemText(index);
	emit updateFilter();
}

void FilterWidget::on_lineEdit_lostFocus()
{
	mFilParam.param = ui->lineEdit->text();
	emit updateFilter();
}

void FilterWidget::on_lineEdit_editingFinished()
{
	on_lineEdit_lostFocus();
}

void FilterWidget::on_checkBox_clicked(bool checked)
{
	ui->cbColumns->setEnabled(checked);
	ui->cbOp->setEnabled(checked);
	ui->lineEdit->setEnabled(checked);
	emit updateFilter();
}
