#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = 1;
  if (rows > 0 && columns > 0 && result != 0) {
    flag = 0;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
  }
  return flag;
}

int s21_CHECKMATRIX(matrix_t *A) {
  int result = 1;
  if (A != NULL) {
    if (A->matrix != NULL) {
      result = 0;
    }
  }
  return result;
}

void s21_remove_matrix(matrix_t *A) {
  if (s21_CHECKMATRIX(A) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = 0;
      }
    }
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i]) free(A->matrix[i]);
    }
    if (A->matrix) free(A->matrix);
    A->matrix = NULL;
    A = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if (s21_CHECKMATRIX(A) == 0 && s21_CHECKMATRIX(B) == 0) {
    if (s21_SIZECHECK(A, B) == 0) {
      if ((s21_COMPARISIONMATRIX(A, B) == 0)) {
        result = SUCCESS;
      }
    }
  }
  return result;
}

int s21_SIZECHECK(matrix_t *A, matrix_t *B) {
  int result = 1;
  if (s21_CHECKMATRIX(A) == 0 && s21_CHECKMATRIX(B) == 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      result = 0;
    }
  }
  return result;
}

int s21_COMPARISIONMATRIX(matrix_t *A, matrix_t *B) {
  int result = 0;
  double delta = 0;
  for (int i = 0; i < A->rows && result == 0; i++) {
    for (int j = 0; j < A->columns && result == 0; j++) {
      delta = fabs(A->matrix[i][j] - B->matrix[i][j]);
      if (delta > nan) {
        result = 1;
      }
    }
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0 && s21_CHECKMATRIX(B) == 0 && result != NULL) {
    if (s21_SIZECHECK(A, B) == 1) {
      flag = 2;
    } else {
      flag = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0 && s21_CHECKMATRIX(B) == 0 && result != NULL) {
    if (s21_SIZECHECK(A, B) == 1) {
      flag = 2;
    } else {
      flag = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0 && result != NULL) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0 && s21_CHECKMATRIX(B) == 0 && result != NULL) {
    if (A->columns != B->rows) {
      flag = 2;
    } else {
      flag = s21_create_matrix(A->rows, B->columns, result);
      s21_SIMPLMULT(A, B, result);
    }
  }
  return flag;
}

void s21_SIMPLMULT(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0 && result != NULL) {
    flag = s21_create_matrix(A->columns, A->rows, result);
    for (int j = 0; j < A->columns; j++) {
      for (int i = 0; i < A->rows; i++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return flag;
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0) {
    if (A->rows != A->columns) {
      flag = 2;
    } else if (A->rows == 1) {
      *result = A->matrix[0][0];
      flag = 0;
    } else {
      flag = 0;
      matrix_t B;
      s21_create_matrix(A->rows, A->columns, &B);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          B.matrix[i][j] = A->matrix[i][j];
        }
      }
      int sign_determinant = s21_TRIANGULARMATRIX(&B);
      *result = 1;
      for (int i = 0; i < B.rows; i++) {
        *result = *result * B.matrix[i][i];
      }
      *result = *result * sign_determinant;
      s21_remove_matrix(&B);
    }
  }
  return flag;
}

int s21_ZEROLINECHECK(matrix_t *A) {
  int result = 0;
  int i = 0;
  int j = 0;
  while (result == 0 && i < A->rows) {
    result = 1;
    for (j = 0; j < A->columns; j++) {
      if (A->matrix[i][j] != 0) {
        result = 0;
      }
    }
    i++;
  }
  j = 0;
  while (result == 0 && j < A->columns) {
    result = 1;
    for (i = 0; i < A->columns; i++) {
      if (A->matrix[i][j] != 0) {
        result = 0;
      }
    }
    j++;
  }
  return result;
}

int s21_TRIANGULARMATRIX(matrix_t *result) {
  int sign = 1;
  int i = 0;
  while (i < result->rows - 1 && s21_CHECKINGFORZERO(result, i, &sign) == 0 &&
         s21_ZEROLINECHECK(result) == 0) {
    s21_NULLING(result, i);
    i++;
  }
  return sign;
}

int s21_CHECKINGFORZERO(matrix_t *A, int m, int *s) {
  int result = 0;
  int k = m;
  while (A->matrix[k][m] == 0 && k < A->rows - 1) {
    k++;
  }
  if (k > m && k < A->rows) {
    double buffer;
    for (int j = 0; j < A->columns; j++) {
      buffer = A->matrix[m][j];
      A->matrix[m][j] = A->matrix[k][j];
      A->matrix[k][j] = buffer;
    }
    *s = *s * (-1);
  } else if (k >= A->rows) {
    result = 1;
  }
  return result;
}

void s21_NULLING(matrix_t *A, int n) {
  double coefficient;
  for (int i = n; i < A->rows - 1; i++) {
    coefficient = -1 * (A->matrix[i + 1][n] / A->matrix[n][n]);
    for (int j = n; j < A->columns; j++) {
      A->matrix[i + 1][j] = A->matrix[i + 1][j] + coefficient * A->matrix[n][j];
    }
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0 && result != 0) {
    if (A->rows != A->columns) {
      flag = 2;
    } else {
      flag = s21_create_matrix(A->rows, A->columns, result);
      if (A->rows == 1) {
        result->matrix[0][0] = 1;
      } else {
        s21_CALCALGORITM(A, result);
      }
    }
  }
  return flag;
}

void s21_CALCALGORITM(matrix_t *A, matrix_t *result) {
  matrix_t Minor;
  s21_create_matrix(A->rows - 1, A->columns - 1, &Minor);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] =
          pow(-1, (i + j)) * s21_MINORDETERMINANT(A, &Minor, i, j);
    }
  }
  s21_remove_matrix(&Minor);
}

double s21_MINORDETERMINANT(matrix_t *A, matrix_t *M, int m, int n) {
  double result = 0;
  int k = 0, l;
  for (int i = 0; i < A->rows; i++) {
    l = 0;
    if (i != m) {
      for (int j = 0; j < A->columns; j++) {
        if (j != n) {
          M->matrix[k][l] = A->matrix[i][j];
          l++;
        }
      }
      k++;
    }
  }
  s21_determinant(M, &result);
  return result;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = 1;
  if (s21_CHECKMATRIX(A) == 0 && result != 0) {
    double determinant = 0;
    flag = s21_determinant(A, &determinant);
    if (flag == 0) {
      if (determinant == 0) {
        flag = 2;
      } else if (A->rows == 1) {
        flag = s21_create_matrix(1, 1, result);
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        matrix_t M, MT;
        s21_calc_complements(A, &M);
        s21_transpose(&M, &MT);
        flag = s21_mult_number(&MT, (1 / determinant), result);
        s21_remove_matrix(&M);
        s21_remove_matrix(&MT);
      }
    }
  }
  return flag;
}
