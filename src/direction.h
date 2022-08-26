#ifndef DIRECTION_H_
#define DIRECTION_H_

typedef struct nes_direction {
	int x;
	int y;
} DIRECTION;

#define UP (DIRECTION){0, -1}
#define DOWN (DIRECTION) {0, 1}
#define LEFT  (DIRECTION) {-1, 0}
#define RIGHT  (DIRECTION){1, 0}

#define KEY_ESC 27

void set_direction(DIRECTION *cur_dir, int key);

#endif // DIRECTION_H_

