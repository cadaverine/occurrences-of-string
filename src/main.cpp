#include <iostream>

#include "mystring.h"

using namespace std;

int main() {
	MyString s, t;

	cout << endl;

	cout << "Введите строку: ";
	s.get_line();

	cout << "Введите подстроку: ";
	t.get_line();

	cout << endl;

	cout << "Первое вхождение: ";
	cout << s.first_occurrence(t) << endl;

	cout << "Последнее вхождение: ";
	cout << s.last_occurrence(t) << endl;

	cout << "Всего вхождений: ";
	cout << s.occurrence_num(t) << endl;

	cout << "Пересекающихся вхождений: ";
	cout << s.ol_occurrence_num(t) << endl;

	cout << endl;

	return 0;
}