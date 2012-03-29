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
    for (Node* n = header; n; n = header)
    {
        header = header->next;
        delete n;
    }
}

bool Set::empty () const
{
    //header->next will refer to NULL for empty sets
    return !header->next;
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

const Set& Set::operator=(const Set& b)
{
    //Node* to = header->next;
    for (Node* n = b.header->next; n; n = n->next) {
        insert(n->value);
        //to = to->next;
    }
    return *(new Set());
}

void Set::insert (int value)
{
    //insert if it is the first node..
    if (!header->next)
    {
        header->next  = header->insert(value);
    }
    else
    {
        //..otherwise find the right place for it
        for (Node* n = header->next; n; n = n->next) {
            if (value > n->value && n->next)
            {
                if (value < n->next->value)
                {
                    n->next = n->insert(value);
                    return;
                }
            }
            else if(!n->next)
            {
                n->next = n->insert(value);
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
    if (b.empty()) {
        os << "Set is empty!";
    }
    else
    {
        os << "{ ";
        //cout << "b.header=" << b.header << endl;
        for (Node* n = b.header->next; n; n = n->next)
        {
            //cout << "n=" << n << " n->next=" << n->next << " n->value=" << n->value <<endl;
            os << n->value << " ";
        }
        os << "}";
    }
    return os;
}

