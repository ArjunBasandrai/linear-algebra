all:
	clang main.c -L. -llinear_algebra -o lin.exe

gcc:
	gcc main.c -L. -llinear_algebra -o lin.exe

run:
	./lin.exe

lib_gcc:
	gcc -c src/matrix/matrix.c
	gcc -c src/matrix/operations.c
	ar -rc linear_algebra.lib *.o
	del *.o

lib_clang_64:
	clang -c src/matrix/matrix.c -o matrix.o -m64
	clang -c src/matrix/operations.c -o operations.o -m64
	llvm-ar rc linear_algebra.lib operations.o matrix.o
	del *.o

lib_clang_32:
	clang -c src/matrix/matrix.c -o matrix.o
	clang -c src/matrix/operations.c -o operations.o
	llvm-ar rc linear_algebra.lib operations.o matrix.o
	del *.o

lib: lib_clang_64

# NOTE: To link with the library, use "-L. -llinear_algebra" as arguments to clang / gcc