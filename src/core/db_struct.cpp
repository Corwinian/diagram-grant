
#include "core/db_struct.h"
#include <QString>

Table::Table::Column::Column(QString name, QString caption, TColumnType type)
	:mName(name), mCaption(caption), mColumnType(type)
{

}



Table::Table(QString name, QString caption, TColumns colums)
	:mName(name), mCaption(caption),  mColums (colums)
{

}
