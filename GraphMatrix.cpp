#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class T>
class Nodo{
	public:
	int id;
	T value;
	
	Nodo(){
		id=0;
	}
	
	Nodo(int id, T value){
		this->id=id;
		this->value=value;
	}
};

template <class T>
class Graph{
	public:
	unordered_map<string,Nodo<T>> nodos;
	vector<vector<int>> matrix;
	int idActual;
	
	Graph(){
		idActual=0;
	}
	
	void agregarNodo(string value){
		if(nodos.find(value)==nodos.end()){
			Nodo<T> nuevo(idActual, value);
			nodos[value]=nuevo;
			vector<int> nuevaFila;
			for(int i=0; i<idActual; i++){
				matrix[i].push_back(0);
				nuevaFila.push_back(0);
			}
			nuevaFila.push_back(0);
			matrix.push_back(nuevaFila);
			idActual++;
		}
	}
	
	void agregarArcoDirigidoPeso(string v1, string v2, int peso){
		if(nodos.find(v1)!=nodos.end() && nodos.find(v2)!=nodos.end()){
			matrix[nodos[v1].id][nodos[v2].id]=peso;
		}
	}
	
	void agregarArcoDirigido(string v1, string v2){
		agregarArcoDirigidoPeso(v1,v2, 1);
	}
	
	void agregarArcoPeso(string v1, string v2, int peso){
		agregarArcoDirigidoPeso(v1, v2, peso);
		agregarArcoDirigidoPeso(v2, v1, peso);
	}
	
	void agregarArco(string v1, string v2){
		agregarArcoPeso(v1, v2, 1);
	}
	
	void imprimirNodos(){
		for(auto nodo: nodos){
			cout<<nodo.first<<endl;
		}
	}
	
	void imprimirMatrix(){
		for(auto fila: matrix){
			for(int valor: fila){
				cout<<valor<<",";
			}
			cout<<endl;
		}
	}
};

int main(){
	Graph<string> ciudades;
	ciudades.agregarNodo("Tlaxcala");
	cout<<"matrix:"<<endl;
	ciudades.imprimirMatrix();
	ciudades.agregarNodo("CDMX");
	cout<<"matrix:"<<endl;
	ciudades.imprimirMatrix();
	ciudades.agregarNodo("Puebla");
	cout<<"matrix:"<<endl;
	ciudades.agregarArco("CDMX", "Puebla");
	ciudades.imprimirMatrix();
	
}



