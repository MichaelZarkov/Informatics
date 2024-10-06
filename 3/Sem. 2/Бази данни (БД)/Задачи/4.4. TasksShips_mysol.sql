set schema DB2SHIPS;

-- Напишете заявка, която извежда страните, чиито кораби са с най-голям брой оръжия.
  -- Първи вариант:
  select country
    from Classes
    order by numguns desc
    fetch first 1 rows only;  -- FETCH FIRST n ROWS ONLY може да не работи при други системи за управление на бази данни.
  -- Втори вариант с подзаявка:
  select distinct country
    from Classes
    where numguns >= all(select numguns from Classes);

-- Напишете заявка, която извежда класовете, за които поне един от корабите им е потънал в битка.
  select distinct class
    from Ships
    where name in (select ship from Outcomes where result = 'sunk');

-- Напишете заявка, която извежда имената на корабите с 16 инчови оръдия (bore).
  select name
    from Ships
    where class in (select class from Classes where bore = 16);

-- Напишете заявка, която извежда имената на битките, в които са участвали
-- кораби от клас ‘Kongo’.
  -- Първи вариант (странен, но изглежда верен):
  select B.name
    from Battles as B
    where
      exists((select ship from Outcomes where B.name = battle) intersect
      (select name from Ships where class = 'Kongo'));
  -- Втори вариант (значително по-разбираем):
  select distinct O.battle
    from Outcomes as O
    where O.ship in (select name from Ships where class = 'Kongo');

-- Напишете заявка, която извежда иманата на корабите, чиито брой оръдия е
-- най-голям в сравнение с корабите със същия калибър оръдия (bore).
  select name
    from Ships
    where Ships.class in
      (select C1.class
          from Classes as C1
          where C1.numguns >= all(select numguns from Classes as C2 where C1.bore = C2.bore));