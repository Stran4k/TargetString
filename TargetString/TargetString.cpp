
#include "tString.h"
#include <vector>

/*
	-1	// <0
	 1	// >0
	 0	// ==0
	сравнение символов без учета регистра
*/
int lowStrCmp(tString& str1, tString& str2)
{
	for (size_t i = 0; ; i++)
	{
		if (tolower(str1[i]) != tolower(str2[i]))
		{
			return tolower(str1[i]) < tolower(str2[i]) ? -1 : 1;
		}

		if (str1[i] == '\0')
		{
			return 0;
		}
	}
}

// сортировка пузырьком в обратном лексикографическом порядке без учета регистра
void BubleSort(std::vector <tString>& str) {	 

	for (size_t i = 1; i < str.size(); ++i) {			
		for (size_t j = 0; j < (str.size() - 1);++j) {	

			if (lowStrCmp(str[j],str[j+1]) == -1) {
				tString temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}

}


int main(){

	//std::vector <tString> vStr = {  "aaa", "bbb", "ccc", "bcdc","dcc", "Abbc", "abc", "bCCCd", "ergc", "Eac" };
	
	std::cout << std::endl << "Enter the number of words " << std::endl;
	size_t num = 0;
	std::cin >> num;
	std::cout << std::endl;

	std::cout << std::endl << "Enter the lines " << std::endl;
	std::vector<tString> vStr;

	for ( int i = 0; i < num; ++i ) {
		tString temp;
		std::cin >> temp;
		vStr.push_back(temp);
	}
	std::cout << std::endl;

	BubleSort( vStr );

	for ( auto a : vStr ) {
		std::cout << a << "  ";
	}
	std::cout << std::endl << std::endl;

	/*tString str("Hello ");
	tString str2("world ");
	tString result;

	result = str + str2;
	std::cout <<result << std::endl << std::endl;

	tString result1=str2+str;
	result1 += result;
	result1 += 'h';
	result1 += "lh";
	
	std::cout << result1 << std::endl << std::endl;
	std::cout << std::endl << std::endl;*/
	system("pause");
	return 0;
}


