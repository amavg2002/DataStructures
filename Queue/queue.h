#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
  public:
  Queue();
  Queue(int size);
  /* implement copy constructor, assignment, destructor if needed */
  void enqueue(float value);
  float dequeue();
  bool isFull();
  bool isEmpty();

  private:
  /* declare your data */
  float* data;
  int maxsize;
  int front;
  int back;
};


#endif
