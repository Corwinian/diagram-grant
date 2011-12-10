#ifndef DB_STRUCT_H
#define DB_STRUCT_H

#include <QString>
#include <QList>
#include <QMap>

#include <QSqlRelation>

class Table
{
public:
	class Column
	{
	public:
		enum TColumnType
		{
			TCOLUMN_TYPE_NONE,
			TCOLUMN_TYPE_INT,
			TCOLUMN_TYPE_BOOL,
			TCOLUMN_TYPE_DATE,
			TCOLUMN_TYPE_STRING,
		};

	public:
		Column(QString name, QString caption, TColumnType type, QSqlRelation link, int index =0);
		Column(QString name, QString caption, TColumnType type, QList<QString> avelebleValues);

		Column(QString name="", QString caption="", TColumnType type=TCOLUMN_TYPE_NONE, int index = 0);

		//Column(const Column &a)

		QString name() const { return mName;}
		QString caption() const { return mCaption;}
		TColumnType columnType() const { return mColumnType; }
		bool isForeingKey() const { return mIsForeingKey;}
		const QSqlRelation &link() const {return mLink;}
		const QList<QString> avelebleValues()  const { return mAvelebleValues; }

		int index() const {return mIndex;}
	private:
		QString mName;
		QString mCaption;
		TColumnType mColumnType;
		bool mIsForeingKey;
		QSqlRelation mLink;
		QList<QString> mAvelebleValues; //для полей котрые могут принимать заранее определенный набор ззначений, допустим у пользователя админ или не админ
		int mIndex;
};

public:
	typedef QMap<QString, Column>  TColumns;

	Table(QString name="", QString mCaption="", TColumns colums=TColumns());

	QString name() const { return  mName;}
	QString caption() const { return  mCaption;}
	TColumns colums() const { return  mColums;}

private:
	QString mName;
	QString mCaption;

	TColumns mColums;
};

typedef QMap<QString, Table> TTableList;

#endif // DB_STRUCT_H
