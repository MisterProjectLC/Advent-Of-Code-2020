#include <stdio.h>

int main() {
    // Input
    int vetor[100000];
    vetor[0] = 0;
    int size = 1;
    while (scanf("%d", &vetor[size]) != EOF) {size++;}

    // Sort the input (Bubblesort cuz I'm lazy as fuck)
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (vetor[i] > vetor[j]) {
                int helper = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = helper;
            }
        }
    }

    // Get the difference between each of them
    int diffs[3] = {0};
    for (int i = 1; i < size; i++) {
        diffs[vetor[i] - vetor[i-1] - 1]++;
    }

    diffs[2]++;
    printf("%d\n", diffs[0]*diffs[2]);


    return 0;
}