#include <iostream>

using namespace std;

template <class T>
class Vector{
	public:
	T *data;
	int count;//cantidad de elementos guardados
	int size;//maximo de elementos a poder guardar
	
	Vector(int cantidad){
		size=cantidad;
		data=new T[size]();
		count=0;
	}
	
	
	Vector(){
		size=2;
		data=new T[size]();
		count=0;
	}
	
	void increaseSize(){
		T *temp=new T[size*2]();//crear nuevo arreglo del doble de tamaño
		for(int i=0; i<count; i++){
			temp[i]=data[i];
		}//copiar de data a temp
		delete [] data;//liberamos el espacio de data
		data=temp;//ahora data apunta a temp
		size=size*2;//guardamos que el tamaño es el doble
	}
	
	void append(T value){
		if(count<size){
			data[count]=value;
			count++;
		}else{
			increaseSize();
			append(value);
		}
	}
	
	void insert(T value, int pos){
		if(count>=size){
			increaseSize();
		}
		for(int i=count; i>pos; i--){
			data[i]=data[i-1];
		}
		data[pos]=value;
		count++;
	}
	
	void removeValue(T value){
		for(int i=0; i<count; i++){
			if(data[i]==value){
				for(int j=i; j<count-1; j++){
					data[j]=data[j+1];
				}
				count--;
				break;
			}
		}
	}
	
	
	T leer(int pos){
		return data[pos];
	}
	
	void imprimir(){
		for(int i=0; i<count; i++){
			cout<<data[i]<<",";
		}
		cout<<endl;
	}
	
	~Vector(){
		delete [] data;
	}
	
};



int main(){
	Vector<int> a;
	a.append(1);
	a.imprimir();
	a.append(5);
	a.imprimir();
	a.append(3);
	a.imprimir();
	a.insert(2, 0);
	a.imprimir();
	a.removeValue(3);
	a.imprimir();
	
	/*Vector<int> *b=new Vector<int>(10,2);
	Vector<int> c[10];//a fuerza va el vacio
	a.print(10)
	a.print()*/
	


	
	
}