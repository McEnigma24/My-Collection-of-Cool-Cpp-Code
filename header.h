#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <memory>
#include "windows.h"
#include <thread>

#include <array>
#include <vector>
#include <list>

#include <map>
//#include <hash_map>
#include <unordered_map>

//using namespace  std;

using std::cout; using std::string; using std::endl; using std::fstream; using std::ofstream; using std::ifstream; using std::list; using std::unique_ptr; using std::shared_ptr; using std::weak_ptr;

//                                                                                MO¯E DOROBIÆ ¯EBY KA¯DA KLASA MIA£A POLE name, i podczas wyœwietlania bêdzie wyœwietla³a to
//																				  ¿eby nie trzeba by³o pisaæ za ka¿dym razem siur
//                                                                                2 konstruktory, jeœli nie okreœlisz nazwy to nic nie bêdzie pisa³
//                                                                                jak okreœlisz to bêdzie pisa³ za ka¿dym razem jak wyœwietlisz

// CLOCKS_PER_SEC zosta³ manualnie zdefiniowany
#define MY_CLOCKS_PER_SEC 1000
#define endl "\n"
// Declarations to not necessarily use orderkc
template<typename T> class Random_Value;
template <typename T> class Matrix;
template<typename T> class Unique_ptr;
template<typename T> class Shared_ptr;
template <typename T> class Variables_Limits;
template <typename T> class Stack;
template <typename T> class Queue;
template<typename T> class List; 
template<typename T, typename R> class List_Multivalue;
template <typename T> class Array_Functions;
template<typename T, int N> class Array_template_trick;
template<typename T> class Array_Dynamic;
class String;
class Word_Cross;
class Time;
class Time_Scope;
class Search_Patterns;
class Number_Bases;
class Stats;
class Sudoku;
class Interesting_Recursion;

#ifdef DEBUG
#define LOG(x) cout << x << endl
#else
#define LOG(x)
#endif


////////////////////////////////////////////                     mo¿e ¿eby zrobiæ, ¿e Time_Scope jakoœ zwraca napis 0h - 4m - 20s gdzieœ do jakiejœ zmiennej String albo zapisuje to do pliku
//																 do Stringa, a liczby bêd¹ funkcj¹ Parse_Int()
//Time Control//
class Time
{
	clock_t start, stop;

public:

	Time();
	void Start();
	void Stop();
	double Get_how_much_time_passed();
	void Show_how_much_time_passed();	
};

class Time_Scope
{
private:
	double start;
	double stop;
	string scope_name;
	unsigned int endlines_before;
	unsigned int endlines_after;

public:
	Time_Scope(const string& name, int endlines_before_, int endlines_after_);
	~Time_Scope();	
};

class starting
{
	double start;
	double stop;

public:
	starting()
	{
		cout << "starting.... ";
		start = clock();
	}
	~starting()
	{
		stop = clock();
		double diff = (stop - start) / CLOCKS_PER_SEC;

		cout << "done --- took: " << diff << "s" << endl;
	}
};


////////////////////////////////////////////
//Variable Max and Min values//
//Mo¿na zrobiæ tak, ¿e dla ka¿dego typu jest specjalizacja templata i 
//dla ka¿dego s¹ inne funkcje dostêpne ale maj¹ t¹ sam¹ nazwê tylko inne body
//bo ka¿da zmienna ma inne wartoœci max i mini
template <typename T>
class Variables_Limits
{
public:
	double Double_Max_Value()
	{
		double i = 0;
		i = !i;

		return i;
	}

	unsigned long long Unsigned_Long_Max_Value()
	{
		unsigned long long i = 0;
		i = ~i;

		return i;
	}

	unsigned int Unsigned_Int_Max_Value()
	{
		unsigned int i = 0;
		i = ~i;

		return i;
	}

	unsigned int Int_Max_Value()
	{
		unsigned int i = 0;
		i = ~i;
		i >>= 1;

		return i;
	}

	void Show_Int_Max_Value()
	{
		cout << "Int max value:           " << Int_Max_Value() << endl;
	}
	void Show_Unsigned_Int_Max_Value()
	{
		cout << "Unsigned Int max value:  " << Unsigned_Int_Max_Value() << endl;
	}
	void Show_Unsigned_Long_Max_Value()
	{
		cout << "Unsigned Long max value: " << Unsigned_Long_Max_Value() << endl;
	}
	void Show_Double_Max_Value()
	{
		cout << "Double max value:        " << Double_Max_Value() << endl;
	}
};


////////////////////////////////////////////                                   
//																				+ Try_Parse() - DONE
//																				+ Operator - overload
//																			    + zamiana z binarnego / ósemkowego / szesnatkowego na dziesiêtny ale to w clasie Number_Bases		
//																				+ Contains 1 jako char, 1 jako inny String. Overload funkcji																		
//Mój String//
class String
{
private:
	char* tab;
	int size;
	char for_execptions;

public:
	String();
	String(const char* input);
	~String();
	String(const String& other);
	String(String&& other) noexcept;

	String& operator=(const String& other);
	String& To_String(long long input);
	int& Get_Size();
	char*& Get_Tab();

	void Print();
	void Reverse();
	int Length();
	bool Is_Empty();
	void Replace(char old_char, char new_char);

	// + += dopisuj¹ na koniec	
	String& operator+(const String& other);
	String& operator+(const char* input);
	String& operator+(const char input);
	String& operator+=(const String& other);
	String& operator+=(const char* input);
	String& operator+=(const char input);

	// sort by alphabet order
	bool operator>(const String& other);
	bool operator<(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	bool operator>=(const String& other);
	bool operator<=(const String& other);

	String Password_Generetor(String allowed_characters, int how_long);
	String Password_Generetor_basic_set(int how_long);

	// sort strings of numbers
	short int Which_number_is_bigger(String one, String two);

	// contains
	bool operator^(const char& key);

	
	// -= usuwa wszystkie litery ze String
	String& operator-=(const char input);

	String& cut_from_string();	
	// - usuwa poszczególne wyrazy
	String& operator-(const String& other);

	// []
	char& operator[](int index);

	//Turn String (mój) na liczbê, spróbowaæ dla intów bo double bêdzie znacznie ciê¿szy//
	// zwraca int, bierze String
	int Parse_to_Int();

	// Przepatruje tablice char i patrzy czy wystêpuj¹ce tam znaki to tylko liczby i -, jak co kolwiek innego to mówi, ¿e nie mo¿e zmieniæ
	bool Try_Parse_to_Int();


private:

	bool Contains_for_Try_Parse(const char* all_numbers, const int& size, const char& this_char);
	int which_word_is_first_in_alphabet(const char* a, const char* b, unsigned int size_a, unsigned int size_b);
	int which_character_is_first_in_alphabet(const char& a, const char& b);
	//int* Brute_Force_Approach_returns_table_of_index(String& full_tekst, String& pattern, int& size);

public:
	friend std::ostream& operator<<(std::ostream& os, const String& obj);
};

class JumpingString
{
	list<char*> tab_list;
	list<int> size_list;

public:

	JumpingString();	
	JumpingString(const char* input);
	JumpingString(JumpingString& other);
	JumpingString operator=(JumpingString& other);
	JumpingString operator=(const char* input);
	~JumpingString();
	
	int Count_in_Total();
	char* Combine_to_One();
	void Add(const char* input);
	void Print();

	void operator+=(const char* input);
};


// Test for Move Semantics //
class Entity_Bad_Allocation
{
	String name;
public:
	Entity_Bad_Allocation(const String& n)
		:name(n)
	{
		cout << "Created Entity" << endl;
	}

	~Entity_Bad_Allocation()
	{
		cout << "Deleting Entity_Bad_Allocation..." << endl;
	}

	void Show()
	{
		cout << name << endl << endl;
	}
};

class Entity_with_Move
{
	String name;
public:
	Entity_with_Move(String&& n)
		:name((String&&)n)
	{
		cout << "Created Entity" << endl;
	}

	~Entity_with_Move()
	{
		cout << "Deleting Entity_with_Move..." << endl;
	}

	void Show()
	{
		cout << name << endl << endl;
	}
};


// Testing SmartPointers
class Testing_Smart
{
	int size;
	std::unique_ptr<int[]> ptr;

public:
	Testing_Smart(int a)
		:size(a), ptr(std::make_unique<int[]>(size)) {}

	void Make_Matrix()
	{
		//unique_ptr<int[]> tmp = make_unique<int[]>(size);
		
		


		//for (int i = 0; i < size; i++)
			//ptr[i] = std::unique_ptr<int[]>(new int(size));
	}

};

template<typename T>
class Array_1d_like_2d
{
	int rows;	int columns;
	T* tab;

public:

	Array_1d_like_2d(int r, int c)
		:rows(r), columns(c)
	{
		tab = new T[rows * columns]{};
	}
	~Array_1d_like_2d()
	{
		delete[] tab;
	}

	void tabFillUp()
	{
		int c = 1;
		for (int i = 0; i < rows * columns; i++) { tab[i] = c; c++; }
	}

	void printMatrix()
	{
		cout << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << tab[j + (i * rows)] << "	";
			}
			cout << endl;
		}
	}
	void print()
	{
		cout << endl;
		for (int i = 0; i < rows * columns; i++) cout << tab[i] << endl;
	}


	T& operator()(int i, int j)
	{
		return tab[j + (i * rows)];
	}
};


////////////////////////////////////////////
// File Operations
class Txt_Operations
{
public:

	string Load_txt(string path)
	{
		ifstream file((path).c_str());

		if (file.good())
		{
			string result = "";
			string tmp;
			while (!file.eof())
			{
				file >> tmp;
				result += tmp;
			}
			return result;
		}
		return "";
	}
	int Check_how_many_lines_not_empty(string path)
	{
		ifstream file((path).c_str());

		int counter = 0;

		if (file.good())
		{
			string tmp;
			while (!file.eof())
			{
				getline(file, tmp);
				if(tmp != "") counter++;
			}
		}

		return counter;
	}

