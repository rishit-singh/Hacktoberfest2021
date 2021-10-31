// Common tree node implementation.

#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

// Stores a tree node.
template<typename T>
struct Node
{
    T Data;

    Node<T>* Left, // Left child node.
        *Right; // Right child node.

    Node(T data) : Data(data), Left(nullptr), Right(nullptr)
    {
    }

    Node(T data, T* parent, T* left, T* right) : Data(data), Left(left), Right(right)
    {
    }
};

#endif // NODE_H
