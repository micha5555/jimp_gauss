all:
	gcc -Wall --pedantic src/*.c -o bin/gauss
#   Test dla danych prawidłowych
test: all
	bin/gauss dane/A dane/b

#    Test dla danych prawidłowych;   
test2: all
	bin/gauss dane/prawidlowe/C dane/prawidlowe/d

#    Test dla zer na diagonali;
test3: all
	bin/gauss dane/zerodiagonala/E dane/zerodiagonala/f

#   Test dla macierzy osobliwej
test4: all  
	bin/gauss dane/osobliwa/G dane/osobliwa/h

#   Test dla różnej liczby kolumn i wierszy
test5: all  
	bin/gauss dane/niekwadratowa/I dane/niekwadratowa/j

#   Test dla różnej liczby wierszy macierzy A i b
test6: all  
	bin/gauss dane/A_mniejsze_od_b/K dane/A_mniejsze_od_b/l
