#include <QDebug>

#include "FilterWidget.h"
#include "ui_FilterWidget.h"

#include "TableWindow.h"

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

	on_cbColumns_currentIndexChanged(0);

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

	if (mColumns[index].isForeingKey())
	{
		ui->cbValues->clear();

		for(auto value : static_cast<TableWindow *>(this->parent())->getLinkValues(mFilParam.column))
		{
			ui->cbValues->addItem(value.first, value.second);
		}

		ui->lineEdit->hide();
		ui->cbValues->show();
		mFilParam.param = ui->cbValues->itemData(ui->cbValues->currentIndex()).toString();
	}
	else
	{
		ui->lineEdit->setText("");
		mFilParam.param = ui->lineEdit->text();

		ui->lineEdit->show();
		ui->cbValues->hide();
	}

	emit updateFilter();
}

void FilterWidget::on_cbOp_currentIndexChanged(int index)
{
	mFilParam.op = ui->cbOp->itemText(index);
	emit updateFilter();
}

void FilterWidget::on_lineEdit_textEdited(const QString &arg1)
{
	mFilParam.param = ui->lineEdit->text();
	emit updateFilter();
}

void FilterWidget::on_cbValues_currentIndexChanged(int index)
{
	mFilParam.param = ui->cbValues->itemData(index).toString();
	emit updateFilter();
}

void FilterWidget::on_checkBox_clicked(bool checked)
{
	ui->cbColumns->setEnabled(checked);
	ui->cbOp->setEnabled(checked);
	ui->cbValues->setEnabled(checked);
	ui->lineEdit->setEnabled(checked);
	emit updateFilter();
}