	int Check_how_many_lines(string path)
	{
		ifstream file((path).c_str());

		int counter = 0;

		if (file.good())
		{
			string tmp;
			while (!file.eof())
			{
				getline(file, tmp);
				counter++;
			}			
		}

		return counter;
	}
	void Read_txt(string path)
	{
		ifstream file((path).c_str());
		int lines = Check_how_many_lines(path);
		int lines_not_empty = Check_how_many_lines_not_empty(path);

		cout << "File " << path << " - not empty lines: " << lines_not_empty << endl << "total lines: " << lines << endl;
		if (file.good())
		{			
			string tmp;
			while (!file.eof())
			{
				getline(file, tmp);
				cout << tmp << endl;;
			}			
		}
	}

	// deletes original after change
	void Correnct_txt_change_single_character(string path, string output_file_name_and_path, char old, char better)
	{
		ifstream file_in((path).c_str());
		ofstream file_out((output_file_name_and_path).c_str());

		if (!(file_in.good())) return;

		char t;
		string line;
		while (!file_in.eof())
		{
			file_in >> line;

			for (int i = 0; i < (int)line.length(); i++)
			{
				t = line[i];
				if (t == old) t = better;
				file_out << t;
			}
			file_out << endl;
		}

		file_in.close();
		file_out.close();
		remove(path.c_str());
	}
	void Copy_txt_from_one_to_another(string source, string destination)
	{
		ifstream fsource((source).c_str());
		ofstream fdestination((destination).c_str());
		
		if (fsource.good() && fdestination.good())
		{
			string tmp;

			bool first = true;
			while (!fsource.eof())
			{
				if (first) first = false;
				else fdestination << endl;
				getline(fsource, tmp);
				fdestination << tmp;
			}
		}

		fsource.close();
		fdestination.close();
	}

	void Delete_empty_spaces(string path)
	{
		ifstream file((path).c_str());

		ofstream no_empty_spaces("empty_spaces_tmp.txt");
		if (file.good())
		{
			string tmp;

			bool first = true;
			while (!file.eof())
			{
				getline(file, tmp);

				if (tmp != "")
				{
					if (first) first = false;
					else no_empty_spaces << endl;
					no_empty_spaces << tmp;
				}
			}
		}
		file.close();
		no_empty_spaces.close();

		Copy_txt_from_one_to_another("empty_spaces_tmp.txt", (path).c_str());
		remove("empty_spaces_tmp.txt");
	}
};


////////////////////////////////////////////                                                          + Opcja dla stringów
// Random Value//
template<typename T>
class Random_Value {};
template<> class Random_Value<char>
{
public:
	char return_random_value_mine()
	{
		String alphabet = "abcdefghijklmnopqrstuvwxyz";
		int random = rand() % (alphabet.Length());

		return alphabet[random];
	}
	char return_random_value_mine(int range)
	{
		String alphabet = "abcdefghijklmnopqrstuvwxyz";
		int random = rand() % (alphabet.Length()) % range;

		return alphabet[random];
	}
	char return_random_value_mine(String& availeble_letters)
	{		
		int random = rand() % (availeble_letters.Length());

		return availeble_letters[random];
	}
};
template<> class Random_Value<int>
{
public:
	int return_random_value_mine(int range)
	{
		int random = rand() % range;
		return random;
	}
};
template<> class Random_Value<String>
{
public:
	String return_random_value(int how_long)
	{
		String alphabet = "abcdefghijklmnopqrstuvwxyz";
		String tmp = "";

		int ran = 0;
		int range = alphabet.Length();
		for (int i = 0; i < how_long; i++)
		{
			ran = rand() % range;
			tmp += alphabet[ran];
		}
		return tmp;
	}

	String return_random_value_alphabet_plus_numbers(int how_long)
	{
		String alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
		String tmp = "";

		int ran = 0;
		int range = alphabet.Length();
		for (int i = 0; i < how_long; i++)
		{
			ran = rand() % range;
			tmp += alphabet[ran];
		}
		return tmp;
	}

	String return_random_value(String& range, int how_long)
	{
		if (range == "") return "";

		int lentgh = range.Length();
		String tmp = "";		
		for (int i = 0; i < how_long; i++)
		{
			tmp += range[rand() % lentgh];
		}
		return tmp;
	}
};












///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////															Jak robie struktury to dodawaæ size, ¿eby nie trzeba by³o liczyæ tylko wyci¹gn¹æ wartoœæ
///////////////////////////////////////															A jak nie chcesz, ¿eby mo¿na by³o edytowaæ i coœ przez przypadek zepsuæ to robiæ tak
///////////////////////////////////////															pole jest prywatne i metoda zwraca sam¹ wartoœæ, jakby zwróci³o referencjê to mo¿na by by³o edytowaæ

////////////////////////////////////////////
//Stack//
template <typename T>
class Stack
{
	class node
	{
	public:
		T value = (T)0;
		node* pnext = nullptr;

		void Delete_All()
		{
			if (this->pnext != nullptr) this->pnext->Delete_All();
			delete this;
		}
	};

	node* top;
	unsigned int stack_size;

public:
	Stack()
	{
		top = nullptr;
		stack_size = 0;
	}
	~Stack()
	{
		if (top != nullptr)
		{
			top->Delete_All();
		}
	}
	Stack(Stack<T>& other)
	{
		if (!other.Is_Empty())
		{
			top = nullptr;
			node* obj = other.Get_Top();

			while (true)
			{
				this->Push(obj->value);

				if (obj->pnext != nullptr) obj = obj->pnext;
				else break;
			}

			this->Invert();
		}
		else
		{
			top = nullptr;
		}
	}

	node* Get_Top()
	{
		return top;
	}
	void Push(T value)
	{
		node* obj = new node;
		obj->value = value;

		if (top == nullptr)
		{
			obj->pnext = nullptr;			
		}
		else
		{
			obj->pnext = top;
		}
		top = obj;
	}
	void Push_unique(T value)
	{
		if (!Containes(value)) Push(value);
	}
	void Clear()
	{
		while (top != nullptr)
		{
			this->Pop();
		}
	}
	void Show_All()
	{
		if (top == nullptr) cout << "na stosie nie na zadnych obiektow" << endl;
		else
		{
			cout << endl;
			node* tmp = top;
			int i = 1;
			while (tmp != nullptr)
			{
				cout << i << ". " << tmp->value << endl;
				i++;
				tmp = tmp->pnext;
			}
			cout << endl;
		}
	}
	void Invert()
	{		
		int size = 0;
		T* tab = this->Return_Tab(size);
		
		/*Array_Functions<T> a;
		for (int i = 0; i < size; i++)
		{
			a.Reverse_Functions(tab, size);
		}	*/	

		this->Clear();
		for (int i = 0; i < size; i++)
		{
			this->Push(tab[i]);
		}
		delete[] tab;
	}
	int Count()
	{
		if (top == nullptr) return 0;
		else
		{
			node* tmp = top;
			int count = 0;
			while (tmp != nullptr)
			{
				count++;
				tmp = tmp->pnext;
			}
			return count;
		}
	}
	bool Is_Empty()
	{
		if (top == nullptr) return true;
		else return false;
	}
	bool Containes(T key)
	{
		if (top == nullptr) return false;
		else
		{
			node* tmp = top;
			while (tmp != nullptr)
			{
				if (tmp->value == key) return true;
				tmp = tmp->pnext;
			}
			return false;
		}
	}
	T Pop()
	{
		if (top == nullptr) return 0;
		else if (top->pnext == nullptr)
		{
			T value = top->value;
			delete top;
			top = nullptr;
			return value;
		}
		else
		{
			T value = top->value;
			node* tmp = top;
			top = top->pnext;
			delete tmp;
			return value;
		}
	}
	T Peek()
	{
		if (top != nullptr) return top->value;
		else return 0;
	}
	T* Return_Tab(int& size)
	{
		if (top == nullptr) return nullptr;
		else
		{
			node* obj = top;
			size = this->Count();
			T* tab = new T[size];

			for (int i = 0; i < size; i++)
			{
				tab[i] = obj->value;
				obj = obj->pnext;
			}

			return tab;
		}
	}
	void Push_from_tab(T* tab, const int& size)
	{
		if (tab == nullptr) cout << "tab to nullptr" << endl;
		else
		{
			for (int i = 0; i < size; i++)
			{
				this->Push(tab[i]);
			}
		}
	}
};


////////////////////////////////////////////
//Queue//
template <typename T>
class Queue
{
	class node
	{
	public:
		T value = (T)0;
		node* pnext = nullptr;
		node* pbefore = nullptr;

		void Delete_All()
		{
			if (this->pnext != nullptr) this->pnext->Delete_All();
			delete this;
		}
	};

	node* first;
	node* last;

public:
	Queue()
	{
		first = nullptr;
		last = nullptr;
	}
	~Queue()
	{
		if (last != nullptr)
		{
			last->Delete_All();
		}
	}

	void Enque(T val)
	{
		node* obj = new node;
		obj->value = val;

		if (first == nullptr)
		{
			first = obj;
			last = obj;
			obj->pnext = nullptr;
			obj->pbefore = nullptr;
		}
		else
		{
			obj->pbefore = nullptr;
			obj->pnext = last;
			last->pbefore = obj;
			last = obj;
		}
	}
	void Enque_unique(T val)
	{
		if (!Contains(val)) Enque(val);
	}
	T Deque()
	{
		if (first == nullptr) return (T)0;
		else if (first->pbefore == nullptr)
		{
			T value = first->value;
			delete first;
			first = nullptr;
			last = nullptr;
			return value;
		}
		else
		{
			node* tmp = first;
			T value = first->value;

			first = first->pbefore;
			first->pnext = nullptr;
			delete tmp;
			return value;
		}
	}
	T Peek()
	{
		if (first == nullptr) return (T)0;
		else return first->value;
	}
	void Show_All()
	{
		if (first == nullptr) cout << "nie ma nic w kolejce" << endl;
		else
		{
			node* obj = first;
			cout << endl;

			int i = 1;
			while (obj != nullptr)
			{
				cout << i << ". " << obj->value << endl;
				i++;
				obj = obj->pbefore;
			}
			cout << endl;
		}
	}
	void Clear()
	{
		if (first != nullptr)
		{
			while (first != nullptr)
			{
				this->Deque();
			}
		}
	}
	int Count()
	{
		if (first == nullptr) return 0;
		else
		{
			int i = 0;
			node* obj = first;
			while (obj != nullptr)
			{
				i++;
				obj = obj->pbefore;
			}
			return i;
		}
	}
	T* Return_Tab(int& size)
	{
		if (first == nullptr) return nullptr;
		else
		{
			size = this->Count();
			node* obj = first;
			T* tab = new T[size];

			for (int i = 0; i < size; i++)
			{
				tab[i] = obj->value;
				obj = obj->pbefore;
			}
			return tab;
		}
	}
	bool Contains(T key)
	{
		if (first == nullptr) return false;
		else
		{
			node* obj = first;

			while (obj != nullptr)
			{
				if (obj->value == key) return true;
				obj = obj->pbefore;
			}
			return false;
		}
	}
	void Enque_from_tab(T* tab, const int& size)
	{
		if (tab == nullptr) cout << "tablica jest pusta" << endl;
		else
		{
			for (int i = 0; i < size; i++)
			{
				this->Enque(tab[i]);
			}
		}
	}
};


