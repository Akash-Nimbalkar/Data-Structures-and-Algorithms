#include <iostream>
#include <map>
#include <math.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};
void InsertAtHead(Node *&head, int d)
{
    // Create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

// void DeleteNode(int position, Node *&head, Node *&tail)
// {
//     if (position == 1) // To delete first node
//     {
//         Node *temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else // To delete any middle or last node
//     {
//         Node *curr = head;
//         Node *prev = NULL;
//         int cnt = 1;

//         while (cnt < position - 1)
//         {
//             curr = curr->next;
//             cnt++;
//         }

//         if (curr->next == NULL)
//         {
//             tail = prev;
//         }
//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//     }
// }
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->next = NULL;
        delete temp;
    }
    else
    {
        int cnt = 1;
        Node *curr = head;
        Node *prev = NULL;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void Print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Cycle present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydDetectLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    cout << "The beginning of loop is at node " << slow->data << endl;
    return slow;
}
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *StartNode = getStartingNode(head);
    Node *temp = StartNode;
    while (temp->next != StartNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void removeDuplicates(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        Node *curr = temp->next;
        Node *prev = temp;
        while (curr != NULL)
        {
            if (temp->data == curr->data)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
}
void sortList(Node *&head)
{
    Node *temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
        {
            cnt2++;
        }
        temp = temp->next;
    }

    Node *curr = head;
    int i = 0, j = 0, k = 0;
    while (i < cnt0)
    {
        curr->data = 0;
        curr = curr->next;
        i++;
    }
    while (j < cnt1)
    {

        curr->data = 1;
        curr = curr->next;
        j++;
    }
    while (k < cnt2)
    {
        curr->data = 2;
        curr = curr->next;
        k++;
    }
}
int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    // Print(head);

    InsertAtTail(tail, 3);
    Print(head);

    InsertAtTail(tail, 5);
    Print(head);

    InsertAtTail(tail, 7);
    Print(head);

    InsertAtTail(tail, 9);
    Print(head);

    InsertAtTail(tail, 11);
    Print(head);

    // tail->next = head->next;
    //  cout << "Head is " << head->data << endl;
    //  cout << "Tail ka next is " << tail->next->data << endl;
    deleteNode(head, tail, 6);
    Print(head);

    // cout << "Head is " << head->data << endl;
    // cout << "Tail is " << tail->data << endl;
    // if (floydDetectLoop(head) != NULL)
    // {
    //     cout << "Cycle is present!! ";
    // }
    // else
    // {
    //     cout << "Cycle is not present !!";
    // }
    // getStartingNode(head);
    // removeLoop(head);
    // Print(head);
    // if (floydDetectLoop(head) != NULL)
    // {
    //     cout << "Cycle is present!! ";
    // }
    // else
    // {
    //     cout << "Cycle is not present !!";
    // }
    // removeDuplicates(head);
    // sortList(head);
    // Print(head);

    return 0;
}