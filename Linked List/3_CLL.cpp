#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};
void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL) // empty list
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "List is empty!!" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == prev) // 1 Node LL
        {
            tail = NULL;
        }
        if (curr == tail) //>=2 Nodes LL
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
void Print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
bool isCircular(Node *&head)
{
    Node *temp = head->next;
    if (head == NULL)
    {
        return 1;
    }
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    if (temp == head)
    {
        return true;
    }
}
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 11, 3);
    Print(tail);

    insertNode(tail, 3, 5);
    Print(tail);

    insertNode(tail, 5, 7);
    Print(tail);

    insertNode(tail, 7, 9);
    Print(tail);

    insertNode(tail, 5, 15);
    Print(tail);

    deleteNode(tail, 15);
    Print(tail);

    deleteNode(tail, 3);
    Print(tail);

    if (isCircular(tail))
    {
        cout << "Linked list is circular " << endl;
    }
    else
        cout << "Linked list is not circular " << endl;

    cout << "The LL has loop or not " << detectLoop(tail) << endl;
    return 0;
}