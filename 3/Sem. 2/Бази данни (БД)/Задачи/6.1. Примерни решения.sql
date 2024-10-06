/* Групиране */

-- Зад 1. За базата от данни PC

set schema DB2PC;

-- Напишете заявка, която извежда средната честота на компютрите
select decimal(avg(speed),9,2) as AvgSpeed 
from pc;

-- Напишете заявка, която извежда средния размер на екраните на лаптопите за всеки 
-- производител
select p.maker, decimal(avg(screen), 9, 2) as AvgScreen
from laptop l join product p on p.model=l.model
group by p.maker;

-- Напишете заявка, която извежда средната честота на лаптопите с цена над 1000
select decimal(avg(speed),9,2) as AvgSpeed
from laptop
where price > 1000;

-- Напишете заявка, която извежда средната цена на компютрите произведени от 
-- производител 'A'
select p.maker, decimal(avg(price), 9, 2) as AvgPrice
from pc join product p on p.model=pc.model
where p.maker = 'A'
group by p.maker;

-- Напишете заявка, която извежда средната цена на компютрите и лаптопите за 
-- производител 'B'
select decimal(avg(price), 9, 2) as AvgPrice
from
(
select maker, price
from product p, pc
where p.model=pc.model and maker='B'
union all
select maker, price
from product p, laptop l
where p.model=l.model and maker='B'
)T;

-- Напишете заявка, която извежда средната цена на компютрите според различните им честоти
select speed, decimal(avg(price), 9, 2) as AvgPrice
from pc
group by speed;

-- Напишете заявка, която извежда производителя, които е произвел поне 3 различни 
-- модела компютъра
select p.maker, count(p.model) as CNT
from pc join product p on p.model=pc.model
where p.type='PC'
group by p.maker
having count(p.model)>=3;

-- Напишете заявка, която извежда производителя с най-висока цена на компютър
select maker, t.price
from 
(
select p.maker, max(price) price
from pc join product p on p.model=pc.model
where p.type='PC'
group by p.maker
)T 
where t.price >= all(select price from
(
select p.maker, max(price) price
from pc join product p on p.model=pc.model
where p.type='PC'
group by p.maker
)T);

-- Напишете заявка, която извежда средната цена на компютрите за всяка честота по-голяма
-- от 800
select speed, decimal(avg(price), 9, 2) as AvgPrice
from pc
where speed > 800
group by speed;

-- Напишете заявка, която извежда средния размер на диска на тези компютри произведени 
-- от производители, които произвеждат и принтери
select decimal(avg(hd), 9, 2) as AvgHDD
from pc join product p on p.model=pc.model
where maker in
(select distinct maker
from product
where type='Printer');

-- Зад 2. За базата от данни SHIPS 

 set schema ships;
 
-- Напишете заявка, която извежда броя на класовете кораби
select count(class)
from classes;

-- Напишете заявка, която извежда средния брой на оръжия, според класа на кораба
select class, avg(numGuns) as avgGuns
from classes
group by class;

-- Напишете заявка, която извежда средния брой на оръжия за всички кораби
select avg(numGuns) as avgGuns
from classes c join ships s on c.class=s.class;

-- Напишете заявка, която извежда за всеки клас първата и последната година, 
-- в която кораб от съответния клас е пуснат на вода
select c.class, min(s.launched) as FirstYear, max(s.launched) as LastYear
from classes c join ships s on c.class=s.class
group by c.class
order by c.class;

-- Напишете заявка, която извежда броя на корабите потънали в битка според класа
select class, count(o.ship)
from ships s join outcomes o on s.name=o.ship
where o.result='sunk'
group by class;

-- Напишете заявка, която извежда броя на корабите потънали в битка според класа, 
-- за тези класове с повече от 2 кораба
-- I вариант
select class
from ships s join outcomes o on s.name=o.ship
group by class
having count(o.ship)>=2
intersect
select class
from ships s join outcomes o on s.name=o.ship
where o.result='sunk';


-- II вариант
select class,count(name) as "Number of sunk ships"
from ships s join outcomes o on s.name=o.ship
where result='sunk' and class in (select c.class
								  from classes c join ships s on c.class=s.class
								  group by c.class
								  having count(name)>2)
group by class;

-- Напишете заявка, която извежда средното тегло на корабите, за всяка страна. 
-- I вариант
select country, decimal(sum(weight)/sum(br), 9, 2) as AvgWeioght
from 
(
select c.country, c.class, count(s.name)as br,count(s.name)* c.bore as Weight
from classes c join ships s on c.class=s.class
group by c.country, c.class, c.bore) T
group by country;


-- II вариант
select country,avg(c.bore) as avg_displacement
from classes c join ships s on c.class=s.class
group by country;