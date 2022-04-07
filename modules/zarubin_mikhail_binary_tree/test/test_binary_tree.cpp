// Copyright 2022 Zarubin Mikhail

#include <gtest/gtest.h>
#include <vector>

#include "include/binary_tree.h"

using std::vector;


TEST(Zarubin_Mikhail_Binary_Tree, can_create_tree) {
    ASSERT_NO_THROW(BinaryTree());
}

TEST(Zarubin_Mikhail_Binary_Tree, can_find_value_in_tree) {
    BinaryTree tree;
    ASSERT_NO_THROW(tree.findByValue(5));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_insert_value_in_empty_tree) {
    BinaryTree tree;
    ASSERT_NO_THROW(tree.insertByValue(5));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_insert_value_in_no_empty_tree) {
    BinaryTree tree;
    tree.insertByValue(5);
    ASSERT_NO_THROW(tree.insertByValue(10));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_transportate_vector_to_tree) {
    vector<int> data = { 1, 5, 4, -3, 7, -4 };
    ASSERT_NO_THROW(BinaryTree(data));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_delete_value_in_empty_tree) {
    BinaryTree tree;
    ASSERT_NO_THROW(tree.deleteByValue(10));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_delete_value_in_no_empty_tree) {
    BinaryTree tree;
    tree.insertByValue(5);
    ASSERT_NO_THROW(tree.deleteByValue(10));
}

TEST(Zarubin_Mikhail_Binary_Tree, search_an_existing_value_is_correct) {
    BinaryTree tree;
    tree.insertByValue(5);
    ASSERT_TRUE(tree.findByValue(5));
}

TEST(Zarubin_Mikhail_Binary_Tree, search_a_non_existent_value_is_correct) {
    BinaryTree tree;
    ASSERT_FALSE(tree.findByValue(5));
}

TEST(Zarubin_Mikhail_Binary_Tree, get_size_tree_is_correct) {
    BinaryTree tree;
    ASSERT_NO_THROW(tree.getSize());
}

TEST(Zarubin_Mikhail_Binary_Tree,
    insert_a_non_existent_value_changes_size_tree) {
    BinaryTree tree;

    auto startSize = tree.getSize();
    tree.insertByValue(5);
    auto finishSize = tree.getSize();

    EXPECT_EQ(startSize, finishSize - 1);
}

TEST(Zarubin_Mikhail_Binary_Tree,
    insert_an_existing_value_no_changes_size_tree) {
    BinaryTree tree;
    tree.insertByValue(5);

    auto startSize = tree.getSize();
    tree.insertByValue(5);
    auto finishSize = tree.getSize();

    EXPECT_EQ(startSize, finishSize);
}

TEST(Zarubin_Mikhail_Binary_Tree,
    delete_a_non_existent_value_no_changes_size_tree) {
    BinaryTree tree;

    auto startSize = tree.getSize();
    tree.deleteByValue(5);
    auto finishSize = tree.getSize();

    EXPECT_EQ(startSize, finishSize);
}

TEST(Zarubin_Mikhail_Binary_Tree, delete_an_existing_value_changes_size_tree) {
    BinaryTree tree;
    tree.insertByValue(5);

    auto startSize = tree.getSize();
    tree.insertByValue(5);
    auto finishSize = tree.getSize();

    EXPECT_EQ(startSize, finishSize);
}

TEST(Zarubin_Mikhail_Binary_Tree, can_delete_a_vertex_without_descendants) {
    BinaryTree tree({ 1, 5, 4, -3, 7, -4 });
    ASSERT_NO_THROW(tree.deleteByValue(7));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_delete_a_vertex_with_left_descendants) {
    BinaryTree tree({ 1, 5, 4, -3, 7, -4 });
    ASSERT_NO_THROW(tree.deleteByValue(-3));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_delete_a_vertex_with_right_descendants) {
    BinaryTree tree({ 1, 5, 4, -3, 7, -2 });
    ASSERT_NO_THROW(tree.deleteByValue(-3));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_delete_a_vertex_with_two_descendants) {
    BinaryTree tree({ 1, 5, 4, -3, 7, -2 });
    ASSERT_NO_THROW(tree.deleteByValue(5));
}

TEST(Zarubin_Mikhail_Binary_Tree, can_delete_a_root) {
    BinaryTree tree({ 1, 5, 4, -3, 7, -2 });
    ASSERT_NO_THROW(tree.deleteByValue(1));
}
