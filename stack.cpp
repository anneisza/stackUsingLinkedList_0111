#include <iostream>
using namespace std;

class Node // Membuat class node
{
public:
    int data;   // mendeklarasikan integer data
    Node *next; // Node pointer next
    Node()
    {
        next = NULL; // Node berikutnya(NEXT) kosong(NULL)
    }
};

// stack class
class Stack
{
private:
    Node *top; // pointer to the top node of the stack

public:
    Stack()
    {
        top = NULL; // Initialize the stack with a null top pointer
    }

    // Push operation: Insert an element onto the top of the stack
    int push(int value)//Untuk memasukkan data
    {
        Node *newNode = new Node(); // 1. Allocate memory for the new code
        newNode->data = value;      // 2. Assign value
        newNode->next = top;        // 3. Set the next pointer of the new node to the current
        top = newNode;              // 4. update the top pointer to the new node
        cout << "Push value:" << value << endl;
        return value;
    }

    // IsEmpty operation: Check if the stack is empty
    bool isEmpty()
    {
        return top == NULL; // return true if the top pointer is NULL, indicating an empty stack
    }

    // pop operation: Remove the topmost element from the stack
    void pop()//Untuk menghapus data
    {
        Node *temp = top; // create a temporary pointer to the current top node
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return; // If the stack is empty, print a message and return
        }
        cout << "Popped value: " << temp->data << endl;
        top = temp->next; // Update the top pointer to the next node
        temp = nullptr;   // Free the memory of the popped node
    }

    // Peek/Top operation: Retrieve the value of the topmost element without removing it
    void peek()//Untuk melihat data
    {
        if (isEmpty())
        {
            cout << "List is empty." << endl;
            return; // If the stack is empty, print a message and return
        }
        else
        {
            Node *current = top;
            while (current != NULL)
            {
                cout << current->data << " " << endl;
                current = current->next;
            }
            cout << endl;

        } // Return the value of the top node
    }
};

int main()
{
    Stack stack;

    int choice = 0;
    int value;

    while (choice != 4)
    {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            stack.push(value); // Push the entered value onto the stack
            break;
        case 2:
            stack.pop(); // Pop the topmost element from the stack
            break;
        case 3:
            stack.peek();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}
