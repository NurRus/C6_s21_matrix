#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define nan 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_CHECKMATRIX(matrix_t *A);
int s21_SIZECHECK(matrix_t *A, matrix_t *B);
int s21_COMPARISIONMATRIX(matrix_t *A, matrix_t *B);
void s21_SIMPLMULT(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_TRIANGULARMATRIX(matrix_t *result);
void s21_NULLING(matrix_t *A, int n);
int s21_ZEROLINECHECK(matrix_t *A);
double s21_MINORDETERMINANT(matrix_t *A, matrix_t *M, int m, int n);
void s21_CALCALGORITM(matrix_t *A, matrix_t *result);
int s21_CHECKINGFORZERO(matrix_t *A, int m, int *s);

#endif