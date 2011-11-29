#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QDialog>

#include <QtSql>

namespace Ui {
	class TableWindow;
}

class TableWindow : public QDialog
{
	Q_OBJECT

public:
	explicit TableWindow(QString table, QSqlDatabase *db, QWidget *parent = 0);

	void view();

	QString table() const { return mTable;}

	~TableWindow();

private:
	Ui::TableWindow *ui;

	QSqlTableModel  model;

	QString	mTable;
};

#endif // TABLEWINDOW_H
