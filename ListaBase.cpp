/* Si implementi una classe Lista (con templates, senza usare la classe STL di libreria) che
permetta le operazioni di:
? Aggiunta elemento in posizione N
? Eliminazione di tutti gli elementi (metodo Clear())
b) Spiegare se si ritiene necessario fornire un copy costructor e operator= per la classe Lista
c) Fornire un unittest per la classe realizzata. */

#include <iostream>
using namespace std;

class Lista{
	private:
	  struct Nodo{
		  int valore;
		  Nodo* successivo;
		
		  Nodo(const int& val): valore(val), successivo(nullptr);
	  }
	  Nodo* testa;
	public:
		Lista(): testa(nullptr){ }
		void Add(const int& elemento, int posizione){
			Nodo* nuovoNodo = new Nodo(elemento);
			if(testa == nullptr || posizione = 0){
				nuovoNodo->successivo = testa;
				testa = nuovoNodo; 
			}
			else{
				Nodo* nodoCorrente = testa;
				int  count = 1;
				while(nodoCorrente->successivo!=nullptr && count < posizione){
					nodoCorrente->successivo = nodoCorrente->successivo;
					count++
				}
				nodoNuovo->successivo = nodoCorrente->successivo;
				nodoCorrente->successivo = nodoNuovo;
			}
		}
		void Clear(){
			Nodo* nodoCorrente = testa;
			while(nodoCorrente!=nullptr){
				Nodo* nodoNuovo = nodoCorrente->successivo;
				delete nodoCorrente;
				nodoCorrente = nodoNuovo;
			}
		}
		~Lista(){
			Clear();
		}
		
}; 