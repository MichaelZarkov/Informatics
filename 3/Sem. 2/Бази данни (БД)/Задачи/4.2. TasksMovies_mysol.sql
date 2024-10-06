set schema DB2MOVIE;

-- Напишете заявка, която извежда имената на актрисите, които са също и
-- продуценти с нетна стойност по-голяма от 10 милиона.
-- Първи вариант без подзаявки:
  select MovieStar.name
    from MovieStar, MovieExec
    where gender = 'F' and MovieStar.name = MovieExec.name and networth > 10000000;
  -- Втори вариант с подзаявка:
  select name
    from MovieExec
    where networth > 10000000 and
          name in (select name
                     from MovieStar
                     where gender = 'F');

-- Напишете заявка, която извежда имената на тези актьори (мъже и жени), които
-- не са продуценти.
  select name
    from MovieStar
    where name not in (select name from MovieExec);

-- Напишете заявка, която извежда имената на всички филми с дължина по-голяма
-- от дължината на филма 'Gone With the Wind'.
-- Вариант 1 с подзаявка:
  select title
    from Movie
    where length > (select length
                      from Movie
                      where title = 'Gone With the Wind');
  -- Вариант 2 без подзаявка:
  select M1.title
    from Movie M1, Movie M2
    where M1.length > M2.length and M2.title = 'Gone With the Wind';

-- Напишете заявка, която извежда имената на тези продуценти
-- с NETWORTH по-голям от продуцента 'Merv Griffin'.
  select name
    from MovieExec
    where networth > (select networth from MovieExec where name = 'Merv Griffin');

-- Напишете заявка, която извежда заглавията на филмите на продуцентите и имената на
-- продуцентите, които са с по-голям NETWORTH от продуцента 'Merv Griffin'.
  select title, P.name
    from Movie,
         (select name, cert# from MovieExec
         where networth > (select networth from MovieExec where name = 'Merv Griffin')) as P
    where Movie.producerc# = P.cert#;

-- Напишете заявка, която извежда името на филмите от всяко студио с най-голяма дължина.
  select M.studioname, M.title, M.length
    from Movie M
    where M.length >= all(select length from Movie where studioname = M.studioname);
