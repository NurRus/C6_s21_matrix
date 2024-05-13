#include "s21_matrix_test.h"

START_TEST(s21_transpose_1) {
  matrix_t *matrix_A = NULL, result;

  ck_assert_int_eq(s21_transpose(matrix_A, &result), 1);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t matrix_A, result, etalon;

  s21_create_matrix(3, 2, &matrix_A);
  s21_create_matrix(2, 3, &etalon);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[1][0] = 2;
  matrix_A.matrix[2][0] = 3;

  matrix_A.matrix[0][1] = 4;
  matrix_A.matrix[1][1] = 5;
  matrix_A.matrix[2][1] = 6;

  etalon.matrix[0][0] = 1;
  etalon.matrix[0][1] = 2;
  etalon.matrix[0][2] = 3;

  etalon.matrix[1][0] = 4;
  etalon.matrix[1][1] = 5;
  etalon.matrix[1][2] = 6;

  s21_transpose(&matrix_A, &result);

  ck_assert_int_eq(s21_eq_matrix(&etalon, &result), SUCCESS);

  s21_remove_matrix(&result);
  s21_remove_matrix(&etalon);
  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t matrix_A, result;

  s21_create_matrix(1, 1, &matrix_A);

  matrix_A.matrix[0][0] = 1;

  s21_transpose(&matrix_A, &result);

  ck_assert_int_eq(s21_eq_matrix(&matrix_A, &result), SUCCESS);

  s21_remove_matrix(&result);
  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_transpose_4) {
  matrix_t matrix_A, result, etalon;

  s21_create_matrix(1, 3, &matrix_A);
  s21_create_matrix(3, 1, &etalon);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 3;

  etalon.matrix[0][0] = 1;
  etalon.matrix[1][0] = 2;
  etalon.matrix[2][0] = 3;

  s21_transpose(&matrix_A, &result);

  ck_assert_int_eq(s21_eq_matrix(&etalon, &result), SUCCESS);

  s21_remove_matrix(&result);
  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&etalon);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s = suite_create("s21_transpose_suite");
  TCase *tc = tcase_create("s21_transpose_testcase");

  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);
  tcase_add_test(tc, s21_transpose_3);
  tcase_add_test(tc, s21_transpose_4);

  suite_add_tcase(s, tc);
  return s;
}