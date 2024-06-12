#pragma once 
#include <iostream>

class tString
{
private:
  char*  str_;
  size_t length_;

public:

	tString ();				// конструктор по умоолчанию
	tString	( const char* str );		// конструктор с параметром
	tString	( const tString& other );	// контсруктор копирования
	tString	( tString&& other ) noexcept;	// конструктор перемещения 

   ~tString ();					// деструктор

	tString& operator=  ( const tString& other );		// опрератор присваивания строки
	tString& operator=  ( const char ch );			// опрератор присваивания символа
	tString& operator=	(  tString&& other ) noexcept;	// оператор присвания перемещением

	tString  operator+  ( const tString& other );		// оператор сложения со строкой 
	tString  operator+  ( const char ch );				// оператор сложения с символом

	tString& operator+= ( const tString& other );		// оператор добавления к строке строки
	tString& operator+= ( const char ch );				// оператор добавления к строке символа

	bool	 operator==	( const tString& other );		// оператор сравнения
	bool	 operator!=	( const tString& other );		// оператор сравнения
	
	char&	 operator[]	( const size_t index );			// оператор получения по индексу

	friend std::ostream& operator<<(std::ostream& os, const tString& str);	// вспомогательный оператор для вывода на консоль
	friend std::istream& operator>>(std::istream& is,  tString& str);		// вспомогательный оператор для ввода c консолиым 

	size_t get_len ();	// получения длинны
	char*  get_str ();	// получения строки

};
