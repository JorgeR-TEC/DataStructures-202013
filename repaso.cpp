#include <iostream>

using namespace std;


template <class T>
class Ejemplo{
	public: 
		T a;
		
		void imprimirValor(){
			cout<<a<<endl;
		}
		
		void sumar(T a, T b){
			T c=a+b;
			cout<<c<<endl;
		}
	
};

template <class T>//Faltaba indicar que Herencia tiene un template y el tipo de template de Ejemplo
class Herencia: public Ejemplo<T>{

};

void imprimirString(string name){
	cout<<name<<endl;
}

int main(){
	int a=1;//declaracion y definicion
	float b=2.0;
	double c=2.0;
	char d='a';
	string e="hola mundo";
	imprimirString(e);
	Ejemplo<int> f;
	f.a=5;
	f.imprimirValor();
	f.sumar(5,3);
	Ejemplo<string> g;
	g.a="perro";
	g.imprimirValor();
	return 0;
}