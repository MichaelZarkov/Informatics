;; A fixed point of a function is a point 'x' that: x = f(x).
(define (fixed-point? f x) (= x (f x)))
(= (sin 0) 0)
(= ((lambda (x) (* x x)) 1) 1)

;; If the predicate 'p' is true then return f(x), else return g(x).
(define (branch p f g x) ((if (p x) f g) x))
(= (branch even? abs exp -6) 6)

;; Тази функция е от произволно висок ред. Ако ѝ подадем число например, то тя ще се държи
;; като ф-я от нулев ред. Ако ѝ подадем ф-я от n-ти ред, то тя ще стане от n+1-ви. Значи може
;; да е от произволно висок ред.
(define (id x) x)
(not (equal? (id "Hello World!") "hello"))

;; Задача: да се пресметне сумата: К^2 + (K+1)^2 + ... + 100^2 за К <= 100.
;; Решение:
(define (sum k)
  (if (> k 100) 0 (+ (* k k) (sum (+ k 1)))))
(= (sum 100) 10000)
(= (sum 99) 19801)
;; Супер, сметнахме го. Но какво става, ако искаме сумата на кубовете, или произведението, или от К
;; до 1000. Ще обобщим горната функция по следния начин (важно да се знае!!!):
(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a) (accumulate op nv (next a) b term next))))
;; Където
;; 'op' - двуместна операция
;; 'nv' - нулевият елемент на тази операция
;; 'а' - начално число
;; 'b' - крайно число
;; 'term' - ф-я на един аргумент, която ни дава поредния член на редицата.
;; 'next' - ф-я на един аргумент, която ни дава следващото число от интервала [a,b].

;; Горната функция е функция за "дясно натрупване". В нея има отложена операция и при изпълнението си
;; тя генерира същински рекурсивен процес.
;; Следващата функция е много подобна, но не същата. Тя е функция за "ляво натрупване", няма отложена
;; операция и при изпълнение генерира итеративен процес:
(define (accumulate-i op nv a b term next)
  (if (> a b) nv
      (accumulate-i op (op nv (term a)) (next a) b term next)))

;; Test 'accumulate' and 'accumulate-i'.
(define (++ x) (+ 1 x))
(= (accumulate + 0 1 4 id ++) 10)    ;; 1+2+3+4 = 10
(= (accumulate-i + 0 1 4 id ++) 10)  ;; 1+2+3+4 = 10
;; Notice that the two tests below give different answers. This is because division is
;; non associative. 'accumulate' and 'accumulate-i' put the brackets of the operation in a different
;; place and so their output is not the same for non associative operations (like division).
;; Затова казваме, че 'accumulate' прави дясно натрупване, а 'accumulate-i' - ляво.
(= (accumulate / 1 1 3 id ++) 3/2)   ;; 1/(2/3) = 3/2
(= (accumulate-i / 1 1 3 id ++) 1/6) ;; (1/2)/3 = 1/6



;; Ламбда функции (анонимни функции), синтаксис, примери.
;; Анонимната функция пази указател към средата, в която е оценена.
;; (lambda (<arguments>) <body>)
(lambda (x) (+ x 3))       ;; <procedure>
((lambda (x) (+ x 3)) 5)   ;; Прилагаме ги като "нормалните" функции (връща 8).

;; Всъщност това:
(define (square1 x) (* x x))
;; Е съкратен запис за:
(define square2 (lambda (x) (* x x)))

;; Можем да ги подаваме като аргументи, както обикновените функции:
(= (accumulate + 0 5 9 (lambda (x) (* x x x)) (lambda (x) (+ 2 x))) 1197)  ;; 5^3 + 7^3 + 9^3 = 1197
