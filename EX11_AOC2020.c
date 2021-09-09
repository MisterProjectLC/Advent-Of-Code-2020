#include <stdio.h>

int main() {
    // Input
    int matrix[1000][1000];
    int new_matrix[1000][1000];

    int y_size = 0, x_size = 0;
    
    // Input
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            y_size++;
            x_size = 0;
        } else {
            matrix[y_size][x_size] = c;
            x_size++;
        }
    }
    y_size++;

    for (int y = 0; y < y_size; y++)
        for (int x = 0; x < x_size; x++)
            new_matrix[y][x] = matrix[y][x];

    // Apply the rules
    int has_changed;
    do {
        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                if (matrix[y][x] == '.') {
                    continue;
                }

                // Adjacency check
                int adjacents = 0;
                for (int i = y-1; i <= y+1 && i < y_size; i++) {
                    for (int j = x-1; j <= x+1 && j < x_size; j++) {
                        if (i < 0 || j < 0 || (i == y && j == x))
                            continue;
                        
                        adjacents += (matrix[i][j] == '#');
                    }
                }

                if (adjacents == 0)
                    new_matrix[y][x] = '#';
                else if (adjacents >= 4)
                    new_matrix[y][x] = 'L';
            }
        }

        // Turn new into old
        has_changed = 0;
        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                has_changed += (!has_changed && matrix[y][x] != new_matrix[y][x]);
                matrix[y][x] = new_matrix[y][x];
            }
        }

    } while (has_changed);

    int count = 0;
    for (int y = 0; y < y_size; y++)
        for (int x = 0; x < x_size; x++)
            count += (matrix[y][x] == '#');

    printf("%d\n", count);


    return 0;
}