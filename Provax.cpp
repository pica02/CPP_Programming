/* Deve essere possibile scrivere o leggere ogni persona su/da una stringa che ne codifica le sue caratteristiche
Deve essere possibile scrivere i dati delle persone su file e rileggerli da file */
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class PersonBase {
 public:
  virtual std::string ToString() const = 0;
  virtual bool ToFile(const std::string& filename) const = 0;
  // virtual void FromString(const std::string& in_string) = 0;
  // virtual bool FromFile(const std::string& filename) = 0;
  virtual ~PersonBase() { }

  // FACTORY DA FARE
  // Definition of the factory Method, DESIGN PATTERN.
  static PersonBase* Build(const std::string& def);
};

class Person : public PersonBase {
 protected:
  std::string name;
  std::string citizenship;
 public:
  Person(const std::string& name_, const std::string& citizenship_) :
      name(name_), citizenship(citizenship_) { }
  const std::string& GetName() const { return name; }
  const std::string& GetCitizenship() const { return citizenship; }
  virtual std::string ToString() const {
    // std::ostringstream os;
    // os << name << "\t" << citizenship;
    // return os.str();
    return name + "\t" + citizenship;
  }

  virtual bool ToFile(const std::string& filename) const {
    std::ofstream of(filename);
    if (!of.good())  return false;
    of << this->ToString();
    return true;
  }
  virtual ~Person() { }
};

class Student : public Person {
 protected:
  std::string faculty;
  std::string course;
 public:
  Student(const std::string& name_, const std::string& citizenship_,
          const std::string& faculty_, const std::string& course_) :
      Person(name_, citizenship_), faculty(faculty_), course(course_) { }
  const std::string& GetFaculty() const { return faculty; }
  const std::string& GetCourse() const { return course; }
  std::string ToString() const {
    return "STUDENT " + Person::ToString() + "\t" + faculty + "\t" + course;
  }
  virtual ~Student() { }
};

class Researcher : public Person {
 protected:
  std::string research_topics;
 public:
  Researcher(const std::string& name_, const std::string& citizenship_,
             const std::string& research_topics_) :
      Person(name_, citizenship_), research_topics(research_topics_) { }
  const std::string& ResearchTopics() const { return research_topics; }
  virtual std::string ToString() const {
    return "RESEARCHER " + Person::ToString() + "\t" + research_topics;
  }
  virtual ~Researcher() { }
};

class Professor : public Researcher {
 protected:
  std::string courses;
 public:
  Professor(const std::string& name_, const std::string& citizenship_,
            const std::string& research_topics_,
            const std::string& courses_) :
      Researcher(name_, citizenship_,research_topics_), courses(courses_) { }
  const std::string& GetCourses() const { return courses; }
  virtual std::string ToString() const {
    return "PROFESSOR " + Person::ToString() + "\t" + research_topics + "\t" + courses;
  }
  virtual ~Professor() { }
};

std::ostream& operator<<(std::ostream& os, const PersonBase& p) {
  os << p.ToString();
  return os;
}

// FACTORY DA FARE
PersonBase* PersonBase::Build(const std::string& def) { .. }

/* DA FARE
   Definire una classe che definisce un Dipartimento come un
   insieme di Persone (usa std::vector) */
class Department {
 private:
  // Vector of pointers to base class, can store different types: Student, Researcher, etc.
  std::vector<PersonBase*> people;
 public:
  Department() { }
  // Trasferimento ownership: prendi possesso del puntatore.
  void Add(PersonBase* person) { ... }
  ~Department() { ... }

  class ConstIterator { ... };
  friend class ConstIterator;
};

// LETTURA DEL DIPARTIMENTO
std::istream& operator>>(std::istream& is, Department& dip) {
  std::string line;
  while (getline(is, line)) {
    PersonBase* person = PersonBase::Build(line);
    dip.Add(person);
  }
  return is;
}

int main(int argc, char** argv) {
  Department dip;

  // Inserimento con cast esplicito a PersonBase.
  PersonBase* person1 = new Researcher("Mario_Rossi", "SanMarino", "Informatica");
  dip.Add(person1);
  dip.Add(new Student("Carlo_Rossi", "Italia", "Fisica"));
  dip.Add(new Student("Maria_Bianchi", "Svizzera", "Matematica"));
  dip.Add(new Teacher("Stefano_Melacci", "Italia", "Ingegneria", "PPS"));

  std::cout << dip;

  // Scrivi il dipartimento su file.
  std::ofstream of("department.txt");
  of << dip;
  of.close();

  // Leggi il dipartimento da file
  Department dip1;
  std::ifstream is("department.txt");
  is >> dip1;
  std::cout << "\nRead Department from file\n" << dip1;

  Department::ConstIterator iter(dip1);
  // DA FARE
  // USO ITERATORE

  return 0;
}