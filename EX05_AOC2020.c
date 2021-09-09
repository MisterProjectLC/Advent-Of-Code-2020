#include <stdio.h>

int main() {
    char c;
    int r_min = 0, r_max = 127;
    int c_min = 0, c_max = 7;
    int highest_id = 0;
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
            printf("%d %d %d %d\n", r_min, r_max, c_min, c_max);
            int id = r_max*8 + c_min;
            if (highest_id < id)
                highest_id = id;
            r_min = 0; r_max = 127; c_min = 0; c_max = 7;
        }

    }

    printf("%d\n", highest_id);
    return 0;
}