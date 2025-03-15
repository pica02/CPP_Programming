#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

enum Seme {CUORI, PICCHE, QUADRI, FIORI}
class Card{
	private:
		Seme seme;
		string nome;
	public:
		Card(seme s, string n) : seme(s), nome(n) {};
		Seme Get_Seme() const { return seme; }
		string Get_Nome() const { return nome; }

		
};

class Deck{
	private:
		Card* card;
	public:
		Deck(){
			for(int seme = CUORI; seme <= PICCHE; ++i){
				for(int i = 0; i <= 13; ++i){
					string nome;
					switch(i):
						case 1 : nome = "Asso"; break;
						case 11 : nome = "Jack"; break;
						case 12 : nome = "Regina"; break;
						case 13: nome = "Re";
						 
				}
			}
		}
		
};