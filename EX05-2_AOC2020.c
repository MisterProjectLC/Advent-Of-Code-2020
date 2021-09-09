#include <stdio.h>

int main() {
    char c;
    int r_min = 0, r_max = 127;
    int c_min = 0, c_max = 7;
    int seat_list[128][8] = {0};
    while (scanf("%c", &c) != EOF) {
        if (c == 'F')
            r_max = r_min + (r_max-r_min)/2;
        else if (c == 'B')
            r_min += (1+r_max-r_min)/2;
        else if (c == 'L')
            c_max = c_min + (c_max-c_min)/2;
        else if (c == 'R')
            c_min += (1+c_max-c_min)/2;
        
        // End line
        else if (c == '\n') {
            seat_list[r_max][c_min] += 1;
            printf("%d %d %d %d %d\n", r_min, r_max, c_min, c_max, seat_list[r_max][c_min]);
            r_min = 0; r_max = 127; c_min = 0; c_max = 7;
        }

    }

    for (int i = 1; i < 127; i++) { // skip front and back
        for (int j = 0; j < 8; j++) {
            if (seat_list[i][j] == 0)
                printf("%d %d %d\n", i, j, i*8 + j);
        }
    }

    return 0;
}