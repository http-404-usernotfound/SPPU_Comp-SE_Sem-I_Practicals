#include <iostream>
using namespace std;
#define MAX 5

class queue{
	
	int a[MAX],front,rear;
public:
	queue(){
		rear = front = 0;
	}
	
	void add(int);
	int del();
	int isEmpty();
	int peek();
	void display();
};

void queue::add(int j){
	a[rear++] = j;
}

int stack::isEmpty(){
	return rear;
}

void stack::display(){
	for(int i = 0; i < rear; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
		
}

int main(){
	queue q1;
	cout<<q1.isEmpty()<<endl;
	q1.add(9);
	q1.display();
	
	return 0;
}