#include <iostream>
using namespace std;


class Vector{   //codice di partenza
	float* vec = nullptr;
	Vector(const int n){ vec = new float[n]; }
	~Vector() { delete[] vec; }   //Distruttore:   Vector(){if(vector != nullptr) 
	                              //                        delete[] vec; 
								  //                       } 
								  //           Questo per assicurarsi che il vettore
								  //           sia stato allocato per poi distruggerlo
};

int main(){
	
}