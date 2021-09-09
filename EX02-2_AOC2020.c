#include <stdio.h>

int main() {
    int first, second, amount_valid = 0;

    // Scan each line
    for (int n = 0; scanf("%d", &first) != EOF;) {
        char target_letter;
        int times_appeared = 0;
        scanf("%*c%d", &second);
        scanf("%*c%c%*c%*c", &target_letter);

        // Scan each char in string
        int i = 1;
        for (char received_letter; scanf("%c", &received_letter) != EOF; i++) {
            if (received_letter == '\n')
                break;

            if (received_letter == target_letter && (i == first || i == second))
                times_appeared++;
        }

        if (times_appeared == 1)
            amount_valid++;
    }

    printf("%d\n", amount_valid);
    return 0;
}