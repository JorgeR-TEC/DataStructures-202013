#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
		T value;
		Nodo<T> *next;
		
		Nodo(T val){
			value=val;
			next=NULL;
		}
};

template <class T>
class LinkedList{
	public:
	Nodo<T> *root;
	
	LinkedList(){
		root=NULL;
	}
	
	void append(Nodo<T> *nuevo){
		if(root==NULL){
			root=nuevo;
		}else{
			Nodo<T> *temp=root;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=nuevo;
		}
	}
	
	void append(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		append(nuevo);
	}
	
	void print(){
		Nodo<T> *temp=root;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int main(){
	LinkedList<int> list;
	//Nodo<int> *nuevo=new Nodo<int>(3);
	//list.append(nuevo);
	list.append(3);
	list.append(5);
	list.append(7);
	list.print();
}