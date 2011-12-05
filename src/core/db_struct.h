#ifndef DB_STRUCT_H
#define DB_STRUCT_H

#include <QString>
#include <QList>
#include <QMap>

class Table
{
public:
	class Collum
	{
	public:
		struct ForeingLink
		{
			const QString tableName; //подумать могет лучше сделать ссылку именно на саму таблицу
			const QString columnName;

			ForeingLink(QString iTableName, QString iColumnName)
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
		Column(QString name, QString caption, TColumnType type, QList<QString> avelebleValues =0);

		QString name() const { return mName;}
		QString caption() const { return mCaption;}
		TColumnType columnType() const { return mColumnType; }
		bool isForeingKey() const { return mIsForeingKey;}
		const ForeingLink &llink() const {return mLink;}
		const QList<QString> avelebleValues()  const { return mAvelebleValues; }

	private:
		QString mName;
		QString mCaption;
		TColumnType mColumnType;
		bool mIsForeingKey;
		ForeingLink mLlink;
		QList<QString> mAvelebleValues; //для полей котрые могут принимать заранее определенный набор ззначений, допустим у пользователя админ или не админ
};

public:
	typedef QMap<QString, Collum>  TColumns;

	Table(QString name, QString mCaption, TColumns colums);

	QString name() const { return  mName;}
	QString caption() const { return  mCaption;}
	TColumns colums() const { return  mColums;}

private:
	QString mName;
	QString mCaption;

	TColumns mColums;

};

#endif // DB_STRUCT_H
