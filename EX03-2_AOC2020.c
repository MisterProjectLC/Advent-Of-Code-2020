#include <stdio.h>

#define MAX 1000

int checkCollisions(int matrix[][MAX], int lines, int columns, int right, int down);

int main() {
    int matrix[MAX][MAX];
    int x = 0, y = 0;

    // Scan each char
    char c;
    while (scanf("%c", &c) != EOF) {
        // Line break
        if (c == '\n') {
            y++;
            x = 0;
        
        } else {
            matrix[y][x] = c;
            x++;
        }
    }

    y += 1;
    printf("%lli\n", (long long int)(checkCollisions(matrix, x, y, 1, 1)*checkCollisions(matrix, x, y, 3, 1)*checkCollisions(matrix, x, y, 5, 1)*
                    checkCollisions(matrix, x, y, 7, 1)*checkCollisions(matrix, x, y, 1, 2)));
}

int checkCollisions(int matrix[][MAX], int columns, int lines, int right, int down) {
    int amount = 0;
    for (int x = right, y = down; y < lines; x += right, y += down) {
        if (x >= columns)
            x -= columns;

        if (matrix[y][x] == '#')
            amount++;
    }
    
    printf("%d\n", amount);
    return amount;
}