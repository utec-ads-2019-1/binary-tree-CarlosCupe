#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <functional>
#include <stack>
#include <iostream>

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
            
            Node<T> *ptr = this->root;

            while (ptr) {
                if (ptr->data == data)
                    return true;
                if (data > ptr->data)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }
            return false;
        } 

        bool insert(T data) {
            // TODO
            if (this->root == nullptr) {
                this->root = new Node<T>(data);
                return true;
            }

            Node<T> **ptr = &this->root;
            
            while(*ptr) {
                if (data == (*ptr)->data)
                    return false;

                if (data < (*ptr)->data)
                    ptr = &(*ptr)->left;
                else
                    ptr = &(*ptr)->right;
            }
            
            *ptr = new Node<T>(data);
            return true;
        }

        bool remove(T data) {
            // TODO
            if (this->root == nullptr)
                return false;
            Node<T> **ptr = &this->root;
            
            while(*ptr) {
                if (data == (*ptr)->data)
                    break;

                if (data < (*ptr)->data) 
                    ptr = &(*ptr)->left;
                else
                    ptr = &(*ptr)->right;
            }
            
            if (*ptr  == nullptr)
                return false;

            auto children = [] (Node<T> *&node) -> int {
                return (node->left != nullptr) + (node->right != nullptr);
                };
            
            Node<T> *temp = *ptr;

            while (*ptr) {
                switch (children(*ptr)) {
                    case 0: delete *ptr;
                        (*ptr) = nullptr;
                        return true;
                        break;
                    case 1:
                        temp = *ptr;
                        if ((*ptr)->left)
                            *ptr = (*ptr)->left;
                        else
                            *ptr = (*ptr)->right;
                        delete temp;
                        return true;
                        break;
                    case 2:
                        ptr = &((*ptr)->left);
                        while((*ptr)->right) {
                            ptr = &(*ptr)->right;
                        }
                        swap((*ptr)->data, temp->data);
                        break;
                }
            }
        }

        unsigned int size() {
            // TODO
            std::function<int(Node<T> *&)> recursive_count;
            recursive_count = [&recursive_count] (Node<T> *& node) ->int {
                if (node)
                    return 1 + recursive_count(node->right) + recursive_count(node->left);
                return 0;
                };
            return recursive_count(this->root);                        
        }

        void traversePreOrder() {
            // TODO
            std::function<void(Node<T> *&)> recursive_print;
            recursive_print = [&recursive_print] (Node<T> *& node) ->void {
                if (node == nullptr)
                    return;
                std::cout << node->data << " ";
                recursive_print(node->left);
                recursive_print(node->right); 
                };
            recursive_print(this->root);
            std::cout << std::endl;
        }

        void traverseInOrder() {
            // TODO
            std::function<void(Node<T> *&)> recursive_print;
            recursive_print = [&recursive_print] (Node<T> *& node) ->void {
                if (node == nullptr)
                    return;
                recursive_print(node->left);
                std::cout << node->data << " ";
                recursive_print(node->right); 
                };
            recursive_print(this->root);
            std::cout << std::endl;
        }

        void traversePostOrder() {
            // TODO
            std::function<void(Node<T> *&)> recursive_print;
            recursive_print = [&recursive_print] (Node<T> *& node) ->void {
                if (node == nullptr)
                    return;
                recursive_print(node->left);
                recursive_print(node->right); 
                std::cout << node->data << " ";
                };
            recursive_print(this->root);
            std::cout << std::endl;
        }

        Iterator<T> begin() {
            // TODO
            if (this->size() == 0)
                return Iterator<T>();;
            
            Iterator<T> it(this->root);

            Node<T> *ptr = this->root;
            
            while (ptr->left)
                ptr = ptr->left;
            
            while(*it != ptr->data)
                --it;

            return it;
        }

        Iterator<T> end() { 
            // TODO
            return Iterator<T>();
        }

        ~BSTree() {
            // TODO
            if (this->root)
                this->root->killSelf();
        }
};

#endif
