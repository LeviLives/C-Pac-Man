// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#include <stdio.h>

#include "defines.h"
#include "colours.h"
#include "map.h"

extern char *map, *dot_map;
extern int width, height;

/**
 * You should use this function to print out individual characters
 * in the colours used in the demo.
 * @param c
 */
static void printc(char c) {
    switch (c) {
        case WALL:
            change_text_colour(BLUE);
            break;
        case GHOST:
            change_text_colour(PINK);
            break;
        case PLAYER:
            change_text_colour(YELLOW);
            break;
        case DOT:
            change_text_colour(WHITE);
            break;
        default:
            change_text_colour(WHITE);
    }
    printf("%c", c);
}

void print_map(void) {

    //print upper wall before map. If there are two side walls,
    //the width of the top wall will be the
    //map width +2 from the side walls.
    //format all element of map with two spaces after

    //Lab 1 auto grader wanted only one space after somehow?
    //According to auto grader instead of assignment instruction,
    //only one space after each element.

    for (int x = 0; x < width+2; x++) {
        printc(WALL);
        printf(" ");
    }

    //Go to next line to start the map's first row
    printf("\n");

    //start from 0 because it is reading from an array
    for (int y = 0; y < height; y++) {

        //before each line of map, print the outer left wall
        printc(WALL);
        printf(" ");

        //read the horizontal line of map
        for (int x = 0; x < width; x++) {

            //y*width indicates the row it is in, x is the column of that row
            printc(map[y * width + x]);
            printf(" ");

        }

        //after each line of map, print the outer right wall
        printc(WALL);
        printf(" ");

        //go to next line of map
        if (y < height ) {
            printf("\n");
        }

    }

    //After all map has been printed, print the outer bottom wall
    //Same as top wall, the width of it will be map width +2
    for (int x = 0; x < width+2; x++) {
        printc(WALL);
        printf(" ");
    }
}

int is_wall(int y, int x) {
    return NOT_WALL;
}

char * load_map(char * filename, int *map_height, int *map_width) {
    return NULL;
}
