
(define (foldl op nv ls)
  (if (null? ls) nv
      (foldl op (op nv (car ls)) (cdr ls))))

;; Връща истина, ако 'bs' мажорира 'as'.
(define (majoring? as bs)
  (cond ((and (null? as)
              (null? bs)) #t)
        ((or (null? as)
             (null? bs)) #f)
        ((> (car as) (car bs)) #f)
        (else (majoring? (cdr as) (cdr bs)))))

;; Връща списък от първите 'n' елемента на 'ls'.
;; Тази функция е супер бавна, но както и да е...
(define (first-n ls n)
  (let ((len (length ls)))
    (if (< len n) '()
        (reverse (list-tail (reverse ls) (- len n))))))
      
;; Връща списък от всички подсписъци на 'ls' с дължина 'n'.
(define (all-n-sublists ls n)
  (let ((sub-ls (first-n ls n)))
    (if (null? sub-ls) '()
        (cons sub-ls (all-n-sublists (cdr ls) n)))))

;; Връща истина, ако някой подсписък на 'bs' мажорира 'as'.
(define (sub-majoring? as bs)
  (foldl (lambda (p q) (or p q)) #f
         (map (lambda (sub-bs) (majoring? as sub-bs)) (all-n-sublists bs (length as)))))
         
;; Проверява дали 'lss' е мажорен.
(define (is-major? lss)
  (cond ((or (null? lss)
             (null? (cdr lss))) #t)
        (else (and (sub-majoring? (car lss) (cadr lss))
                   (is-major? (cdr lss))))))
;; Test
(is-major? '())
(is-major? '((1 2 3)))
(is-major? '((1 3) (4 2 7) (2 5 4 3 9 12))) ;; #t
(is-major? '((1 3) (4 2 7) (2 5 3 3 9 12))) ;; #f



        