#include "s21_matrix_test.h"

START_TEST(s21_calc_complements_1) {
  matrix_t *matrix_A = NULL, C;

  ck_assert_int_eq(s21_calc_complements(matrix_A, &C), 1);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t matrix_A, *C = NULL;
  s21_create_matrix(3, 3, &matrix_A);

  ck_assert_int_eq(s21_calc_complements(&matrix_A, C), 1);
  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t matrix_A, C;

  s21_create_matrix(3, 4, &matrix_A);

  ck_assert_int_eq(s21_calc_complements(&matrix_A, &C), 2);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t matrix_A, C, M;

  s21_create_matrix(3, 3, &matrix_A);
  s21_create_matrix(3, 3, &M);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 3;

  matrix_A.matrix[1][0] = 0;
  matrix_A.matrix[1][1] = 4;
  matrix_A.matrix[1][2] = 2;

  matrix_A.matrix[2][0] = 5;
  matrix_A.matrix[2][1] = 2;
  matrix_A.matrix[2][2] = 1;

  M.matrix[0][0] = 0;
  M.matrix[0][1] = 10;
  M.matrix[0][2] = -20;

  M.matrix[1][0] = 4;
  M.matrix[1][1] = -14;
  M.matrix[1][2] = 8;

  M.matrix[2][0] = -8;
  M.matrix[2][1] = -2;
  M.matrix[2][2] = 4;

  ck_assert_int_eq(s21_calc_complements(&matrix_A, &C), 0);
  ck_assert_int_eq(s21_eq_matrix(&M, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t matrix_A, C, M;

  s21_create_matrix(3, 3, &matrix_A);
  s21_create_matrix(3, 3, &M);

  matrix_A.matrix[0][0] = 5;
  matrix_A.matrix[0][1] = -1;
  matrix_A.matrix[0][2] = 1;

  matrix_A.matrix[1][0] = 2;
  matrix_A.matrix[1][1] = 3;
  matrix_A.matrix[1][2] = 4;

  matrix_A.matrix[2][0] = 1;
  matrix_A.matrix[2][1] = 0;
  matrix_A.matrix[2][2] = 3;

  M.matrix[0][0] = 9;
  M.matrix[0][1] = -2;
  M.matrix[0][2] = -3;

  M.matrix[1][0] = 3;
  M.matrix[1][1] = 14;
  M.matrix[1][2] = -1;

  M.matrix[2][0] = -7;
  M.matrix[2][1] = -18;
  M.matrix[2][2] = 17;

  ck_assert_int_eq(s21_calc_complements(&matrix_A, &C), 0);
  ck_assert_int_eq(s21_eq_matrix(&M, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_6) {
  matrix_t matrix_A, C, M;

  s21_create_matrix(4, 4, &matrix_A);
  s21_create_matrix(4, 4, &M);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 3;
  matrix_A.matrix[0][3] = 4;

  matrix_A.matrix[1][0] = 0;
  matrix_A.matrix[1][1] = 4;
  matrix_A.matrix[1][2] = 2;
  matrix_A.matrix[1][3] = 2;

  matrix_A.matrix[2][0] = 5;
  matrix_A.matrix[2][1] = 2;
  matrix_A.matrix[2][2] = 1;
  matrix_A.matrix[2][3] = 1;

  matrix_A.matrix[3][0] = 5;
  matrix_A.matrix[3][1] = 2;
  matrix_A.matrix[3][2] = 1;
  matrix_A.matrix[3][3] = 1;

  M.matrix[0][0] = 0;
  M.matrix[0][1] = 0;
  M.matrix[0][2] = 0;
  M.matrix[0][3] = 0;

  M.matrix[1][0] = 0;
  M.matrix[1][1] = 0;
  M.matrix[1][2] = 0;
  M.matrix[1][3] = 0;

  M.matrix[2][0] = 0;
  M.matrix[2][1] = 10;
  M.matrix[2][2] = -60;
  M.matrix[2][3] = 40;

  M.matrix[3][0] = 0;
  M.matrix[3][1] = -10;
  M.matrix[3][2] = 60;
  M.matrix[3][3] = -40;

  ck_assert_int_eq(s21_calc_complements(&matrix_A, &C), 0);

  ck_assert_int_eq(s21_eq_matrix(&M, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_7) {
  matrix_t matrix_A, C, M;

  s21_create_matrix(1, 1, &matrix_A);
  s21_create_matrix(1, 1, &M);

  matrix_A.matrix[0][0] = 5;

  M.matrix[0][0] = 1;

  ck_assert_int_eq(s21_calc_complements(&matrix_A, &C), 0);
  ck_assert_int_eq(s21_eq_matrix(&M, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_8) {
  matrix_t matrix_A, C, M;

  s21_create_matrix(3, 3, &matrix_A);
  s21_create_matrix(3, 3, &M);

  matrix_A.matrix[0][0] = 2;
  matrix_A.matrix[0][1] = 5;
  matrix_A.matrix[0][2] = 7;

  matrix_A.matrix[1][0] = 6;
  matrix_A.matrix[1][1] = 3;
  matrix_A.matrix[1][2] = 4;

  matrix_A.matrix[2][0] = 5;
  matrix_A.matrix[2][1] = -2;
  matrix_A.matrix[2][2] = -3;

  M.matrix[0][0] = -1;
  M.matrix[0][1] = 38;
  M.matrix[0][2] = -27;

  M.matrix[1][0] = 1;
  M.matrix[1][1] = -41;
  M.matrix[1][2] = 29;

  M.matrix[2][0] = -1;
  M.matrix[2][1] = 34;
  M.matrix[2][2] = -24;

  ck_assert_int_eq(s21_calc_complements(&matrix_A, &C), 0);

  ck_assert_int_eq(s21_eq_matrix(&M, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_calc_complements_9) {
  matrix_t matrix_A, C, M;

  s21_create_matrix(1, 1, &matrix_A);
  s21_create_matrix(1, 1, &M);

  matrix_A.matrix[0][0] = 0;

  M.matrix[0][0] = 1;

  ck_assert_int_eq(s21_calc_complements(&matrix_A, &C), 0);
  ck_assert_int_eq(s21_eq_matrix(&M, &C), SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&M);
  s21_remove_matrix(&C);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s = suite_create("s21_calc_complements_suite");
  TCase *tc = tcase_create("s21_calc_complements_testcase");

  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);
  tcase_add_test(tc, s21_calc_complements_4);
  tcase_add_test(tc, s21_calc_complements_5);
  tcase_add_test(tc, s21_calc_complements_6);
  tcase_add_test(tc, s21_calc_complements_7);
  tcase_add_test(tc, s21_calc_complements_8);
  tcase_add_test(tc, s21_calc_complements_9);

  suite_add_tcase(s, tc);
  return s;
}