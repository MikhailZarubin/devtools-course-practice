// Copyright 2022 Zarubin Mikhail

#ifndef MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_H_
#define MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_H_

#include <vector>


template <class Type>
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


template <class Type>
BinaryTree<Type>::Vertex::Vertex(const Type& _value,
    Vertex* _leftEdge, Vertex* _rightEdge) :
    value(_value),
    leftEdge(_leftEdge),
    rightEdge(_rightEdge) {
}

template <class Type>
void BinaryTree<Type>::Vertex::replaceValue(const Type& newValue) {
    value = newValue;
}

template <class Type>
void BinaryTree<Type>::Vertex::replaceVertex(Vertex* vertex) {
    value = vertex->value;
    leftEdge = vertex->leftEdge;
    rightEdge = vertex->rightEdge;
}

template <class Type>
BinaryTree<Type>::SearchState::SearchState(Vertex* _previousVertex,
    Vertex* _currentVertex, Direction _lastStep) :
    previousVertex(_previousVertex),
    currentVertex(_currentVertex),
    lastStep(_lastStep) {
}

template <class Type>
void BinaryTree<Type>::SearchState::reset(Vertex* _previousVertex,
    Vertex* _currentVertex) {
    previousVertex = _previousVertex;
    currentVertex = _currentVertex;
    lastStep = Direction::LEFT;
}

template <class Type>
void BinaryTree<Type>::SearchState::goToLeft() {
    lastStep = Direction::LEFT;
    previousVertex = currentVertex;
    currentVertex = currentVertex->leftEdge;
}

template <class Type>
void BinaryTree<Type>::SearchState::goToRight() {
    lastStep = Direction::RIGHT;
    previousVertex = currentVertex;
    currentVertex = currentVertex->rightEdge;
}

template <class Type>
void BinaryTree<Type>::SearchState::replaceLink(Vertex* vertex) {
    switch (lastStep) {
    case(Direction::LEFT):
        previousVertex->leftEdge = currentVertex;
        break;
    case(Direction::RIGHT):
        previousVertex->rightEdge = currentVertex;
        break;
    default:
        break;
    }
}

template <class Type>
BinaryTree<Type>::BinaryTree() :
    root(nullptr),
    searchState(),
    treeSize(0) {
}

template <class Type>
BinaryTree<Type>::BinaryTree(const std::vector<Type>& data) : BinaryTree() {
    for (const auto& value : data) {
        insertByValue(value);
    }
}

template <class Type>
bool BinaryTree<Type>::findByValue(const Type& value) {
    searchState.reset(nullptr, root);

    while (searchState.currentVertex != nullptr) {
        auto currentValue = searchState.currentVertex->value;

        if (value < currentValue) {
            searchState.goToLeft();
        } else {
            if (value > currentValue) {
                searchState.goToRight();
            } else {
                return true;
            }
        }
    }

    return false;
}

template <class Type>
void BinaryTree<Type>::insertByState(const Type& value) {
    treeSize++;
    searchState.replaceLink(new Vertex(value));
}

template <class Type>
void BinaryTree<Type>::insertByValue(const Type& value) {
    if (root == nullptr) {
        root = new Vertex(value);
        treeSize++;
        return;
    }

    bool success = findByValue(value);
    if (!success) {
        insertByState(value);
    }
}

template <class Type>
void BinaryTree<Type>::deleteByState(const Type& value) {
    bool rootFlag = searchState.currentVertex == root;
    treeSize--;

    if (searchState.currentVertex->leftEdge == nullptr
        && searchState.currentVertex->rightEdge == nullptr) {
        delete searchState.currentVertex;
        searchState.currentVertex = nullptr;
    } else {
        if (searchState.currentVertex->leftEdge == nullptr 
            && searchState.currentVertex->rightEdge != nullptr) {
            auto deletedVertex = searchState.currentVertex->rightEdge;
            searchState.currentVertex->replaceVertex(searchState.currentVertex->rightEdge);
            delete deletedVertex;
        } else {
            if (searchState.currentVertex->leftEdge != nullptr 
                && searchState.currentVertex->rightEdge == nullptr) {
                auto deletedVertex = searchState.currentVertex->leftEdge;
                searchState.currentVertex->replaceVertex(searchState.currentVertex->leftEdge);
                delete deletedVertex;
            } else {
                SearchState deleteState(searchState.currentVertex,
                    searchState.currentVertex->rightEdge, Direction::RIGHT);

                while (deleteState.currentVertex->leftEdge != nullptr) {
                    deleteState.goToLeft();
                }

                auto deletedVertex = deleteState.currentVertex;
                deleteState.replaceLink(deleteState.currentVertex->rightEdge);
                searchState.currentVertex->replaceValue(deleteState.currentVertex->value);
                delete deletedVertex;
            }
        }
    }

    if (rootFlag) {
        root = searchState.currentVertex;
    } else {
        searchState.replaceLink(searchState.currentVertex);
    }
}

template <class Type>
void BinaryTree<Type>::deleteByValue(const Type& value) {
    bool success = findByValue(value);
    if (success) {
        deleteByState(value);
    }
}

template <class Type>
size_t BinaryTree<Type>::getSize() const {
    return treeSize;
}

#endif  // MODULES_ZARUBIN_MIKHAIL_BINARY_TREE_INCLUDE_BINARY_TREE_H_
