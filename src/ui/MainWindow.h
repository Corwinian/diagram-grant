#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "core/db_struct.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	const TTableList tables() const { return mTables;}

private slots:
	void on_mTablesTriggered();

private:
	Ui::MainWindow *ui;
	TTableList mTables;
};

#endif // MAINWINDOW_H
