// Copyright 2.002.02.0 Zarubin Mikhail

#include "../include/complex_number.h"

#include <gtest/gtest.h>

const double ERROR = 0.001;


TEST(ZarubinMikhail_ComplexNumberTesting, can_create_object_complex_number_with_default_constructor) {
	ASSERT_NO_THROW(ComplexNumber());
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_create_object_complex_number_constructor_with_parameters) {
	ASSERT_NO_THROW(ComplexNumber(1.0, 1.0));
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_get_realPart_complex_number) {
	ComplexNumber obj;
	ASSERT_NO_THROW(obj.getRe());
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_get_imaginaryPart_complex_number) {
	ComplexNumber obj;
	ASSERT_NO_THROW(obj.getIm());
}

TEST(ZarubinMikhail_ComplexNumberTesting, get_realPart_is_correct) {
    double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj(realPart, imaginaryPart);
	ASSERT_NEAR(obj.getRe(), realPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, get_imaginaryPart_is_correct) {
	double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj(realPart, imaginaryPart);
	ASSERT_NEAR(obj.getIm(), imaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_set_realPart_complex_number) {
	ComplexNumber obj;
	ASSERT_NO_THROW(obj.setRe(1.0));
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_set_imaginaryPart_complex_number) {
	ComplexNumber obj;
	ASSERT_NO_THROW(obj.setIm(2.0));
}

TEST(ZarubinMikhail_ComplexNumberTesting, set_realPart_is_correct) {
	double realPart = 1.0;

	ComplexNumber obj;
	obj.setRe(realPart);
	ASSERT_NEAR(obj.getRe(), realPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, set_imaginaryPart_is_correct) {
	double imaginaryPart = 2.0;

	ComplexNumber obj;
	obj.setIm(imaginaryPart);
	ASSERT_NEAR(obj.getIm(), imaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_assign_two_complex_number) {
	ComplexNumber obj1, obj2;
	ASSERT_NO_THROW(obj1 = obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, assign_two_complex_number_is_correct) {
	double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj1, obj2(realPart, imaginaryPart);
	obj1 = obj2;

	ASSERT_NEAR(obj1.getRe(), realPart, ERROR);
	ASSERT_NEAR(obj1.getIm(), imaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_assign_three_complex_number) {
	ComplexNumber obj1, obj2, obj3;
	ASSERT_NO_THROW(obj1 = obj2 = obj3);
}

TEST(ZarubinMikhail_ComplexNumberTesting, assign_three_complex_number_is_correct) {
	double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj1, obj2, obj3(realPart, imaginaryPart);
	obj1 = obj2 = obj3;

	ASSERT_NEAR(obj1.getRe(), realPart, ERROR);
	ASSERT_NEAR(obj1.getIm(), imaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_addit_two_complex_number) {
	ComplexNumber obj1, obj2;
	ASSERT_NO_THROW(obj1 + obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, addition_two_complex_number_is_correct) {
	double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj1(realPart, imaginaryPart), obj2(realPart, imaginaryPart);
	auto sum = obj1 + obj2;

	double expectedRealPart = 2.0;
	double expectedImaginaryPart = 4.0;

	ASSERT_NEAR(sum.getRe(), expectedRealPart, ERROR);
	ASSERT_NEAR(sum.getIm(), expectedImaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_subtract_two_complex_number) {
	ComplexNumber obj1, obj2;
	ASSERT_NO_THROW(obj1 - obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, subtraction_two_complex_number_is_correct) {
	double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj1(realPart, imaginaryPart), obj2(realPart, imaginaryPart);
	auto diff = obj1 - obj2;

	double expectedRealPart = 0.0;
	double expectedImaginaryPart = 0.0;

	ASSERT_NEAR(diff.getRe(), expectedRealPart, ERROR);
	ASSERT_NEAR(diff.getIm(), expectedImaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_multiply_two_complex_number) {
	ComplexNumber obj1, obj2;
	ASSERT_NO_THROW(obj1 * obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, multiplication_two_complex_number_is_correct) {
	double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj1(realPart, imaginaryPart), obj2(realPart, imaginaryPart);
	auto multRes = obj1 * obj2;

	double expectedRealPart = -3.0;
	double expectedImaginaryPart = 4.0;

	ASSERT_NEAR(multRes.getRe(), expectedRealPart, ERROR);
	ASSERT_NEAR(multRes.getIm(), expectedImaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_divide_by_unzero_complex_number) {
	ComplexNumber obj1, obj2(1.0, 1.0);
	ASSERT_NO_THROW(obj1 / obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_not_divide_by_zero_complex_number) {
	ComplexNumber obj1, obj2;
	ASSERT_ANY_THROW(obj1 / obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, division_two_complex_number_is_correct) {
	double realPart = 1.0;
	double imaginaryPart = 2.0;

	ComplexNumber obj1(realPart, imaginaryPart), obj2(realPart, imaginaryPart);
	auto divRes = obj1 / obj2;

	double expectedRealPart = 1.0;
	double expectedImaginaryPart = 0.0;

	ASSERT_NEAR(divRes.getRe(), expectedRealPart, ERROR);
	ASSERT_NEAR(divRes.getIm(), expectedImaginaryPart, ERROR);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_check_for_equality_two_complex_number) {
	ComplexNumber obj1, obj2;
	ASSERT_NO_THROW(obj1 == obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, check_for_equality_two_complex_number_is_correct) {
	ComplexNumber obj1, obj2;
	ASSERT_TRUE(obj1 == obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, can_check_for_inequality_two_complex_number) {
	ComplexNumber obj1, obj2;
	ASSERT_NO_THROW(obj1 != obj2);
}

TEST(ZarubinMikhail_ComplexNumberTesting, check_for_inequality_two_complex_number_is_correct) {
	ComplexNumber obj1, obj2(1.0, 2.0);
	ASSERT_TRUE(obj1 != obj2);
}
