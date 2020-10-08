#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> interseccion(unordered_set<int> A, unordered_set<int> B){
	unordered_set<int> C;
	for(int value: A){
		if(B.find(value)!=B.end()){
			C.insert(value);
		}
	}
	return C;
}

unordered_set<int> diferencia(unordered_set<int> A, unordered_set<int> B){
	unordered_set<int> C;
	for(int value: A){
		if(B.find(value)==B.end()){
			C.insert(value);
		}
	}
	return C;
}

int main(){
	unordered_set<int> A;
	A.insert(10);
	A.insert(20);
	A.insert(30);
	A.insert(20);
	unordered_set<int> B;
	B.insert(30);
	B.insert(40);
	B.insert(50);
	unordered_set<int> C;
	C=interseccion(A,B);
	for(int val: C){
		cout<<val<<"," ;
	}
	cout<<endl;
	/*hash<int> hi;
	hash<string> hs;
	cout<<hi(10)<<endl;
	cout<<hs("hola")<<endl;*/
	/*if(A.find(30)!=A.end()){
		cout<<"30 encontrado"<<endl;
	}
	unordered_set<int>::iterator pos30=A.find(30);
	cout<<*pos30<<endl;
	
	if(A.find(40)!=A.end()){
		cout<<"40 encontrado"<<endl;
	}else{
		cout<<"40 no encontrado"<<endl;
	}
	for(auto i=A.begin(); i!=A.end(); i++){
		cout<<*i<<",";
	}
	cout<<endl;
	for(int perro: A){
		cout<<perro<<",";
	}
	cout<<endl;*/
	
	return 0;
}