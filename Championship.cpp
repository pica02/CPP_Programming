/* Creare una classe Team che rappresenti una squadra di calcio e abbia come attributi
   il nome della squadra, il numero di partite vinte, il numero di partite perse e il
   numero di partite pareggiate. La classe deve disporre di opportuni metodi per
   impostare o visualizzare gli attributi, un metodo che restituisce quanti punti ha in
   campionato (ogni partita vinta vale 3 punti, ogni partita pareggiata 1, quelle perse
   0) e un metodo per azzerare il numero di partite vinte, pareggiate e perse.
   2. Create una classe Championship che raccoglie un insieme di squadre come al punto
   sopra. Deve essere possibile aggiornare il campionato immettendo il risultato di
   una partita ed aggiornare le statistiche delle due squadre coinvolte nell’incontro.
   Permette di emettere su uno stream lo stato del campionato. Permettere anche si
   rileggere lo stato del campionato da uno stream di input. */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Team{
	private:
		string name;
		int win;
		int lost;
		int equal;
	public:
		Team(const string& name_, const int& win_, const int& lost_, const int& equal_):
			name(name_), win(win_), lost(lost_), equal(equal_);
		inline string GetName() const { return name; }
		inline int GetWin() const{ return win; }
		inline int GetLost() const{ return lost; }
		inline int GetEqual() const{ return equal; }
		void SetName(const string& team_name){
			name = team_name;
		}
		void SetWin(const int& team_win){
			win = team_win;
		}
		void SetLost(const int& lost_team){
			lost = lost_team;
		}
		void SetEqual(const int& equal_team){
			equal = equal_team;
		}
		void GetPoint() const{
			int count;
			count = (win * 3) + (equal);
			return count;
		}
		void Reset(){
			win = 0;
			lost = 0;
			equal = 0;
		}
};

class Championship{
	private:
		vector<Team*> teams;
	public:
		Championship(){	}
		void AddTeam(Team* t){
			teams.push_back(t);
		}
		void UpdateMatchResults(const Team* t1, const Team* t2, int goalTeam1, int goalTeam2){
			for(auto& team : teams){
				if(team.GetName()==t1){
					if(goalTeam1 < goalTeam2){
						team.SetLost(team.GetLost() + 1);
					}
			        else if(goalTeam1 > goalTeam2){
					team.SetWin(team.GetWin() + 1);
				    }
				    else{
					team.SetEqual(team.GetEqual() + 1);
				    }
			    }
			    else if(team.GetName()==t2){
			    	if(goalTeam1 > goalTeam2){
			    		team.SetLost(teamGetLost() + 1);
					} else if(goalTeam1 < goalTeam2){
						team.SetWin(teamGetWin() + 1);
					}else {
						team.SetEqual(team.GetEqual() + 1);
					}
				}
		    }
	    }
	    
	    void PrintChampionshipStatus(const ostream& os) const{
	    	for(auto& team: teams){
	    		os << "Team name: " << team.GetName() << endl;
	    		os << "Match won: " << team.GetWin() << endl;
	    		os << "Match lost: " << team.GetLost() << endl;
	    		os << "Match drawn: " << team.GetEqual() << endl;
	    		os << "Team point: " << team.GetPoint() << endl;
	    		os << "<------------------------------>"
			}
		}
		void ReadChampionshipStatus(const istream& is){
			string teamName;
			while(is >> name >> win >> lost >> equal){
				Team team(teamname);
				team.SetWin(win);
				team.SetLost(lost);
				team.SetEqual(equal);
				team.Print
			}
		}
};