
#include "core/db_struct.h"
#include <QString>

Table::Table::Column::Column(QString name, QString caption, TColumnType type, bool isPrimaryKey, bool isAutoInc)
	:mName(name), mCaption(caption), mColumnType(type), mIsAutoInc(isAutoInc), mIsForeingKey(false), mIsPrimaryKey(isPrimaryKey)
{

}

Table::Column::Column(QString name, QString caption, TColumnType type, QSqlRelation link, bool isPrimaryKey)
	:mName(name), mCaption(caption), mColumnType(type), mLink(link), mIsAutoInc(false),
		mIsForeingKey(true), mIsPrimaryKey(isPrimaryKey)
{
}


Table::Table(QString name, QString caption, TColumns colums)
	:mName(name), mCaption(caption),  mColums (colums)
{

}
