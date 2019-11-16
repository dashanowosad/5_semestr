/*Задание № 1*/

func1:-
  write('Список: '),
  read(List),
  write('X = '),
  read(X),
  delete(List,X,L1),
  write(L1).

/*Задание № 2*/

r(F1,F2):-
  %(at_end_of_stream \== true,write('fhwehf')).
  %set_input(F1),
  read_line_to_codes(F1,L),
  %set_output(user),
  name(S,L),

  (at_end_of_stream, write('');r(F1,F2),!),
  writeln(S).

func2:-
  open('text.txt',read,F1),
  open('result.txt',write,F2),
  set_input(F1),
  set_output(F2),
  r(F1,F2),
  close(F1),
  close(F2).

/*  open('text.txt',read,F1),
  open('result.txt',write,F2),


  read_line_to_codes(F1,L),
  name(S,L),
  set_output(user),
  write(S),

 write(S),


  close(F1),
  close(F2).
*/
