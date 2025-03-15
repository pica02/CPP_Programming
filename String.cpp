/* Supponendo che non esista la classe std::string, realizzare una classe String che permetta
di:
? Costruire una stringa a partire da un char*
? Concatenare stringhe tramite operator+
? Svuotare la stringa
? Controllo della dimensione della stringa
? Accedere ad un carattere
? Stampare la stringa su uno stream con operator<<
b) Spiegare se si ritiene necessario fornire un copy costructor e operator= per la classe, se si
ritiene necessario implementarli. */

#include <iostream>
#include <string>
using namespace std;

class String{
	private:
		char* data;
		int size;
	public:
		String(const char* n = ""){
			size = 0;
			while(n[size]!='\0'){
				++size;
			}
			data = new char[size + 1];
			for(int i = 0; i < size; ++i){
				data[i] = n[i];
			} 
			data[size] = '\0';
		}
		inline int GetSize() const{ return size; }
		~String(){ }
};

String operator+(const String& other){
	int newSize = size + other.size;
	char* NewData = new char*[newSize + 1];
	for(int i = 0; i < size; ++i){
		NewData[i] = data[i];
	}
	for(int i = 0; i < other.size; ++i){
		NewData[size + i] = other.data[i];
	}
	NewData[newSize] = '\0';
	
	string result = newData;
	delete[] newData;
	return result;
}

void Clear(){
	delete[] data;
	size = 0;
	data = new char[1];
	data[0] = '\0';
//TI AMO GABRI MIO 
}

char operator[](int index){
	if(index > 0 && index < size){
		return data[index];
	} else{
		return '\0';
	}
}

friend ostream& operator<<(ostream& os, String& str){
	os << str.data;
	return os;
}



