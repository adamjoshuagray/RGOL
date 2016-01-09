#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int count_neighbours(bool* current, int x, int y, int width, int height) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int k = x + i;
            if (k == -1) {
                k = width - 1;
            }
            if (k == width) {
                k = 0;
            }
            int l = y + j;
            if (l == -1) {
                l = width - 1;
            }
            if (l == height) {
                l = 0;
            }
            int index = l * width + k;
            if (current[index]) {
                count++;
            }
        }
    }
    return count;
}

void iterate(bool* current, bool* next, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {

        }
    }
}

int main() {
    int height = 10000;
    int width = 10000;
    bool* current = (bool*)malloc(sizeof(bool) * width * height);
    bool* next = (bool*)malloc(sizeof(bool) * width * height);
    memset(current, false, sizeof(bool) * width * height);
    memset(next, false, sizeof(bool) * width * height);
    return 0;
}

