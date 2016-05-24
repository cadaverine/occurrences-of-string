#ifndef _MYSTRING
#define _MYSTRING


class MyString
{
public:
	char * str;
	int length;

private:
	// Конструктор по умолчанию
	MyString();

	// Конструктор копирования
	MyString(MyString & s);

	// Оператор присваивания
	MyString & operator=(MyString const & s);

	// Деструктор
	~MyString();

	// Длина строки
	int size() const;


	// Методы поиска вхождений:

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