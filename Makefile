all:
	clang -o lin.exe main.c src/matrix/matrix.c src/matrix/operations.c

run:
	./lin.exe