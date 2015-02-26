Linked List Implementation of a Stack with Constant Time Push, Pop, and Findmin
===============================================================================

----------------------------------------------------------

Objective
---------

Suppose one is implementing a stack of integers using a singly linked list. It is trivial to implement push and pop in worst case O(1) time (i.e. constant time) by maintaining the top of the stack to be the first element in the linked list and the bottom of the stack to be the last element in the linked list. The objective is to include another operation called “findmin” which returns the minimum element in the stack. All the 3 operations (push, pop and findmin) must all run in O(1) time. An additional linked list may be used.

Naïve Solution
--------------

Implement two stacks using linked lists. Call them nStack and mStack (for “normal stack” and “min stack”). For each element pushed into nStack, compare with mStack’s top element and push the smaller of the two into mStack. For each element popped from nStack, pop one element from mStack. For findmin operation, return top element in mStack.

+ Push() – Θ(1)
+ Pop() – Θ(1)
+ FindMin() – Θ(1)
+ Space used – Θ(N) for nStack, Θ(N) for mStack

Better Solution
---------------

Implement two stacks using linked lists. Call them nStack and mStack (for “normal stack” and “min stack”). For each element pushed into nStack, compare with mStack’s top element and push the element into mStack only if it is lesser than or equal to the top element. For each element popped from nStack, pop the top element from mStack only if it is equal to the element popped from nStack. For findmin operation, return top element in mStack.

+ Push() – Θ(1)
+ Pop() – Θ(1)
+ FindMin() – Θ(1)
+ Space used – Θ(N) for nStack, O(N) for mStack

The solution is better since it requires O(N) space for mStack instead of Θ(N) since it requires space of N in worst case (reverse sorted numbers are pushed) but lesser space in any other case


License
-------

[MIT License](http://jay.mit-license.org/2013)
