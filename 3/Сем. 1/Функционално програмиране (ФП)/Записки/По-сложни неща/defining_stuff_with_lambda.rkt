;; Наредени двойки с ламбда.
;; Първи начин:
(define (mk-pair-1 x y) (lambda (p) (if p x y)))
(define (fst-1 pair) (pair #t))
(define (snd-1 pair) (pair #f))

(define my-pair-1 (mk-pair-1 5 7))
(fst-1 my-pair-1)  ;; 5
(snd-1 my-pair-1)  ;; 7

;; Втори начин:
(define (mk-pair-2 x y) (lambda (f) (f x y)))
(define (fst-2 pair) (pair (lambda (x y) x)))
(define (snd-2 pair) (pair (lambda (x y) y)))

(define my-pair-2 (mk-pair-2 9 8))
(fst-2 my-pair-2)  ;; 9
(snd-2 my-pair-2)  ;; 8