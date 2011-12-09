
CREATE DATABASE `db`;

Connect `db`;

CREATE  TABLE  `Company` (
  `id` INT AUTO_INCREMENT PRIMARY KEY,
  `name` VARCHAR(45) NOT NULL
);

CREATE  TABLE `Developer` (
  `login` VARCHAR(10) PRIMARY KEY,
  `pass` VARCHAR(45) NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `isAdmin` BOOL  NULL DEFAULT false,
  `company` INT NOT NULL,

  FOREIGN KEY (`company`) REFERENCES `Company`(id)
);

CREATE  TABLE `Project` (
  `id` INT AUTO_INCREMENT PRIMARY KEY,
  `name` VARCHAR(45) NOT NULL,
  `dateStart` DATETIME NOT NULL,

  `supposeDateFinish` DATETIME NOT NULL
		CHECK (`supposeDateFinish` > `dateStart`),

  `dateFinish` DATETIME 
		CHECK (`dateFinish` > `dateStart`),

  `description` VARCHAR(1000) NULL
);

CREATE  TABLE `Task` (
  `id` INT AUTO_INCREMENT PRIMARY KEY,
  `isOpen` BOOL NULL DEFAULT 1,
  `name` VARCHAR(45) NOT NULL,
  `description` VARCHAR(10000) NULL,
  `workTime` INT NOT NULL,
  `project` INT NOT NULL,

  FOREIGN KEY (`project`) REFERENCES `Project`(id)
 );

CREATE  TABLE `Contract` (
  `id` INT AUTO_INCREMENT PRIMARY KEY,
  `date` DATETIME NULL,
  `isRunning` BOOL NULL DEFAULT 1,
  `company` INT NOT NULL,
  `project` INT NOT NULL,

  FOREIGN KEY (`company`) REFERENCES `Company`(id),
  FOREIGN KEY (`project`) REFERENCES `Project`(id)
);

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

CREATE  TABLE `DistribDevelopers` (
  `developer` VARCHAR(10) NOT NULL,
  `project` INT NOT NULL,
  PRIMARY KEY (`developer`, `project`),

  FOREIGN KEY (`project`) REFERENCES `Project`(id),
  FOREIGN KEY (`developer`) REFERENCES `Developer`(`login`)
);

CREATE  TABLE `TaskList` (
  `task` INT NOT NULL,
  `depend` INT NOT NULL,

  PRIMARY KEY (`task`, `depend`),

  FOREIGN KEY (`task`) REFERENCES `Task`(id),
  FOREIGN KEY (`depend`) REFERENCES `Task`(id)
);

CREATE INDEX in_company_id
  ON `Company`(`id`);
  
CREATE INDEX in_developer_id
  ON `Developer`(`login`);
  
CREATE INDEX in_project_id
  ON `Project`(`id`);
  
CREATE INDEX in_task_id
  ON `Task`(`id`);   
  
  
CREATE INDEX in_developer_and_project
  ON `DistribDevelopers`(`project`,`developer`);
  
CREATE INDEX in_developer_and_company
  ON `Developer`(`company`, `login`); 
  
CREATE INDEX in_company_and_project
  ON `Contract`(`project`, `company`);   
  
CREATE INDEX in_task_and_dependends
  ON `TaskList`(`task`, `depend`);   
  
 
   
