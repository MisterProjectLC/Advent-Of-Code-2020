#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int n_children;
    unsigned long long int path_count;
    int children[3];
} node;

node* nodes[100000];

unsigned long long int path_count(node* root) {
    if (root->path_count == 0) { 
        if (root->n_children == 0)
            root->path_count = 1;
        else {
            for (int i = 0; i < root->n_children; i++) {
                root->path_count += path_count(nodes[root->children[i]]);
            }
        }
    }

    return root->path_count;
}

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

    // Create a tree
    for (int i = 0; i < size; i++) {
        nodes[i] = (node*)malloc(sizeof(node));
        nodes[i]->value = vetor[i];
        nodes[i]->n_children = 0;
        nodes[i]->path_count = 0;

        for (int j = i+1; j < size && vetor[j] <= vetor[i]+3; j++) {
            nodes[i]->children[nodes[i]->n_children] = j;
            nodes[i]->n_children++;
        }
    }

    printf("HOOPLA\n");
    printf("%llu\n", path_count(nodes[0]));

    return 0;
}