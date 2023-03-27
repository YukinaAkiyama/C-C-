#include <iostream>
using namespace std;

typedef struct Node {
    char data;
    struct Node* left, * right;
} Node, * Tree;

Tree create() {
    char ch;
    Tree tree = NULL;
    if (scanf_s("%c", &ch)) {//当有输入时
        if (ch != '#') {
            tree = (Tree)malloc(sizeof(Node));
            tree->data = ch;
            tree->left = create();
            tree->right = create();
        }
        else {
            tree = NULL;
        }
    }
    return tree;
}

void order(Tree tree) {
    if (!tree)
        return;
    order(tree->left);
    printf("%c", tree->data);
    order(tree->right);
}

void swap(Tree tree) {
    if (!tree)
        return;
    if (!tree->left && !tree->right)
        return;
    Tree tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;
    swap(tree->left);
    swap(tree->right);
}

int main() {
    Tree tree = create();
    order(tree);
    cout << endl;
    swap(tree);
    order(tree);
    return 0;
}
