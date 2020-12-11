/*
//   Written by Professor Kenneth L Moore
//   For CIT245 Data Structures and Programming C++
//   This code implements a singly linked list
//   Students must change it to a doubly linked list
//
//  Modified by Morgan Visnesky
//  Date: 11/14/2018
//  FileName: doublylinkedlist.cpp
//  last modified: 12/01/2018

*/
#include <iostream>
#include <string>
using namespace std;

// define a node for storage and linking
class node{
public:
	string name;
    node *next;
		node *prev; // to be implemented by students
};

class linkedList{
public:
  linkedList():top(NULL){}
	bool empty(){return top == NULL;}
	node *getTop(){return top;}
	void setTop(node *n){top = n;}
	void add(string);
	int menu();
	void remove(string);
	~linkedList();
	void reversePrint(); // to be implemented by students
	friend ostream& operator << (ostream&, const linkedList&); // default output is in-order print.
private:
	node *top;
	node *end; // to be used for reverse print and implemented by students
};

int main(){
   linkedList l;
   cout << l.empty() << endl;
   int option = 0;
   string s;
   bool go = true;
   while(go){
	   option = l.menu();
	   switch(option){
			case 1: cout << "enter a name: ";cin >> s; l.add(s); break;
			case 2: cout << "enter name to be deleted: "; cin >> s; l.remove(s);break;
			case 3: cout << l; break;
			case 4: l.reversePrint(); break;
			case 5: cout << "exiting" << endl; go = false; break;
	   }
   }
   system("pause");
   return 0;
}


void linkedList::remove(string s){
	bool found = false;
	node *curr = getTop(), *prev=NULL;
	while(curr != NULL){

		// match found, delete
		if(curr->name == s){
			found = true;

			// found at top
			if(prev == NULL){
    			node *temp = getTop();
				setTop(curr->next);
				delete(temp);

			// found in list - not top
			}else{
				prev->next = curr->next;
				delete(curr);
			}
		}

		// not found, advance pointers
		if(!found){
			prev = curr;
			curr = curr->next;
		}

		// found, exit loop
		else curr = NULL;
	}
	if(found)cout << "Deleted " << s << endl;
	else cout << s << " Not Found "<< endl;
}

void linkedList::add(string s){
	node *n = new node();
	n->name = s;
	n->next = NULL;

	// take care of empty list case
	if(empty()){
		top = n;
		end = n;

	// take care of node belongs at beginning case
} else if(getTop()->name > n->name){
		n->next = top;
		top->prev = n;
		n->prev = NULL;
		top = n;

	// take care of inorder and end insert
	}else{

		// insert in order case
		node *curr = getTop(), *prev = curr;
		while(curr != NULL){
			if(curr->name > n->name){
				node *temp = curr->prev;
					curr->prev = n;
					n->next = curr;
					n->prev = temp;
					temp->next = n;

					if (curr->next == NULL) {
						end = curr;
					}
					break;
			}
			//prev = curr;
			//curr = curr->next;
			else if(curr->next == NULL){
				curr->next = n;
					n->prev = curr;
					n->next = NULL;
					end = n;
					break;
			}
				curr = curr->next;
				prev = curr->prev;
			}
		}
	}




ostream& operator << (ostream& os, const linkedList& ll){

	node *n = ll.top;
	if(n == NULL)cout << "List is empty." << endl;
	else
		while(n != NULL){
			os << n->name << endl;
			n = n->next;
		}
	return os;
}

// return memory to heap
linkedList::~linkedList(){
	cout << "~linkedList called." << endl;
	node *curr = getTop(), *del;
	while(curr != NULL){
		del = curr;
		curr = curr->next;
		delete(del);
	}
}

int linkedList::menu(){
	int choice = 0;
	while(choice < 1 || choice > 5){
		cout << "\nEnter your choice" << endl;
		cout << " 1. Add a name." << endl;
		cout << " 2. Delete a name." << endl;
		cout << " 3. Show list." << endl;
		cout << " 4. Show reverse list. " << endl; 
		cout << " 5. EXIT " << endl;
		cin >> choice;
	}
	return choice;
}

void linkedList::reversePrint() {
	//node *temp;
	node *curr = end;
	while ( curr != NULL)
	{
		cout << curr->name << " " << endl;
		curr = curr->prev;
	}

}
