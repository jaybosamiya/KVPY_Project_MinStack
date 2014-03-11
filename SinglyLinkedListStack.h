/*

SinglyLinkedListStack declaration and definition

Copyright 2013 Jay H. Bosamiya

*/

#ifndef FILE_SINGLYLINKEDLISTSTACK_H
#define FILE_SINGLYLINKEDLISTSTACK_H

template<class T> class SinglyLinkedListStack {
	struct Node {
		T value;
		Node *next;
	};
	Node *stackTop;
	public:
	SinglyLinkedListStack();
	~SinglyLinkedListStack();
	bool top ( T &element );
	void push ( T element );
	bool pop();
};

template<class T> SinglyLinkedListStack<T>::SinglyLinkedListStack() {
	stackTop = new Node;
	stackTop->next = NULL;
}

template<class T> SinglyLinkedListStack<T>::~SinglyLinkedListStack() {
	while ( pop() ) {}
	delete stackTop;
}

template<class T> void SinglyLinkedListStack<T>::push ( T element ) {
	Node *tempNode = new Node;
	tempNode->value = element;
	tempNode->next = stackTop;
	stackTop = tempNode;
}

template<class T> bool SinglyLinkedListStack<T>::top ( T &element ) {
	if ( stackTop->next == NULL ) return false;
	element = stackTop->value;
	return true;
}

template<class T> bool SinglyLinkedListStack<T>::pop() {
	if ( stackTop->next == NULL ) return false;
	Node *tempNode = stackTop;
	stackTop = stackTop->next;
	delete tempNode;
	return true;
}

#endif