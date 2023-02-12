//CS311 Yoshii SUM22 llist.h

//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Sebastian Partow
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================
#include "elem.h"
// alias el_t : element type definition
// int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
   void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //Returns true if there are no nodes in the linked list
  bool isEmpty();
    
  //displays all nodes in the linked list from front to end
  void displayAll();

  //adds a new node to the front of the list
  void addFront(el_t);
    
  //adds a new node to the end of the list
  void addRear(el_t);

  //removes the first node in the list
  void deleteFront(el_t&);
  
    
  //removes the last node in the list
  void deleteRear(el_t&);

  //---------------------------------------


  //**
  void deleteIth(int, el_t&);  // calls moveTo

  //**    
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
