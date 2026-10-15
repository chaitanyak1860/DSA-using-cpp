#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void findKthLargest(Node* root, int &k, int &ans)
{
    if (root == NULL || k == 0)
        return;

    findKthLargest(root->right, k, ans);

    if (k == 0)
        return;

    k--;

    if (k == 0)
    {
        ans = root->data;
        return;
    }

    findKthLargest(root->left, k, ans);
}

int main()
{
    Node* root = NULL;
    int n, value, k, ans = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of elements";
        return 0;
    }

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter K: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid value of K";
        return 0;
    }

    findKthLargest(root, k, ans);

    if (ans != -1)
        cout << "Kth largest element is: " << ans;
    else
        cout << "Element not found";

    return 0;
}