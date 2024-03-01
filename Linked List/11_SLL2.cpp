#include <iostream>
#include <bits/stdc++.h>
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
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};
void print(Node *&head, Node *&tail)
{
    cout << "Head " << head->data << " Tail " << tail->data << endl;
    Node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
    }
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        tail = temp;
    }
    tail->next = temp;
    tail = temp;
}
void InsertAtmiddle(Node *&head, Node *&tail, int d, int pos)
{
    Node *temp = head;
    int cnt = 1;
    if (pos == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void DeleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
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
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void reverseLL(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *forward = NULL;
    Node *prev = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }
    return prev;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "Present at " << temp->data << endl;
            return 1;
        }
        visited[temp] == true;
        temp = temp->next;
    }
    return 0;
}

Node *floydDetectLoop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            cout << "Present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node *getStartingNode(Node *head)
{
    Node *intersection = floydDetectLoop(head);
    Node *slow = head;
    Node *fast = intersection;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
void removeLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *startOfLoop = getStartingNode(head);
    Node *curr = startOfLoop;
    while (curr->next != startOfLoop)
    {
        curr = curr->next;
    }
    curr->next = NULL;
}
void removeDuplicates_SortedList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
}
void removeDuplicates_UnsortedList(Node *head) // Has O(N^2) T.C
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        Node *prev = curr;
        while (temp != NULL)
        {

            if (curr->data == temp->data)
            {
                Node *next_next = prev->next->next;
                Node *nodeToDelete = temp;
                delete nodeToDelete;
                prev->next = next_next;
                temp = next_next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}
void removeDuplicatesUsingMap(Node *&head)
{
    Node *curr = head;

    Node *prev = NULL;

    map<int, bool> seen;

    while (curr != NULL)
    {
        int val = curr->data;

        if (seen[val])
        {

            prev->next = curr->next;

            delete curr;

            curr = prev->next;
        }
        else
        {
            seen[val] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}
void deleteNode(Node *head, int x)
{
    if (head == NULL)
    {
        return;
    }

    int count = 1;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = curr->next;
    while (count < x)
    {
        prev = curr;
        curr = curr->next;
        forward = curr->next;
        count++;
    }
    prev->next = forward;
    curr->next = NULL;
    delete curr;
}

void unsort_remove(Node *&head)
{
    unordered_map<int, bool> mapping;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = curr->next;

    while (curr != NULL)
    {
        int val = curr->data;
        forward = curr->next;
        if (mapping[val] == false)
        {
            mapping[val] = true;
        }
        else if (mapping[val] == true)
        {
            Node *nodeToDelete = curr;
            prev->next = curr->next;
            delete nodeToDelete;
        }
        prev = curr;
        curr = forward;
    }
}

Node *foldMerge(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp)
    {
        len++;
    }
    int mid = len / 2;
    int cnt = 1;
    temp = head;
    while (cnt < mid)
    {
        temp = temp->next;
    }
    Node *head2 = temp->next;
    temp->next = NULL;
    Node *head1 = head;

    Node *prev = NULL;
    Node *curr = head1;

    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head1 = prev;

    temp = head1;
    curr = head2;
    while (temp != NULL && curr != NULL)
    {
        temp->data = (temp->data) * (curr->data);
        temp = temp->next;
        curr = curr->next;
    }

    return head1;
}

int main()
{
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;
    print(head, tail);

    InsertAtTail(tail, 2);
    print(head, tail);

    InsertAtTail(tail, 3);
    print(head, tail);

    // InsertAtmiddle(head, tail, 10, 4);
    // print(head, tail);

    // InsertAtHead(head, 3);
    // print(head, tail);

    // InsertAtHead(head, 1);
    // print(head, tail);

    InsertAtTail(tail, 4);
    print(head, tail);

    InsertAtTail(tail, 5);
    print(head, tail);

    InsertAtTail(tail, 6);
    print(head, tail);

    // InsertAtTail(tail, 9);
    // print(head, tail);

    // InsertAtTail(tail, 4);
    // print(head, tail);

    // unsort_remove(head);
    // print(head, tail);

    // DeleteNode(head, tail, 3);
    // print(head, tail);

    // reverseLL(head);
    // print(head, tail);
    // Node *temp = kReverse(head, 2);
    // cout << "After reversing LL in group of 2 nodes..." << endl;
    // print(temp, tail);

    // tail->next = head->next;

    // if (floydDetectLoop(head))
    // {
    //     cout << "Loop is present " << endl;
    // }
    // else
    // {
    //     cout << "Loop is not present " << endl;
    // }
    // Node *temp = getStartingNode(head);
    // cout << "Loop starts at " << temp->data << endl;

    // removeLoop(head);

    // if (floydDetectLoop(head))
    // {
    //     cout << "Loop is present " << endl;
    // }
    // else
    // {
    //     cout << "Loop is not present " << endl;
    // }
    // removeDuplicates_SortedList(head);
    // print(head, tail);

    // removeDuplicates_UnsortedList(head);
    // removeDupli(head);
    // removeDuplicatesUsingMap(head);
    // print(head, tail);

    // deleteNode(head, 4);
    // print(head, tail);

    Node *ans = foldMerge(head);
    Node *temp = ans;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    return 0;
}