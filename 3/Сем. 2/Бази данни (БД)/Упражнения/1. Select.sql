-- Author Michael Zarkov.
-- Този файл не е предназначен за компилация (въпреки че най-вероятно всичко е вярно и ще се компилира).
-- Файлът съдържа обяснения и примери с SQL командата SELECT, както и уводни бележки за SQL.

/*
  Отделни части информация:
  
  Символни низове:
    - Символните низове се ограждат със единични кавички ''.
    - За да се запише кавичка в низ се ползват две кавички, например: 'Bob''s bike' е низът "Bob's bike".
    - При pattern matching, за да се интерпретират % и _ като буквалните символи, задаваме escape character за
      конкретния низ(pattern) с ключовата дума "escape".
      Пример:
        <attribute> like 'm%%m%' escape 'm' - зададохме "m" като escape character. Ще мачнем низовете, които започват
                                              и завършват на %.
  
  Semicolon:
    - не е задължително, но е добра практика да се слага в края на всеки statement.
  
  Table.Attribute:
    - Да кажем, че имаме релацията: Movie(Name, Year, Length). Може може само с Name "да се обърнем" към атрибута
      Name, а може и да уточним Movie.Name (например, ако имаме две таблици с атрибут с едно и също име).

  Case sensitivity:
    - SQL е case insensitive относно ключовите думи. Тоест SELECT, FROM, WHERE ... е същото като select, from, where.
      В тези записки ключовите думи ще са предимно с малки букви.
    - В повечето случаи имената на таблици и атрибути са case insensitive. Тоест ONLINEUSERS е същото като onlineusers
      е същото като OnlineUsers. Основно ще ползвам PascalCase или cammelCase за имената.
      
  Оператори:
    За сравнение:
      <> и != - оператори "не е равно на" (двете са напълно еквивалентни).
    Други:
      || - конкатенация на низове.
*/

/*
  SELECT statement:
    - "The SQL SELECT statement returns a result set of records, from one or more tables." - тоест select ни позволява
      да извличаме информация от базата данни и всъщност това ще ни е основната команда за извличане на информация.
    - select е част от подезика data manipulation language (DML).
    - Клаузи, които може да ползваме със select:
      - as - преименува върнатата колона.
      - distinct - връща само редовете с различни стойности.
      - where <predicate> - за филтриране на редове. Ползва се непрекъснато.
      - <attribute> is null - предикат за тестване дали атрибутът има стойност.
      - <attribute> between x and y - истина, ако атрибутът е в затворения интервала [x,y]. x,y може да са числа,
        низове и дати (но не знам как точно се сравняват низове и дати).
      - <attribute> in (x1,...,xn) - истина, ако атрибутът е от множеството {x1,...,xn}.
      - <attribute> like '<pattern>' - истина, ако низът съответства на шаблона.
        - Специални символи:
          '%' - съответства на един или повече произволни символа.
          '_' - съответства на точно един произволен символ.
      - not, and, or - отрицание, конюнкция, дизюнкция. Приоритетът им е в този ред.
*/

/*
  Приемам, че имам следните релации(таблици) от базата данни Movies в примерите отдолу:
    Movie(Title, Year, Length, InColor, StudioName, ProducerC#)
    MovieExec(Cert#, Name, Address, NetWorth)
    MovieStar(Name, Address, Gender, BirthData)
    StarsIn(MovieTitle, MovieYear, StarName)
    Studio(Name, Address, Presc#)
*/
-- Примери за работа със select:

-- Връща всички редове и колони от релацията Movie.
select * from Movie;

-- Връща само колоните title и year.
select title, year from Movie;
-- Можеше да напиша и по-уточнено:
select Movie.title, Movie.year from Movie;
-- или също:
SELECT title, YEAR From MoVIe;  -- не е красиво ;)

-- Връща колоната title и колоната length със стойности разделени на 60.
select title, length / 60 from Movie;

-- Клаузата "as" - преименува върнатата колона.
select title as movie_title from Movie;

-- Връща редовете с различни title и length.
-- Ако имаме:
--   1. (Title 1, 120)
--   2. (Title 2, 120)
--   3. (Title 1, 100)
--   4. (Title 1, 120)
-- Резултатът ще е:
--   1. (Title 1, 120)
--   2. (Title 2, 120)
--   3. (Title 1, 100)
select distinct title, lenght  from Movie;

-- Връща имената на филмите, които са продължителност под 110 минути.
select title from Movie where lenght < 110;

-- Сравнение със низ.
-- Връща филмите, които са произведени от студиото Fox (обърни внимание, че кавичките са единични).
select * from Movie where studioName = 'Fox';

-- Връща имената на филмите, за които producerC# няма стойност.
select title from Movie where producerC# is null;

-- Връща имената на филмите с продължителност между 100 и 140 минути включително.
select title from Movie where length between 100 and 140;

-- Връща имената на филмите с продължителност 100, 110 или 112 минути.
select title from Movie where length in (100,110,112);

-- Връща имената на филмите, които започват със "Star".
select title from Movie where title like 'Star%';

-- Връща имената на филмите, които съдържат точно 4 символа.
select title from Movie where title like '____';

-- Връща името и годината на филмите, които или са с продължителност 111 или 119 мин. и името им започва със "S", или
-- името им завършва на "Wars".
select title, year, length from Movie
where (length not in (111, 119) and title like 'S%') or title like '%Wars';