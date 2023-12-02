all:
	clang -o lin.exe main.c src/matrix/matrix.c

run:
	./lin.exe