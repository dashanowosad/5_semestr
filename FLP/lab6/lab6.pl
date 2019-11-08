/*Задание № 1*/
/*[3,7,1,-3,5,8,0,9,2]*/

/*first(List,A,L1):-
  List = [Head|Tail],
  append([Head],L1,L2),
  select(Head,List,List2),

  (List \== [],
    (Head < A, first(List2,A,L2); first(List2,A,L1));
    write(L2)).*/

/*(Head < B, append([Head],L1,L11), L22 = L2; L11 = L1, L22 = L2),*/


    first(List,B,C,L1,L2,L3):-
        List = [Head|_],

        (Head > C, append([Head],L2,L22); L22 = L2),
        (Head < B, append([Head],L1,L11); L11 = L1),
        (Head =< C, Head >= B, append([Head],L3,L33); L33 = L3),
        select(Head,List,List2),

        (List2 \== [], first(List2,B,C,L11,L22,L33);write(L11), write(' '), write(L33), write(' '), write(L22)).


func1:-
  /*write("Введите список: "),
  read(List),
  write("Введите первое число: "),
  read(B),
  write("Введите второе число: "),
  read(C),*/
  List = [3,7,1,-3,5,8,0,9,2],
  B = 3,
  C = 8,
  L1 = [],
  L2 = [],
  L3 = [],
  (B > C, B1 is C, C1 is B; B1 is B, C1 is C),
  first(List,B1,C1,L1,L2,L3).
/*Задание № 2*/

find_max(List,[Head|Tail],Max):-
  Max1 is Head,
  Max < Head,
  find_max(List,Tail, Max1).

find_max(List,[_|Tail],Max):-
  find_max(List,Tail,Max).

find_max(List,[], Max):-
  write(Max).


func2:-
  List = [3,5,4,2,5,5,0],
  List1 = List,
  List1 = [Head|_],
  Max is Head,
  find_max(List,List1,Max).
