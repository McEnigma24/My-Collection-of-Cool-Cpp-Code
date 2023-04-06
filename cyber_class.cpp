#include "header.h"
#include <string>



////////////////////////////////////////////
//Mój String//
 
// może zrobic metodę To_String(), bo może nie aż taka trudna jest do zrobienia dla intów. 
// Dla intów można na początku sprawdzić czy jest dodatni czy ujemny a potem dzielić bez resztu przez 100, 10 itd. i takży wnik zmienić od razu na char
// 
// funkcja do wycinania z tablicy określonych indexów i sklejania ze sobą całej reszty
// może przeciążenie operatora* żeby robił iloczyn kartezjański, dla wszystkich możliowych kombinacji wyrazów, jedna literka z każdą inną z drugiego, 
// potem dwie literki z każdą inną itd. albo jakis inny sposób
// Jeszcze żeby działało na obietkach const to trzeba mieć też funkcje i operatory const - Cherno Arrow Operator

	// String //

	String::String()
		:size(0), tab(nullptr), for_execptions('e')
	{
	}
	String::String(const char* input)
		{
			size = strlen(input);
			tab = new char[size + 1];

			for (int i = 0; i < size; i++) tab[i] = input[i];
			tab[size] = '\0';
			for_execptions = 'e';
		}
	String::~String()
		{
			if (tab != nullptr) delete[] tab;
		}
	String::String(const String& other)
			: size(other.size)
		{
			tab = new char[other.size + 1];
			for (int i = 0; i < other.size; i++) tab[i] = other.tab[i];
			tab[other.size] = '\0';
			for_execptions = 'e';
		}
	// deletes previous object
	String& String::operator=(const String& other)
	{
		if (other.size < 0 || other.tab == nullptr) return *this;
		else if (tab != nullptr && size > 0) // mamy już jakąś tablicę
		{
			size = other.size;
			char* new_tab = new char[size + 1];
			for (int i = 0; i < size; i++) new_tab[i] = other.tab[i];
			new_tab[size] = '\0';

			delete[] tab;
			tab = new_tab;
			return *this;
		}
		else // obiekt jest pusty
		{
			size = other.size;
			char* new_tab = new char[size + 1];
			for (int i = 0; i < size; i++) new_tab[i] = other.tab[i];
			new_tab[size] = '\0';
			
			tab = new_tab;
			return *this;
		}		
	}
	String& String::To_String(long long input)
	{
		Number_Bases n;		
		(*this) = n.Decimal(input);	
		return *this;
	}
	int String::Get_Size()
	{
		return size;
	}
	char* String::Get_Tab()
	{
		return tab;
	}

	void String::Print()
		{
			String obj = (*this);
			cout << "->";
			for (int i = 0; i < obj.size; i++) cout << obj.tab[i];
			cout << endl;
		}
	void String::Reverse()
		{
			if (tab != nullptr && size > 0)
			{
				int i = 0;
				int j = size - 1;
				char tmp;
				while (i < j)
				{
					tmp = tab[i];
					tab[i] = tab[j];
					tab[j] = tmp;

					i++;
					j--;
				}
			}
		}
	int String::Length()
		{
			return size;
		}
	bool String::Is_Empty()
		{
			if (size == 0) return true;
			return false;
		}
	void String::Replace(char old_char, char new_char)
	{
		if (tab == nullptr) return;

		for (int i = 0; i < size; i++)
		{
			if (this->operator[](i) == old_char) this->operator[](i) = new_char;
		}
	}

	// + += dopisują na koniec	
	String& String::operator+(const String& other)
		{
			int new_size = this->size + other.size;
			if (new_size == this->size) return *this;
			else if(tab != nullptr) // ten do którego dodajemy już ma coś swojego
			{					
				char* new_tab = new char[new_size + 1];

				int i;
				for (i = 0; i < size ; i++) new_tab[i] = tab[i];			
				for (int j = 0; i < new_size; i++, j++) new_tab[i] = other.tab[j];
				new_tab[new_size] = '\0';

			
				// usuwanie wczesniejszej tabeli
				delete[] tab;
			
			
				this->size = new_size;
				this->tab = new_tab;
				return *this;
			}
			else // jak na razie String jest pusty
			{
				tab = new char[other.size + 1];
				for (int i = 0; i < other.size; i++) tab[i] = other.tab[i];
				tab[other.size] = '\0';
				size = other.size;
				return *this;
			}
		}
	String& String::operator+(const char* input)
		{
			int input_size = strlen(input);		
			if (input_size <= 0 ) return *this;
			else if (tab != nullptr) // ten do którego dodajemy już ma coś swojego
			{
				int new_size = this->size + input_size;
				char* new_tab = new char[new_size + 1];

				int i;
				for (i = 0; i < size; i++) new_tab[i] = tab[i];
				for (int j = 0; i < new_size; i++, j++) new_tab[i] = input[j];
				new_tab[new_size] = '\0';


				// usuwanie wczesniejszej tabeli
				delete[] tab;


				this->size = new_size;
				this->tab = new_tab;
				return *this;
			}
			else // jak na razie String jest pusty
			{
				tab = new char[input_size + 1];
				for (int i = 0; i < input_size; i++) tab[i] = input[i];
				tab[input_size] = '\0';
				size = input_size;
				return *this;
			}
		}
	String& String::operator+(const char input)
		{
			if (tab != nullptr) // ten do którego dodajemy już ma coś swojego
			{
				size++;
				char* new_tab = new char[size + 1];

				for (int i = 0; i < size; i++) new_tab[i] = tab[i];
				new_tab[size - 1] = input;
				new_tab[size] = '\0';

				// usuwanie wczesniejszej tabeli
				delete[] tab;

				tab = new_tab;
				return *this;
			}
			else // jak na razie String jest pusty
			{
				size = 1;
				tab = new char[size + 1];
				tab[0] = input;
				tab[1] = '\0';

				return *this;
			}
		}
	String& String::operator+=(const String& other)
		{
			int new_size = this->size + other.size;
			if (new_size == this->size) return *this;
			else if (tab != nullptr) // ten do którego dodajemy już ma coś swojego
			{
				char* new_tab = new char[new_size + 1];

				int i;
				for (i = 0; i < size; i++) new_tab[i] = tab[i];
				for (int j = 0; i < new_size; i++, j++) new_tab[i] = other.tab[j];
				new_tab[new_size] = '\0';


				// usuwanie wczesniejszej tabeli
				delete[] tab;


				this->size = new_size;
				this->tab = new_tab;
				return *this;
			}
			else // jak na razie String jest pusty
			{
				tab = new char[other.size + 1];
				for (int i = 0; i < other.size; i++) tab[i] = other.tab[i];
				tab[other.size] = '\0';
				size = other.size;
				return *this;
			}
		}
	String& String::operator+=(const char* input)
		{
			int input_size = strlen(input);
			if (input_size <= 0) return *this;
			else if (tab != nullptr) // ten do którego dodajemy już ma coś swojego
			{
				int new_size = this->size + input_size;
				char* new_tab = new char[new_size + 1];

				int i;
				for (i = 0; i < size; i++) new_tab[i] = tab[i];
				for (int j = 0; i < new_size; i++, j++) new_tab[i] = input[j];
				new_tab[new_size] = '\0';


				// usuwanie wczesniejszej tabeli
				delete[] tab;


				this->size = new_size;
				this->tab = new_tab;
				return *this;
			}
			else // jak na razie String jest pusty
			{
				tab = new char[input_size + 1];
				for (int i = 0; i < input_size; i++) tab[i] = input[i];
				tab[input_size] = '\0';
				size = input_size;
				return *this;
			}
		}
	String& String::operator+=(const char input)
		{
			if (tab != nullptr) // ten do którego dodajemy już ma coś swojego
			{
				size++;
				char* new_tab = new char[size + 1];

				for (int i = 0; i < size; i++) new_tab[i] = tab[i];
				new_tab[size - 1] = input;
				new_tab[size] = '\0';

				// usuwanie wczesniejszej tabeli
				delete[] tab;
						
				tab = new_tab;
				return *this;
			}
			else // jak na razie String jest pusty
			{
				size = 1;
				tab = new char[size + 1];
				tab[0] = input;
				tab[1] = '\0';
			
				return *this;
			}
		}
	
	// sort by alphabet order
	bool String::operator>(const String& other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) == 2) return true;
				return false;
			}
			else return false;
		}
	bool String::operator<(const String& other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) == 1) return true;
				return false;
			}
			else return false;
		}
	bool String::operator==(const String& other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) == 3) return true;
				return false;
			}
			else return false;
		}
	bool String::operator!=(const String& other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) != 3) return true;
				return false;
			}
			else return false;
		}
	bool String::operator>=(const String& other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) == 2 || 
					which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) == 3) 
					return true;
				return false;
			}
			else return false;
		}
	bool String::operator<=(const String& other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) == 1 ||
					which_word_is_first_in_alphabet(this->tab, other.tab, this->size, other.size) == 3) 
					return true;
				return false;
			}
			else return false;
		}

	// sort by number	
	/*
		bool String::operator>(const String & other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (Which_number_is_bigger(*this, other) == 1) return true;
				return false;
			}
			else return false;
		}
		bool String::operator<(const String & other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (Which_number_is_bigger(*this, other) == 2) return true;
				return false;
			}
			else return false;
		}
		bool String::operator==(const String & other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (Which_number_is_bigger(*this, other) == 3) return true;
				return false;
			}
			else return false;
		}
		bool String::operator!=(const String & other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (!(Which_number_is_bigger(*this, other) == 3)) return true;
				return false;
			}
			else return false;
		}
		bool String::operator>=(const String & other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (Which_number_is_bigger(*this, other) == 1 ||
					Which_number_is_bigger(*this, other) == 3)
					return true;
				return false;
			}
			else return false;
		}
		bool String::operator<=(const String & other)
		{
			if (this->tab != nullptr && this->size > 0 && other.tab != nullptr && other.size > 0)
			{
				if (Which_number_is_bigger(*this, other) == 2 ||
					Which_number_is_bigger(*this, other) == 3)
					return true;
				return false;
			}
			else return false;
		}
		*/	

	// []
	char& String::operator[](int index)
	{
		if (size > 0 && index < size)
		{
			return tab[index];
		}
		else return for_execptions;
	}

	// contains
	bool String::operator^(const char& key)
	{
		if (tab == nullptr) return false;

		for (int i = 0; i < size; i++) if (tab[i] == key) return true;
		return false;
	}

	// - usuwa poszczególne wyrazy
	// -= usuwa wszystkie litery ze Stringa

	String& String::cut_from_string()
	{
		//Search_Patterns_Char obj;
		//obj.Brute_Force_Approach_returns_table_of_index();
		return *this;
	}
	String& String::operator-(const String& other)
	{
		if (other.size <= 0 || other.tab != nullptr) return *this;
		else
		{

		}
	}
	
	String& String::operator-=(const char input)
	{
		if (tab == nullptr) return *this;
		Array_Functions<char> c;
		if (!c.Already_in_array(tab, size, input)) return *this;

		// now the real part, we know the String is not empty and it holds at least 1 input character

		int* tmp = new int[size];
		for (int i = 0; i < size; i++) tmp[i] = (int)tab[i];

		// marking positions where the unwanted char sits
		String return_string;

		for (int i = 0; i < size; i++)
		{
			if (tab[i] != input) 
			{
				return_string += tab[i];
			}
		}
		
		(*this) = return_string;

		return *this;
	}

	// Turn String (mój) na liczbę, spróbować dla intów bo double będzie znacznie cięższy//
	// zwraca int, bierze String
	int String::Parse_to_Int()
	{
		if (!this->Try_Parse_to_Int()) return 0;
		else
		{
			String tmp = *this;
			bool negative = tmp ^ '-';
			tmp-=('-');

			int result = 0;
			unsigned int index_of_last = tmp.size - 1;
			int how_many = 0;
			int times = 1;

			while (index_of_last != -1)
			{
				how_many = (int)tmp.tab[index_of_last] - 48;
				result += (how_many * times);

				times *= 10;
				index_of_last--;
			}


			if (negative) result *= (-1);
			return result;
		}
	}	
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	bool String::Try_Parse_to_Int()
	{		
		if (tab == nullptr) return false;

		// '-' counter
		int _counter = 0;
		char all_numbers[11] = { 0 };

		int tmp = 48;
		for (int i = 0; i < 10; i++)
		{
			all_numbers[i] = tmp;
			tmp++;
		}
		all_numbers[10] = 45;

		//for (unsigned int i = 0; i < 11; i++) cout << all_numbers[i] << endl;

		// check how many '-'
		for (int i = 0; i < size; i++) if ((tab != nullptr) && (tab[i] == '-')) _counter++;
				
		if (_counter > 1) return false;
		else if (_counter == 1) if (tab[0] != '-') return false;
		
		// teraz wiemy, że jedyne napisy jakie możemy mieć to bez minusa lub z minusem na początku 
		// teraz sprawdzamy czy cała reszta napisu wpasowywuje się w tablicę

		// teraz przesialiśmy i mamy pewność że są same liczby
		for (int i = 0; i < size; i++)
		{
			if ((tab != nullptr) && (!Contains_for_Try_Parse(all_numbers, 11, tab[i]))) return false;
		}

		// teraz już wiemy, że jest git liczba
		// sprawdzamy tylko czy jest większa od 2147483647
		// najpierw sprawdzamy rozmiary napisów, a potem można alfabetycznie < > <= >=
		if (tab[0] == '-')
		{
			String smallest = "-2147483648";
			int length_smallest = smallest.Length();
			int length_this = size;

			if (length_this < length_smallest) return true;
			else if (length_this > length_smallest) return false;
			else
			{
				// tych samych rozmiarów
				if (*this > smallest) return false;
				else if (*this <= smallest) return true;				
			}
		}
		else
		{
			String max = "2147483647";
			int max_length = max.Length();
			int this_length = size;

			if (this_length < max_length) return true;
			else if (this_length > max_length) return false;
			else
			{
				// tych samych rozmiarów
				if (*this > max) return false;
				else if (*this <= max) return true;
			}
		}
	}
	bool String::Contains_for_Try_Parse(const char* all_numbers, const int& size, const char& this_char)
	{
		if (all_numbers == nullptr) return false;

		for (int i = 0; i < size; i++) if (all_numbers[i] == this_char) return true;		
		return false;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

	// doesn't apply to strings of numbers
	//  
	// 1 if right is bigger
	// 2 if left is bigger
	// 3 if equal
	int String::which_word_is_first_in_alphabet(const char* a, const char* b, unsigned int size_a, unsigned int size_b)
	{
		if ((a && b != nullptr) && (size_a && size_b > 0))
		{	
			unsigned int smaller = size_a > size_b ? size_b : size_a;
			for (unsigned int i = 0; i < smaller; i++)
			{
				if (which_character_is_first_in_alphabet(a[i], b[i]) == 1) return 1;
				else if (which_character_is_first_in_alphabet(a[i], b[i]) == 2) return 2;
			}			

			if (size_a == size_b) return 3;
			else if (size_a > size_b) return 2;
			else return 1;
		}
		else return 0;
	}
	int String::which_character_is_first_in_alphabet(const char& a, const char& b)
	{
		if (a < b) return 1;
		else if (a > b) return 2;
		else return 3;
	}

	/*bool String::Does_full_pattern_match(String& full_tekst, String& pattern, const int& index_of_first_match)
	{		
		if (!full_tekst.Is_Empty() && pattern.Is_Empty() && index_of_first_match >= 0)
		{
			for (int i = 0; i < (int)pattern.Length(); i++)
			{
				if (pattern[i] != full_tekst[index_of_first_match + i]) return false;
			}
			return true;
		}
		else return false;
	}
	int* String::Brute_Force_Approach_returns_table_of_index(String& full_tekst, String& pattern, int& size)
	{
		if (pattern != "")
		{
			Queue<int> obj;

			int length = full_tekst.Length();

			for (int i = 0; i < length; i++)
			{
				if ((full_tekst[i] == pattern[0]) && Does_full_pattern_match(full_tekst, pattern, i))
				{
					obj.Enque(i);
				}
			}


			return obj.Return_Tab(size);
		}
		else return nullptr;
	}
	*/
	// -String //








	// Time //

	Time::Time()
	{
		start = 0;
		stop = 0;
	}
	void Time::Start()
	{
		start = clock();
	}
	void Time::Stop()
	{
		stop = clock();
	}
	double Time::Get_how_much_time_passed()
	{
		if (start != 0 && stop != 0) return (double)(((double)stop - (double)start) / (double)MY_CLOCKS_PER_SEC);
		else return 0;
	}
	void Time::Show_how_much_time_passed()
	{
		if (start != 0 && stop != 0) cout << endl << "Time passed: " << (double)(((double)stop - (double)start) / (double)MY_CLOCKS_PER_SEC) << endl << endl;
		else cout << endl << "something went wrong " << endl;
	}


	Time_Scope::Time_Scope(const string& name, int b, int a)		
	{
		start = clock();
		stop = 0;
		scope_name = name;


		endlines_before = b < 0 ? 0:b;
		endlines_after = a < 0 ? 0:a;	
	}
	Time_Scope::~Time_Scope()
	{
		stop = clock();
		double result = (double)((stop - start) / (double)MY_CLOCKS_PER_SEC);
		
		int hours = (int)(result / 3600);
		int minuts = (int)(result / 60) - (int)(hours * 60);
		int seconds = (int)(result / 1) - (int)(hours * 3600) - (int)(minuts * 60);

		for (unsigned int i = 0; i < endlines_before; i++) cout << endl;
		cout << scope_name << " took - " << hours << "h - " << minuts << "m - " << seconds << "s";
		for (unsigned int i = 0; i < endlines_after; i++) cout << endl;
	}

	// ~Time //


////////////////////////////////////////////
//Wbombić tu Framework na Grafy co zrobiłem//     Zastanowić się nad tym dodatkowym zadaniem na pierwszego kolosa. Czyli jak sprawdzić czy w grafie występuje cykl i jeśli tak to jakie krawędzie i ile ich jest





	// Search Patterns //                             sprawdzić czy, wielowątkowość poleceń do procesora przyśpieszy doczyt z pliku Cherno C++ faster

	//for (size_t i = 0; i < pattern.length(); i++)
	// cos gosc mowil ze to niby lepiej przechodzi, nie wiem do konca

	string Search_Patterns::wygeneruj_losowe_ciagi_znakow(const string& jakich_liter_moge_uzywac, const int& jak_wiele_znakow_wylosowac)
	{
		if (jakich_liter_moge_uzywac == "") return "";
		else
		{
			int length = (int)jakich_liter_moge_uzywac.length();
			int random_index;
			int czy_pora_na_spacje;

			string losowe_znaki = "";
			for (int i = 0; i < jak_wiele_znakow_wylosowac; i++)
			{
				random_index = rand() % length;
				losowe_znaki += jakich_liter_moge_uzywac[random_index];

				czy_pora_na_spacje = rand() % 100 + 1;
				if (czy_pora_na_spacje > 80) losowe_znaki += " ";
			}
			return losowe_znaki;
		}
	}
	string Search_Patterns::Odczytane_z_Pliku()
	{
		fstream ODCZYT("tekst.txt");

		string tekst = "";
		string odczyt;
		while (!ODCZYT.eof())
		{
			ODCZYT >> odczyt;
			if (tekst != "") tekst += " ";
			tekst += odczyt;
		}
		ODCZYT.close();

		return tekst;
	}

	//Brute Force
	bool Search_Patterns::Does_full_pattern_match(const string& full_tekst, const string& pattern, const int& index_of_first_match)
	{
		if (full_tekst != "" && pattern != "" && index_of_first_match >= 0)
		{
			for (int i = 0; i < (int)pattern.length(); i++)
			{
				if (pattern[i] != full_tekst[index_of_first_match + i]) return false;
			}
			return true;
		}
		else return false;
	}
	void Search_Patterns::Show_Index_In_Tekst(const string& pattern, const int* tab, const int& size, const int& how_many_letters_before, const int& how_many_letters_after)
	{
		if (tab != nullptr && size > 0)
		{
			string full_tekst = Odczytane_z_Pliku();
			int size_pattern = (int)pattern.length();

			int current_index = 0;

			cout << "found " << size << " elements" << endl;
			for (int i = 0; i < size; i++)
			{
				current_index = tab[i];

				for (int k = how_many_letters_before; k > 0 && current_index - k >= 0; k--)
				{
					cout << full_tekst[current_index - k];
				}

				cout << "(";
				for (int j = 0; j < size_pattern && current_index + j < (int)full_tekst.length(); j++)
				{
					cout << full_tekst[current_index + j];
				}
				cout << ")";

				for (int j = 0; j < how_many_letters_after && j + how_many_letters_after < (int)full_tekst.length(); j++)
				{
					cout << full_tekst[current_index + size_pattern + j];
				}
				cout << endl;
			}
		}
		else cout << "tab to nullptr" << endl;
	}
	int* Search_Patterns::Brute_Force_Approach_returns_table_of_index(const string& full_tekst, const string& pattern, int& size)
	{
		if (pattern != "")
		{
			Queue<int> obj;

			int length = full_tekst.length();

			for (int i = 0; i < length; i++)
			{
				if ((full_tekst[i] == pattern[0]) && Does_full_pattern_match(full_tekst, pattern, i))
				{
					obj.Enque(i);
				}
			}


			return obj.Return_Tab(size);
		}
		else return nullptr;
	}

	//Pierwszy algorytm
	//Morisa Pratta
	string Search_Patterns::Zwraca_najwiekszy_wystepujacy_w_obydwu_element(const string* tab_a, const string* tab_b, const int& size_a, const int& size_b)
	{

		// teraz zakladam ze sa posorotwane, bo wiem ze sa // zrobic inny przypadek ze tablica jest sortowana
		Queue<string> powtarzajace_sie; //// w sumie to nie trzeba sortowac /// pozniej znajdzie sie z tej tablicy najwieksza i naura


		string current = "";
		for (int i = 0; i < size_a; i++)
		{
			current = tab_a[i];

			for (int j = 0; j < size_b; j++)
			{
				if (current == tab_b[j]) powtarzajace_sie.Enque(current);
			}
		}

		int size_powtarzajacych_sie = 0;
		string* tab = powtarzajace_sie.Return_Tab(size_powtarzajacych_sie);

		Array_Functions<string> functions;
		return functions.Biggest_value_in_tab(tab, size_powtarzajacych_sie);
	}
	string Search_Patterns::Najwiekszy_wspolny_prefix_sufix(const string& pattern)
	{
		if (pattern != "")
		{
			int length = pattern.length();

			// Prefixy
			Queue<string> prefix;
			string tmp = "";
			for (int i = 0; i < length - 1; i++)
			{
				tmp += pattern[i];
				prefix.Enque(tmp);
			}
			int size_prefix = 0;
			string* tab_prefix = prefix.Return_Tab(size_prefix);



			// Sufix
			Queue<string> sufix;
			for (int i = length - 1; i > 0; i--)
			{
				tmp = "";
				for (int j = i; j <= length - 1; j++) tmp += pattern[j];

				sufix.Enque(tmp);
			}
			int size_sufix = 0;
			string* tab_sufix = sufix.Return_Tab(size_sufix);


			Array_Functions<string> functions;
			string pierwszy = functions.Biggest_value_from_both(tab_prefix, tab_sufix, size_prefix, size_sufix);
			//string drugi = Zwraca_najwiekszy_wystepujacy_w_obydwu_element(tab_prefix, tab_sufix, size_prefix, size_sufix);
			//if (pierwszy == drugi) cout << "wszystko git" << endl;

			return pierwszy;
		}
		else return "";
	}
	int* Search_Patterns::Generator_Tablicy_Morrisa_Pratta(const string& pattern, int& size)
	{
		if (pattern == "") return nullptr;
		else
		{
			size = (int)pattern.length();
			int* tab = new int[size];
			for (int i = 0; i < size; i++) tab[i] = 0;


			string tmp;
			for (int i = 0; i < size; i++)
			{
				tmp = "";
				for (int j = 0; j <= i; j++) tmp += pattern[j];

				string max_wspolny_prefix_sufix = Najwiekszy_wspolny_prefix_sufix(tmp);
				tab[i] = (int)max_wspolny_prefix_sufix.length();
			}

			return tab;
		}
	}
	int Search_Patterns::Return_Index_Of_Missmatch(const string& full_tekst, const string& pattern, const int& limit, const int& pattern_size, const int& index_in_tekst)
	{
		if (full_tekst == "" || pattern == "" || index_in_tekst < 0) return -2;
		else
		{

			for (int i = 0; i < pattern_size && index_in_tekst + i < limit; i++)
			{
				if (pattern[i] != full_tekst[index_in_tekst + i]) return i;
			}
			return -1;
		}
	}
	int* Search_Patterns::Knuth_Morris_Pratt(const string& full_tekst, const string& pattern, int& size_of_returned_tab)
	{

		int length = (int)full_tekst.length();
		int pattern_size = (int)pattern.length();

		// tworzenie tablicy		

		int size = 0;
		int* prefix_table = Generator_Tablicy_Morrisa_Pratta(pattern, size);
		for (int i = 0; i < size; i++) prefix_table[i]++;

		//Array_Functions<int> f;
		//f.Show_Tab(prefix_table, size);

		Queue<int> index_trafionych;


		int result;
		for (int i = 0; i < length; )
		{
			result = Return_Index_Of_Missmatch(full_tekst, pattern, length, pattern_size, i);

			if (0 <= result)
			{
				i += prefix_table[result];
			}
			else if (result == -1) // trafiony match do końca
			{
				index_trafionych.Enque(i);
				i += prefix_table[size - 2]; // poprawiony wczesniej skakal co caly patern jak znalazl ale przeciez moze sie zdarzyc ze koniec paternuj jest jaki sam jak poczatek i jakby slowa znalezione 
			}
		}


		return index_trafionych.Return_Tab(size_of_returned_tab);
	}

	//Drugi algorytm
	//Boyer Moore			   	
	void Search_Patterns::Construct_Bad_Match_Two_Tabs(const string& pattern, char*& tab_char, int*& tab_int, int& size)
	{
		if (pattern != "")
		{
			int size_pattern = (int)pattern.length();

			Queue<char> q;
			for (int i = 0; i < size_pattern; i++) q.Enque_unique(pattern[i]);
			size = q.Count();

			tab_char = new char[size + 1];
			tab_int = new int[size + 1];

			for (int i = 0; i < size; i++) tab_char[i] = q.Deque();
			for (int i = 0; i < size; i++) tab_int[i] = -1;


			Array_Functions<char> fun;
			int value;
			int index;
			for (int i = 0; i < size_pattern; i++)
			{
				index = fun.Find_Index_of(pattern[i], tab_char, size);
				if (index != -1)
				{
					value = size_pattern - i - 1;
					if (i == size_pattern - 1 && tab_int[index] == -1) tab_int[index] = size_pattern;
					else tab_int[index] = value;
				}
			}

			// ostatni dla znaków niewystępujacych w patternie
			tab_char[size] = '*';
			tab_int[size] = size_pattern;
			size++;
		}
	}
	int Search_Patterns::Return_Index_of_Char_Tab_if_not_found_return_last_index(const char& key, const char* tab, const int& size)
	{
		if (tab != nullptr && size > 0)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (tab[i] == key) return i;
			}
			return size - 1;
		}
		else return -1;
	}
	int Search_Patterns::O_ile_przeskoczyc(const string& full_tekst, const string& pattern, const int& size_pattern, int index, char*& tab_char, int*& tab_int, const int& size)
	{
		for (int i = size_pattern - 1; i >= 0; i--)
		{
			if (pattern[i] == full_tekst[index]) index--;
			else if (i == size_pattern - 1 && pattern[i] != full_tekst[index])
			{
				// Miss match na pierwszym miejscu
				//cout<<"o ile przeskakujemy: " << tab_int[Return_Index_of_Char_Tab_if_not_found_return_last_index(full_tekst[index], tab_char, size)] <<"   " << full_tekst[index] << endl;
				return tab_int[Return_Index_of_Char_Tab_if_not_found_return_last_index(full_tekst[index], tab_char, size)];
			}
			else
			{
				// Miss match na kolejnych miejscach
				//cout << full_tekst[index] << endl;
				return size_pattern;
			}
		}
		return -1;
	}
	int* Search_Patterns::Boyer_Moore(const string& full_tekst, const string& pattern, int& size_of_returned_tab)
	{
		if (pattern == "") return nullptr;
		else
		{
			int size_full_text = full_tekst.length();
			if (size_full_text <= 0) return nullptr;

			int size_pattern = (int)pattern.length();
			char* bad_char = nullptr;
			int* bad_int = nullptr;

			int size = 0;
			Construct_Bad_Match_Two_Tabs(pattern, bad_char, bad_int, size);

			// printing tabs	
			/*
			Array_Functions<char> fun_char;
			Array_Functions<int> fun_int;

			if(size == 0) cout<<"size to 0"<<endl;
			fun_char.Show_Tab(bad_char, size);
			fun_int.Show_Tab(bad_int, size);
			cout << endl;
			*/

			Queue<int> indexy_wynikowe;
			int function_value = 0;
			for (int i = size_pattern - 1; i < size_full_text;)
			{
				function_value = O_ile_przeskoczyc(full_tekst, pattern, size_pattern, i, bad_char, bad_int, size);

				if (function_value == -1) //znalezione miejsce
				{
					indexy_wynikowe.Enque(i - size_pattern + 1);
					i += size_pattern;
				}
				else i += function_value;
			}

			delete[] bad_char;
			delete[] bad_int;

			return indexy_wynikowe.Return_Tab(size_of_returned_tab);
		}
	}

	//Trzeci algorytm
	//Rabin Karp
	int* Search_Patterns::Rabin_Karp(const string& text, const string& pattern, const int& q, int& size_of_returned_tab)
	{
		if (pattern == "" || text == "") return nullptr;


		Queue<int> index_of_match;

		int d = 10;
		int m = (int)pattern.length();
		int n = (int)text.length();
		int i, j;
		int p = 0;
		int t = 0;
		int h = 1;

		for (i = 0; i < m - 1; i++)
			h = (h * d) % q;

		// Calculate hash value for pattern and text
		for (i = 0; i < m; i++) {
			p = (d * p + pattern[i]) % q;
			t = (d * t + text[i]) % q;
		}


		// Find the match		
		for (i = 0; i <= n - m; i++) {
			if (p == t) {
				for (j = 0; j < m; j++) {
					if (text[i + j] != pattern[j])
						break;
				}

				if (j == m)
					index_of_match.Enque(i + 1);
			}

			if (i < n - m) {
				t = (d * (t - text[i] * h) + text[i + m]) % q;

				if (t < 0)
					t = (t + q);
			}
		}


		return index_of_match.Return_Tab(size_of_returned_tab);
	}

	// ~Search Patterns //









	// Wykreślanka //                               

	char** Word_Cross::Generete_Random_Grid_Symetric_Matrix(const int& size)
	{
		char** tab = new char* [size];

		char* current = nullptr;
		for (int i = 0; i < size; i++)
		{
			current = new char[size];
			tab[i] = current;
		}

		string alfabet = "abcdefghijklmnopqrstuvwxyz";
		int length = (int)alfabet.length();

		int random = 0;

		for (int i = 0; i < size; i++)
		{

			for (int j = 0; j < size; j++)
			{
				random = rand() % length;
				tab[i][j] = alfabet[random];
			}
		}

		//Show_Matrix_Symetric<char>(tab, size);
		return tab;
	}

	string* Word_Cross::Get_All_Left_to_Right(char**& tab, const int& size)
	{
		if (tab == nullptr || size <= 0) return nullptr;

		string* left_to_right_tab = new string[size];

		string tmp;
		for (int i = 0; i < size; i++)
		{
			tmp = "";
			for (int j = 0; j < size; j++)
			{
				tmp += tab[i][j];
			}

			left_to_right_tab[i] = tmp;
		}
		return left_to_right_tab;
	}
	string* Word_Cross::Get_All_Top_to_Bottom(char**& tab, const int& size)
	{
		if (tab == nullptr || size <= 0) return nullptr;

		string* top_to_bottom_tab = new string[size];

		string tmp;
		for (int i = 0; i < size; i++)
		{
			tmp = "";
			for (int j = 0; j < size; j++)
			{
				tmp += tab[j][i];
			}

			top_to_bottom_tab[i] = tmp;
		}
		return top_to_bottom_tab;
	}
	string* Word_Cross::Get_All_Diagonal_Left_to_Right(char**& tab, const int& size)
	{
		if (tab == nullptr || size <= 0) return nullptr;

		int tab_size = ((size * 2) - 1);
		string* diagonal_tab = new string[tab_size];

		string tmp;

		int starting_i = size - 1;
		int starting_j = 0;

		int current_i = 0;
		int current_j = 0;

		for (int m = 0; m < tab_size; m++)
		{
			current_i = starting_i;
			current_j = starting_j;

			tmp = "";
			while (current_i != size && current_j != size)
			{
				tmp += tab[current_i][current_j];

				current_i++;
				current_j++;
			}
			diagonal_tab[m] = tmp;


			if (starting_i != 0)
			{
				starting_i--;
				starting_j = 0;
			}
			else
			{
				starting_i = 0;
				starting_j++;
			}

		}


		return diagonal_tab;
	}

	//List_Multivalue<string, int>* Word_Cross::Search_For_Pattern_In_Matrix(const string& pattern, const int& matrix_size, char**& tab)
	//{		
	//	tab = Generete_Random_Grid_Symetric_Matrix(matrix_size);
	//		
	//	string* left_right = Get_All_Left_to_Right(tab, matrix_size);
	//	string* top_bottom = Get_All_Top_to_Bottom(tab, matrix_size);
	//	string* diagonal = Get_All_Diagonal_Left_to_Right(tab, matrix_size);
	//
	//	//Array_Functions<string> s;
	//	//s.Show_Tab(left_right, matrix_size);
	//	//s.Show_Tab(top_bottom, matrix_size);
	//	//s.Show_Tab(diagonal, matrix_size * 2 - 1);
	//
	//	Search_Patterns search;
	//	List_Multivalue<string, int>* kierunek_i_indexy = new List_Multivalue<string, int>;
	//
	//	int* algo_output = nullptr;
	//	int algo_size = 0;
	//	int* for_the_list = nullptr;
	//
	//
	//	// left to right
	//	for (int i = 0; i < matrix_size; i++) //// przeszukuje left_to_right // tam sie zmienia i = 0 do i = size - 1
	//	{
	//		algo_output = search.Boyer_Moore(left_right[i], pattern, algo_size);
	//
	//		if (algo_output != nullptr) // cos znalazl, moze nawet kilka
	//		{
	//			for (int j = 0; j < algo_size; j++)
	//			{
	//				for_the_list = new int[2];
	//				for_the_list[0] = i;
	//				for_the_list[1] = algo_output[j];
	//
	//
	//				kierunek_i_indexy->Add_Back("left to right", for_the_list, 2);
	//				delete[] for_the_list;
	//			}
	//			delete[] algo_output;
	//		}
	//	}
	//
	//	// top to bottom
	//	for (int i = 0; i < matrix_size; i++) //// przeszukuje top_to_bottom // tam sie zmienia i = 0 do i = size - 1
	//	{
	//		algo_output = search.Boyer_Moore(top_bottom[i], pattern, algo_size);
	//
	//		if (algo_output != nullptr) // cos znalazl, moze nawet kilka
	//		{
	//			for (int j = 0; j < algo_size; j++)
	//			{
	//				for_the_list = new int[2];
	//				for_the_list[0] = algo_output[j];
	//				for_the_list[1] = i;
	//
	//
	//				kierunek_i_indexy->Add_Back("top to bottom", for_the_list, 2);
	//				delete[] for_the_list;
	//			}
	//			delete[] algo_output;
	//		}
	//	}
	//		
	//	// diagonal
	//	int starting_i = matrix_size - 1;
	//	int starting_j = 0;
	//
	//	int addition_i = matrix_size - 1;
	//	int addition_j = 0;
	//
	//	int tab_size = ((matrix_size * 2) - 1);
	//	for (int m = 0; m < tab_size; m++)
	//	{			
	//		algo_output = search.Boyer_Moore(diagonal[m], pattern, algo_size);
	//			
	//		if (algo_output != nullptr) // cos znalazl, moze nawet kilka
	//		{
	//			for (int algo = 0; algo < algo_size; algo++)
	//			{
	//				for_the_list = new int[2];
	//				for_the_list[0] = algo_output[algo] + addition_i;
	//				for_the_list[1] = algo_output[algo] + addition_j;
	//
	//
	//				kierunek_i_indexy->Add_Back("diagonal", for_the_list, 2);
	//				delete[] for_the_list;					
	//			}
	//			delete[] algo_output;
	//		}
	//
	//
	//		if (starting_i != 0)
	//		{
	//			starting_i--;
	//			starting_j = 0;
	//
	//			addition_i--;
	//		}
	//		else
	//		{
	//			starting_i = 0;
	//			starting_j++;
	//
	//			addition_j++;
	//		}
	//	}
	//		
	//		
	//	delete[] left_right;
	//	delete[] top_bottom;
	//	delete[] diagonal;
	//
	//	return kierunek_i_indexy;
	//}	
	//List_Multivalue<string, int>* Word_Cross::All_cases_present(const string& pattern, const int& matrix_size, char**& tab)
	//{
	//	List_Multivalue<string, int>* tmp = Word_Cross::Search_For_Pattern_In_Matrix(pattern, matrix_size, tab);
	//
	//	while(!(tmp->Containes("left to right") && tmp->Containes("top to bottom") && tmp->Containes("diagonal")))
	//	{
	//		if (tab != nullptr)
	//		{
	//			for (int i = 0; i < matrix_size; i++) delete[] tab[i];
	//			delete[] tab;
	//		}
	//
	//		if (tmp->Count() > 0) tmp->Delete_All();
	//		delete tmp;
	//
	//		tmp = Word_Cross::Search_For_Pattern_In_Matrix(pattern, matrix_size, tab);
	//	}
	//
	//	return tmp;
	//}




	


	List_Multivalue<string, int>* Word_Cross::Search_For_Pattern_In_Matrix_My_Matrix(const string& pattern, Matrix<char>& tmp)
	{
		char** tab = tmp.Get_Tab();
		unsigned int size = tmp.Get_Columns();


		string* left_right = Get_All_Left_to_Right(tab, size);
		string* top_bottom = Get_All_Top_to_Bottom(tab, size);
		string* diagonal = Get_All_Diagonal_Left_to_Right(tab, size);
	

		//Array_Functions<string> s;
		//s.Show_Tab(left_right, matrix_size);
		//s.Show_Tab(top_bottom, matrix_size);
		//s.Show_Tab(diagonal, matrix_size * 2 - 1);

		Search_Patterns search;
		List_Multivalue<string, int>* kierunek_i_indexy = new List_Multivalue<string, int>;

		int* algo_output = nullptr;
		int algo_size = 0;	
		int for_the_list[2] = {0,0};

		// left to right
		for (unsigned int i = 0; i < size; i++) //// przeszukuje left_to_right // tam sie zmienia i = 0 do i = size - 1
		{
			algo_output = search.Boyer_Moore(left_right[i], pattern, algo_size);

			if (algo_output != nullptr) // cos znalazl, moze nawet kilka
			{
				for (int j = 0; j < algo_size; j++)
				{
					for_the_list[0] = i;
					for_the_list[1] = algo_output[j];

					kierunek_i_indexy->Add_Back("left to right", for_the_list, 2);				
				}
				delete[] algo_output;
			}
		}

		// top to bottom
		for (unsigned int i = 0; i < size; i++) //// przeszukuje top_to_bottom // tam sie zmienia i = 0 do i = size - 1
		{
			algo_output = search.Boyer_Moore(top_bottom[i], pattern, algo_size);

			if (algo_output != nullptr) // cos znalazl, moze nawet kilka
			{
				for (int j = 0; j < algo_size; j++)
				{				
					for_the_list[0] = algo_output[j];
					for_the_list[1] = i;

					kierunek_i_indexy->Add_Back("top to bottom", for_the_list, 2);		
				}
				delete[] algo_output;
			}
		}

		// diagonal
		int starting_i = size - 1;
		int starting_j = 0;

		int addition_i = size - 1;
		int addition_j = 0;

		int tab_size = ((size * 2) - 1);
		for (int m = 0; m < tab_size; m++)
		{
			algo_output = search.Boyer_Moore(diagonal[m], pattern, algo_size);

			if (algo_output != nullptr) // cos znalazl, moze nawet kilka
			{
				for (int algo = 0; algo < algo_size; algo++)
				{				
					for_the_list[0] = algo_output[algo] + addition_i;
					for_the_list[1] = algo_output[algo] + addition_j;

					kierunek_i_indexy->Add_Back("diagonal", for_the_list, 2);			
				}
				delete[] algo_output;
			}


			if (starting_i != 0)
			{
				starting_i--;
				starting_j = 0;

				addition_i--;
			}
			else
			{
				starting_i = 0;
				starting_j++;

				addition_j++;
			}
		}


		delete[] left_right;
		delete[] top_bottom;
		delete[] diagonal;

		return kierunek_i_indexy;
	}

	List_Multivalue<string, int>* Word_Cross::All_cases_present_My_Matrix(const string& pattern, Matrix<char>& obj, const unsigned int& size)
	{
		List_Multivalue<string, int>* result = nullptr;
				
		Matrix<char> random(size, size);
		while (true)
		{
			random.Initiate_random(1);
			result = Search_For_Pattern_In_Matrix_My_Matrix(pattern, random);

			if(!(result->Containes("left to right") && result->Containes("top to bottom") && result->Containes("diagonal")))
			{
				delete result;			
			}
			else
			{
				obj = random;
				break;
			}
		}

		return result;
	}

	// ~Wykreślanka //





