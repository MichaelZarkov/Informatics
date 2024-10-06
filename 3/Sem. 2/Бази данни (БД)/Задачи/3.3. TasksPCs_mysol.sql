set schema DB2PC;

-- Напишете заявка, която извежда производителя и честотата на тези лаптопи с
-- размер на диска поне 9GB.
select Product.maker, Laptop.speed
  from Product, Laptop
  where Laptop.HD > 9 and Laptop.model = Product.model;
-- Reference:
select maker, speed
  from product,laptop
  where product.model = laptop.model and hd > 9;

-- Напишете заявка, която извежда номер на модел, цена и тип на всички продукти,
-- произведени от производител с име 'B'.
(select Product.model, Laptop.price, Product.type
 from Product, Laptop
 where Product.maker = 'B' and Product.model = Laptop.model)
union
(select Product.model, PC.price, Product.type
 from Product, PC
 where Product.maker = 'B' and Product.model = PC.model)
union
(select Product.model, Printer.price, Product.type
 from Product, Printer
 where Product.maker = 'B' and Product.model = Printer.model);

-- Напишете заявка, която извежда размерите на тези дискове, които се предлагат в
-- повече от два компютъра.
select distinct pc1.HD
  from PC pc1, PC pc2
  where pc1.code <> pc2.code and pc1.HD = pc2.HD
  order by pc1.hd;

-- Напишете заявка, която извежда размерите на тези дискове, които се предлагат в
-- повече от три компютъра.
select distinct pc1.hd
  from PC as pc1, PC as pc2, PC as pc3
  where pc1.model <> pc2.model and pc1.model <> pc3.model and pc2.model <> pc3.model and
        pc1.hd=pc2.hd and pc2.hd=pc3.hd
  order by pc1.hd;

-- Напишете заявка, която извежда всички двойки модели на компютри, които
-- имат еднаква честота и памет. Двойките трябва да се показват само по веднъж,
-- например само (i, j), но не и (j, i).
select distinct pc1.model, pc2.model
  from PC as pc1, PC as pc2
  where pc1.model < pc2.model and  -- Allow only one of (i,j) or (j,i). Don't allow (i,i).
        pc1.speed = pc2.speed and pc1.RAM = pc2.RAM
  order by pc1.model;

-- Напишете заявка, която извежда производителите на поне два различни
-- компютъра с честота поне 400.
select distinct p1.maker
  from Product p1, Product p2, PC pc1, PC pc2
  where p1.model <> p2.model and p1.maker = p2.maker and
        p1.type = 'PC' and p1.type = 'PC' and
        pc1.model = p1.model and pc2.model = p2.model and
        pc1.speed >= 400 and pc2.speed >= 400
  order by p1.maker;