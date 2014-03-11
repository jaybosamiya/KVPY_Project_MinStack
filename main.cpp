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

#include "MinStack.h"

int main() {
	int t;
	MinStack<int> m;
	m.push(5);
	m.push(10);
	m.findMin(t);std::cout << t << std::endl; // 5
	m.push(2);
	m.findMin(t);std::cout << t << std::endl; // 2
	m.pop();
	m.findMin(t);std::cout << t << std::endl; // 5
	m.pop();
	m.pop();
	m.push(11);
	m.findMin(t);std::cout << t << std::endl; // 11
}
