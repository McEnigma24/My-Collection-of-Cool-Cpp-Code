#include "header.h"

std::ostream& operator<<(std::ostream& stream, const String& obj)
{
	if (obj.tab != nullptr)
	{
		for (int i = 0; i < obj.size; i++) stream << obj.tab[i];
	}
	
	return stream;
}
template<typename T>
std::ostream& operator<<(std::ostream& stream, const Array_Dynamic<T>& obj)
{
	if (obj.tab != nullptr)
	{
		for (int i = 0; i < obj.size; i++) stream << i << ". " << obj.tab[i] << endl;
		stream << endl;
	}
	
	return stream;
}

using namespace std;

# define PI          3.141592653589793238462643383279502884
#define multiply( f1, f2 ) ( f1 * f2 )

#define getrandom(min, max) \
    ((rand()%(int)(((max) + 1)-(min)))+ (min))

#define MAIN int main() \
{\
	cout<<"dziala"<<endl;\
	return 0;\
}

typedef list<string> string_l;

template<class T, size_t I>
void printArray(array<T, I> a)
{
	for (auto& i : a)
	{
		i.Print();
		cout << '\n';
	}
}

class VectorOperations
{
public:
	void print(vector<int>& a)
	{
		for (auto& aa : a) cout << aa << ' ';
		cout << endl << endl;
	}
	void print(vector<vector<int>>& a)
	{
		for (auto& biga : a)
		{
			for (auto& smalla : biga)
			{
				cout << smalla << ' ';
			}
			cout << endl;
		}

		cout << endl << endl;
	}
	void print(vector<vector<vector<int>>>& a)
	{
		int level = 0;
		for (auto& biga : a)
		{
			cout << "level " << level << endl; level++;
			for (auto& mida : biga)
			{
				for (auto& smalla : mida)
				{
					cout << smalla << ' ';
				}
				cout << endl;
			}

			cout << endl;
		}

		cout << endl << endl;
	}

};

// testing unique pointer as member
class UniqueTest
{
	unique_ptr<int[]> m_a;
	int& m_b;
	int m_c;

public:
	UniqueTest(int& bb, int cc)
		:m_b(bb), m_c(cc)
	{
		m_a = make_unique<int[]>(10);
		for (int i = 0; i < 10; i++) m_a[i] = i + 1;
	}

	void Print()
	{
		cout << "unique ptr" << endl;
		for (int i = 0; i < 10; i++) cout << m_a[i] << endl;

		cout << "referenced b: " << m_b << "	zmieniæ wartosc zmiennej i zobaczyc jeszcze raz na wartosci" << endl;
		cout << "           c: " << m_c << endl;
	}
};

