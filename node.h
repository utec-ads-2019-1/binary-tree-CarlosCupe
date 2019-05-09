#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
private:
        T data;
        Node<T> *left;
        Node<T> *right;

    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 

public:
    Node(){}

    Node(T data): data(data){
        left = right = nullptr;
    }

    void killSelf() {
        if (this->left)
            this->left->killSelf();
        if (this->right)
            this->right->killSelf();
        delete this;
    }
};

#endif