// ToString bases 2, 8, 10, 16 //

	String Number_Bases::Binary(int input_number)
	{
		String result;
		char tmp;

		while(input_number != 0)
		{
			tmp = input_number % 2 + 48;			
			result += tmp;
			input_number = input_number / 2;
		}
		
		result.Reverse();		
		return result;
	}
	String Number_Bases::Octagonal(int input_number)
	{
		String result;
		char tmp;

		while (input_number != 0)
		{
			tmp = input_number % 8 + 48;

			result += tmp;
			input_number = input_number / 8;
		}

		result.Reverse();
		return result;
	}
	String Number_Bases::Decimal(int input_number)
	{
		String result;
		char tmp;
		bool negative = input_number < 0;

		if (negative) input_number *= (-1);

		while (input_number != 0)
		{
			tmp = input_number % 10 + 48;

			result += tmp;
			input_number = input_number / 10;
		}
		if (negative) result += '-';

		result.Reverse();
		return result;
	}
	String Number_Bases::Decimal(long long input_number)
	{
		String result;
		char tmp;
		bool negative = input_number < 0;

		if (negative) input_number *= (-1);

		while (input_number != 0)
		{
			tmp = input_number % 10 + 48;

			result += tmp;
			input_number = input_number / 10;
		}
		if (negative) result += '-';

		result.Reverse();
		return result;
	}
	String Number_Bases::Hexadecimal(int input_number)
	{
		String result;
		char tmp;

		while (input_number != 0)
		{
			tmp = input_number % 16 + 48;
			if (input_number % 16 > 9)
			{
				tmp -= 48;
				tmp += 87;
			}

			result += tmp;
			input_number = input_number / 16;
		}

		result.Reverse();
		return result;
	}

	String Number_Bases::Binary_Bit (unsigned int input_number)
	{
		String result;
		char tmp;		

		while (input_number != 0)
		{
			tmp = input_number % 2 + 48;
			result += tmp;						
			input_number >>= 1;					
		}

		result.Reverse();
		return result;
	}
	String Number_Bases::Octagonal_Bit(int input_number)
	{
		String result;
		char tmp;

		while (input_number != 0)
		{
			tmp = input_number % 8 + 48;
			result += tmp;
			input_number >>= 3;
		}

		result.Reverse();
		return result;
	}	
	String Number_Bases::Hexadecimal_Bit(int input_number)
	{
		String result;
		char tmp;

		while (input_number != 0)
		{
			tmp = input_number % 16 + 48;
			if (input_number % 16 > 9)
			{
				tmp -= 48;
				tmp += 87;
			}

			result += tmp;
			input_number >>= 4;
		}

		result.Reverse();
		return result;
	}

	// nie można używać funckji Try_Parse_to_Int bo ona wsprawdza tylko dla decymalnych
	//             															szesnastkowego nie przesuści


	// coś dziwnie działa
	int Number_Bases::Parse_to_Int_from_Binary(String& input_binary)
	{
		if (!input_binary.Try_Parse_to_Int()) return 0;
		else
		{
			char* tab = input_binary.Get_Tab();			
			bool negative = ((tab[0] == '1') && (input_binary.Get_Size() == 32));			
			//cout << "STAN NEGATIVE - " << negative << endl;

			int result = 0;
			unsigned int index_of_last = input_binary.Get_Size() - 1;
			long long how_many = 0;
			unsigned long long times = 1;
						
			int i = 1;

			int limit = -1;
			if (negative) limit = 0;

			while (index_of_last != limit)
			{
				how_many = (long long)tab[index_of_last] - 48;
				//cout << "times: " << times;
				//cout << " how_many: " << how_many;
				//cout <<" i=" << i; if (i < 10) cout << " ";
				//cout << " before " << result << " after ";
				result += (int)(how_many * times);
				//cout << result << endl;

				times <<= 1;
				//times *= 2;
				index_of_last--;
				
				//cout << i << " aktualny stan result " << result << endl;
				i++;
			}


			//cout << "po wyjsciu z petli: " << result << endl;

			if (negative)
			{
				//cout << endl << "inside negative" << endl;
				//cout << "before " << result << endl;

				int example_for_what_to_add_if_negative = 1;
				example_for_what_to_add_if_negative <<= 31;			

				result += example_for_what_to_add_if_negative;
				//cout << "after " << result << endl;
			}
			//cout << endl << endl;
				
			return result;
		}
	}
	unsigned int Number_Bases::Parse_to_Un_Int_from_Binary(String& input_binary)
	{
		if (!input_binary.Try_Parse_to_Int()) return 0;
		else
		{			
			char* tab = input_binary.Get_Tab();			

			unsigned int result = 0;
			unsigned int index_of_last = input_binary.Get_Size() - 1;
			int how_many = 0;
			unsigned long long times = 1;

			int i = 1;
			while (index_of_last != -1)
			{				
				how_many = (int)(tab[index_of_last] - 48);
				//cout << "times: " << times;
				//cout << " how_many: " << how_many;
				//cout <<" i=" << i; if (i < 10) cout << " ";
				//cout << " before " << result << " after ";
				result += (unsigned int)(how_many * times);
				//cout << result << endl;
				i++;

				times <<= 1;
				index_of_last--;			
			}
			
			
			return result;
		}
	}


	int Number_Bases::Parse_to_Int_from_Decimal(String& input_decimal)
	{
		if (!input_decimal.Try_Parse_to_Int()) return 0;
		else
		{
			String tmp = input_decimal;
			bool negative = tmp ^ '-';
			tmp -= ('-');

			int result = 0;
			unsigned int index_of_last = tmp.Get_Size() - 1;
			int how_many = 0;
			int times = 1;

			char* tab = tmp.Get_Tab();
			while (index_of_last != -1)
			{
				how_many = (int)tab[index_of_last] - 48;
				result += (how_many * times);

				times *= 10;
				index_of_last--;
			}


			if (negative) result *= (-1);
			return result;
		}
	}
	// najpierw zmiana na binarny // tylko dla dodatnich
	int Number_Bases::Parse_to_Int_from_Hexadecimal(String& input)
	{

		return 0;
	}