////////////////////////////////////////////
//																								+ funkcja do liczenia czy s¹ powtórzenia i jakie wystêpuj¹
//																								+ Funkcja co zmienia uk³ad elementów w liœcie na taki jaki zosta³ podany do funckji w postaci tablicy wartoœci
//																								  musi byæ tyla samo elementów co wartoœci na liœcie, bêdzie sprawdza³ czy dana wartoœæ jest na w³aœciwej pozycji
//																								  jak nie to go zmienia z t¹ wartoœcia gdzie powinna byæ i patrzy dalej, funkcja swap na liœcie
//List one element//
template<typename T>
class List
{
	class list
	{
	public:
		// int index; moze po prostu dac // wtedy tylko trzeba pozmieniac przy dodawaniu, usuwaniu i jakichs zamianach miejsc 
		// ale w sumie zawsze mozna po jakiejs operacji wywylac funkcje co przejdzie od poczatku i nada wartosci indexow
		T value = (T)0;
		list* pnext = nullptr;

		void Delete_all_list()
		{
			if (this->pnext != nullptr) (this->pnext)->Delete_all_list();
			delete this;
		}
		int Count_them_all()
		{
			int i = 1;

			if (this->pnext != nullptr) i += (this->pnext)->Count_them_all();
			return i;
		}
		void Iterate_to_pnext(list*& obj)
		{
			if (obj != nullptr)
			{
				if (obj->pnext != nullptr) obj = obj->pnext;
				else obj = nullptr;
			}
		}
		list* Iterator_better()
		{
			if (this->pnext != nullptr) return this->pnext;
			else return nullptr;
		}
	};

	typedef list* iterator;

	list* phead;
	list* last;
	int list_size;

public:
	List()
		:phead(nullptr), last(nullptr), list_size(0)
	{
	}
	~List()
	{
		if (phead != nullptr)
		{
			phead->Delete_all_list();
		}
	}

	list* Get_phead()
	{
		return phead;
	}
	list* Get_last()
	{
		return last;
	}
	list* Get_one_before(list* obj)
	{
		if (phead == nullptr || last == nullptr) return nullptr;
		else if (obj == phead) return nullptr;
		else
		{
			list* one_before = phead;

			while (one_before != nullptr)
			{
				if (one_before->pnext == obj) return one_before;
				one_before = one_before->pnext;
			}
			return nullptr;
		}
	}
	int Get_list_size()
	{
		return list_size;
	}

	iterator begin() { return phead; }
	iterator end() { return last; }

	void Show()
	{
		if (phead == nullptr) cout << "nie ma co wyswietlac" << endl;
		else
		{
			list* obj = phead;
			int i = 1;
			while (true)
			{
				cout << i << ". " << obj->value << endl;
				i++;

				if (obj->pnext != nullptr) obj = obj->pnext;
				else break;
			}
			cout << endl;
		}
	}
	int Count()
	{
		if (phead == nullptr) return 0;
		else return phead->Count_them_all();
	}
	bool Containes(T val)
	{
		if (phead == nullptr) return false;

		list* obj = phead;
		while (true)
		{
			if (obj->value == val) return true;

			if (obj->pnext != nullptr) obj = obj->pnext;
			else return false;
		}
	}
	void Add_Back(T val)
	{
		list_size++;
		if (phead == nullptr)
		{
			list* obj = new list;
			obj->value = val;
			obj->pnext = nullptr;
			phead = obj;
			last = obj;
		}
		else
		{
			list* obj = new list;
			obj->value = val;
			obj->pnext = nullptr;

			last->pnext = obj;
			last = obj;
		}
	}
	void Add_Back_from_tab(T* tab, const int& size)
	{		
		for (int i = 0; i < size; i++)
		{			
			this->Add_Back(tab[i]);
		}
	}
	void Add_Back_from_Array_Dynamic(Array_Dynamic<T>& obj)
	{
		T* pointer = obj.Return_Pointer();
		int size = obj.Return_Size();		
		if (pointer == nullptr || size < 1) return;

		Add_Back_from_tab(pointer, size);
	}

	void Delete_All()
	{
		list_size = 0;
		if (phead == nullptr);//cout << "nie ma co usuwac" << endl;
		else
		{
			phead->Delete_all_list();
			phead = nullptr;
			last = nullptr;
		}
	}
	void Delete_Adress(list* to_delete)
	{		
		if (phead != nullptr && last != nullptr && to_delete != nullptr)
		{
			//cout << "wlasnie usuwam " << to_delete->value << endl;

			list_size--;
			if (to_delete == phead)     // usuwamy phead
			{
				if (phead->pnext == nullptr) // list to tylko phead
				{
					delete phead;
					phead = nullptr;
					last = nullptr;
				}
				else // jest cos wiecej w liscie
				{
					list* tmp = phead;
					phead = phead->pnext;
					delete tmp;
				}
			}
			else if (to_delete == last) // usuwamy ostatniego
			{
				list* one_before = Get_one_before(to_delete);

				one_before->pnext = nullptr;
				delete to_delete;
			}
			else                         // usuwamy obiet w œrodku
			{
				list* one_before = Get_one_before(to_delete);
				if (one_before == nullptr)
				{
					cout << "nie znalazl takiego obiektu w tej liscie" << endl;
					return;
				}

				list* one_after = to_delete->pnext;


				one_before->pnext = one_after;
				delete to_delete;
			}
		}

	}
	void Delete_All_Adresses_Stack(T key)
	{
		Stack<list*> stack;
		Adress_of_all_values(key, stack);

		if (!stack.Is_Empty())
		{
			int limit = stack.Count();
			for (int i = 0; i < limit; i++)	Delete_Adress(stack.Pop());
		}
	}
	bool Are_there_any_repetitions()
	{
		if (phead == nullptr) return false;
		
		list* obj = phead;
		list* smaller_obj = nullptr;
		T starting_value;
		while (true)
		{
			smaller_obj = obj; 
			starting_value = smaller_obj->value;

			if (smaller_obj->pnext != nullptr)
			{
				smaller_obj = smaller_obj->pnext;
				while (true)
				{
					if (smaller_obj->value == starting_value) return true;

					if (smaller_obj->pnext != nullptr) smaller_obj = smaller_obj->pnext;
					else break;
				}
			}

			if (obj->pnext != nullptr) obj = obj->pnext;
			else return false;
		}
	}

	// mo¿e byæ wiêcej ni¿ jedna taka wartoœæ                          + Funkcja do liczenia ile jest obiektów o jakiejœ wartoœci i wrzuciæ je wszystkie do tablicy i iteracyjnie usuwaæ

	void Delete_Value(const T& key)
	{
		list* to_delete = Adress_of_value(key);
		if (to_delete != nullptr) Delete_Adress(to_delete);
	}
	void Delete_Index(const int& index)
	{
		list* to_delete = Adress_of_index(index);
		if (to_delete != nullptr) Delete_Adress(to_delete);
	}
	list* Adress_of_value(T key)
	{
		if (phead != nullptr && last != nullptr)
		{
			list* obj = phead;

			while (obj != nullptr)
			{
				if (key == obj->value) return obj;
				phead->Iterate_to_pnext(obj);
			}
			return nullptr;
		}
		else return nullptr;
	}
	void Adress_of_all_values(T& key, Stack<list*>& stack)
	{
		if (phead != nullptr)
		{
			list* obj = phead;
			for (unsigned int i = 0; i < list_size; i++)
			{
				if (obj->value == key) stack.Push(obj);
				obj = obj->pnext;
			}
		}
	}

	list* Adress_of_index(const int& index)
	{
		if (phead != nullptr && last != nullptr)
		{
			list* obj = phead;
			int size = Count();

			for (int i = 0; i < index; i++)
			{
				if (obj->pnext != nullptr) phead->Iterate_to_pnext(obj);
				else return nullptr;
			}

			return obj;
		}
		else return nullptr;
	}
	void Set_phead_last(list* new_phead)
	{
		if (new_phead == nullptr) cout << "new phead to NULL" << endl;
		else
		{
			phead = new_phead;

			list* obj = phead;
			while (true)
			{
				if (obj->pnext != nullptr) obj = obj->pnext;
				else break;
			}
			last = obj;
		}
	}
	void Reverse()
	{
		int size = this->Count();
		T* tab = new T[size];

		list* obj = phead;

		for (int i = size - 1; i >= 0; i--)
		{
			tab[i] = obj->value;
			obj = obj->pnext;
		}

		List<T> reversed;
		for (int i = 0; i < size; i++) reversed.Add_Back(tab[i]);

		this->Delete_All();
		this->Set_phead_last(reversed.Get_phead());
	}
	int Index_of(T key)
	{
		if (phead == nullptr) return -1;

		list* obj = phead;
		int i = 0;
		while (true)
		{
			if (key == obj->value) return i;
			i++;

			if (obj->pnext != nullptr) obj = obj->pnext;
			else return -1;
		}
	}
	T Value_of_Index(const int& index)
	{
		if (index < 0) return 0;
		else
		{
			list* obj = phead;

			int i = 0;
			while (obj != nullptr)
			{
				if (i == index) return obj->value;

				i++;
				obj = obj->pnext;
			}
			return (T)0;
		}
	}
	T Pick_Random_Value()
	{
		if (phead == nullptr) return (T)0;
		else
		{
			//cout << "zliczonych" << Count() << endl;
			//cout << "list size is " << list_size << endl;
			int random = rand() % list_size;
			return Value_of_Index(random);
		}
	}
	T Pick_Random_Value_delete_after()
	{
		if (phead == nullptr) return (T)0;
		else
		{
			T tmp = this->Pick_Random_Value();
			this->Delete_Value(tmp);
			return tmp;
		}
	}

