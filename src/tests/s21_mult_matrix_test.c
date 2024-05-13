#include "s21_matrix_test.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t *A = NULL, B, result;
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(A, &B, &result), 1);
  s21_remove_matrix(&B);
}
END_TEST

/*START_TEST(s21_mult_matrix_2) {

  matrix_t *B = NULL, A, result;
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(A, &B, &result), 1);
  s21_remove_matrix(&B);

}
END_TEST

START_TEST(s21_mult_matrix_3) {

  matrix_t *result = NULL, B, A;
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(A, &B, &result), 1);
  s21_remove_matrix(&B);

}
END_TEST*/

START_TEST(s21_mult_matrix_4) {
  matrix_t A, B, result, etalon;

  s21_create_matrix(5, 3, &A);
  s21_create_matrix(3, 5, &B);
  s21_create_matrix(5, 5, &etalon);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = i;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      B.matrix[i][j] = j;
    }
  }

  etalon.matrix[0][0] = 0;
  etalon.matrix[0][1] = 0;
  etalon.matrix[0][2] = 0;
  etalon.matrix[0][3] = 0;
  etalon.matrix[0][4] = 0;

  etalon.matrix[1][0] = 0;
  etalon.matrix[1][1] = 3;
  etalon.matrix[1][2] = 6;
  etalon.matrix[1][3] = 9;
  etalon.matrix[1][4] = 12;

  etalon.matrix[2][0] = 0;
  etalon.matrix[2][1] = 6;
  etalon.matrix[2][2] = 12;
  etalon.matrix[2][3] = 18;
  etalon.matrix[2][4] = 24;

  etalon.matrix[3][0] = 0;
  etalon.matrix[3][1] = 9;
  etalon.matrix[3][2] = 18;
  etalon.matrix[3][3] = 27;
  etalon.matrix[3][4] = 36;

  etalon.matrix[4][0] = 0;
  etalon.matrix[4][1] = 12;
  etalon.matrix[4][2] = 24;
  etalon.matrix[4][3] = 36;
  etalon.matrix[4][4] = 48;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &etalon), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&etalon);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  matrix_t A, B, result;
  s21_create_matrix(5, 3, &A);
  s21_create_matrix(5, 4, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 2);

  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *s = suite_create("s21_mult_matrix_suite");
  TCase *tc = tcase_create("s21_mult_matrix_testcase");

  tcase_add_test(tc, s21_mult_matrix_1);
  // tcase_add_test(tc, s21_mult_matrix_2);
  // tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, s21_mult_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}