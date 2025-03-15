/*Realizzare un software per tradurre un testo. Definire l’interfaccia in una classe base di
un traduttore generico. Definire poi una classe figlia che realizza un traduttore che carica
da file una tabella di traduzione parola -> parola_tradotta e permette la traduzione
di un testo in ingresso, se una parola da tradurre non è compresa nella tabella, stampare
la parola UNKNOWN.*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

class Translator{
	public:
		virtual string translator(const string& word) const = 0;
};

class FileTranslator: public Translator{
	private:
		unordered_map<string, string> translationTable;
	public:
		FileTranslation(const string& def){
			ifstream file(def);
			if(!file){
				cerr << "Error\n";
			}
			string word, translated;
			while(file >> word >> translated){
				translationTable[word] = translated;
			}			
		}
		
		string translator(const string& word) const override{
			auto it = translationTable.find(word);
			if(it != translationTable.end()){
				return it->second;
			} else{
				return "UNKNOWN";
			}
		}
};