	T* to_array()
	{
		list* iterator = phead;

		int size = Count(); if (size == 0) return nullptr;
		T* tab = new T[Count()];

		int i = 0;
		while (iterator)
		{
			tab[i] = iterator->value;

			iterator = iterator->Iterator_better();
			i++;
		}
		
		return tab;
	}
};


//List multiple element of the same type//
template<typename T, typename R>
class List_Multivalue
{
	class linked_obj
	{
	public:
		T main_value;
		R* value_tab = nullptr;
		//shared_ptr<R> shared_v_tab;
		int size_of_value_tab = 0;
		linked_obj* pnext = nullptr;

		void Delete_all_linked_obj()
		{
			linked_obj* next_to_delete = nullptr;
			linked_obj* obj = this;

			while (true)
			{
				if (obj->pnext != nullptr)
				{
					next_to_delete = obj->pnext;
					delete obj;
					obj = next_to_delete;
				}
				else
				{
					delete obj;
					break;
				}
			}
		}

		linked_obj() {}
		linked_obj(T mv, R* vt, int size)
		{
			main_value = mv;
			pnext = nullptr;

			R* new_dynamic_tab = new R[size];
			for (int i = 0; i < size; i++) new_dynamic_tab[i] = vt[i];

			value_tab = new_dynamic_tab;
			size_of_value_tab = size;

			//shared_v_tab = make_shared<R>();				
			// bez delete bo to moze byc zalokowane na stosie
			//delete[] vt;
		}
		~linked_obj()
		{
			if (value_tab != nullptr) delete[] value_tab;
			//shared_v_tab = nullptr;
		}
	};

	linked_obj* phead = nullptr;
	linked_obj* last = nullptr;

public:

	~List_Multivalue()
	{
		if (phead != nullptr) phead->Delete_all_linked_obj();
	}
	linked_obj* Get_phead()
	{
		return phead;
	}
	linked_obj* Get_last()
	{
		return last;
	}

	void Add_Back_Constructor(const T val, R* tab, const int& size)
	{
		if (phead == nullptr)
		{
			linked_obj* obj = new linked_obj(val, tab, size);
			phead = obj;
			last = obj;
		}
		else
		{
			linked_obj* obj = new linked_obj(val, tab, size);
			last->pnext = obj;
			last = obj;
		}
	}
	void Delete_All()
	{
		if (phead == nullptr) cout << "nie ma co usuwac" << endl;
		else
		{
			phead->Delete_all_linked_obj();
			phead = nullptr;
			last = nullptr;
		}
	}

	void Add_Back(const T val, const R* tab, const int& size) //czyœci zawartosc podawanej tablicy	
	{
		if (phead == nullptr)
		{
			linked_obj* obj = new linked_obj;
			obj->main_value = val;
			obj->pnext = nullptr;

			R* new_dynamic_tab = new R[size];
			for (int i = 0; i < size; i++) new_dynamic_tab[i] = tab[i];

			obj->value_tab = new_dynamic_tab;
			obj->size_of_value_tab = size;
			// bez delete bo to moze byc zalokowane na stosie
			//delete[] tab;



			phead = obj;
			last = obj;
		}
		else
		{
			linked_obj* obj = new linked_obj;
			obj->main_value = val;
			obj->pnext = nullptr;

			R* new_dynamic_tab = new R[size];
			for (int i = 0; i < size; i++) new_dynamic_tab[i] = tab[i];

			obj->value_tab = new_dynamic_tab;
			obj->size_of_value_tab = size;
			// bez delete bo to moze byc zalokowane na stosie
			//delete[] tab;

			last->pnext = obj;
			last = obj;
		}
	}
	void Add_Back_Unique(const T val, const R* tab, const int& size)
	{
		if (!Containes(val)) Add_Back(val, tab, size);
	}
	void Show()
	{
		if (phead == nullptr) cout << "nie ma co wyswietlac" << endl;
		else
		{
			linked_obj* obj = phead;
			int i = 1;
			while (true)
			{
				cout << i << " <-- " << obj->main_value << endl;
				i++;

				for (int i = 0; i < obj->size_of_value_tab; i++) cout << obj->value_tab[i] << endl;
				cout << endl;

				if (obj->pnext != nullptr) obj = obj->pnext;
				else break;
			}
			cout << endl;
		}
	}
	int Count()
	{
		if (phead == nullptr) return 0;

		int i = 0;
		linked_obj* obj = phead;
		while (true)
		{
			i++;
			if (obj->pnext != nullptr) obj = obj->pnext;
			else break;
		}
		return i;
	}
	void Set_phead_last(linked_obj* new_phead)
	{
		if (new_phead == nullptr) cout << "new phead to NULL" << endl;
		else
		{
			phead = new_phead;

			linked_obj* obj = phead;
			while (true)
			{
				if (obj->pnext != nullptr) obj = obj->pnext;
				else break;
			}
			last = obj;
		}
	}
	void Reverse()
	{
		int size = this->Count();
		T* tab = new T[size];

		linked_obj* obj = phead;

		for (int i = size - 1; i >= 0; i--)
		{
			tab[i] = obj->main_value;
			obj = obj->pnext;
		}

		List<T> reversed;
		for (int i = 0; i < size; i++) reversed.Add_Back(tab[i]);

		this->Delete_All();
		this->Set_phead_last(reversed.Get_phead());
	}
	bool Containes(T key)
	{
		if (phead == nullptr) return false;

		linked_obj* obj = phead;
		while (true)
		{
			if (obj->main_value == key) return true;

			if (obj->pnext != nullptr) obj = obj->pnext;
			else return false;
		}
	}
	int Index_of(T key)
	{
		if (phead == nullptr) return -1;

		linked_obj* obj = phead;
		int i = 0;
		while (true)
		{
			if (key == obj->main_value) return i;
			i++;

			if (obj->pnext != nullptr) obj = obj->pnext;
			else return -1;
		}
	}
	T Item(const int& index)
	{
		if (index < 0) return 0;
		else
		{
			linked_obj* obj = phead;
			for (int i = 0; i != index; i++)
			{
				if (obj->pnext != nullptr) obj = obj->pnext;
				else return 0;
			}
			return obj->main_value;
		}
	}
	linked_obj* Adress_for(T key)
	{
		if (phead == nullptr) return nullptr;

		linked_obj* obj = phead;

		while (obj != nullptr)
		{
			if (obj->main_value == key) return obj;

			obj = obj->pnext;
		}
		return nullptr;
	}

	// cos tu nie dziala
	/*template <>
	string List_Multivalue<string, R>::Item(const int& index)
	{
		if (index < 0) return "nie ma takiego indeksu";
		else
		{
			linked_obj* obj = phead;
			for (int i = 0; i != index; i++)
			{
				if (obj->pnext != nullptr) obj = obj->pnext;
				else return "nie ma takiego indeksu";
			}
			return obj->value;
		}
	}
	template<>
	char List_Multivalue<char, R>::Item(const int& index)
	{
		if (index < 0) return 'n';
		else
		{
			linked_obj* obj = phead;
			for (int i = 0; i != index; i++)
			{
				if (obj->pnext != nullptr) obj = obj->pnext;
				else return 'n';
			}
			return obj->value;
		}
	}
	*/
};


// Jeszcze lista co ma jedno pole jakiejœ wartoœci, a drugie pokazuje na jakiœ obiekt//
// I mo¿na wy³uskiwaæ ten obiekt + on bêdzie jako unique pointer, ¿eby sam siê kasowa³ przy usuwaniu
// operatorem * albo razej -> - bêdzie zwracaæ pointer albo referencjê na obiekt
//template<typename T, typename R>
//class List_Object


////////////////////////////////////////////
//Array on stack//
template<typename T, int N>
class Array_template_trick
{
	T tab[N];

public:

	T* Return_Pointer()
	{
		return tab;
	}
	int Return_Size()
	{
		return N;
	}
};

//Array on heap//                                                                Zrobiæ konstruktor kopiuj¹cy i operator =
//																				 
template<typename T>
class Array_Dynamic : public Array_Functions<T>
{
	int size;
	T* tab;
	T exeption_value = (T)0;

public:
	Array_Dynamic()
	{
		size = 0;
		tab = nullptr;
	}
	Array_Dynamic(int sizee)
	{
		size = sizee;
		tab = new T[size];
	}
	Array_Dynamic(int sizee, T initial_value)
	{
		size = sizee;
		tab = new T[size];
		for (int i = 0; i < size; i++) tab[i] = initial_value;
	}
	Array_Dynamic(T* values_tab, int values_size)
	{
		tab = nullptr;
		size = 0;

		this->Add_from_tab(values_tab, values_size);
	}

	// Konstruktor kopiuj¹cy

	~Array_Dynamic()
	{
		if (tab != nullptr) delete[] tab;
	}

	T* Return_Pointer()
	{
		return tab;
	}
	int Return_Size()
	{
		return size;
	}
	void Add(T new_value)
	{
		T* new_tab = new T[size + 1];

		for (int i = 0; i < size; i++) new_tab[i] = tab[i];
		new_tab[size] = new_value;

		if (tab != nullptr) delete[] tab;
		tab = new_tab;
		size++;
	}
	void Add_from_tab(const T* tab_input, const int size_input)
	{
		if (tab_input == nullptr || size_input <= 0) return;

		if (tab != nullptr) // obiekt ju¿ ma jakieœ wartoœci w tablicy
		{
			int size_new = size + size_input;			
			T* tab_new = new T[size_new];

			int i;
			for (i = 0; i < size && i < size_new; i++) tab_new[i] = tab[i];
			for (int j=0; j < size_input && i < size_new; j++)
			{
				tab_new[i] = tab_input[j];
				i++;
			}

			delete[] tab;
			tab = tab_new;
			size = size_new; 
		}
		else // obiek nie ma niczego
		{
			size = size_input;
			tab = new T[size];

			for (int i = 0; i < size; i++)
			{
				tab[i] = tab_input[i];
			}			
		}
	}
	void Show_All()
	{
		if (tab != NULL) for (int i = 0; i < size; i++) cout << i << ". " << tab[i] << endl;
		else cout << "tab to NULL" << endl;
	}
	void Show_Index(int index)
	{
		if (0 <= index && index < size) cout << index + 1 << ". " << tab[index] << endl;
		else cout << "zle podany index" << endl;
	}
	int Index_of(int value)
	{
		for (int i = 0; i < size; i++) if (tab[i] == value) return i;
		return -1;
	}
	
