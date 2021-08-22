#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "queue.h"
#include "timer.c"

using namespace std;

int main(int argc, char* argv[]) {
    
    int n, t;
    float x;
    if(argc != 3) {
        cout << "Error: Incorrect number of arguments\n";
	return 1;
    } else {
	n = atoi(argv[1]);
	t = atoi(argv[2]);
    }
   
    //Create empty queue
    Queue q = Queue(n);

    //Enqueue n random numbers into queue
    for(int i = 0; i < n; i++) {
	q.enqueue((float)rand());
    }
    
    //Timer setup
    stopwatch_init();
    struct stopwatch_t* timer = stopwatch_create();

    long double timeSum = 0;
    //Dequeue x, enqueue x t times
    for(int i = 0; i < t; i++) {
	stopwatch_start(timer);
	x = q.dequeue();
	q.enqueue(x);
	timeSum += stopwatch_stop(timer);
    }
    long double timeAverage = timeSum / t;
    printf("Average Time: %Lg seconds \n", timeAverage); 
    return 0;
}






