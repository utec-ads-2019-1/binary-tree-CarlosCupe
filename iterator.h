#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>
#include <iostream>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        std::stack<Node<T>*> *pre_path;
        std::stack<Node<T>*> *pos_path;
        Node<T> * root;

    public:
        Iterator() : current(nullptr), pre_path(nullptr), pos_path(nullptr) {
            // TODO
        }

        Iterator(Node<T> *node) {
            // TODO
            root = current = node;
            pre_path = new std::stack<Node<T>*>;
            pos_path = new std::stack<Node<T>*>;
            
        }

        Iterator<T> operator=(Iterator<T> other) {          
            // TODO
            current = other->current;
            return *current;
        }

        bool operator!=(Iterator<T> other) {
            // TODO
            return current != other.current;
        }

        Iterator<T> operator++() {
            // TODO
            if (this->root->data > this->current->data) {
                if (this->pos_path->size() > 1) {
                    this->pos_path->pop();
                    this->current = this->pos_path->top();
                } else {
                    this->current = this->root;
                    delete this->pre_path;
                    delete this->pos_path;
                    pre_path = new std::stack<Node<T>*>;
                    pos_path = new std::stack<Node<T>*>;
                }
                return *this;
            }
            
            if (this->current ==this->root && this->current->right == nullptr)
                return Iterator<T>();

            Node<T> *temp;
            if (this->current->right) {
                this->current = this->current->right;

                while(this->current->left) {
                    this->pos_path->push(this->current);
                    this->current = this->current->left;
                }
            } else {
                if (this->pos_path->size() == 0) {
                    this->current = nullptr;
                    return *this;
                }

                temp = this->pos_path->top();
                this->pos_path->pop();
                
                while (temp && this->current == temp->right) {
                    this->current = temp;
                    if (this->pos_path->size() == 0) {
                        this->current = nullptr;
                        return *this;
                    }
                    temp = this->pos_path->top();
                    this->pos_path->pop();
                }
                this->current = temp;                
            }
            this->pre_path->push(this->current);  
                
            return *this;
        }

        Iterator<T> operator--() {
            // TODO
            if (this->current == nullptr) {
                this->current = this->pre_path->top();   
                return *this;
            }

            if (this->root->data < this->current->data) {
                if (this->pre_path->size() > 1) {
                    this->pre_path->pop();
                    this->current = this->pre_path->top();
                } else {
                    this->current = this->root;
                    delete this->pre_path;
                    delete this->pos_path;
                    pre_path = new std::stack<Node<T>*>;
                    pos_path = new std::stack<Node<T>*>;
                }
                return *this;
            }
            if (this->current ==this->root && this->current->left == nullptr)
                return Iterator<T>();

            Node<T> *temp;
            if (this->current->left) {
                this->current = this->current->left;

                while(this->current->right) {
                    this->pre_path->push(this->current);
                    this->current = this->current->right;
                }
            } else {
                if (this->pre_path->size() == 0)
                    return Iterator<T>();
                temp = this->pre_path->top();
                this->pre_path->pop();
                
                while (temp && this->current == temp->left) {
                    this->current = temp;
                    if (this->pre_path->size() == 0) {
                        return Iterator<T>();
                    }
                    temp = this->pre_path->top();
                    this->pre_path->pop();
                }
                this->current = temp;

            }
            
            this->pos_path->push(this->current);
            return *this;
        }

        T operator*() {
            // TODO
            if (current->data)
                return current->data;
            exit(0);
        }
};

#endif
