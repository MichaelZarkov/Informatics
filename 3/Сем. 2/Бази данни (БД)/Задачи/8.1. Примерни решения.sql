-- Вариант 1 - Решения

-- 1 (movies) (2 т.)
-- Да се напише заявка, която извежда имената и годините на всички филми, 
-- които са по-дълги от 120 минути и са снимани преди 1990 г. Ако дължината на филма е неизвестна
-- (NULL), името и годината на този филм също да се изведът.

set schema movies;

select title, year, length
from movie
where length>120 and year<1990 or length is NULL;

-- 2 (movies) (3 т.)
-- Да се напише заявка, която извежда имената на най-младия актьор (мъж). 
-- Забележка: полът на актьора може да бъде 'M' или 'F'. 

set schema movies;

-- I

select name
from moviestar 
where gender='M' and birthdate in
(
select  max(birthdate) m
from moviestar
where gender='M'
);

--II

select name
from moviestar
where gender='M' and birthdate>=ALL(select birthdate from moviestar where gender='M');

-- 3 (ships) (4 т.)
-- Да се напише заявка, която извежда държавата и броят на потъналите кораби за тази държава.
-- Държави, които нямат кораби или имат кораб, но той не е участвал в битка, също да 
-- бъдат изведени.

set schema ships;

-- I (с group by)
select c.country , count(o.result) as Sunk
from classes c left join ships s on c.class=s.class 
left join outcomes o on s.name=o.ship 
where result='sunk' or result is NULL
group by c.country;

-- II (без group by)

select distinct c.country , (select count(o.result) as Sunk
					from classes c1 left join ships s on c1.class=s.class 
					left join outcomes o on s.name=o.ship 
					where result='sunk'
					and c1.country=c.country)
from classes c;


-- 4 (pc) (5 т.)
-- Да се изведат различните модели компютри, чиято цена 
-- е по-ниска от най-евтиния лаптоп, произвеждан от същия производител.
set schema pc;

select distinct pc.model
from pc join product p on pc.model=p.model
where price < (select min(price) from laptop
	join product t 
	on laptop.model=t.model
	where t.maker=p.maker);
	
-- Вариант 2 - Решения

-- 1 (movies) (2 т.)
-- Да се напише заявка, която извежда имената и пола на всички актьори (без значение мъж или жена), чието име започва с 'J'
-- и са родени след 1948 година. Резултатът да бъде подреден по име в намаляващ ред.

set schema movies;

select name, gender
from moviestar
where name like 'J%' and year(birthdate)>1948
order by name desc;

-- 3 (ships) (4 т.)
-- Да се напише заявка, която извежда име и държава на всички кораби, които никога 
-- не са потъвали в битка (може и да не са участвали).

set schema ships;

-- I
select name, country
from ships
join classes on ships.class=classes.class
where name not in
 (select ship from outcomes where result='sunk');
 
-- II
 
 select name, country
 from ships left join outcomes on name=ship
 join classes on ships.class=classes.class
 where result<>'sunk' or battle is null;

-- 2 (pc) (3 т.)
-- Да се напише заявка, която извежда всички модели лаптопи, за които се предлагат 
-- както разновидности с 15" екран, така и с 11" екран.

set schema pc;

select model, code, screen
from laptop 
where screen=15 or screen=11;

-- 4 (pc) (5 т.)
-- Един модел компютри може да се предлага в няколко разновидности 
-- с евентуално различна цена. Да се изведат тези модели компютри, чиято средна цена 
-- (на различните му разновидности) е по-ниска от най-евтиния лаптоп.
set schema pc;

-- I (с group by)
select model
from pc
group by model
having avg(price)<(select min(price) from laptop);	

-- (без group by)

-- Вариант 3 - Решения

-- 1 (ships) (2 т.)
-- Да се напише заявка, която извежда имената на всички кораби без повторения, които 
-- са участвали в поне една битка и чиито имена започват с буквите C или K.

set schema ships;

select distinct ship 
from outcomes
where ship like 'C%' or ship like 'K%';

-- 3 (movies) (4 т.)
-- Да се напише заявка, която извежда името на филма, годината и броят на актьорите 
-- участвали в този филм, за тези филми с повече от 2-ма актьори.

set schema movies;

-- I (с group by)
select movietitle, movieyear
from starsin  
group by movietitle, movieyear
having count(*) > 2;

-- II (без group by)
select distinct s1.movietitle, s1.movieyear
from starsin s1, starsin s2, starsin s3,
movie m1, movie m2, movie m3
where s1.starname<>s2.starname and
s2.starname<>s3.starname
and s1.starname<>s3.starname
and m1.title=s1.movietitle and m1.year=s1.movieyear
and m2.title=s2.movietitle and m2.year=s2.movieyear
and m3.title=s3.movietitle and m3.year=s3.movieyear
and m1.title=m2.title and m1.title=m3.title
and m1.year=m2.year and m1.year=m3.year;

-- 2 (pc) (3 т.) 
-- Да се напише заявка, която извежда за всеки компютър: 
-- код на продукта (code); производител; брой компютри, които имат цена, 
-- по-голяма или равна на неговата.

set schema pc;

-- I (с group by)

select p1.code, maker,  count(p2.code) 
from pc p1, pc p2, product
where p1.price <= p2.price and p1.model=product.model and p2.model=product.model
group by p1.code, maker;

-- II (без group by)

select distinct code, maker,(select count(p2.code) 
					from pc p2
					where p2.price >= p1.price 
					and p2.model=p1.model)
from pc p1, product
where p1.model=product.model
order by code;				



-- 4 (pc) (5 т.)
-- Един модел компютри може да се предлага в няколко разновидности 
-- с евентуално различна цена. Да се изведат тези модели компютри, чиято сума от цените 
-- (на различните му разновидности) е по-ниска от сумата на цените на лаптопите.
set schema pc;

-- I (с group by и корелация)

select pc.model, sum(price) from pc
join product p on pc.model=p.model
group by pc.model
having sum(price) < (select sum(price) from laptop
	join product t 
	on laptop.model=t.model);
	
-- Допълнителна задача - Решение
	
-- Един модел компютри може да се предлага в няколко разновидности 
-- с евентуално различна цена. Да се изведат тези модели компютри, чиято средна цена 
-- (на различните му разновидности) е по-ниска от най-евтиния лаптоп, произвеждан 
-- от същия производител.

set schema pc;

-- I (с group by и корелация)

select pc.model, avg(price) from pc
join product p on pc.model=p.model
group by pc.model, p.maker
having avg(price) < (select min(price) from laptop
	join product t 
	on laptop.model=t.model
	where t.maker=p.maker);
