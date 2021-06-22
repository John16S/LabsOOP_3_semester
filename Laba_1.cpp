#include <iostream>
#include <ctime>;
#include <string>
using namespace std;

/* Class instrumenti dlya sozdaniye programmnoe obespe4eniye */
class instrumenti_PO
{
private:
	char* official_name = NULL; 
	int year;
	char* kod_name; // kodovoe nazvaniye
	double version; // versia
	char* realize_data; // data vihoda

public:
	void defconstructor(); // Psevdokonstructor po umol4aniyu
	void constructor(char* Of_name, int Year, char* Kod_nazvaniye, double vers, char* real_data); // Psevdokonstructor s parametri
	void Destructor(); // Psevdodestructor

	void get_Po() const; // Vivod poley objecta classa
	void set_Po(); // Izmeneniye poley objecta classa
	int get_year() const; // Metod vozvrashayushiy zna4eniye pole year
	instrumenti_PO& copy(const instrumenti_PO& s); //metod kopirovaniye poley odnogo objecta v drugoy
};

/* Conteyner-class v vide Steka*/
class conteiner {
private:
	struct Stack {
		instrumenti_PO Data;
		Stack* Next = NULL;
	};
	Stack* top;

public:
	conteiner(); // constructor po umol4aniyu
	~conteiner(); // deconstructor po umol4aniyu
	void Push(instrumenti_PO& PO); // metod dobavleniye objecta v stek
	void Pop(); // metod udaleniye objecta iz steka
	void Get_po(); // metod vivoda poley objecta v steke
	void Search() const; // metod dlya poiska
	void Compare() const; // metod sravneniye
	void Sorting(); // metod dlya sortirovaniye elementov steka
};

int main() {
	srand(time(NULL));

	instrumenti_PO a1, a2, a3;
	a1.set_Po();
	a2.set_Po();
	a3.set_Po();

	conteiner st;
	st.Push(a1);
	st.Push(a2);
	st.Push(a3);
	system("cls");

	st.Get_po();
	system("pause");
	system("cls");

	cout << "Search: " << endl;
	st.Search();
	system("pause");
	system("cls");

	cout << "Compare: " << endl;
	st.Compare();
	system("pause");
	system("cls");

	cout << "Sorted: " << endl;
	st.Sorting();
	st.Get_po();

	system("pause");
	return 0;
}

void instrumenti_PO::defconstructor() { // Psevdokonstructor po umol4aniyu
	char Default[] = "default";

	official_name = new char[strlen(Default) + 1];
	strcpy_s(official_name, strlen(Default) + 1, Default);

	year = 0;

	kod_name = new char[strlen(Default) + 1];
	strcpy_s(kod_name, strlen(Default) + 1, Default);

	version = 0;

	realize_data = new char[strlen(Default) + 1];
	strcpy_s(realize_data, strlen(Default) + 1, Default);
}

void instrumenti_PO::constructor(char* Of_name, int Year, char* Kod_nazvaniye, double vers, char* Real_data) { // Psevdokonstructor s parametri
	official_name = new char[strlen(Of_name) + 1];
	strcpy_s(official_name, strlen(Of_name) + 1, Of_name);

	year = Year;

	kod_name = new char[strlen(Kod_nazvaniye) + 1];
	strcpy_s(kod_name, strlen(Kod_nazvaniye) + 1, Kod_nazvaniye);

	version = vers;

	realize_data = new char[strlen(Real_data) + 1];
	strcpy_s(realize_data, strlen(Real_data) + 1, Real_data);
}

void instrumenti_PO::Destructor(){ // Psevdodestructor
	if (official_name != NULL) delete[] official_name;
}

void instrumenti_PO::get_Po() const { // Vivod poley objecta classa
	cout << "____________________________________________\n";
	cout << "Official_name: " << official_name << endl;
	cout << "Year: " << year << endl;
	cout << "Kodovoe nazvaniye: " << kod_name << endl;
	cout << "Version: " << version << endl;
	cout << "Realize date: " << realize_data << endl;
}

