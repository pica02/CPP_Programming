//2. Una biblioteca vuole memorizzare i suoi libri in un database. Ogni elemento nella biblioteca
//ha un titolo ed un autore, il loro numero di pagine ed il nome dell'editore. Realizzare le classi
//per la gestione dei libri, permettendo di aggiungere libri alla biblioteca, oltre che leggere e
//scrivere il contenuto della biblioteca su file.

class Book{
	private:
		friend ostream& operator<<(ostream& os, Book& b);
		friend istream& operator>>(istream& is, Book& b);
		string author;
		string name;
		string editor;
		string pages;
	public:
		Book(){}
		Book(const string& author_, const string& name_,
		     const string& editor_, const string& pages_):
		     	author(author), name(name_), editor(editor_), pages(pages_){};
		inline int Get_Author() const{
			return author;
		}
		inline int Get_Name() const{
			return name;
		}
		inline int Get_Editor() const{
			return editor;
		}
		inline int Get_Pages() const{
			return pages;
		}
		
		
};

friend ostream& operator<<(ostream& os, Book& b){
	os << b.author << "" << b.name << "" << b.editor << "" << b.pages << "/n";
	return os
}

friend istream& operator>>(istream& is, Book& b){
	
}

class Bibliotheque{
	private:
		Book* book;
	public:
		Bibliotheque(){}
		void AddBook();
		void ReadFile();
		void WriteFile();
		
}