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
  List = [2,4,2,3,2,3],
  in_sort(List,L1),
  S is 1,
  Kol = [],
  kol(L1,L1,S,Kol).
