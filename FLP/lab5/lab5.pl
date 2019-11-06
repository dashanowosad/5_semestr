/*Задание № 1 */

nechet(A, B):-
  A =< B,
  C is A mod 2,
  A1 is A + 1,
  nechet(A1, B),
  (C =\= 0), write(A); write(' ').



func1:-
  write('Введите первое число: '),
  read(A),
  write('Введите второе число: '),
  read(B),
  nechet(A,B).


/*Задание № 2*/

sum(A,B,S):-
  A1 is A + 1,
  S1 is S + A,
  (A =< B, sum(A1,B,S1); write('Сумма = '), write(S)).
  /*S is S + A,*/


func2:-
  write('Введите первое число: '),
  read(A),
  write('Введите второе число: '),
  read(B),
  S is 0,
  sum(A,B,S).


/*Задание № 3*/
min(A,B):-
  A1 is A div 10,
  C is A mod 10,
  (B > C, B1 is C; B1 is B),
  (A > 0, min(A1,B1); write('Наименьшее = '), write(B)).


func3:-
  write('Введите число: '),
  read(A),
  B is 10,
  min(A,B).


/*Задание № 4*/

fib(A,B,N,K):-
  C is A + B,
  K1 is K + 1,
  write(C),
  write(' '),
  (K1 < N, fib(B,C,N,K1); write('')).


func4:-
  repeat,
  nl,
  write('Введите число: '),
  read(N),
  B is 1,
  A is 1,
  K is 1,
  (N > 0, write('1 1 '), fib(A,B,N,K);write('')),
  prov(N),!.


prov(N):-
  N < 0, writeln('Конец ввода').

/*
цель:-write('Введите слово для повтора '),nl, эхо.

эхо:-repeat,
read(Slovo),
write(Slovo),nl,
проверка(Slovo),!.

проверка(стоп):-write('Конец'),nl.
*/
