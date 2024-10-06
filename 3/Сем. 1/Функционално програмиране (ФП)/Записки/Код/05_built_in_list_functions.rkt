
(define separator "-------------------------")  ;; For easy reading.

;; The following are some built in list functions in R5RS language.
;; In racket language there are more built in functions like 'flatten', 'foldr', 'foldl' and so on
;; but will be using R5RS in this course.

;; Returns the element at the given position.
(list-ref '(1 2 3 4 5) 3)    ;; returns 4
(list-ref (list 0 1 2) 0)    ;; returns 0
;(list-ref '(a b c) -1)      ;; error
;(list-ref '(a b c) 3)       ;; error
separator

;; How many elements in the list.
(length '(1 2 3))      ;; 3
(length '((a b) '()))  ;; 2
(length '())           ;; 0
separator

;; Check if the object is a list.
(list? '())          ;; #t
(list? (cons 1 2))   ;; #f
separator

;; Checks if the list is empty.
(null? (list))  ;; #t
(null? '('()))  ;; #f
separator

;; (member <елемент> <списък>)
;; Проверява дали <елемент> се среща в <списък>. По-точно, връща <списък> от първото срещане на
;; <елемент> нататък, ако го има, и връща #f, ако <елемент> го няма в <списък>.
;; Сравнява с 'equal?'
(member 7 '(1 2 3 4 5))
(member 2 '(1 2 3 4 5))
(list? (member 2 '(1 2 3 4 5)))
separator

;; Същото като 'member', но сравнява с 'eqv?'.
(memv 'a '(b a))
(memv (cons 1 2) (list (cons 1 2)))
separator

;; Същото като 'member', но сравнява с 'eq?'.
(memq 1 (list 1 2))
separator

;; Returns in reverse order.
(reverse '(1 2 3 4 5))
separator

;; Concatenates all given lists.
(append '(1 2 3) '(4 5 6) '(7 8 9) '(10 11 12) '(13))
separator

;; Вика дадената функция с аргументи всички елементи от списъка.
;; Това означава, че ако дадената функция приема различен брой аргументи от броя на елементите
;; в списъка, ще даде грешка.
(apply + '(1 2 3 4 5))   ;; Прави същото като (+ 1 2 3 4 5).
(apply (lambda (x) (+ 1 x)) '(1))       ;; Правилен брой аргументи.
;(apply (lambda (x) (+ 1 x)) '(1 2 3))  ;; Грешка, неправилен брой аргументи.
separator

;; Прилага дадената функция върху всеки елемент на дадения списък и връща списъка от получените елементи.
(map (lambda (x) (+ x 1)) '(1 2 3 4 5))
((car (map (lambda (x) (lambda (y) (+ x y))) '(1 2 3 4 5))) 0)  ;; 1
separator

;; (list-tail <list> n) - връща елементите на списък без първите n.
(list-tail '(1 2 3 4 5) 0)  ;; Същия списък.
(list-tail '(1 2 3 4 5) 3)

