#include <iostream>
#include <vector>

using namespace std;

int a=10;

int factorial1(int n){
	if(n==0){
		return 1;
	}else{
		return n*factorial1(n-1);
	}
}

int factorial2(int n, int resultado){
	if(n==0){
		return resultado;
	}else{
		return factorial2(n-1, n*resultado);
	}
}

int factorial(int n){
	return factorial2(n, 1);
}

int mcd(int m, int n){
	int r=m%n;
	cout<<"M: "<<m<<" N: "<<n<<endl;
	if(r==0){
		return n;
	}else{
		return mcd(n, r);
	}
}

int sumaVectorAux(vector<int> a, int resultado, int posicion){
	if(posicion==a.size()){//base
		return resultado;
	}else{//recursivo
		return sumaVectorAux(a, resultado+a[posicion], posicion+1);
	}
}

int sumaVector(vector<int> a){
	return sumaVectorAux(a, 0,0);
}

int main(){
	/*int array1[5]={1,2,3,4,5};
	/int *array2=new int[5];
	/vector<int> a;
	a.push_back(10)
	a.push_back(20);*/
	//int b=5;
	//cout<<mcd(1500, 1376)<<endl;
	vector<int> a={1,1,1,1,1};
	cout<<sumaVector(a)<<endl;
}