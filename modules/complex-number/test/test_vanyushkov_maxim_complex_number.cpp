// Copyright 2022 Vanyushkov Maxim

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Init) {
    ASSERT_NO_THROW(ComplexNumber z);
}

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Init_With_Values) {
    ASSERT_NO_THROW(ComplexNumber z(1.5, 2.75));
}

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Get_Complex_Number) {
    double re = 1.5, im = 2.75;

    ComplexNumber z(re, im);

    ASSERT_NO_THROW(z.getRe());
    ASSERT_NO_THROW(z.getIm());
}

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Get_Complex_Number_Currect) {
    double re = 1.5, im = 2.75;

    ComplexNumber z(re, im);

    ASSERT_DOUBLE_EQ(re, z.getRe());
    ASSERT_DOUBLE_EQ(im, z.getIm());
}

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Copy) {
    double re = 1.5, im = 2.75;

    ComplexNumber z(re, im);

    ASSERT_NO_THROW(ComplexNumber z1(z));
}

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Copy_Correct) {
    double re = 1.5, im = 2.75;

    ComplexNumber z(re, im);
    ComplexNumber z1(z);

    ASSERT_DOUBLE_EQ(z1.getRe(), z.getRe());
    ASSERT_DOUBLE_EQ(z1.getIm(), z.getIm());
}

TEST(Vanyushkov_Maxim_ComplexNumberTest,
    Can_Copy_With_Assignment_Operator_Correct) {
    double re = 1.5, im = 2.75;

    ComplexNumber z(re, im);
    ComplexNumber z1 = z;

    ASSERT_DOUBLE_EQ(z1.getRe(), z.getRe());
    ASSERT_DOUBLE_EQ(z1.getIm(), z.getIm());
}

TEST(Vanyushkov_Maxim_ComplexNumberTest,
    Correct_Comparison_Of_Equal_Numbers) {
    double re1 = 1.5;
    double im1 = 2.75;
    double re2 = 1.5;
    double im2 = 2.75;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ASSERT_TRUE(z1 == z2);
}

TEST(Vanyushkov_Maxim_ComplexNumberTest,
    Correct_Comparison_Of_Not_Equal_Numbers) {
    double re1 = 1.5;
    double im1 = 2.75;
    double re2 = 2.75;
    double im2 = 1.5;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ASSERT_TRUE(z1 != z2);
}

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Add_Complex_Numbers) {
    double re1 = 1.5;
    double im1 = 2.75;
    double re2 = 1.5;
    double im2 = 3.25;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber sum;
    sum = z1 + z2;

    ASSERT_DOUBLE_EQ(re1 + re2, sum.getRe());
    ASSERT_DOUBLE_EQ(im1 + im2, sum.getIm());
}

TEST(Vanyushkov_Maxim_ComplexNumberTest,
    Can_Find_The_Difference_Of_Complex_Numbers) {
    double re1 = 1.5;
    double im1 = 2.75;
    double re2 = 1.5;
    double im2 = 3.25;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber difference;
    difference = z1 - z2;

    ASSERT_DOUBLE_EQ(re1 - re2, difference.getRe());
    ASSERT_DOUBLE_EQ(im1 - im2, difference.getIm());
}

TEST(Vanyushkov_Maxim_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    double re1 = 1.5;
    double im1 = 2.75;
    double re2 = 1.5;
    double im2 = 3.25;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber multiplication;
    multiplication = z1 * z2;

    ASSERT_DOUBLE_EQ(re1 * re2 - im1 * im2, multiplication.getRe());
    ASSERT_DOUBLE_EQ(re1 * im2 + im1 * re2, multiplication.getIm());
}

TEST(Vanyushkov_Maxim_ComplexNumberTest,
    Cant_Division_Complex_Numbers_With_Zero) {
    double re1 = 1.5;
    double im1 = 2.75;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2;
    ASSERT_ANY_THROW(z1 / z2);
}
