Project 1 : Sorting Algorithm 
Contributors: Andrew Nguyen, Tri Dang, Huy Phan
Course: CS 271 - Data Structures
Professor: Michael Chavrimootoo


#Description: 
This project is the implementation of a doubly linked list templated data structure using C++. The Doubly Linked List is similar to a Linked List data structure in that it is a series of nodes connected by pointers, but where the standard Linked List’s nodes are made up of an item and one pointer pointing to the next element in the list, the Doubly Linked List nodes have two pointers, one to the next node, and one to the previous node. The Doubly Linked List is a template class, which means the implementation is not limited to a single or small subset of data types.


#Methods:
We implemented the default methods of an object class in C++ ( default constructor, copy constructor, destructor, and assignment operator) as well as typical list class methods which are as follows: 

prepend
Append
search
Indexing operator [ ]
Length
Empty
And Concatenation
See directory guide for further information, specifications on these methods. 


#Directory Guide: 
The definition of the class and the methods are included in the DoublyLinkedList.hpp file, and detailed documentation specifying the operation, parameters, and return values of each method can be found in the DoublyLinkedList.cpp file. 

The test cases could be found in mytests.cpp. You could run this test by entering make mytests into the terminal.

After running "make mytests" into the terminal; you might see a mytests.o and a mytests file. 

Running "make list" on the terminal gives an object file doublylinkedlist

You can clear these objects by entering make clear in the terminal

#Design Choices:

There was only one optional decision we made beyond the basic requirements of the Doubly Linked List class, a list size variable. Having already built the linked list class before, we knew it was worth a few extra lines of code in many of the operators maintaining a size variable for our Doubly Linked List class, as the variable reduces the code needed to implement the length and empty methods to one line each. 


#Challenges: 

Being a Dynamically allocated class, the main challenge of this project was ensuring no memory leakage occurs before, during and after operations. Solving this problem came down to simply having a robust destructor, which looks out for any potential dangling pointers to prevent any chance of leakage. 
Another challenege was with the remove method ensuring that the pointers (prev and next) of neighboring nodes are updated correctly. This is important when removing nodes fro 
One of the challenges was ensuring that insertion at any arbitrary index is efficient and correctly updates the pointers of neighboring nodes. Specifically, when inserting into the middle of the list, we had to traverse from the head to the desired position, update both the prev and next pointers of surrounding nodes, and maintain the integrity of the list. This involved careful consideration of pointer manipulation, particularly when dealing with edge cases like inserting at the beginning or end of the list.

