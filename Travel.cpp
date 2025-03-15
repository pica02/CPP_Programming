/*Un'agenzia di viaggi desidera realizzare del software per gestire i viaggi effettuati dai suoi clienti.
 Ogni viaggio si compone di luogo di partenza, luogo di destinazione, date partenza e ritorno, ed i nomi dei viaggiatori.
  Il software deve permettere di:
- caricare da file i dati relativi ai viaggi;
- cercare in modo efficiente i viaggi con una certa destinazione;
Realizzare un iteratore che permetta di scandire i viaggi.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Travel{
	private:
		string departure, arrival;
		int date_dep, date_ret;
		vector<string> travellers;
	public:
		Travel(const string& departure_, const string& arrival_,
		       const int& date_dep_, const int& date_ret_, const vector<string>& travellers_):
		       	departure(departure_), arrival(arrival_), date_dep(date_dep_), date_ret(date_ret_), travellers(travellers_){}
		
		inline string GetDeparture(){ return departure;	}
		
		inline string GetArrival() { return arrival; }
		
		inline int GetDateDep(){ return date_dep; }
		
		inline int GetDateRet(){ return date_ret; }
		
		inline vector<string> GetName(){ return travellers; }
};


class VectorTravel: public Travel{
	private:
		vector<Travel*> travels;
	public:
		VectorTravel(){}
		bool FromFile(const string& file) const{
			ifstream is(file);
			if(!is.is_open()){
				cerr << "Error\n";
				return false;
			}
			string dep, arr;
			int date_dep, date_ret;
			vector<string> travellers;
			while(is >> dep >> arr >> date_dep >> date_ret >> travellers;){
			    Travel* t1 = new Travel(dep, arr, date_dep, date_ret, travellers);
			    travels.push_back(t1);
		    }
		    return true;
		}
		
		void SeachTravel(const string& trav) const{
			cout << "Travel with this destination: " << trav << "\n";
			for(auto travel: travels){
				if(travel->GetName() == trav){
					cout << "Place of departure: " << travel->GetDeparture() << ",";
					cout << "Place of arrival: " << travel->GetArrival() << ",";
					cout << "Date of Departure: " << travel->GetDateDep() << ",";
					cout << "Date of Return: " << travel->GetDateRet() << ",";
					cout << "Travellers: " << travel->GetName() << endl;
				}
			}
		}
};