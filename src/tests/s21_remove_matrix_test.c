#include "s21_matrix_test.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t matrix_A, *matrix_B = NULL;

  int rows_A = 32;
  int columns_A = 54;

  s21_create_matrix(rows_A, columns_A, &matrix_A);
  ck_assert_ptr_ne(&matrix_A, matrix_B);

  s21_remove_matrix(&matrix_A);
  ck_assert_ptr_eq(matrix_A.matrix, matrix_B);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s = suite_create("s21_remove_matrix_suite");
  TCase *tc = tcase_create("s21_remove_matrix_testcase");

  tcase_add_test(tc, s21_remove_matrix_1);

  suite_add_tcase(s, tc);
  return s;
}