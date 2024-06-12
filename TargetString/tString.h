#pragma once 
#include <iostream>

class tString
{
private:
  char*  str_;
  size_t length_;

public:

	tString ();								// ����������� �� ����������
	tString	( const char* str );			// ����������� � ����������
	tString	( const tString& other );		// ����������� �����������
	tString	( tString&& other ) noexcept;	// ����������� ����������� 

   ~tString ();								// ����������

	tString& operator=  ( const tString& other );		// ��������� ������������ ������
	tString& operator=  ( const char ch );				// ��������� ������������ �������
	tString& operator=	(  tString&& other ) noexcept;	// �������� ��������� ������������

	tString  operator+  ( const tString& other );		// �������� �������� �� ������� 
	tString  operator+  ( const char ch );				// �������� �������� � ��������

	tString& operator+= ( const tString& other );		// �������� ���������� � ������ ������
	tString& operator+= ( const char ch );				// �������� ���������� � ������ �������

	bool	 operator==	( const tString& other );		// �������� ���������
	bool	 operator!=	( const tString& other );		// �������� ���������
	
	char&	 operator[]	( const size_t index );			// �������� ��������� �� �������

	friend std::ostream& operator<<(std::ostream& os, const tString& str);	// ��������������� �������� ��� ������ �� �������
	friend std::istream& operator>>(std::istream& is,  tString& str);		// ��������������� �������� ��� ����� c ��������� 

	size_t get_len ();	// ��������� ������
	char*  get_str ();	// ��������� ������

};
