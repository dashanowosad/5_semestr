/*Задание № 1*/
%сортировка с повторениями
in_sort([ ],[ ]).
in_sort([X|Tail],Sort_list):-
  in_sort(Tail,Sort_tail),
  insert(X,Sort_tail,Sort_list).

insert(X,[Y|Sort_list],[Y|Sort_list1]):-
  X@>Y,!,
  insert(X,Sort_list,Sort_list1).

insert(X,Sort_list,[X|Sort_list]).

%список количества встречаний
kol(L,[Head|Tail],S,Res):-
  Tail = [H|_],
  (Head =:= H, S1 is S + 1, Res1 = Res; append([S],Res,Res1), S1 is 1),
  (Tail \== [], kol(L,Tail,S1,Res1),!;
  (Head =:= H, S2 is S1 + 1; S2 is S1),
   append([S2],Res1,Res2),f(L,Res2)).

%список без повторений элементов
del(List,Del,Kol):-
     List = [Head|Tail],
     append([Head],Del,Del1),
     delete(List,Head,List2),
     (Tail \== [], del(List2,Del1,Kol),!; f2(Del1,Kol)).

%создание итогового списка
spis([Head|Tail],[H|T],Res):-
  append([[Head, H]],Res,Res1),
 (Tail \== [], spis(Tail,T,Res1),!;write(Res1)).

%промежуточная функция для списка удаления
 f(List,Kol):-
   Del = [],
   del(List,Del,Kol).
%промежуточная функция перед объединением списков
f2(Del,Kol):-
  Res = [],
  spis(Del,Kol,Res).

func1:-
  write('Список: '),
  read(List),
  %List = [2,4,2,3,2,3],
  in_sort(List,L1),
  S is 1,
  Kol = [],
  kol(L1,L1,S,Kol).


/*Задание №2*/
%запись в конечный файл
w(S,Res):-
  R is Res mod 10,
  write('Строка № '),
  write(S),
  write(' содержит '),
  write(Res),
  %write(' слов '),
  (Res =:= 1,write(' слово ');write('')),
  (R =:= 2,write(' слова ');write('')),
  (R =:= 3,write(' слова ');write('')),
  (R =:= 4,write(' слова ');write('')),
  (R >=5 ,write(' слов ');write('')),
  (R =:= 0, write(' слов '); write('')),
  nl.

%подсчет слов в строке
chet([Head|Tail],Res,S):-
  (Head =:= 32, Res1 is Res+1; Res1 is Res),
  (Tail \== [], chet(Tail,Res1,S),!;w(S,Res1)).

%чтение из файла
r(F1,S):-
  read_line_to_codes(F1,L),
  Res is 1,
  S1 is S + 1,
  chet(L,Res,S1),
  (at_end_of_stream, write('');r(F1,S1),!).

func2:-
  open('1.txt',read,F1),
  open('2.txt',write,F2),
  set_input(F1),
  set_output(F2),
  S is 0,
  r(F1,S),
  close(F1),
  close(F2).
