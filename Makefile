all:
	clang -o lin.exe main.c src/matrix/matrix.c src/matrix/operations.c src/nn/activations.c

run:
	./lin.exe