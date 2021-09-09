#include <stdio.h>
#include <stdlib.h>

void move(char c, int d, int *x, int *y) {
    switch(c) {
            case 'N':
                *y += d;
                break;
            case 'S':
                *y -= d;
                break;
            case 'E':
                *x += d;
                break;
            case 'W':
                *x -= d;
                break;
        }
}

int main() {
    int x = 10, y = 1, ship_x = 0, ship_y = 0;

    // Input
    char c;
    int d;
    while (scanf("%c%d\n", &c, &d) != EOF) {
        if (c == 'F') {
            move('N', d*y, &ship_x, &ship_y);
            move('E', d*x, &ship_x, &ship_y);

        } else if (c == 'L') {
            for (int i = 0; i < d/90; i++) {
                int helper = -y;
                y = x;
                x = helper;
            }
        } else if (c == 'R') {
            for (int i = 0; i < d/90; i++) {
                int helper = -x;
                x = y;
                y = helper;
            }
        } else {
            move(c, d, &x, &y);
        }
    }

    printf("%d\n", abs(ship_x)+abs(ship_y));

    return 0;
}