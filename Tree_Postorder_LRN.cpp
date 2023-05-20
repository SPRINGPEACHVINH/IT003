
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /* you only have to complete the function given below.
    Node is defined as

    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    void postOrder(Node *root)
    {
        if (root == NULL)
            return;
        // postOrder(root->left);
        // postOrder(root->right);
        // cout << root->data << " ";

        stack<Node *> s;
        Node *current = root;
        Node *temp = NULL;
        while (current != NULL || !s.empty())
        {
            // Thêm tất cả các nút bên trái của cây con trái vào stack
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            if (current->right == NULL || current->right == temp)
            {
                cout << current->data << " ";
                s.pop();
                temp = current;
                current = NULL;
            }
            else
            {
                current = current->right;
            }
        }
    }
};

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.postOrder(root);

    return 0;
}