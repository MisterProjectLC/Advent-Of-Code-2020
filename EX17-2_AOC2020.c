#include <stdio.h>

#define SIZE 45
#define INIT_SIZE 8

int main() {
    // Input
    char matrix[SIZE][SIZE][SIZE][SIZE] = {'.'};
    char new_matrix[SIZE][SIZE][SIZE][SIZE] = {'.'};

    int w_size = 1, z_size = 1, y_size = INIT_SIZE, x_size = INIT_SIZE;
    
    // Input
    char c;
    int xx = (SIZE - x_size)/2;
    int yy = (SIZE - y_size)/2;
    
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            yy++;
            xx = (SIZE - x_size)/2;
        } else {
            matrix[SIZE/2][SIZE/2][yy][xx] = c;
            xx++;
        }
    }

    
    int w_initial = (SIZE)/2, z_initial = (SIZE)/2, y_initial = (SIZE - y_size)/2, x_initial = (SIZE - x_size)/2;

    for (int y = y_initial; y < y_initial + y_size; y++) {
        for (int x = x_initial; x < x_initial + x_size; x++) {
            new_matrix[SIZE/2][SIZE/2][y][x] = matrix[SIZE/2][SIZE/2][y][x];
        }
    }

    // Apply the rules

    for (int t = 0; t < 6; t++) {
        w_size += 2; w_initial--;
        z_size += 2; z_initial--;
        y_size += 2; y_initial--;
        x_size += 2; x_initial--;
        printf("%d %d %d %d\n%d %d %d %d\n-----\n", w_initial, z_initial, y_initial, x_initial, w_size, z_size, y_size, x_size);

        for (int w = w_initial; w < w_initial+w_size; w++) {
            for (int z = z_initial; z < z_initial+z_size; z++) {
                for (int y = y_initial; y < y_initial+y_size; y++) {
                    for (int x = x_initial; x < x_initial+x_size; x++) {
                        // Adjacency check
                        int adjacents = 0;
                        for (int i = w-1; i <= w+1; i++) {
                            for (int j = z-1; j <= z+1; j++) {
                                for (int k = y-1; k <= y+1; k++) {
                                    for (int l = x-1; l <= x+1; l++) {
                                        if (i == w && j == z && k == y && l == x)
                                            continue;
                                    
                                        adjacents += (matrix[i][j][k][l] == '#');
                                    }
                                }
                            }
                        }

                        if (adjacents == 3 || (adjacents == 2 && matrix[w][z][y][x] == '#'))
                            new_matrix[w][z][y][x] = '#';
                        else
                            new_matrix[w][z][y][x] = '.';
                    }
                }
            }
        }

        // Turn new into old
        for (int w = w_initial; w < w_initial+w_size; w++)
            for (int z = z_initial; z < z_initial+z_size; z++)
                for (int y = y_initial; y < y_initial+y_size; y++)
                    for (int x = x_initial; x < x_initial+x_size; x++)
                        matrix[w][z][y][x] = new_matrix[w][z][y][x];

    }

    int count = 0;
    for (int w = w_initial; w < w_initial+w_size; w++)
        for (int z = z_initial; z < z_initial+z_size; z++)
            for (int y = y_initial; y < y_initial+y_size; y++)
                for (int x = x_initial; x < x_initial+x_size; x++)
                    count += (matrix[w][z][y][x] == '#');

    printf("%d\n", count);

    return 0;
}