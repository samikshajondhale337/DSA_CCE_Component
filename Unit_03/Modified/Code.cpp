#include <iostream>
using namespace std;

struct Node {
    int c, p;
    Node *prev, *next;
};

Node* create(int c, int p) {
    Node *n = new Node;
    n->c = c;
    n->p = p;
    n->prev = n->next = NULL;
    return n;
}

void insert(Node *&h, int c, int p) {
    Node *n = create(c, p);

    if (h == NULL) {
        h = n;
        return;
    }

    Node *t = h;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;
}

void display(Node *h) {
    while (h != NULL) {
        cout << h->c << "x^" << h->p << " + ";
        h = h->next;
    }
    cout << "0\n";
}

int main() {
    Node *a = NULL, *b = NULL;
    Node *sum = NULL, *mul = NULL;
    int c, p, n;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        insert(a, c, p);
    }

    cout << "Enter number of terms in second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        insert(b, c, p);
    }

    for (Node *x = a; x != NULL; x = x->next) {
        insert(sum, x->c, x->p);
        for (Node *y = b; y != NULL; y = y->next)
            insert(mul, x->c * y->c, x->p + y->p);
    }

    for (Node *y = b; y != NULL; y = y->next)
        insert(sum, y->c, y->p);

    cout << "Addition: ";
    display(sum);

    cout << "Multiplication: ";
    display(mul);

    return 0;
}