// ~ToString bases 2, 8, 10, 16 //





// Sudoku plane generetor //

	Sudoku::Sudoku()
	{		
		int tab[9] = { 1,2,3,4,5,6,7,8,9 };
		plane.Make_rows_columns(9, 9);	
		number_tab.Add_from_tab(tab, 9);

		pattern.Load_from_file("sudoku_standard.txt");
	}
	Sudoku::Sudoku(Matrix<int>& custom_pattern)
	{
		int tab[9] = { 1,2,3,4,5,6,7,8,9 };
		plane.Make_rows_columns(9, 9);
		number_tab.Add_from_tab(tab, 9);

		pattern.Load_from_file("sudoku_custom.txt");
	}
	void Sudoku::Make_Random_Plane()
	{		
		plane.Fill_all_values_based_on_array_mixed_up(number_tab.Return_Pointer(), 9);
	}	
	void Sudoku::Show()
	{
		plane.Show();
	}

	bool Sudoku::Check_If_Correct_Columns()
	{
		if (plane.Is_Empty()) return false;

		int sum;
		for (int i = 0; i < plane.Get_Rows(); i++)
		{
			sum = 0;
			for (int j = 0; j < plane.Get_Columns(); j++) sum += plane(j, i);
			if (sum != 45) return false;
		}
		return true;
	}
	bool Sudoku::Check_If_Correct_Rows()
	{
		if (plane.Is_Empty()) return false;

		int sum;
		for (int i = 0; i < plane.Get_Rows(); i++)
		{
			sum = 0;
			for (int j = 0; j < plane.Get_Columns(); j++) sum += plane(i, j);
			if (sum != 45) return false;
		}
		return true;
	}
	bool Sudoku::Check_If_Correct_Rows_and_Columns()
	{
		if (plane.Is_Empty()) return false;

		if (Check_If_Correct_Rows() && Check_If_Correct_Columns()) return true;
		else return false;

	}
	bool Sudoku::Check_If_Correct_Groups()
	{
		if (plane.Is_Empty() || pattern.Is_Empty()) return false;

		int sum_tab[9] = { 0 };

		for (int i = 0; i < plane.Get_Rows(); i++) for (int j = 0; j < plane.Get_Columns(); j++)
		{
			sum_tab[pattern(i, j)] += plane(i, j);
		}

		for (int i = 0; i < 9; i++) if (sum_tab[i] != 45) return false;
		return true;
	}
	bool Sudoku::Check_If_Sudoku()
	{
		if (plane.Is_Empty()) return false;

		return (Check_If_Correct_Rows_and_Columns() && Check_If_Correct_Groups());
	}

	void Sudoku::Make_Sudoku()
	{
		while (true)
		{
			plane.Initiate_value(-1);
			
			List<int>* pattern_list = new List<int>[9];
			for (int i = 0; i < 9; i++) pattern_list[i].Add_Back_from_Array_Dynamic(number_tab);

			
			//list.Add_Back_from_Array_Dynamic(number_tab);

			//cout << "list size: " << list.Get_list_size() << endl;

			int random = 0;
			int safe_check = 0;
			int for_safe_check = 0;

			for (int i = 0; i < 9; i++)
			{				
				//cout << "starting list status" << endl;
				//list.Show();
				for (int j = 0; j < 9; j++)
				{
					random = pattern_list[pattern(i, j)].Pick_Random_Value();
					safe_check = 0;
					//cout << "///////////////////////////////////////" << endl;
					while (plane.Already_In_Cross(i, j, random))
					{
						random = pattern_list[pattern(i, j)].Pick_Random_Value();
						safe_check++;

						//cout << safe_check << endl;

						// start all over again
						if (safe_check > 11)
						{
							plane.Initiate_value(-1);
							for (int i = 0; i < 9; i++) pattern_list[i].Delete_All();
							i = 0;
							j = 0;
							for (int i = 0; i < 9; i++) pattern_list[i].Add_Back_from_Array_Dynamic(number_tab);
							break;
						}
						if (safe_check > 10)
						{
							for (int k = 0; k < 9; k++)
							{
								//cout << "przeszukiwane " << plane(i, k) << endl;
								//Sleep(1000);

								if (plane(i, k) != -1 && !plane.Already_In_Columns(k, random) && !plane.Already_In_Columns(j, plane(i, k)))
								{
									int tmp = plane(i, k);
									plane(i, k) = random;
									for_safe_check = random;
									//cout << "swapped " << tmp << " with " << random << endl;
									random = tmp;
									break;
								}
							}
						}
						else if (safe_check > 9)
						{
							// przejść po kolei cały rządek i sprawdzić czy można zamienić wartości
							// czy tą co wylosowaliśmy pasuje w miejsce innej, czy ta inna pasuje w miejsce gdzie mamy wpisać

							// rząd i
							for (int k = 0; k < 9; k++)
							{
								//cout << "przeszukiwane " << plane(i, k) << endl;
								//Sleep(1000);

								if (plane(i, k) != -1 && !plane.Already_In_Columns(k, random) && !plane.Already_In_Columns(j, plane(i, k)))
								{
									int tmp = plane(i, k);
									plane(i, k) = random;
									for_safe_check = random;
									//cout << "swapped " << tmp << " with " << random << endl;
									random = tmp;
									break;
								}
							}
						}
					}

					plane(i, j) = random;

					// czasami usuwa zły element z listy

					//if (safe_check > 9) cout << "usuwam " << for_safe_check << endl;
					//else cout << "usuwam " << random << endl;

					if (safe_check > 9) pattern_list[pattern(i, j)].Delete_Value(for_safe_check);
					else pattern_list[pattern(i, j)].Delete_Value(random);

					//cout << "stan listy" << endl;
					//list.Show();

					//plane.Fill_up_visualized(1);
				}
			}

			for (int i = 0; i < 9; i++) pattern_list[i].~List();

			if (this->Check_If_Sudoku()) break;
		}
	}
	void Sudoku::Make_Sudoku_Many_Lists()
	{
		List<int>* available_row = new List<int>[9];
		List<int>* available_column = new List<int>[9];
		List<int>* available_group = new List<int>[9];
		int safe_check = 0;

		while (true)
		{
			// czyszczenie list
			for (int i = 0; i < 9; i++)
			{
				available_row[i].Delete_All();
				available_column[i].Delete_All();
				available_group[i].Delete_All();
			}

			// inicjalizacja sudoku_matrix
			plane.Initiate_value(-1);

			// zapełnianie list dostępnymi numerami
			for (int i = 0; i < 9; i++) available_row[i].Add_Back_from_Array_Dynamic(number_tab);
			for (int i = 0; i < 9; i++) available_column[i].Add_Back_from_Array_Dynamic(number_tab);
			for (int i = 0; i < 9; i++) available_group[i].Add_Back_from_Array_Dynamic(number_tab);



			int random = 0;			
			int for_safe_check = 0;
			int cg_id = 0; // current group identificator

			for (int i = 0; i < 9; i++)
			{
				//cout << "starting list status" << endl;
				//list.Show();
				for (int j = 0; j < 9; j++)
				{
					cg_id = pattern(i, j);

					random = available_group[cg_id].Pick_Random_Value();
					safe_check = 0;
					//cout << "///////////////////////////////////////" << endl;
					while(!(available_row[i].Containes(random) && available_column[j].Containes(random) && available_group[cg_id].Containes(random)))
					{
						random = available_group[cg_id].Pick_Random_Value();
						safe_check++;

						//cout << safe_check << endl;
						/*
						// start all over again
						if (safe_check > 11)
						{
							plane.Initiate_value(-1);
							for (int i = 0; i < 9; i++) pattern_list[i].Delete_All();
							i = 0;
							j = 0;
							for (int i = 0; i < 9; i++) pattern_list[i].Add_Back_from_Array_Dynamic(number_tab);
							break;
						}
						if (safe_check > 10)
						{
							for (int k = 0; k < 9; k++)
							{
								//cout << "przeszukiwane " << plane(i, k) << endl;
								//Sleep(1000);

								if (plane(i, k) != -1 && !plane.Already_In_Columns(k, random) && !plane.Already_In_Columns(j, plane(i, k)))
								{
									int tmp = plane(i, k);
									plane(i, k) = random;
									for_safe_check = random;
									//cout << "swapped " << tmp << " with " << random << endl;
									random = tmp;
									break;
								}
							}
						}
						else if (safe_check > 9)
						{
							// przejść po kolei cały rządek i sprawdzić czy można zamienić wartości
							// czy tą co wylosowaliśmy pasuje w miejsce innej, czy ta inna pasuje w miejsce gdzie mamy wpisać

							// rząd i
							for (int k = 0; k < 9; k++)
							{
								//cout << "przeszukiwane " << plane(i, k) << endl;
								//Sleep(1000);

								if (plane(i, k) != -1 && !plane.Already_In_Columns(k, random) && !plane.Already_In_Columns(j, plane(i, k)))
								{
									int tmp = plane(i, k);
									plane(i, k) = random;
									for_safe_check = random;
									//cout << "swapped " << tmp << " with " << random << endl;
									random = tmp;
									break;
								}
							}
						}
						*/


						if (safe_check > 10) break;
					}
					if (safe_check > 10) break;
					

					plane(i, j) = random;


					//if (safe_check > 9) cout << "usuwam " << for_safe_check << endl;
					//else cout << "usuwam " << random << endl;

					// PREVIOUS
					//if (safe_check > 9) pattern_list[pattern(i, j)].Delete_Value(for_safe_check);
					//else pattern_list[pattern(i, j)].Delete_Value(random);

					//cout << "stan listy" << endl;
					//list.Show();


					// usuwanie z właściwej listy wartości

					available_row[i].Delete_Value(random);
					available_column[j].Delete_Value(random);
					available_group[cg_id].Delete_Value(random);


					//plane.Fill_up_visualized(100);
				}

				if (safe_check > 10) break;
			}

			// PREVIOUS
			//for (int i = 0; i < 9; i++) pattern_list[i].~List();
			if (safe_check > 10) continue;
			if (this->Check_If_Sudoku()) break;
		}

		// usuwanie stworzonych list
		for (int i = 0; i < 9; i++)
		{
			available_row[i].~List();
			available_column[i].~List();
			available_group[i].~List();
		}

		delete[] available_row;
		delete[] available_column;
		delete[] available_group;	
	}

	void Sudoku::Save_Matrix_to_File(const char* name)
	{
		ofstream ZAPIS(name);
				
		for (int i = 0; i < plane.Get_Rows(); i++)
		{
			for (int j = 0; j < plane.Get_Columns(); j++)
			{
				ZAPIS << plane(i, j);
				if (j < plane.Get_Columns() - 1) ZAPIS << " ";
			}
				
			ZAPIS << endl;
		}

		ZAPIS.close();
	}
	void Sudoku::Save_Sudoku_Set_Hardness(const char* name, int index, int hardness_level)
	{
		ofstream ZAPIS(name);
		ZAPIS << "Sudoku " << index << endl;

		int random = 0;
		for (int i = 0; i < plane.Get_Rows(); i++)
		{
			for (int j = 0; j < plane.Get_Columns(); j++)
			{
				random = rand() % hardness_level;
				if (random == 0) ZAPIS << plane(i, j);
				else ZAPIS << " ";

				if (j < plane.Get_Columns() - 1) ZAPIS << " ";
			}

			ZAPIS << endl;
		}

		ZAPIS.close();
	}

	void Sudoku::Make_Correct_Vertical_and_Horizontal()
	{
		while (true)
		{
			plane.Initiate_value(-1);
		
			List<int> list;
			//list.Add_Back_from_Array_Dynamic(number_tab);
		
			//cout << "list size: " << list.Get_list_size() << endl;

			int random = 0;
			int safe_check = 0;
			int for_safe_check = 0;
		
				for (int i = 0; i < 9; i++)
				{
					list.Add_Back_from_Array_Dynamic(number_tab);
					//cout << "starting list status" << endl;
					//list.Show();
					for (int j = 0; j < 9; j++)
					{
						random = list.Pick_Random_Value();
						safe_check = 0;
						//cout << "///////////////////////////////////////" << endl;
						while (plane.Already_In_Cross(i, j, random))
						{
							random = list.Pick_Random_Value();
							safe_check++;

							//cout << safe_check << endl;

							// start all over again
							if (safe_check > 11)
							{
								plane.Initiate_value(-1);
								list.Delete_All();
								i = 0;
								j = 0;
								list.Add_Back_from_Array_Dynamic(number_tab);
								break;
							}
							else if (safe_check > 10)
							{
								for (int k = 0; k < 9; k++)
								{
									//cout << "przeszukiwane " << plane(i, k) << endl;
									//Sleep(1000);

									if (plane(i, k) != -1 && !plane.Already_In_Columns(k, random) && !plane.Already_In_Columns(j, plane(i, k)))
									{
										int tmp = plane(i, k);
										plane(i, k) = random;
										for_safe_check = random;
										//cout << "swapped " << tmp << " with " << random << endl;
										random = tmp;
										break;
									}
								}
							}
							else if (safe_check > 9)
							{
								// przejść po kolei cały rządek i sprawdzić czy można zamienić wartości
								// czy tą co wylosowaliśmy pasuje w miejsce innej, czy ta inna pasuje w miejsce gdzie mamy wpisać

								// rząd i
								for (int k = 0; k < 9; k++)
								{
									//cout << "przeszukiwane " << plane(i, k) << endl;
									//Sleep(1000);

									if (plane(i, k) != -1 && !plane.Already_In_Columns(k, random) && !plane.Already_In_Columns(j, plane(i, k)))
									{
										int tmp = plane(i, k);
										plane(i, k) = random;
										for_safe_check = random;
										//cout << "swapped " << tmp << " with " << random << endl;
										random = tmp;
										break;
									}
								}
							}
						}

						plane(i, j) = random;

						// czasami usuwa zły element z listy

						//if (safe_check > 9) cout << "usuwam " << for_safe_check << endl;
						//else cout << "usuwam " << random << endl;

						if (safe_check > 9) list.Delete_Value(for_safe_check);
						else list.Delete_Value(random);

						//cout << "stan listy" << endl;
						//list.Show();

						//plane.Fill_up_visualized(1);
					}
				}

			if (this->Check_If_Correct_Rows_and_Columns()) break;
		}
	}
	void Sudoku::Make_Random_Correct_Vertical_and_Horizontal()
	{
		while (Check_If_Correct_Columns() != true)
		{
			Make_Random_Plane();
		}		
	}

