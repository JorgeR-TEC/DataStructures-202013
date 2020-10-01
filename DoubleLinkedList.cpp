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
class DoubleLinkedList{
	public:
	Nodo<T> *head;
	Nodo<T> *tail;
	
	DoubleLinkedList(){
		head=NULL;
		tail=head;
	}
	
	void append(Nodo<T> *nuevo){
		if(head==NULL){
			head=nuevo;
			tail=nuevo;
		}else{
			tail->next=nuevo;
			nuevo->prev=tail;
			tail=nuevo;
		}
	}
	
	void append(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		append(nuevo);
	}
	
	void insert(Nodo<T> *nuevo, int pos){
		if(head==NULL){
			head=nuevo;
			tail=nuevo;
		}else if(pos==0){
			nuevo->next=head;
			head->prev=nuevo;
			head=nuevo;
		}else{
			Nodo<T> *temp=head;
			int i=0;
			while(temp!=NULL && i<pos){
				temp=temp->next;
				i++;
			}
			if(temp==NULL){
				tail->next=nuevo;
				nuevo->prev=tail;
				tail=nuevo;
			}else{
				nuevo->next=temp;
				nuevo->prev=temp->prev;
				//temp->prev=nuevo;
				//nuevo->prev->next=nuevo;
				temp->prev->next=nuevo;
				temp->prev=nuevo;
				
			}
		}
	}
	
	void duplicar(){
		Nodo<T> *temp=head;
		while(temp!=NULL){
			Nodo<T> *sig=temp->next;
			Nodo<T> *nuevo=new Nodo<T>(temp->value);
			nuevo->next=sig;
			nuevo->prev=temp;
			temp->next=nuevo;
			if(sig!=NULL){
				sig->prev=nuevo;
			}else{
				tail=nuevo;
			}
			temp=sig;
		}
	}
	
	void remove(T value){
		Nodo<T> *temp=head;
		while(temp!=NULL){
			if(temp->value==value){
				if(temp->prev==NULL){
					head=temp->next;
				}else{
					temp->prev->next=temp->next;
				}
				if(temp->next==NULL){
					tail=temp->prev;
				}else{
					temp->next->prev=temp->prev;
				}
				delete temp;
				return;
			}
			temp=temp->next;
		}
		
	}
	
	void insert(T value, int pos){
		Nodo<T> *nuevo=new Nodo<T>(value);
		insert(nuevo, pos);
	}
	
	void print(){
		Nodo<T> *temp=head;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}	
		cout<<endl;
	}
};

int main(){
	DoubleLinkedList<int> ll;
	ll.append(10);
	ll.append(7);
	ll.append(3);
	ll.print();
	ll.insert(15, 0);
	ll.print();
	ll.insert(30, 1000);
	ll.print();
	ll.insert(12, 1);
	ll.print();
	ll.print();
	ll.remove(10);
	ll.print();
	ll.remove(15);
	ll.print();
	ll.remove(30);
	ll.print();
	return 0;
}