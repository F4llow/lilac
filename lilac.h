#ifndef lilac_h
#define lilac_h

#include <stdbool.h>

typedef struct Matrix {
    double **arr;
    int row;
    int column;
} Matrix;

int matrix_init(Matrix *m_a, int row, int column, bool random);
int matrix_manual(Matrix *m_a, int row, int column);
int matrix_free(Matrix *m_a);

int matrix_arr_print(double **arr, int row, int column);
int matrix_struct_print(Matrix *m_a);

int matrix_addition(const Matrix *m_a, const Matrix *m_b, Matrix *m_c);
int matrix_subtraction(const Matrix *m_a, const Matrix *m_b, Matrix *m_c);
int matrix_dot_product(const Matrix *m_a, const Matrix *m_b, Matrix *m_c);
int matrix_transpose(const Matrix *m_a, Matrix *m_b);
int matrix_duplicate(const Matrix *m_a, Matrix *m_b);

double rand_uniform();

#endif