#include <iostream>
#include <list>
using namespace std;

class Set{
	public:
	list<int> *data;
	int size;
	
	Set(){
		size=100;
		data=new list<int>[size];
	}
	
	Set(int s){
		size=s;
		data=new list<int>[size];
	}
	
	int hash(int value){
		return value%size;
	}
	
	void insert(int value){
		int pos=hash(value);
		for(int val:data[pos]){
			if(val==value){
				return;
			}
		}
		data[pos].push_back(value);
	}
	
	bool find(int value){
		int pos=hash(value);
		for(int val:data[pos]){
			if(val==value){
				return true;
			}
		}
		return false;
	}
	
	void print(){
		for(int i=0; i<size; i++){
			cout<<"["<<i<<"]: ";
			/*Nodo<T> *temp=data[i].root;
			while(temp!=NULL){
				cout<<temp->value<<",";
				temp=temp->next;
			}¨*/
			for(auto j=data[i].begin(); j!=data[i].end(); j++){
				cout<<*j<<",";
			}
			cout<<endl;
		}
	}
};

int main(){
	Set s(9);
	s.insert(5);
	s.insert(15);
	s.insert(3);
	s.insert(3);
	s.print();
	cout<<s.find(3)<<endl;
	cout<<s.find(12)<<endl;
	return 0;
}