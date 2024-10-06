-- ���������� 4

-- ��� 1. �� ������ �� ����� Movies
set schema DB2MOVIES;

-- �������� ������, ����� ������� ������� �� ������� � ����� ��
-- ����������, ����������� �� ���������� �� 'Star Wars'
-- ������� 1
select title, t.name
from movie m join
(select name, cert#
from movieexec
where cert# in (select producerc#
               from movie
               where title='Star Wars')) t
on m.producerc#=t.cert#;

-- ������� 2
select title, name
from movie m join movieexec me
on m.producerc#=me.cert#
where me.cert# in (select producerc#
               from movie
               where title='Star Wars');

-- �������� ������, ����� ������� ������� �� ������������ �� ������� �� 'Harrison Ford'
select distinct me.name
from movie m join starsin s
on m.title=s.movietitle and m.year=s.movieyear
join movieexec me on m.producerc#=me.cert#
where starname='Harrison Ford';

-- �������� ������, ����� ������� ����� �� �������� � ������� �� ��������� ��������� ��� ����� ����������� �� ����
-- ������, ��������� �� ��� �� ������.
select distinct s.name, si.starname
from studio s join movie m on s.name=m.studioname
join starsin si on m.title=si.movietitle and m.year=si.movieyear
order by s.name;

-- �������� ������, ����� ������� ������� �� ������� (���������) ��������� ��� ����� �� ���-������ ��������.
select si.starname, t.networth, m.title
from starsin si join movie m on si.movietitle=m.title and
si.movieyear=m.year join (
select cert#, networth
from movieexec
where networth >= all (select networth from movieexec)) t
on m.producerc#=t.cert#;

-- �������� ������, ����� ������� ������� �� ��������� �� ��������� � ���� ���� ����. (����������� ����������!)
select ms.name, si.movietitle
from moviestar ms left join starsin si
on ms.name=si.starname
where si.movietitle is NULL;

-- ��� 2. �� ������ �� ����� PC
set schema DB2PC;

-- �������� ������, ����� ������� ������������, ����� � ��� �� ������� �� ���� �������������, �� ����� �����������
-- ������� �� �� ������� (���� �� � ��������� PC, ������ ��� �������).
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

-- ��� 3. �� ������ �� ����� SHIPS
set schema ships;

-- �������� ������, ����� ������� ������ ������� ���������� �� ����� �����, ����������� � ������� �� ������� ����.
-- � ��������� �� ������ �� �� �������� ���� �������, ����� ����� ������.
select * from
ships s right join classes c on s.class=c.class
where s.name is not NULL;

-- ��������� ������� ������ ���� ���� ��� �������� � ��������� � ���������, ����� ����� ������, �� ����������� ������
-- ��� ������ ��� ���� �������.
select * from
ships s right join classes c on s.class=c.class
where s.name is not NULL
union
select * from
ships s right join classes c on s.class=c.class
where s.name is NULL and c.class in (select name from ships);

-- �� ����� ������ �������� ������� �� ��������, ����� ������ �� �� ��������� � �����.
select distinct c.country, s.name
from classes c join ships s on c.class=s.class
left join outcomes o on s.name=o.ship
where o.ship is NULL
order by c.country;

