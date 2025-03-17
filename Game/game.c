// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#include "defines.h"
#include "game.h"
#include <string.h>

extern char * map, * dot_map;
extern int height;
extern int width;

int check_win(void) {
    int dotCounter = 0;
        for (int i = 0; i<height*width; i++) {
            if (dot_map[i] == DOT) {
                dotCounter++;
            }
        }
    if (dotCounter == 0) {
        return YOU_WIN;
    }
    else {
        return KEEP_GOING;
    }
}

int check_loss(int player_y, int player_x, int ghosts_y[NUM_GHOSTS], int ghosts_x[NUM_GHOSTS]) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
        if (player_x == ghosts_x[i] && player_y == ghosts_y[i]) {
            return YOU_LOSE;  // Immediate loss on any collision
        }
    }
    return KEEP_GOING;  // Only return "continue" after ALL ghosts checked
}


