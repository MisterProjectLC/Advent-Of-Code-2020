#include <stdio.h>

int main() {
    int vector[1000];
    int b;
    for (int n = 0; scanf("%d", &b) != EOF;) {
        if (b > 2020)
            continue;
        vector[n] = b;

        for (int i = n-1; i >= 0; i--) {
            for (int j = i-1; j >= 0; j--) {
                if (vector[i] + vector[j] + vector[n] == 2020) {
                    printf("%lli\n", (long long int)(vector[i]*vector[j]*vector[n]));
                }
            }
        }

        n++;
    }

    return 0;
}