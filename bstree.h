#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;

    public:
        BSTree() : root(nullptr) {};

        bool find(T data) { 
            // TODO
            if (this->root == nullptr)
                return false;
        } 

        bool insert(T data) {
            // TODO
            if (this->root == nullptr) {
                this->root = new Node<T>(data);
                return true;
            }

            Node **ptr = &this->root;
            
            while(*ptr) {
                if (data == (*ptr)->data)
                    return false;

                if (data < (*ptr)->data)
                    ptr = &(*ptr)->left;
                
                if (data > (*ptr)->data)
                    ptr = &(*ptr)->right;
            }

            *ptr = new Node<T>(data);
            return true;
        }

        bool remove(T data) {
            // TODO
            if (this->root == nullptr)
                return false;

            Node **ptr = &this->root;
            
            while(*ptr) {
                if (data == (*ptr)->data)
                    break;

                if (data < (*ptr)->data)
                    ptr = &(*ptr)->left;
                
                if (data > (*ptr)->data)
                    ptr = &(*ptr)->right;
            }

            if (*ptr  == nullptr)
                return false;

            auto sum = [] (T &node) -> T {
                return node->left == nullptr + node->right == nullptr;
                }
            
            while (*ptr)
                switch (sum (**ptr)) {
                case 0:
                    delete *ptr;
                    break;
                case 1:
                
                default:
                    break;
                }

        }

        unsigned int size() {
            // TODO
        }

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
};

#endif
