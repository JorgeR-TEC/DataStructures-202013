#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;
int busquedaSecuencial(vector<int> a, int buscado){
	for(int i=0; i<a.size(); i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

int busquedaOrdenada1(vector<int> a, int buscado){
	for(int i=0; i<a.size(); i++){
		if(a[i]>buscado){
			return -1;
		}
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

int busquedaOrdenada2Aux(vector<int> a, int buscado, int inicio, int fin, int paso){
	//cout<<inicio<<","<<fin<<endl;
	if(fin>a.size()){
		fin=a.size();
	}
	if(a[fin-1]>=buscado){
		for(int i=inicio; i<fin; i++){
			if(a[i]==buscado){
				return i;
			}
		}
		return -1;
	}else{
		return busquedaOrdenada2Aux(a, buscado, fin, fin+paso, paso);
	}
}

int busquedaBinariaAux(vector<int> a, int buscado, int inicio, int fin){
	if(fin<inicio){
		return -1;
	}
	int medio=(inicio+fin)/2;
	if(a[medio]==buscado){
		return medio;
	}else if(buscado>a[medio]){
		return busquedaBinariaAux(a, buscado, medio+1, fin);
	}else{
		return busquedaBinariaAux(a, buscado, inicio, medio-1);
	}
}

int busquedaBinaria(vector<int> a, int buscado){
	if(buscado>a[a.size()-1]|| buscado<a[0]){
		return -1;
	}else{
		return busquedaBinariaAux(a, buscado, 0, a.size()-1);
	}
}

int busquedaOrdenada2(vector<int> a, int buscado){
	int paso=10000;
	return busquedaOrdenada2Aux(a, buscado, 0, paso, paso);
}


int main(){
	vector<int> a;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,10000000);
	for(int i=0; i<1000000; i++){
		a.push_back(distribution(generator));
	}
	int buscado=a[0];
	sort(a.begin(), a.end());
	int x;
	
	auto inicio=high_resolution_clock::now();
	x=busquedaSecuencial(a,buscado);
	auto fin=high_resolution_clock::now();
	auto tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;
	//Busqueda Ordenada 1
	cout<<"Ordenada 1"<<endl;
	inicio=high_resolution_clock::now();
	x=busquedaOrdenada1(a,buscado);
	fin=high_resolution_clock::now();
	tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;
	/*cout<<"Ordenada 2"<<endl;
	inicio=high_resolution_clock::now();
	x=busquedaOrdenada2(a,buscado);
	fin=high_resolution_clock::now();
	tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;*/
	cout<<"Binario"<<endl;
	inicio=high_resolution_clock::now();
	x=busquedaBinaria(a,buscado);
	fin=high_resolution_clock::now();
	tiempo=duration_cast<microseconds>(fin - inicio).count();
	cout<<"posicion: "<<x<<", tiempo: "<<tiempo<<endl;
	return 0;
}