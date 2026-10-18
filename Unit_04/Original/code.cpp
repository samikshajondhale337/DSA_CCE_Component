#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;

    Node(int x) {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int height(Node *n) {
    return n ? n->height : 0;
}

int balance(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node *root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int b = balance(root);

    if (b > 1 && key < root->left->data)
        return rightRotate(root);

    if (b < -1 && key > root->right->data)
        return leftRotate(root);

    if (b > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* deleteNode(Node *root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node *temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int b = balance(root);

    if (b > 1 && balance(root->left) >= 0)
        return rightRotate(root);

    if (b > 1 && balance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && balance(root->right) <= 0)
        return leftRotate(root);

    if (b < -1 && balance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);

    cout << "Before deletion: ";
    inorder(root);

    root = deleteNode(root, 20);

    cout << "\nAfter deletion: ";
    inorder(root);

    cout << "\n";
    return 0;
}
