#include <iostream>
#include <unordered_map>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	bool visited;
	unordered_map<Nodo<T> *, int> siguientes;
	
	Nodo(T val){
		value=val;
		visited=false;
	}
	
	void agregarArcoDirigidoConPeso(Nodo<T> *sig, int peso){
		if(siguientes.find(sig)==siguientes.end()){
			siguientes[sig]=peso;
		}
	}
	
	void agregarArcoDirigido(Nodo<T> *sig){
		agregarArcoDirigidoConPeso(sig, 1);
	}
	
	void imprimirNodo(){
			cout<<value<<":";
			for(auto nodoSiguiente:siguientes){
				cout<<nodoSiguiente.first->value<<","<<nodoSiguiente.second<<";";
			}
			cout<<endl;
	}
	
	/*bool conexion(Nodo<T> *nodo){
	}
	
	void modificarPeso(Nodo<T> *nodo, nuevoPeso){
	}*/
};


template <class T>
class Graph{
	public:
	unordered_map<T, Nodo<T> *> nodos;
	
	void agregarNodo(T value){
		if(nodos.find(value)==nodos.end()){
			Nodo<T> *nuevo=new Nodo<T>(value);
			nodos[value]=nuevo;
		}
	}
	
	void agregarArcoDirigidoConPeso(T nodo1, T nodo2, int peso){
		if(nodos.find(nodo1)!=nodos.end() && nodos.find(nodo2)!=nodos.end()){
			nodos[nodo1]->agregarArcoDirigidoConPeso(nodos[nodo2], peso);
		}			
	}
	
	void agregarArcoDirigido(T nodo1, T nodo2){
		agregarArcoDirigidoConPeso(nodo1, nodo2, 1);
	}
	
	void agregarArcoConPeso(T nodo1, T nodo2, int peso){
		agregarArcoDirigidoConPeso(nodo1, nodo2, peso);
		agregarArcoDirigidoConPeso(nodo2, nodo1, peso);
	}
	
	void agregarArco(T nodo1, T nodo2){
		agregarArcoConPeso(nodo1, nodo2, 1);
	}
	
	void imprimirGrafo(){
		for(auto parValorNodo: nodos){
			parValorNodo.second->imprimirNodo();
		}
	}
	
	unordered_map<string, int> ordenarPorDia(){
		unordered_map<string, int> a;
		//llenar el mapa
		return a;
	}
	
	/*void modificar(T nodo1, T nodo2, int nuevoPeso){
		//Encontrar que existan
		//buscar si existe el arco nodo1-nodo2 y modificarlo
	}*/
	
	bool BFS(T v1, T v2){
		
	}
};

int main(){
	Graph<string> g;
	g.agregarNodo("CDMX");
	g.agregarNodo("Tlaxcala");
	g.agregarNodo("Puebla");
	g.agregarNodo("Toluca");
	g.agregarArcoDirigidoConPeso("CDMX", "Tlaxcala", 50);
	g.agregarArcoConPeso("CDMX", "CDMX", 20);
	g.agregarArcoConPeso("CDMX", "Puebla", 100);
	g.agregarArco("Puebla", "Puebla");
	g.imprimirGrafo();
	
}