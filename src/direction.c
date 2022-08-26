#include<ncurses.h>
#include"direction.h"

void set_direction(DIRECTION *cur_dir, int key)
{
	switch (key) {
		case KEY_UP:
			if(cur_dir->x == DOWN.x) return;
			*cur_dir = UP;
			break;
		case KEY_DOWN:
			if(cur_dir->x == UP.x) return;
			*cur_dir = DOWN;
			break;
		case KEY_LEFT:
			if(cur_dir->y == RIGHT.y) return;
			*cur_dir = LEFT;
			break;
		case KEY_RIGHT:
			if(cur_dir->y == LEFT.y) return;
			*cur_dir = RIGHT;
			break;
	}
}
