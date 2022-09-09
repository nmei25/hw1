#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
//Adds a new value to the back of the list
void ULListStr::push_back(const std::string& val)
{
	if (empty()){ //checking if empty
		Item *newItem = new Item;
		newItem -> val[0] = val;
		head_ = newItem;
		tail_ = newItem;
		newItem -> last++;
		size_++;
		return;
	}
	if (tail_ -> last == 10){ //checking if it's full in the back
		Item *newItem = new Item;
		tail_-> next = newItem;
		newItem -> prev = tail_;
		tail_ = newItem;
		tail_ -> val[0] = val;
		newItem -> last++;
		size_++;
	}
	else{
		tail_ -> val [tail_ -> last] = val; //if it's not full, can add to existing array item
		tail_ -> last++;
		size_++;
	}
}

//Removes a value from the back of the list
void ULListStr::pop_back()
{
	if(empty()){
		return;
	}
	else{
		if (tail_-> last - tail_->first == 1){ //checking only 1 element
			tail_ = tail_ -> prev; // setting new tail to tail previous
			delete tail_ -> next; //removing the last item
			size_--;
		}
		else { //more than 1 element 
			tail_ -> last--;
			size_--;
		}
		if (empty()){ //checking empty again, set rest to NULL
			head_ = NULL;
			tail_ = NULL;
		}
	}
}
//Adds a new value to the front of the list. If there is room before the 'first' value in the head node add it there, otherwise, allocate a new head node.
void ULListStr::push_front(const std::string& val)
{
	if (empty()){  //checking if empty
		Item *newItem = new Item;
		newItem -> val[9] = val;
		newItem -> first = 9;
		newItem -> last = 10; //last is noninclusive so doesn't include 10
		head_ = newItem;
		tail_ = newItem;
		size_++;
		return;
	}
	if (head_ -> first == 0){ //full in the front
		Item *newItem = new Item;
		head_-> prev = newItem;
		newItem -> next = head_;
		head_ = newItem;
		head_ -> val[9] = val;
		newItem -> first = 9;
		newItem -> last = 10; //last is noninclusive so doesn't include 10
		size_++;
	}
	else{
		head_ -> val[head_-> first-1] = val; //putting into item that already exist
		head_ -> first--;
		size_++;
	}
}
//Removes a value from the front of the list
void ULListStr::pop_front()
{
	if(empty()){
		return;
	}
	else{
		if (head_-> last - head_->first == 1){ //checking only 1 element
			head_ = head_ -> next;
			delete head_ -> prev;
			size_--;
		}
		else { //more than 1 element 
			head_ -> first++;
			size_--;
		}
		if (empty()){ //checking empty again, set rest to NULL
			head_ = NULL;
			tail_ = NULL;
		}
	}
}
//Returns a const reference to the back element
std:: string const & ULListStr:: back() const
{
	return tail_->val[tail_->last-1];
}

//Returns a const reference to the front element
std::string const & ULListStr::front() const
{
	return head_->val[head_ ->first];
}

//Returns a pointer to the item at index, loc,
//if loc is valid and NULL otherwise
std::string* ULListStr:: getValAtLoc(size_t loc) const
{
	if (size_ <= loc){ // not valid, not inclusive
		return NULL;
	}
	else {
		size_t originalLoc = loc; //keeps original location before it changes 
		loc = (head_->first + originalLoc)/10; // this is getting the right node and each node increments by 10
		Item* temp = head_;
		size_t count = 0; //new variable because not same type as loc
		while( count != loc) { //ends when location is equal to counter variable
			temp = temp -> next;
			count++;
		}
		loc = (head_->first + originalLoc) %10; //getting the first element and adding with location
		return &(temp->val[loc]); //returns pointer to the item
	}
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
