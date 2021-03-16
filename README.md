# Hash Table

## Description

This project implements a hash table using the chaining technique in order to manage collisions.

The hash table uses an array and the chaining is performed by a sinlgy linked list.

The code features template classes to make the hash table more versatile. By now, it only supports
integer types, floating point types and char types.

## Execution Process

This project was developed in a Linux OS, so in order to compile this project and test it, it is 
necessary to have this package installed:

```
sudo apt-get install build-essential -y
```

After that, a terminal should be opened in the corresponding location. Any cpp file can be created 
to work with, and the hash table library sould be included like:

```
#include "HashTable.h"
```

_Note_: the hash table header file includes the "LinkedList.h" library, so it is not necessary to 
call it again.

The main.cpp file in the repository can be used as a first try to see how it works, stores and displays the 
elements in the hash table. Then, the users can utilize the hash table as they want.
The way a hash table object should be created is like so:

_Using_ a single initial value:

```
dataType name = value;

HashTable< dataType > objectName(value);
```

_Using_ an array of elements:

```
dataType array[] {list_of_values};

HashTable< dataType > objectName(array, arraySize);
```

### Compile the Code for Linux

_To_ get the code compiled, type the next command:

```
g++ -Wall -Wextra -o executableName main.cpp
```

The g++ compiler was used, -Wall to enable all the warning options as well as some extra ones with the 
-Wextra flag. In addition, the executable file is created using the -o flag and right next to it a name
should be given instead of executableName, which is only an example. Last but not least, specify the source
file name by typing its name and extension.


No warnings or errors should be displayed after executing the command.

# Working with Files

This project can also be used to count the amount of characters in a *.txt file. The _HashTable_ data type has 
to be _char_. The fstream library was used to open and read a file. The insertion of the characters to the hash 
table was done using the _.insert(character)_ method.

An example, is provided in _countingLetters.cpp_, which reads the _file.txt_ file and puts the letters in the hash
table.

```
HashTable< char > name(' '); //_Initialize with any character_

name.del(' '); //_After initializing the hash table, delete the inital character_

name.show(); //_Use this command to display the hashed characters_
```

# Development

This project was built using Linux Ubuntu 18.04 and the g++ compiler.



