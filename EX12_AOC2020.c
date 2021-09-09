#include <stdio.h>
#include <stdlib.h>

void move(char c, int d, int *x, int *y, int *direction) {
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
            case 'L':
                *direction -= d/90;
                while (*direction < 0) {*direction += 4;}
                break;
            case 'R':
                *direction += d/90;
                break;
            case 'F':
                switch (*direction % 4) {
                    case 0:
                        move('N', d, x, y, direction);
                        break;
                    case 1:
                        move('S', d, x, y, direction);
                        break;
                    case 2:
                        move('E', d, x, y, direction);
                        break;
                    case 3:
                        move('W', d, x, y, direction);
                        break;
                }
        }
}

int main() {
    int x = 0, y = 0;
    int direction = 1;

    // Input
    char c;
    int d;
    while (scanf("%c%d\n", &c, &d) != EOF) {
        move(c, d, &x, &y, &direction);
    }

    printf("%d\n", abs(x)+abs(y));

    return 0;
}