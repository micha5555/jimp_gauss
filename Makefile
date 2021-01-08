all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b


test2: all
	bin/gauss dane/C dane/d
test_a: all
	bin/gauss dane/T3/A dane/T3/b
	echo "\nRozwiazania dla porownania wynikow otrzymanych przez program"
	cat dane/T3/rozw
#test dla macierzy z samymi zerami na diagonali
