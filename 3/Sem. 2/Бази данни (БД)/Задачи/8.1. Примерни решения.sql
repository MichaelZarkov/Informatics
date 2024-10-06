-- ������� 1 - �������

-- 1 (movies) (2 �.)
-- �� �� ������ ������, ����� ������� ������� � �������� �� ������ �����, 
-- ����� �� ��-����� �� 120 ������ � �� ������� ����� 1990 �. ��� ��������� �� ����� � ����������
-- (NULL), ����� � �������� �� ���� ���� ���� �� �� �������.

set schema movies;

select title, year, length
from movie
where length>120 and year<1990 or length is NULL;

-- 2 (movies) (3 �.)
-- �� �� ������ ������, ����� ������� ������� �� ���-������ ������ (���). 
-- ���������: ����� �� ������� ���� �� ���� 'M' ��� 'F'. 

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

-- 3 (ships) (4 �.)
-- �� �� ������ ������, ����� ������� ��������� � ����� �� ���������� ������ �� ���� �������.
-- �������, ����� ����� ������ ��� ���� �����, �� ��� �� � �������� � �����, ���� �� 
-- ����� ��������.

set schema ships;

-- I (� group by)
select c.country , count(o.result) as Sunk
from classes c left join ships s on c.class=s.class 
left join outcomes o on s.name=o.ship 
where result='sunk' or result is NULL
group by c.country;

-- II (��� group by)

select distinct c.country , (select count(o.result) as Sunk
					from classes c1 left join ships s on c1.class=s.class 
					left join outcomes o on s.name=o.ship 
					where result='sunk'
					and c1.country=c.country)
from classes c;


-- 4 (pc) (5 �.)
-- �� �� ������� ���������� ������ ��������, ����� ���� 
-- � ��-����� �� ���-������� ������, ����������� �� ����� ������������.
set schema pc;

select distinct pc.model
from pc join product p on pc.model=p.model
where price < (select min(price) from laptop
	join product t 
	on laptop.model=t.model
	where t.maker=p.maker);
	
-- ������� 2 - �������

-- 1 (movies) (2 �.)
-- �� �� ������ ������, ����� ������� ������� � ���� �� ������ ������� (��� �������� ��� ��� ����), ����� ��� ������� � 'J'
-- � �� ������ ���� 1948 ������. ���������� �� ���� �������� �� ��� � ��������� ���.

set schema movies;

select name, gender
from moviestar
where name like 'J%' and year(birthdate)>1948
order by name desc;

-- 3 (ships) (4 �.)
-- �� �� ������ ������, ����� ������� ��� � ������� �� ������ ������, ����� ������ 
-- �� �� �������� � ����� (���� � �� �� �� ���������).

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

-- 2 (pc) (3 �.)
-- �� �� ������ ������, ����� ������� ������ ������ �������, �� ����� �� ��������� 
-- ����� ������������� � 15" �����, ���� � � 11" �����.

set schema pc;

select model, code, screen
from laptop 
where screen=15 or screen=11;

-- 4 (pc) (5 �.)
-- ���� ����� �������� ���� �� �� �������� � ������� ������������� 
-- � ���������� �������� ����. �� �� ������� ���� ������ ��������, ����� ������ ���� 
-- (�� ���������� �� �������������) � ��-����� �� ���-������� ������.
set schema pc;

-- I (� group by)
select model
from pc
group by model
having avg(price)<(select min(price) from laptop);	

-- (��� group by)

-- ������� 3 - �������

-- 1 (ships) (2 �.)
-- �� �� ������ ������, ����� ������� ������� �� ������ ������ ��� ����������, ����� 
-- �� ��������� � ���� ���� ����� � ����� ����� �������� � ������� C ��� K.

set schema ships;

select distinct ship 
from outcomes
where ship like 'C%' or ship like 'K%';

-- 3 (movies) (4 �.)
-- �� �� ������ ������, ����� ������� ����� �� �����, �������� � ����� �� ��������� 
-- ��������� � ���� ����, �� ���� ����� � ������ �� 2-�� �������.

set schema movies;

-- I (� group by)
select movietitle, movieyear
from starsin  
group by movietitle, movieyear
having count(*) > 2;

-- II (��� group by)
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

-- 2 (pc) (3 �.) 
-- �� �� ������ ������, ����� ������� �� ����� ��������: 
-- ��� �� �������� (code); ������������; ���� ��������, ����� ���� ����, 
-- ��-������ ��� ����� �� ��������.

set schema pc;

-- I (� group by)

select p1.code, maker,  count(p2.code) 
from pc p1, pc p2, product
where p1.price <= p2.price and p1.model=product.model and p2.model=product.model
group by p1.code, maker;

-- II (��� group by)

select distinct code, maker,(select count(p2.code) 
					from pc p2
					where p2.price >= p1.price 
					and p2.model=p1.model)
from pc p1, product
where p1.model=product.model
order by code;				



-- 4 (pc) (5 �.)
-- ���� ����� �������� ���� �� �� �������� � ������� ������������� 
-- � ���������� �������� ����. �� �� ������� ���� ������ ��������, ����� ���� �� ������ 
-- (�� ���������� �� �������������) � ��-����� �� ������ �� ������ �� ���������.
set schema pc;

-- I (� group by � ���������)

select pc.model, sum(price) from pc
join product p on pc.model=p.model
group by pc.model
having sum(price) < (select sum(price) from laptop
	join product t 
	on laptop.model=t.model);
	
-- ������������ ������ - �������
	
-- ���� ����� �������� ���� �� �� �������� � ������� ������������� 
-- � ���������� �������� ����. �� �� ������� ���� ������ ��������, ����� ������ ���� 
-- (�� ���������� �� �������������) � ��-����� �� ���-������� ������, ����������� 
-- �� ����� ������������.

set schema pc;

-- I (� group by � ���������)

select pc.model, avg(price) from pc
join product p on pc.model=p.model
group by pc.model, p.maker
having avg(price) < (select min(price) from laptop
	join product t 
	on laptop.model=t.model
	where t.maker=p.maker);
