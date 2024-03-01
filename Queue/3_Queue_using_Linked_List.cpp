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
};
class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        if (front == NULL)
        {
            front = rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    int pop()
    {
        if (front == NULL)
        {
            return -1;
        }
        else
        {
            int ans = front->data;
            Node *nodeToDelete = front;
            front = front->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            return ans;
        }
    }
    int getFront()
    {
        if (front == NULL)
        {
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        Node *temp = front;
        int len = 0;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
};

int main()
{
    Queue q;
    q.push(12);
    q.push(24);
    q.push(36);
    q.push(48);
    q.push(60);

    cout << q.getFront() << endl;
    cout << "Popped " << q.pop() << " from queue " << endl;

    cout << q.getFront() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}