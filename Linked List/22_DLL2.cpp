#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};
void print(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head " << head->data << " Tail " << tail->data << endl;
}
int getLength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    { 
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head; 
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtMiddle(Node *&head, Node *&tail, int position, int d)
{
    Node *nodeToInsert = new Node(d);
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    int cnt = 1;
    Node *temp = head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            prev->next = curr->next;
            tail = prev;
            curr->prev = NULL;
            delete curr;
            return;
        }

        prev->next = curr->next;
        curr->next->prev = prev;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}
void reverseDLL(Node *&head)
{
    Node *currPtr = head;
    Node *prevPtr = NULL;
    Node *forward = NULL;

    while (currPtr != NULL)
    {
        forward = currPtr->next;
        currPtr->next = prevPtr;
        currPtr->prev = forward;
        prevPtr = currPtr;
        currPtr = forward;
    }
    head = prevPtr;
}
int main()
{
    // Node *node1 = new Node(20);
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    print(head, tail);

    insertAtTail(head, tail, 30);
    print(head, tail);

    insertAtTail(head, tail, 50);
    print(head, tail);

    insertAtMiddle(head, tail, 2, 20);
    print(head, tail);

    insertAtMiddle(head, tail, 4, 40);
    print(head, tail);

    reverseDLL(head);
    print(head, tail);

    // deleteNode(head, tail, 5);
    // print(head, tail);

    return 0;
}