SET SCHEMA FN71677;

CREATE OR REPLACE TRIGGER TRIG_BEFORE_INSERT_EMP_SAL
BEFORE INSERT ON EMPLOYEES
REFERENCING NEW AS N
FOR EACH ROW
WHEN ((SELECT COUNT(*) FROM JOBS WHERE JOBID = N.JOBID
      AND (N.SALARY > MAX_SALARY OR N.SALARY < MIN_SALARY)) >= 1)
BEGIN ATOMIC
    DECLARE V_MINSAL DECIMAL(9,2);
    DECLARE V_MAXSAL DECIMAL(9,2);

    SET V_MINSAL = (SELECT MIN_SALARY FROM JOBS WHERE JOBID = N.JOBID);
    SET V_MAXSAL = (SELECT MAX_SALARY FROM JOBS WHERE JOBID = N.JOBID);

    SIGNAL SQLSTATE '75999' ('Salary is out of range: [' || V_MINSAL || ', ' || V_MAXSAL || ']');
END;

SELECT * FROM JOBS WHERE JOBID = 34;

INSERT INTO EMPLOYEES(EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO)
VALUES (302, 'Penka', 'Petrova', '2000-01-13', '2022-12-13', '1232193021', 'ppetrova@micom.bg', 3000, 20, 34, 60, 103);

SELECT * FROM EMPLOYEES WHERE EMPNO = 302;

INSERT INTO EMPLOYEES(EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO)
VALUES (302, 'Penka', 'Petrova', '2000-01-13', '2022-12-13', '1232193021', 'ppetrova@micom.bg', 5000, 20, 34, 60, 103);

SELECT * FROM EMPLOYEES WHERE EMPNO = 302;

CREATE OR REPLACE TRIGGER TRIG_AFTER_UPD_EMP
AFTER UPDATE OF JOBID ON EMPLOYEES
REFERENCING NEW AS N OLD AS O
FOR EACH ROW
WHEN (N.JOBID <> O.JOBID)
BEGIN
    INSERT INTO JOBHISTORY(EMPNO, START_DATE, END_DATE, JOBID, DEPTNO)
    VALUES(O.empno, O.hiredate, CURRENT_DATE, O.JOBID, O.deptno);
end;

SELECT * FROM EMPLOYEES WHERE EMPNO = 302;
SELECT * FROM JOBHISTORY WHERE EMPNO = 302;

UPDATE EMPLOYEES
SET JOBID = 27
WHERE EMPNO = 302;

SELECT * FROM JOBHISTORY WHERE EMPNO = 302;
