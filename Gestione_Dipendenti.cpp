#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <deque>
using namespace std;

class Person{
	private:
		int month = 0;
		float salary = 0.0;
	public:
		Person(const int& month_, const float& salary_):
			month(month_), salary(salary_);{ }
		inline int GetMonth(){ return month; }
		inline float GetSalary(){ return salary; }
		virtual string ToString() const{
			ostringstream os;
			os >> month << " " << salary;
			return os.str();
		}
		//Factory
		static Person* build(const string& file) const;
		virtual ~Person(){ }
};

class Engineer : public Persone{
	private:
		string project;
	public:
		Engineer(const int& month_, const float& salary_, const string& project_):
			Person(month_, salary_), project(project_); {}
		string ToString() const{
			ostringstream os;
			os << "Engineer: " << Person(month_, salary_) << " " << project << endl;
			return os.str();
		}
		virtual ~Engineer(){ }
};

class Administer: public Person{
	private:
		int code;
	public:
		Administer(const int& month_, const float& salary_, const int& code_):
			       Person(month_, salary_), code(code_); {  }
		string ToString() const{
			ostringstream os;
			os << "Administrator: " << Person(month_, salary_) << " " << code;
			return os.str();
		}
		virtual ~Administer(){	}
};

Person* Person::Build(const string& def){
	istream is(def);
	string type;
	is >> type;
	if(type == "Engineer"){
		int month = 0;
		float salary = 0.0;
		string project;
		is >> month >> salary >> project;
		p = new Engineer(month, salary, project);
	}
	else if(type == "Administer"){
		int month = 0;
		float salary = 0.0;
		int code;
		is >> month >> salary >> code;
		p = new Administer(month, salary, code);
	}
	return p;
}

class Company{
	private:
		deque<Person*> people;
	public:
		Company(){ }
		void AddPeople(Person* p){
			for(Person* p : people){
				people.push_back(p);
			}
		}
		
		bool ToFile(const string& file){
			istream is(file);
			if(!is.good()){
				cerr << "File-name uncorrect\n";
				return false
			}
			for(Person* p : people){
				os << p->ToString();
			}
			return true;
		}
		
		void MonthlyCost(Person* p){
			float cost;
			for(Person* p : people){
				cost += p->GetSalary()/p->GetMonth;
			}
			return cost;
		}
		
		
		~Company(){
			for(Person* p : people){
				if(p != nullptr){
					delete p;
				}
			}
		}
};