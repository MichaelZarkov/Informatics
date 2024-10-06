set schema DB2MOVIE;

-- Напишете заявка, която извежда имената на актьорите мъже участвали в 'Terms of Endearment'.
select starName
  from MovieStar, StarsIn
  where gender = 'M' and movieTitle = 'Terms of Endearment' and name = starName;

-- Напишете заявка, която извежда имената на актьорите участвали във филми
-- продуцирани от 'MGM' през 1995г.
select starName
  from StarsIn, Movie
  where movieTitle = title and movieYear = year and movieYear = 1995 and studioName = 'MGM';

-- Напишете заявка, която извежда името на президента на 'MGM'.
select distinct name
  from Movie, MovieExec
  where studioName = 'MGM' and producerc# = cert#;

-- Напишете заявка, която извежда имената на всички филми с дължина по-голяма
-- от дължината на филма 'Gone With the Wind'.
select m2.title
  from Movie m1, Movie m2
  where m1.title = 'Gone With the Wind' and m1.length < m2.length;

-- Напишете заявка, която извежда имената на тези продуценти
-- на стойност по-голяма от продуцента 'Merv Griffin'.
select m2.name
  from MovieExec m1, MovieExec m2
  where m1.name = 'Merv Griffin' and m1.networth < m2.NETWORTH;