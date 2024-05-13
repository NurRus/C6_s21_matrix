#include "s21_matrix_test.h"

START_TEST(s21_create_matrix_1) {
  matrix_t matrix_A, matrix_B, *matrix_C = NULL;

  int rows_A = 32;
  int columns_A = 54;

  int rows_B = 32;
  int columns_B = 0;

  ck_assert_int_eq(s21_create_matrix(rows_A, columns_A, &matrix_A), 0);

  ck_assert_int_eq(matrix_A.rows, rows_A);
  ck_assert_int_eq(matrix_A.columns, columns_A);
  ck_assert_int_eq(s21_create_matrix(rows_B, columns_B, &matrix_B), 1);
  ck_assert_int_eq(s21_create_matrix(rows_A, columns_A, matrix_C), 1);

  s21_remove_matrix(&matrix_A);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s = suite_create("s21_create_matrix_suite");
  TCase *tc = tcase_create("s21_create_matrix_testcase");

  tcase_add_test(tc, s21_create_matrix_1);

  suite_add_tcase(s, tc);
  return s;
}