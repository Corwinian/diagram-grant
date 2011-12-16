#ifndef DB_STRUCT_H
#define DB_STRUCT_H

#include <QString>
#include <QList>
#include <QVector>
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
		Column(QString name, QString caption, TColumnType type, QList<QString> avelebleValues);

		Column(QString name, QString caption, TColumnType type, QSqlRelation link, bool isPrimaryKey = false);
		Column(QString name="", QString caption="", TColumnType type=TCOLUMN_TYPE_NONE,	bool isPrimaryKey = false, bool isAutoInc = false);

		//Column(const Column &a)

		QString name() const { return mName;}
		QString caption() const { return mCaption;}
		TColumnType columnType() const { return mColumnType; }
		bool isForeingKey() const { return mIsForeingKey;}
		const QSqlRelation &link() const {return mLink;}
		const QList<QString> avelebleValues()  const { return mAvelebleValues; }

		bool isPrimaryKey() const { return mIsPrimaryKey;}
		bool isAutoInc() const { return mIsAutoInc;}
	private:
		QString mName;
		QString mCaption;
		TColumnType mColumnType;
		bool mIsForeingKey;
		QSqlRelation mLink;
		QList<QString> mAvelebleValues; //для полей котрые могут принимать заранее определенный набор ззначений, допустим у пользователя админ или не админ
		bool mIsPrimaryKey;
		bool mIsAutoInc;
};

public:
	//typedef QMap<QString, Column>  TColumns;
	typedef QVector<Column>  TColumns;

	Table(QString name="", QString mCaption="", TColumns colums=TColumns());

	QString name() const { return mName;}
	QString caption() const { return mCaption;}
	TColumns colums() const { return mColums;}


private:
	QString mName;
	QString mCaption;

	TColumns mColums;
};

typedef QMap<QString, Table> TTableList;

#endif // DB_STRUCT_H
