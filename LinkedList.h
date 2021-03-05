#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>

template <class T>
class Node{
	public:
		T data;
		Node<T> *next;
};

template <class T>
class LinkedList{
	private:
		Node<T> *first;
		Node<T> *last;
		int length;
	public:
		LinkedList<T>();
		LinkedList<T>(T value);
		~LinkedList<T>();
		//Methods
		void display();		
		void insert(T element,int index);
		void insertInOrder(T value);
		void removeIndex(int index);
		void removeElement(T element);
		int getLength();
		T at(int index);
		T popBack();
		T popFront();
		int count(T element);
		void pushBack(T value);
		void pushFront(T value);
};

//Initialize linked list to '\0'
template <class T>
LinkedList<T>::LinkedList(){
	first = new Node<T>;
	first->data = '\0';
	first->next = nullptr;
	last = first;
	length = 1;
}

//Get length
template <class T>
int LinkedList<T>::getLength(){
	return length;
}

//Initialize linked list to a value
template <class T>
LinkedList<T>::LinkedList(T value){
	first = new Node<T>;	
	first->data = value;
	first->next = nullptr;
	last = first;
	length = 1;
}

template <class T>
LinkedList<T>::~LinkedList(){
	delete first;
}

template <class T>
T LinkedList<T>::at(int index){
	if(index < 0 || index >= length){
		std::cerr << "Index out of range" << std::endl;
		return -1;
	}
	else if(index == 0){
		return first->data;
	}
	Node<T> *temp = first;
	for(int i=0;i<index;i++){
		temp = temp->next;
	}
	return temp->data;
}

template <class T>
void LinkedList<T>::display(){
	if(first != nullptr){
		Node<T> *p = first;
		std::cout << "{ ";
		while(p != nullptr){
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << "}" << std::endl;
	}
	else {
		return;
	}
}

//Push back method
template <class T>
void LinkedList<T>::pushBack(T value){	
	if(first->data != '\0'){
		Node<T> *temp = last;
		Node<T> *newNode = new Node<T>;
		//Make temp point on last
		newNode->data = value;
		temp->next = newNode;
		last = newNode;
		length++;
		//std::cout << "Length: " << length << std::endl;
	} else {
		first->data = value;
		first->next = nullptr;
		last = first;
	}
}

//Push Front Method
template <class T>
void LinkedList<T>::pushFront(T value){
	if(first->data == '\0' && length == 1){
		first->data = value;
		first->next = nullptr;
		last = first;
	}
	else {
		Node<T> *temp = new Node<T>;
		temp->data = value;
		temp->next = first;
		first = temp;
		length++;
	}	
}

//POP BACK METHOD
template <class T>
T LinkedList<T>::popBack(){
	if(length > 1){
		Node<T> *head = first;
		Node<T> *tail {nullptr};
		int value = 0;
			
		for(int i=0;i<length-1;i++){
			tail = head;
			head = head->next;
		}
		tail->next = nullptr;
		value = head->data;
		delete head;
		last = tail;
		length--;
		return value;
	} 
	else if(length == 1) {
		first->data = '\0';
		first->next = nullptr;
		last = first;
	}
	return -1;
}

//POP FRONT
template <class T>
T LinkedList<T>::popFront(){	
	if(length > 1){
		T value = '\0';
		Node<T> *temp = first;
		first = first->next;		
		value = temp->data;
		delete temp;	
		length--;
		return value;	
	} 
	else if(length == 1){
		first->data = '\0';
		first->next = nullptr;
		last = first;
	}
	return -1;
} 

//Remove method
template <class T>
void LinkedList<T>::removeIndex(int index){
	if(index < 0 || index > length){
		return;
	}
	Node<T> *head = first;
	Node<T> *tail {nullptr};
	if(first->next == nullptr){
		//std::cout << "Cannot delete last element" << std::endl;
		first->data = '\0';
		last = first;
		return;
	}
	else if(index == 0){
		first = first->next;//Move the pointer 'first'
		delete head;
		length--;
	}
	else {
		for(int i=0;i<index;i++){
			tail = head;
			head = head->next;
		}
		tail->next = head->next;//Make the tail node point on the node next to the one deleted
		delete head;
		length--;
	}
}

//Remove a value or element
template <class T>
void LinkedList<T>::removeElement(T element){
	Node<T> *head = first;
	Node<T> *tail {nullptr};
	if(first->next == nullptr){
		//std::cout << "Cannot delete last element" << std::endl;
		first->data = '\0';
		last = first;
		return;
	}
	if(head->data == element){
		first = first->next;
		delete head;
		length--;
	}
	else {
		while(head->next != nullptr){
			tail = head;
			head = head->next;
			if(head->data == element){
				tail->next = head->next;
				delete head;
				length--;
				return;
			}
		}		
	}
}


//Insertion
template <class T>
void LinkedList<T>::insert(T element, int index){
	if(index < 0 || index > length){
		return;
	}
	Node<T> *temp = new Node<T>;
	temp->data = element;
	if(length == 1 && first->data == '\0'){
		first->data = element;
		first->next = nullptr;
		last = first;	
		length = 1;	
	}
	else if(index == 0){		
		temp->next = first;
		first = temp;
		length++;
	}
	else {
		Node<T> *tail{nullptr};
		Node<T> *head = first;	
		//Stop just before the given index
		for(int i=0;i<index;i++){
			tail = head;
			head = head->next;
		}
		tail->next = temp;
		temp->next = head;
		length++;		
	}	
}

template <class T>
void LinkedList<T>::insertInOrder(T value){
	if(first->data == '\0' && length == 1){
		first->data = value;		
	}
	else {
				
		Node<T> *temp = new Node<T>;
		temp->data = value;
		if(value < first->data){
			temp->next = first;
			first = temp;
			last = temp;
		}
		else {
			Node<T> *head = first;
			Node<T> *tail = nullptr;
			while(head != nullptr && head->data < value){
				tail = head;
				head = head->next;
			}
			if(head == first){
				temp->next = first;
				first = temp;
			}
			else {
				tail->next = temp;
				temp->next = head;
			}					
		}		
		length++;					
	}
}

//Count the occurrences of the given number
template <class T>
int LinkedList<T>::count(T element){
	if(length >= 1){
		int counter = 0;
		Node<T> *ptr = first;
		while(ptr != nullptr){
			if(ptr->data == element){
				counter++;
			}
			ptr = ptr->next;
		}
		return counter;
	}
	else {
		return -1;
	}
}


#endif
