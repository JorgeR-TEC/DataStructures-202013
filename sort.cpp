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

template <class T>
class InsertionSort: public Sort<T>{
	public:
	void sort(vector<T> &data){
		for(int i=1; i<data.size(); i++){
			for(int j=i; j>0; j--){
				if(data[j]<data[j-1]){
					this->intercambiar(data, j, j-1);
				}else{
					break;
				}
			}			
		}
	}
};

template <class T>
class MergeSort: public Sort<T>{
	
	public:
	void sort(vector<T> &data){
		sortAux(data, 0, data.size()-1);
	}
	private:
	void sortAux(vector<T> &data, int lo, int hi){
		if(lo>=hi){
			return;
		}
		int mid=(lo+hi)/2;
		sortAux(data, lo, mid);
		sortAux(data, mid+1, hi);
		merge(data, lo, mid, hi);
	}
	
	
	
	void merge(vector<T> &data, int low, int mid, int hi){
	int sizeA=mid-low+1;
	int sizeB=hi-mid;
	vector<T> copiaA;
	vector<T> copiaB;
	
	for(int i=0; i<sizeA; i++){
		copiaA.push_back(data[low+i]);
	}
	
	for(int i=0; i<sizeB; i++){
		copiaB.push_back(data[mid+i+1]);
	}
	
	int indexA=0;
	int indexB=0;
	int indexData=low;
	while(indexA<sizeA&&indexB<sizeB){
		if(copiaA[indexA]<copiaB[indexB]){
			data[indexData]=copiaA[indexA];
			indexA++;
		}else{
			data[indexData]=copiaB[indexB];
			indexB++;
		}
		indexData++;
	}
	
	while(indexA<sizeA){
		data[indexData]=copiaA[indexA];
		indexA++;
		indexData++;
	}
	
	while(indexB<sizeB){
		data[indexData]=copiaB[indexB];
		indexB++;
		indexData++;
	}
}
	
};


template <class T>
class QuickSort: public Sort<T>{
	public:
	void sort(vector<T> &data){
		sortAux(data, 0, data.size()-1);
	}
	
	void sortAux(vector<T> &data, int low, int hi){
		if(low>=hi){
			return;
		}
		int j=partition(data, low, hi);//poner pivote en su lugar
		sortAux(data, low, j-1);//lado izquierdo
		sortAux(data, j+1, hi);//lado derecho
		
	}
	
	int partition(vector<T> &data, int low, int hi){
		int pivote=low;
		int i=low+1;
		int j=hi;
		while(true){
			while(data[i]<=data[pivote]&& i<hi){
				i++;
			}
			while(data[j]>data[pivote]&& j>low){
				j--;
			}
			if (i>=j){
				break;
			}else{
				this->intercambiar(data, i, j);
			}
		}
		this->intercambiar(data, pivote, j);
		return j;
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
	QuickSort<int> s;
	vector<int> data={7,5,3,5,1};
	s.sort(data);
	s.imprimir(data);
	return 0;
}