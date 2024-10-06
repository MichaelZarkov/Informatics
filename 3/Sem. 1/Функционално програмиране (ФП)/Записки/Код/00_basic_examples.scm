; Examples for defining symbols.
(define x 3)            ; x -> 3
(define y 3/2)          ; y -> 3/2
(define z "my_string")  ; z -> "my_string"
;(define w (+ x w))      ; Error: cannot reference an identifier before its definition


; Examples for defining functions.
(define (square x) (* x x))
(= (square 3) 9) ; This is used like a unit test. When we run it we expect output #t (true).
                 ; If not #t, then the test failed so something is wrong.

(define (1+ n) (+ n 1))
(= (1+ 5) 6)

(define (distance x1 y1 x2 y2)
  (sqrt (+ (square (- x1 x2)) (square (- y1 y2)))))
(= (distance 0 0 3 4) 5)
(= (distance 1 1 2 2) (sqrt 2))

(define (foo) (+ 2 4))
(= (foo) 6)


; Quoting examples.
(quote square)
(quote y)
'(/ 2 3)            ; Alternate writing. Does the same as (quote (/ 2 3)).
(quote (/ 4 0))     ; Не дава грешка, защото изразът не се смята.


; if examples.
(if (< 1 2) "Scheme is cool" "Scheme is bad")  ; Returns "Scheme is cool".

(define (abs-val n) (if (< n 0) (- n) n))
(= (abs-val -9) 9)
(= (abs-val 0) 0)

(define (f1 x) (if (>= x 5) x "x is less than 5"))
(f1 6)   ; Returns 6.
(f1 3)   ; Returns "x is less than 5".


; cond examples
(define x1 6.3)  (define y1 7.4)
; The following conditional returns "output_3".
(cond
  ((< 4 3) "output_1")
  ((= x1 y1) "output_2")
  (else "output_3")
  )


; case examples.
(define (f2 n)
(case n
  ((2 4 6 8) "even and less than 10")
  ((1 3 5 7 9) "odd and less than 10")
  (else "more than 10")
  ))
(f2 3)   ; outputs "odd and less than 10".