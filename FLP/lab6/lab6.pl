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

        (List2 \== [], first(List2,B,C,L11,L22,L33),!;reverse(L11, L111), reverse(L22, L222), reverse(L33, L333), write(L111), write(' '), write(L333), write(' '), write(L222)).


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

find_max([Max],Max):-!.
find_max([Head|Tail],Max):-
  find_max(Tail,Max1),
  Max1 > Head, !, Max = Max1; Max = Head.

index([Head|Tail],Max,L,S):-
  S1 is S + 1,
  (Head == Max, append([S1],L,L1); L1 = L),
  (Tail \== [], index(Tail,Max,L1,S1),!; reverse(L1,L2), write(L2)).

func2:-
  List = [3,5,4,2,5,5,0],
  List = [Head|_],
  L = [],
  S is 0,
  find_max(List,Max),
  index(List,Max,L,S).
