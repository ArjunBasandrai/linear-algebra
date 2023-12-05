all:
	clang main.c -L. -lnumc -o numc.exe

gcc:
	gcc main.c -L. -lnumc -o numc.exe

run:
	./numc.exe

lib_gcc:
	gcc -c src/matrix.c
	gcc -c src/operations.c
	ar -rc numc.lib *.o
	del *.o

lib_clang_64:
	clang -c src/matrix.c -o matrix.o -m64
	clang -c src/operations.c -o operations.o -m64
	llvm-ar rc numc.lib operations.o matrix.o
	del *.o

lib_clang_32:
	clang -c src/matrix.c -o matrix.o -m32
	clang -c src/operations.c -o operations.o -m32
	llvm-ar rc numc.lib operations.o matrix.o
	del *.o

lib: lib_clang_64

# NOTE: To link with the library, use "-L. -lnumc" as arguments to clang / gcc