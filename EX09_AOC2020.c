#include <stdio.h>

int main() {
    // Input
    int vetor[100000];
    int size = 0;
    while (scanf("%d", &vetor[size]) != EOF) {size++;}

    for (int i = 0; i < size; i++) {
        if (i < 25)
            continue;
        
        int valid = 0;
        for (int j = i - 25; j < i && !valid; j++) {
            for (int k = j+1; k < i && !valid; k++) {
                if (vetor[j]+vetor[k] == vetor[i])
                    valid = 1;
            }
        }

        if (!valid) {
            printf("%d\n", vetor[i]);
            return 0;
        }
    }

    return 0;
}