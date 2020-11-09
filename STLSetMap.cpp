#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <vector>

using namespace std;
int main(){
	/*set<int> tree;
	tree.insert(50);
	tree.insert(20);
	tree.insert(70);
	tree.insert(10);
	tree.insert(30);
	tree.insert(60);
	tree.insert(80);

	for(auto it=tree.begin(); it!=tree.end(); it++){
		cout<<*it<<endl;
	}
	for(int v:tree){
		cout<<v<<endl;
	}*/
	
	map<int, vector<string>> calificaciones;
	
	calificaciones[100].push_back("lorena");
	calificaciones[70].push_back("juan");
	calificaciones[85].push_back("ana");
	calificaciones[100].push_back("alonso");
	for(auto it=calificaciones.rbegin(); it!=calificaciones.rend(); it++){
		cout<<it->first<<":";
		for(string persona:calificaciones[it->first]){
			cout<<persona<<",";
		}
		cout<<endl;
	}
	
	
	
}