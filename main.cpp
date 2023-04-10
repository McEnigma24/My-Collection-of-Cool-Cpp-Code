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

#ifdef DEBUG
#define LOG(x) cout << x << endl;
#define OPERATIONS
#else
#define LOG(x)
#endif

int main()
{
#ifdef OPERATIONS
	cout << "siema" << endl;
#endif

	cout << "Hello world!" << endl << endl;
	srand((unsigned int)time(NULL));
	Time_Scope time("main", 3, 0);

	// {} do chowania tego co nie potrzebne na teraz
	{
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
			delete przykladowy; // w destruktorze j� usuwane wszystkie linked objecty
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
		// Word Cross - teraz bez ci�g�ej alokacji i dealokacji
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
		// Dzia�aj�ce Sudoku
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
		// sprawdzanie parsowania dla Stringa - testowanie limit�w 
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
		// 16 bit�w do dyspozycji	
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
	}

	// String 	  // to z wycinaniec jakiego� patternu i usuwaniem konkretnych liter
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
	// Zmiana z Stringa na licz� binarn�
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
	// Test Matrix do uk�adu wsp�rzenych
	/*
	Matrix<int> obj(25, 25);
	obj.Initiate_value(0);
	obj.Put_This_value_in_random_places(1, 2);
	//obj.Show();
	obj.Show_nothing_if_zero();
	//obj.Show();
	*/
	// R�nicze w zapisie liczb w pami�ci ---> wy�uskowanie z r�nych pointer�w --- Ilostracja r�nych prymitywnych typ�w danych
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


	// Mo�e to pole name do klas, �eby automatycznie wy�wietla�o nazw�
	// ale je�li u�. nie poda nazwy to te� jest giet	

	
	// Permutacje z powt�rzeniami
	/*
	Interesting_Operations inte;

	int size = 10;
	int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;	
	int window = 3;

	inte.Permutations_by_Recursion_Hub(tab, size, window);
	*/

	// to samo ale na przyk�ad z mo�liwo�ci� z�apania kolejno�ci
	// zamiast tylko 1, niech ka�dy kolejny daje o jeden wi�kszy ni� ostatni najwi�kszy w tablicy (bo ca�a reszta to 0)
	// p�niej mo�na odtworzy� kolejno�� ---> znale�� najwi�kszy na li�cie i wiesz, �e tyle ich b�dzie, znajdujesz po koleji pozycje od 1 do tego maxa
	// niech iteruje w k�ko po p�tli puki nie dojdzie do ostatniego

	int size = 10;
	int* tab = new int[size]; for (int i = 0; i < size; i++) tab[i] = i + 1;
	int window = 5;

	/*Interesting_Operations i;
	i.basic_call_no_repeat_sum();
	i.basic_call_no_repeat_showing_sum();*/

	return 0;
}