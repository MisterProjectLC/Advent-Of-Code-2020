#include <stdio.h>

#define TARGET 20874512

int main() {
    // Input
    int vetor[100000];
    int size = 0;
    while (scanf("%d", &vetor[size]) != EOF) {size++;}

    for (int i = 0; i < size; i++) {
        int min = vetor[i], max = vetor[i];
        int sum = vetor[i];

        for (int j = 1+i; j < size && sum <= TARGET; j++) {
            if (min > vetor[j])
                min = vetor[j];
            else if (max < vetor[j])
                max = vetor[j];

            sum += vetor[j];
            if (sum == TARGET) {
                printf("%d\n", max+min);
                return 0;
            }
        }
    }

    return 0;
}