# Записки от упражнения

## Упражнение 1, 04.10.2024 

Пропуснах го.

## Упражнение 2, 11.10.2024

### Файлови системи

Файловите системи не влизат в изпита.

**Заб.** Може да прочета за различни имплементации на файлови системи.  
**Заб.** Конкретно да прочета за файловата система в Unix.  
**Заб.** Препоръча да прочетем книгата на курса: "Modern operating systems (Tannenbaum)" - нещата, които дискутирахме ги пише там.  

Може би най-простата дефиниция на файл: набор от байтове, които са именувани (т.е. има конкретно наименование).

Имплементацията на файловата система в Unix (паметта е разделена на блокове). Какво точно значеше *inode*. Обсъдихме някои проблеми при направата на файлова система.
Различни схеми за алокация на памет за файлове (съответно какви са предимствата и недостатъците им):
- contiguous allocation.
- linked list allocation - бавно четене поради няколко причини:
  - изисква O(n) "скачания" по паметта на диска, което е бавно.
- file allocation table (FAT - оттам идва и името нас FAT файловата система).

Най-често ползваната имплементация на файлова система:
- за всеки файл съществува един **i-node**. i-node-ът е някаква структура в която се пази някаква 
  информация за файла. Да погледна как точно работят нещата.
- Директориите в Unix са файлове, които пазят имената на файловете и съответните идентификаторите на 
  i-node-ове, които се "съдържат" в директорията.

#### Директории

В Unix директориите са файлове. Всъщност в директориите се пазят имената на файловете и "указатели" към *i-node-овете* на файловете. 
В *i-node-овете* се пази типа на файла - дали е директория, дали е обикновен файл. Когато пътят към файл започва с `/`, то това е абсолютен път до файла от корена. 
Коренът на файловата система в Unix отбелязваме с `/` и същия символ ползваме за разделител между имената да директориите от пътя.  
Пример:
```bash
# Absolute path from the root
/dir1/dir2/file1
# Relative path
dir3/dir4/file2
```

### Bash

**Shell** е програма, която ни дава команден интерфейс, с който да комуникираме с операционната система. Пишем текстови команди и операционната система ги изпълнява.
**Bash** е вид **shell**. Bash е програма, която чете от стандартния си вход команди и ги изпълнява (не е задължително стандартният вход да е клавиатурата, може да е файл на пример).

Разликата между програма и процес.

## Упражнение 3, 18.10.2024

Основни команди, които ще ползваме днес: `ls, cd, touch, mkdir, mv, rm, cp, man, chmod`.

Други команди, които споменахме: `which, gcc, env, stat, groups`.
- `ln` - инструмент за създавана на hard и soft линкове.

`printf` да науча важните специфики (**C** `printf` и **bash** `printf`).

С `gcc <filepath>` може да компилираме `.c` файлове.

Името на програмата се подава като аргумент на програмата като първи аргумент. 
Затова `argc` (argument count) е с едно повече от очакваното. Пример за подаване на аргументи на 
програма е `cd <path>`. Може и без аргументи да извикаме `cd` - това ни завежда в нашата home 
директория. 

### Environment Variables

Какво представляват.

Пример: променливата `PATH` - къде **bash** търси изпълнимите команди(програми). Можем да добавяме 
пътища към `PATH`, но най-вероятно няма никога да се наложи да го ползваме.

Ако имаме наши команди(програмки) в някаква си наша директория може да ги викаме така например 
(ако програмата е в текущата директория):
```
./<my-command> <arg1> <arg2> ... <argn>
``` 

### Задачи

**Зад. 0:** Направете копие на файла `/etc/passwd` във вашата home директория и го наречете `my_passwd`.
```bash
cp /etc/passwd ~/my_passwd
```

**Зад. 1:** Направете директория `practice-test` в home директорията ви. Вътре направете
директория `test1`. Можете ли да направите тези две неща наведнъж? Разгледайте нужната man страница. 
След това създайте празен файл вътре, който да се казва `test.txt`, преместете го в `practice-test`
чрез релативни пътища. 
```bash
# NOT TESTED!!! MAY NOT WORK!!!
mkdir -p ~/practice-test/test1
touch ~/practice-test/test1/test.txt
cd ~/practice-test
mv ./test1/test.txt
```

**Зад. 3:** Създайте директорията `practice/01` във вашата home директория. Създайте 3 файла в нея -
`f1`, `f2`, `f3`. Копирайте файловете `f1`, `f2`, `f3` от директорията `practice/01/` в директория
`dir1`, намираща се във вашата home директория. Ако нямате такава, създайте я.
```bash
# NOT TESTED!!! MAY NOT WORK!!!
mkdir -p ~/practice/01/dir1
cd ~/practice/01/dir1
touch f1 f2 f3
```

### Hard Link

Има разлика между файл и име. Може 2 имена във файловата система да са "свързани" с един и същи файл 
на диска, т.е. към един и същи **i-node**. Това точно се нарича **hard link**. С `ls -l` може да 
видим броя на hard линковете.

`.` и `..` са hard links.

### Soft Link (symbolic link) (symlink)

Това е просто файл, който съдържа път към друг файл. Пример за път: `/etc/passwd`. Може да е абсолютен
или относителен път. По подразбиране, когато работим със symlink, всъщност работим с файла, който той 
реферира. Може да счупим symlink като преименуваме файла, който сочи например.

### Permissions (на български - права)

**Groups** - може да сме в няколко групи, но имаме една основна група.  
Защо съществуват групи и потребители - за да се ограничават ресурсите на компютъра (най-малкото всеки 
потребител си има собствена директория и другите да не могат да му бъркат във файловете).

Всеки файл има потребител собственик и група собственик.

Има три вида "хора" в Linux:
- user owner.
- group owner - принадлежим към групата, на която принадлежи файлът.
- other - нито едно от посочените.

#### Примери:  

------

Може да имаме ситуацията:
| user | group | other |
| :---: | :---: | :---: |
| wx | r | x |

В този случай, ако сме собственик на файла и също сме от групата собственик на файла ще се гледа само 
това, че сме собственик - т.е. нямаме read access. Ако бяхме само от групата owner, то щяхме да имаме 
**само** read access.

------

Или друга ситуация:
| user | group | other |
| :---: | :---: | :---: |
| rwx | - | - |

В този пример никой няма права освен user owner.

------

Правата можем да ги сетваме с числа.  
Ако сме собственици на файл може да променяме правата му както си искаме.

`sudo` командата не я ползваме.