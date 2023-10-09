#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
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
        Node(Node *node)
        {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };
    Node *root; // 根节点
    int count;  // 节点数量
    Node *insert(Node *node, Key key, Value value);
    bool contain(Node *node, Key key);
    Value *search(Node *node, Key key);
    void preOrder(Node *node);
    void inOrder(Node *node);
    void postOrder(Node *node);
    void destroy(Node *node);
    void display(Node *node);
    Node *minimum(Node *node);
    Node *maximum(Node *node);
    Node *removeMin(Node *node);
    Node *removeMax(Node *node);
    Node *remove(Node *node, Key key);

public:
    BST();
    ~BST();
    int size();
    bool isEmpty();
    void insert(Key key, Value value); // 插入
    // void insert2(Key key, Value value); 非递归实现
    bool contain(Key key);  // 包含
    Value *search(Key key); // 查找
    void preOrder();        // 前序遍历
    void inOrder();         // 中序遍历
    void postOrder();       // 后序遍历
    void levelOrder();      // 层序遍历
    void display();
    void preOrderNotRecursion();  // 前序遍历 非递归 栈
    void inOrderNotRecursion();   // 中序遍历 非递归 栈
    void postOrderNotRecursion(); // 后序遍历 非递归 栈
    Key minimum();                // 当前树的最小值
    Key maximum();                // 当前树的最大值
    void removeMin();
    void removeMax();
    void remove(Key key);
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
    // 使用后序遍历进行销毁
    destroy(root);
}

template <typename Key, typename Value>
void BST<Key, Value>::destroy(Node *node)
{
    if (node == NULL)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
    count--;
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

template <typename Key, typename Value>
void BST<Key, Value>::preOrder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename Key, typename Value>
void BST<Key, Value>::preOrder()
{
    preOrder(root);
    cout << endl;
}

template <typename Key, typename Value>
void BST<Key, Value>::inOrder(Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}

template <typename Key, typename Value>
void BST<Key, Value>::inOrder()
{
    inOrder(root);
    cout << endl;
}

template <typename Key, typename Value>
void BST<Key, Value>::postOrder(Node *node)
{
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << " ";
}

template <typename Key, typename Value>
void BST<Key, Value>::postOrder()
{
    postOrder(root);
    cout << endl;
}

template <typename Key, typename Value>
void BST<Key, Value>::levelOrder()
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        Node *node = q.front(); // 不太理解为啥分两步
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        cout << node->key << " ";
    }
    cout << endl;
}

template <typename Key, typename Value>
void BST<Key, Value>::preOrderNotRecursion()
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) /*栈不空时循环*/
    {
        Node *node = s.top();
        s.pop();
        cout << node->key << " ";
        if (node->right != NULL)
            s.push(node->right);
        if (node->left != NULL)
            s.push(node->left);
    }
    cout << endl;
}

/**
 while (!stack.empty() || root != null) {
    while (root != null) {
        stack.push(root);
        root = root.left;
    }
    root = stack.pop();
    rs.add(root.getValue());
    root = root.right;
}
————————————————
版权声明：本文为CSDN博主「morningcat2018」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u013837825/article/details/105554745
*/
// https://blog.csdn.net/u013837825/article/details/106557694
// https://blog.csdn.net/u013837825/article/details/113756063
// https://blog.csdn.net/u013837825/article/details/120857910
template <typename Key, typename Value>
void BST<Key, Value>::inOrderNotRecursion()
{
    stack<Node *> s;
    Node *p = root;
    while (!s.empty() || p != NULL)
    {
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        cout << p->key << " ";
        p = p->right;
    }
    cout << endl;
}

/**
ChatGPT NB
*/
template <typename Key, typename Value>
void BST<Key, Value>::postOrderNotRecursion()
{
    stack<Node *> stack1, stack2;
    stack1.push(root);
    while (!stack1.empty())
    {
        Node *node = stack1.top();
        stack1.pop();
        stack2.push(node);
        if (node->left)
        {
            stack1.push(node->left);
        }
        if (node->right)
        {
            stack1.push(node->right);
        }
    }
    while (!stack2.empty())
    {
        Node *node = stack2.top();
        stack2.pop();
        cout << node->key << " ";
    }
    cout << endl;
}

template <typename Key, typename Value>
void BST<Key, Value>::display(Node *node)
{
    if (node == NULL)
        return;
    cout << node->key << " ";
    if (node->left != NULL || node->right != NULL)
    {
        cout << "(";
        display(node->left);
        if (node->right != NULL)
            cout << ",";
        display(node->right);
        cout << ")";
    }
}

template <typename Key, typename Value>
void BST<Key, Value>::display()
{
    display(root);
    cout << endl;
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::minimum(Node *node)
{
    if (node->left == NULL)
        return node;
    return minimum(node->left);
}

template <typename Key, typename Value>
Key BST<Key, Value>::minimum()
{
    assert(count > 0);
    Node *node = minimum(root);
    return node->key;
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::maximum(Node *node)
{
    if (node->right == NULL)
        return node;
    return maximum(node->right);
}

template <typename Key, typename Value>
Key BST<Key, Value>::maximum()
{
    assert(count > 0);
    Node *node = maximum(root);
    return node->key;
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::removeMin(Node *node)
{
    if (node->left == NULL)
    {
        Node *rightNode = node->right;
        delete node;
        count--;
        return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
}

template <typename Key, typename Value>
void BST<Key, Value>::removeMin()
{
    if (root != NULL)
        root = removeMin(root);
}

template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::removeMax(Node *node)
{
    if (node->right == NULL)
    {
        Node *leftNode = node->left;
        delete node;
        count--;
        return leftNode;
    }
    node->right = removeMax(node->right);
    return node;
}

template <typename Key, typename Value>
void BST<Key, Value>::removeMax()
{
    if (root != NULL)
        root = removeMax(root);
}

// Hubbard Deletion
template <typename Key, typename Value>
typename BST<Key, Value>::Node *BST<Key, Value>::remove(Node *node, Key key)
{
    if (node == NULL)
        return NULL;

    if (key < node->key)
    {
        node->left = remove(node->left, key);
        return node;
    }
    if (key > node->key)
    {
        node->right = remove(node->right, key);
        return node;
    }
    // key == node.key

    if (node->left == NULL)
    {
        // 只有右孩子
        Node *rightNode = node->right;
        delete node;
        count--;
        return rightNode;
    }
    if (node->right == NULL)
    {
        // 只有左孩子
        Node *leftNode = node->left;
        delete node;
        count--;
        return leftNode;
    }
    // 两边都有节点
    // 第一种写法
    Node *minNode = minimum(node->right);
    Node *addNode = new Node(minNode->key, minNode->value);
    count++;
    addNode->right = node->right;
    addNode->left = node->left;
    delete minNode;
    count--;
    delete node;
    count--;
    return addNode;

    // 第二种写法
    // Node *successor = new Node(minimum(node->right));
    // count++;
    // successor->right = removeMin(node->right);
    // successor->left = node->left;
    // delete node;
    // count--;

    // 第三种写法
    // Node *successor = new Node(maximum(node->left));
    // successor->left = removeMax(node->left);
    // successor->right = node->right;
    // delete node;

    // return successor;
}

template <typename Key, typename Value>
void BST<Key, Value>::remove(Key key)
{
    root = remove(root, key);
}

#endif