	void Reverse_slower()
	{
		if (size > 0)
		{
			T* reversed = new T[size];

			int count = size - 1;
			for (int i = 0; i < size; i++)
			{
				reversed[i] = tab[count];
				count--;
			}

			delete[] tab;
			tab = reversed;
		}
		else cout << "tablica jest pusta" << endl;
	}
	void Reverse()
	{
		if (tab != nullptr && size > 0)
		{
			int i = 0;
			int j = size - 1;
			T tmp;
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
	void Delete_Value(T value)
	{
		int index = -1;
		for (int i = 0; i < size; i++) if (tab[i] == value) index = i;

		if (0 <= index && index < size && size > 1)
		{
			int* new_tab = new int[size - 1];
			int j = 0;

			for (int i = 0; i < size; i++)
			{
				if (i != index)
				{
					new_tab[j] = tab[i];
					j++;
				}
			}
			delete[] tab;
			tab = new_tab;
			size--;
		}
		else if (size == 1)
		{
			delete[] tab;
			tab = NULL;
		}
		else cout << "nie na co usuwac" << endl;

	}
	void Delete_Index(int index)
	{
		if (0 <= index && index < size && size > 1)
		{
			T* new_tab = new T[size - 1];

			int j = 0;
			for (int i = 0; i < size - 1; i++, j++)
			{
				if (j != index)
				{
					new_tab[i] = tab[j];
				}
				else i--;
			}

			delete[] tab;
			tab = new_tab;
			size--;
		}
		else if (size == 1)
		{
			if (index == 0)
			{
				delete[] tab;
				tab = nullptr;
				size = 0;
			}
		}
	}
	void Make_Random_Array_No_Repeat(const int& how_many, const int& range)
	{		
		Array_Functions<int> f;
		f.Random_Array_No_Repeat(tab, size, how_many, range);
	}
	void Make_Random_Array_No_Repeat_with_this_values_included(T* tab_included_valeus, int size_of_included_values, int how_many, int range)
	{
		if (size_of_included_values <= 0 || size_of_included_values > how_many) return;
		
		if (tab != nullptr) delete[] tab;


		Array_Functions<int> f;
		f.Random_Array_No_Repeat_with_included_values(tab, size, how_many, range, tab_included_valeus, size_of_included_values);

		for (int i = 0; i < size_of_included_values; i++) tab[i] = tab_included_valeus[i];

		f.Mix_Up(tab, size);
	}
	T Random_value()
	{
		if (tab == nullptr || size < 1) return exeption_value;
		else
		{
			return tab[rand() % size];
		}
	}
	void Sort()
	{
		Array_Functions<T> f;
		f.Sort_Bubble(tab, size);
	}
	void Mix()
	{
		if (tab == nullptr) return;
		Array_Functions<T> f;
		f.Mix_Up(tab, size);
	}

	// []
	T& operator[](int index)
	{
		if (tab != nullptr && size > 0 && 0 <= index && index < size) return tab[index];
		return exeption_value;
	}

	// =
	Array_Dynamic<T>& operator=(const Array_Dynamic<T>& other)
	{

	}

	// Adding tabs together
	Array_Dynamic<T>& operator+=(const Array_Dynamic<T>& other)
	{		
		this->Add_from_tab(other.tab, other.size);

		return *this;
	}

public:
	 template<typename T> friend std::ostream& operator<<(std::ostream& os, const Array_Dynamic<T>& obj);
};

////////////////////////////////////////////                    
//																+ Generate Random Array ale ró¿nych typów nie tylko int
//																	u¿yæ tego templata Random_Values 
//Array functions//
template<typename T>
class Array_Functions
{
	T exeption_value = (T)0;
public:

	void Show_Tab(const T* tab, const int& size)
	{
		cout << endl;
		if (tab == nullptr) cout << "tab to nullptr" << endl;
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << i << ". " << tab[i] << endl;
			}
		}
	}
	void Initialize_Value(T* tab, const int& size, const T& initial_value)
	{
		if (tab == nullptr) cout << "pointer to nullptr" << endl;
		else
		{
			for (int i = 0; i < size; i++)
			{
				tab[i] = initial_value;
			}
		}
	}
	int Find_Index_of(const T& key, const T* tab, const int& size)
	{
		if (tab != nullptr && size > 0)
		{
			for (int i = 0; i < size; i++)
			{
				if (key == tab[i]) return i;
			}
			return -1;

		}
		else return -1;
	}	
	
	int Index_help_function(const T& key, const T*& tab, const int& boarder_left, const int& boarder_right)
	{
		int middle_point = (boarder_left + boarder_right) / 2;

		if (key == tab[middle_point]) return middle_point;
		else if (key < tab[middle_point]) return Index_help_function(key, tab, boarder_left, middle_point);
		else return Index_help_function(key, tab, middle_point, boarder_right);
	}	
	int Find_Index_of_sorted_array(const T& key, const T* tab, const int& size)
	{
		if (tab == nullptr || size <= 0 || !Already_in_array(tab, size, key)) return -1;

		return Index_help_function(key, tab, 0, size - 1);
	}

	bool Already_in_array(const T* tab, const int& size, const T& key)
	{
		if (tab == nullptr) return false;

		for (int i = 0; i < size; i++) if (tab[i] == key) return true;
		return false;
	}
	//
	//
	//
	// dzia³aj¹ na int, mo¿e zrobiæ, ¿e u¿ywa templatu do generowania losowych liczb okreœlonego rodzaju
	void Random_Array_No_Repeat(int*& tab, int& size, const int& how_many, const int& range_for_value_in_tab)
	{
		if (tab != nullptr) delete[] tab;

		int random = 0;
		size = how_many;
		tab = new int[size];
		for (int i = 0; i < size; i++) tab[i] = -1;

		for (int i = 0; i < size; i++)
		{
			random = rand() % range_for_value_in_tab + 1;
			while (Already_in_array(tab, size, random)) random = rand() % range_for_value_in_tab + 1;

			tab[i] = random;
		}
	}
	void Random_Array_No_Repeat_with_included_values(int*& tab, int& size, int& how_many, int& range_for_value_in_tab, T* tab_input, int& size_input)
	{
		if (tab != nullptr) delete[] tab;

		int random = 0;
		size = how_many;
		tab = new int[size];
		for (int i = 0; i < size; i++) tab[i] = -1;

		for (int i = 0; i < size; i++)
		{
			random = rand() % range_for_value_in_tab + 1;
			while (Already_in_array(tab, size, random) || Already_in_array(tab_input, size_input, random)) random = rand() % range_for_value_in_tab + 1;

			tab[i] = random;
		}
	}
	void Reverse_Functions(const T* tab, const int& size)
	{
		if (tab != nullptr && size > 0)
		{
			int i = 0;
			int j = size - 1;
			T tmp;
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

	bool Is_tab_sorted(const T* tab, const int& size)
	{
		if (tab == nullptr || size < 1) return false;
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (tab[i] > tab[i + 1]) return false;
			}
			return true;
		}
	}
	void Swap_values(T* tab, const int& size, const int& first_index, const int& second_index)
	{
		if (tab != nullptr && size > 0 && (0 <= first_index && first_index < size) && (0 <= second_index && second_index < size))
		{
			if (first_index == second_index) cout << "same index" << endl;
			else
			{
				T tmp_value = tab[first_index];

				tab[first_index] = tab[second_index];
				tab[second_index] = tmp_value;
			}
		}
	}
	bool Is_Every_Value_in_Tab_same_as_Key(const T* tab, const int& size, const T& key)
	{
		if (tab == nullptr || size <= 0) return false;

		for (int i = 0; i < size; i++)
		{
			if (tab[i] != key) return false;
		}
		return true;
	}

	void Sort_Bubble(T* tab, const int& size)
	{
		if (tab != nullptr && size > 0 && !Is_tab_sorted(tab, size))
		{
			int how_far_in_tab = size;

			for (int i = 0; !Is_tab_sorted(tab, how_far_in_tab); i++)
			{
				for (int j = 0; j < how_far_in_tab - 1; j++) if (tab[j] > tab[j + 1]) Swap_values(tab, size, j, j + 1);
				how_far_in_tab--;
			}
		}
	}
	// trzeba coœ poprawiæ
	void Mix_Up(T*& tab, const int& size)
	{
		if (tab != nullptr)
		{
			List<int> available_indexs;
			for (int i = 0; i < size; i++) available_indexs.Add_Back(i);

			int random_index = 0;
			Unique_ptr<T> new_tab = new T[size];
			//T* new_tab = new T[size];

			for (int i = 0; i < size; i++)
			{
				random_index = available_indexs.Pick_Random_Value_delete_after();
				new_tab[random_index] = tab[i];
			}

			// koniec, wszystkie wartoœci z tablicy input, zosta³y przepisane na losowe miejsca w nowej tablicy
			for (int i = 0; i < size; i++) tab[i] = new_tab[i];
			//delete[] new_tab;
		}
	}
	void Sort_Bong(T*& tab, const int& size)
	{		
		Time_Scope t("Bong sort", 1, 1);

		if (tab != nullptr && size > 0)
		{
			// wczesniejsza wersja Lista przechowuje jeszcze nie wykorzystane indexy i jak tylko jakiœ bêdzie wykorzystany to go usuwa
			// mo¿a to zrobiæ na kolejce, z listy losujemy jakiœ dowolny element (mo¿e z listy multivalue gdzie pierwsze pole bêdzie na mówi³o czy nie zosta³ ju¿ wykorzystany)
			// z listy losujemy kolejne liczby i dodajemy je do kolejki a potem tylko z niej wyci¹gamy i ju¿ mamy now¹ losow¹ kolejnoœæ

			// albo po prostu zrobiæ, ¿e funkcja dzia³a okreœlon¹ iloœæ razy i losuje z wszystkich dostêpnych indexy i je zamienia
			// prêdzej czy póŸniej pozmienia miejsce wszystkich liczb
			/*
			List<int> available_indexes;
			int* index_tab = new int[size];
			for (int i = 0; i < size; i++) index_tab[i] = i;
			available_indexes.Add_Back_from_tab(index_tab, size);
			List<int> copy;

			Array_Dynamic<T> obj_tab(size);
			T* new_tab = obj_tab.Return_Pointer();

			Array_Functions<int> i;
			int a = 1;
			int random = 0;
			int how_many_elements = 0;
			do
			{
				copy = available_indexes;
				how_many_elements = size;

				for (int i = 0; i < size; i++)
				{
					if (how_many_elements == 1)
					{
						new_tab[i] = copy.Value_of_Index(0);
						break;
					}

					random = rand() % how_many_elements;
					new_tab[i] = copy.Value_of_Index(random);
					copy.Delete_Index(random);
					how_many_elements--;
				}
				cout << a << " attempt" << endl; a++;
				i.Show_Tab(new_tab, size);

			} while (!i.Is_tab_sorted(new_tab, size));

			// jak juz jest posortowana
			for (int i = 0; i < size; i++) tab[i] = new_tab[i];
			*/
			

			while (!Is_tab_sorted(tab, size))
			{				
				Mix_Up(tab, size);
			}		
		}		
	}

