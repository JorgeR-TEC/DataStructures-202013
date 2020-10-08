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
class Stack{
	public:
	Nodo<T> *top;
	
	Stack(){
		top=NULL;
	}
	
	void push(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(top==NULL){
			top=nuevo;
		}else{
			nuevo->next=top;
			top->prev=nuevo;
			top=nuevo;
		}
	}
	
	T check(){
		if(top!=NULL){
			return top->value;
		}else{
			return NULL;
		}
	}
	
	void pop(){
		if(top!=NULL){
			Nodo<T> *aBorrar=top;
			top=top->next;
			top->prev=NULL;
			delete aBorrar;
		}
	}
	
	void print(){
		Nodo<T> *temp=top;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}
		cout<<endl;
		
	}
};

int main(){
	Stack<int> s;
	s.push(30);
	s.push(20);
	s.push(10);
	cout<<s.check()<<endl;
	s.print();
	s.pop();
	s.print();
}
