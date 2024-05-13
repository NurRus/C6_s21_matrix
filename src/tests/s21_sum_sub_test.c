#include "s21_matrix_test.h"

START_TEST(s21_sum_sub_matrix_1) {
  matrix_t matrix_A, matrix_B, matrix_C;

  int rows_A = 3;
  int columns_A = 5;

  int rows_B = 3;
  int columns_B = 4;

  s21_create_matrix(rows_A, columns_A, &matrix_A);
  s21_create_matrix(rows_B, columns_B, &matrix_B);

  ck_assert_int_eq(s21_sum_matrix(&matrix_A, &matrix_B, &matrix_C), 2);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_sum_sub_matrix_2) {
  matrix_t matrix_A, *matrix_B = NULL, matrix_C;

  int rows_A = 3;
  int columns_A = 5;

  s21_create_matrix(rows_A, columns_A, &matrix_A);

  ck_assert_int_eq(s21_sum_matrix(&matrix_A, matrix_B, &matrix_C), 1);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_sum_sub_matrix_3) {
  matrix_t matrix_A, matrix_B, matrix_C, matrix_D;

  int rows = 3;
  int columns = 5;

  s21_create_matrix(rows, columns, &matrix_A);
  s21_create_matrix(rows, columns, &matrix_B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = i + j;
      matrix_B.matrix[i][j] = -i - j;
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&matrix_A, &matrix_B, &matrix_C), 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(matrix_C.matrix[i][j], 0);
    }
  }

  ck_assert_int_eq(s21_sub_matrix(&matrix_A, &matrix_B, &matrix_D), 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(matrix_D.matrix[i][j], 2 * (i + j));
    }
  }

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
  s21_remove_matrix(&matrix_C);
  s21_remove_matrix(&matrix_D);
}
END_TEST

START_TEST(s21_sum_sub_matrix_4) {
  matrix_t matrix_A, matrix_B, matrix_C;

  int rows_A = 3;
  int columns_A = 5;

  int rows_B = 3;
  int columns_B = 4;

  s21_create_matrix(rows_A, columns_A, &matrix_A);
  s21_create_matrix(rows_B, columns_B, &matrix_B);

  ck_assert_int_eq(s21_sub_matrix(&matrix_A, &matrix_B, &matrix_C), 2);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(s21_sum_sub_matrix_5) {
  matrix_t matrix_A, *matrix_B = NULL, matrix_C;

  int rows_A = 3;
  int columns_A = 5;

  s21_create_matrix(rows_A, columns_A, &matrix_A);

  ck_assert_int_eq(s21_sub_matrix(&matrix_A, matrix_B, &matrix_C), 1);

  s21_remove_matrix(&matrix_A);
}
END_TEST

Suite *s21_sum_sub_matrix_suite(void) {
  Suite *s = suite_create("s21_sum_sub_matrix_suite");
  TCase *tc = tcase_create("s21_sum_sub_matrix_testcase");

  tcase_add_test(tc, s21_sum_sub_matrix_1);
  tcase_add_test(tc, s21_sum_sub_matrix_2);
  tcase_add_test(tc, s21_sum_sub_matrix_3);
  tcase_add_test(tc, s21_sum_sub_matrix_4);
  tcase_add_test(tc, s21_sum_sub_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}