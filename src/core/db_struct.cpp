
#include "core/db_struct.h"
#include <QString>

Table::Table::Column::Column(QString name, QString caption, TColumnType type, int index)
	:mName(name), mCaption(caption), mColumnType(type), mIndex(index)
{

}

Table::Column::Column(QString name, QString caption, TColumnType type, QSqlRelation link, int index)
	:mName(name), mCaption(caption), mColumnType(type), mLink(link), mIndex(index), mIsForeingKey(true)
{

}


Table::Table(QString name, QString caption, TColumns colums)
	:mName(name), mCaption(caption),  mColums (colums)
{

}
