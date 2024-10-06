SET SCHEMA FN71677;
/*
Employees (empno, fname, lname, birthdate, hiredate, phone, email, salary, comm, jobid, deptno, mgrno)
Departments (deptno, deptname, empno_mgr)
Jobs (jobid, title, min_salary, max_salary)
JobHistory (empno, start_date, end_date, jobid, deptno)
 */

INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('100   ', 'Steven', 'King', '1950-05-11', '1987-06-17', '515.123.45', 'sking@micom.bg', 24000.00, null, 26, '90 ', null);
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('101   ', 'Neena', 'Kochhar', '1951-06-12', '1989-09-21', '515.123.45', 'nkochhar@micom.bg', 17000.00, null, 21, '90 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('102   ', 'Lex', 'De Haan', '1952-07-13', '1993-01-13', '515.123.45', 'ldehaan@micom.bg', 17000.00, null, 21, '90 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('103   ', 'Alexander', 'Hunold', '1953-08-14', '1990-01-03', '590.423.45', 'ahunold@micom.bg', 9000.00, null, 34, '60 ', '102   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('106   ', 'Valli', 'Pataballa', '1956-11-17', '1998-02-05', '590.423.45', 'vpatabal@micom.bg', 4800.00, null, 34, '60 ', '103   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('107   ', 'Diana', 'Lorentz', '1957-12-18', '1999-02-07', '590.423.55', 'dlorentz@micom.bg', 4200.00, null, 34, '60 ', '103   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('108   ', 'Nancy', 'Greenberg', '1958-01-19', '1994-08-17', '515.124.45', 'ngreenbe@micom.bg', 12000.00, null, 23, '100', '101   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('109   ', 'Daniel', 'Faviet', '1959-02-20', '1994-08-16', '515.124.41', 'dfaviet@micom.bg', 9000.00, null, 24, '100', '108   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('110   ', 'John', 'Chen', '1960-03-21', '1997-09-28', '515.124.42', 'jchen@micom.bg', 8200.00, null, 24, '100', '108   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('111   ', 'Ismael', 'Sciarra', '1961-04-22', '1997-09-30', '515.124.43', 'isciarra@micom.bg', 7700.00, null, 24, '100', '108   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('112   ', 'Jose Manuel', 'Urman', '1962-05-23', '1998-03-07', '515.124.44', 'jmurman@micom.bg', 7800.00, null, 24, '100', '108   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('113   ', 'Luis', 'Popp', '1963-06-24', '1999-12-07', '515.124.45', 'lpopp@micom.bg', 6900.00, null, 24, '100', '108   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('114   ', 'Den', 'Raphaely', '1964-07-25', '1994-12-07', '515.127.45', 'drapheal@micom.bg', 11000.00, null, 29, '30 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('115   ', 'Alexander', 'Khoo', '1965-08-26', '1995-05-18', '515.127.45', 'akhoo@micom.bg', 3100.00, null, 30, '30 ', '114   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('116   ', 'Shelli', 'Baida', '1966-09-27', '1997-12-24', '515.127.45', 'sbaida@micom.bg', 2900.00, null, 30, '30 ', '114   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('117   ', 'Sigal', 'Tobias', '1967-10-28', '1997-07-24', '515.127.45', 'stobias@micom.bg', 2800.00, null, 34, '30 ', '114   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('118   ', 'Guy', 'Himuro', '1968-11-29', '1998-11-15', '515.127.45', 'ghimuro@micom.bg', 2600.00, null, 30, '30 ', '114   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('119   ', 'Karen', 'Colmenares', '1969-12-30', '1999-08-10', '515.127.45', 'kcolmena@micom.bg', 2500.00, null, 30, '30 ', '114   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('120   ', 'Matthew', 'Weiss', '1970-01-01', '1996-07-18', '650.123.12', 'mweiss@micom.bg', 8000.00, null, 31, '50 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('121   ', 'Adam', 'Fripp', '1971-02-02', '1997-04-10', '650.123.22', 'afripp@micom.bg', 8200.00, null, 31, '50 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('122   ', 'Payam', 'Kaufling', '1972-03-03', '1995-05-01', '650.123.32', 'pkauflin@micom.bg', 7900.00, null, 31, '50 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('123   ', 'Shanta', 'Vollman', '1973-04-04', '1997-10-10', '650.123.42', 'svollman@micom.bg', 6500.00, null, 31, '50 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('124   ', 'Kevin', 'Mourgos', '1974-05-05', '1999-11-16', '650.123.52', 'kmourgos@micom.bg', 5800.00, null, 31, '50 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('125   ', 'Julia', 'Nayer', '1975-06-06', '1997-07-16', '650.124.12', 'jnayer@micom.bg', 3200.00, null, 33, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('126   ', 'Irene', 'Mikkilineni', '1976-07-07', '1998-09-28', '650.124.12', 'imikkili@micom.bg', 2700.00, null, 32, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('127   ', 'James', 'Landry', '1977-08-08', '1999-01-14', '650.124.13', 'jlandry@micom.bg', 2400.00, null, 32, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('128   ', 'Steven', 'Markle', '1978-09-09', '2000-03-08', '650.124.14', 'smarkle@micom.bg', 2200.00, null, 32, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('129   ', 'Laura', 'Bissot', '1979-10-10', '1997-08-20', '650.124.52', 'lbissot@micom.bg', 3300.00, null, 32, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('130   ', 'Mozhe', 'Atkinson', '1980-11-11', '1997-10-30', '650.124.62', 'matkinso@micom.bg', 2800.00, null, 33, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('131   ', 'James', 'Marlow', '1981-12-12', '1997-02-16', '650.124.72', 'jamrlow@micom.bg', 2500.00, null, 33, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('132   ', 'TJ', 'Olson', '1982-01-13', '1999-04-10', '650.124.82', 'tjolson@micom.bg', 2100.00, null, 32, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('133   ', 'Jason', 'Mallin', '1983-02-14', '1996-06-14', '650.127.19', 'jmallin@micom.bg', 3300.00, null, 32, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('134   ', 'Michael', 'Rogers', '1984-03-15', '1998-08-26', '650.127.18', 'mrogers@micom.bg', 2900.00, null, 33, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('135   ', 'Ki', 'Gee', '1985-04-16', '1999-12-12', '650.127.17', 'kgee@micom.bg', 2400.00, null, 33, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('136   ', 'Hazel', 'Philtanker', '1986-05-17', '2000-02-06', '650.127.16', 'hphiltan@micom.bg', 2200.00, null, 32, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('137   ', 'Renske', 'Ladwig', '1987-06-18', '1995-07-14', '650.121.12', 'rladwig@micom.bg', 3600.00, null, 32, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('138   ', 'Stephen', 'Stiles', '1988-07-19', '1997-10-26', '650.121.20', 'sstiles@micom.bg', 3200.00, null, 33, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('139   ', 'John', 'Seo', '1989-08-20', '1998-02-12', '650.121.20', 'jseo@micom.bg', 2700.00, null, 33, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('140   ', 'Joshua', 'Patel', '1990-09-21', '1998-04-06', '650.121.18', 'jpatel@micom.bg', 2500.00, null, 32, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('141   ', 'Trenna', 'Rajs', '1991-10-22', '1995-10-17', '650.121.80', 'trajs@micom.bg', 3500.00, null, 32, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('142   ', 'Curtis', 'Davies', '1992-11-23', '1997-01-29', '650.121.29', 'cdavies@micom.bg', 3100.00, null, 28, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('143   ', 'Randall', 'Matos', '1993-12-24', '1998-03-15', '650.121.28', 'rmatos@micom.bg', 2600.00, null, 33, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('144   ', 'Peter', 'Vargas', '1994-01-25', '1998-07-09', '650.121.20', 'pvargas@micom.bg', 2500.00, null, 32, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('145   ', 'John', 'Russell', '1995-02-26', '1996-10-01', '011.44.134', 'jrussel@micom.bg', 14000.00, 40.00, 27, '80 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('146   ', 'Karen', 'Partners', '1996-03-27', '1997-01-05', '011.44.134', 'kpartner@micom.bg', 13500.00, 30.00, 27, '80 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('147   ', 'Alberto', 'Errazuriz', '1997-04-28', '1997-03-10', '011.44.134', 'aerrazur@micom.bg', 12000.00, 30.00, 27, '80 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('148   ', 'Gerald', 'Cambrault', '1998-05-29', '1999-10-15', '011.44.134', 'gcambrau@micom.bg', 11000.00, 30.00, 27, '80 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('149   ', 'Eleni', 'Zlotkey', '1999-06-30', '2000-01-29', '011.44.134', 'ezlotkey@micom.bg', 10500.00, 20.00, 27, '80 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('150   ', 'Peter', 'Tucker', '1950-07-01', '1997-01-30', '011.44.134', 'ptucker@micom.bg', 10000.00, 30.00, 28, '80 ', '145   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('151   ', 'David', 'Bernstein', '1951-08-02', '1997-03-24', '011.44.134', 'dbernste@micom.bg', 9500.00, 25.00, 28, '80 ', '145   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('152   ', 'Peter', 'Hall', '1952-09-03', '1997-08-20', '011.44.134', 'phall@micom.bg', 9000.00, 25.00, 28, '80 ', '145   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('153   ', 'Christopher', 'Olsen', '1953-10-04', '1998-03-30', '011.44.134', 'colsen@micom.bg', 8000.00, 20.00, 28, '80 ', '145   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('154   ', 'Nanette', 'Cambrault', '1954-11-05', '1998-12-09', '011.44.134', 'ncambrau@micom.bg', 7500.00, 20.00, 28, '80 ', '145   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('155   ', 'Oliver', 'Tuvault', '1955-12-06', '1999-11-23', '011.44.134', 'otuvault@micom.bg', 7000.00, 15.00, 28, '80 ', '145   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('156   ', 'Janette', 'King', '1956-01-07', '1996-01-30', '011.44.134', 'jking@micom.bg', 10000.00, 35.00, 28, '80 ', '146   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('157   ', 'Patrick', 'Sully', '1957-02-08', '1996-03-04', '011.44.134', 'psully@micom.bg', 9500.00, 35.00, 28, '80 ', '146   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('158   ', 'Allan', 'McEwen', '1958-03-09', '1996-08-01', '011.44.134', 'amcewen@micom.bg', 9000.00, 35.00, 28, '80 ', '146   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('159   ', 'Lindsey', 'Smith', '1959-04-10', '1997-03-10', '011.44.134', 'lsmith@micom.bg', 8000.00, 30.00, 28, '80 ', '146   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('160   ', 'Louise', 'Doran', '1960-05-11', '1997-12-15', '011.44.134', 'ldoran@micom.bg', 7500.00, 30.00, 28, '80 ', '146   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('161   ', 'Sarath', 'Sewall', '1961-06-12', '1998-11-03', '011.44.134', 'ssewall@micom.bg', 7000.00, 25.00, 28, '80 ', '146   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('162   ', 'Clara', 'Vishney', '1962-07-13', '1997-11-11', '011.44.134', 'cvishney@micom.bg', 10500.00, 25.00, 28, '80 ', '147   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('163   ', 'Danielle', 'Greene', '1963-08-14', '1999-03-19', '011.44.134', 'dgreene@micom.bg', 9500.00, 15.00, 28, '80 ', '147   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('164   ', 'Mattea', 'Marvins', '1964-09-15', '2000-01-24', '011.44.134', 'mmarvins@micom.bg', 7200.00, 10.00, 28, '80 ', '147   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('165   ', 'David', 'Lee', '1965-10-16', '2000-02-23', '011.44.134', 'dlee@micom.bg', 6800.00, 10.00, 28, '80 ', '147   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('166   ', 'Sundar', 'Ande', '1966-11-17', '2000-03-24', '011.44.134', 'sande@micom.bg', 6400.00, 10.00, 28, '80 ', '147   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('167   ', 'Amit', 'Banda', '1967-12-18', '2000-04-21', '011.44.134', 'abanda@micom.bg', 6200.00, 10.00, 28, '80 ', '147   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('168   ', 'Lisa', 'Ozer', '1968-01-19', '1997-03-11', '011.44.134', 'lozer@micom.bg', 11500.00, 25.00, 28, '80 ', '148   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('169   ', 'Harrison', 'Bloom', '1969-02-20', '1998-03-23', '011.44.134', 'hbloom@micom.bg', 10000.00, 20.00, 28, '80 ', '148   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('170   ', 'Tayler', 'Fox', '1970-03-21', '1998-01-24', '011.44.134', 'tfox@micom.bg', 9600.00, 20.00, 28, '80 ', '148   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('171   ', 'William', 'Smith', '1971-04-22', '1999-02-23', '011.44.134', 'wsmith@micom.bg', 7400.00, 15.00, 28, '80 ', '148   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('172   ', 'Elizabeth', 'Bates', '1972-05-23', '1999-03-24', '011.44.134', 'ebates@micom.bg', 7300.00, 15.00, 28, '80 ', '148   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('173   ', 'Sundita', 'Kumar', '1973-06-24', '2000-04-21', '011.44.134', 'skumar@micom.bg', 6100.00, 10.00, 28, '80 ', '148   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('174   ', 'Ellen', 'Abel', '1974-07-25', '1996-05-11', '011.44.164', 'eabel@micom.bg', 11000.00, 30.00, 28, '80 ', '149   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('175   ', 'Alyssa', 'Hutton', '1975-08-26', '1997-03-19', '011.44.164', 'ahutton@micom.bg', 8800.00, 25.00, 28, '80 ', '149   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('176   ', 'Jonathon', 'Taylor', '1976-09-27', '1998-03-24', '011.44.164', 'jtaylor@micom.bg', 8600.00, 20.00, 28, '80 ', '149   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('177   ', 'Jack', 'Livingston', '1977-10-28', '1998-04-23', '011.44.164', 'jlivings@micom.bg', 8400.00, 20.00, 28, '80 ', '149   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('178   ', 'Kimberely', 'Grant', '1978-11-29', '1999-05-24', '011.44.164', 'kgrant@micom.bg', 7000.00, 15.00, 28, null, '149   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('179   ', 'Charles', 'Johnson', '1979-12-30', '2000-01-04', '011.44.164', 'cjohnson@micom.bg', 6200.00, 10.00, 28, '80 ', '149   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('180   ', 'Winston', 'Taylor', '1980-01-01', '1998-01-24', '650.507.98', 'wtaylor@micom.bg', 3200.00, null, 33, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('181   ', 'Jean', 'Fleaur', '1981-02-02', '1998-02-23', '650.507.98', 'jfleaur@micom.bg', 3100.00, null, 33, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('182   ', 'Martha', 'Sullivan', '1982-03-03', '1999-06-21', '650.507.98', 'msulliva@micom.bg', 2500.00, null, 33, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('183   ', 'Girard', 'Geoni', '1983-04-04', '2000-02-03', '650.507.98', 'ggeoni@micom.bg', 2800.00, null, 33, '50 ', '120   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('184   ', 'Nandita', 'Sarchand', '1984-05-05', '1996-01-27', '650.509.18', 'nsarchan@micom.bg', 4200.00, null, 32, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('185   ', 'Alexis', 'Bull', '1985-06-06', '1997-02-20', '650.509.28', 'abull@micom.bg', 4100.00, null, 32, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('186   ', 'Julia', 'Dellinger', '1986-07-07', '1998-06-24', '650.509.38', 'jdelling@micom.bg', 3400.00, null, 32, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('187   ', 'Anthony', 'Cabrio', '1987-08-08', '1999-02-07', '650.509.48', 'acabrio@micom.bg', 3000.00, null, 32, '50 ', '121   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('188   ', 'Kelly', 'Chung', '1988-09-09', '1997-06-14', '650.505.18', 'kchung@micom.bg', 3800.00, null, 32, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('189   ', 'Jennifer', 'Dilly', '1989-10-10', '1997-08-13', '650.505.28', 'jdilly@micom.bg', 3600.00, null, 33, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('190   ', 'Timothy', 'Gates', '1990-11-11', '1998-07-11', '650.505.38', 'tgates@micom.bg', 2900.00, null, 33, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('191   ', 'Randall', 'Perkins', '1991-12-12', '1999-12-19', '650.505.48', 'rperkins@micom.bg', 2500.00, null, 32, '50 ', '122   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('192   ', 'Sarah', 'Bell', '1992-01-13', '1996-02-04', '650.501.18', 'sbell@micom.bg', 4000.00, null, 32, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('193   ', 'Britney', 'Everett', '1993-02-14', '1997-03-03', '650.501.28', 'beverett@micom.bg', 3900.00, null, 33, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('194   ', 'Samuel', 'McCain', '1994-03-15', '1998-07-01', '650.501.38', 'smccain@micom.bg', 3200.00, null, 33, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('195   ', 'Vance', 'Jones', '1995-04-16', '1999-03-17', '650.501.48', 'vjones@micom.bg', 2800.00, null, 32, '50 ', '123   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('196   ', 'Alana', 'Walsh', '1996-05-17', '1998-04-24', '650.507.98', 'awalsh@micom.bg', 3100.00, null, 32, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('197   ', 'Kevin', 'Feeney', '1997-06-18', '1998-05-23', '650.507.98', 'kfeeney@micom.bg', 3000.00, null, 33, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('198   ', 'Donald', 'OConnell', '1998-07-19', '1999-06-21', '650.507.98', 'doconnel@micom.bg', 2600.00, null, 33, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('199   ', 'Douglas', 'Grant', '1999-08-20', '2000-01-13', '650.507.98', 'dgrant@micom.bg', 2600.00, null, 32, '50 ', '124   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('200   ', 'Jennifer', 'Whalen', '1950-09-21', '1987-09-17', '515.123.44', 'jwhalen@micom.bg', 4400.00, null, 22, '10 ', '101   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('201   ', 'Michael', 'Hartstein', '1951-10-22', '1996-02-17', '515.123.55', 'mhartste@micom.bg', 13000.00, null, 35, '20 ', '100   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('202   ', 'Pat', 'Fay', '1952-11-23', '1997-08-17', '603.123.66', 'pfay@micom.bg', 6000.00, null, 28, '20 ', '201   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('203   ', 'Susan', 'Mavris', '1953-12-24', '1994-06-07', '515.123.77', 'smavris@micom.bg', 6500.00, null, 37, '40 ', '101   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('204   ', 'Hermann', 'Baer', '1954-01-25', '1994-06-07', '515.123.88', 'hbaer@micom.bg', 10000.00, null, 38, '70 ', '101   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('205   ', 'Shelley', 'Higgins', '1955-02-26', '1994-06-07', '515.123.80', 'shiggins@micom.bg', 12000.00, null, 25, '110', '101   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('206   ', 'William', 'Gietz', '1956-03-27', '1994-06-07', '515.123.81', 'wgietz@micom.bg', 8300.00, null, 28, '110', '205   ');
INSERT INTO FN71677.EMPLOYEES (EMPNO, FNAME, LNAME, BIRTHDATE, HIREDATE, PHONE, EMAIL, SALARY, COMM, JOBID, DEPTNO, MGRNO) VALUES ('669   ', 'Maq', 'Deneva', '1969-10-10', '1999-05-24', '515.123.81', 'nqma@micom.bg', 7000.00, null, 20, '120', null);
-----------------------------------------------------------
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('10 ', 'Administration', '200   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('20 ', 'Marketing', '201   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('30 ', 'Purchasing', '114   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('40 ', 'Human Resources', '203   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('50 ', 'Shipping', '121   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('60 ', 'IT', '103   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('70 ', 'Public Relations', '204   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('80 ', 'Sales', '145   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('90 ', 'Executive', '100   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('100', 'Finance', '108   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('110', 'Accounting', '205   ');
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('120', 'Treasury', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('130', 'Corporate Tax', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('140', 'Control And Credit', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('150', 'Shareholder Services', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('160', 'Benefits', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('170', 'Manufacturing', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('180', 'Construction', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('190', 'Contracting', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('200', 'Operations', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('210', 'IT Support', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('220', 'NOC', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('230', 'IT Helpdesk', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('240', 'Government Sales', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('250', 'Retail Sales', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('260', 'Recruiting', null);
INSERT INTO FN71677.DEPARTMENTS (DEPTNO, DEPTNAME, EMPNO_MGR) VALUES ('270', 'Payroll', null);
-------------------------------------------------------------
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (20, 'President                     ', 20000.00, 40000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (21, 'Administration Vice President ', 15000.00, 30000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (22, 'Administration Assistant      ', 3000.00, 6000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (23, 'Finance Manager               ', 8200.00, 16000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (24, 'Accountant                    ', 4200.00, 9000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (25, 'Accounting Manager            ', 8200.00, 16000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (26, 'Public Accountant             ', 4200.00, 9000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (27, 'Sales Manager                 ', 10000.00, 20000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (28, 'Sales Representative          ', 6000.00, 12000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (29, 'Purchasing Manager            ', 8000.00, 15000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (30, 'Purchasing Clerk              ', 2500.00, 5500.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (31, 'Stock Manager                 ', 5500.00, 8500.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (32, 'Stock Clerk                   ', 2000.00, 5000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (33, 'Shipping Clerk                ', 2500.00, 5500.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (34, 'Programmer                    ', 4000.00, 10000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (35, 'Marketing Manager             ', 9000.00, 15000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (36, 'Marketing Representative      ', 4000.00, 9000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (37, 'Human Resources Representative', 4000.00, 9000.00);
INSERT INTO FN71677.JOBS (JOBID, TITLE, MIN_SALARY, MAX_SALARY) VALUES (38, 'Public Relations Representativ', 4500.00, 10500.00);
----------------------------------------------------------------------
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('102   ', '1993-01-13', '1998-07-24', 34, '60 ');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('101   ', '1989-09-21', '1993-10-27', 26, '110');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('101   ', '1993-10-28', '1997-03-15', 25, '110');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('201   ', '1996-02-17', '1999-12-19', 36, '20 ');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('114   ', '1998-03-24', '1999-12-31', 32, '50 ');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('122   ', '1999-01-01', '1999-12-31', 32, '50 ');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('200   ', '1987-09-17', '1993-06-17', 22, '90 ');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('176   ', '1998-03-24', '1998-12-31', 28, '80 ');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('176   ', '1999-01-01', '1999-12-31', 27, '80 ');
INSERT INTO FN71677.JOBHISTORY (EMPNO, START_DATE, END_DATE, JOBID, DEPTNO) VALUES ('200   ', '1994-07-01', '1998-12-31', 26, '90 ');
