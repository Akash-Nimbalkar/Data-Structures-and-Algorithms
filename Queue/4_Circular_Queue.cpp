#include <bits/stdc++.h>
class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) // Queue is Full
        {
            return false;
        }
        else if (front == -1) // We are inserting first element in our queue
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) // To maintain cyclic nature
        {
            rear = 0;
        }
        else // normal condition
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue()
    {

        if (front == -1) // Queue is empty
        {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) // Only single element is present in queue
        {
            front = rear = -1;
        }
        else if (front == size - 1) // To maintain cyclic nature
        {
            front = 0;
        }
        else // normal condition
        {
            front++;
        }
        return ans;
    }
};