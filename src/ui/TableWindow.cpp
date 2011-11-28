#include "TableWindow.h"
#include "ui_TableWindow.h"

TableWindow::TableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
}

TableWindow::~TableWindow()
{
    delete ui;
}
