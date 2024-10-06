
;; Apply 'f' n-times to 'stack'.
(define (apply-f-n f n stack)
  (cond ((or (null? stack)
             (null? (cdr stack))
             (= n 0))
         stack)
        ((and (number? (car stack))
              (number? (cadr stack)))
         (apply-f-n f (- n 1) (cons (f (car stack) (cadr stack)) (cddr stack))))
        (else stack)))
  
;; Returns the resulting stack after 'instr' is applied.
(define (apply-instruction instr stack)
  (cond ((or (number? instr)
             (symbol? instr))
         (cons instr stack))
        ((procedure? instr)
         (map (lambda (x) (if (number? x) (instr x) x)) stack))
        ((and (pair? instr)
              (procedure? (car instr))
              (number? (cdr instr)))
         (apply-f-n (car instr) (cdr instr) stack))
        (else stack)))

;; Returns resulting stack after application of all instructions.
(define (run-machine l)
  (define (run stack curr-l)
    (if (null? curr-l) stack
        (run (apply-instruction (car curr-l) stack) (cdr curr-l))))
  (run '() l))  

;; Test
(run-machine (list 1 'x 4 'a 9 16 25 sqrt 6))                       ;; (6 5 4 3 a 2 x 1)
(run-machine (list 1 'x 4 'a 9 16 25 sqrt 6 (cons + 2) (cons * 5))) ;; (45 a 2 x 1)