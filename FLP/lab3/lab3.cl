(defun func (lst1 lst2)
	(if lst1
		(if (find (car lst1) lst2) (func (cdr lst1) lst2) nil)
		t)
	)

(defun fun1 (lst1 lst2)(if (and (func lst1 lst2) (func lst2 lst1)) t nil))

(defun func (lst1 lst2)(if lst1(if (find (car lst1) lst2) (func (cdr lst1) lst2) nil)t))


(defun fun4 (lst1 lst2)
  (cond ((null lst1) nil)
        ((member (car lst1) lst2) (cons (car lst1) (fun4 (cdr lst1) lst2)))
        (t (fun4 (cdr lst1) lst2))))

(defun fun4 (lst1 lst2) (cond ((null lst1) nil)((member (car lst1) lst2) (cons (car lst1) (fun4 (cdr lst1) lst2)))(t (fun4 (cdr lst1) lst2))))


(defun fun9 (lam lst)
	(cond 
		((null lst) nil)
		((funcall lam (car lst)) (cons '* (cons (car lst) (fun9 lam (cdr lst)))))
		(t (cons (car lst) (fun9 lam (cdr lst))))
		
		)
	)

(defun fun9 (lam lst)(cond ((null lst) nil)((funcall lam (car lst)) (cons '* (cons (car lst) (fun9 lam (cdr lst)))))(t (cons (car lst) (fun9 lam (cdr lst))))))

(fun9 #'evenp '(1 2 3 0 -1 -2 9 -3 -8))