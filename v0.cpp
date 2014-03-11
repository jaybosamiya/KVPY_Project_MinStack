/*

Miniproject 1 - Linked List Implementation of a Stack with Constant Time Push, Pop, and Findmin

Suppose you are implementing a stack of integers using a singly linked list. The top of the stack 
will be the first element in the linked list and the bottom of the stack will be the last element 
in the linked list. It is easy to see that both push and pop operations can be implemented easily 
in worst case O(1) time (that is, constant time). Suppose now that you want to implement one more 
operation findmin which will find and return a minimum element in the stack by maintaining an 
additional linked list which correctly keeps track of the minimum element all the time by 
suitably updating the links when a push or pop operation is performed. If it is required that 
the findmin operations should also have a worst case running time of O(1), then how do you
implement the additional list, push operation, pop operation, and findmin operation. Note that all 
three operations must run in worst case constant time. Implement your idea and carry out 
experimentation on a set of data.

Solution
Keep two linked lists.
One of them acts as a normal stack. (call it nStack)
The other keeps elements in such a way that any element in the stack is not greater than any member below it in the stack. (call it mStack)

Push
Push the element into nStack
Compare with the top element in mStack
	If smaller or equal, push it into mStack

Pop
Pop the element from nStack
Compare with top element in mStack
	If equal, pop from mStack

Findmin
Read top element of mStack

*/

/*

Notes:
(1) The linked list can be easily done with STL but I have made my own implementation.
(2) I have used templates so as to make the code reusable. These can be removed to make it specific to
	integers only (as the question asks for).

*/

#include <iostream>

using namespace std;

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
	mStack.top(temp);
	if ( element <= temp ) {
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

int main() {
	int t;
	MinStack<int> m;
	m.push(5);
	m.push(10);
	m.findMin(t);cout << t << endl;
	m.push(2);
	m.findMin(t);cout << t << endl;
	m.pop();
	m.findMin(t);cout << t << endl;
}
