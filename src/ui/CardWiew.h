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
	explicit CardView(Table table, QWidget *parent = 0);

	~CardView();

private:
    Ui::CardView *ui;

	QSqlRelationalTableModel model;

	int selectRow;

	Table mTable;

};

#endif // CARDWIEW_H
