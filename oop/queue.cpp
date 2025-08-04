#include<iostream>
#include<vector>

using namespace std;

class Queue {
    int capacity;
    int size;
    vector<int> q;
    int front;
    int rear;

public:
    Queue(int cap) {
        capacity = cap;
        q.resize(capacity, 0);
        size = 0;
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        q[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << q[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    q.dequeue();
    q.display();  // Output: 20 30

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // This will fill queue
    q.display();

    q.enqueue(70);  // Queue is full

    return 0;
}
