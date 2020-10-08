#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo<T> *next;
	Nodo<T> *prev;
	
	Nodo(T val){
		value=val;
		next=NULL;
		prev=NULL;
	}
};

template <class T>
class Queue{
	public:
	Nodo<T> *front;
	Nodo<T> *back;
	
	Queue(){
		front=NULL;
		back=NULL;
	}
	
	void enqueue(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(back==NULL){
			back=nuevo;
			front=back;
		}else{
			back->next=nuevo;
			nuevo->prev=back;
			back=nuevo;
		}
	}
	
	void dequeue(){
		if(front!=NULL){
			Nodo<T> *aBorrar=front;
			if(front==back){
				front=NULL;
				back=NULL;
			}else{
				front=front->next;
				front->prev=NULL;
			}
			delete aBorrar;
		}
	}
	
	T check(){
		if(front!=NULL){
			return front->value;
		}else{
			return NULL;
		}
	}
	
	void print(){
		Nodo<T> *temp=front;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}
		cout<<endl;
		
	}
	
};

int main(){
	Queue<int> q;
	int a=q.check();
	if(a!=0){
		cout<<a<<endl;
	}
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.print();
	q.dequeue();
	q.print();
	return 0;

}