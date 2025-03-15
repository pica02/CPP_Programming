/* Una bicicletta si compone di componenti più semplici.
Che a loro volta sono composti da altri componenti più semplici ad esempio:
ruote composte da ruota anteriore e posteriore, cambio composto da cambio anteriore e posteriore, telaio, ecc.
Ogni componente ha un prezzo e la classe bicicletta ha un costo pari alla somma dei singoli componenti. 
Realizzare una bicicletta attraverso il design pattern composite, deve essere possible conoscere il prezzo della bicicletta composta.*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

class BikeComponentBase{
	private:
		string name;
	public:
		BikeComponentBase(const string& name_) : name(name_) {	};
		virtual const string& GetName() const{ return name; }
		virtual float GetWeight() const = 0;
		virtual float GetPrice() const = 0;
		~BikeComponentBase(){ }
};

class BikeComponent : public BikeComponentBase{
	protected:
		float weight;
		float price;
	public:
		BikeComponent(const string& name_, const float& weight_,
		              const float& price_):
		              	BikeComponentBase(name_), weight(weight_), price(price_) {  };
		virtual float& GetWeight(){ return weight; }
		virtual float& GetPrice(){ return price; }
		~BikeComponent(){ }
};

class BikeComposite: public BikeComponentBase{
	protected:
		deque<const BikeComponentBase*> components;
	public:
		BikeComposite(const string& name_): BikeComponentBase(name_) {	};
		void AddComponent(const BikeComponentBase* component){
			components.push_back(component);
		}
		
		virtual float GetPrice() const{
			float price= 0.0f;
			for(unsigned int i = 0; i <= components.size(); ++i){
				price += components[i]->GetPrice();
			}
			return price;
		}
		
		virtual float GetWeight() const{
			float weight = 0.0f;
			for(unsigned int i = 0; i < components.size(); ++i){
				weight += components[i]->GetWeight();
			}
			return weight;
		}
		
		virtual ~BikeComposite(){
			for(unsigned int i = 0; i < components.size(); ++i){
				delete components[i];
			}
		}
};

class Bike : public BikeComposite{
	public:
		Bike() : BikeComposite("bike"){
		//Compongo le ruote;
			BikeComponentBase* front_wheel= new BikeComponent("front_wheel", 200, 0.6);
			BikeComponentBase* rear_wheel=new BikeComponent("rear_wheel", 300, 0.9);
			BikeComponentBase* front_tyre=new BikeComponent("front_tyre", 100, 0.6);
			BikeComponentBase* rear_tyre=new BikeComponent("rear_tyre", 100, 0.6);
			BikeComposite* wheels = new BikeComposite("wheels");
			wheels->AddComponent("front_wheel");
			wheels->AddComponent("rear_wheel");
			wheels->AddComponent("front_tyre");
			wheels->AddComponent("rear_tyre");
		//Compongo il cambio;
		    BikeComponentBase* front_der = new BikeComponent("front_der");
		    BikeComponentBase* rear_der = new BikeComponent("rear_der");
		}
};