#ifndef DB_STRUCT_H
#define DB_STRUCT_H

#include <QString>
#include <QList>
#include <QMap>

class Table
{
public:
	class Column
	{
	public:
		struct ForeingLink
		{
			QString tableName; //подумать могет лучше сделать ссылку именно на саму таблицу
			QString columnName;

			ForeingLink(QString iTableName="", QString iColumnName="")
				:tableName(iTableName), columnName(iColumnName){}

		};

		enum TColumnType
		{
			TCOLUMN_TYPE_INT,
			TCOLUMN_TYPE_DATE,
			TCOLUMN_TYPE_STRING,
		};

	public:
		Column(QString name, QString caption, TColumnType type, ForeingLink llink);
		Column(QString name, QString caption, TColumnType type, QList<QString> avelebleValues);
		Column(QString name, QString caption, TColumnType type);

		//Column(const Column &a)

		QString name() const { return mName;}
		QString caption() const { return mCaption;}
		TColumnType columnType() const { return mColumnType; }
		bool isForeingKey() const { return mIsForeingKey;}
		const ForeingLink &link() const {return mLink;}
		const QList<QString> avelebleValues()  const { return mAvelebleValues; }

	private:
		QString mName;
		QString mCaption;
		TColumnType mColumnType;
		bool mIsForeingKey;
		ForeingLink mLink;
		QList<QString> mAvelebleValues; //для полей котрые могут принимать заранее определенный набор ззначений, допустим у пользователя админ или не админ
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
