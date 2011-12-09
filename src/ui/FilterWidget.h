#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QFrame>

#include "core/db_struct.h"

namespace Ui {
	class FilterWidget;
}

class FilterWidget : public QFrame
{
	Q_OBJECT

public:
	struct FilteringParams
	{
		QString column, op, param;
	};

public:
	explicit FilterWidget(Table::TColumns columns, QWidget *parent = 0);
	~FilterWidget();

	FilteringParams getParams() const {return mFilParam;}

signals:
	void updateFilter();

private slots:
	void on_cbColumns_currentIndexChanged(int index);
	void on_coOp_currentIndexChanged(int index);

	void on_lineEdit_lostFocus();

	void on_lineEdit_editingFinished();

private:

	Table::TColumns mColumns;
	Ui::FilterWidget *ui;
	FilteringParams mFilParam;

};

#endif // FILTERWIDGET_H
