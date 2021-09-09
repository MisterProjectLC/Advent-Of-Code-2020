#include <stdio.h>

#define TARGET 2020

int main() {
    // Input
    int vetor[100000];
    int size = 0;
    while (scanf("%d", &vetor[size]) != EOF) {size++;}

    for (int i = size; i < TARGET; i++) {
        int last = vetor[i-1];
        int found = 0;

        for (int j = i-2; j >= 0 && !found; j--) {
            if (vetor[j] == last) {
                vetor[i] = i-1 - j;
                found = 1;
            }
        }

        if (!found)
            vetor[i] = 0;
        
        //printf("%d\n", vetor[i]);
    }

    printf("%d\n", vetor[TARGET-1]);

    return 0;
}