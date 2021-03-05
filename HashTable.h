#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "LinkedList.h"

template <class T>
class HashTable{
	private:
		LinkedList<T> hashTable[10]{};
	public:
		HashTable<T>(T *arr, int size);
		HashTable<T>(T element);
		int hash(T element);
		void show();
		int occurrences(T element);
		void del(T element);
		void insert(T element);
};

template <class T>
HashTable<T>::HashTable(T *arr, int size){
	for(int i=0;i<size;i++){
		hashTable[hash(arr[i])].insertInOrder(arr[i]);
	}
}

template <class T>
HashTable<T>::HashTable(T value){	
	insert(value);
}

template <class T>
int HashTable<T>::hash(T element){
	int typeCast = static_cast<int>(element);
	int hashedValue = (typeCast % 10);
	return hashedValue;
}

template <class T>
void HashTable<T>::show(){
	for(int i=0;i<10;i++){
		hashTable[i].display();
	}
}

template <class T>
int HashTable<T>::occurrences(T element){
	int hashedValue = hash(element);
	int occurrences = hashTable[hashedValue].count(element);
	return occurrences;
}

template <class T>
void HashTable<T>::del(T element){
	//Get corresponding key
	hashTable[hash(element)].removeElement(element);
}

template <class T>
void HashTable<T>::insert(T element){
	hashTable[hash(element)].insertInOrder(element);
}

#endif
