#ifndef _MYSTRING
#define _MYSTRING

class MyString {
private:
	char * str;
	int length;
	bool flag; // true, если пямять выделена

public:
	// Конструктор по умолчанию
	MyString();

	// Конструктор, принимающий C-style строку в качестве аргумента
	MyString(const char ch[]);

	// Конструктор копирования
	MyString(MyString const & s);

	// Оператор присваивания
	MyString & operator=(MyString const & s);

	// Оператор присваивания для C-style строки
	MyString & operator=(const char ch[]);

	// Деструктор
	~MyString();

	// Длина строки
	int size() const;

	// Указатель на массив
	char * pointer() const;

	// Консольный вывод
	void console_out();

	// Консольный ввод строки
	void get_line();

	// -------------------------------------------------------
	// Методы поиска вхождений:
	//
	// Первое вхождение (возвращает индекс)
	int first_occurrence(MyString const & s);

	// Последнее вхождение (возвращает индекс)
	int last_occurrence(MyString const & s);

	// Количество всех вхождений
	int occurrence_num(MyString const & s);

	// Количество пересекающихся вхождений
	int ol_occurrence_num(MyString const & s); // overlapping
};

#endif // _MYSTRING