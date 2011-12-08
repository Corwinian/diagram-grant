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
	mFilParam.op = ui->cbColumns->itemData(index).toString();
	emit updateFilter();
}
