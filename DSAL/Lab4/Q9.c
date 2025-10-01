#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows, cols;
    int **data;
};

int main() {
    struct Matrix m;
    int i, j;

    printf("Enter rows and cols: ");
    scanf("%d %d", &m.rows, &m.cols);

    // allocate memory for row pointers
    m.data = (int **)malloc(m.rows * sizeof(int *));
    for (i = 0; i < m.rows; i++) {
        m.data[i] = (int *)malloc(m.cols * sizeof(int));
    }

    printf("Enter elements:\n");
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            scanf("%d", &m.data[i][j]);
        }
    }

    printf("Matrix:\n");
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);

    return 0;
}