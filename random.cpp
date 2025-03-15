#include <ctime>
#include <cstdlib>
#include <iostream>

class Random{
	private:
		float min_value;
		float max_value;
	public:
		Random();
		Random(const float min_value_, const float max_value_){
			  min_value = min_value_;
			  max_value = max_value;
			  srand(time(NULL));
		    if (max_value < min_value){
			 std::cout << "ERROR Passing interval range.\n";
		   }
		}
		float Rand(){
			float prob = (float)rand() / (float)RAND_MAX;
			return min_value + prob * (max_value - min_value);
		}
};

int main(){
	Random random_gen(0.0, 100.0);  //Costruttore
	for(int i = 0; i < 10; i++){
		std::cout << random_gen.Rand();  //Generazione
	}
	return 0;
}