;; Наредените двойки са най-общия тип данни в Scheme. С тях могат да се дефинират произволно
;; сложни структури от данни.

;; Make an ordered pair:
;; '(a . b) and (cons a b) do the same.
'(#\a . #\b)
'(3 . 7)
(cons "hello" "world")
(cons (lambda (x) (* x x)) 3.14)

;; Check if something is a pair:
(pair? (cons 1 3))  ;; #t
(pair? 3)  ;; #f

;; Get first element of a pair:
(car (cons "first" "second"))
;; Get second element of a pair:
(cdr (cons "first" "second"))

;; В Scheme списъците са частен случай на наредедните двойки. Всеки списък (освен празният) е
;; наредена двойка, но не всяка наредена двойка е списък.
;; Заб. Мисля, че списъците са имплементирани точно като вложени нередени двойки.
'()  ;; empty list
'(5 . ())  ;; list with one element: 5
'(5 . (1))  ;; list with two elements: 5, 1
'(1 . (2 . (3 . (4))))  ;; list with elements: 1, 2, 3, 4

;; Shorter definitions of a list:
(list 1 2 3 4)
'(5 6 7 8)

;; Check if something is a list:
(list? '(#\a #\b #\c))  ;; #t

;; Of course we can have nested lists:
(list 1 2 3 (list #\a #\b #\c) 4)

;; Тъй като списъците са наредени двойки, можем да ползваме 'car' и 'cdr' да вземем съответно
;; главата и опашката на списъка.
(car '(1 2 3))  ;; 1
(cdr '(1 2 3))  ;; '(2 3)

;; Ако искаме да вземем първия елемент може да напишем (индексирането е от нула):
(car (cdr '(1 2 3)))  ;; 2
;; Но може да напишем и:
(cadr '(1 2 3))
;; Можем да слагаме до 4 'a' и 'd' в какъвто ред искаме стига операцията да е валидна.
;; Същото важи и за наредени двойки.