//MAIN
int main()
{
	string_l lista;
	lista.emplace_back("typedef in use"); for (auto& l : lista) cout << l << endl;

	// Hello World
	{
		cout << "Hello world!" << endl;

		#ifdef DEBUG
				cout << "Debug Mode on" << endl;
		#endif
		cout << endl;

		srand((unsigned int)time(NULL));
	}
	Time_Scope time("main", 3, 0);	

	// Mo¿e to pole name do klas, ¿eby automatycznie wyœwietla³o nazwê
	// ale jeœli u¿. nie poda nazwy to te¿ jest giet
	
	// inicjalizacja
	int* t = new int[10]{};

	unique_ptr<int> unique = make_unique<int>(10); //cout << unique << " " << *unique << endl;
	unique_ptr<int[]> unique_tab = make_unique<int[]>(10); //cout << unique_tab << endl;  for (int i = 0; i < 10; i++) unique_tab[i] = 0; for (int i = 0; i < 10; i++) cout << unique_tab[i] << endl;

	int size = 5;		// rozmiar , wartoœæ jak¹ inicjujemy
	vector<double> simple (size, 0);							// vector 1d 
	vector<vector<double>> matrix (size, vector<double>(size)); // vector 2d 
	
	// {} do chowania tego co nie potrzebne na teraz
	{
		// ruppysuppy   Daily - Coding - Problem - Solutions
		{
			{
				// Problem 9 - biggest non-adjacent sum
				/*
				Coding_Problems::Problem_9 p;

				Array_Optimization<int> opt;
				int size = 0;
				int* tab = opt.From_txt_to_array("input_1.txt", size);

				p.biggest_non_adjacent_sum(tab, size);
				*/

				// Problem 10 - very simple job scheduler
				/*
				Coding_Problems::Problem_10 p;
				p.Job_Scheduler([]() -> void {cout << "job" << endl; }, 1000);
				*/

				// Problem 14 - Monte Carlo - pi approximation
				/*
				Coding_Problems::Problem_14 p;
				p.Pi_approximation(10000000, 1);
				*/
			}
		}
		//Stack
		/*Stack<string> test;

		test.Push("kot");
		test.Push("ma");
		test.Push("ale");
		test.Push("nie ma");

		cout<<"ile tego "<<test.Count()<<endl;
		cout << test.Pop() << endl;

		test.Show_All();

		int size = 0;
		string* tab = test.Return_Tab(size);

		Show_Tab(tab, size);*/
		//Queue
		/*
		cout << "KOLEJKA" << endl;
		Queue<string> que;
		que.Enque("cos");
		que.Enque("mam");
		que.Enque("ciekawego");
		que.Enque("do");
		que.Enque("powiedzenia");
		cout << "ile: " << que.Count() << endl;

		cout<<que.Peek()<<endl;
		que.Show_All();

		cout << "dequeed " << que.Deque() << endl;
		que.Show_All();

		string tab[4];
		tab[0] = "tab";
		tab[1] = "value";
		tab[2] = "from";
		tab[3] = "tab";

		que.Clear();
		que.Enque_from_tab(tab, 4);
		que.Show_All();
		*/
		//Array
		/*
		Array_Functions<int> functions_int;

		Array_template_trick<int, 15> trick;
		auto* ptrick = trick.Return_Pointer();
		functions_int.Initialize_Value(ptrick, 15, 0);

		Array_Dynamic<int> dynamic;
		dynamic.Add(10);
		dynamic.Add(15);
		dynamic.Add(16);

		cout << dynamic[2] << endl;

		auto* pdynamic = dynamic.Return_Pointer();
		auto size = dynamic.Return_Size();
		functions_int.Initialize_Value(pdynamic, size, 15);

		functions_int.Show_Tab(ptrick, 15);
		functions_int.Show_Tab(pdynamic, size);
		*/
		//List
		/*
		List<int> list;
		list.Add_Back(10);
		list.Add_Back(12);
		list.Add_Back(14);

		int index = list.Index_of(12);
		cout << "znalezony index " << list.Item(index) << endl;
		*/
		//List multiple value
		/*
		List_Multivalue<char, int> multi_a;
		List_Multivalue<char, int> multi_b;
		List_Multivalue<char, int> multi_c;
		List_Multivalue<char, int> multi_d;

		int tab_a[1];
		tab_a[0] = 1;

		int tab_b[2];
		tab_b[0] = 1;
		tab_b[1] = 2;

		int tab_c[3];
		tab_c[0] = 1;
		tab_c[1] = 2;
		tab_c[2] = 4;

		int tab_d[4];
		tab_d[0] = 1;
		tab_d[1] = 2;
		tab_d[2] = 4;
		tab_d[3] = 8;

		multi_a.Add_Back('T', tab_a, 1);
		multi_b.Add_Back('A', tab_b, 2);
		multi_c.Add_Back('B', tab_c, 3);
		multi_d.Add_Back('U', tab_d, 4);

		multi_a.Show();
		multi_b.Show();
		multi_c.Show();
		multi_d.Show();
		*/
		//List_Multivalue leak check
		/*
		int size = 30;
		int* random = new int[26];
		string alfabet = "abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < 26; i++) random[i] = (int)alfabet[i];


		List_Multivalue<string, int>* przykladowy = nullptr;
		for (int j = 0; j < 100000000; j++)
		{
			przykladowy = new List_Multivalue<string, int>;
			for (int i = 0; i < 100; i++) przykladowy->Add_Back_Constructor("czesc", random, 26);
			delete przykladowy; // w destruktorze j¹ usuwane wszystkie linked objecty
		}

		*/
		//Stats
		/*
		Stats stat;

		stat.Create_file("pierwszy_test", 15, 1000, 2147483640, 10000);
		*/
		// Search Patterns
		/*
		Time time;
		Array_Functions<int> fun;
		Search_Patterns search_p;

		time.Start();
		string full_tekst = search_p.Odczytane_z_Pliku();
		time.Stop();
		cout << "odczyt z pliku: " << time.Get_how_much_time_passed() << endl << endl << endl;


		cout << "Brute force" << endl;
		int size_b = 0;
		time.Start();
		int* tab_b = search_p.Brute_Force_Approach_returns_table_of_index(full_tekst, "Lorem", size_b);
		time.Stop();

		cout << "znalazl elementow: " << size_b;
		//fun.Show_Tab(tab_b, size_b);
		//search_p.Show_Index_In_Tekst("Lorem", tab_b, size_b, 5, 5);
		time.Show_how_much_time_passed();


		cout << "Knuth Morris Pratt" << endl;
		int size_p = 0;
		time.Start();
		int* tab_p = search_p.Knuth_Morris_Pratt(full_tekst ,"Lorem", size_p);
		time.Stop();

		cout << "znalazl elementow: " << size_p;
		//fun.Show_Tab(tab_p, size_p);
		//search_p.Show_Index_In_Tekst("Lorem", tab_p, size_p, 5, 5);
		time.Show_how_much_time_passed();


		cout << "Boyer Moore"<<endl;
		int size_d = 0;
		time.Start();
		int* tab_d = search_p.Boyer_Moore(full_tekst, "Lorem", size_d);
		time.Stop();

		cout << "znalazl elementow: " << size_d;
		//fun.Show_Tab(tab_d, size_d);
		//search_p.Show_Index_In_Tekst("Lorem", tab_d, size_d, 5, 5);
		time.Show_how_much_time_passed();


		cout << "Rabin Karp" << endl;
		int size_h = 0;
		time.Start();
		int* tab_h = search_p.Rabin_Karp(full_tekst, "Lorem", 13, size_h);
		time.Stop();

		cout << "znalazl elementow: " << size_h;
		//fun.Show_Tab(tab_d, size_d);
		//search_p.Show_Index_In_Tekst("Lorem", tab_d, size_d, 5, 5);
		time.Show_how_much_time_passed();
		*/
		// Numeric Systems	
		/*
		Unique_ptr<Time_Scope> ptr = new Time_Scope("main");

		Number_Bases based;
		int input = 43981;

		cout << based.Binary(input) << endl;
		cout << based.Binary_Bit(input) << endl;
		cout << based.Octagonal(input) << endl;
		cout << based.Octagonal_Bit(input) << endl;
		cout << based.Decimal(input) << endl;
		cout << based.Hexadecimal(input) << endl;
		cout << based.Hexadecimal_Bit(input) << endl;
		*/
		// Intersect Check
		/*
		Array_Dynamic<int> tab_1;
		tab_1.Make_Random_Array_No_Repeat(10, 50);
		Array_Dynamic<int> tab_2;
		tab_2.Make_Random_Array_No_Repeat(20, 50);

		Array_Functions<int> f;
		int size = 0;
		int *tab = f.Array_Intersect(tab_1.Return_Pointer(), tab_1.Return_Size(), tab_2.Return_Pointer(), tab_2.Return_Size(), size);

		cout << "pierwsza" << endl;
		tab_1.Show_All();
		cout << "druga" << endl;
		tab_2.Show_All();
		cout << "wynikowa tablica" << endl;
		f.Show_Tab(tab, size);
		*/
		// String	  // Parse to Int // Job well done
		/*
		String number = "-123456f778";

		cout << "czy mozna " << number.Try_Parse_to_Int() << endl;

		int test = number.Parse_to_Int();
		cout << "wynik testu " << test << endl;

		test -= 1;
		cout << "wynik testu " << test << endl;

		test *= (-1);
		cout << "wynik testu " << test << endl;

		test *= 0;
		cout << "wynik testu " << test << endl;
		*/
		// Bong sort DONE
		/*
		Array_Dynamic<int> dy;
		int random = 0;
		for (int i = 0; i < 15; i++)
		{
			random = rand() % 100 + 1;
			dy.Add(random);
		}
		dy.Show_All();

		auto* tab = dy.Return_Pointer();
		auto size = dy.Return_Size();

		dy.Sort_Bong(tab, size);
		cout << "after sort" << endl;
		dy.Show_All();
		*/
		// Word Cross - teraz bez ci¹g³ej alokacji i dealokacji
		/*
		Word_Cross w;
		Matrix<char> result;
		Unique_ptr<List_Multivalue<string, int>> list =	w.All_cases_present_My_Matrix("jul", result, 25);
		result.Show();
		list->Show();
		*/
		// Matrix Transposition also for non square
		/*
		Matrix<int> test(10, 5);

		int** tab = new int* [10];

		for (int i = 0; i < 10; i++)
		{
			tab[i] = new int[5];
			for (int j = 0; j < 5; j++) tab[i][j] = j + 1;
		}



		test.Get_values_from_raw_matrix(tab, 10, 5);
		test.Show();


		test.Transposition();
		test.Show();
		*/
		// Array Binary search of index in sorted array
		/*
		Array_Dynamic<int> obj;
		int tab[] = { 1,2,3,5,4,6,7,8,9,10 };


		obj.Add_from_tab(tab, 10);
		obj.Sort_Bubble(obj.Return_Pointer(), obj.Return_Size());
		obj.Show_All();


		cout << "index is " << obj.Find_Index_of_sorted_array(8, obj.Return_Pointer(), obj.Return_Size()) << endl;
		*/
		// Array_Dynamic random no repeate with guarantiee of some values
		/*
		Array_Dynamic<int> obj;
		int tab[] = { 1,2,3,4,5,6 };

		obj.Make_Random_Array_No_Repeat_with_this_values_included(tab, 6, 10, 50);
		cout << obj << endl;
		obj.Sort();
		cout << obj << endl;
		*/
		// Dzia³aj¹ce Sudoku
		/*
		Sudoku obj;

		//obj.Make_Sudoku();
		//obj.Save_Matrix_to_File("matrix.txt");

		while (true)
		{
			obj.Make_Sudoku_Many_Lists();
			obj.Show();
			Sleep(100);
			system("cls");
		}
		*/
		// sprawdzanie parsowania dla Stringa - testowanie limitów 
		/*
		Random_Value<String> s;
		String range = "-12345";
		int counter = 1;
		bool breaker = true;
		while (breaker)
		{
			for (int i = 0; i < 1000; i++)
			{
				String result = s.return_random_value(range, counter);

				bool only_at_beginning = true;
				for (int j = 1; j < result.Length(); j++) if (result[j] == '-') only_at_beginning = false;

				if (!result.Try_Parse_to_Int() && result[0] == '-' && only_at_beginning)
				{
					cout << result << endl;
					cout << counter << endl;
					breaker = false;
					break;
				}
			}
			counter++;
		}
		*/
		// Bool_tab //
		// 16 bitów do dyspozycji	
		/*
		unsigned short int t = 1;
		t <<= 15;
		cout << t << endl;
		*/
		// Bool_tab test --- success
		/*
		Bool_tab<10> a;
		a.Show();

		a(9, true);
		a.Show();

		a.Set_all_true();
		a.Show();

		a(9, false);
		a.Show();

		a(1, false);
		a.Show();

		a(0, false);
		a.Show();


		cout << endl << "wykaz" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (i % 8 == 0) cout << endl;
			cout << a[i];
		}
		*/
		// Bool tab 2D test --- success
		/*
		Bool_tab_2D<5,5> b;

		cout << endl;
		b(1, 1, true);
		b(0, 0, true);
		b(0, 1, true);
		b(0, 2, true);
		b(4, 4, true);
		*/
		// String 	  // to z wycinaniec jakiegoœ patternu i usuwaniem konkretnych liter
		/*for (int i = 0; i < 10000000000000; i++)
		{
			String tab = "Test";
		}*/
		// Varaible Limist // Bit Operations
		/*
		int j;
		j = 1;

		for (int i = 0; i < 31; i++)
		{
			cout << i  << " proba: ";
			cout << j << endl;
			j <<= 1;
		}

		cout << "przed negacja " << j << endl;
		j = ~j;
		cout << "po negacji " << j << endl;
		*/
		// Smart_Pointers
		/*
		cout << "poczatek duzego" << endl;
		{
			Shared_ptr<Time_Scope> first = new Time_Scope("duzy");
			{
				cout << "poczatek malego" << endl;
				Unique_ptr<Time_Scope> ptr = new Time_Scope("maly");

				Shared_ptr<Time_Scope> second = first;
			}
			cout << "koniec malego" << endl;
		}
		cout << "koniec duzego" << endl;
		*/
		// Zmiana z Stringa na liczê binarn¹
		/*
		Number_Bases obj;

		String s =    "10000000000000000000000000000000";
		String u =    "10000000000000000000000000000000";
		String u_biggest = "11111111111111111111111111111111";
		String u_ = "01111111111111111111111111111111";

		String sa =   "01111111111111111111111111111111";
		String saa =  "11111111111111111111111111111111";
		String saaa = "1111";

		cout << endl << s << endl;
		cout << "main signed - " << obj.Parse_to_Int_from_Binary(s) << endl;

		cout << endl << saaa << endl;
		cout << "main signed - " << obj.Parse_to_Int_from_Binary(saaa) << endl;

		cout << endl << s << endl;
		cout << "main signed - " << obj.Parse_to_Int_from_Binary(s) << endl;

		cout << endl << sa << endl;
		cout << "main signed - " << obj.Parse_to_Int_from_Binary(sa) << endl;

		cout << endl << saa << endl;
		cout << "main signed - " << obj.Parse_to_Int_from_Binary(saa) << endl;


		cout << endl << endl;




		cout << endl << u << endl;
		cout << "main unsigned - " << obj.Parse_to_Un_Int_from_Binary(u) << endl;

		cout << endl << u_ << endl;
		cout << "main unsigned - " << obj.Parse_to_Un_Int_from_Binary(u_) << endl;


		cout << endl;
		cout << "biggest" << endl;
		cout << u_biggest << endl;
		cout << "main unsigned - " << obj.Parse_to_Un_Int_from_Binary(u_biggest) << endl;
		*/
		// Test Matrix do uk³adu wspó³rzenych
		/*
		Matrix<int> obj(25, 25);
		obj.Initiate_value(0);
		obj.Put_This_value_in_random_places(1, 2);
		//obj.Show();
		obj.Show_nothing_if_zero();
		//obj.Show();
		*/
		// Ró¿nicze w zapisie liczb w pamiêci ---> wy³uskowanie z ró¿nych pointerów --- Ilostracja ró¿nych prymitywnych typów danych
		/*
		int i = 24;
		void* pointer = &i;

		cout << "Value casting" << endl;
		cout << "int:        " << ((int)i) << endl;
		cout << "long long:  " << ((long long)i) << endl;
		cout << "char:       " << ((char)i) << endl;
		cout << "float:      " << ((float)i) << endl;
		cout << "double:     " << ((double)i) << endl;

		cout << endl << "Pointer casting" << endl;
		cout << "int:        " << *((int*)pointer) << endl;
		cout << "long long:  " << *((long long*)pointer) << endl;
		cout << "char:       " << *((char*)pointer) << endl;
		cout << "float:      " << *((float*)pointer) << endl;
		cout << "double:     " << *((double*)pointer) << endl;
		*/
		// Password Generetor
		/*
		String s;

		while(true)
		{
			s = s.Password_Generetor_basic_set(10);
			cout << s << endl;
			cin.get();
		}
		*/
		// Fractions 0 -> x
		/*
		Interesting_Operations o;
		int how_many = 0;

		double chosen = 100;
		double tmp = o.Fractions_from_0_to_user_number(chosen);
		while (tmp != chosen)
		{
			how_many++;
			tmp = o.Fractions_from_0_to_user_number(chosen);
			cout << tmp << endl;
		}
		cout << how_many << endl;
		cout << tmp << endl;
		*/

		// --- ZAJEBISTA REKURENCJA ---
		// Permutacje z powtórzeniami
		/*
		Interesting_Recursion inte;

		int size = 10;
		int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;
		int window = 5;

		cout << "set " << endl;
		for (int i = 0; i < size; i++) cout << tab[i] << " ";

		inte.HUB_Permutations(tab, size, window);
		inte.basic_call_no_repeat(tab, size, window);
		*/
		// ODPOWIED NA PYTANIE WSZECHCZASÓW --- jakie kombinacje podanych liczb sumuj¹ siê do okreœlonej wartoœci
		/*
		int size = 10;
		int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;
		int sum = 12;

		Interesting_Recursion i;
		i.basic_call_no_repeat_sum(tab, size, sum);
		i.basic_call_no_repeat_showing_sum(tab, size);
		*/

		// Move Semantisc
		/*
		{
			{
				Entity_Bad_Allocation test("Wojtek");
				test.Show();
			}
			cout << endl << endl;
			{
				Entity_with_Move test("Wojtek");
				test.Show();
			}
		}


		{
			cout << endl << endl << "##########################" << endl;
			cout << "##########################" << endl;
			cout << "##########################" << endl << endl;
			String wojtek("Wojtek");

			{
				Entity_Bad_Allocation test(wojtek);
				test.Show();
			}
			cout << endl << endl;
			{
				// Entity_with_Move test(wojtek);
				// test.Show();
			}
		}
		*/
		// Jumping String
		/*
		JumpingString s;

		s.Add("ciekawe ");
		s.Add("czy ");
		s.Add("dobrze \n");
		s.Add("zadziala");

		s.Print();
		cout << s.Count_in_Total() << endl;

		JumpingString new_s = s;
		new_s.Print();
		cout << new_s.Count_in_Total() << endl;

		JumpingString string;

		{
			string = new_s;
			cout << "string: " << endl;
			string.Print();
			cout << string.Count_in_Total() << endl;
		}
		*/
		// Checking Stack allocated obj
		/*
		int* Tab()
		{
			int tab[40]{};
			return tab;
		}


		string* Str()
		{
			string test = "Wojtek";
			return &test;
		}

		int* tab = nullptr;
		{
			tab = Tab();
		}
		string wojtek = "Wojtaz";

		int taba[100]{};
		int tabb[100]{};
		int tabc[100]{};
		int tabd[100]{};

		//int* t = new int[10]{};

		unique_ptr<int> unique = make_unique<int>(10); //cout << unique << " " << *unique << endl;
		unique_ptr<int[]> unique_tab = make_unique<int[]>(10); //cout << unique_tab << endl;  for (int i = 0; i < 10; i++) unique_tab[i] = 0; for (int i = 0; i < 10; i++) cout << unique_tab[i] << endl;

		tab[12] = 1;
		for (int i = 0; i < 40; i++) cout << tab[i] << endl;


		string* test = Str();
		cout <<"->" << *test << "<-" << endl;
		*/		
		// Foreach array, vector
		/*
		string tab[] = {"wojtek", "tab"};

		std::vector<string> v;
		v.reserve(3);
		v.emplace_back("wojtek");
		v.emplace_back("tab");
		v.emplace_back("mad scientist");

		v[1] = "k";

		for (auto& vec : v)
			cout << vec << "\n";

		for (const auto& vec : v)
			cout << vec << "\n";

		array<int, 10> ar{};

		for (auto& a : ar)
		{
			a = 1;
			cout << a << "\n";
		}

		cout << "other" << "\n\n";
		for (const auto& a : ar)
			cout << a << "\n";



		String moj[] = {"moj", "string"};
		for (String m : moj)
			cout << m << "\n";

		cout << "\n";

		std::array<JumpingString, 3> jump_array;
		jump_array[0] = "jump";
		jump_array[1] = "jump";
		jump_array[2] = "jump";

		cout << "\nprint array" << endl;
		printArray(jump_array);


		JumpingString jump[] = {"inny", "test"};

		for (auto j : jump)
		{
			j = "zmiana";
			j.Print(); cout << "\n";
		}

		for (auto& j : jump)
		{
			j.Print(); cout << "\n";
		}
		*/
		// Foreach list
		/*
			list<JumpingString> lista;
			lista.emplace_back("clear");
			lista.emplace_back("consisten");
			lista.emplace_back("boundery");

			for (JumpingString& l : lista)
				l.Print(); cout << "\n";
		*/
		// Maps
		/*
		map<string, int> nazwy_numer;

		nazwy_numer["test"] = 12;
		nazwy_numer["t"] = 13;
		nazwy_numer["te"] = 14;

		for (auto& n : nazwy_numer)
		{
			cout << n.first;
			cout <<" " << n.second << endl;
		}

		int a = nazwy_numer.at("t");
		int b = nazwy_numer["testing"];

		cout << nazwy_numer.at("t") << "\n";
		cout << a << "\n";
		cout << b << "\n";
		*/
		// Foreach on my List --- coœ trzeba dorobiæ, ¿eby dzia³a³o	
		/*
		List<int> test;
		test.Add_Back(10);
		test.Add_Back(20);
		test.Add_Back(30);
		test.Add_Back(40);

		for (auto& i : test)
			cout << i.value << "\n";
		*/
		// Frequency of use
		/*
		unordered_map<string, int> hash;
		hash["a"] = 10;
		hash["b"] = 11;
		hash["c"] = 20;
		hash["d"] = 30;


		unordered_map<string, int>::iterator it = hash.find("a");
		cout << (*it).second << endl;

		for (auto& h : hash)
		{
			cout << h.first << " ";
			cout << h.second << endl;
		}
		*/
		// Matrix 2d, but actually 1d
		/*
		Array_1d_like_2d<double> arr(5,5);
		arr.tabFillUp();

		arr(0, 0) = 10;
		//arr.print();
		arr.printMatrix();
		*/
		// Vector 1d 2d 3d    
		// ---> clear() kasuje wszystko nawet z zagnie¿dŸonych vectorów 2d i 3d 	  (bo to s¹ tylko obiekty, które aktywuj¹ swoje destruktory)
		/*
		typedef vector<int> vec1d;
		typedef vector<vector<int>> vec2d;
		typedef vector<vector<vector<int>>> vec3d;
	
		int vecsize = 10;
		VectorOperations vop;
		{
			vec1d a(vecsize, 1);									//vop.print1d(a);
			vec2d b(vecsize, vec1d(vecsize, 2));					//vop.print2d(b);
			vec3d c(vecsize, vec2d(vecsize, vec1d(vecsize, 3)));	//vop.print3d(c);
		}

		// pointery
		while(1)
		{
			vec1d* a = new vec1d(vecsize, 1);									//vop.print1d(a);
			vec2d* b = new vec2d(vecsize, vec1d(vecsize, 2));					//vop.print2d(b);
			vec3d* c = new vec3d(vecsize, vec2d(vecsize, vec1d(vecsize, 3)));	//vop.print3d(c);

			//a->clear(); 
			delete a;
			//b->clear(); 
			delete b;
			//c->clear(); 
			delete c;
		}
		*/
		// Testing iterating through vector ---> resize vs reserve			reserver nie powoduje wyœwietlania pustych itemów, resize tak
		/*
		vector<int> vec;

		vec.reserve(50);
		vec.push_back(0);

		int i = 0;
		for (auto& v : vec)
		{
			vec.push_back(10);
			cout << i << " "; i++;
			cout << v << endl;

		}
		*/
		// Bool switching 0 to 1, 1 to 0	---> ~ doesn't work to switch, ! does
		/*
		bool test = true;

		int i = 10;
		while (i-- > 0)
		{
			cout << i << " ";

			test = !test;
			cout << test << endl;
		}
		*/	
		// Unique Test
		/*
		int b = 10;
		int c = 10;
	
		while (1)
			UniqueTest tmp(b, c);

	
		tmp.Print();

		cout << endl;
		cout << "incrementing" << endl;		b++; c++;
		cout << endl;	
	
		tmp.Print();	
		*/
	}

	cout << "";









	

	
	
	return 0;
}