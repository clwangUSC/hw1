#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr u;
  u.push_back("1");
  u.push_front("2");
  //cout<<"front is "<<u.front()<<endl;
  //cout<<"back is "<<u.back()<<endl;
  // u.pop_back();
  // u.pop_front();
  // u.pop_back();
  u.push_back("1");
  u.push_front("3");
  u.push_back("1");
  u.push_front("4");
  u.push_back("1");
  u.push_front("5");
  u.push_back("1");
  u.push_front("6");
  u.push_back("1");
  u.push_front("2");
  u.pop_back();
  u.pop_back();
  u.pop_back();
  u.pop_back();
  u.pop_back();
  u.pop_back();
  u.pop_front();
  u.pop_front();
  
  
}
