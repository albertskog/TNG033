/*
TNG033 - Exercise 1
Albert Skog
albsk635
870327-7593
*/

#include <iostream>

using namespace std;

class List;

/********************************
* Class Node definition         *
*********************************/

class Node {
public:
   // Constructor
   Node (int i, Node* ptr):  value (i), next (ptr)
   { };


private:
   int value;
   Node* next;

   friend class List;
   friend ostream& operator <<(ostream &os, const List& L);
};



/********************************
* Class List definition         *
*********************************/

class List {
public:

   //Constructors
   List() { header = NULL; }

   //Add new constructor
    List(int i) { header = new Node(i, NULL); }

   //destructor
   ~List ();

   //Add append operator
    List& operator+ (List& l);

   friend ostream& operator << (ostream& os, const List& L);


private:
   Node *header;
};

/*****************************************************
* Class List member functions implementation         *
******************************************************/

//Append operator
List& List::operator+ (List& l) {
    if (!(header && l.header) || (header == l.header)) {
        return *this;
    }
    
    Node* n = header;
    Node* o = l.header;

    //Go to end of this list
    while (n->next) {
        //cout << n->value << endl;
        n = n->next;
    }

    //Append l
    while (o) {
        n->next = new Node(o->value, NULL);
        n = n->next;
        o = o->next;
    }

    return *this;
}

List::~List()
{
    if (header)
	  {
		 Node *temp = header -> next;
		 while (temp != NULL)
		 {
			delete header;
			header = temp;
			temp = temp -> next;
		 }
		 delete header;
	  }
}



ostream& operator<< (ostream& os, const List& L)
{
    if (!L.header)
    {
        os << "The list is empty!!" << endl;
        return os;

    }

    Node *temp = L.header;
    while (temp)
    {
        os << temp -> value << " ";
        temp = temp -> next;
    }
    os << endl;

   return os;
}


/**************************************
* Main function  -- test              *
* DO NOT CHANGE                       *
***************************************/

int main()
{
    List L1, L2;
    List L3(3), L4(4), L5(5), L6(6);

    cout << "List L1: " << L1 << endl;
    cout << "List L2: " << L2 << endl;
    cout << "List L3: " << L3 << endl;
    cout << "List L4: " << L4 << endl;
    cout << "List L5: " << L5 << endl;
    cout << "List L6: " << L6 << endl;
    cout << "List L1+L2: " << L1+L2 << endl;
    L3+L4+L5+L6;
    cout << "List L3+L4+L5+L6: " << L3 << endl;

    L1+L3;
    cout << "List L1+L3: " << L1 << endl;

    L3+L2;
    cout << "List L3+L2: " << L3 << endl;

    L3+L3; //self-appending
    cout << "Self-appending L3+L3: " << L3 << endl;

    return 0;
}
