set schema DB2SHIPS;

-- Напишете заявка, която извежда името на корабите по-тежки от 35000.
select Ships.name
  from Ships, Classes
  where Ships.class = Classes.class and Classes.displacement > 35000
  order by Ships.name;

-- Напишете заявка, която извежда имената, водоизместимостта и броя оръжия на
-- всички кораби участвали в битката при 'Guadalcanal'.
select o.ship, c.displacement, c.numGuns
  from Outcomes o, Ships s, Classes c
  where o.battle = 'Guadalcanal' and
        o.ship = s.name and s.class = c.class
  order by o.ship;

-- Напишете заявка, която извежда имената на тези държави, които имат кораби от
-- тип ‘bb’ и ‘bc’ едновременно.
-- Вариант 1:
select c1.country
  from Classes c1, Classes c2
  where c1.country = c2.country and c1.type = 'bb' and c2.type = 'bc'
  order by c1.country;
-- Вариант 2:
(select country from Classes where type='bb')
intersect
(select country from classes where type='bc');

-- Напишете заявка, която извежда имената на тези битки с три кораба на една и
-- съща държава.
select distinct o1.battle
  from Outcomes o1, Outcomes o2, Outcomes o3,
       Ships s1, Ships s2, Ships s3,
       Classes c1, Classes c2, Classes c3
  where o1.battle = o2.battle and o2.battle = o3.battle and
        o1.ship <> o2.ship and o1.ship <> o3.ship and o2.ship <> o3.ship and
        o1.ship = s1.name and o2.ship = s2.name and o3.ship = s3.name and
        s1.class = c1.class and s2.class = c2.class and s3.class = c3.class and
        c1.country = c2.country and c2.country = c3.country
  order by o1.battle;

-- Напишете заявка, която извежда имената на тези кораби, които са били
-- повредени в една битка, но по късно са участвали в друга битка.
select o1.ship
  from Outcomes o1, Outcomes o2, Battles b1, Battles b2
  where o1.result = 'damaged' and o1.ship = o2.ship and o1.battle <> o2.battle and
        b1.name = o1.battle and b2.name = o2.battle and b1.date < b2.date
  order by o1.ship;