	T Biggest_value_in_tab(const T* tab, const int& size)
	{
		if (tab != nullptr)
		{
			T biggest;

			for (int i = 0; i < size; i++)
			{
				if (i == 0) biggest = tab[i];
				else
				{
					if (biggest < tab[i]) biggest = tab[i];
				}
			}

			return biggest;
		}
		else return exeption_value;
	}
	T Biggest_value_from_both(const T* tab_a, const T* tab_b, const int& size_a, const int& size_b)
	{
		if (tab_a != nullptr && tab_b != nullptr && size_a > 0 && size_b > 0)
		{
			T a = Biggest_value_in_tab(tab_a, size_a);
			T b = Biggest_value_in_tab(tab_b, size_b);

			if (a > b) return a;
			else return b;
		}
		else return exeption_value;
	}
	double Average_of_array(const T* tab, const int& size)
	{
		if (tab != nullptr && size > 0)
		{
			double sum = (double)tab[0];

			for (int i = 1; i < size; i++)
			{
				sum += (double)tab[i];
			}
			return (double)(sum / size);
		}
		else return 0;
	}

	T* Array_Intersect(T* tab_1, int size_1, T* tab_2, int size_2, int& return_size)
	{
		if (tab_1 && tab_2 != nullptr && size_1 && size_2 > 0)
		{
			int mini = 0;
			int other = 0;
			T* mini_tab = nullptr;
			T* other_tab = nullptr;

			if (size_1 < size_2)
			{
				mini = size_1;
				other = size_2;
				mini_tab = tab_1;
				other_tab = tab_2;
			}
			else
			{
				mini = size_2;
				other = size_1;
				mini_tab = tab_2;
				other_tab = tab_1;
			}

			Queue<T> result;
			for (int i = 0; i < mini; i++)
			{
				if (Already_in_array(other_tab, other, mini_tab[i]))
					result.Enque_unique(mini_tab[i]);
			}

			return result.Return_Tab(return_size);
		}
		else return nullptr;
	}
};
/*
template<>
char Array_Functions<char>::Biggest_value_in_tab(const char* tab, const int& size)
{
	if (tab != nullptr)
	{
		char biggest = ' ';

		for (int i = 0; i < size; i++)
		{
			if (i == 0) biggest = tab[i];
			else
			{
				if (biggest < tab[i]) biggest = tab[i];
			}
		}

		return biggest;
	}
	else return ' ';
}
template<>
string Array_Functions<string>::Biggest_value_in_tab(const string* tab, const int& size)
{
	if (tab != nullptr)
	{
		string biggest;

		for (int i = 0; i < size; i++)
		{
			if (i == 0) biggest = tab[i];
			else
			{
				if (biggest < tab[i]) biggest = tab[i];
			}
		}

		return biggest;
	}
	else return "";
}
template<>
string Array_Functions<string>::Biggest_value_from_both(const string* tab_a, const string* tab_b, const int& size_a, const int& size_b)
{
	if (tab_a != nullptr && tab_b != nullptr && size_a > 0 && size_b > 0)
	{
		string a = Biggest_value_in_tab(tab_a, size_a);
		string b = Biggest_value_in_tab(tab_b, size_b);

		if (a > b) return a;
		else return b;
	}
	else return "";
}
*/

// Simple Array Simplifications //
template<typename T>
class Array_Optimization
{
public:
	
	// dowolny odstêp miêdzy liczbami (spacja, enter)
	T* From_txt_to_array(string path, int& size)
	{
		string right_path = "_load_array_from_txt/" + path;
		ifstream FILE(right_path.c_str());

		T recever;
		List<T> list;

		while (!FILE.eof())
		{
			FILE >> recever;
			list.Add_Back(recever);
		}

		size = list.Get_list_size();

		return list.to_array();
	}

};

///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////



////////////////////////////////////////////                zrobiæ ¿eby pointer na tablicê tablic by³ Unique / Shared pointerem i wtedy niepotrzebny jest destruktor
//Matrix//  
template <typename T>
class Matrix
{
private:
	T** tab;
	int rows;
	int columns;	
	T null_return;

public:
	T** Get_Tab()
	{
		return tab;
	}
	int Get_Rows()
	{
		return rows;
	}
	int Get_Columns()
	{
		return columns;
	}


	Matrix()
		:tab(nullptr), rows(0), columns(0), null_return((T)0)
	{
	}
	void Make_rows_columns(int r, int c)
	{
		rows = r;
		columns = c;

		tab = new T * [rows];

		for (int i = 0; i < (int)rows; i++)
		{
			tab[i] = new T[columns];
		}

	}
	void Load_from_file(const char* name)
	{
		this->Make_rows_columns(9, 9);

		ifstream ODCZYT(name);
		char tmp;		
		
		for (int i = 0; i < rows; i++)
		{			
			for (int j = 0; j < columns; j++)
			{
				if (!ODCZYT.eof())
				{
					ODCZYT >> tmp;
					if (tmp == ' ') j--;
					else if (tmp == '\n') i--;

					tab[i][j] = (int)tmp - 48;
				}
				else break;
			}
		}
		
		ODCZYT.close();
	}
	Matrix(int r, int c)
		:rows(r), columns(c), null_return((T)0)
	{
		tab = new T * [rows];

		for (int i = 0; i < (int)rows; i++)
		{
			tab[i] = new T[columns];
		}
	}
	~Matrix()
	{
		if (tab != nullptr)
		{
			for (int i = 0; i < rows; i++) delete[] tab[i];
			delete[] tab;
		}
	}
	bool Is_Empty()
	{
		if (tab == nullptr || rows == 0 || columns == 0) return true;
		else return false;
	}
	void Show()
	{
		if (tab == nullptr) return;

		cout << endl << "    ";
		for (int i = 0; i < columns; i++)
		{
			cout << i << " ";
			if (i < 10) cout << " ";
		}


		cout << endl << "    ";
		for (int i = 0; i < columns * 3 - 1; i++) cout << "_";
		cout << endl;

		for (int i = 0; i < rows; i++)
		{
			if (i <= 9) cout << i << "  |";
			else cout << i << " |";

			for (int j = 0; j < columns; j++)
			{
				cout << tab[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void Show_nothing_if_zero()
	{
		if (tab == nullptr) return;

		cout << endl << "    ";
		for (int i = 0; i < columns; i++)
		{
			cout << i << " ";
			if (i < 10) cout << " ";
		}


		cout << endl << "    ";
		for (int i = 0; i < columns * 3 - 1; i++) cout << "_";
		cout << endl;

		for (int i = 0; i < rows; i++)
		{
			if (i <= 9) cout << i << "  |";
			else cout << i << " |";

			for (int j = 0; j < columns; j++)
			{
				if(tab[i][j] != 0) cout << tab[i][j] << "  ";
				else cout << "   ";
			}
			cout << endl;
		}
		cout << endl;
	}


	
	void Initiate_value(T value)
	{
		if (tab != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					tab[i][j] = value;
				}
			}
		}
	}
	void Initiate_random(const int& range)
	{
		if (tab != nullptr)
		{
			Random_Value<T> r;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					tab[i][j] = r.return_random_value_mine(range);
				}
			}
		}
	}
	void Put_This_value_in_random_places(T value, int change_how_many_values)
	{
		if (tab == nullptr || rows < 0 || columns < 0) return;

		Matrix<bool> tmp(rows, columns);
		tmp.Initiate_value(true);

		int i_random = 0;
		int j_random = 0;

		// ustawania miejsc w które wpiszemy liczbê
		for (int count = 0; count < change_how_many_values; count++)
		{
			i_random = rand() % rows;
			j_random = rand() % columns;

			while (!tmp(i_random, j_random))
			{
				i_random = rand() % rows;
				j_random = rand() % columns;
			}

			tmp(i_random, j_random) = false;
		}

		// wpisywanie na wybrane miejsca wartoœci
		for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) if(tmp(i, j) == false) this->operator()(i, j) = value;
	}
	int How_many_places_with_this_Value(T value)
	{
		if (tab == nullptr || rows < 0 || columns < 0) return 0;

		int counter = 0;
		for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++)
		{
			if (this->operator()(i, j) == value) counter++;
		}
		return counter;
	}

	void Fill_all_values_from_raw_matrix(T** t, int r, int c)
	{
		if ((t && tab != nullptr) && (rows == r && columns == c))
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++) this->operator()(i, j) = t[i][j];
			}
			this->Transposition();
		}
		else cout << "bad size of matrix or nullptr" << endl;
	}
	void Fill_all_values_based_on_array(T* values_tab, int values_size)
	{
		if (columns != values_size || tab == nullptr) return;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < values_size; j++) tab[i][j] = values_tab[j];
		}
	}
	void Fill_all_values_based_on_array_mixed_up(T* values_tab, int values_size)
	{
		if (columns != values_size || tab == nullptr) return;

		Array_Dynamic<int> tmp(values_tab, values_size);

		for (int i = 0; i < rows; i++)
		{
			tmp.Mix();
			for (int j = 0; j < values_size; j++) tab[i][j] = tmp[j];
		}
	}
	void Fill_up_visualized(int change_rate)
	{
		system("cls");
		this->Show();
		Sleep(change_rate);
	}

	// Sudoku fun
	bool Already_In_Row(int r, T key)
	{
		if (tab == nullptr || rows < 1 || columns < 1) return false;

		for (int j = 0; j < columns; j++)
		{
			if (tab[r][j] == key) return true;
		}
		return false;
	}
	bool Already_In_Columns(int c, T key)
	{
		if (tab == nullptr || rows < 1 || columns < 1) return false;

		for (int i = 0; i < rows; i++)
		{
			if (tab[i][c] == key) return true;
		}
		return false;
	}
	bool Already_In_Cross(int r, int c, T key)
	{
		if (tab == nullptr || rows < 1 || columns < 1) return false;

		if (Already_In_Row(r, key) || Already_In_Columns(c, key)) return true;
		else return false;
	}	

	// operacje
	void Transposition()
	{
		if (tab != nullptr)
		{
			if (rows == columns) // macierz kwadratowa
			{
				T tmp;

				int starting_i = 0;
				int starting_j = 1;

				while (starting_j != columns && starting_i != rows)
				{
					for (int j = starting_j; j < columns; j++)
					{
						tmp = tab[j][starting_i];
						tab[j][starting_i] = tab[starting_i][j];
						tab[starting_i][j] = tmp;
					}

					starting_i++;
					starting_j++;
				}
			}
			else // macierz prostok¹tna
			{
				// trzeba zrobiæ macierz z iloœci¹ kolumn tak¹ jak iloœæ rzêdów i iloœæ rzêdów tak¹ jak iloœæ kolumn

				Matrix<T> replacement(this->columns, this->rows);

				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < columns; j++) replacement(j, i) = tab[i][j];
				}				
				
				(*this) = replacement;
			}
		}
	}
	T Sum_of_all_elements_in_matrix()
	{
		if (tab != nullptr)
		{
			T sum;
			for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++) {
				if (i == 0 && j == 0) sum = tab[i][j];
				else sum += tab[i][j];
			}
			return sum;
		}

		return (T)0;
	}
	// wyznacznik
	void Determinant()
	{
		if (rows != columns) return;
		
		Matrix<T> tmp = *this;

		// do tmp trzeba dorobiæ te zdublowane kolumny ¿eby siê przyjemnije mno¿y³o



	}
	void Dubble_for_determinant()
	{
		Matrix<T> tmp(rows, columns + (columns -1));


		
	}

	// operatory
	T& operator()(int i, int j)
	{
		if (i < (int)rows && j < (int)columns && (i >= 0 && j >= 0))	return tab[i][j];
		return null_return;
	}	
	Matrix& operator=(Matrix& other)
	{
		if (other.tab != nullptr)
		{
			if (tab != nullptr)
			{
				for (int i = 0; i < rows; i++) delete[] tab[i];
				delete[] tab;
			}

			rows = other.rows;
			columns = other.columns;			

			tab = new T * [rows];

			for (int i = 0; i < rows; i++)
			{
				tab[i] = new T[columns];
			}

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					tab[i][j] = other(i, j);
				}
			}		
			return *this;
		}
		return *this;		
	}
};




