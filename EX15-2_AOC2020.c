#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

#define TARGET 30000000

int main() {
    // Input
    avl* tree =  (avl*)malloc(sizeof(avl));
    inicializar(tree);

    long long int data, size = 0;
    while (scanf("%lli", &data) != EOF) {
        inserir(tree, data, size);
        size++;
    }

    int last_seen = -1, this_time;

    for (long long int i = size; i < TARGET; i++) {
        if (last_seen == -1)
            data = 0;
        else
            data = i-1-last_seen;

        this_time = retornar(tree, data);
        inserir(tree, data, i);
        //printf("%lli %lli\n", data, i);

        last_seen = this_time;
    }

    printf("%lli\n", data);

    return 0;
}