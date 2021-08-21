#include "dlist.h"
#include <iostream>
using std::cout; using std::cin;
///////////////////////////// ListNode STRUCT CONSTRUCTOR: /////////////////////////

ListNode::ListNode(const int & data, ListNode *previous, ListNode *nxt):val(data),next(nxt),prev(previous)
{}


/////////////////////////////////// DOUBLY LIST MEMBER FUNCTIONS: ////////////////////


////////////////default constructor: ///////////////////////
/* Initializes the list to be empty */
DList::DList():head(NULL),tail(NULL),m_size(0)
{}


////////////////////Copy Constructor: ////////////////////
/* Initializes the list as a copy of an existing one */
 DList::DList(const DList & List):m_size(List.m_size)
{
	if(this!=&List)//not duplicated list
	{
		if(List.m_size==0)
			head=tail=NULL;
		else
		{
			head=tail=new ListNode(List.tail->val,NULL,NULL);
			for(ListNode * p=List.tail->prev;p!=NULL;p=p->prev)
			{
				head=head->prev=new ListNode(p->val,NULL,head);
			}
		}
	}

}

/////////////////////////////// Assignment Operator: ////////////////////
DList & DList::operator=(const DList & List)
{
	if(this!=&List)
	{
		destroy();
		if(List.m_size!=0)//if list is not empty add elements
		{
			head=tail=new ListNode(List.tail->val,NULL,NULL);
			for(ListNode * p= List.tail->prev;p!=NULL;p=p->prev)
			{
				head=head->prev=new ListNode(p->val,NULL,head);
			}
			m_size=List.m_size;
		}
		else// if list empty
		{
			head=tail=NULL;
		}
	}
	return *this;
}


//Destructor
DList::~DList()
{
    if(!isEmpty())
        destroy();
}
 

void DList::add_to_front(int value)
{
	if(m_size==0)
	{
		head=tail=new ListNode(value,NULL,NULL);
		++m_size;
	}
	else{
		head=head->prev=new ListNode(value,NULL,head);
		++m_size;
	}
}


void DList::add_to_back(int value)
{
	if(m_size==0)
	{
		tail=head=new ListNode(value,NULL,NULL);	
		++m_size;
	}
	else
	{
		tail=tail->next=new ListNode(value,tail,NULL);
		++m_size;
	}
}


int DList::first()
{
	int value;
	if(m_size==0)
	{
		throw EmptyException();
	}
	value=head->val;
	return value;

}

int DList::last()
{
	int value;
	if(m_size==0)
		throw EmptyException();
	if(tail)
		value=tail->val;
	return value;
}


void DList::remove(ListNode* node)
{
	if(head&&tail)
	{
		if(m_size>0)
		{
			if(node->prev!=NULL)//if  element is not head
			{
				if(node->next==NULL)//if next element is tail 
				{
					tail = node->prev;//move tail to previous element
					node->prev->next = NULL; //previous element next pointer shoud be null
					delete node;//delete element
					--m_size;
				}
				else //if element is not tail and not head (body of list)
				{
					node->prev->next=node->next;//previous element  next pointer now points to the element after node
					node->next->prev = node->prev;//next element previous pointer now points to element before given node
					delete node;//delete the  given node 
					--m_size;
				}
			}
			else//if element is head
			{

				if(node->next!=NULL)//if  next element is not tail we at the beginning
				{
					head = node->next;
					node->next->prev=NULL;
					delete node;//delete the node
					--m_size;
				}
				else//if next element is tail (we only have one element in the list to delete)
				{
					head = tail = NULL;
					delete node;
					--m_size;
				}				
			}
		}
	}
}

ListNode * DList::previous(ListNode * node)
{
	if(head&&tail)
	{
		if(m_size>0)
		{
			ListNode * current=node->prev;
			return current;
		}
	}
	return NULL;
}

ListNode * DList:: next(ListNode * node)
{
	if(head&&tail)
	{
		if(m_size>0)
		{
			ListNode * current=node->next;
			return current;
		}
	}
	return NULL;
}

//returns the node that contains the value otherwise return NULL
ListNode * DList::search_value(int value)
{
	if(head&&tail)
	{
		if(m_size>0)
		{
			ListNode * current=head;
			while(current!=NULL)
			{
				if(current->val==value)//found your node
					return current;
				current=current->next;
			}
		}
	}
	return NULL;
}


   //This function helps delete nodes
  void DList::destroy()
  {
  	if(head&&tail)
  	{
  		ListNode * current=head;
  		while(current!=NULL)
  		{
  			ListNode * temp=current;
  			current=current->next;
  			delete temp;
  		}
  	}
  	m_size=0;
  }

  unsigned int DList::size() 
  {
  	return m_size;
  }

  bool DList::isEmpty() 
  {
  	return m_size==0;
  }


  ////////////////////////////////////////////
  void DList::printlist()
  {
  	 ListNode * current= head;
  	 while(current)
  	 {
  	 	std::cout<<" -------------------- "<<std::endl;
  	 	if(current->prev){
  	 		std::cout<<"| Prev:   "<<current->prev<<" |"<<std::endl;
  	 	}
  	 	else{
  	 		std::cout<<"| Prev:  NULL    |"<<std::endl;
  	 	}

  	 	std::cout<<"|  val:   "<<current->val<<"        |"<<std::endl;

  	 	if(current->next){
   	 		std::cout<<"| Next:   "<<current->next<<" |"<<std::endl;
  	 	}
  	 	else{
  	 		std::cout<<"| Next:  NULL    |"<<std::endl;
  	 	}
  	 	if(current->next)
  	 	{
  	 		std::cout<<" -------------------- "<<std::endl;
	  	 	std::cout<<"          |  "<<std::endl;
	  	 	std::cout<<"          |  "<<std::endl;
	  	 	std::cout<<"          V  "<<std::endl;
	  	 }
	  	 else
	  	 {
	  	 	std::cout<<" -------------------- "<<std::endl;
	  	 }
  	 	current=current->next;
  	 }
  }
