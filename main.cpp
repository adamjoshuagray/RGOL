/*
 * This simulates Conway's game of life, but with a slight addition: randomness.
 *
 * For more information on Conway's game of life see:
 * https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 *
 * Author: Adam J. Gray
 */


#include <iostream>
#include <string.h>

using namespace std;

/*
 * Count the number of neighbours surrounding a square and return that value.
 */
int count_neighbours(bool* current, int x, int y, int height, int width) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int k = x + i;
            if (k == -1) {
                k = height - 1;
            }
            if (k == height) {
                k = 0;
            }
            int l = y + j;
            if (l == -1) {
                l = height - 1;
            }
            if (l == width) {
                l = 0;
            }
            int index = l * height + k;
            if (current[index]) {
                count++;
            }
        }
    }
    return count;
}

/*
 * Given the current state and the number of neighbours
 * return whether the next square should be alive or not.
 */
bool decide_next(bool current, int neighbour_count) {
    // Note we need better randomization.
    // This is very "hackish"
    if (current) {
        // The cell is already alive:
        // This decides what happens next.
        switch(neighbour_count) {
            case 0:
                return (rand() % 10000 >= 9998);
            case 1:
                return (rand() % 10000 >= 9990);
            case 2:
                return (rand() % 10000 >= 10);
            case 3:
                return (rand() % 10000 >= 10);
            case 4:
                return (rand() % 10000 >= 9990);
            case 5:
                return (rand() % 10000 >= 9998);
            case 6:
                return (rand() % 10000 >= 9998);
            case 7:
                return (rand() % 10000 >= 9998);
            case 8:
                return (rand() % 10000 >= 9998);
            default:
                // This should never happen.
                return true;
        }
    } else {
        // The cell is currently dead.
        // This decides what happens next.
        switch(neighbour_count) {
            case 0:
                return (rand() % 10000 >= 9998);
            case 1:
                return (rand() % 10000 >= 9998);
            case 2:
                return (rand() % 10000 >= 9990);
            case 3:
                return (rand() % 10000 >= 10);
            case 4:
                return (rand() % 10000 >= 9990);
            case 5:
                return (rand() % 10000 >= 9998);
            case 6:
                return (rand() % 10000 >= 9998);
            case 7:
                return (rand() % 10000 >= 9998);
            case 8:
                return (rand() % 10000 >= 9998);
            default:
                // This should never happen.
                return true;
        }
    }
}

/*
 * Create the next board based off the current board.
 */
void iterate(bool* current, bool* next, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = j * height + i;
            int neighbour_count = count_neighbours(current, i, j, height, width);
            bool new_value = decide_next(current[index], neighbour_count);
            next[index] = new_value;
        }
    }
}

/*
 * Prints the grid.
 * Used for debuging purposes.
 */
void print_grid(bool* grid, int height, int width) {
    for(int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = j * height + i;
            if (grid[index]) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Just some skeleton scafolding to run the "game."
 */
int main() {
    // We need this otherwise every run will be the same.
    srand((unsigned int)time(NULL));
    // Setup the dimensions of the board.
    int width = 200;
    int height = 30;
    // Allocate memory for the boards.
    bool* current = (bool*)malloc(sizeof(bool) * height * width);
    bool* next = (bool*)malloc(sizeof(bool) * height * width);
    // Set the boards to 0.
    memset(current, false, sizeof(bool) * height * width);
    memset(next, false, sizeof(bool) * height * width);

    // Initial conditions
    for (int i = 0; i < height * 3; i+=3) {
        current[i] = true;
    }

    // Iteration
    for (int i = 0; i < 5000; i++) {
        iterate(current, next, height, width);
        bool* tmp = next;
        next = current;
        current = tmp;
    }

    // For the moment we just print out the last 500 iterations.
    for (int i = 0; i < 500; i++) {
        print_grid(current, height, width);
        iterate(current, next, height, width);
        bool* tmp = next;
        next = current;
        current = tmp;
    }

    // Cleanup.
    free(current);
    free(next);
    return 0;
}

