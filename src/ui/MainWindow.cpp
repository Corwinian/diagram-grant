#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <qdebug.h>

#include  "TableWindow.h"

const Table getCompany()
{

		auto id = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT, true);
		auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

		Table::TColumns colums;

		//colums .insert(QString("Id"), id);
		//colums.insert(QString("name"), name);

		colums.append(id);
		colums.append(name);

		 return Table ("Company", "Company", colums);
}

const Table getProjecty()
{
		auto id = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
		auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);
		auto dateStart = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
		auto supposeDateFinish = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

		auto dateFinish = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
		auto description = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

		Table::TColumns colums;
/*
		colums.insert(QString("Id"), id);
		colums.insert(QString("name"), name);
		colums.insert(QString("name"), name);
		colums.insert(QString("name"), name);
		colums.insert(QString("name"), name);
		colums.insert(QString("name"), name);
		*/

		/*
  CREATE  TABLE `Project` (
	`id` INT AUTO_INCREMENT PRIMARY KEY,
	`name` VARCHAR(45) NOT NULL,
	`dateStart` DATETIME NOT NULL,

	`supposeDateFinish` DATETIME NOT NULL
		  CHECK (`supposeDateFinish` > `dateStart`),

	`dateFinish` DATETIME
		  CHECK (`dateFinish` > `dateStart`),

	`description` VARCHAR(1000) NULL
  )
*/

		return Table ("Developers", "Developers", colums);
}


const Table getDeveloper()
{
		auto login = Table::Column("login","login", Table::Column::TCOLUMN_TYPE_STRING);
		auto pass = Table::Column("pass","pass", Table::Column::TCOLUMN_TYPE_STRING);
		auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

		auto isAdmin = Table::Column("isAdmin" ,"isAdmin", Table::Column::TCOLUMN_TYPE_BOOL);
		auto company = Table::Column("company","company",
						Table::Column::TCOLUMN_TYPE_INT,
						QSqlRelation("Company", "id", "name"));


		Table::TColumns colums;
/*
		colums.insert(QString("login"), login);
		colums.insert(QString("pass"), pass);
		colums.insert(QString("name"), name);
		colums.insert(QString("isAdmin"), isAdmin);
		colums.insert(QString("company"), company);
		*/

		colums.append(login);
		colums.append(pass);
		colums.append(name);
		colums.append(isAdmin);
		colums.append(company);


		return Table ("Developer", "Developer", colums);

}

const Table getContact()
{

/*	CREATE  TABLE `Contract` (
	  `id` INT AUTO_INCREMENT PRIMARY KEY,
	  `date` DATETIME NULL,
	  `isRunning` BOOL NULL DEFAULT 1,
	  `company` INT NOT NULL,
	  `project` INT NOT NULL,

	  FOREIGN KEY (`company`) REFERENCES `Company`(id),
	  FOREIGN KEY (`project`) REFERENCES `Project`(id)
	);
	*/

	auto id = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);
	auto dateStart = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto supposeDateFinish = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	auto dateFinish = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto description = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	Table::TColumns colums;

	/*
	colums.insert(QString("Id"), id);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	*/

	return Table  ("Company", "Company", colums);

}

const Table getTask()
{
/*	CREATE  TABLE `Task` (
	  `id` INT AUTO_INCREMENT PRIMARY KEY,
	  `isOpen` BOOL NULL DEFAULT 1,
	  `name` VARCHAR(45) NOT NULL,
	  `description` VARCHAR(10000) NULL,
	  `workTime` INT NOT NULL,
	  `project` INT NOT NULL,

	  FOREIGN KEY (`project`) REFERENCES `Project`(id)
	 );
*/
	auto id = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);
	auto dateStart = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto supposeDateFinish = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	auto dateFinish = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto description = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	Table::TColumns colums;

	/*colums.insert(QString("Id"), id);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	*/

	return Table  ("Company", "Company", colums);
}

const Table getWorkReport()
{



/*
CREATE  TABLE `WorkReport` (
  `id` INT AUTO_INCREMENT PRIMARY KEY,
  `dateTimeStart` DATETIME NOT NULL,
  `dateStartFinish` DATETIME NULL,
  `workDescription` VARCHAR(1000) NOT NULL,
  `task` INT NOT NULL,
  `developer` VARCHAR(10) NOT NULL,

  FOREIGN KEY (`developer`) REFERENCES `Developer`(`login`),
  FOREIGN KEY (`task`) REFERENCES `Task`(id)
);
*/
	auto id = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);
	auto dateStart = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto supposeDateFinish = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	auto dateFinish = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto description = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	Table::TColumns colums;

	/*colums.insert(QString("Id"), id);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	*/

	return Table  ("Company", "Company", colums);
}
const Table getDistribDevelopers()
{

	/*
CREATE  TABLE `DistribDevelopers` (
  `developer` VARCHAR(10) NOT NULL,
  `project` INT NOT NULL,
  PRIMARY KEY (`developer`, `project`),

  FOREIGN KEY (`project`) REFERENCES `Project`(id),
  FOREIGN KEY (`developer`) REFERENCES `Developer`(`login`)
);
*/
	auto id = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);
	auto dateStart = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto supposeDateFinish = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	auto dateFinish = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto description = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	Table::TColumns colums;

	/*colums.insert(QString("Id"), id);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	*/

	return Table  ("Company", "Company", colums);
}

const Table getTaskList()
{
/*

CREATE  TABLE `TaskList` (
  `task` INT NOT NULL,
  `depend` INT NOT NULL,

  PRIMARY KEY (`task`, `depend`),

  FOREIGN KEY (`task`) REFERENCES `Task`(id),
  FOREIGN KEY (`depend`) REFERENCES `Task`(id)
)

*/
	auto id = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto name = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);
	auto dateStart = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto supposeDateFinish = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	auto dateFinish = Table::Column("id","id", Table::Column::TCOLUMN_TYPE_INT);
	auto description = Table::Column("name","name", Table::Column::TCOLUMN_TYPE_STRING);

	Table::TColumns colums;

	/*colums.insert(QString("Id"), id);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	colums.insert(QString("name"), name);
	*/

	return Table  ("Company", "Company", colums);
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{

	ui->setupUi(this);

	ui->mMain->addAction(ui->actionDbConenct);

	mTables.insert("Company",getCompany());
	mTables.insert("Developer",getDeveloper());
	for(auto table : mTables)
	{
		QAction *action = ui->mTables->addAction(table.caption());

		action->setProperty("table", table.name());
		connect(action, SIGNAL(triggered()) ,SLOT(mTablesTriggered()));

	}
}


MainWindow::~MainWindow()
{
	db.close();
	delete ui;
}

void MainWindow::mTablesTriggered()
{
	TableWindow *window = new TableWindow(mTables[sender()->property("table").toString()], &db, this);
	window->show();
}

void MainWindow::on_actionDbConenct_triggered()
{
	db = QSqlDatabase::addDatabase("QMYSQL", "db");
	db.setHostName("localhost");
	db.setDatabaseName("db");
	db.setUserName("root");
	db.setPassword("");

	if(!db.open())
	{
		qDebug() << "не удалось подлючиться к базе данных" << db.lastError();
		throw 1;
	}
}


