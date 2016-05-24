#include <iostream>

#include "mystring.h"


using namespace std;


// Конструктор по умолчанию
MyString::MyString() : length(0), flag(false) {}

// Конструктор, принимающий C-style строку в качестве аргумента
MyString::MyString(const char ch[]) : length(0), flag(true)
{
	while (ch[length] != '\0')
	{
		length++;
	}

	str = new char[length];

	for (int i = 0; i < length; i++)
	{
		str[i] = ch[i];
	}
}

// Конструктор копирования
MyString::MyString(MyString const & s) : length(s.size()), flag(true)
{
	str = new char[length];

	for (int i = 0; i < length; i++)
	{
		str[i] = s.pointer()[i];
	}
}

// Оператор присваивания
MyString & MyString::operator=(MyString const & s)
{
	if(flag == true) delete[] str;

	length = s.size();

	str = new char[length];

	for (int i = 0; i < length; i++)
	{
		str[i] = s.pointer()[i];
	}
}

// Оператор присваивания для C-style строки
MyString & MyString::operator=(const char ch[])
{
	if(flag == true) delete[] str;

	int counter = 0;

	while (ch[counter] != '\0')
	{
		counter++;
	}

	length = counter;

	str = new char[length];

	for (int i = 0; i < length; i++)
	{
		str[i] = ch[i];
	}
}

// Деструктор
MyString::~MyString()
{
	if(flag == true) delete[] str;
}

// Длина строки
int MyString::size() const
{
	return length;
}

// Указатель на массив 
char * MyString::pointer() const
{
	return str;
}

// Консольный вывод
void MyString::console_out()
{
	cout << "Строка: '";
	for (int i = 0; i < length; i++) 
	{
		cout << str[i];
	}
	cout <<"'"<< endl;
}


// Консольный ввод строки
void MyString::get_line()
{
	if(flag == true) delete[] str;

		length  = 10;
	int counter =  0;

	str = new char[length];

	char x;

	// Пока осуществляется консольный ввод (до символа переноса строки)
	while (cin.get(x) && x != '\n')
	{
		// Увеличиваем массив на 10 по мере его заполнения введенными символами
		if (counter == length)
		{
			char * temp = new char[counter];

			for (int i = 0; i < counter; i++)
			{
				temp[i] = str[i];
			}
			delete[] str;

			length = length + 10;

			str = new char[length];

			for (int i = 0; i < counter; i++)
			{
				str[i] = temp[i];
			}
			delete[] temp;
		}
		str[counter] = x;
		counter++;
	}

	// Создаем окончательный массив размера, 
	// соответствующего количеству введенных символов 
	if (counter < length)
	{
		length = counter;

		char * temp = new char[counter];

		for (int i = 0; i < counter; i++)
		{
			temp[i] = str[i];
		}
		delete[] str;

		str = new char[length];

		for (int i = 0; i < counter; i++)
		{
			str[i] = temp[i];
		}
		delete[] temp;
	}
}


// Методы поиска вхождений:
//
// Первое вхождение
int MyString::first_occurrence()
{
	
}

// Последнее вхождение
int MyString::ast_occurrence()
{

}

// Количество всех вхождений
int MyString::occurrence_num()
{

}

// Количество пересекающихся вхождений
int MyString::ol_occurrence_num()
{
	
}