
-- Make a request which returns the address of the studio 'MGM'.
SELECT STUDIO.ADDRESS FROM STUDIO WHERE STUDIO.NAME = 'MGM';

-- Make a request which returns the birth date of Sandra Bullock.
SELECT MOVIESTAR.BIRTHDATE FROM MOVIESTAR WHERE MOVIESTAR.NAME = 'Sandra Bullock';

-- Make a request which returns the names of all actors which were in a movie from 1977
-- and in the title of the movie there is the word "Wars".
SELECT STARSIN.STARNAME FROM STARSIN
WHERE STARSIN.MOVIEYEAR = 1977 AND STARSIN.MOVIETITLE LIKE '%Wars%';

-- Make a request that returns the names of all producers
-- with net worth over 10 000 000 dollars.
SELECT MOVIEEXEC.NAME FROM MOVIEEXEC WHERE MOVIEEXEC.NETWORTH > 10000000;

-- Make a request that returns the names of all actors which are men or live in Malibu.
SELECT MOVIESTAR.NAME FROM MOVIESTAR
WHERE MOVIESTAR.GENDER = 'M' OR MOVIESTAR.ADDRESS = 'Malibu';
