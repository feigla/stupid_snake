build:
	clang -Wall main.c utils/string.c src/direction.c src/snake.c -o main -lncurses
run:
	./main
