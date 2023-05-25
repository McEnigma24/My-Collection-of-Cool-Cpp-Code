#pragma once

#include "header.h"

// Jumping String //

JumpingString::JumpingString()
{
}
JumpingString::JumpingString(const char* input)
{
	Add(input);
}
JumpingString::JumpingString(JumpingString& other)
{
	char* comb = other.Combine_to_One();

	tab_list.push_back(comb);
	size_list.push_back(strlen(comb));
}
JumpingString JumpingString::operator=(JumpingString& other)
{
	char* comb = other.Combine_to_One();

	this->tab_list.push_back(comb);
	this->size_list.push_back(strlen(comb));

	return *this;
}
JumpingString JumpingString::operator=(const char* input)
{
	tab_list.clear();
	size_list.clear();

	Add(input);

	return *this;
}

JumpingString::~JumpingString()
{
	// for (list<char*>::iterator tab = tab_list.begin(); tab != tab_list.end(); tab++)		

	for (auto& t : tab_list)
		delete[]t;

	tab_list.clear();
	size_list.clear();
}

int JumpingString::Count_in_Total()
{
	if (tab_list.empty()) return 0;

	int res = 0;
	for (list<int>::iterator size = size_list.begin(); size != size_list.end(); size++)
		res += (*size);

	return res;
}
char* JumpingString::Combine_to_One()
{
	if (tab_list.empty()) return nullptr;

	int total_size = Count_in_Total();
	char* result = new char[total_size + 1];

	list<int>::iterator size = size_list.begin();
	int res_index = 0;
	for (list<char*>::iterator tab = tab_list.begin(); tab != tab_list.end(); tab++, size++)
	{
		for (int i = 0; i < (*size); i++, res_index++)
		{
			result[res_index] = (*tab)[i];
		}
	}

	result[total_size] = '\0';
	return result;
}
void JumpingString::Add(const char* input)
{
	int size = strlen(input);
	char* tab = new char[size + 1];

	for (int i = 0; i < size; i++) tab[i] = input[i];
	tab[size] = '\n';

	tab_list.push_back(tab);
	size_list.push_back(size);
}
void JumpingString::Print()
{
	//cout << "How many jumps: " << distance(tab_list.begin(), tab_list.end()) << endl;

	list<int>::iterator size = size_list.begin();
	char* tmp_tab = nullptr;
	int tmp_size = 0;
	for (list<char*>::iterator tab = tab_list.begin(); tab != tab_list.end(); tab++, size++)
	{
		tmp_tab = (*tab);
		tmp_size = (*size);

		for (int i = 0; i < tmp_size; i++) cout << tmp_tab[i];
	}
}

void JumpingString::operator+=(const char* input)
{
	Add(input);
}

// ~Jumping String //