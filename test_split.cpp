/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{

  Node* n6 = new Node(6, NULL);
  Node* n5 = new Node(5, n6);
  Node* n4 = new Node(4, n5);
  Node* n3 = new Node(3, n4);
  Node* n2 = new Node(2, n3);
  Node* n = new Node(1, n2);



  Node* eve = NULL;
  Node* odd = NULL;

  split(n,odd,eve);

  Node* temp;
  while(odd->next != NULL && odd->next !=nullptr)
  {
    temp = odd;
    cout<<"delete "<<odd->value<<endl;
    odd=odd->next;
    delete temp;
  }
    temp = odd;
    cout<<"delete "<<odd->value<<endl;
    delete temp;

  while(eve->next != NULL && eve->next !=nullptr)
  {
    temp = eve;
    cout<<"delete even "<<eve->value<<endl;
    eve=eve->next;
    delete temp;
  }
    temp = eve;
    cout<<"delete even "<<eve->value<<endl;
    delete temp;

}
