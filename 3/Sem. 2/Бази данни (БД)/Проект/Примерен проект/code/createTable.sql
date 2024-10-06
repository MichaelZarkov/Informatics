SET SCHEMA FN71677;
/*
Employees (empno, fname, lname, birthdate, hiredate, phone, email, salary, comm, jobid, deptno, mgrno)
Departments (deptno, deptname, empno_mgr)
Jobs (jobid, title, min_salary, max_salary)
JobHistory (empno, start_date, end_date, jobid, deptno)
 */
CREATE TABLE Employees
 (empno CHAR(6) NOT NULL,
  fname VARCHAR(20) NOT NULL,
  lname VARCHAR(20) NOT NULL,
  birthdate DATE,
  hiredate DATE NOT NULL,
  phone CHAR(10),
  email VARCHAR(30),
  salary DECIMAL(9,2) NOT NULL,
  comm DECIMAL(9,2),
  jobid INT NOT NULL,
  deptno CHAR(3),
  mgrno CHAR(6)
 );

CREATE TABLE Departments (
    deptno CHAR(3) NOT NULL,
    deptname VARCHAR(30) NOT NULL,
    empno_mgr CHAR(6)
);

CREATE TABLE Jobs (
    jobid INT NOT NULL,
    title VARCHAR(30) NOT NULL,
    min_salary DECIMAL(9,2) NOT NULL,
    max_salary DECIMAL(9,2) NOT NULL
);

CREATE TABLE JobHistory (
    empno CHAR(6) NOT NULL,
    start_date DATE NOT NULL,
    end_date DATE,
    jobid INT NOT NULL,
    deptno CHAR(3) NOT NULL
);

/* Constraint - Primary key
Employees: PK (empno)
Departments: PK (deptno)
Jobs: PK(jobid)
JobHistory (empno, start_date)
*/
ALTER TABLE Employees ADD PRIMARY KEY(EMPNO);
ALTER TABLE Departments ADD PRIMARY KEY(DEPTNO);
ALTER TABLE Jobs ADD PRIMARY KEY(JOBID);
ALTER TABLE JobHistory ADD PRIMARY KEY(EMPNO, START_DATE);

/* Constarint - Foreign key
Employees: FK(jobid) -> Jobs (jobid)
Employees: FK(deptno) -> Departments (deptno)
Employees: FK(mgrno) -> Employees(empno)
Departments: FK(empno_mgr) -> Employees(empno)
JobHistory: FK(empno)  -> Employees(empno)
JobHistory: FK(deptno) -> Departments (deptno)
JobHistory: FK(jobid) -> Jobs (jobid)
*/

ALTER TABLE Employees ADD FOREIGN KEY (jobid) REFERENCES Jobs(jobid);
ALTER TABLE Employees ADD FOREIGN KEY (deptno) REFERENCES Departments(deptno);
ALTER TABLE Employees ADD FOREIGN KEY (mgrno) REFERENCES Employees(empno);
ALTER TABLE Departments ADD FOREIGN KEY (empno_mgr) REFERENCES Employees(empno);
ALTER TABLE JobHistory ADD FOREIGN KEY (empno) REFERENCES Employees(empno);
ALTER TABLE JobHistory ADD FOREIGN KEY (deptno) REFERENCES Departments(deptno);
ALTER TABLE JobHistory ADD FOREIGN KEY (jobid) REFERENCES Jobs(jobid);

/* Constraint - Check
Employees: CK (email - @ .)
Employees: CK (salary > 0)
Employees: CK (comm between 1 and 100)
Jobs: CK (min_salary < max_salary and min_salary > 0)
 */

ALTER TABLE Employees ADD CONSTRAINT CK_EMP_EMAIL CHECK (email LIKE '_%@%_.%_');
ALTER TABLE Employees ADD CONSTRAINT CK_EMP_SAL CHECK (salary > 0);
ALTER TABLE Employees ADD CONSTRAINT CK_EMP_COMM CHECK (comm BETWEEN 1 AND 100);
ALTER TABLE Jobs ADD CONSTRAINT CK_JB_SAL CHECK (min_salary < max_salary and min_salary > 0);
