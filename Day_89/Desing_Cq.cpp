class MyCircularDeque {
private:
    vector<int> deque;  // Array to store the elements
    int front;          // Index of the front element
    int rear;           // Index of the rear element
    int capacity;       // Maximum capacity of the deque
    int size;           // Current size of the deque

public:
    // Constructor to initialize the deque with maximum size k
    MyCircularDeque(int k) {
        deque.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        size = 0;
    }
    
    // Adds an item at the front of Deque. Returns true if successful
    bool insertFront(int value) {
        if (isFull()) return false;  // Check if the deque is full
        front = (front - 1 + capacity) % capacity;  // Move front backwards circularly
        deque[front] = value;  // Insert the value
        size++;  // Increase the size
        return true;
    }
    
    // Adds an item at the rear of Deque. Returns true if successful
    bool insertLast(int value) {
        if (isFull()) return false;  // Check if the deque is full
        deque[rear] = value;  // Insert the value
        rear = (rear + 1) % capacity;  // Move rear forwards circularly
        size++;  // Increase the size
        return true;
    }
    
    // Deletes an item from the front of Deque. Returns true if successful
    bool deleteFront() {
        if (isEmpty()) return false;  // Check if the deque is empty
        front = (front + 1) % capacity;  // Move front forwards circularly
        size--;  // Decrease the size
        return true;
    }
    
    // Deletes an item from the rear of Deque. Returns true if successful
    bool deleteLast() {
        if (isEmpty()) return false;  // Check if the deque is empty
        rear = (rear - 1 + capacity) % capacity;  // Move rear backwards circularly
        size--;  // Decrease the size
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1; 
        return deque[front]; 
    }
    
    int getRear() {
        if (isEmpty()) return -1; 
        return deque[(rear - 1 + capacity) % capacity];  
    }
    
    bool isEmpty() {
        return size == 0;  
    }
    
    bool isFull() {
        return size == capacity;  
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
