#include "CardWiew.h"
#include "ui_CardWiew.h"

CardView::CardView(Table table, QWidget *parent = 0) :
	QDialog(parent),
	ui(new Ui::CardView),
	mTable(table)
{
	 ui->setupUi(this);
}

CardView::~CardView()
{
	delete ui;
}
