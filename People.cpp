/*Definire una classe Person che memorizzi nome, cognome, indirizzo, data di nascita
di una persona. Realizzare anche gli operator<<, operator>> e operator==
2. Definire una classe People per la gestione di un gruppo di N persone modellate
con la classe Person, deve essere possibile accedere o modificare i dati delle singole
persone e ritornare chi sia la persona più giovane e quella più anziana del gruppo.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
	private:
		string name;
		string surname;
		string address;
		string birth_date;
	public:
		Person(){ }
		Person(const string& name_, const string& surname_,
		       const string& address_, const int& birth_date_):
		       	name(name_), surname(surname_), address(address_), birth_date(birth_date_){  }
	    
		string GetName() const {
	    	return name;
		}
		
		string GetSurname() const{
			return surname;
		}
		
		string GetAddress() const{
			return address;
		}
		
		string GetBirthday() const{
		    return birth_date;	
		}
		
		friend ostream& operator<<(ostream& os, Person& p){
			os << "Name:" << p.name << endl;
			os << "Surname: " << p.surname << endl;
			os << "Address: " << p.address << endl;
			os << "Birthday: " << p.birth_date << endl;
			return os;
		}
		
	    friend istream& operator>>(istream& is, Person& p){
	    	cout << "Enter the name: " << endl;
	        is >> p.name;
	        cout << "Enter the surname: " << endl;
	        is >> p.surname;
	        cout << "Enter the address: " << endl;
	        is >> p.address;
	        cout << "Enter the birthday: " << endl;
	        is >> p.birth_date;
	        return is;
		}
		
		bool operator==(Person* p1){
			return (name == p1.name) && (surname == p1.surname) && (address==p1.address) && (birth_date==p1.birth_date);
		}
};

class People : public Person{
	private:
		vector<Person*> people;
	public:
		People(){ }
		
		void AddPeople(Person* p){
			people.push_back(p);
		}
		
		void GetPerson(int index){
			return people[index];
		}
		
		Person& operator[](int index){
			return people[index];
		}
		
		int GetSize() const{
			return people.size();
		}
		
		Person& GetYounger(){
			auto it = min_elem(people.begin(), people.end(), [](Person* p1, Person* p2)){
				return p1.GetBirthday < p2.GetBirthday;
			}
			return *it;
		}
		
		Person& GetOldest(){
			auto it = max_elem(people.begin(), people.end(), [](const Person* p1, const Person* p2)){
				return p1.GetBirthday < p2.GetBirthday;
			}
			return *it;
		}
};