#include <stdio.h>

int main() {
    int amount = 0;
    int line_length = 1, first_line = 1;

    // Scan each char
    char c;
    for (long long int x = 0, y = 0; scanf("%c", &c) != EOF;) {
        // Line break
        if (c == '\n') {
            // Register line length
            if (first_line) {
                first_line = 0;
                line_length = x - 1;
            }
            printf("\n");
            y++;
            x = 0;
        
        } else {
             // Register tree collision (ouch)
            if (y > 0 && x == (y*3) % line_length) {
                if (c == '#') {
                    amount++;
                }
                printf("%lld", x);
            } else {
                printf("%c", c);
            }
            x++;
        }

    }

    printf("%d\n", amount);
}