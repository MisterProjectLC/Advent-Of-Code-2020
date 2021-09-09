#include <stdio.h>

int main() {
    int minimum, maximum, amount_valid = 0;

    // Scan each line
    for (int n = 0; scanf("%d", &minimum) != EOF;) {
        char target_letter;
        int times_appeared = 0;
        scanf("%*c%d", &maximum);
        scanf("%*c%c%*c%*c", &target_letter);

        // Scan each char in string
        for (char received_letter; scanf("%c", &received_letter) != EOF;) {
            if (received_letter == '\n')
                break;

            if (received_letter == target_letter)
                times_appeared++;
        }

        if (minimum <= times_appeared && times_appeared <= maximum)
            amount_valid++;
    }

    printf("%d\n", amount_valid);
    return 0;
}