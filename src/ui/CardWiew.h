#ifndef CARDWIEW_H
#define CARDWIEW_H

#include <QDialog>
#include <QSqlRelationalTableModel>

#include "core/db_struct.h"

namespace Ui {
    class CardView;
}

class CardView : public QDialog
{
    Q_OBJECT

public:
   // explicit CardView(Table table, const QSqlDatabase &db, QWidget *parent = 0);

     explicit CardView(Table table, QSqlRelationalTableModel &model, QWidget *parent = 0);
    ~CardView();
private slots:
    void on_buttonBox_accepted();

private:
    QWidget *createSimpleItem(Table::Column::TColumnType type);
    QWidget *createForeingLinkItem(Table::Column column);

    QVariant getValue(QWidget *widget, Table::Column column);

    Ui::CardView *ui;

    QSqlRelationalTableModel &mModel;

    Table mTable;

};

#endif // CARDWIEW_H
