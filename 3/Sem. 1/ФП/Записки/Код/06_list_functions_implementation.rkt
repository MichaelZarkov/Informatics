
;; Имплементация на вградената функция 'map'.
(define (myMap f l)
  (if (null? l) '()
      (cons (f (car l)) (myMap f (cdr l)))))

(define (filter p? l)
  (cond ((null? l) l)
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))

;; Дясно свиване. Рекурсивен процес.
;; а1 * (a2 * (a3 *...(an * nv)...)), където * е дадената операция.
;; Важно!!! В езика racket тази функция е вградена, но има различна имплементация и в общия случай
;; дава различен изход от долната.
(define (foldr op nv l)
  (if (null? l) nv
      (op (car l) (foldr op nv (cdr l)))))

;; Ляво свиване. Итеративен процес.
;; (...((nv * a1) * a2)...* an-1) * an, където * е дадената операция.
;; Също има различна имплементация в racket.
;; 'foldr' и 'foldl' не правят едно и също. С натрупването на опит по-лесно ще разпознаваме, кога се
;; налага да ползваме едната и кога другата.
(define (foldl op nv l)
  (if (null? l) nv
      (foldl op (op nv (car l)) (cdr l))))

;; Същото като 'foldr', но работи само над непразни списъци (ако подадем празен, дава грешка).
;; Тази функция има смисъл, когато искаме да намерим max/min елемент в списък.
(define (foldr1 op l)
  (if (null? (cdr l)) (car l)
      (op (car l) (foldr1 op (cdr l)))))

;; Същото като 'foldl', но работи само над непразни списъци (ако подадем празен, дава грешка).
(define (foldl1 op l)
  (foldl op (car l) (cdr l)))

;; Имплементация на вградената ф-я 'list?'.
(define (isList? l) (or (null? l) (and (pair? l) (isList? (cdr l)))))


