set schema DB2PC;

-- Напишете заявка, която извежда производителите на персонални компютри с
-- честота поне 500 (500 включително).
  select distinct maker
    from Product
    where model in (select model from PC where speed >= 500)
    order by maker;

-- Напишете заявка, която извежда принтерите с най-висока цена.
  select *
    from Printer
    where price >= all(select price from Printer);

-- Напишете заявка, която извежда лаптопите, чиято честота е по-ниска от
-- честотата на всеки персонален компютър.
  select *
    from Laptop
    where speed < all(select distinct speed from PC);

-- Напишете заявка, която извежда производителя на цветния принтер с най-ниска цена.
  select maker
    from Product
    where model in
      (select model
        from Printer
        where color = 'y' and
              price <= all(select price from Printer where color = 'y'));

-- Напишете заявка, която извежда производителите на тези персонални компютри, които имат
-- минималната RAM памет и са с най-бърз процесор (в сравнение с тези с минимална RAM памет).
  select maker
    from product
    where model in
      (select model
        from PC p
        where ram <= all(select distinct ram from PC) and
              speed >= all(select distinct speed from PC where ram=p.ram));