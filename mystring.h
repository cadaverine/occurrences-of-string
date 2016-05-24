#ifndef _MYSTRING
#define _MYSTRING


class MyString
{
private:
	char * str;
	int length;

	bool flag; // true, если пямять выделена

public:
	// Конструктор по умолчанию
	MyString();

	// Конструктор копирования
	MyString(MyString const & s);

	// Оператор присваивания
	MyString & operator=(MyString const & s);

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


	// Методы поиска вхождений:
	//
	// Первое вхождение
	int first_occurrence();

	// Последнее вхождение
	int last_occurrence();

	// Количество всех вхождений
	int occurrence_num();

	// Количество пересекающихся вхождений
	int ol_occurrence_num(); // overlapping

};

#endif // _MYSTRING