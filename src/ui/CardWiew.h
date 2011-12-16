#ifndef CARDWIEW_H
#define CARDWIEW_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>

#include "core/db_struct.h"

namespace Ui {
    class CardView;
}

class CardView : public QDialog
{
    Q_OBJECT

public:
   // explicit CardView(Table table, const QSqlDatabase &db, QWidget *parent = 0);

   explicit CardView(Table table, QSqlRelationalTableModel &model, int row =-1);

    ~CardView();
private slots:
    void on_buttonBox_accepted();

private:
    void loadItems();

    QWidget *createSimpleItem(Table::Column::TColumnType type, QVariant value = QVariant());
    QWidget *createForeingLinkItem(Table::Column column, QVariant value = QVariant());

    QVariant getValue(QWidget *widget, Table::Column column);

    Ui::CardView *ui;

    QSqlRelationalTableModel &mModel;

    Table mTable;

    int mRow;
    bool isInsert;
};

#endif // CARDWIEW_H
