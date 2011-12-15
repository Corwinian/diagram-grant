
#include "core/db_struct.h"
#include <QString>

Table::Table::Column::Column(QString name, QString caption, TColumnType type, bool isAutoInc)
	:mName(name), mCaption(caption), mColumnType(type), mIsAutoInc(isAutoInc), mIsForeingKey(false)
{

}

Table::Column::Column(QString name, QString caption, TColumnType type, QSqlRelation link, bool isAutoInc)
	:mName(name), mCaption(caption), mColumnType(type), mLink(link), mIsAutoInc(isAutoInc), mIsForeingKey(true)
{
}


Table::Table(QString name, QString caption, TColumns colums)
	:mName(name), mCaption(caption),  mColums (colums)
{

}
