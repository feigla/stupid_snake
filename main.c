#include<ncurses.h>
#include"src/direction.h"
#include"src/snake.h"

static void init_fields()
{
	int row, col, y, x;
	getmaxyx(stdscr, row, col);
	for(y = 0; y < row; y++) {	
		for(x = 0; x < col; x++) {
			if(x == 0 || y == 0 || y == row - 1 || x == col - 1) {
				mvaddstr(y, x, "#");
			}
		}

	}
}

static void init_game()
{
	int snake_size, key;
	DIRECTION cur_dir = LEFT;
	COORDINATE **coord_snake = NULL;
	COORDINATE coord_apple;	
	initscr();
	cbreak();
	keypad(stdscr, 1);
	curs_set(0);
	noecho();
	
	init_fields();	

	coord_snake = create_snake(&snake_size, "***");
	
	generate_apple(&coord_apple, coord_snake, snake_size);

	refresh();

	do {
		key = getch();
		set_direction(&cur_dir, key);
		coord_snake = move_snake(coord_snake, &snake_size, cur_dir.x, cur_dir.y, &coord_apple);
		timeout(30);
	} while(key != KEY_ESC);
	
	clear_coord_snake(&coord_snake, snake_size);
	
	endwin();
}

int main()
{
	init_game();
	return 0;
}
