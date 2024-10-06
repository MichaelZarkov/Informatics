-- Упражнение 4

-- Зад 1. За базата от данни Movies
set schema DB2MOVIES;

-- Напишете заявка, която извежда имената на филмите и името на
-- продуцента, продуцирани от продуцента на 'Star Wars'
-- Вариант 1
select title, t.name
from movie m join
(select name, cert#
from movieexec
where cert# in (select producerc#
               from movie
               where title='Star Wars')) t
on m.producerc#=t.cert#;

-- Варинат 2
select title, name
from movie m join movieexec me
on m.producerc#=me.cert#
where me.cert# in (select producerc#
               from movie
               where title='Star Wars');

-- Напишете заявка, която извежда имената на продуцентите на филмите на 'Harrison Ford'
select distinct me.name
from movie m join starsin s
on m.title=s.movietitle and m.year=s.movieyear
join movieexec me on m.producerc#=me.cert#
where starname='Harrison Ford';

-- Напишете заявка, която извежда името на студиото и имената на актьорите участвали във филми произведени от това
-- студио, подредени по име на студио.
select distinct s.name, si.starname
from studio s join movie m on s.name=m.studioname
join starsin si on m.title=si.movietitle and m.year=si.movieyear
order by s.name;

-- Напишете заявка, която извежда имената на актьора (актьорите) участвали във филми на най-голяма стойност.
select si.starname, t.networth, m.title
from starsin si join movie m on si.movietitle=m.title and
si.movieyear=m.year join (
select cert#, networth
from movieexec
where networth >= all (select networth from movieexec)) t
on m.producerc#=t.cert#;

-- Напишете заявка, която извежда имената на актьорите не участвали в нито един филм. (Използвайте съединение!)
select ms.name, si.movietitle
from moviestar ms left join starsin si
on ms.name=si.starname
where si.movietitle is NULL;

-- Зад 2. За базата от данни PC
set schema DB2PC;

-- Напишете заявка, която извежда производител, модел и тип на продукт за тези производители, за които съответният
-- продукт не се продава (няма го в таблиците PC, лаптоп или принтер).
select p.*
from product p left join pc on p.model=pc.model
where type='PC' and code is NULL
union
select p.*
from product p left join printer pp on p.model=pp.model
where p.type='Printer' and code is NULL
union
select p.*
from product p left join laptop l on p.model=l.model
where type='Laptop' and code is NULL;

-- Зад 3. За базата от данни SHIPS
set schema ships;

-- Напишете заявка, която извежда цялата налична информация за всеки кораб, включително и данните за неговия клас.
-- В резултата не трябва да се включват тези класове, които нямат кораби.
select * from
ships s right join classes c on s.class=c.class
where s.name is not NULL;

-- Повторете горната заявка като този път включите в резултата и класовете, които нямат кораби, но съществуват кораби
-- със същото име като тяхното.
select * from
ships s right join classes c on s.class=c.class
where s.name is not NULL
union
select * from
ships s right join classes c on s.class=c.class
where s.name is NULL and c.class in (select name from ships);

-- За всяка страна изведете имената на корабите, които никога не са участвали в битка.
select distinct c.country, s.name
from classes c join ships s on c.class=s.class
left join outcomes o on s.name=o.ship
where o.ship is NULL
order by c.country;

