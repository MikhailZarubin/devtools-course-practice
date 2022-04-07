// Copyright 2022 Zarubin Mikhail

#include <gtest/gtest.h>
#include <vector>

#include "include/binary_tree.h"

using std::vector;


BinaryTree::Vertex::Vertex(const Type& _value,
    Vertex* _leftEdge, Vertex* _rightEdge) :
    value(_value),
    leftEdge(_leftEdge),
    rightEdge(_rightEdge) {
}
 
void BinaryTree::Vertex::replaceValue(const Type& newValue) {
    value = newValue;
}
 
void BinaryTree::Vertex::replaceVertex(Vertex* vertex) {
    value = vertex->value;
    leftEdge = vertex->leftEdge;
    rightEdge = vertex->rightEdge;
}

BinaryTree::SearchState::SearchState(Vertex* _previousVertex,
    Vertex* _currentVertex, Direction _lastStep) :
    previousVertex(_previousVertex),
    currentVertex(_currentVertex),
    lastStep(_lastStep) {
}

void BinaryTree::SearchState::reset(Vertex* _previousVertex,
    Vertex* _currentVertex) {
    previousVertex = _previousVertex;
    currentVertex = _currentVertex;
    lastStep = Direction::LEFT;
}
 
void BinaryTree::SearchState::goToLeft() {
    lastStep = Direction::LEFT;
    previousVertex = currentVertex;
    currentVertex = currentVertex->leftEdge;
}
 
void BinaryTree::SearchState::goToRight() {
    lastStep = Direction::RIGHT;
    previousVertex = currentVertex;
    currentVertex = currentVertex->rightEdge;
}
 
void BinaryTree::SearchState::replaceLink(Vertex* vertex) {
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
 
BinaryTree::BinaryTree() :
    root(nullptr),
    searchState(),
    treeSize(0) {
}

BinaryTree::BinaryTree(const std::vector<Type>& data) : BinaryTree() {
    for (const auto& value : data) {
        insertByValue(value);
    }
}
 
bool BinaryTree::findByValue(const Type& value) {
    searchState.reset(nullptr, root);

    while (searchState.currentVertex != nullptr) {
        auto currentValue = searchState.currentVertex->value;

        if (value < currentValue) {
            searchState.goToLeft();
        }
        else {
            if (value > currentValue) {
                searchState.goToRight();
            }
            else {
                return true;
            }
        }
    }

    return false;
}

void BinaryTree::insertByState(const Type& value) {
    treeSize++;
    searchState.replaceLink(new Vertex(value));
}
 
void BinaryTree::insertByValue(const Type& value) {
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

void BinaryTree::deleteByState(const Type& value) {
    bool rootFlag = searchState.currentVertex == root;
    treeSize--;

    if (searchState.currentVertex->leftEdge == nullptr
        && searchState.currentVertex->rightEdge == nullptr) {
        delete searchState.currentVertex;
        searchState.currentVertex = nullptr;
    }
    else {
        if (searchState.currentVertex->leftEdge == nullptr
            && searchState.currentVertex->rightEdge != nullptr) {
            auto deletedVertex = searchState.currentVertex->rightEdge;
            searchState.currentVertex->
                replaceVertex(searchState.currentVertex->rightEdge);
            delete deletedVertex;
        }
        else {
            if (searchState.currentVertex->leftEdge != nullptr
                && searchState.currentVertex->rightEdge == nullptr) {
                auto deletedVertex = searchState.currentVertex->leftEdge;
                searchState.currentVertex->
                    replaceVertex(searchState.currentVertex->leftEdge);
                delete deletedVertex;
            }
            else {
                SearchState deleteState(searchState.currentVertex,
                    searchState.currentVertex->rightEdge, Direction::RIGHT);

                while (deleteState.currentVertex->leftEdge != nullptr) {
                    deleteState.goToLeft();
                }

                auto deletedVertex = deleteState.currentVertex;
                deleteState.replaceLink(deleteState.currentVertex->rightEdge);
                searchState.currentVertex->
                    replaceValue(deleteState.currentVertex->value);
                delete deletedVertex;
            }
        }
    }

    if (rootFlag) {
        root = searchState.currentVertex;
    }
    else {
        searchState.replaceLink(searchState.currentVertex);
    }
}
 
void BinaryTree::deleteByValue(const Type& value) {
    bool success = findByValue(value);
    if (success) {
        deleteByState(value);
    }
}
 
size_t BinaryTree::getSize() const {
    return treeSize;
}

