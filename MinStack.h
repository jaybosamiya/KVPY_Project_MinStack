#include "SinglyLinkedListStack.h"

#define INFINITY 2147483647

template<class T> class MinStack {
	SinglyLinkedListStack<T> mStack,nStack; // nStack is normal, mStack is the one with min property
	public:
	MinStack();
	~MinStack();
	bool top ( T &element );
	bool findMin ( T &element );
	void push ( T element );
	bool pop();
};

template<class T> MinStack<T>::MinStack() {
	// Nothing really needed here
}

template<class T> MinStack<T>::~MinStack() {
	// Nothing really needed here
}

template<class T> bool MinStack<T>::top ( T &element ) {
	return nStack.top(element);
}

template<class T> bool MinStack<T>::findMin ( T &element ) {
	return mStack.top(element);
}

template<class T> void MinStack<T>::push ( T element ) {
	T temp;
	if ( !mStack.top(temp) ) {
		mStack.push(element);
	}
	else if ( element <= temp ) {
		mStack.push(element);
	}
	nStack.push(element);
}

template<class T> bool MinStack<T>::pop() {
	T temp, element;
	nStack.top(element);
	mStack.top(temp);
	if ( element == temp ) {
		mStack.pop();
	}
	return nStack.pop();
}
