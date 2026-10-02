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

pair<int, int> rob(Node* root) {
    if (!root)
        return {0, 0};

    auto left = rob(root->left);
    auto right = rob(root->right);

    int robCurrent = root->data + left.second + right.second;

    int skipCurrent = max(left.first, left.second) +
                      max(right.first, right.second);

    return {robCurrent, skipCurrent};
}

int main() {
    Node* root = new Node(3);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(3);
    root->right->right = new Node(1);

    auto result = rob(root);

    cout << "Maximum Money: "
         << max(result.first, result.second);

    return 0;
}
