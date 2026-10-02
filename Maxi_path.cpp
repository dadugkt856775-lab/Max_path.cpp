#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

int maxPath(Node* root, int& answer) {
    if (root == nullptr)
        return 0;

    int left = max(0, maxPath(root->left, answer));
    int right = max(0, maxPath(root->right, answer));

    answer = max(answer, root->data + left + right);

    return root->data + max(left, right);
}

int main() {
    Node* root = new Node(-10);

    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int answer = INT_MIN;

    maxPath(root, answer);

    cout << "Maximum Path Sum: " << answer;

    return 0;
}
