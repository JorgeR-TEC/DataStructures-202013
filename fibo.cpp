#include <iostream>

using namespace std;

long cantidad=0;
long fibRecursivo(int n){
	//cantidad++;
	if(n<=1){
		return 1;
	}else{
		return fibRecursivo(n-1)+fibRecursivo(n-2);
	}
}

long fibIterativo(long n){
	long a=0;
	long b=1;
	for(int i=0; i<n; i++){
		//cantidad++;
		long temp=a;
		a=b;
		b=temp+a; 
	}
	return b;
}

long fibAux(int n, long a,long b){
	//cantidad++;
	if(n<=1){
		return a+b;
	}else{
		return fibAux(n-1, b, a+b);
	}
} 

long fibRecursivo2(int n){
	return fibAux(n, 0, 1);
}

int main(int argc, char* argv[]){
	if(argc!=3){
		cout<<"Uso: ./<nombre> <tipo> <n>"<<endl;
		cout<<"1. Recursivo 2.Recursivo O(n) 3. Iterativo"<<endl;
		return 1;
	}
	int opcion=atoi(argv[1]);
	int n=atoi(argv[2]);
	if(opcion==1){
		cout<<"Valor: "<<fibRecursivo(n);
		//cout", cantidad:"<<cantidad;
		cout<<endl;
	}else if (opcion==2){
		cout<<"Valor: "<<fibRecursivo2(n);
		//cout", cantidad:"<<cantidad;
		cout<<endl;
	}else if(opcion==3){
		cout<<"Valor: "<<fibIterativo(n);
		//cout", cantidad:"<<cantidad;
		cout<<endl;
	}
	return 0;
}