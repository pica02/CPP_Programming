/* Realizzare un software per gestire le macchine di un noleggio.
Il software riceve messaggi di aggiornamento della posizione che
specificano l’identificativo della macchina, il tempo attuale, oltre che
la sua posizione come posizione relativa [x,y], assumendo che la
terra sia localmente piatta).
a) calcolare la distanza percorsa da ogni macchina;
b) ritornare le macchine ordinate per km percorsi;
c) Fornire un iteratore per scandire le macchine in ordine di
chilometri percorsi.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Car{
    public:
	  double km;
	  int id;
	  int xIniziale;
	  int yIniziale;
	  int T_Start;
	  bool Start_Pos = false;
	public:
		Car(const int& id_):
			id(id_), km(0);
		const double& GetKm(){ return km; }
		const int& GetId() { return id; }
		void RefPosition(int x, int y, int T_Now){
			if(!T_Start){
				Start_Pos = true;
				xIniziale = x;
				yIniziale = y;
				T_Start = T_Now;
			}
			else{
				int delta_x = x - xIniziale;
				int delta_y = y - yIniziale;
				double Distanza_Percorsa = sqrt((delta_x)^2 + (delta_y)^2);
				double km += Distanza_Percorsa;
				xIniziale = x;
				yIniziale = y;
			}
			bool operator<(Car& other_cars) const{
				return km > other_cars.km;
			}
		}
};

class RentCar{
	private:
		vector<Car> cars;
	public:
		vector<Car> cars::iterator begin() {
			return cars.begin();
		}
		vector<Car> cars::iterator end(){
			return cars.end();
		}
		
		void AggiornaPosCar(int id, int x, int y, T_Now){
			auto it = find_if(cars.begin(), cars.end(), [id](Car* car)){
				return Car.GetId();
			}
			if(it != cars.end){
				it->RefPosition(int x, int y, int T_Now);
			}
			else{
				Car* newCar(id);
				newCar.RefPosition(int x, int y, int T_Now);
				cars.push_back(newCar);
			}
		}
		void StampaCarKmCresc(){
			sort(cars.begin(), cars.end())
				for(const auto& car : cars){
					cout << "Macchina: " << car.GetId() << ", ha percorso: " << car.GetKm() << endl;
				}
			}
};