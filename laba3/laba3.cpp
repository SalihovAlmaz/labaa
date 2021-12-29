#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#define N 26
const int t = N * 1.5;
using namespace std;
void randInput(int* arr) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        bool stop = false;
        while (!stop) {
            stop = true;
            arr[i] = rand() % 9000 + 1000;
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    stop = false;
                    break;
                }
            }
        }
    }
}
void show(int* arr, int size = N) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl << endl;
}
class NodeTree {
private:
    NodeTree* left;
    NodeTree* right;
    int value;
public:
    NodeTree() {
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    NodeTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
    void addChild(int value) {
        if (value > this->value)
            if (right == nullptr)
                right = new NodeTree(value);
            else
                right->addChild(value);
        else if (value < this->value)
            if (left == nullptr)
                left = new NodeTree(value);
            else
                left->addChild(value);
    }
    void showTree(NodeTree* t, const int level = 0) {
        if (t->right != nullptr)
            showTree(t->right, level + 1);
        for (int i = 0; i < level; i++)
            std::cout << "     ";
        std::cout << t->value << std::endl;
        if (t->left != nullptr)
            showTree(t->left, level + 1);
    }
     void inorder(NodeTree* root) {
        if (root == NULL) return;
        inorder(root->right);
        printf("%d ->", root->value);
        inorder(root->left);
    }

    void preorder(NodeTree* root) {
        if (root == NULL) return;
        printf("%d ->", root->value);
        preorder(root->right);
        preorder(root->left);
    }

    void postorder(NodeTree* root) {
        if (root == NULL) return;
        postorder(root->right);
        postorder(root->left);
        printf("%d ->", root->value);
    }
};
    
int main() {
    int a[N];
    randInput(a);
    //int a[7] = {5, 7, 9, 4, 2, 3, 9};
    show(a);
    NodeTree* tree = new NodeTree(a[0]);
    for (int i = 1; i < N; i++) {
        tree->addChild(a[i]);
    }
    tree->showTree(tree);
    cout << endl << endl;
    printf("RLN\n");
    tree->inorder(tree);
 
    printf("\nNRL \n");
    tree->preorder(tree);
 
    printf("\nRNL \n");
    tree->postorder(tree);
    
}