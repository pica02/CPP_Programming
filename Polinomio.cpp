 #include <iostream>  //std::cout
#include <cmath>  //sqrt

class Polinomyous{
	private:
		float a;
		float b;
		float c;
	public:
		Polinomyous();
		Polinomyous(const float a_, const float b_, const float c_){
			a = a_;
			b = b_;
			c = c_;
		}
		float Calcola(const float x){
		      return a * x * x + b * x + c;
	    }
	    
	    void Radici(float* radice_1, float* radice_2){
	    	float delta = b * b - 4 * a * c;
	    	if(delta >= 0 && a != 0.0){
			    *radice_1 = (-b + sqrt(delta))/(2 * a);
			    *radice_2 = (-b - sqrt(delta))/(2 * a);
			    *valid_1 = true;
			    *valid_2 = false;
		    }
		    else if(a == 0 && b != 0){
		    	*radice_1 = -c / b;
		    	*valid_1 = true;
		    	*valid_2 = false;
			}
		    else if(b == 0.0){
		    	*valid_1 = false;
				*valid_2 = false; 
			}
			else{
				std::cout << "Error Radici non calcolabili"
				*valid_1 = false;
				*valid_2 = false; 
			}
		}
};

int main(){
	Polinomyous p(4.0, 3.0, 1);
	
	const float y = p.Calcola(1.0);
	
	float r1 = 0.0;
	float r2 = 0.0;
	p.Radici(&r1, &r2, &valid_1, &valid_2);
	
	if(valid_1){
		std::cout << "Radice 1" << radice_1;
	}
	
	std::cout << "Radice 1:" << r1 << "\nRadice 2: " << r2;
	return 0;
}