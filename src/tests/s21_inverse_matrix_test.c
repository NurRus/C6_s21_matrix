#include "s21_matrix_test.h"

START_TEST(s21_inverse_matrix_1) {
  matrix_t *matrix_A = NULL, C;

  ck_assert_int_eq(s21_inverse_matrix(matrix_A, &C), 1);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t matrix_A, *C = NULL;
  s21_create_matrix(3, 3, &matrix_A);

  ck_assert_int_eq(s21_inverse_matrix(&matrix_A, C), 1);
  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t matrix_A, C;

  s21_create_matrix(3, 4, &matrix_A);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 1;
  matrix_A.matrix[0][2] = 3;
  matrix_A.matrix[0][3] = 1.25;

  matrix_A.matrix[1][0] = 324;
  matrix_A.matrix[1][1] = 2;
  matrix_A.matrix[1][2] = 323;
  matrix_A.matrix[1][3] = 2.5;

  matrix_A.matrix[2][0] = 1.25;
  matrix_A.matrix[2][1] = 3;
  matrix_A.matrix[2][2] = 3.75;
  matrix_A.matrix[2][3] = 3.75;

  ck_assert_int_eq(s21_inverse_matrix(&matrix_A, &C), 2);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t matrix_A, C, I;

  s21_create_matrix(3, 3, &matrix_A);
  s21_create_matrix(3, 3, &I);

  matrix_A.matrix[0][0] = 2;
  matrix_A.matrix[0][1] = 5;
  matrix_A.matrix[0][2] = 7;

  matrix_A.matrix[1][0] = 6;
  matrix_A.matrix[1][1] = 3;
  matrix_A.matrix[1][2] = 4;

  matrix_A.matrix[2][0] = 5;
  matrix_A.matrix[2][1] = -2;
  matrix_A.matrix[2][2] = -3;

  I.matrix[0][0] = 1;
  I.matrix[0][1] = -1;
  I.matrix[0][2] = 1;

  I.matrix[1][0] = -38;
  I.matrix[1][1] = 41;
  I.matrix[1][2] = -34;

  I.matrix[2][0] = 27;
  I.matrix[2][1] = -29;
  I.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&matrix_A, &C), 0);

  ck_assert_int_eq(s21_eq_matrix(&I, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&I);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  matrix_t matrix_A, B;

  s21_create_matrix(3, 3, &matrix_A);

  matrix_A.matrix[0][0] = 2;
  matrix_A.matrix[0][1] = 5;
  matrix_A.matrix[0][2] = 7;

  matrix_A.matrix[1][0] = 4;
  matrix_A.matrix[1][1] = 10;
  matrix_A.matrix[1][2] = 14;

  matrix_A.matrix[2][0] = 5;
  matrix_A.matrix[2][1] = -2;
  matrix_A.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&matrix_A, &B), 2);
  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  matrix_t matrix_A, C, I;

  s21_create_matrix(1, 1, &matrix_A);
  s21_create_matrix(1, 1, &I);

  matrix_A.matrix[0][0] = 2.46;

  I.matrix[0][0] = 1 / 2.46;

  ck_assert_int_eq(s21_inverse_matrix(&matrix_A, &C), 0);
  ck_assert_int_eq(s21_eq_matrix(&I, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&I);
}
END_TEST

START_TEST(s21_inverse_matrix_7) {
  matrix_t matrix_A, C;

  s21_create_matrix(1, 1, &matrix_A);

  matrix_A.matrix[0][0] = 0;

  ck_assert_int_eq(s21_inverse_matrix(&matrix_A, &C), 2);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_inverse_matrix_8) {
  matrix_t matrix_A, C, I;

  s21_create_matrix(1, 1, &matrix_A);
  s21_create_matrix(1, 1, &I);

  matrix_A.matrix[0][0] = 1;

  I.matrix[0][0] = 1;

  ck_assert_int_eq(s21_inverse_matrix(&matrix_A, &C), 0);
  ck_assert_int_eq(s21_eq_matrix(&I, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&I);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s = suite_create("s21_inverse_matrix_suite");
  TCase *tc = tcase_create("s21_inverse_matrix_testcase");

  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);
  tcase_add_test(tc, s21_inverse_matrix_4);
  tcase_add_test(tc, s21_inverse_matrix_5);
  tcase_add_test(tc, s21_inverse_matrix_6);
  tcase_add_test(tc, s21_inverse_matrix_7);
  tcase_add_test(tc, s21_inverse_matrix_8);

  suite_add_tcase(s, tc);
  return s;
}