////////////////////////////////////////////
//Interesting Recursion//
class Interesting_Recursion
{
private:
	int count_ones(int*& tab, int& size);
	int max_of_tab(int*& tab, int& size);

	void BODY_Permutations(int*& tab, int& size, int*& available_tab, int& limit, ofstream& FILE);
	void BODY_Permutations_no_repeat(int*& tab, int& size, int*& available_tab, int& recursion_limit, int starting_index, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE), void(*at_the_end)(int sum, ofstream& FILE), ofstream& FILE);
	void BODY_Permutations_no_repeat_sum(int*& tab, int& size, int*& available_tab, int sum_looking_for, int starting_index, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE), ofstream& FILE);

public:
	void HUB_Permutations(int*& tab, int& size, int& window_size);
	void HUB_Permutations_no_repeat(int*& tab, int& size, int how_many_in_a_group, ofstream& FILE, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE), void(*at_the_end)(int sum, ofstream& FILE));
	void HUB_Permutations_no_repeat_sum(int*& tab, int& size, int sum_looking_for, ofstream& FILE, void(*normal)(int*& tab, int& index, ofstream& FILE), void(*last)(int*& tab, int& index, ofstream& FILE));

	void basic_call_no_repeat_sum(int* tab, int size, int sum_looking_for);
	void basic_call_no_repeat_showing_sum(int* tab, int size);
	void basic_call_no_repeat(int* tab, int size, int how_many_number_in_group);
	void basic_call_repeat(int* tab, int size, int how_many_number_in_group);
};


////////////////////////////////////////////
//Interesting Operations//
class Interesting_Operations
{
public:
	double Fractions_from_0_to_1();
	double Fractions_from_0_to_user_number(double user_number);
};


////////////////////////////////////////////
//Optimized bool tab//		
template<int N>
class Bool_tab
{	
	unsigned short int bits[(N/16) + 1];	

public:
	Bool_tab()		
	{		
		for (int i = 0; i < (N / 16) + 1; i++) bits[i] = 0;

		cout << "obiekt stworzony" << endl;		
	}
	void Set_all_true()
	{
		for (int i = 0; i < N; i++)
		{
			this->operator()(i, true);
		}
	}
	void Set_all_false()
	{
		for (int i = 0; i < N; i++)
		{
			this->operator()(i, false);
		}
	}

	void operator()(int index, bool value)
	{
		if (!(0 <= index && index < N)) return;
		
		int i = index / 16;
		int j = index % 16;

		// teraz sprawdza czy ju¿ jest ta wartoœæ co chcemy na w³aœciwym miejscu
		// dodawanie lub odejmowanie przesuniêtej liczby do bits[i]

		if (value == this->operator[](index)) return;

		unsigned short int t = 1;		
		t <<= 15;		
		t >>= j;

		if (value == true) bits[i] += t;
		else              bits[i] -= t;
	}
	// operator []
	bool operator[](int index)
	{
		if (!(0 <= index && index < N))
		{
			cout << "index: " << index << " out of range" << endl;
			return false;
		}

		int i = index / 16;
		int j = index % 16;
		
		unsigned short int t = 1;
		// teraz mamy t na najbardziej prawej pozycji
		t <<= 15;
		// przesuwamy na odpowiednie miejsce
		t >>= j;
		
		if ((t & bits[i]) > 0) return true;
		else return false;
	}
	void Show()
	{	
		for (int i = 0; i < N; i++)
		{
			if (i % 8 == 0) cout << endl;

			if (this->operator[](i) == true) cout << "1";
			else cout << "0";			
		}
	}
};

template<int N, int M>
class Bool_tab_2D
{
	Bool_tab<N> bool_tab[M];

public:
	Bool_tab_2D()
	{
		cout << "1 obiekt 2D zrobiony" << endl;
		for (int i = 0; i < M; i++) bool_tab[i].Set_all_false();
	}	
	void Show()
	{		
		for (int i = 0; i < M; i++)
		{
			cout << i + 1 << ". obiekt ";
			for (int j = 0; j < N; j++)
			{
				cout << this->operator()(i, j);
			}
			
			cout << endl;
		}
	}

	void operator()(int i, int j, bool value)
	{
		if (!(0 <= i && i < M && 0 <= j && i < N)) return;
		bool_tab[i](j, value);
	}
	bool operator()(int i, int j)
	{
		if (!(0 <= i && i < M && 0 <= j && i < N)) return false;
		return bool_tab[i][j];
	}
};


////////////////////////////////////////////
//Daily Coding Problems//
class Coding_Problems
{
public:
	 
	// biggest non-adjacent sum
	class Problem_9
	{
	public:

		void biggest_non_adjacent_sum(int* tab, int size)
		{
			int biggest = 0;
			int tmp = 0;

			for (int big_iteration = 0; big_iteration < size; big_iteration++)
			{
				for (int j = big_iteration + 2; j < size; j++)
				{
					tmp = tab[big_iteration];
					tmp += tab[j];

					if (big_iteration == 0 || biggest < tmp) biggest = tmp;
				}
			}

			for (int i = 0; i < size; i++) cout << tab[i] << " ";
			cout << endl << "najwieksza suma dla tablicy to: " << tmp << endl;
		}
	};

	// very simple job scheduler
	class Problem_10
	{
	public:

		void Job_Scheduler(void (*ptr)(), int n)
		{
			Sleep(n);
			ptr();
		}
	};

	// Monte Carlo - pi approximation
	class Problem_14
	{
	public:

		struct Point_int
		{
			int x;
			int y;
		};
		struct Point_double
		{
			double x;
			double y;
		};

		double Length(Point_double p)
		{
			return sqrt((p.x * p.x) + (p.y * p.y));
		}
		double Length(Point_int p)
		{
			return sqrt((((double)p.x * (double)p.x) + ((double)p.y * (double)p.y)));
		}

		Point_double Random_Point_in_square(double r)
		{			
			Point_double result;
			result.x = (rand() % 2 * r) - r;
			result.y = (rand() % 2 * r) - r;

			return result;
		}

		Point_int Random_point_in_bounds(int width, int height)
		{
			Point_int result;

			result.x = rand() % (width + 1);
			result.y = rand() % (height + 1);

			return result;
		}

		void Main_thing(int number_of_iterations, int r)
		{
			double square = 0;
			double circle = 0;
			double pi = 0;

			for (int i = 0; i < number_of_iterations; i++)
			{
				Point_int random;
				{
					random.x = (rand() % (2 * r + 1)) - r;
					random.y = (rand() % (2 * r + 1)) - r;
				}

				square++;
				if (sqrt((random.x * random.x) + (random.y * random.y)) <= (double)r) circle++;
				pi = ((double)(4 * circle) / (double)(square));

				#ifdef DEBUG
					cout << "iterations " << i + 1 << " " << pi << endl;
					// Sleep(50);
					//cin.get();
				#endif
			}			
		}

