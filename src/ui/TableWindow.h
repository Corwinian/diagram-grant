#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QDialog>

#include <QtSql>

#include "core/db_struct.h"

namespace Ui {
	class TableWindow;
}

class TableWindow : public QDialog
{
	Q_OBJECT

public:
	explicit TableWindow(Table table, QSqlDatabase *db, QWidget *parent = 0);

	void view();

	Table table() const { return mTable;}

	~TableWindow();

private slots:
	void on_btnStartt_clicked() {selectItem(0); }

	void on_btnEnd_clicked() {selectItem(model.query().size()-1); }

	void on_btnPrev_clicked() {selectItem(selectRow - 1);}

	void on_btnNext_clicked() {selectItem(selectRow + 1);}

	void on_tableView_clicked(const QModelIndex &index);

	void on_btnDelRow_clicked();

	void on_btnOk_clicked();

	void on_btnCansel_clicked();

private:
	Ui::TableWindow *ui;

	QSqlTableModel  model;
	//QItemSelectionModel selection;

	int selectRow;

	Table mTable;

	void selectItem(int row);
};

#endif // TABLEWINDOW_H
