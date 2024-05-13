#include "s21_matrix_test.h"

START_TEST(s21_mult_number_1) {
  matrix_t *A = NULL, result;
  double number = 23.334;
  ck_assert_int_eq(s21_mult_number(A, number, &result), 1);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A, result, etalon;

  double number = 23.4;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &etalon);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = i + j;
    }
  }

  etalon.matrix[0][0] = 0;
  etalon.matrix[0][1] = 1 * number;
  etalon.matrix[1][0] = 1 * number;
  etalon.matrix[1][1] = 2 * number;

  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&etalon);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s = suite_create("s21_mult_number_suite");
  TCase *tc = tcase_create("s21_mult_number_testcase");

  tcase_add_test(tc, s21_mult_number_1);
  tcase_add_test(tc, s21_mult_number_2);

  suite_add_tcase(s, tc);
  return s;
}