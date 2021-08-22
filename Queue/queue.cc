

#include <iostream>
#include <stdlib.h>
#include "queue.h"

using namespace std;

Queue::Queue() {

}

Queue::Queue(int size) {
    data = (float*)malloc(sizeof(float) * size);
    maxsize = size;
    front = 0;
    back = 0;   

}

void Queue::enqueue(float val) {
    data[back % maxsize] = val;
    back++;   
}

float Queue::dequeue() {
    front++;
    return data[(front - 1) % maxsize];
}

bool Queue::isFull() {
    return (back == maxsize);
}

bool Queue::isEmpty() {
    return (front < 0 || front > back);
}

 
