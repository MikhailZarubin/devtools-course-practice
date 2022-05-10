// Copyright 2022 Samoiluk Anastasiya

#include <gtest/gtest.h>
#include "include/stack.h"

TEST(Stack, can_create_stack_with_positive_length) {
    ASSERT_NO_THROW(Stack<int> s(5));
}

TEST(Stack, cant_create_stack_with_negative_length) {
    ASSERT_ANY_THROW(Stack<int> s(-5));
}

TEST(Stack, can_create_stack_from_vector) {
    ASSERT_NO_THROW(Stack<int>({ 1, 2, 3 }));
}

TEST(Stack, can_create_copied_stack) {
    Stack<int> s(10);

    ASSERT_NO_THROW(Stack<int> s1(s));
}

TEST(Stack, can_copy_stack_correctly) {
    Stack<double> s(8);
    s.push(4.5);
    s.push(2.7);
    Stack<double> s1(s);

    EXPECT_EQ(s.getLast(), s1.getLast());
}

TEST(Stack, can_push_element) {
    Stack<int> s(4);
    s.push(1);

    EXPECT_EQ(1, s.getLast());
}

TEST(Stack, can_pop_element) {
    Stack<int> s(15);
    s.push(17);
    s.push(23);

    EXPECT_EQ(23, s.pop());
    EXPECT_EQ(17, s.getLast());
}

TEST(Stack, can_get_last) {
    Stack<int> s(6);
    s.push(3);
    s.push(25);

    EXPECT_EQ(25, s.getLast());
}

TEST(Stack, can_get_size) {
    Stack<int> s(48);

    EXPECT_EQ(48, s.getSize());
}

TEST(Stack, throws_when_add_element_to_full_stack) {
    Stack<int> s(2);
    s.push(19);
    s.push(47);

    ASSERT_ANY_THROW(s.push(3));
}

TEST(Stack, throws_when_pop_element_from_empty_stack) {
    Stack<int> s;

    ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_assign_stack_to_itself) {
    Stack<int> s(11);

    ASSERT_NO_THROW(s = s);
}

TEST(Stack, can_assign_stacks_of_equal_size) {
    Stack<int> s(2);
    Stack<int> s1(2);
    s1.push(18);
    s1.push(26);

    ASSERT_NO_THROW(s = s1);
}

TEST(Stack, can_assign_stacks_of_equal_size_correctly) {
    Stack<double> s(3);
    Stack<double> s1(3);
    s.push(1.5);
    s.push(5.5);
    s1 = s;

    EXPECT_DOUBLE_EQ(s.getLast(), s1.getLast());
}

TEST(Stack, can_assign_stacks_of_different_size) {
    Stack<int> s(5);
    Stack<int> s1(7);
    s1.push(1);
    s1.push(2);

    ASSERT_NO_THROW(s = s1);
}

TEST(Stack, can_assign_stacks_of_different_size_correctly) {
    Stack<double> s(5);
    Stack<double> s1(4);
    s.push(0.3);
    s.push(0.8);
    s1 = s;

    EXPECT_DOUBLE_EQ(s.getLast(), s1.getLast());
}

TEST(Stack, can_convert_stack_to_string) {
    Stack<int> s({ 1, 2, 3 });
    ASSERT_NO_THROW(s.convertToString());
}

TEST(Stack, convert_to_string_is_correct) {
    Stack<int> s({ 1, 2, 3 });
    EXPECT_EQ(s.convertToString(), "3 2 1 ");
}