		void Pi_approximation(int iterations, int r)
		{
			double square = 0;
			double circle = 0;
			double pi = 0;

			// void(*ptr)(int,double) = &Coding_Problems::Problem_14::Main_thing(1,2);
			// void (*ptr)(int,double) = Main_thing;
			// ptr(1, 2);

			// void (Coding_Problems::Problem_14::*ptr)(int,int) = &Coding_Problems::Problem_14::Main_thing;

			// pierwszy pomys³
			/*
			auto f = [&square, &circle, &pi](int number_of_iterations, int r)
			{
				for (int i = 0; i < number_of_iterations; i++)
				{					
					Point_int random;
					{
						random.x = (rand() % (2 * r + 1)) - r;
						random.y = (rand() % (2 * r + 1)) - r;
					}

					square++;
					if (sqrt((random.x * random.x) + (random.y * random.y)) <= (double)r) circle++;
					pi = ((double)(4 * circle) / (double)(square));

					#ifdef DEBUG
						cout << "iterations " << i + 1 << " " << pi << endl;
						// Sleep(50);
						cin.get();
					#endif
				}
			};
			*/
			
			// drugi pomys³
			/*
			int fractions = 800;
			fractions = 300;
			
			auto f = [&square, &circle, &pi, fractions](int number_of_iterations, double r)
			{
				double distance = 0;
				for (int i = 0; i < number_of_iterations; i++)
				{
					Point_double random; // < 0, 1 >
					{
						random.x = ((double)(rand() % fractions) / (double)fractions); LOG("x: " << random.x);
						random.y = ((double)(rand() % fractions) / (double)fractions); LOG("y: " << random.y);
					}

					square++;
					distance = sqrt((random.x * random.x) + (random.y * random.y));
					if (distance <= r) circle++;
										
					pi = (circle / square) * 4;

					#ifdef DEBUG
						cout << "iterations " << i + 1 << " " << pi << endl;
						Sleep(50);
						//cin.get();
					#endif
				}
			};	

			thread t(f, iterations, 1);
			t.join();
			*/

			// strzelanie pixelami jak na obrazku
			{
				int general = 356;				
				int width = general, height = general;

				int local_r = general;
				double length;
				for (int i = 0; i < iterations; i++)
				{
					Point_int point = Random_point_in_bounds(width, height);
					length = Length(point);

					square++;
					if (length <= (double)general) circle++;

					pi = (circle / square) * 4;

					#ifdef DEBUG
						cout << "iterations " << i + 1 << " " << pi << endl;
						Sleep(50);
						//cin.get();
					#endif
				}
			}


			cout << "Funkcja skonczona" << endl;	
			cout << "ile w kwadrat: " << square << endl;
			cout << "ile w kolko: " << circle << endl;

			cout << endl << "Pi: " << pi << endl;
		}
	};

};































////////////////////////////////////////////
//Sudoku//											Sudoku w innych rozmiarach
class Sudoku
{
	Matrix<int> plane;	
	Array_Dynamic<int> number_tab;
	Matrix<int> pattern;	

public:
	Sudoku();
	Sudoku(Matrix<int>& custom_pattern);
	void Make_Random_Plane();
	void Show();

	bool Check_If_Correct_Columns();
	bool Check_If_Correct_Rows();
	bool Check_If_Correct_Rows_and_Columns();
	bool Check_If_Correct_Groups();
	bool Check_If_Sudoku();

	void Make_Correct_Vertical_and_Horizontal();
	void Make_Sudoku();
	void Make_Sudoku_Many_Lists();

	void Save_Matrix_to_File(const char* name);
	void Save_Sudoku_Set_Hardness(const char* name, int index, int hardness_level);


	void Make_Random_Correct_Vertical_and_Horizontal();
};


////////////////////////////////////////////
//Search Patterns//
class Search_Patterns
{

public:

	//for (size_t i = 0; i < pattern.length(); i++)
	// cos gosc mowil ze to niby lepiej przechodzi, nie wiem do konca

	string wygeneruj_losowe_ciagi_znakow(const string& jakich_liter_moge_uzywac, const int& jak_wiele_znakow_wylosowac);
	string Odczytane_z_Pliku();

	//Brute Force
	bool Does_full_pattern_match(const string& full_tekst, const string& pattern, const int& index_of_first_match);
	void Show_Index_In_Tekst(const string& pattern, const int* tab, const int& size, const int& how_many_letters_before, const int& how_many_letters_after);
	int* Brute_Force_Approach_returns_table_of_index(const string& full_tekst, const string& pattern, int& size);


	//Pierwszy algorytm
	//Morisa Pratta
	string Zwraca_najwiekszy_wystepujacy_w_obydwu_element(const string* tab_a, const string* tab_b, const int& size_a, const int& size_b);
	string Najwiekszy_wspolny_prefix_sufix(const string& pattern);
	int* Generator_Tablicy_Morrisa_Pratta(const string& pattern, int& size);
	int Return_Index_Of_Missmatch(const string& full_tekst, const string& pattern, const int& limit, const int& pattern_size, const int& index_in_tekst);
	int* Knuth_Morris_Pratt(const string& full_tekst, const string& pattern, int& size_of_returned_tab);


	//Drugi algorytm
	//Boyer Moore			   	
	void Construct_Bad_Match_Two_Tabs(const string& pattern, char*& tab_char, int*& tab_int, int& size);
	int Return_Index_of_Char_Tab_if_not_found_return_last_index(const char& key, const char* tab, const int& size);
	int O_ile_przeskoczyc(const string& full_tekst, const string& pattern, const int& size_pattern, int index, char*& tab_char, int*& tab_int, const int& size);
	int* Boyer_Moore(const string& full_tekst, const string& pattern, int& size_of_returned_tab);


	//Trzeci algorytm
	//Rabin Karp
	int* Rabin_Karp(const string& text, const string& pattern, const int& q, int& size_of_returned_tab);	
};


////////////////////////////////////////////               
//Word Cross// 
class Word_Cross
{
public:

	char** Generete_Random_Grid_Symetric_Matrix(const int& size);
	string* Get_All_Left_to_Right(char**& tab, const int& size);
	string* Get_All_Top_to_Bottom(char**& tab, const int& size);
	string* Get_All_Diagonal_Left_to_Right(char**& tab, const int& size);

	//List_Multivalue<string, int>* Search_For_Pattern_In_Matrix(const string& pattern, const int& matrix_size, char**& tab);	
	//List_Multivalue<string, int>* All_cases_present(const string& pattern, const int& matrix_size, char**& tab);

	List_Multivalue<string, int>* Search_For_Pattern_In_Matrix_My_Matrix(const string& pattern, Matrix<char>& tmp);
	List_Multivalue<string, int>* All_cases_present_My_Matrix(const string& pattern, Matrix<char>& obj, const unsigned int& size);
};


////////////////////////////////////////////                     tak powinno byæ chyba wszêdzie unsigned, albo dorobiæ ¿e uwzglêdnia znak.
//																 Dla ujemnych trzeba zamieniæ na dodatni bo wychodz¹ z³e liczby z tablicy ascii
//																 
//																 FUNKCJA co liczy i wyœwietla adres sieci, adres broadcast i wszystkie inne 
//   															 mo¿e da siê zrobiæ tak ¿e bêdzie ustawiony limit ile znaków na raz weŸmie. 
//																 Bierze adres ipv4 i robi ca³¹ resztê, tylko ¿eby to siê wprowadza³o oktetami a nie jedna du¿a liczba.
//Number Bases//
class Number_Bases
{
public:
	String Binary(int input_number);	
	String Octagonal(int input_number);	
	String Decimal(int input_number);
	String Decimal(long long input_number);
	String Hexadecimal(int input_number);

	String Binary_Bit(unsigned int input_number);	
	String Octagonal_Bit(int input_number);
	String Hexadecimal_Bit(int input_number);

	
	int Parse_to_Int_from_Binary(String& input_binary);
	unsigned int Parse_to_Un_Int_from_Binary(String& input_binary);
	int Parse_to_Int_from_Decimal(String& input);

	int Parse_to_Int_from_Hexadecimal(String& input);
};


////////////////////////////////////////////
//Stats//
class Stats
{
public:

	void Testing_Fuction(Time& clock, double& time, const int& how_many_elements);
	void Create_file(const string& name, const int& how_many_repetitions_on_each, const int& start, const int& end, const int& rate_of_increment);
};


////////////////////////////////////////////
//Smart pointers//                                         Doda³em to dla pointera na tablicê
template<typename T>
class Unique_ptr
{
private:
	T* pointer;
	T** double_pointer;
	//T exeption_value = (T)0;

public:
	Unique_ptr(T* ptr)
		:pointer(ptr), double_pointer(nullptr)
	{
	}
	Unique_ptr(T** ptr)
		:pointer(nullptr), double_pointer(ptr)
	{
	}

	~Unique_ptr()
	{
		//cout << "usuwam Unique_ptr" << endl;
		if (pointer != nullptr) delete pointer;
		if (double_pointer != nullptr) delete[] pointer;
	}

	T* operator->()
	{
		return pointer;
	}

	T& operator[](int index)
	{
		if (index > 0 && pointer != nullptr) return pointer[index];
	}

	T& operator()(int index_a, int index_b)
	{
		if (index_a > 0 && index_b > 0 && double_pointer != nullptr) return double_pointer[index_a][index_b];
	}

	/*
	T* operator*()
	{
		return *pointer;
	}
	*/
	Unique_ptr(const Unique_ptr& other) = delete;
};

template<typename T>
class Shared_ptr
{
private:
	T* pointer;
	unsigned int* counter;

public:
	Shared_ptr(T* ptr)
		:pointer(ptr)
	{
		counter = new unsigned int;
		(*counter) = 1;
	}
	~Shared_ptr()
	{
		(*counter)--;
		if ((*counter) == 0)
		{
			//cout << "usuwam Shared_ptr" << endl;
			delete pointer;
			delete counter;
		}
	}
	Shared_ptr(const Shared_ptr& other)
	{
		pointer = other.pointer;
		counter = other.counter;
		(*counter)++;
	}

	T* operator->()
	{
		return pointer;
	}
};

// WEAK pointer
/*
template<typename T>                             // sprawdziæ czy na pewno dobrze dzia³a
class Weak_ptr
{
private:
	T* pointer;

public:

	bool Is_Still_Alive()
	{
		if (pointer == nullptr) return false;
		return true;
	}

	Weak_ptr(const Shared_ptr& other)
	{
		pointer = other.pointer;
	}

	T* operator->()
	{
		return pointer;
	}

};
*/