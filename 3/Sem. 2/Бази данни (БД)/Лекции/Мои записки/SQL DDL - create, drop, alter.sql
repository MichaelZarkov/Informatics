-- ВАЖНО!!!
-- Този файл върви комплект с файла "БД записки от лекции.docx". Важно е да не се преименува, защото има линк към него.

-- Пример за създаване на таблица (релация).
create table MovieStar (
  name char(40),
  address varchar(255),
  gender char(1),
  birthdate date default current_date
);

-- "not null" ограничение. Декларира се само на ниво атрибут.
create table MovieStar (
  name char(40) not null,
  address varchar(255)
);

-- Ограничение за първичен ключ (primary key). Ако първичният ключ се състои само от един
-- атрибут, то можем да сложим ограничението веднага след атрибута (на ниво атрибут).
-- Атрибутите от първичния ключ не могат да имат NULL стойности и изрично трябва да се каже "not null".
create table MovieStar (
  name char(40) not null primary key,
  address varchar(255)
);
-- Ако първичният ключ е с повече от един атрибут, то трябва да сложим ограничението в края (на ниво таблица).
create table Movie (
  title varchar(255) not null,
  yearReleased int not null,
  lengthMins int,
  inColour char(1),
  studioName varchar(50),
  primary key (title, yearReleased)
);

-- Ограничение за външен ключ (foreign key). На ниво атрибут, само ако външният ключ се състои от един атрибут:
references <parent_table> (<parent_table_attribute)
-- На ниво таблица, ако външният ключ е с два или повече атрибута:
foreign key (<child_table_attributes>) references <parent_table> (<parent_table_attributes>)
-- Пример:
create table MovieStudio (
  name char(50) not null primary key,
  address varchar(255)
);
create table Movie (
  title varchar(255) not null,
  yearReleased int not null,
  studioName char(50),
  primary key (title, yearReleased),
  foreign key (studioName) references MovieStudio (name)
);

-- Check ограничения. На ниво атрибут:
create table MovieStar (
  name char(30) not null primary key,
  gender char(1) check (gender in ('M', 'F'))
);
-- На ниво таблица:
create table MovieStar (
  name char(30) not null primary key,
  gender char(1),
  check (gender in ('M', 'F'))
);