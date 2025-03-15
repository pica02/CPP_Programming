#include <iostream>
using namespace std;

class Integer{
	private:
		int i;
		friend Integer& operator++(Integer& a);
	public:
		Integer(int j) { i= j; }
		inline int Get() const { return i; }
};

Integer& operator++(Integer& a){
	a.i++;
	return a;
}

int main(){
	Integer a(5);
	cout << a.Get() << "\n";
	cout << (++a).Get() << "\n";
}