;; These functions are for convenience so that I don't have to write
;; (- n 1) or (+ n 1) to increment.
(define (-- n) (- n 1))
(define (++ n) (+ n 1))


(define (factoriel_recursive n)
  (if (= n 0) 1
      (* n (factoriel_recursive (-- n)))))
;; Test 'factoriel_recursive':
(= (factoriel_recursive 0) 1)
(= (factoriel_recursive 1) 1)
(= (factoriel_recursive 5) 120)


(define (factoriel n)
  (define (factoriel_iterative i result)
    (if (<= i n)
        (factoriel_iterative (++ i) (* result i))
        result))
  (factoriel_iterative 1 1))
;; Test iterative factoriel:
(= (factoriel 0) 1)
(= (factoriel 1) 1)
(= (factoriel 4) 24)
(= (factoriel 6) 720)


;; 'ex' must be a whole number.
;; The time complexity is linear.
(define (pow base ex)
  (cond ((= ex 0) 1)
        ((< ex 0) (/ 1 (pow base (- ex))))
        (else (* base (pow base (-- ex))))))
;; Test 'pow':
(= (pow 2 3) 8)
(= (pow 2 -3) 1/8)


;; 'ex' must be a whole number.
;; The time complexity is logarithmic.
(define (fast_pow base ex)
  (define (sqr x) (* x x))
  (cond ((= ex 0) 1)
        ((< ex 0) (/ 1 (fast_pow base (- ex))))
        ((even? ex) (sqr (fast_pow base (/ ex 2))))
        (else (* base (fast_pow base (-- ex))))))
;; Test 'fast_pow':
(= (fast_pow 2 64) 18446744073709551616)
(= (fast_pow 5 -3) 1/125)


;; Time and space complexity is exponential.
;; Тази функция генерира дървовиден рекурсивен процес.
(define (fibonacci n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fibonacci (- n 1)) (fibonacci (- n 2))))))
;; Test 'fibonacci':
(= (fibonacci 0) 0)
(= (fibonacci 1) 1)
(= (fibonacci 4) 3)
(= (fibonacci 5) 5)
(= (fibonacci 30) 832040)


;; Time complexity is linear. Сложността по памет е константна, защото компилаторът оптимизира
;; опашковата рекурсия до цикъл (и не се заделя нова памет за всяко рекурсивно викане).
;; This function generates linear iterative process.
(define (fast_fib n)
  (define (fib_iter fi fi-1 i)
    (if (< i n)
        (fib_iter (+ fi fi-1) fi (++ i))
        fi))
  (if (= n 0) 0
      (fib_iter 1 0 1)))
;; Test 'fast_fib':
(= (fast_fib 10) (fibonacci 10))
(= (fast_fib 20) (fibonacci 20))
(= (fast_fib 30) (fibonacci 30))
