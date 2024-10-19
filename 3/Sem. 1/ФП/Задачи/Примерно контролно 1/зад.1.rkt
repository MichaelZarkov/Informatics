
(define (1+ n) (+ 1 n))

(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a) (accumulate op nv (next a) b term next))))

;; Returns true if 'n' is perfect.
(define (done? n)
  (define (sum-of-divs n)
    (accumulate + 0 1 (- n 1) (lambda (x) (if (= (remainder n x) 0) x 0)) 1+))
  (= (+ n 2) (sum-of-divs n)))

; Test
(done? 20)  ;; ans: #t
(done? 28)  ;; ans: #f

;; Returns true if at least one of the numbers in the interval [a,b] satisties 'p?'.
(define (any? p? a b)
  (accumulate (lambda (p q) (or p q)) #f a b p? 1+))

(define (sum-almost-done a b)
  ;; Returns x if x is closer to a purfect num that to the ends of the interval. Returns 0 otherwise.
  (define (term x)
    (let ((a1 (- (1+ x) (min (- x a) (- b x))))
          (b1 (+ (- x 1) (min (- x a) (- b x)))))
      (if (any? done? a1 b1) x 0)))
  (accumulate + 0 a b term 1+))

;; Test
(sum-almost-done 5 24)  ;; ans: 153 (сумата на числата от 13 до 21)