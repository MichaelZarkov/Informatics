set schema FN24_45655;

-- Task 1.
-- Make a new table the same as old.
create table FN24_45655.Employee like DB2SAMPLE.Employee;
-- Copy the rows.
insert into FN24_45655.Employee
select *
from DB2SAMPLE.Employee;

-- Task 2.
-- Create a function which returns how many employees work in the given department.
create function FN24_45655.employee_count(dept_num varchar(3))
returns int
begin
  declare emp_count int;

  select count(*)
  into emp_count
  from FN24_45655.Employee
  where workDept = dept_num;

  return emp_count;
end;

-- Call the function. Note that for some reason there is an error if the schema
-- 'FN24_45655' is not specified, even if we run 'set schema FN24_45655;' beforehand.
values FN24_45655.employee_count('A00');
-- Another way to call it.
select FN24_45655.employee_count('A00') from SYSIBM.SYSDUMMY1;

-- If we want to remove it
-- drop function FN24_45655.employee_count;

-- Task 3.
-- Create a function that by given department number returns a table of the numbers and
-- names of all employees that work there.
create function FN24_45655.employees_in_department(dept_num char(3))
returns table (empNo char(6), name varchar(18))
return
  select empno, firstNme || ' ' || lastName
  from Employee
  where workDept = dept_num;

-- Call the function. 'table()' is necessary to cast the result of the function to a table.
select *
from table(FN24_45655.employees_in_department('A00')) as T
order by T.name;
