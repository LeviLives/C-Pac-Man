// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stdio.h>

// make sure not to modify anything in this extern block
extern "C"{
#include "defines.h"
#include "map.h"
#include "actor.h"
#include "game.h"
char *map = NULL, *dot_map = NULL;
int width, height;
}

/**
 * This file is where you should put your tests for your code.
 * Your code must have tests that execute at least 85% of the code in
 * required functions for you to get full marks for the project.
 * Make sure to check out the course videos on automated testing for
 * more information about how to write tests.
 */

/* tests for map.c */
TEST_SUITE_BEGIN("Map tests");

// tests for load_map
TEST_CASE("A test for load_map") {
    CHECK(0 == 0);
}

// tests for is_wall

TEST_SUITE_END();

/* tests for actor.c */
TEST_SUITE_BEGIN("Actor tests");

// tests for sees_player

// tests for move_player

// tests for move_ghost

TEST_SUITE_END();

/* tests for game.c */
TEST_SUITE_BEGIN("Game tests");

// tests for check_win
TEST_CASE("check_win - all dots collected") {
    // Setup win condition
    // set up arbitrary map dimension
    height = 2;
    width = 2;

    //set up map content with no dots
    char test_dot_map[4] = {EMPTY, EMPTY, EMPTY, EMPTY};

    //mask test_dot_map onto dot_map
    //dot_map is a pointer so it can be = to an array straight up
    //dotCounter will be 0 here
    dot_map = test_dot_map;

    //If dotCounter is 0, player should win
    REQUIRE(check_win() == YOU_WIN);
}

TEST_CASE("check_win - some dots are left") {
    // Setup win condition
    // set up arbitrary map dimension
    height = 3;
    width = 3;

    //set up map content with dots
    char test_dot_map[9] = {DOT, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY};

    //mask test_dot_map onto dot_map
    //dot_map is a pointer so it can be = to an array straight up
    dot_map = test_dot_map;

    //there are still dots on the map. Player should keep going
    REQUIRE(check_win() == KEEP_GOING);
}

// test for check_loss
//assuming there are two ghosts
TEST_CASE("check_loss - player collide with ghost 1") {
    int ghost_x[NUM_GHOSTS]={1,2};
    int ghost_y[NUM_GHOSTS]={3,4};

    //player coordinate the same as ghost 1
    //Player should be killed by the ghost 1 and lose
    REQUIRE (check_loss(1,3,ghost_x,ghost_y)==YOU_LOSE);
}

TEST_CASE("check_loss - player collide with ghost 2") {
    int ghost_x[NUM_GHOSTS]={1,2};
    int ghost_y[NUM_GHOSTS]={3,4};

    //player coordinate the same as ghost 2
    //Player should be killed by the ghost 2 and lose
    REQUIRE (check_loss(2,4,ghost_x,ghost_y)==YOU_LOSE);
}

TEST_CASE("check_loss - player does not collide with ghost") {

    //initialize ghost position
    int ghost_x[NUM_GHOSTS]={1,2};
    int ghost_y[NUM_GHOSTS]={3,4};

    //player coordinate is different from all ghosts
    //Player should not be dead and can keep going
    REQUIRE (check_loss(3,5,ghost_x,ghost_y)==KEEP_GOING);
}

TEST_SUITE_END();