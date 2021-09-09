#include <stdio.h>

#define SIZE 100
#define INIT_SIZE 8

int main() {
    // Input
    char matrix[SIZE][SIZE][SIZE] = {'.'};
    char new_matrix[SIZE][SIZE][SIZE] = {'.'};

    int z_size = 1, y_size = INIT_SIZE, x_size = INIT_SIZE;
    
    // Input
    char c;
    int xx = (SIZE - x_size)/2;
    int yy = (SIZE - y_size)/2;
    
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            yy++;
            xx = (SIZE - x_size)/2;
        } else {
            matrix[SIZE/2][yy][xx] = c;
            xx++;
        }
    }

    
    int z_initial = (SIZE)/2, y_initial = (SIZE - y_size)/2, x_initial = (SIZE - x_size)/2;

    for (int y = y_initial; y < y_initial + y_size; y++) {
        for (int x = x_initial; x < x_initial + x_size; x++) {
            new_matrix[SIZE/2][y][x] = matrix[SIZE/2][y][x];
        }
    }

    // Apply the rules

    for (int t = 0; t < 6; t++) {
        z_size += 2; z_initial--;
        y_size += 2; y_initial--;
        x_size += 2; x_initial--;
        printf("%d %d %d\n%d %d %d\n-----\n", z_initial, y_initial, x_initial, z_size, y_size, x_size);

        for (int z = z_initial; z < z_initial+z_size; z++) {
            for (int y = y_initial; y < y_initial+y_size; y++) {
                for (int x = x_initial; x < x_initial+x_size; x++) {
                    // Adjacency check
                    int adjacents = 0;
                    for (int i = z-1; i <= z+1; i++) {
                        for (int j = y-1; j <= y+1; j++) {
                            for (int k = x-1; k <= x+1; k++) {
                                if (i == z && j == y && k == x)
                                    continue;
                            
                                adjacents += (matrix[i][j][k] == '#');
                            }
                        }
                    }

                    if (adjacents == 3 || (adjacents == 2 && matrix[z][y][x] == '#'))
                        new_matrix[z][y][x] = '#';
                    else
                        new_matrix[z][y][x] = '.';
                }
            }
        }

        // Turn new into old
        for (int z = z_initial; z < z_initial+z_size; z++) {
            for (int y = y_initial; y < y_initial+y_size; y++) {
                for (int x = x_initial; x < x_initial+x_size; x++) {
                    matrix[z][y][x] = new_matrix[z][y][x];
                }
            }
        }

    }

    int count = 0;
    for (int z = z_initial; z < z_initial+z_size; z++)
        for (int y = y_initial; y < y_initial+y_size; y++)
            for (int x = x_initial; x < x_initial+x_size; x++)
                count += (matrix[z][y][x] == '#');

    printf("%d\n", count);

    return 0;
}