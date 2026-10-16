#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void displayInorder(Node* root)
{
    if (root == NULL)
        return;

    displayInorder(root->left);
    cout << root->data << " ";
    displayInorder(root->right);
}

void findKthLargest(Node* root, int& k, int& answer)
{
    if (root == NULL || k == 0)
        return;

    findKthLargest(root->right, k, answer);

    if (k > 0)
    {
        k--;

        if (k == 0)
        {
            answer = root->data;
            return;
        }
    }

    findKthLargest(root->left, k, answer);
}

int main()
{
    Node* root = NULL;
    int n, value, k, answer = -1;

    cout << "Kth Largest Element in BST\n";

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of nodes.";
        return 0;
    }

    cout << "Enter BST elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nBST elements in ascending order: ";
    displayInorder(root);

    cout << "\nEnter the value of K: ";
    cin >> k;

    if (k <= 0 || k > n)
    {
        cout << "Invalid K value.";
        return 0;
    }

    findKthLargest(root, k, answer);

    cout << "Kth Largest Element = " << answer << endl;

    return 0;
}
