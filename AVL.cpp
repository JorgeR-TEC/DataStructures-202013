#include <iostream>
using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo<T> *izq;
	Nodo<T> *der;
	
	Nodo(){
		value=NULL;
		izq=NULL;
		der=NULL;
	}
	
	Nodo(T val){
		value=val;
		izq=NULL;
		der=NULL;
	}
};

template <class T>
class BST{
	public:
	Nodo<T> *root;
	
	BST(){
		root=NULL;
	}
	
	int altura(Nodo<T> *temp){
		if(temp==NULL){
			
			return -1;
		}
		int alturaIzquierda=altura(temp->izq);
		int alturaDerecha=altura(temp->der);
		int alt= alturaIzquierda>alturaDerecha? alturaIzquierda+1:alturaDerecha+1;
		return alt;
	}
	
	int calcularFE(Nodo<T> *temp){
		if(temp==NULL){
			return 0;
		}
		return altura(temp->der)-(altura(temp->izq));
	}
	
	void insertar(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(root==NULL){
			root=nuevo;
		}else{
			root=insertar(nuevo, root);
		}
	}
	
	Nodo<T> *rotacionDerecha(Nodo<T> *X){
		Nodo<T> *Y=X->izq;
		X->izq=Y->der;
		Y->der=X;
		return Y;
	}
	
	Nodo<T> *rotacionIzquierda(Nodo<T> *X){
		Nodo<T> *Y=X->der;
		X->der=Y->izq;
		Y->izq=X;
		return Y;
	}
	
	Nodo<T> *balance(Nodo<T> *temp){
		int FE=calcularFE(temp);
		if(FE>1){//Necesitamos Rotación Izquierda, esta cargado a la derecha
			int FEY=calcularFE(temp->der);
			if(FEY<0){
				temp->der=rotacionDerecha(temp->der);
			}
			temp=rotacionIzquierda(temp);
		}else if (FE<-1){//Necesitamos Rotación Dereha, ya que esta cargado a la izquierda
			int FEY=calcularFE(temp->izq);
			if(FEY>0){
				temp->izq=rotacionIzquierda(temp->izq);
			}
			temp=rotacionDerecha(temp);
		}
		return temp;
	}
	
	Nodo<T> *insertar(Nodo<T> *nuevo, Nodo<T> *temp){
		if(temp==NULL){
				return nuevo;
		}else if(nuevo->value<temp->value){//si el valor es menor que el valor de temp
			temp->izq=insertar(nuevo, temp->izq);
		}else{//si el valor es mayor que el valor de temp
			temp->der=insertar(nuevo, temp->der);
		}
		temp=balance(temp);
		return temp;
	}
	
	void inorder(){
		inorder(root);
		cout<<endl;
	}

	
	void inorder(Nodo<T> *temp){
		if(temp!=NULL){
			inorder(temp->izq);
			cout<<temp->value<<" ";
			inorder(temp->der);
		}
	}
	
	void preorder(){
		preorder(root);
		cout<<endl;
	}

	
	void preorder(Nodo<T> *temp){
		if(temp!=NULL){
			cout<<temp->value<<" ";
			inorder(temp->izq);
			inorder(temp->der);
		}
	}
	
	bool buscarIterativo(T value){
		Nodo<T> *temp=root;
		while(temp!=NULL){
			if(temp->value==value){
				return true;
			}else if(value<temp->value){
				temp=temp->izq;
			}else{
				temp=temp->der;
			}
		}
		return false;
	}
	
	bool buscarRecursivo(T value){
		if(root==NULL){
			return false;
		}else{
			return buscarRecursivo(value, root);
		}
	}
	
	bool buscarRecursivo(T value, Nodo<T> *temp){
		if(temp==NULL){
			return false;
		}else if(temp->value==value){
			return true;
		}else if(value<temp->value){
			return buscarRecursivo(value, temp->izq);
		}else{
			return buscarRecursivo(value, temp->der);
		}
	}
	
	void eliminar(T value){
		if(root==NULL){
			return;
		}else{
			root=eliminar(value, root);
		}
	}
	
	Nodo<T> *eliminar(T value, Nodo<T> *temp){
		if(temp==NULL){
			return NULL;
		}else if(value<temp->value){
			temp->izq=eliminar(value, temp->izq);
		}else if(value>temp->value){
			temp->der=eliminar(value, temp->der);
		}else{//Si el valor es igual
			if(temp->izq==NULL && temp->der==NULL){//el nodo es una hoja
				delete temp;
				return NULL;
			}else if(temp->izq!=NULL &&temp->der==NULL){//temp tiene hijo izquierdo pero no derecho
				Nodo<T> *regresar=temp->izq;
				delete temp;
				temp=regresar;
			}else if(temp->izq==NULL &&temp->der!=NULL){
				Nodo<T> *regresar=temp->der;
				delete temp;
				temp=regresar;
			}else{//el nodo a borrar tiene 2 hijos
				Nodo<T> *sucesor=temp->der;
				while(sucesor->izq!=NULL){
					sucesor=sucesor->izq;
				}
				temp->value=sucesor->value;
				temp->der=eliminar(temp->value, temp->der);
			}
		}
		temp=balance(temp);
		return temp;
	}

};
	 

	
int main(){
	BST<int> tree;
	tree.insertar(10);
	tree.insertar(35);
	tree.insertar(15);
	tree.insertar(100);
	tree.insertar(30);
	tree.insertar(20);
	tree.preorder();
	tree.eliminar(100);
	tree.insertar(1);
	tree.preorder();
	return 0;
}

