SET SCHEMA FN42671;

-- Зад. 1. Напишете процедура, която по подаден входен параметър N цяло число извежда на екрана стойността на N!.
CREATE OR REPLACE PROCEDURE P1_NFACT(IN N INT)
BEGIN
    DECLARE V_NFACT DecFloat  DEFAULT 1;
    DECLARE I INT DEFAULT 1;

    WHILE I <= N DO
         SET V_NFACT = V_NFACT * I;
         SET I = I + 1;
    end while;

    CALL DBMS_OUTPUT.PUT_LINE(N || '! = ' || V_NFACT);
end;

CALL FN77777.P1_NFACT(30);

-- Зад. 2. Напишете функция, която по подаден входен параметър N цяло число връща стойност 1,
-- ако това число е просто и 0 в противен случай.
CREATE OR REPLACE FUNCTION F2_PRIME(N INT)
RETURNS INT
BEGIN
    DECLARE I INT DEFAULT 2;
    IF N <= 0 THEN RETURN -1;
    ELSEIF N <= 3 THEN RETURN 1;
    ELSE
    WHILE I <= N/2 DO
      IF MOD(N, I) = 0 THEN RETURN 0;
      ELSE
          SET I = I + 1;
      END IF;
    end while;
    RETURN 1;
    END IF;
end;

VALUES FN77777.F2_PRIME(11);

-- Зад. 3. Напишете процедура, която по подаден входен параметър N цяло число,
-- извежда на екрана простите числа <= N (използвайте функцията от предходната задача).
CREATE OR REPLACE PROCEDURE P3_PRIME_LIST_N(IN N BIGINT)
BEGIN
    DECLARE I BIGINT DEFAULT 1;
    CALL DBMS_OUTPUT.PUT_LINE('ALL PRIME NUMBERS <= ' || N);
    WHILE I <= N DO
    IF (FN77777.F2_PRIME(I) = 1) THEN
        CALL DBMS_OUTPUT.PUT_LINE(I);
    end if;
    SET I = I + 1;
    end while;
end;

CALL FN77777.P3_PRIME_LIST_N(10000);

-- зад. 3.1. Напишете функция, която по подадено число връща сумата на цифрите на числото.
CREATE OR REPLACE FUNCTION F3_SUM_DIGITS(N BIGINT)
RETURNS BIGINT
BEGIN
  DECLARE V_SUM BIGINT DEFAULT 0;
  SET N = ABS(N);
  WHILE N > 0 DO
     SET V_SUM = V_SUM + MOD(N, 10);
     SET N = N/10;
  end while;
  RETURN V_SUM;
end;

VALUES FN77777.F3_SUM_DIGITS(1);

-- Зад. 3.2 Да се напише процедура, която извежда всички прости числа <= N, такива че сумата
-- на цифрите им също да е просто число.
CREATE OR REPLACE PROCEDURE P3_PRIME2_LIST_N(IN N BIGINT)
BEGIN
    DECLARE I BIGINT DEFAULT 1;
    CALL DBMS_OUTPUT.PUT_LINE('ALL PRIME NUMBERS WITH PRIME SUM <= ' || N);
    WHILE I <= N DO
    IF (FN77777.F2_PRIME(I) = 1) THEN
      IF (FN77777.F2_PRIME(FN77777.F3_SUM_DIGITS(I)) = 1)  THEN
        CALL DBMS_OUTPUT.PUT_LINE(I);
      END IF;
    end if;
    SET I = I + 1;
    end while;
end;

CALL FN77777.P3_PRIME2_LIST_N(100);

-- Зад. 5. Напишете процедура, която по зададена цифра и число да провери дали
-- цифрата се съдържа в записа на числото
CREATE OR REPLACE PROCEDURE P5_DIGIT_CONTAINS(IN D INT, IN N BIGINT)
BEGIN
  DECLARE V_N BIGINT;
  SET N = ABS(N);
  SET D = ABS(D);
  SET V_N = N;
  WHILE N > 0 DO
     IF D = MOD(N, 10) THEN
         CALL DBMS_OUTPUT.PUT_LINE('DIGIT ' || D || ' CONTAINS IN NUMBER ' || V_N);
         RETURN;
     ELSE
        SET N = N/10;
     end if;
  end while;
  CALL DBMS_OUTPUT.PUT_LINE('DIGIT ' || D || ' DOES NOT CONTAIN IN NUMBER ' || V_N);
end;

CALL FN77777.P5_DIGIT_CONTAINS(1, 2134);

-- Зад. 6. Напишете процедура, която по зададено число да изведе обратното му число.
CREATE OR REPLACE PROCEDURE P6_LIST_DIGIT_REVERSE(IN N BIGINT)
BEGIN
  SET N = ABS(N);
  WHILE N > 0 DO
   CALL DBMS_OUTPUT.PUT_LINE(MOD(N, 10));
   SET N = N/10;
  end while;
end;

CALL FN77777.P6_LIST_DIGIT_REVERSE(12336444);