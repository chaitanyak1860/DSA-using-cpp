#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string item;
    Node* next;
};

Node* head = NULL;

// Add multiple grocery items
void addItem()
{
    int n;

    cout << "How many grocery items do you want to add? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node;

        cout << "Enter grocery item " << i + 1 << ": ";
        cin >> newNode->item;

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    cout << "Items added successfully.\n";
}

// Display grocery list
void displayList()
{
    if (head == NULL)
    {
        cout << "Shopping list is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\nGrocery Shopping List:\n";

    while (temp != NULL)
    {
        cout << "- " << temp->item << endl;
        temp = temp->next;
    }
}

// Search grocery item
void searchItem()
{
    string item;

    cout << "Enter item to search: ";
    cin >> item;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->item == item)
        {
            cout << "Item found in the shopping list.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Item not found.\n";
}

// Delete grocery item
void deleteItem()
{
    string item;

    cout << "Enter item to delete: ";
    cin >> item;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->item != item)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Item not found.\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;

    cout << "Item deleted successfully.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Grocery Shopping List =====\n";
        cout << "1. Add Items\n";
        cout << "2. Display List\n";
        cout << "3. Search Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addItem();
                break;

            case 2:
                displayList();
                break;

            case 3:
                searchItem();
                break;

            case 4:
                deleteItem();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}