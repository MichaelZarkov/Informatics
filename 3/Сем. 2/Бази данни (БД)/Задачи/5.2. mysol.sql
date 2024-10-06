-- Зад 1. Да се напише заявка, която извежда име на битка и име на кораб в една колона (конкатенирани) с тире между
-- тях, както и деня и седмицата, в която се е провела битката.
set schema DB2SHIPS;
select (O.battle || ' - ' || O.ship) as battle_and_ship,
       dayName(B.date) as day_of_week, week(B.date) as week
from Battles B, Outcomes O
where B.name = O.battle;

-- Зад 2. Напишете заявка, която извежда имената и рождените дати на тези актьори, за които е изпълнено, че са родени
-- във високосна година и едновременно с това са и една и съща зодия по китайския календар. Да се счита, че всички
-- родени с 12 години разлика са една и съща зодия по китайския календар.
set schema DB2MOVIE;
select MS1.name as actor_1, MS1.birthdate as act_1_birthdate, MS2.name as actor_2, MS2.birthdate as act_2_birthdate
from MovieStar MS1, MovieStar MS2
where MS1.name <> MS2.name and MS1.birthdate <= MS2.BIRTHDATE  -- Notice the <=
  and mod(year(MS1.birthdate), 4) = 0 and (mod(year(MS1.birthdate), 400) = 0 or mod(year(MS1.birthdate), 100) <> 0)
  and mod(year(MS2.birthdate), 4) = 0 and (mod(year(MS2.birthdate), 400) = 0 or mod(year(MS2.birthdate), 100) <> 0)
  and mod(year(MS1.birthdate) - year(MS2.birthdate), 12) = 0;

-- Зад 3. Напишете заявка, която извежда рождената дата и имената на тези актьори родени на една и съща дата. Изведете
-- имената на актьорите по шаблона (MS1_NAME, MS2_NAME). Повтарящите се двойки от вида (MS1_NAME, MS2_NAME) да не се
-- извеждат в резултата.
select ('(' || trim(MS1.name) || ', ' || trim(MS2.name) || ')') as pairs,
       MS1.birthdate as MS1_date, MS2.birthdate as MS2_date
from MovieStar MS1, MovieStar MS2
where MS1.name < MS2.name and
      day(MS1.birthdate) = day(MS2.birthdate) and month(MS1.birthdate) = month(MS2.birthdate);

-- Зад 4. Да се напише заявка, която извежда колко години има разлика между датата, на която кораб е бил пуснат на вода
-- и първата битка, в която е участвал.
-- Заб: Със сигурност има по-добър начин да се изчисли колко години е разликата.
set schema DB2SHIPS;
select *
from
  (select S.name as Ship_Name,
    year((select min(B.date) as date_of_first_battle
          from Outcomes O, Battles B
          where S.name = O.ship and O.battle = B.name)) - S.launched as Difference
  from Ships S) as Result
where Result.Difference is not null;

-- Зад 5. Да се напише заявка, която намира филма с най-малка продължителност. Ако продължителността на филма е NULL да
-- се извежда 0.
set schema DB2MOVIE;
select title, year, coalesce(length, 0)
from Movie
where coalesce(length, 0) = (select min(coalesce(length, 0)) from Movie);


