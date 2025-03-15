#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class PersonBase{
	public:
		virtual string ToString() const = 0;
		virtual bool ToFile(const string& filename) const = 0;
		virtual ~PersonBase() {	};
		static PersonBase Build(const string& def);
};

class Person : public PersonBase{
	protected:
		string name;
		string citizenship;
	public:
		Person(){ };
		Person(const string& name_,
		 const string& citizenship_) :
		 	name(name_), citizenship(citizenship_)
		const string& GetName(){ return name; }
		const string& GetCitizenship() { return citizenship; }
		virtual string ToString () const {
			return name + "/t" + citizenship;
		}
		virtual bool ToFile(const string& filename) const{
			ofstream of(filename);
			if(!of.good()) return false;
			of << this->ToString();
			return true;
		}
		virtual ~Person() {	}
};

class Student: public Person{
	protected:
		string faculty;
		string course;
	public:
		Student(){}
		Student(const string& name_, const string& citizenship_,
		        const string& faculty_, const string& course_):
		        Person(name_, citizenship_), faculty(faculty_), course(course_);
		const string& GetFaculty(){ return faculty;	}
		const string& GetCourse() { return course;	}
		virtual string ToString() const{
			return "Student" + Person::ToString() + "/t" + faculty + "/t" + course;
		}
		virtual ~Student() { }
};

class Researcher: public Person{
	protected:
		string research_topics;
	public:
		Researcher(){ }
		Researcher(const string& name_, const string& citizenship_,
				   const string& research_topics) : 
				   Person(name_, citizenship_), research_topics(research_topics_);
		const string& GetResearchTopics(){ return research_topics;	}
		virtual string ToString(){
			return "Researcher" + Person::ToString() + "/t" research_topics;
		}
		virtual ~Researcher(){ }
};

class Professor: public Researcher{
	protected:
		string courses;
	public:
		Professor(){ }
		Professor(const string& name_, const string& citizenship,
	               const string& research_topics, const string& courses_):
	             Researcher(name_, citizenship_, research_topics_), courses(courses_);
	    const string& GetCourses(){ return courses;	}
	    virtual string ToString(){
	    	return "Professor" + Person::ToString() + "/t" + research_topics + "/t" + courses;
		}
		virtual ~Professor(){ }
};


ostream& operator<<(ostream& os, const PersonBase& p){
	os << p.ToString();
	return os;
}



PersonBase* PersonBase::Build(const string& def){
}
 
//Da implementare la scorsa funzione.

class Department{
	private:
		vector<PersonBase*> people;
	public:
		Department();
		void Add(PersonBase* person){	}
		~Department(){. . .}
		class ConstIterator{. . .};
		friend class ConstIterator;
};

istream& operator>>(istream& is, Department& dip){
	string line;
	while(getline(is, line)){
		PersonBase* person = PersonBase::Build(line);
		dip.Add(person);
		
	}
	return is;
}

int main(int argc, char** argv){
	Department dip;
	PersonBase* person1 = new Researcher("Chiara Massaro", "Faicchio", "Ingegneria Gestionale");
	dip.Add(person1);
	dip.Add(new student("Simone Dominici", "Palermo", "Ostetricia"));
	dip.Add(new student("Ciccio Palma", "Grisì", "Meccanica"))
	dip.Add(new student("Alessandro Riggio", "Monteriggioni", "Infermieristica"));
	
	
	cout << dip;
	
	ofstream of(department.txt);
	of << dip;
	of.close();
	
	Departmend dip1;
	istream is(department.txt);
	is >> dip1;
	cout << "/nRead Department from file/n" << dip1;
	Department::ConstIterator(dip1);
	return 0;
}



























