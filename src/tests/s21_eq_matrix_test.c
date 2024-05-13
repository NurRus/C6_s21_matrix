#include "s21_matrix_test.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t matrix_A, matrix_B;

  int rows_A = 3;
  int columns_A = 4;
  s21_create_matrix(rows_A, columns_A, &matrix_A);

  int rows_B = 3;
  int columns_B = 5;
  s21_create_matrix(rows_B, columns_B, &matrix_B);

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &matrix_B), FAILURE);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t matrix_A, matrix_B;

  int rows = 3;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = i + j;
    }
  }

  s21_create_matrix(rows, columns, &matrix_B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_B.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &matrix_B), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t matrix_A, matrix_B;

  int rows = 3;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = i + j;
    }
  }

  s21_create_matrix(rows, columns, &matrix_B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_B.matrix[i][j] = i + j;
    }
  }
  matrix_B.matrix[2][3] = 0;

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &matrix_B), FAILURE);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t matrix_A, matrix_B;

  int rows = 3;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = i + j;
    }
  }

  s21_create_matrix(rows, columns, &matrix_B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_B.matrix[i][j] = i + j;
    }
  }
  matrix_B.matrix[0][1] = 1.0000001;

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &matrix_B), FAILURE);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t matrix_A, matrix_B;

  int rows = 3;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = i + j;
    }
  }

  s21_create_matrix(rows, columns, &matrix_B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_B.matrix[i][j] = i + j;
    }
  }
  matrix_A.matrix[0][1] = 123456789.00000011;
  matrix_B.matrix[0][1] = 123456789.0000001;

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &matrix_B), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t matrix_A, matrix_B;

  int rows = 3;
  int columns = 4;
  s21_create_matrix(rows, columns, &matrix_A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = i + j;
    }
  }

  s21_create_matrix(rows, columns, &matrix_B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_B.matrix[i][j] = i + j;
    }
  }
  matrix_A.matrix[0][1] = 12345678903.000011;
  matrix_B.matrix[0][1] = 12345678903.000012;

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &matrix_B), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  matrix_t matrix_A, M;

  s21_create_matrix(3, 3, &matrix_A);
  s21_create_matrix(3, 3, &M);

  matrix_A.matrix[0][0] = -1;
  matrix_A.matrix[0][1] = 38;
  matrix_A.matrix[0][2] = -27;

  matrix_A.matrix[1][0] = 1;
  matrix_A.matrix[1][1] = -41;
  matrix_A.matrix[1][2] = 29;

  matrix_A.matrix[2][0] = -1;
  matrix_A.matrix[2][1] = 34;
  matrix_A.matrix[2][2] = -24;

  M.matrix[0][0] = -1;
  M.matrix[0][1] = 38;
  M.matrix[0][2] = -27;

  M.matrix[1][0] = 1;
  M.matrix[1][1] = -41;
  M.matrix[1][2] = 29;

  M.matrix[2][0] = -1;
  M.matrix[2][1] = 34;
  M.matrix[2][2] = -24;

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &M), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&M);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s = suite_create("s21_eq_matrix_suite");
  TCase *tc = tcase_create("s21_eq_matrix_testcase");

  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);
  tcase_add_test(tc, s21_eq_matrix_5);
  tcase_add_test(tc, s21_eq_matrix_6);
  tcase_add_test(tc, s21_eq_matrix_7);

  suite_add_tcase(s, tc);
  return s;
}