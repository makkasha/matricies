#include <stdio.h>
#include <stdlib.h>

void matVect(double** mat, double* a, double* c, int n){
    for(int i = 0; i < n; i++) {
        c[i] = 0;
        for (int j = 0; j < n; j++) {
            c[i] += *(*(mat + i) + j) * a[j];
        }
    }
}

int main() {

    int* row = (int*)malloc(sizeof(int));
    int* col = (int*)malloc(sizeof(int));
    printf("Enter nrow and ncol:\n");
    scanf("%d %d", row, col);

    double** mat = NULL; //A pointer to a pointer to an int
    //Allocate a block of memory for an array of pointers to int (there are n = row of pointers in this array)
    mat = malloc((*row)*sizeof(double*));
    for(int i = 0; i < *col; i++){
        //Allocate a block of memory to each element in the array of pointers,
        //each getting a block that can store m = col pointers to ints
        mat[i] = malloc((*col)*sizeof(double));
    }
    //What now was created was a matrix with n = row and m = col

    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            printf("enter mat[%d][%d]\n", i, j);
            scanf("%lf", &(mat[i][j]));
        }
    }

    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            printf("mat[%d][%d] is %.4f\n", i, j, (mat[i][j]));
        }
    }

    double* v = (double*)malloc((*row)*sizeof(double ));
    double* c = (double*)malloc((*row)*sizeof(double));

    for(int i = 0; i < *row; i++){
            printf("enter v[%d]\n", i);
            scanf("%lf", v + i);
    }

    matVect(mat, v, c, *row);

    for(int i = 0; i < *row; i++){
        printf("c[%d] is %lf\n", i, c[i]);
    }

    return 0;
}
