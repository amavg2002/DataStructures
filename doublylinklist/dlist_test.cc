#include <iostream>
#include <string>
#include <assert.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"
#include "timer.c"

using namespace std;

void emptywhenDefaultConstructed();
void sizeIsZerowhenDefaultconstructed();
void whenAddingToStart_SizeIncreases();
void afterAddingAValue_ListIsNoLongerEmpty();
void whileAddingValues_FirstAndLastAreCorrect();
void whenRemovingValues_SizeDecreases();
void whenRemovingValues_ListIsEmptyAfterRemovingLast();
void whenRemovingValues_FirstAndLastAreCorrect();
void  cannotObtainFirstElementFromEmptyList();
void cannotObtainLastElementFromEmptyList();
void  listsCanBeCopyConstructed_WithSeparateContents();
void listsCanBeCopyAssigned_WithSeparateContents();
int main(int argc, char* argv[]);
void Test_Cases();

int main(int argc, char * argv[])
{
    //Test_Cases();
    int N=-1;
    int randnumber=-1;
    ListNode * temp=NULL;
    cin >> N;
    assert(N > 0);
   /* if(argc==2)
    {
        N=atoi(argv[1]);
        assert(N>0);
    }
    else
    {
        cerr<<"usage: "<<argv[0]<<" <n>"<<endl;
        cerr<<"where <n> is the length of the list."<<endl;
        return -1;
    }*/
	//initialize clock
	stopwatch_init();
	struct stopwatch_t* timer = stopwatch_create(); assert(timer);
    
	DList list;//empty list
    //adding 'n' integers [1,2,...,n] to  list:
    for (int i = 1; i <= N; ++i) 
    {
        list.add_to_front(i);
        assert(list.size()==(i));
    }
    //cout << "PRINTING LIST" << endl;
    //list.printlist();
    //cout << endl;
    //char a=getchar();
	
	std::srand(5353);//set initial seed value to N(upperbound)
    for(int i=1;i<=N;++i)
    {
        randnumber=std::rand()%N;
     //   cout<<"Randnumber= "<<randnumber<<endl;
	    stopwatch_start(timer);
        temp=list.search_value(randnumber);
        if(temp)
        {
            list.remove(temp);
            long double t_qs=stopwatch_stop(timer);
			printf("Remove: %Lg seconds ==> %Lg million keys per second\n",t_qs,1e-6*N/t_qs);
            //assert(list.size()==N-i);
			//cout << "PRINT LIST: " << endl;
            //list.printlist();
            //getchar();
            list.add_to_front(randnumber);
        }
    }
    //cout << "\n\nfinal list: " << endl;
    //list.printlist();
    stopwatch_destroy(timer);
    return 0;
}

void Test_Cases()
{
   	//test cases:
     cannotObtainLastElementFromEmptyList();
     cannotObtainFirstElementFromEmptyList(); 
     listsCanBeCopyConstructed_WithSeparateContents();
     emptywhenDefaultConstructed();
     sizeIsZerowhenDefaultconstructed();
     whenAddingToStart_SizeIncreases();
     afterAddingAValue_ListIsNoLongerEmpty();
     whileAddingValues_FirstAndLastAreCorrect();
     listsCanBeCopyAssigned_WithSeparateContents();
     whenRemovingValues_SizeDecreases();
     whenRemovingValues_ListIsEmptyAfterRemovingLast();
     whenRemovingValues_FirstAndLastAreCorrect();
		   
}

void emptywhenDefaultConstructed()
{
    DList list;
    assert(list.isEmpty()==true);
    //list.printlist();
    cout<<"PASS TEST emptywhenDefaultConstructed"<<endl;
}
void sizeIsZerowhenDefaultconstructed()
{
    DList list;
    assert(list.size()==0);
    cout<<"PASS TEST sizeIsZerowhenDefaultconstructed"<<endl;
}
void whenAddingToStart_SizeIncreases()
{	
	DList list;
    for (unsigned int i = 1; i <= 10000; ++i)
    {
        list.add_to_front(i * 5);
        assert(list.size()==(i));
    }
    cout<<"PASS TEST whenAddingToStart_SizeIncreases "<<endl;
}

void afterAddingAValue_ListIsNoLongerEmpty()
{
    DList list;
    list.add_to_front(10);
    assert(list.isEmpty()==false);
    cout<<"PASS TEST ListIsNoLongerEmpty"<<endl;

}

