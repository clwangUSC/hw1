#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if(tail_==NULL)
  {
    Item* temp = new Item();
    temp->val[0] = val;
    tail_=temp;
    head_=temp;
    tail_->first=0;
    tail_->last=1;
  } else if(tail_->last>9)
  {
    Item* temp = new Item();
    temp->val[0] = val;
    tail_->next=temp;
    temp->prev=tail_;
    tail_=temp;
    tail_->first=0;
    tail_->last=1;
  }
  else
  {
    tail_->val[tail_->last]=val;
    (tail_->last)++;
  }
  //cout<<"val "<<val<<endl;
  size_++;
}

void ULListStr::pop_back()
{
  if(tail_==NULL)
  {
    return;

  } else if(tail_->last <= 1)
  {
    if(head_==tail_)
    {
      tail_=NULL;
      delete head_;
      head_=NULL;
    }
    else
    {
      Item* temp = tail_;
      tail_= (tail_->prev);
      delete temp;
      tail_->next=NULL;
    }
  }
  else
  {
    (tail_->last)--;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val)
{
  if(head_==NULL)
  {
    Item* temp = new Item();
    temp->val[9] = val;
    tail_=temp;
    head_=temp;
    head_->first=9;
    head_->last=10;
  } else if(head_->first <= 0)
  {
    Item* temp = new Item();
    temp->val[9] = val;
    head_->prev=temp;
    temp->next=head_;
    head_=temp;
    head_->first=9;
    head_->last=10;
  }
  else
  {
    head_->val[head_->first-1]=val;
    head_->first--;
    
  }
  //cout<<"val "<<val<<endl;
  size_++;
}

void ULListStr::pop_front()
{
  if(head_==NULL)
  {
    return;
  } 
  else if(head_->first>=9)
  {
    if(head_==tail_)
    {
      tail_=NULL;
      delete head_;
      head_=NULL;     
    }
    else
    {
      Item* temp = head_;
      head_=head_->next;
      delete temp;
      head_->prev = NULL;
    }
  }
  else
  {
    head_->first++;
  }
  size_--;
}

std::string const & ULListStr::back() const
{
  return (tail_->val[tail_->last-1]);
}

std::string const & ULListStr::front() const
{
  return (head_->val[head_->first]);
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* temp = head_;
  size_t index=head_->first;
  // int locTemp = loc;
  if(loc>=size())
  {
    return NULL;
  }
  //cout<<"HEY "<<temp->val[index]<<endl;
  for(size_t x=0; x< loc; x++)
  {
    index++;
    if (index>=temp->last)
    {
      temp=temp->next;
      index=temp->first;
    }

  }
  return &(temp->val[index]);
}
