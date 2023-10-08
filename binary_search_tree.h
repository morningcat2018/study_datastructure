#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <cassert>
using namespace std;

template <typename Key, typename Value>
class BST
{
private:
    struct Node
    {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value)
        {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };
    Node *root; // 根节点
    int count;  // 节点数量
    Node *insert(Node *node, Key key, Value value);
    bool contain(Node *node, Key key);
    Value *search(Node *node, Key key);

public:
    BST();
    ~BST();
    int size();
    bool isEmpty();
    void insert(Key key, Value value); // 插入
    // void insert2(Key key, Value value); 非递归实现
    bool contain(Key key);  // 查找
    Value *search(Key key); // 查找
};

template <typename Key, typename Value>
BST<Key, Value>::BST()
{
    root = NULL;
    count = 0;
}

template <typename Key, typename Value>
BST<Key, Value>::~BST()
{
    // TODO
}

template <typename Key, typename Value>
int BST<Key, Value>::size()
{
    return count;
}

template <typename Key, typename Value>
bool BST<Key, Value>::isEmpty()
{
    return count == 0;
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::insert(Node *node, Key key, Value value)
{
    if (node == NULL)
    {
        count++;
        return new Node(key, value);
    }
    if (key == node->key)
        node->value = value;
    else if (key < node->key)
        node->left = insert(node->left, key, value);
    else
        node->right = insert(node->right, key, value);
    return node;
}

template <typename Key, typename Value>
void BST<Key, Value>::insert(Key key, Value value)
{
    root = insert(root, key, value);
}

template <typename Key, typename Value>
bool BST<Key, Value>::contain(Node *node, Key key)
{
    if (node == NULL)
        return false;
    if (key == node->key)
        return true;
    if (key < node->key)
        return contain(node->left, key);
    else
        return contain(node->right, key);
}

template <typename Key, typename Value>
bool BST<Key, Value>::contain(Key key)
{
    return contain(root, key);
}

template <typename Key, typename Value>
Value *BST<Key, Value>::search(Node *node, Key key)
{
    if (node == NULL)
        return NULL;
    if (key == node->key)
        return &(node->value);
    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

template <typename Key, typename Value>
Value *BST<Key, Value>::search(Key key)
{
    return search(root, key);
}

#endif
