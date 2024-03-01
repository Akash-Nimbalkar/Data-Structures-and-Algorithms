#include <iostream>
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
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};
void print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}
void insertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
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
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    if (tail == curr) // CLL with >2 nodes
    {
        tail = prev;
    }
    if (curr == prev) // CLL with single node
    {
        tail = NULL;
    }
    curr->next = NULL;
    delete curr;
}
bool isCircular(Node *&head)
{
    // Node *slow = head;
    // Node *fast = head->next;

    // while (fast != NULL && fast != slow)
    // {
    //     fast = fast->next;
    //     if (fast != NULL)
    //     {
    //         fast = fast->next;
    //     }
    //     slow = slow->next;
    // }
    // if (fast == slow)
    // {
    //     return true;
    // }
    // else
    //     return false;

    // empty list
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    if (temp == NULL)
    {
        return false;
    }
}
void splitCLL(Node *head)
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int len = 0;
    Node *temp = head;
    do
    {
        len++;
        temp = temp->next;
    } while (temp != head);

    int len1, len2;
    if (len % 2 == 0)
    {
        len1 = len2 = len / 2;
    }
    else
    {
        len1 = (len / 2) + 1;
        len2 = len - len1;
    }

    int cnt1 = 1, cnt2 = 1;
    Node *curr1 = head;
    while (cnt1 < len1)
    {
        curr1 = curr1->next;
        cnt1++;
    }
    head2 = curr1->next;
    curr1->next = head;
    head1 = head;
    print(head1);
    Node *curr2 = head2;
    while (cnt2 < len2)
    {
        curr2 = curr2->next;
        cnt2++;
    }
    curr2->next = head2;
    print(head2);
}
int main()
{

    Node *tail = NULL;

    insertNode(tail, 10, 10);
    print(tail);

    insertNode(tail, 10, 20);
    print(tail);

    insertNode(tail, 20, 30);
    print(tail);

    insertNode(tail, 30, 40);
    print(tail);

    insertNode(tail, 40, 50);
    print(tail);

    insertNode(tail, 50, 60);
    print(tail);

    // deleteNode(tail, 20);
    // print(tail);

    // if (isCircular(tail))
    // {
    //     cout << "Linked list is circular " << endl;
    // }
    // else
    // {
    //     cout << "Linked list is circular " << endl;
    // }

    cout << "After splitting..." << endl;
    splitCLL(tail);

    return 0;
}