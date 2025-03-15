/* Marco ama molto il vino e vuole realizzare una classe per gestire la lista di vini da lui
posseduti memorizzandoli per nome, produttore ed anno. Deve essere possibile:
• leggere i vini da file
• aggiungere o rimuovere un vino
• cercare un vino dato il suo nome
• ottenere in modo efficiente la lista di vini ordinata per produttore */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

class Wine{
	private:
		string name;
		string winemaker;
		int year;
	 public:
	 	Wine(){ }
	 	Wine(const string& name_, const string& winemaker_, const int& year_):
	 		name(name_), winemaker(winemaker_), year(year_) { }
	 	inline string GetName() const{ return name; }
	 	inline string GetWineMaker() const { return winemaker; }
	 	inline int GetYear() const{ return year; }
};

class WineCollection{
	private:
		vector<Wine*> wines;
	public:
		WineCollection(){}
		void ReadByFile(const string& nameFile){
			ifstream file(nameFile);
			if(!file){
				cerr << "Error\n";
				return;
			}
			string name, winemaker;
			int year;
			while(file >> name >> winemaker >> year){
				wines.emplace_back(name, winemaker, year);
				
			}
			file.close();	
		}
		void DeleteWine(const string& wine_name){
			for(auto it = wines.begin(); it != wines.end(); ++it){
				if((*it)->GetName==wine_name){
					delete *it;
					wine.erase(it);
					return;
				}
			}
		}
		void AddWine(Wine* w){
			wines.push_back(w);
		}
		bool SearchWine(const string& name){
			for(const auto& w : wines){
				if(w.GetName()==name)
				return true;
			}
			return false;
		}
		void SortWineMaker(const string& maker){
			vector<Wine*> copiaVini = wines;
			sort(copiaVini.begin(), copiaVini.end()[](const Wine* w1, const Wine* w2)){
				return w1.GetWineMaker() < w2.GetWineMaker()
			}
			for(const auto& w : wines){
				cout << "Wine Maker: " << maker << "; Name: " << name  << "; Year: " << year << endl;
			}
		}		
};