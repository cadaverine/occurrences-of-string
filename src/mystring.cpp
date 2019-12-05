#include <iostream>

#include "mystring.h"

using namespace std;

// Конструктор по умолчанию
MyString::MyString() : length(0), flag(false) {}

// Конструктор, принимающий C-style строку в качестве аргумента
MyString::MyString(const char ch[]) : length(0), flag(true) {
	while (ch[length] != '\0') {
		length++;
	}

	str = new char[length];

	for (int i = 0; i < length; i++) {
		str[i] = ch[i];
	}
}

// Конструктор копирования
MyString::MyString(MyString const & s) : length(s.size()), flag(true) {
	str = new char[length];

	for (int i = 0; i < length; i++) {
		str[i] = s.pointer()[i];
	}
}

// Оператор присваивания
MyString & MyString::operator=(MyString const & s) {
	if(flag == true) delete[] str;

	length = s.size();

	str = new char[length];

	for (int i = 0; i < length; i++) {
		str[i] = s.pointer()[i];
	}
}

// Оператор присваивания для C-style строки
MyString & MyString::operator=(const char ch[]) {
	if(flag == true) delete[] str;

	int counter = 0;

	while (ch[counter] != '\0') {
		counter++;
	}

	length = counter;

	str = new char[length];

	for (int i = 0; i < length; i++) {
		str[i] = ch[i];
	}
}

// Деструктор
MyString::~MyString() {
	if(flag == true) delete[] str;
}

// Длина строки
int MyString::size() const {
	return length;
}

// Указатель на массив
char * MyString::pointer() const {
	return str;
}

// Консольный вывод
void MyString::console_out() {
	cout << "Строка: '";
	for (int i = 0; i < length; i++) {
		cout << str[i];
	}
	cout <<"'"<< endl;
}

// Консольный ввод строки
void MyString::get_line() {
	if(flag == true) delete[] str;

	length  = 10;
	int counter =  0;

	str = new char[length];

	char x;

	// Пока осуществляется консольный ввод (до символа переноса строки)
	while (cin.get(x) && x != '\n') {
		// Увеличиваем массив на 10 по мере его заполнения введенными символами
		if (counter == length) {
			char * temp = new char[counter];

			for (int i = 0; i < counter; i++) {
				temp[i] = str[i];
			}
			delete[] str;

			length = length + 10;

			str = new char[length];

			for (int i = 0; i < counter; i++) {
				str[i] = temp[i];
			}
			delete[] temp;
		}
		str[counter] = x;
		counter++;
	}
	// Создаем окончательный массив размера,
	// соответствующего количеству введенных символов
	if (counter < length) {
		length = counter;

		char * temp = new char[counter];

		for (int i = 0; i < counter; i++) {
			temp[i] = str[i];
		}
		delete[] str;

		str = new char[length];

		for (int i = 0; i < counter; i++) {
			str[i] = temp[i];
		}
		delete[] temp;
	}
}

// ------------------------------------------------------------------------------------------------
// Методы поиска вхождений:
//
// Первое вхождение (возвращает индекс)
int MyString::first_occurrence(MyString const & s) {
	// Основная строка должна быть длиннее или равна подстроке
	if (length >= s.size()) {
		int index = -1; // -1, если вхождений нет

		// Проходим по основной строке до индекса, за которым оставшаяся часть строки короче подстроки
		for (int i = 0; i <= length - s.size(); i++) {
			// Проходим по обеим строкам до тех пор, пока совпадают их символы или не закончится подстрока
			for (int j = 0; j < s.size()  &&  str[i + j] == s.pointer()[j]; j++) {
				if (j == s.size() - 1) {
					return i;
				}
			}
		}
	}

	return -1;
}

// Последнее вхождение (возвращает индекс)
int MyString::last_occurrence(MyString const & s) {
	// Основная строка должна быть длиннее или равна подстроке
	if (length >= s.size()) {
		int index = -1; // -1, если вхождений нет

		// Проходим по основной строке до индекса, за которым оставшаяся часть строки короче подстроки
		for (int i = 0; i <= length - s.size(); i++) {
			// Проходим по обеим строкам до тех пор, пока совпадают их символы или не закончится подстрока
			for (int j = 0; j < s.size()  &&  str[i + j] == s.pointer()[j]; j++) {
				if (j == s.size() - 1) {
					index = i;
				}
			}
		}
		return index;
	}

	return -1;
}

// Количество всех вхождений
int MyString::occurrence_num(MyString const & s) {
	// Основная строка должна быть длиннее или равна подстроке
	if (length >= s.size()) {
		int counter = 0; // 0, если вхождений нет

		// Проходим по основной строке до индекса, за которым оставшаяся часть строки короче подстроки
		for (int i = 0; i <= length - s.size(); i++) {
			// Проходим по обеим строкам до тех пор, пока совпадают их символы или не закончится подстрока
			for (int j = 0; j < s.size()  &&  str[i + j] == s.pointer()[j]; j++) {
				if (j == s.size() - 1) {
					counter++;
				}
			}
		}
		return counter;
	}

	return 0;
}

// Количество пересекающихся вхождений overlapping
int MyString::ol_occurrence_num(MyString const & s) {
	// Основная строка должна быть длиннее или равна подстроке
	if (length >= s.size()) {
		int overlapping_counter = 0; 	// 0, если пересекающихся вхождений нет
		int total_counter = 0;			// общий счетчик вхождений
		int index = 0;   				// индекс предыдущего вхождения
		bool flag = false;				// флаг пересечений

		// Проходим по основной строке до индекса, за которым оставшаяся часть строки короче подстроки
		for (int i = 0; i <= length - s.size(); i++) {
			// Проходим по обеим строкам до тех пор, пока совпадают их символы или не закончится подстрока
			for (int j = 0; j < s.size()  &&  str[i + j] == s.pointer()[j]; j++) {
				if (j == s.size() - 1) {
					// Если вхождения есть и расстояние между индексами начала вхождений меньше длины подстроки,
					// инкрементируем счетчик overlapping_counter и поднимаем флаг
					if (total_counter > 0 && index + s.size() - 1 >= i) {
						overlapping_counter++;
						flag = true;
					}
					// Если пересечение есть, но расстояние между индексами больше длины подстроки (разрыв) -
					// фиксируем последнее пересекающееся вхождение до разрыва, инкрементируя счетчик overlapping_counter,
					// и сбрасываем флаг
					if (flag == true && index + s.size() - 1 < i) {
						overlapping_counter++;
						flag = false;
					}
					total_counter++;
					index = i;
				}
			}
		}
		// Если флаг поднят - фиксируем последнее пересекающееся вхождение
		if (overlapping_counter > 0 && flag == true) {
			overlapping_counter++;
		}
		return overlapping_counter;
	}

	return 0;
}
