#include "split.h"
#include <cstddef> 
#include <iostream>

using namespace std;

int main() 
{
	Node splitt(0,NULL);
	Node clang(15, NULL);
	Node spring(18, NULL);
	Node cling(20, NULL);
	Node ting(23, NULL);

	splitt.next = &clang;
	clang.next = &spring;
	spring.next = &cling;
	cling.next = &ting;
	ting.next = NULL;

	Node *evens = NULL;
	Node *odds = NULL;

	Node *in = &splitt;
	split(in,odds,evens);

	cout << "Odds: " << endl;
	while (odds != NULL)
	{
		cout << odds -> value << endl;
		odds = odds -> next;
	}
	
	cout << "Evens: " << endl;
	while (evens != NULL)
	{
		cout << evens -> value << endl;
		evens = evens -> next;
	}

}
