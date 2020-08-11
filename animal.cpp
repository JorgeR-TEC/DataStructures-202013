#include <iostream>

using namespace std;

class Animal{
	public:
		bool pico;
		bool cola;
		string nombre;
		string especie;
		int patas;
		bool alas;
		string color;
		string sonido;
		float peso;
		
	void hacerSonido(){
		cout<<sonido<<endl;
	}
};

class Perro: public Animal{
	public:
	Perro(){
		pico=false;
		cola=true;
		nombre="perro";
		especie="canis";
		patas=4;
		sonido="guau";
	}
};

class Gato: public Animal{
	public:
	Gato(){
		pico=false;
		cola=true;
		nombre="gato";
		especie="felino";
		patas=4;
		sonido="miau";
	}
};

template <class T>
class Veterinario{
	public:
	void inyectar(T mascota){
		mascota.hacerSonido();
	}
};

int main(){
	Perro piquis;
	Gato malfoy;
	Veterinario<Perro> ale;
	ale.inyectar(piquis);
	ale.inyectar(malfoy);
	return 0;
}