// CS311 Yoshii SUM22 slist.cpp

// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: **
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

//  Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{
  // cout << "slist constructor:" << endl;
}


// positions always start at 1

//I will use a temp pointer to go through the list and find if the key is in the list.
int slist::search(el_t key){
  int pos = 0;
  int counter = 1;
  Node* temp = Front;
  while(temp != NULL){
    if(temp->Elem == key)
      pos = counter;
    temp = temp->Next;
    counter++;
  }
  return pos;
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
// if the pos given is either less than one or greater than the Count then it is out of range and we throw an exception. Otherwise we use the moveTo function to move a temp pointer to the position given and replace the nodes element with the new one.
void slist::replace(el_t element, int pos){
  if(pos < 1 || pos > Count){
    throw OutOfRange();
  } else {
    Node* temp;
    moveTo(pos, temp);
    temp->Elem = element;
  }
}

// First we check if the lists are the same size because if they aren't will get a segmentation error if we try to go through every element of both lists at the same time. Then we go through both lists and if any of the nodes elements are not the same then we return true, otherwise if we get through the entire list we return true;
bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false immediately
  // if the same lengths,
  //    check each node to see if the elements are the same
  if((*this).Count != OtherOne.Count){
    return false;
  } else {
    Node* temp = Front;
    Node* temp2 = OtherOne.Front;
    for(int i = 1; i <= Count; i++){
      if(temp->Elem != temp2->Elem)
	return false;
      temp = temp->Next;
      temp2 = temp2->Next;
    }
  }
  return true;
}

el_t slist::search2(el_t X){
  el_t M;
  Node* temp = Front;
  while(temp != NULL){
    if(temp->Elem.getkey() == X.getkey())
      M = temp->Elem;
    temp = temp->Next;
  }
  return M;
}
