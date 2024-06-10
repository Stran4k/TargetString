#include<iostream>
#include "tString.h"


int main()
{
	setlocale(LC_ALL, "ru");

	tString str("Hello ");
	tString str2("world");

	tString result;

	result = str + str2;

	result.print();
	std::cout << std::endl << std::endl;

	tString result1=result;
	
	result1 += result;
	result1.print();

	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	result.print();


	std::cout << std::endl << std::endl;
	//system("pause");
	return 0;
}

