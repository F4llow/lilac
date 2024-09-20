#include "lilac.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double rand_uniform() {
    return (-1 + (2 * ((double)rand()) / RAND_MAX));
}

int matrix_arr_print(double **arr, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%f    ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

int matrix_struct_print(Matrix *m_a) {
    printf("______________________________________\n");
    printf("Matrix.arr:\n");
    matrix_arr_print(m_a->arr, m_a->row, m_a->column);
    printf("Matrix.row: %d\n", m_a->row);
    printf("Matrix.column: %d\n", m_a->column);
    printf("______________________________________\n");

    return 0;
}

int matrix_init(Matrix *m_a, int row, int column, bool random) {
    m_a->row = row;
    m_a->column = column;

    double **arr = (double **)calloc(row, sizeof(double *));
    for (int i = 0; i < row; i++) {
        arr[i] = (double *)calloc(column, sizeof(double));
    }
    m_a->arr = arr;

    srand(time(NULL));
    if (random) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                arr[i][j] = rand_uniform();
            }
        }
    }

    // matrix_arr_print(arr, row, column);

    return 0;
}

int matrix_free(Matrix *m_a) {
    for (int i = 0; i < m_a->row; i++) {
        free(m_a->arr[i]);
    }

    free(m_a->arr);

    m_a->arr = NULL;
    m_a->row = 0;
    m_a->column = 0;

    return 0;
}

int matrix_dot_product(const Matrix *m_a, const Matrix *m_b, Matrix *m_c) {
    if (m_a->column != m_b->row) {
        return 1;
    }

    int n = m_a->row;
    int p = m_a->column; // m_a->column == m_b->row
    int q = m_b->column;

    matrix_init(m_c, n, q, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            m_c->arr[i][j] = 0;
            for (int k = 0; k < p; k++) {
                m_c->arr[i][j] += m_a->arr[i][k] * m_b->arr[k][j];
            }
        }
    }

    return 0;
}

int matrix_addition(const Matrix *m_a, const Matrix *m_b, Matrix *m_c) {
    if ((m_a->row != m_b->row) || (m_a->column != m_b->column)) {
        return 1;
    }

    int n = m_a->row;
    int p = m_a->column;

    matrix_init(m_c, n, p, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            m_c->arr[i][j] = m_a->arr[i][j] + m_b->arr[i][j];
        }
    }

    return 0;
}

int matrix_subtraction(const Matrix *m_a, const Matrix *m_b, Matrix *m_c) {
    if ((m_a->row != m_b->row) || (m_a->column != m_b->column)) {
        return 1;
    }

    int n = m_a->row;
    int p = m_a->column;

    matrix_init(m_c, n, p, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            m_c->arr[i][j] = m_a->arr[i][j] - m_b->arr[i][j];
        }
    }

    return 0;
}

int matrix_transpose(const Matrix *m_a, Matrix *m_b) {
    int n = m_a->row;
    int p = m_a->column;

    matrix_init(m_b, p, n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            m_b->arr[j][i] = m_a->arr[i][j]; 
        }
    }

    return 0;
}

int matrix_manual(Matrix *m_a, int row, int column) {
    m_a->row = row;
    m_a->column = column;

    double **arr = (double **)calloc(row, sizeof(double *));
    for (int i = 0; i < row; i++) {
        arr[i] = (double *)calloc(column, sizeof(double));
    }
    m_a->arr = arr;

    // max 5 digit number
    char buffer[7];
    char *buffer_end;
    double digit;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("Please enter the value for arr[%d][%d]: ", i, j);
            fgets(buffer, sizeof(buffer), stdin);
            digit = strtod(buffer, &buffer_end);
            arr[i][j] = digit;
        }
    }

    return 0;
}

// not a deep copy
int matrix_duplicate(const Matrix *m_a, Matrix *m_b) {
    m_b->arr = m_a->arr;
    m_b->row = m_a->row;
    m_b->column = m_a->column;

    return 0;
}