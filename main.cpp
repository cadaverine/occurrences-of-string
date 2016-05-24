#include <iostream>

#include "mystring.h"

using namespace std;

int main()
{
	MyString s, t("baobab"), z;
	s = "abracadabra";

	t.console_out();

	s.console_out();

	z = t;
	z.console_out();

	s.get_line();

	s.console_out();

	return 0;
}