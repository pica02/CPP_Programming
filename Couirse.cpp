#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Student{
	private:
	    string name;
	    int id = 0;
	public:
		Student(const string& nome_, const int id_) : name(name_), id(id_) { }
		inline const string& GetName() {
			return name;
		}
		inline int GetId() const {
			return id;
		}
		friend ostream& operator<<(ostream& os, Student& s);
		friend istream& operator>>(istream& is, Student& s);
};

ostream& operator<<(ostream& os, Student& s){
	os << s.id << " " << s.name << endl;
	return os;
}


istream& operator>>(istream& is, Student& s){
	is >> s.id;
	getline(is, n.name);
	if(s.name.length() > 1){
			s.name = s.name.substr(1); //prende la sottostringa di nome a partire dal primo carattere, cioè butta via il primo carattere.
	}
	else{
		cerr << "Can not read the name" << endl;
	}
}

class Course{
	private:
		vector<Student> student;
	public:
		Course(const string& filename) { }
		bool Find(const string& name) const;
		bool Find(const int id) const;
		
};

Course::Course(const string& filename){
	istream is(filename);
	if(!is.good()){
		cerr << "Can not open the file" << filename << endl;
		return;
	}
	int num_stud = 0;
	is >> num_stud;
	if(num_stud <= 0){
		cerr << "Nothing\n";
		return;
	}
	stud.reserve(num_stud);
	
	for(int i = 0; i < num_stud; ++i){
		Student s;
		is >> s;
		students.push_back(s);
	}
}

bool Course::Find(const int id) const{
    //Versione 1
	for(const Student& s){
		if(s.GetName == name){
			return true;
		}
		return false;
	}
	
	
	//Versione 2
	/*for(int i = 0; i < student.size[]; ++i){
	    if(students[i].GetName() == name){
	    	return true
		}
		return false;
	*/
}

bool Course::Find(const string& name){
	for(const Student& s){
		if(s.GetId == id){
			
		}
	}
}


int main(){
	Course c("student.txt");
	cout << "Ci sta Mario Rossi?" << c.Find("Mario Rossi") << endl;
	cout << "Ci sta Giorgia Tropilo?" << c.Find("Giorgia Tropilo") << endl;