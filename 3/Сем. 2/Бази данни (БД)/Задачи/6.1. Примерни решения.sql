/* ��������� */

-- ��� 1. �� ������ �� ����� PC

set schema DB2PC;

-- �������� ������, ����� ������� �������� ������� �� ����������
select decimal(avg(speed),9,2) as AvgSpeed 
from pc;

-- �������� ������, ����� ������� ������� ������ �� �������� �� ��������� �� ����� 
-- ������������
select p.maker, decimal(avg(screen), 9, 2) as AvgScreen
from laptop l join product p on p.model=l.model
group by p.maker;

-- �������� ������, ����� ������� �������� ������� �� ��������� � ���� ��� 1000
select decimal(avg(speed),9,2) as AvgSpeed
from laptop
where price > 1000;

-- �������� ������, ����� ������� �������� ���� �� ���������� ����������� �� 
-- ������������ 'A'
select p.maker, decimal(avg(price), 9, 2) as AvgPrice
from pc join product p on p.model=pc.model
where p.maker = 'A'
group by p.maker;

-- �������� ������, ����� ������� �������� ���� �� ���������� � ��������� �� 
-- ������������ 'B'
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

-- �������� ������, ����� ������� �������� ���� �� ���������� ������ ���������� �� �������
select speed, decimal(avg(price), 9, 2) as AvgPrice
from pc
group by speed;

-- �������� ������, ����� ������� �������������, ����� � �������� ���� 3 �������� 
-- ������ ���������
select p.maker, count(p.model) as CNT
from pc join product p on p.model=pc.model
where p.type='PC'
group by p.maker
having count(p.model)>=3;

-- �������� ������, ����� ������� ������������� � ���-������ ���� �� ��������
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

-- �������� ������, ����� ������� �������� ���� �� ���������� �� ����� ������� ��-������
-- �� 800
select speed, decimal(avg(price), 9, 2) as AvgPrice
from pc
where speed > 800
group by speed;

-- �������� ������, ����� ������� ������� ������ �� ����� �� ���� �������� ����������� 
-- �� �������������, ����� ����������� � ��������
select decimal(avg(hd), 9, 2) as AvgHDD
from pc join product p on p.model=pc.model
where maker in
(select distinct maker
from product
where type='Printer');

-- ��� 2. �� ������ �� ����� SHIPS 

 set schema ships;
 
-- �������� ������, ����� ������� ���� �� ��������� ������
select count(class)
from classes;

-- �������� ������, ����� ������� ������� ���� �� ������, ������ ����� �� ������
select class, avg(numGuns) as avgGuns
from classes
group by class;

-- �������� ������, ����� ������� ������� ���� �� ������ �� ������ ������
select avg(numGuns) as avgGuns
from classes c join ships s on c.class=s.class;

-- �������� ������, ����� ������� �� ����� ���� ������� � ���������� ������, 
-- � ����� ����� �� ���������� ���� � ������ �� ����
select c.class, min(s.launched) as FirstYear, max(s.launched) as LastYear
from classes c join ships s on c.class=s.class
group by c.class
order by c.class;

-- �������� ������, ����� ������� ���� �� �������� �������� � ����� ������ �����
select class, count(o.ship)
from ships s join outcomes o on s.name=o.ship
where o.result='sunk'
group by class;

-- �������� ������, ����� ������� ���� �� �������� �������� � ����� ������ �����, 
-- �� ���� ������� � ������ �� 2 ������
-- I �������
select class
from ships s join outcomes o on s.name=o.ship
group by class
having count(o.ship)>=2
intersect
select class
from ships s join outcomes o on s.name=o.ship
where o.result='sunk';


-- II �������
select class,count(name) as "Number of sunk ships"
from ships s join outcomes o on s.name=o.ship
where result='sunk' and class in (select c.class
								  from classes c join ships s on c.class=s.class
								  group by c.class
								  having count(name)>2)
group by class;

-- �������� ������, ����� ������� �������� ����� �� ��������, �� ����� ������. 
-- I �������
select country, decimal(sum(weight)/sum(br), 9, 2) as AvgWeioght
from 
(
select c.country, c.class, count(s.name)as br,count(s.name)* c.bore as Weight
from classes c join ships s on c.class=s.class
group by c.country, c.class, c.bore) T
group by country;


-- II �������
select country,avg(c.bore) as avg_displacement
from classes c join ships s on c.class=s.class
group by country;