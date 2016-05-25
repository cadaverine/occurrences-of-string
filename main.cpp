#include <iostream>

#include "mystring.h"

using namespace std;

int main()
{
	MyString s, t;

	s.get_line();

	t.get_line();

	cout << "Первое вхождение: ";
	cout << s.first_occurrence(t) << endl;

	cout << "Последнее вхождение: ";
	cout << s.last_occurrence(t) << endl;

	return 0;
}