#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>

using namespace std;

const int MAX = 10000;
double A[MAX][MAX], x[MAX], y[MAX];

// double A[4][4] = {{0 ,1 , 2, 3} , {0,1,2,3} , {0,1,2,3} , {0,1,2,3}};
// double x[4] = {0,1,2,3};
// double y[4] = {0,1,2,4};

void initialice() {
	for(int i = 0; i < MAX ; i++) {
		y[i] = 0;
		x[i] = 1+rand()%(10-1);
		for(int j = 0 ; j < MAX ; j++) A[i][j] = 1+rand()%(101-1);
	}
}


void nestedLoop1() {
    
    for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			y[i] += A[i][j] * x[j];
}

void nestedLoop2() {
    for (int j = 0; j < MAX; j++)
		for (int i = 0; i < MAX; i++)
			y[i] += A[i][j] * x[j];
}


int main() {	
	unsigned t0, t1;
    initialice();
    //nestedLoop1();
    nestedLoop2();
	return 0;
}