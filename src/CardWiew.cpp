#include "CardWiew.h"
#include "ui_CardWiew.h"

CardView::CardView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardView)
{
    ui->setupUi(this);
}

CardView::~CardView()
{
    delete ui;
}