// ~Sudoku plane generetor //




// Interesting Operations //

	int Interesting_Operations::count_ones(int*& tab, int& size)
	{
		int count = 0;
		for (int i = 0; i < size; i++) if (tab[i] == 1) count++;
		return count;
	}
	int Interesting_Operations::max_of_tab(int*& tab, int& size)
	{
		if (tab == nullptr) return 0;

		int max = 0;
		for (int i = 0; i < size; i++)
			if (i == 0 || max < tab[i]) max = tab[i];
		return max;
	}
	int find_index_of_value(int*& tab, int& size, int value)
	{
		if (tab == nullptr) return 0;

		for (int i = 0; i < size; i++) if (tab[i] == value) return i;
		return 0;
	}	
	bool are_all_values_together(int*& tab, int& size, int value)
	{
		if (tab == nullptr) return false;

		bool got_first = false;
		int group_counter = 0;
		for (int i = 0; i < size; i++)
		{
			if (!got_first && tab[i] == value)
			{
				got_first = true;				
			}

			if (got_first && tab[i] != value)
			{
				got_first = false;
				group_counter++;
			}
		}
		if (got_first) group_counter++;

		if (group_counter == 1) return true;
		else return false;
	}


	// wszystkie kombinacje
	void Interesting_Operations::BODY_Permutations(int*& tab, int& size, int*& available_tab, int& limit, ofstream& FILE)
	{
		if (max_of_tab(available_tab, size) != limit)
		{
			for (int i = 0; i < size; i++)
			{
				if (available_tab[i] == 0)
				{
					available_tab[i] = max_of_tab(available_tab, size) + 1;

					BODY_Permutations(tab, size, available_tab, limit, FILE);

					available_tab[i] = 0;
				}
			}
		}
		// koniec rekurencji ---> zapisywanie do pliku
		else
		{
			for (int i = 0; i < limit; i++)
				FILE << tab[find_index_of_value(available_tab, size, i + 1)] << " ";

			FILE << endl;
		}
	}
	void Interesting_Operations::HUB_Permutations(int*& tab, int& size, int& window_size)
	{
		const char* path = "_permutations/permutations.txt";
		int* available_tab = new int[size]; for (int i = 0; i < size; i++) available_tab[i] = 0;
		ofstream FILE(path);
		BODY_Permutations(tab, size, available_tab, window_size, FILE);
		FILE.close();
		delete[] available_tab;

		Txt_Operations txt;
		txt.Delete_empty_spaces(path);
		txt.Read_txt(path);

		// if(deleting_permutation_file) remove(path);
	}
	
	// wszystkie kombinacje bez powtórzeń
	void Interesting_Operations::BODY_Permutations_no_repeat(int*& tab, int& size, int*& available_tab, int& recursion_limit, int starting_index, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE), void(*at_the_end)(int sum, ofstream& FILE), ofstream& FILE)
	{
		if (max_of_tab(available_tab, size) != recursion_limit)
		{
			for (int i = starting_index; i < size; i++)
			{
				if (available_tab[i] == 0)
				{
					available_tab[i] = max_of_tab(available_tab, size) + 1;

					BODY_Permutations_no_repeat(tab, size, available_tab, recursion_limit, i + 1, normal, last, at_the_end, FILE);

					available_tab[i] = 0;
				}
			}
		}
		// koniec rekurencji ---> zapisywanie do pliku
		else
		{
			int looking_for = 1;
			int max_tab = 0;
			for (int i = 0; i < size; i++)
				if (i == 0 || max_tab < available_tab[i]) max_tab = available_tab[i];
			
			int sum = 0;
			while (looking_for <= max_tab)
			{
				for (int i = 0; i < size; i++)
				{
					if (available_tab[i] == looking_for && looking_for != max_tab)
					{
						// cout << tab[i] << " ";

						normal(tab, i, FILE);
						sum += tab[i];
					}
					else if (available_tab[i] == looking_for && looking_for == max_tab)
					{
						// ostatni obrót
						// cout << tab[i] << endl;

						last(tab, i, FILE);
						sum += tab[i];
					}
				}

				looking_for++;
			}

			at_the_end(sum, FILE);
		}
	}
	void Interesting_Operations::HUB_Permutations_no_repeat(int*& tab, int& size, int how_many_in_a_group, ofstream& FILE, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE), void(*at_the_end)(int sum, ofstream& FILE))
	{
		int* available_tab = new int[size]; for (int i = 0; i < size; i++) available_tab[i] = 0;

		BODY_Permutations_no_repeat(tab, size, available_tab, how_many_in_a_group, 0, normal, last, at_the_end, FILE);

		delete[] available_tab;
	}

	// wszystkie kombinacje bez powtórzeń sumujące się do określonej liczby
	void Interesting_Operations::BODY_Permutations_no_repeat_sum(int*& tab, int& size, int*& available_tab, int sum_looking_for, int starting_index, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE), ofstream& FILE)
	{
		if (sum_looking_for != 0)
		{
			for (int i = starting_index; i < size; i++)
			{
				if (available_tab[i] == 0)
				{
					if (sum_looking_for - tab[i] >= 0)
					{
						available_tab[i] = max_of_tab(available_tab, size) + 1;
						BODY_Permutations_no_repeat_sum(tab, size, available_tab, sum_looking_for - tab[i], i + 1, normal, last, FILE);
						available_tab[i] = 0;
					}
				}
			}
		}
		// koniec rekurencji ---> zapisywanie do pliku
		else
		{
			int looking_for = 1;
			int max_tab = 0;
			for (int i = 0; i < size; i++)
				if (i == 0 || max_tab < available_tab[i]) max_tab = available_tab[i];

			while (looking_for <= max_tab)
			{
				for (int i = 0; i < size; i++)
				{
					if (available_tab[i] == looking_for && looking_for != max_tab)
					{
						normal(tab, i, FILE);
					}
					else if (available_tab[i] == looking_for && looking_for == max_tab)
					{
						// ostatni obrót
						last(tab, i, FILE);
					}
				}

				looking_for++;
			}
		}
	}
	void Interesting_Operations::HUB_Permutations_no_repeat_sum(int*& tab, int& size, int sum_looking_for, ofstream& FILE, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE))
	{
		int* available_tab = new int[size]; for (int i = 0; i < size; i++) available_tab[i] = 0;

		BODY_Permutations_no_repeat_sum(tab, size, available_tab, sum_looking_for, 0, normal, last, FILE);

		delete[] available_tab;
	}



	// example
	void Interesting_Operations::basic_call_no_repeat_sum(int* tab, int size, int sum_looking_for)
	{
		if (tab == nullptr) return;
		// int size = 6;
		// int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;
		// int sum_looking_for = 13;

		// const char* path = "_permutations/permutations_no_repeat_sum.txt";
		string path = "_permutations/permutations_no_repeat_sum.txt";
		ofstream FILE(path.c_str());

		HUB_Permutations_no_repeat_sum(tab, size, sum_looking_for, FILE,
			[](int*& tab, int& index, ofstream& FILE) -> void { FILE << tab[index] << " "; },
			[](int*& tab, int& index, ofstream& FILE) -> void { FILE << tab[index] << endl; });

		Txt_Operations txt;
		txt.Delete_empty_spaces(path);
		FILE.close();
	}
	void Interesting_Operations::basic_call_no_repeat_showing_sum(int* tab, int size)
	{
		if (tab == nullptr) return;
		//int size = 6;
		//int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;

		int window = 1;
		while (window != size)
		{
			string path = "_permutations/show_sum_to_all/permutations_no_repeat_" + to_string(window) +".txt";
			ofstream FILE(path.c_str());

			HUB_Permutations_no_repeat(tab, size, window, FILE,
				[](int*& tab, int& index, ofstream& FILE) -> void { FILE << tab[index] << " "; },
				[](int*& tab, int& index, ofstream& FILE) -> void { FILE << tab[index] << " "; },
				[](int sum, ofstream& FILE) -> void { FILE << "== " << sum << endl; });

			Txt_Operations txt;
			txt.Delete_empty_spaces(path);
			FILE.close();

			window++;
		}
	}
	void Interesting_Operations::basic_call_no_repeat(int* tab, int size, int how_many_number_in_group)
	{
		if (tab == nullptr) return;
		//int size = 6;
		//int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;
		//int window = 3;
				
		string path = "_permutations/permutations_no_repeat.txt";
		ofstream FILE(path.c_str());
				
		HUB_Permutations_no_repeat(tab, size, how_many_number_in_group, FILE,
			[](int*& tab, int& index, ofstream& FILE) -> void { FILE << tab[index] << " "; }, 
			[](int*& tab, int& index, ofstream& FILE) -> void { FILE << tab[index] << endl; },
			[](int sum, ofstream& FILE) -> void { /*FILE << sum << endl; */ });

		Txt_Operations txt;
		txt.Delete_empty_spaces(path);
		FILE.close();		
	}
	void Interesting_Operations::basic_call_repeat(int* tab, int size, int how_many_number_in_group)
	{
		if (tab == nullptr) return;
		//int size = 6;
		//int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;
		//int window = 3;

		HUB_Permutations(tab, size, how_many_number_in_group);		
	}

// ~Permutations //





// Statictics //

	void Stats::Testing_Fuction(Time& clock, double& time, const int& how_many_elements)
	{
		Array_Dynamic<int> array;
		array.Make_Random_Array_No_Repeat(how_many_elements, how_many_elements + 1000);
		auto* tab = array.Return_Pointer();
		auto size = array.Return_Size();
		Array_Functions<int> f;

		clock.Start();

		f.Sort_Bubble(tab, size);

		clock.Stop();
		time = clock.Get_how_much_time_passed();
	}

	void Stats::Create_file(const string& name, const int& how_many_repetitions_on_each, const int& start, const int& end, const int& rate_of_increment)
	{
		if (name != "" && how_many_repetitions_on_each > 0 && start < end)
		{
			fstream plik;
			Time clock;
			double time = 0;

			plik.open(name + ".txt", ios::out);
			plik << "Bubble sort" << endl;

			// jeszcze nie uwzględniłem how_many_repetitions_on_each

			for (int i = start; i < end; i += rate_of_increment)
			{

				Testing_Fuction(clock, time, start);

				plik << i << " " << time << endl;
				//cout << i << " done " << endl;
			}

			plik.close();
			cout << "porobione" << endl;
		}
	}

// ~Statictics //