void whileAddingValues_FirstAndLastAreCorrect()
{
    DList list;
    list.add_to_front(10);
    assert( list.first()==10);
    assert(list.last()==10);

    list.add_to_front(20);
    assert(list.first()==20);
    assert(list.last()==10);

    list.add_to_back(30);
    assert(list.first()==20);
    assert(list.last()==30);
    cout<<"PASS TEST  whileAddingValues_FirstAndLastAreCorrect"<<endl;
}
void whenRemovingValues_SizeDecreases()
{
    DList list;
    for (unsigned int i = 1; i <= 100; ++i)
    {
        list.add_to_front(i*2);
    }

     //list.printlist();
     int number;
    for (unsigned int i = 100; i >= 1; --i)
    {
        ListNode * vals = list.search_value(i*2);
        if (vals)
        {
            //number = vals->val;
            list.remove(vals);
            assert( list.size()==i-1);
            //list.add_to_front(number);

        }

        // std::cout<<"number : "<<i-1<<std::endl;
       // assert( list.size()==i-1);
    }

   // list.add_to_front(200);
    //list.add_to_front(300);

   // list.printlist();
       cout<<"PASS TEST  whenRemovingValues_SizeDecreases"<<endl;
}
void whenRemovingValues_ListIsEmptyAfterRemovingLast()
{
   	DList list;

    for (unsigned int i = 1; i <= 10000; ++i)
    {
        list.add_to_back(i);
    }
     //list.printlist();
    for (unsigned int i = 10000; i > 0; --i)
    {
        assert(!list.isEmpty());
        list.remove(list.search_value(i));
    }

    assert(list.isEmpty()==true);
    cout<<"PASS TEST  whenRemovingValues_ListIsEmptyAfterRemovingLast"<<endl;
}
void whenRemovingValues_FirstAndLastAreCorrect()
{
    DList list;
    list.add_to_back(10);
    list.add_to_back(20);
    list.add_to_back(30);
    list.add_to_back(40);
    //cout<<"List 1: "<<endl<<endl;
     //list.printlist();
    list.remove(list.search_value(10));
    //cout<<"List 1A: "<<endl<<endl;
    //list.printlist();
    assert(list.first()==20);
    assert(list.last()==40);
    
    list.remove(list.search_value(40));
    //cout<<"List 1B: "<<endl<<endl;
    //list.printlist();
    assert(list.first()==20);
    //cout<<"list.last= "<<list.last()<<endl<<endl;
    assert(list.last()==30);

   list.remove(list.search_value(20));
    //cout<<"List 1C: "<<endl<<endl;
    //list.printlist();
    assert(list.first()==30);
    //cout<<"list.last= "<<list.last()<<endl<<endl;
    assert(list.last()==30);

    cout<<"PASS TEST whenRemovingValues_FirstAndLastAreCorrect"<<endl;
}
void  cannotObtainFirstElementFromEmptyList()
{
    DList list;
	try{ list.first();}
	catch(EmptyException)
	{
		//cerr << "Empty List Exception\n";
		cout<<"PASS TEST cannotObtainLastElementFromEmptyList"<<endl;
	}
}
void cannotObtainLastElementFromEmptyList()
{
    DList list;
	try{ list.last();}
	catch(EmptyException)
	{
		//cerr << "Empty List Exception\n";
		cout<<"PASS TEST cannotObtainLastElementFromEmptyList"<<endl;
	}
}

void  listsCanBeCopyConstructed_WithSeparateContents()
{
    DList list1;
    list1.add_to_back(10);
    list1.add_to_back(20);
    list1.add_to_back(30);
    list1.add_to_back(40);

    DList list2 (list1);

    
    assert(list2.size()==4);
    assert(list2.first()==10);
    assert(list2.last()==40);
    /*cout<<"LIST 1: "<<endl;
    list1.printlist();
    cout<<endl<<endl;
    cout<<"LIST 2: "<<endl;
    list2.printlist();
    cout<<endl<<endl;*/
    ListNode * tmp=list2.search_value(10);
    if(tmp!=NULL)
    {
    	//cout<<"removing top element: "<<tmp->val<<endl;
    	list2.remove(tmp); //remove function needs work
    }
    else
    {
    	cout<<"could not remove top element"<<endl;
    }

    /*cout<<"LIST 2: "<<endl;
    list2.printlist();
    cout<<endl<<endl;*/

    assert(list1.size()==4);
    assert(list1.first()==10);

    assert(list2.size()==3);
    assert(list2.first()==20);

    cout<<"PAsS TEST listsCanBeCopyConstructed_WithSeparateContents"<<endl;
}
void listsCanBeCopyAssigned_WithSeparateContents()
{
    DList list1;
    list1.add_to_back(10);
    list1.add_to_back(20);
    list1.add_to_back(30);
    list1.add_to_back(40);

    DList list2;
    list2.add_to_back(5);
    list2.add_to_back(15);
    list2.add_to_back(25);

    list1 = list2;
    /*cout<<"LIST 1: "<<endl;
    list1.printlist();
    cout<<endl<<endl;
    cout<<"LIST 2: "<<endl;
    list2.printlist();
    cout<<endl<<endl;*/
    assert(list1.size()==3);
    assert(list1.first()==5);
    assert(list1.last()==25);

    list1.remove(list1.search_value(5)); 
    /*cout<<"LIST 1: "<<endl;
    list1.printlist();
    cout<<endl<<endl;
    cout<<"LIST 2: "<<endl;
    list2.printlist();
    cout<<endl<<endl;*/
    assert(list1.size()==2);
    assert(list1.first()==15);

    assert(list2.size()==3);
    assert(list2.first()==5);	
    cout<<"Pass TEST listsCanBeCopyAssigned_WithSeparateContents"<<endl;
}
