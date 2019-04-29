#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        //stack<T> *path;
        //stack<T> *pos_path;

    public:
        Iterator() : current(nullptr) {
            // TODO
        }

        Iterator(Node<T> *node) {
            // TODO
            current = node;
        }

        Iterator<T> operator=(Iterator<T> other) {          
            // TODO
            current = other->current;
            return current;
        }

        bool operator!=(Iterator<T> other) {
            // TODO
            return current->data != other->current->data;
        }

        Iterator<T> operator++() {
            // TODO
        
        }

        Iterator<T> operator--() {
            // TODO
          /*
            this->current = this->path->top();
            this->path->pop();
            
            if (this->current->left != nullptr) {
                this->path->push(this->current);
                
                this->current = this->current->left;

                while(this->current->right) {
                    this->path->push(this->current);
                    this->current = this->current->right;
                }
            }

            return this;
          */
        }

        T operator*() {
            // TODO
            return current->data;
        }
};

#endif
