#ifndef DLIST_H
#define DLIST_H
#include <iostream>


class EmptyException{};

struct ListNode 
{
  /* define your list node type */
  int val;
  ListNode* next;
  ListNode* prev;
  //Constructor for the node struct
  ListNode(const int & data,ListNode * previous,ListNode *nxt);
};

class DList
{
  public:
  DList();
  DList(const DList & List); //copy constructor
  ~DList();//Destructor
  DList & operator=(const DList & List);//assignment
  void add_to_front(int value);
  void add_to_back(int value);
  int first();// first() returns the value at the start of the list. 
  int last();// last() returns the value at the end of the list. 
  void remove(ListNode* node);
  bool isEmpty();//returns true if list has no values in it, otherwise false
  unsigned int size();//returns the number of values in the list
  ListNode* previous(ListNode* node);//returns the node that is previous to given node
  ListNode* next(ListNode* node);//returns the node that is next to given node
  ListNode* search_value(int value);//returns the node that contains the value
  void printlist();//print list
  private:
  /* declare your data */

  ListNode* head;//points to the first node of the list
  ListNode* tail;//points to the last node of the list
  unsigned int m_size;//hods the size of the list
  void destroy();//This function helps delete nodes
};

#endif
