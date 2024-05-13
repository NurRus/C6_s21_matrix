#include "s21_matrix_test.h"

START_TEST(s21_determinant_1) {
  matrix_t *matrix_A = NULL;
  double determinant = 0;

  ck_assert_int_eq(s21_determinant(matrix_A, &determinant), 1);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(3, 4, &matrix_A);

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 2);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(4, 4, &matrix_A);

  matrix_A.matrix[0][0] = 1.25;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 3;
  matrix_A.matrix[0][3] = 44.98;

  matrix_A.matrix[1][0] = 5;
  matrix_A.matrix[1][1] = 6;
  matrix_A.matrix[1][2] = 7;
  matrix_A.matrix[1][3] = 8;

  matrix_A.matrix[2][0] = 9;
  matrix_A.matrix[2][1] = 10;
  matrix_A.matrix[2][2] = 11;
  matrix_A.matrix[2][3] = 12;

  matrix_A.matrix[3][0] = 13;
  matrix_A.matrix[3][1] = 14;
  matrix_A.matrix[3][2] = 15;
  matrix_A.matrix[3][3] = 16.59;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);
  ck_assert_float_eq(determinant, -0.59);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(3, 3, &matrix_A);

  matrix_A.matrix[0][0] = 0;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 5.26;

  matrix_A.matrix[1][0] = 4;
  matrix_A.matrix[1][1] = 1;
  matrix_A.matrix[1][2] = 8;

  matrix_A.matrix[2][0] = 4;
  matrix_A.matrix[2][1] = 5;
  matrix_A.matrix[2][2] = -0.45;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);

  ck_assert_float_eq(determinant, 151.76);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(4, 4, &matrix_A);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 3;
  matrix_A.matrix[0][3] = 4;

  matrix_A.matrix[1][0] = 5;
  matrix_A.matrix[1][1] = 6;
  matrix_A.matrix[1][2] = 7;
  matrix_A.matrix[1][3] = 8;

  matrix_A.matrix[2][0] = 9;
  matrix_A.matrix[2][1] = 10;
  matrix_A.matrix[2][2] = 11;
  matrix_A.matrix[2][3] = 12;

  matrix_A.matrix[3][0] = 13;
  matrix_A.matrix[3][1] = 14;
  matrix_A.matrix[3][2] = 15;
  matrix_A.matrix[3][3] = 16;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);

  ck_assert_float_eq(determinant, 0);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(4, 4, &matrix_A);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 3;
  matrix_A.matrix[0][3] = 4;

  matrix_A.matrix[1][0] = 0;
  matrix_A.matrix[1][1] = 0;
  matrix_A.matrix[1][2] = 0;
  matrix_A.matrix[1][3] = 0;

  matrix_A.matrix[2][0] = 45;
  matrix_A.matrix[2][1] = 122;
  matrix_A.matrix[2][2] = 15;
  matrix_A.matrix[2][3] = 1212;

  matrix_A.matrix[3][0] = -13;
  matrix_A.matrix[3][1] = 514;
  matrix_A.matrix[3][2] = 15.443;
  matrix_A.matrix[3][3] = 16.08;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);

  ck_assert_float_eq(determinant, 0);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(4, 4, &matrix_A);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 0;
  matrix_A.matrix[0][2] = 3;
  matrix_A.matrix[0][3] = 4;

  matrix_A.matrix[1][0] = 324;
  matrix_A.matrix[1][1] = 0;
  matrix_A.matrix[1][2] = 323;
  matrix_A.matrix[1][3] = 89.544;

  matrix_A.matrix[2][0] = 45;
  matrix_A.matrix[2][1] = 0;
  matrix_A.matrix[2][2] = 15;
  matrix_A.matrix[2][3] = 1212;

  matrix_A.matrix[3][0] = -13;
  matrix_A.matrix[3][1] = 0;
  matrix_A.matrix[3][2] = 15.443;
  matrix_A.matrix[3][3] = 16.08;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);

  ck_assert_float_eq(determinant, 0);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_8) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(4, 4, &matrix_A);

  matrix_A.matrix[0][0] = 1;
  matrix_A.matrix[0][1] = 2;
  matrix_A.matrix[0][2] = 3;
  matrix_A.matrix[0][3] = 4;

  matrix_A.matrix[1][0] = 324;
  matrix_A.matrix[1][1] = 321.32;
  matrix_A.matrix[1][2] = 323;
  matrix_A.matrix[1][3] = 89.544;

  matrix_A.matrix[2][0] = 1.25;
  matrix_A.matrix[2][1] = 2.5;
  matrix_A.matrix[2][2] = 3.75;
  matrix_A.matrix[2][3] = 5;

  matrix_A.matrix[3][0] = -13;
  matrix_A.matrix[3][1] = 654;
  matrix_A.matrix[3][2] = 15.443;
  matrix_A.matrix[3][3] = 16.08;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);

  ck_assert_float_eq(determinant, 0);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_9) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(4, 4, &matrix_A);

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

  matrix_A.matrix[3][0] = -13;
  matrix_A.matrix[3][1] = 4;
  matrix_A.matrix[3][2] = 15.443;
  matrix_A.matrix[3][3] = 5;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);

  ck_assert_float_eq(determinant, 0);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_10) {
  matrix_t matrix_A;
  double determinant = 0;

  s21_create_matrix(1, 1, &matrix_A);

  matrix_A.matrix[0][0] = -11.53;

  ck_assert_int_eq(s21_determinant(&matrix_A, &determinant), 0);

  ck_assert_float_eq(determinant, -11.53);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(s21_determinant_11) {
  matrix_t A;
  double determinant = 0;

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  ck_assert_int_eq(s21_determinant(&A, &determinant), 0);

  ck_assert_float_eq(determinant, -69);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_12) {
  matrix_t A;
  double B, R = -69.0 / 4.0;
  s21_create_matrix(5, 5, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[0][3] = 3.25;
  A.matrix[0][4] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[1][3] = 5.25;
  A.matrix[1][4] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  A.matrix[2][3] = 6.25;
  A.matrix[2][4] = 6.25;
  A.matrix[3][0] = 6.25;
  A.matrix[3][1] = 7.25;
  A.matrix[3][2] = 8.25;
  A.matrix[3][3] = 6.25;
  A.matrix[3][4] = 7.25;
  A.matrix[4][0] = 6.25;
  A.matrix[4][1] = 7.25;
  A.matrix[4][2] = 8.25;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8.25;

  ck_assert_int_eq(s21_determinant(&A, &B), 0);

  ck_assert_float_eq(B, R);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_13) {
  matrix_t A;
  double B;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 13;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 16;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 90;
  A.matrix[2][3] = 19;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 7;
  A.matrix[3][3] = 17;

  ck_assert_int_eq(s21_determinant(&A, &B), 0);

  ck_assert_float_eq(B, 13608);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_14) {
  matrix_t A;
  double B;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  ck_assert_int_eq(s21_determinant(&A, &B), 0);

  ck_assert_float_eq(B, -60);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_15) {
  matrix_t A;
  double B;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = -3;
  A.matrix[2][1] = -6;
  A.matrix[2][2] = -12;

  ck_assert_int_eq(s21_determinant(&A, &B), 0);

  ck_assert_float_eq(B, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_16) {
  matrix_t A;
  double B;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = 7;

  A.matrix[1][0] = -2;
  A.matrix[1][1] = -3;

  ck_assert_int_eq(s21_determinant(&A, &B), 0);

  ck_assert_float_eq(B, -1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_17) {
  matrix_t A;
  double B;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  ck_assert_int_eq(s21_determinant(&A, &B), 0);

  ck_assert_float_eq(B, -1);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s = suite_create("s21_determinant_suite");
  TCase *tc = tcase_create("s21_determinant_testcase");

  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);
  tcase_add_test(tc, s21_determinant_10);
  tcase_add_test(tc, s21_determinant_11);
  tcase_add_test(tc, s21_determinant_12);
  tcase_add_test(tc, s21_determinant_13);
  tcase_add_test(tc, s21_determinant_14);
  tcase_add_test(tc, s21_determinant_15);
  tcase_add_test(tc, s21_determinant_16);
  tcase_add_test(tc, s21_determinant_17);

  suite_add_tcase(s, tc);
  return s;
}