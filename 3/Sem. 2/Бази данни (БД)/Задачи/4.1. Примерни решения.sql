set schema movies; 

  select name
  from moviestar
  where name in (
  select name
  from movieexec
  where networth>10000000) and gender='F';

  select name
  from moviestar
  where name not in (select name from movieexec);

  select title
  from movie 
  where length > ( select length
       from movie
       where title='Gone With the Wind');


  select title,t.name
  from movie m,
  (select cert#, name
   from movieexec
   where networth > ( select networth
             from movieexec
             where name='Merv Griffin')) t
  where m.producerc#=t.cert#;


  select studioname, title, length
  from movie m
  where length >= all (select length 
           from movie
           where studioname=m.studioname)
    
set schema pc; 

  select maker
  from product
  where model in (select model from pc where speed > 500);

  select code, model, price
  from printer
  where price >= ALL(select price from printer);

  select * 
  from laptop
  where speed < all(select distinct speed from pc);

  select maker
  from product
  where model in 
  (select model
   from printer
   where color='y' and price <= ALL(select price from printer where color='y'));

  select maker
  from product
  where model in 
  (select model
  from pc p
  where ram <= ALL(select ram from pc) and speed >= ALL(select speed from pc where ram=p.ram));
   
set schema ships;

  select distinct country
  from classes
  where numguns >= all(select numguns from classes);

  select distinct class
  from ships
  where name = ANY
  (
  select ship 
  from outcomes
  where result='sunk');

  select distinct name, class
  from ships
  where class in
  (
  select class
  from classes
  where bore=16
  ); 

  select battle
  from outcomes
  where ship in
  (select name
   from ships
   where class = 'Kongo');

  select c1. class, name
  from classes c1, ships s
  where numguns >= all (select numguns from classes where bore=c1.bore)
  and s.class = c1.class
  order by c1.class;