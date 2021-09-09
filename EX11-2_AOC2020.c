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

                // Vision check
                int visible = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (i == 0 && j == 0)
                            continue;
                        for (int yy = y+i, xx = x+j; (yy >= 0 && yy < y_size) && (xx >= 0 && xx < x_size); yy += i, xx += j) {
                            if (matrix[yy][xx] == '#') {
                                visible++;
                                break;
                            } else if (matrix[yy][xx] == 'L') {
                                break;
                            }
                        }
                    }
                }   

                if (visible == 0)
                    new_matrix[y][x] = '#';
                else if (visible >= 5)
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