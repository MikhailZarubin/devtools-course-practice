// Copyright 2022 Soldatov Gleb

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Soldatov_Gleb_ComplexNumberTest, Complex_Number_Create_Zero) {
    double re = 0.0;
    double im = 0.0;
    ComplexNumber z(re, im);
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Soldatov_Gleb_ComplexNumberTest, Complex_Number_Addition) {
    double re1 = 7, re2 = 3;
    double im1 = 10, im2 = 7;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber z = c1 + c2;
    EXPECT_DOUBLE_EQ(re1 + re2, z.getRe());
    EXPECT_DOUBLE_EQ(im1 + im2, z.getIm());
}

TEST(Soldatov_Gleb_ComplexNumberTest, Complex_Number_Subtraction) {
    double re1 = 7, re2 = 3;
    double im1 = 10, im2 = 7;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber z = c1 - c2;
    EXPECT_DOUBLE_EQ(re1 - re2, z.getRe());
    EXPECT_DOUBLE_EQ(im1 - im2, z.getIm());
}

TEST(Soldatov_Gleb_ComplexNumberTest, Complex_Number_Multiply) {
    double re1 = 7, re2 = 3;
    double im1 = 10, im2 = 7;
    ComplexNumber c1(re1, im1);
    ComplexNumber c2(re2, im2);
    ComplexNumber z = c1 * c2;
    EXPECT_DOUBLE_EQ(re1 * re2 - im1 * im2, z.getRe());
    EXPECT_DOUBLE_EQ(re1 * im2 + im1 * re2, z.getIm());
}

TEST(Soldatov_Gleb_ComplexNumberTest, Complex_Number_Copy) {
    double re = 7;
    double im = 10;
    ComplexNumber c1(7, 10);
    ComplexNumber z(c1);
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}
