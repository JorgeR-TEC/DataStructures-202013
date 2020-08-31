#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Sort{
	public:
	virtual void sort(vector<T> &data)=0;
	void intercambiar(vector<T> &data, int posI, int posJ){
		T temp=data[posI];
		data[posI]=data[posJ];
		data[posJ]=temp;
	}
	
	void imprimir(vector<T> data){
		for(int i=0; i<data.size(); i++){
			cout<<data[i]<<",";
		}
		cout<<endl;
	}
};

template <class T>
class LuckySort: public Sort<T>{
	public:
	void sort(vector<T> &data){
		this->intercambiar(data, 0, data.size()-1);
	}
};

template <class T>
class SelectionSort: public Sort<T>{
	public:
	void sort(vector<T> &data){
		for(int i=0; i<data.size()-1; i++){
			int m=i;
			for(int j=i+1; j<data.size(); j++){
				if(data[j]<data[m]){
					m=j;
				}
			}
			this->intercambiar(data, i, m);
		}
	}
};

template <class T>
class BubbleSort: public Sort<T>{
	public:
	void sort(vector<T> &data){
		for(int i=0; i<data.size()-1; i++){
			for(int j=0; j<data.size()-1-i; j++){
				if(data[j]>data[j+1]){
					this->intercambiar(data, j, j+1);
				}
			}
		}
	}
};

/*int f(int copia, int *apuntador, int &referencia){
	copia++;
	(*apuntador)++;
	referencia++;
	cout<<"dentro de funcion copia: "<<copia<<endl;
	cout<<"dentro de funcion apuntador: "<<*apuntador<<endl;
	cout<<"dentro de funcion referencia: "<<referencia<<endl;
}*/

int main(){
	
	/*int a=10;
	int b=11;
	int c=12;
	int *d=&b;
	f(a, d, c);
	cout<<"fuera de funcion"<<endl;
	cout<<"copia: "<<a<<endl;
	cout<<"apuntador: "<<b<<endl;
	cout<<"referencia: "<<c<<endl;*/
	//LuckySort<int> s;
	//SelectionSort<int> s;
	BubbleSort<int> s;
	vector<int> data={7,5,3,2,1};
	s.sort(data);
	s.imprimir(data);
	return 0;
}