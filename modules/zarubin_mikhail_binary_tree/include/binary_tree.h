// Copyright 2022 Zarubin Mikhail

#ifndef MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_H_
#define MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_H_

#include <vector>

using Type = int;


class BinaryTree {
    struct Vertex {
        Type value;
        Vertex* leftEdge, * rightEdge;

        Vertex(const Type& _value = Type(),
            Vertex* _leftEdge = nullptr, Vertex* _rightEdge = nullptr);
        void replaceValue(const Type& newValue);
        void replaceVertex(Vertex* value);
    };

    enum class Direction {
        LEFT,
        RIGHT
    };

    struct SearchState {
        Vertex* previousVertex, * currentVertex;
        Direction lastStep;

        SearchState(Vertex* _previousVertex = nullptr,
            Vertex* _currentVertex = nullptr,
            Direction _lastStep = Direction::LEFT);
        void reset(Vertex* _previousVertex = nullptr,
            Vertex* _currentVertex = nullptr);
        void goToLeft();
        void goToRight();
        void replaceLink(Vertex* vertex);
    };

    Vertex* root;
    SearchState searchState;
    std::size_t treeSize;

    void insertByState(const Type& value);
    void deleteByState(const Type& value);

 public:
    BinaryTree();
    explicit BinaryTree(const std::vector<Type>& data);

    bool findByValue(const Type& value);
    void deleteByValue(const Type& value);
    void insertByValue(const Type& value);

    std::size_t getSize() const;
};

#endif  // MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_H_
