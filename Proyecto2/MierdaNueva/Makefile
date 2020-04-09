ast: ast.o gfx.o
	g++ gfx.o ast.o -o ast -lX11
ast.o: ast.cpp
	g++ ast.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c
