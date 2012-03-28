//
//  set.cpp
//  Lab2-1
//
//  Created by Albert Skog on 2012-03-27.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <new>
#include "set.h"

//constructors
Set::Set ()
{
    header = new Node(NULL, NULL);
}

Set::Set (int a[], int n)
{
    header = new Node(NULL, NULL);
    for (int i = 0; i < n; i++)
    {
        cout << "insert " << a[i] << endl;
        insert(a[i]);
    }
}

Set::Set (const Set& b)
{
    header = new Node(NULL, NULL);
    for (Node* n = b.header->next; n; n = n->next )
    {        
        insert(n->value);
    }
    
}

//destructor
Set::~Set ()
{

}

bool Set::empty () const
{

}

int Set::cardinality() const
{

}

bool Set::member (int x) const
{

}

//overloaded operators
Set Set::operator+ (const Set& b) const
{

}

Set Set::operator* (const Set& b) const
{

}

Set Set::operator- (const Set& b) const
{

}

Set Set::operator+(int x) const
{

}

Set Set::operator-(int x) const
{

}

bool Set::operator<=(const Set& b) const
{

}

bool Set::operator==(const Set& b) const
{

}

bool Set::operator<(const Set& b) const
{

}

void Set::insert (int value)
{
    if (!header->next)
    {
        header->next = header->insert(value);
    }
    else
    {
        //hello future Albert; den här loopen är trasig:
        for (Node* n = header->next; n->next; n = n->next) {
            
            cout << "n->next->value=" << n->value;
            cout << " value=" << value;
            
            
            if ( value < n->next->value ) {
                header->next = header->insert(value);
                return;
            }
        }
    }
}

void Set::del (int value)
{

}

ostream& operator << (ostream& os, const Set& b)
{
    //cout << "b.header=" << b.header << endl;
    for (Node* n = b.header->next; n; n = n->next)
    {
        //cout << "n=" << n << " n->next=" << n->next << " n->value=" << n->value <<endl;
        os << n->value << " ";
    }
    return os;
}

