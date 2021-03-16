//Counting all the letters from a file
//Characters must be alphanumeric
#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"

int main(){
		
	std::ifstream inFile;
	inFile.open("./file.txt");
	if(!inFile){
		std::cerr << "Problem opening file" << std::endl;
		return 1; 
	}
	
	HashTable<char> h(' ');
	h.del(' ');
	char cursor{};		
	while(inFile.get(cursor)){
		//If the character is not a line break and it is alphanumeric
		if(cursor != '\n' && std::isalnum(cursor)){
			h.insert(cursor);
		}
	}
	
	inFile.close();
	
	h.show();
	
	std::cout << std::endl;
	std::cout << "File closed successfully" << std::endl;

	std::cout << "How many letters \'y\' s are there in the file?: " << h.occurrences('y') << std::endl;
	
	return 0;
}
