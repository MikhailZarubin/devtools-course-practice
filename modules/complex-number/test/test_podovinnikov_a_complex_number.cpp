// Copyright 2022 Podovinnikov Artyom

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Podovinnikov_Artyom_ComplexNumberTest, sets_values) {
  double re1 = 5.4, im1 = 5.5;
  ComplexNumber a;

  a.setRe(re1);
  a.setIm(im1);

  EXPECT_DOUBLE_EQ(re1, a.getRe());
  EXPECT_DOUBLE_EQ(im1, a.getIm());
}

TEST(Podovinnikov_Artyom_ComplexNumberTest, copy) {
  double re1 = 5.4, im1 = 5.5;
  ComplexNumber a(re1, im1);
  ComplexNumber b(a);

  EXPECT_TRUE(a == b);
}

TEST(Podovinnikov_Artyom_ComplexNumberTest, Equality) {
  ComplexNumber a(11.0, 4.0);
  ComplexNumber b(11.0, 4.0);

  ASSERT_TRUE(a == b);
}

TEST(Podovinnikov_Artyom_ComplexNumberTest, NotEquality) {
  ComplexNumber a(11.0, 4.0);
  ComplexNumber b(11.0, -4.0);

  ASSERT_TRUE(a != b);
}

TEST(Podovinnikov_Artyom_ComplexNumberTest, CanOpPlus) {
  double re1 = 7.0, im1 = 2.0, re2 = 3.0, im2 = 1.0;
  ComplexNumber a(re1, im1);
  ComplexNumber b(re2, im2);

  ComplexNumber sum = a + b;

  EXPECT_DOUBLE_EQ(10.0, sum.getRe());
  EXPECT_DOUBLE_EQ(3.0, sum.getIm());
}

TEST(Podovinnikov_Artyom_ComplexNumberTest, CanOpSub) {
  double re1 = 5.4, im1 = 5.5, re2 = 0.4, im2 = 0.5;

  ComplexNumber a(re1, im1);
  ComplexNumber b(re2, im2);

  ComplexNumber sub = a - b;

  EXPECT_EQ(re1 - re2, sub.getRe());
  EXPECT_EQ(im1 - im2, sub.getIm());
}

TEST(Podovinnikov_Artyom_ComplexNumberTest, CanOpMult) {
  double re1 = 5.4, im1 = 5.5, re2 = 0.4, im2 = 0.5;

  ComplexNumber a(re1, im1);
  ComplexNumber b(re2, im2);

  ComplexNumber multiplies = a * b;

  EXPECT_EQ(re1 * re2 - im1 * im2, multiplies.getRe());
  EXPECT_EQ(re1 * im2 + im1 * re2, multiplies.getIm());
}

TEST(Podovinnikov_Artyom_ComplexNumberTest, CanOpDiv) {
  double re1 = 4.3, im1 = 4.3, re2 = 3.0, im2 = 2.0;

  ComplexNumber a(re1, im1);
  ComplexNumber b(re2, im2);

  ComplexNumber division = a / b;

  double d = 1.0 / (re2 * re2 + im2 * im2);
  double num1 = re1 * re2 + im1 * im2;
  double num2 = im1 * re2 - re1 * im2;

  EXPECT_DOUBLE_EQ(num1 * d, division.getRe());
  EXPECT_DOUBLE_EQ(num2 * d, division.getIm());
}
