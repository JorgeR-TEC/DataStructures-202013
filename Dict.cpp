#include <iostream>
#include <list>

using namespace std;

template <class K, class V>
class Pair{
	public:
	K key;
	V value;
	Pair(){
		key=NULL;
		value=NULL;
	}
	
	Pair(K k, V v){
		key=k;
		value=v;
	}
};

template <class K, class V>
class Dictionary{
	public:
	list<Pair<K,V>> *data;
	int size;
	
	Dictionary(){
		size=100;
		data= new list<Pair<K,V>>[size];
	}
	
	Dictionary(int s){
		size=s;
		data= new list<Pair<K,V>>[size];
	}
	
	void insert(K key, V value){
		int pos=key%size;
		//for(Pair<K,V> elemento: data[pos])
		for(auto i=data[pos].begin(); i!=data[pos].end(); i++){
			if(i->key==key){
				i->value=value;
				return;
			}	
		}
		Pair<K,V> nuevo(key, value);
		data[pos].push_back(nuevo);
		return;
	}	
	
	
	void insert(K key, V value, int hash(K llave)){
		int pos=hash(key)%size;
		//cout<<pos<<endl;
		//for(Pair<K,V> elemento: data[pos])
		for(auto i=data[pos].begin(); i!=data[pos].end(); i++){
			if(i->key==key){
				i->value=value;
				return;
			}	
		}
		Pair<K,V> nuevo(key, value);
		data[pos].push_back(nuevo);
		return;
	}
	
	bool buscar(K key){
		int pos=key%size;
		for(Pair<K,V> elemento: data[pos]){
			if(elemento.key==key){
				return true;
			}
		}
		return false;
	}

	void print(){
		for(int i=0; i<size; i++){
			for(Pair<K,V> elemento:data[i]){
				cout<<elemento.key<<":"<<elemento.value<<endl;
			}
		}
	}
};


int hashString(string key){
	return key.length();
}

int main(){
	Dictionary<int, string> d;
	d.insert(300, "a");
	d.insert(400, "b");
	d.insert(400, "a");
	d.insert(15623, "c");
	Dictionary<string, int> calificaciones;
	calificaciones.insert("Juan", 95, hashString);
	calificaciones.print();
	
	return 0;
}