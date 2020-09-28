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
	
	T getElementAt(int pos){
		Nodo<T> *temp=root;
		int i=0;
		while(temp!=NULL && i<pos){
			temp=temp->next;
			i++;
		}
		if(i==pos && temp!=NULL){
			return temp->value;
		}else{
			return NULL;
		}
	}
	
	void setElementAt(int pos, T value){
		Nodo<T> *temp=root;
		int i=0;
		while(temp!=NULL && i<pos){
			temp=temp->next;
			i++;
		}
		if(i==pos && temp!=NULL){
			 temp->value=value;
		}
	}
	
	
	void insert(Nodo<T> *nuevo, int pos){
		if(root==NULL){
			root=nuevo;
		}else if(pos==0){
			nuevo->next=root;
			root=nuevo;
		}else{
			Nodo<T> *temp=root;
			int i=0;
			while(temp->next!=NULL && i<pos-1){
				temp=temp->next;
				i++;
			}
			nuevo->next=temp->next;
			temp->next=nuevo;
		}
	}
	
	void insert(T value, int pos){
		Nodo<T> *nuevo=new Nodo<T>(value);
		insert(nuevo, pos);
	}
	
	void remove(T value){
		if(root==NULL){
			return;
		}else if(root->value==value){
			Nodo<T> *aBorrar=root;
			root=root->next;
			delete aBorrar;
		}else{
			Nodo<T> *temp=root;
			while(temp->next!=NULL){
				//cout<<temp->value<<endl;
				if(temp->next->value==value){
					Nodo<T> *aBorrar=temp->next;
					//temp->next=temp->next->next
					temp->next=aBorrar->next;
					delete aBorrar;
					return;
				}
				temp=temp->next;
			}
		}
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
	list.append(20);
	list.print();
	list.insert(4, 0);
	list.print();
	list.insert(10, 3);
	list.print();
	list.insert(30, 1000);
	list.print();
	list.remove(4);
	list.print();
	list.remove(30);
	list.print();
	list.remove(7);
	list.print();
}