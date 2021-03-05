#Hash Table

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
\#include "HashTable.h"
```

_Note: this library includes the "LinkedList.h" library, so it is not necessary to call it again.

The main.cpp file in the repository can be used as a first try to see how it stores and displays the 
elements in the hash table. Then, the users can utilize the hash table as they want.
The way a hash table object should be created is:

_Using_ a single initial value:

```
data type name = value;

HashTable< data type> objectName(value);
```

_Using_ an array of elements:

```
data type array[] {list_of_values};

HashTable< data type> objectName(array, arraySize);
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

# Development

This project was built using Linux Ubuntu 18.04 and the g++ compiler.


