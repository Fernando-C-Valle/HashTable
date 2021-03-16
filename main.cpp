#include <iostream>
#include <string>
#include "HashTable.h"

int main(){
	
	/*Examples. The hash table by now only supports float, int, char and double data types*/	
	
	std::cout << "-----------Integer Data Type-----------" << std::endl;
	int arr2[30] {100,0,0,3,2,4,6,8,2,3,1,40,50,2,3,9,43,53,24,23,22,7,67,4,5,76,89,968596,2,118};
	HashTable<int> h2(arr2, 30);
	h2.show();	
	int number = 5;
	std::cout << "How many " << number << "'s are there in the hash table? " << h2.occurrences(number) << std::endl;
	h2.del(5);
	h2.insert(0);
	std::cout << "Deleting 5 and Inserting 0" << std::endl;
	h2.show();
	
	std::cout << "-----------Double Data Type-----------" << std::endl;
	double arr3[] {3.5, 5.3, 4.3, 5.1, 6.18, 5.7, 1.3, 5.6, 5.9, 1.1, 0.7, 9.6, 8.7, 7.2, 10.5, 2.345};
	HashTable<double> h3(arr3, 16);
	h3.show();
	double number2 = 5.1;
	std::cout << "How many " << number << "'s are there in the hash table? " << h3.occurrences(number2) << std::endl;
	h3.del(5.1);
	h3.insert(1.3);
	std::cout << "Deleting 5.1 and Inserting 1.3" << std::endl;
	h3.show();
		
	std::cout << "-----------Char Data Type-----------" << std::endl;
	char arr[] {"Hello there, how's it going?"};
	HashTable<char> h(arr, 29);
	h.show();	
	char letter {'e'};
	std::cout << "How many " << letter << "'s are there in the hash table? " << h.occurrences(letter) << std::endl;
	h.del('?');
	h.insert('!');
	std::cout << "Deleting ? and Inserting !" << std::endl;
	h.show();	
		
	//Count all
	for(int i=97;i<=122;i++){
		char temp = i;
		std::cout << temp << ":" << h.occurrences(temp) << std::endl;
	}

	
	return 0;
}
