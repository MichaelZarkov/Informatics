;; Helper functions.
(define (square x) (* x x))
(define (cube x) (* x x x))
(define (n+ n) (lambda (x) (+ n x)))
(define 1+ (n+ 1))
(define -- (n+ -1))
(define (id x) x)

;; twice(x) == f(f(x)). Връща стойност (която може и да е функция).
(define (twice f x) (f (f x)))
(= (twice square 3) 81)

;; Връща функция.
(define (twice-f f) (lambda (x) (f (f x))))
(= ((twice-f square) 3) 81)
(= ((twice-f (twice-f square)) 2) 65536)

;; Composition.
(define (compose f g) (lambda (x) (f (g x))))
(= ((compose square 1+) 4) 25)

;; Derivative.
(define (derivative f dx)
  (lambda (x) (/ (- (f (+ x dx)) (f x)) dx)))
((derivative square 0.001) 5)

;; Compose n times.
(define (compose-n f n)
  (if (<= n 0) id
      (compose f (compose-n f (-- n)))))
(= ((compose-n 1+ 10) 0) 10)

;; N-th derivative of a function with one argument.
(define (derivative-n f n dx)
  ((compose-n (lambda (g) (derivative g dx)) n) f))
((derivative-n cube 0 0.001) 2)  ;; ans: 8
((derivative-n cube 1 0.001) 2)  ;; ans: 12
((derivative-n cube 2 0.001) 2)  ;; ans: 12
((derivative-n cube 4 0.001) 2)  ;; ans: 0


