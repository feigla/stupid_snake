#ifndef SNAKE_H_
#define SNAKE_H_

typedef struct nes_coordinate {
	int y;
	int x;
} COORDINATE;

COORDINATE **move_snake(COORDINATE **coord_snake, int *size, int shift_x, int shift_y, COORDINATE *coord_apple);


void generate_apple(COORDINATE *coord_apple, COORDINATE **coord_snake, int size);
void clear_coord_snake(COORDINATE ***coord_snake, int size);

COORDINATE **create_snake(int *snake_size, char *body);

#endif // SNAKE_H_
