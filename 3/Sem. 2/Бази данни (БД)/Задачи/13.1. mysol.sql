set schema FN24_45655;

-- Copy tables.
create table FN24_45655.Employee like DB2SAMPLE.Employee;
insert into FN24_45655.Employee
select * from DB2SAMPLE.Employee;

create table FN24_45655.Department like DB2SAMPLE.Department;
insert into FN24_45655.Department
select * from DB2SAMPLE.Department;

-- Task 1.
-- Създайте тригер за таблицата FNXXXXX.EMPLOYEE, който при всяка промяна на
-- заплатата на работник обновява заплатата на шефа на този департамент с 10%. Като
-- използвате изгледа от 1 тествайте тригера за департамент 'C01'.
create trigger FN24_45655.update_boss_salary
after update on FN24_45655.Employee
referencing new as N old as O
for each row when (N.salary <> O.salary)
  update FN24_45655.Employee
  set salary = salary * 1.1
  where empNo = (select mgrNo from FN24_45655.Department where deptNo = N.workDept);