void instrumenti_PO::set_Po() { // Izmeneniye poley objecta classa
	char name[25], kod[20], r_date[25];
	string name1;
	int ye;
	double ver;

	cout << "Enter Name: "; cin >> name;
	if (this->official_name != NULL) delete[] this->official_name;
	this->official_name = new char[strlen(name) + 1];
	strcpy_s(this->official_name, strlen(name) + 1, name);
	
	ye = rand() % 11 + 2011;
	this->year = ye;

	cout << "Kodovoe nazvaniye: "; cin >> kod;
	if (kod_name != NULL) delete[] kod_name;
	kod_name = new char[strlen(kod) + 1];
	strcpy_s(kod_name, strlen(kod) + 1, kod);

	version = (rand() % 10) / 5.0 + 1.1;

	cout << "Realize date: "; cin >> r_date;
	if (realize_data != NULL) delete[] realize_data;
	realize_data = new char[strlen(r_date) + 1];
	strcpy_s(realize_data, strlen(r_date) + 1, r_date);
	cout << endl;
}

int instrumenti_PO::get_year() const { // Metod vozvrashayushiy zna4eniye pole year
	return year;
}

instrumenti_PO& instrumenti_PO::copy(const instrumenti_PO& s) { //metod kopirovaniye poley odnogo objecta v drugoy
	if (this != &s) {
		if (official_name != NULL) delete[] official_name;
		if (s.official_name != NULL) {
			official_name = new char[strlen(s.official_name) + 1];
			strcpy_s(official_name, strlen(s.official_name) + 1, s.official_name);
		}

		year = s.year;

		if (kod_name != NULL) delete[] kod_name;
		if (s.kod_name != NULL) {
			kod_name = new char[strlen(s.kod_name) + 1];
			strcpy_s(kod_name, strlen(s.kod_name) + 1, s.kod_name);
		}

		version = s.version;

		if (realize_data != NULL) delete[] realize_data;
		if (s.realize_data != NULL) {
			realize_data = new char[strlen(s.realize_data) + 1];
			strcpy_s(realize_data, strlen(s.realize_data) + 1, s.realize_data);
		}
		return *this;
	}
}

conteiner::conteiner() {
	top = NULL;
}

conteiner::~conteiner() {
	Stack* tmp = top;
	while (tmp != NULL) {
		top = top->Next;
		delete(tmp);
		tmp = top;
	}
	delete(top);
}

void conteiner::Push(instrumenti_PO& PO) {
	Stack* tmp = new Stack;
	tmp->Next = top;
	top = tmp;
	top->Data = PO;
}

void conteiner::Pop() {
	Stack* tmp = top;
	top = top->Next;
	delete(tmp);
}

void conteiner::Get_po() {
	Stack* tmp = top;
	while (tmp != NULL) {
		tmp->Data.get_Po();
		tmp = tmp->Next;
	}
}

void conteiner::Compare() const {
	int YEAR;
	cout << "Enter year: "; cin >> YEAR;
	Stack* tmp = top;
	while (tmp != NULL) {
		if (tmp->Data.get_year() >= YEAR) tmp->Data.get_Po();
		tmp = tmp->Next;
	}
}

void conteiner::Sorting()
{
	Stack* tmp = top;
	int g = 0;
	while (tmp != NULL) {
		g++;
		tmp = tmp->Next;
	}
	int size = g;

	instrumenti_PO* mas = new instrumenti_PO[size];
	g = 0;
	tmp = top;
	while (tmp != NULL) {
		mas[g++] = tmp->Data;
		tmp = tmp->Next;
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (mas[i].get_year() < mas[j].get_year()) {
				instrumenti_PO tmp;
				tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
		}
	}

	tmp = top;
	while (tmp != NULL) {
		top = top->Next;
		delete(tmp);
		tmp = top;
	}

	for (int i = 0; i < size; i++) {
		Push(mas[i]);
	}
}

void conteiner::Search() const
{
	int YEAR;
	cout << "Enter year: "; cin >> YEAR;
	Stack* tmp = top;
	while (tmp != NULL) {
		if (tmp->Data.get_year() == YEAR) tmp->Data.get_Po();
		tmp = tmp->Next;
	}
}