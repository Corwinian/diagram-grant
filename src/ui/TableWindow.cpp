#include "TableWindow.h"
#include "ui_TableWindow.h"

#include "FilterWidget.h"
#include  "CardWiew.h"


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

    static_cast<FilterWidget *>(ui->FilterLayout->itemAt(0)->widget())->on_checkBox_clicked(false);

    model.setTable(mTable.name());

    for (int i=0; i < table.colums().size(); ++i)
    {
        if(table.colums()[i].isForeingKey())
        {
            model.setRelation(i, table.colums()[i].link());

        }
    }

    model.select();

    ui->tableView->setModel(&model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->show();
}

QList <TableWindow::TLinkValues> TableWindow::getLinkValues(QString columnName) const
{
  auto column = [mTable](QString name)  -> Table::Column {  for (auto i : mTable.colums())	if (i.name() == name) return i;	}(columnName);


    QSqlQuery query( QString("Select %1, %2 from %3")
                        .arg(column.link().displayColumn())
                        .arg(column.link().indexColumn())
                        .arg(column.link().tableName()),
                     model.database());

    query.exec();

    QList <TableWindow::TLinkValues> list;

    while(query.next())
    {
        list << TableWindow::TLinkValues(query.value(0).toString(), query.value(1).toString());
    }

    return list;
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
    FilterWidget *filterWidget =  static_cast<FilterWidget *> (ui->FilterLayout->itemAt(0)->widget());
    FilterWidget::FilteringParams param	= filterWidget->getParams();


    QString filter = filterWidget->isActive() ? QString("%1 %2 %3").arg(param.column).arg(param.op).arg(param.param)
                        : QString("");

    model.setFilter(filter);
    model.select();
    ui->tableView->show();
}

void TableWindow::on_btnAddRow_clicked()
{
    CardView * card = new CardView(table(), model);
    card->show();
}

void TableWindow::on_tableView_doubleClicked(const QModelIndex &index)
{


    CardView * card = new CardView(table(), model, index.row());
    card->show();
}
