// Tree implementations.

#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <cinttypes>
#include <iostream>
#include <utility>

enum class TraversalType
{
    PreOrder,
    PostOrder,
    InOrder
};

// Stores the binary tree nodes and related functions.
template<typename T>
class BinarySearchTree
{
private:
        // void TraversePreOrder()
        // {
        // }

        Node<T>* TraverseInOrder(Node<T>* node)
        {
            if (node == nullptr)
                return node;

            TraverseInOrder(node->Left);

            std::cout << " " << node->Data << " ";

            TraverseInOrder(node->Right);

            return node;
        }

        // void TraversePostOrder(T* array, size_t size)
        // {
        // }

        // void Traverse(T* array, size_t size, TraversalType traversalType) // Wrapper function for the previously defined
        // {
        //     switch (traversalType)
        //     {
        //         case TraversalType::PreOrder:
        //             this->TraversePreOrder(array, size);

        //             break;

        //         case TraversalType::InOrder:
        //             this->TraverseInOrder(array, size);


        //             break;

        //         case TraversalType::PostOrder:
        //             this->TraversePostOrder(array, size);

        //             break;
        //     }
        // }

        void Delete(Node<T>* node) // Deletes all the nodes from the current instance of the tree.
        {
            if (!node)
                return;

            Delete(node->Left);
            Delete(node->Right);

            delete node;
        }

public:
        std::pair<Node<T>*, Node<T>*> GetSmallest(Node<T>* node)
        {
            if (!node)
                return std::pair(nullptr, nullptr);

            Node<T>* parent = node;

            while (node->Left)
            {
                parent = node;

                node = node->Left;
            }

            std::pair(parent, node);
        }

public:
        Node<T>* Root; // Root node.

        Node<T>* Insert(T value)
        {
            Node<T>* node = new Node<T>(value),
                *temp = this->Root,
                *finalNode;

            uint8_t child = 0;

            if (this->Root == nullptr)
                this->Root = node;

            while (temp)
            {
                finalNode = temp;

                if (value < temp->Data)
                {
                    temp = temp->Left;

                    child = 0;
                }
                else
                {
                    temp = temp->Right;

                    child = 1;
                }
            }

            switch (child)
            {
                case 0:
                   finalNode->Left = node;

                    break;

                case 1:
                    finalNode->Right = node;

                    break;
            }

            return node;
        }

        bool Search(T value)
        {
            Node<T>* current = this->Root,
                *finalNode;

            while (current)
            {
                if (current->Data == value)
                    return true;

                if (value < current->Data)
                    current = current->Left;

                if (value > current->Data)
                    current = current->Right;
            }

            return false;
        }

        std::pair<std::pair<Node<T>*, Node<T>*>, uint8_t> GetNode(T value)
        {
            if (!this->Root)
                return std::pair(std::pair(nullptr, nullptr), 0);

            std::pair<std::pair<Node<T>*, Node<T>*>, uint8_t> node = std::pair(std::pair(nullptr, this->Root), 0);

            if (value == this->Root->Data)
                return node;

            while (node.first.second)
            {
                if (value < node.first.second->Data)
                {
                    node.first.first = node.first.second;

                    node.first.second = node.first.second->Left;

                    node.second = 0;
                }

                if (value > node.first.second->Data)
                {
                    node.first.first = node.first.second;

                    node.first.second = node.first.second->Right;

                    node.second = 1;
                }

                if (value == node.first.second->Data)
                    break;
            }

            return node;
        }

        void Delete(T value)
        {
            if (!this->Root)
                return;

            if (value == this->Root->Data)
                delete this->Root;

            uint8_t childDirection = 0;

            std::pair<std::pair<Node<T>*, Node<T>*>, uint8_t> nodePair = this->GetNode(value);

            std::pair<Node<T>*, Node<T>*> smallestNode;

            if (!nodePair.second)
                return;

            // while (nodePair.second)
            // {
            //     if (value == nodePair.second->Data)// node found
            //         break;

            //     if (value < nodePair.second->Data)
            //     {
            //         nodePair.second = nodePair.second->Left;

            //         childDirection = 0;
            //     }

            //     if (value > nodePair.second->Data)
            //     {
            //         nodePair.second = nodePair.second->Right;

            //         childDirection = 1;
            //     }

            //     if (nodePair.second == this->Root)
            //     {
            //         delete nodePair.second;

            //         nodePair.second = nullptr;

            //         this->Root = nullptr;

            //         return;
            //     }

            // }

            if ((smallestNode = this->GetSmallest(nodePair.first.second->Right)).second == nullptr)
            {
                smallestNode.first->Right = nullptr;

                smallestNode.second->Left = nodePair.first.second->Left;
                smallestNode.second->Right = nodePair.first.second->Right;

                nodePair.first.first->Right = smallestNode.second;

                delete nodePair.first.second;
            }

            else
                switch (childDirection)
                {
                    case 0:
                        smallestNode.second->Left = nodePair.first.second->Left;
                        smallestNode.second->Right = nodePair.first.second->Right;

                        delete nodePair.first.first->Left;

                        nodePair.first.first->Left = smallestNode.second;

                        break;

                   case 1:
                        smallestNode.second->Left = nodePair.first.first->Right->Left;
                        smallestNode.second->Right = nodePair.first.first->Right->Right;

                        delete nodePair.first.first->Right;

                        nodePair.first.first->Right = smallestNode.second;

                        break;
                }
        }

        void Traverse()
        {
            this->TraverseInOrder(this->Root);
        }

        BinarySearchTree() : Root(nullptr)
        {
        }

        BinarySearchTree(T data)
        {
            this->Root = new Node<T>(data, nullptr, nullptr, nullptr); // Creates the node root.
        }

        BinarySearchTree(Node<T>* rootNode)
        {
            this->Root = rootNode; // Creates the node root.
        }

        ~BinarySearchTree()
        {
            this->Delete(this->Root);
        }
};

#endif // TREE_H
