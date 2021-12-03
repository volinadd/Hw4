#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void read_matr(int** matr, int n) {  
    int number;  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &number);
            matr[i][j] = number;
        }
    }   
}


void vertex_degrees(int* degrees, int** matr, int n) {
    int degree;
    int max = 0;
    for (int i = 0; i < n; i++) {
        degree = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                degree += 2 * matr[i][j];
            } else {
                degree += matr[i][j];
            }
        }
        degrees[i] = degree;
        if (degree > max) {
            max = degree;
        }      
    }

    int* freq = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max + 1; i++) {
        freq[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        freq[degrees[i]]++;
    }

    printf("\n");
    for (int i = 0; i < max + 1; i++) {
        if (freq[i] >= 0) {
            printf("Vertxes with degree %d: %d\n", i, freq[i] + 1);
        }
    }
    printf("\n");
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int* arr, int* match, int n) {
	int min_idx;
	for (int i = 0; i < n; i++) {
		min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[i], &arr[min_idx]);
        swap(&match[i], &match[min_idx]);
	}
}



int main() {
    printf("\nDimension of adjacency matrix: ");
    int n;
    scanf("%d", &n);
    int** matr = (int**)malloc(n* sizeof(int*));
    for (int i = 0; i < n; i++) {
        matr[i] = (int*)malloc(n * sizeof(int));
    }
    printf("\nMatrix:\n");
    read_matr(matr, n);

    int* degrees = (int*)malloc(n * sizeof(int));

    vertex_degrees(degrees, matr, n);

    int* vertexes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vertexes[i] = i;
    }

    selection_sort(degrees, vertexes, n);

    for (int i = 0; i < n; i++) {
        printf("V%d: deg = %d\n", vertexes[i], degrees[i]);
    }
    printf("\n");

    return 0;
}