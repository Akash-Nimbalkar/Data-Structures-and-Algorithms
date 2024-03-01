#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear) // Single element is present in queue
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};
int main()
{
    Queue q(5);
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);

    cout << "Front queue element is " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front queue element is " << q.getFront() << endl;

    return 0;
}