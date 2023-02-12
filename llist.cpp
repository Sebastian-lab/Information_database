//CS311 Yoshii SUM22 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Sebastian Partow
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ Front = NULL;
  Rear = NULL;
  Count = 0;
  //cout << "... in llist constructor..." << endl;
 }

llist::~llist()
{
  //cout << "calling the llist destructor\n";
el_t temp; 
while(!isEmpty()){
    deleteFront(temp);
  }
// cout << ".... in llist destructor..." << endl; 
}

//PURPOSE: The purpose is to return if the linked list is empty
//PARAMETER: none
bool llist::isEmpty() {
  if(Front == NULL && Rear == NULL && Count == 0) //there might be in error in our code elsewere so we check all 3 position just so we know if the pointers or count is messed up.
    return true;
  return false;} 

//PURPOSE: To display all of the elems of the nodes in the linked list
//PARAMETER: none
void llist::displayAll() {
  Node* ptr = Front;
  cout << "[ ";
  while(ptr != NULL){
    cout << ptr->Elem << " ";
    ptr = ptr->Next;
  }
  cout << "]";
 }  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE:Adding a new node to the end of the linked list
//PARAMETER: el_t which is an int that will be the value of the new node
void llist::addRear(el_t NewNum) {
  Node* ptr = new Node{NewNum, NULL};
  //first case is if the linked list is empty
  if(isEmpty()){
    Front = ptr;
    Rear = ptr;
    Count = 1;
  }else{
  //second case is adding the new Node to the end of the list that already has Nodes;
    Rear->Next = ptr; //makes it so the the current rear is pointing to the node that we are making the new rear
    Rear = ptr; //makes the rear pointer point at the new node now that everything is connected
    Count++;
  }
 } // comment the 2 cases

//PURPOSE: Adds a new node to the front of the linked list
//PARAMETER: el_t which is a int that is the Elem going into the new node.
void llist::addFront(el_t NewNum) {
  Node* ptr = new Node{NewNum, Front}; //we set next = front here because it works for both cases. If the list is empty front = nullptr; and if the list have values we want the next to = the current front.
  //first case is the linked list is empty
  if(isEmpty()){
    Front = ptr;
    Rear = ptr;
    Count = 1;
  }else{
    //second case is that there are nodes already in the linked list
    Front = ptr;
    Count++;
  }
 } // comment the 2 cases

//PURPOSE: We want to remove the front node
//PARAMETER: the parameter is an int so that we can store the value of the node if we want do display what we got rid of.
void llist::deleteFront(el_t& OldNum) {
  //first case the list is empty
  if(isEmpty()){
    throw Underflow();
  }else if(Count == 1){
    //cases two and three can be combined together into one algorithm. If there is only one element in the linked list then fron->next is nullptr and counter is 1 so setting front to nullptr and counter to 0 is correct. If there are multiple nodes is the list then Front->Next is going to be the next Node in the linked list which will be the new Front and subtracting one from count is corret because we are removing one node.  
    //Node* ptr = Front;
    //OldNum = ptr->Elem;
    //Front = Front->Next;
    //delete ptr;
    //Count--;
    Node* ptr = Front;
    Front = NULL;
    Rear = NULL;
    Count = 0;
    OldNum = ptr->Elem;
    delete ptr;
  } else {
    Node* ptr = Front;
    OldNum = Front->Elem;
    Front = Front->Next;
    delete ptr;
    Count--;
  }

 } // comment the 3 cases

//PURPOSE:
//PARAMETER:
void llist::deleteRear(el_t& OldNum){
  //first case is if the list is empty
  if(isEmpty()){
    throw Underflow();}
  else if(Count == 1){
    //second case is if there is only one node in the linked list;  
    Node* ptr = Rear;
    OldNum = ptr->Elem;
    Front = NULL;
    Rear = NULL;
    Count = 0;
    delete ptr;
  }else{
    //third case is there are multiple node is the linked list 
    Node* ptr = Front;
    OldNum = Rear->Elem;
    while(ptr->Next != Rear){ //we want to get to one Node before rear because it is going to become the new Rear
      ptr = ptr->Next;
    }
    ptr->Next = NULL; //removes the current Rear from the linked list
    delete Rear;
    Rear = ptr; //sets the Rear pointer to look at the new Rear
    Count--;
  }

} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
  temp = Front;
  for(int K = 0; K < J-1; K++){
    temp = temp->Next;
  }
}

//PURPOSE: Given an index we reomve the Node that is in that position
//PARAMETER: Int I is the position and el_t is used to store the Elem of the Node we are removing
void llist::deleteIth(int I, el_t& OldNum) {
  cout << "The current Count: " << Count << endl;
  Node* temp;
  //first case I is an illegal value (occurs when the llist is empty or the value called is larger than the linked list;
  if(I > Count || I < 1){
    throw OutOfRange();
  } else if(I == 1){
    //second case is if the number being deleted is in the front;
    deleteFront(OldNum);
  } else if(I == Count){
    //third case is if the number being deleted is in the end
    deleteRear(OldNum);
  } else {
    //final case removing a number in the middle of the linked list
    moveTo(I-1,temp); //I am moving the temp pointer to the position behind the node I want to remove.
    Node* temp2 = temp->Next; //setting a second pointer to the Node that I want to remove;
    temp->Next  = temp2->Next; //detaching the Node I want to remove from the list;
    OldNum = temp2->Elem;
    delete temp2;
    Count--;
  }
 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: To insert a New Node to a given position in the linked list
//PARAMETER: int I which is the position that the Node is going to be added to the list and newNum which is going to be the Elem in the new node that we are adding to the list
void llist::insertIth(int I, el_t newNum) {
  //first case is that I is an illegal value
  if(I < 1 || I > Count + 1){
    throw OutOfRange();
  } else if(I == 1){
    //second case is that the new Node is being added to the front
    addFront(newNum);
  } else if(I == Count +1){
    //third case is that the New Node is being added to the Rear
    addRear(newNum);
  }else {
    //final case is that the New node is being added to a random position in the middle of the linked list
    Node* temp;
    moveTo(I-1, temp); //moving temp to the position one before the position I was to add the new Node into.
    Node* temp2 = new Node{newNum, temp->Next}; //creating the new Node that is going to be added to the linked list
    temp->Next = temp2; //fully ataching the new Node to he linked list
    Count++;
  }
 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: To creat a new linked list that is a deep copy of another linked list
//PARAMETER: The linked list that we want to copy.
llist::llist(const llist& Original) {
  cout << "Running copy constructor\n";
  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;
  el_t x;
  if(&Original != this)
    {
      while(! this->isEmpty())
	{
	  this->deleteRear(x);
	}
  Node* P;
  P = Original.Front;
  while(P != NULL){
    this->addRear(P->Elem);
    P = P->Next;
  }
    }
 } // use my code

//PURPOSE: To make a deep copy of the Linked list that you are setting the current linked list equal to.
//PARAMETER: The linked list that you are trying to make a copy of
llist& llist::operator=(const llist& OtherOne) {
  el_t x;
  if(&OtherOne != this){
    while(! this->isEmpty()){
      this->deleteRear(x);
    }
    Node* P;
    P = OtherOne.Front;
    while(P!=NULL){
      this->addRear(P->Elem);
      P = P->Next;
    }
  }
  return *this;
 } // use my code

