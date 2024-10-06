set schema FN24_45655;

-- Task 1.
-- Make a new table the same as old.
create table FN24_45655.Employee like DB2SAMPLE.Employee;
-- Copy the rows.
insert into FN24_45655.Employee
select * from DB2SAMPLE.Employee;

-- Make a new table the same as old.
create table FN24_45655.Department like DB2SAMPLE.Department;
-- Copy rows.
insert into FN24_45655.Department
select * from DB2SAMPLE.Department;

-- Task 2.
create view Employee_info (empNo, name, birthdate, yearsExperience, edLevel, salary, commission)
as
  select empNo, firstNme || ' ' || lastName as name, birthdate,
         year(CURRENT_DATE) - year(hireDate) as yearsExperience, edLevel, salary, comm as commission
  from FN24_45655.Employee
  where year(CURRENT_DATE) - year(hireDate) > 30 or edLevel > 18;

-- Test the view.
select * from Employee_info;

-- To delete the view.
-- drop view Employee_info;

-- Task 3.
create view Employee_boss_info (dept_no, emp_no, emp_salary, boss_no, boss_salary)
as
  select D.deptNo, E.empNo, E.salary, Boss.empNo, Boss.salary
  from FN24_45655.Employee E, FN24_45655.Department D, FN24_45655.Employee Boss
  where E.workDept = D.deptNo and D.mgrNo = Boss.empNo;

-- Test the view.
select * from Employee_boss_info;