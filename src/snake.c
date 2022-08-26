#include<ncurses.h>
#include<stdlib.h>
#include"snake.h"
#include"../utils/string.h"

void generate_apple(COORDINATE *coord_apple, COORDINATE **coord_snake, int size)
{
	int row, col, flag, i;
	getmaxyx(stdscr, row, col);
	
	do {
	flag = 0;
	coord_apple->y = (rand() % (row - 2)) + 1;
	coord_apple->x = (rand() % (col - 2)) + 1;
	
	for(i = 0; i < size; i++)
		if(coord_snake[i]->x == coord_apple->x && coord_snake[i]->y == coord_apple->y) {
			flag = 1;
			break;
		}
	if(!flag) break;
	
	} while(1);
	mvaddstr(coord_apple->y, coord_apple->x, "@");
}

int protect_snake(COORDINATE **coord_snake, int size) 
{
	int i, row, col;
	getmaxyx(stdscr, row, col);

	if(coord_snake[0]->x == 0 || coord_snake[0]->y == 0 || coord_snake[0]->x == col - 1 || coord_snake[0]->y == row - 1)
		return 0;

	for(i = 1; i < size; i++) 
		if(coord_snake[0]->x == coord_snake[i]->x && coord_snake[0]->y == coord_snake[i]->y) return 0;

	return 1;
}

COORDINATE **move_snake(COORDINATE **coord_snake, int *size, int shift_x, int shift_y, COORDINATE *coord_apple)
{	
	int i;	
	if(coord_apple->y == coord_snake[0]->y && coord_apple->x == coord_snake[0]->x) {
		coord_snake = realloc(coord_snake, (*size + 1) * (sizeof(COORDINATE *)));
		coord_snake[*size] = malloc(sizeof(COORDINATE));
		*coord_snake[*size]=*coord_snake[*size - 1];
	} else {
		mvaddch(coord_snake[*size - 1]->y, coord_snake[*size - 1]->x, ' ');	
	
	}
	for(i = *size - 2; i>=0; i--)
		*coord_snake[i + 1] = *coord_snake[i];
	
	coord_snake[0]->x += shift_x;
	coord_snake[0]->y += shift_y;
	
	mvaddstr(coord_snake[0]->y, coord_snake[0]->x, "*");
	
	if(coord_apple->y == coord_snake[1]->y && coord_apple->x == coord_snake[1]->x) {
		(*size)++;
		generate_apple(coord_apple, coord_snake, *size);
	}
	
	refresh();
	return coord_snake;
}


COORDINATE **init_coord_snake(int coord_first_y, int coord_first_x, int size)
{	
	COORDINATE **coord_snake;
	coord_snake = malloc(size * (sizeof(COORDINATE *)));
	int i;
	for(i = 0; i < size; i++) {
		coord_snake[i] = malloc(sizeof(COORDINATE));
		coord_snake[i]->x = coord_first_x + i;
		coord_snake[i]->y = coord_first_y;
	}	
	return coord_snake;
}

void clear_coord_snake(COORDINATE ***coord_snake, int size)
{
	int i;
	for(i = 0; i < size; i++) {
		free((*coord_snake)[i]);
	}
	free(*coord_snake);
}

COORDINATE **create_snake(int *snake_size, char *body)
{
	int row, col;
	COORDINATE **coord_snake = NULL;
	
	getmaxyx(stdscr, row, col);
	
	*snake_size = stringlen(body);
	
	coord_snake = init_coord_snake(row / 2, (col - 1) / 2, *snake_size);	
	mvaddstr(coord_snake[0]->y , coord_snake[0]->x, body);
	return coord_snake;
}


