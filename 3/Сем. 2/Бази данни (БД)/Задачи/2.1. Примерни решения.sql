SET SCHEMA PC;

SELECT MODEL, SPEED AS MHZ, HD AS GB
  FROM PC
  WHERE PRICE < 1200;
  
SELECT DISTINCT MAKER
  FROM PRODUCT
  WHERE TYPE = 'Printer';
  
SELECT MODEL, RAM, SCREEN
  FROM LAPTOP
  WHERE PRICE > 1000;
  
SELECT *
  FROM PRINTER
  WHERE COLOR ='y';
  
SELECT MODEL, SPEED, HD
  FROM PC
  WHERE (CD = '12' OR CD = '16') AND PRICE < 2000;