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
Set::~Set () {
    for (Node* n = header; n; n = header)
    {
        header = header->next;
        delete n;
    }
}

bool Set::empty () const{
    //header->next will refer to NULL for empty sets
    return !header->next;
}

int Set::cardinality() const {
    int i = 0;
    for (Node* n = header->next; n; n = n->next) {
        i++;
    }
    return i;
}

bool Set::member (int x) const {
    for (Node* n = header->next; n; n = n->next) {
        if (x == n->value) {
            return true;
        }
    }
    return false;
}

//overloaded operators

Set Set::operator+ (const Set& b) const {
    Node* n = header->next;
    Node* o = b.header->next;
    Set* newSet = new Set();
    
    //combine the sets
    while (n && o) {
        if (n->value < o->value) {
            newSet->header->next = newSet->header->insert(n->value);
            n = n->next;
        }
        else if (n->value > o->value){
            newSet->header->next = newSet->header->insert(o->value);
            o = o->next;
        }
        else if (n->value == o->value) {
            newSet->header->next = newSet->header->insert(n->value);
            n = n->next;
            o = o->next;
        }
    }
    //insert remaining nodes, if any
    while (n) {
        newSet->header->next = newSet->header->insert(n->value);
        n = n->next;
    }
    while (o) {
        newSet->header->next = newSet->header->insert(o->value);
        o = o->next;
    }
    
    /*
    //Old version
    for (Node* n = header->next; n; n = n->next) {
        //cout << "n->value: " << n->value << endl;
        newSet->insert(n->value);
    }
     */
    
    return *newSet;
}

Set Set::operator* (const Set& b) const{

    Node* n = header->next;
    Node* o = b.header->next;
    Set* newSet = new Set();
    
    //combine the sets
    while (n && o) {
        if (n->value < o->value) {
            n = n->next;
        }
        else if (n->value > o->value){
            o = o->next;
        }
        else if (n->value == o->value) {
            newSet->header->next = newSet->header->insert(n->value);
            n = n->next;
            o = o->next;
        }
    }
    /*
    Set* newSet = new Set();
    for (Node* n = b.header->next; n; n = n->next) {
        for (Node* o = header->next; o; o = o->next) {
            if (n->value == o->value) {
                newSet->insert(n->value);
            }
        }
    }
     */
    return *newSet;
}

Set Set::operator- (const Set& b) const {
    Node* n = header->next;
    Node* o = b.header->next;
    Set* newSet = new Set();
    
    while (n && o) {
        if (n->value < o->value) {
            newSet->header->next = newSet->header->insert(n->value);
            n = n->next;
        }
        else if (n->value > o->value){
            o = o->next;
        }
        else if (n->value == o->value) {
            n = n->next;
            o = o->next;
        }
    }
    //insert remaining nodes, if any
    while (n) {
        newSet->header->next = newSet->header->insert(n->value);
        n = n->next;
    }

    return *newSet;
    /*
    //Add all the nodes that are not in b to newSet
    Set* newSet = new Set();
    for (Node* n = b.header->next; n; n = n->next) {
        for (Node* o = header->next; o; o = o->next) {
            if (n->value == o->value) {
                cout << "del: " << n->value;
                newSet->del(n->value);
            }
        }
    }
     */
    
}

Set Set::operator+(int x) const {
    Set* newSet = new Set(*this);
    newSet->insert(x);
    return *newSet;
}

Set Set::operator-(int x) const {
    Node* n = header->next;
    Set* newSet = new Set();
    
    while (n) {
        if (n->value != x) {
            newSet->header->next = newSet->header->insert(n->value);            
        }
        n = n->next;
    }
    return *newSet;
}

bool Set::operator<=(const Set& b) const {
    Node* n = header->next;
    Node* o = b.header->next;
    
    while (n && o) {
        if (n->value < o->value) {
            return false;
        }
        else if (n->value > o->value){
            o = o->next;
        }
        else if (n->value == o->value) {
            n = n->next;
            o = o->next;
        }
    }
    return true;
}

bool Set::operator==(const Set& b) const {
    return (*this <= b) && (this->cardinality() == b.cardinality());
}

bool Set::operator<(const Set& b) const {
    return (*this <= b) && (this->cardinality() < b.cardinality());
}

const Set& Set::operator=(const Set& b){
    for (Node* n = header; n; n = header)
    {
        header = header->next;
        delete n;
    }
    header = new Node(NULL, NULL);
    //cout << "b:" <<b<<endl;
    for (Node* n = b.header->next; n; n = n->next)
    {
        insert(n->value);
    }
    return *this;
}

void Set::insert (int value){
    //cout << "Inserting: " << value << endl;
    
    //insert if it is the first node..
    if (!header->next)
    {
        header->next  = header->insert(value);
    }
    else
    {
        //..otherwise find the right place for it
        for (Node* n = header; n; n = n->next)
        {
            if (value > n->value && n->next)
            {
                if (value < n->next->value)
                {
                    n->next = n->insert(value);
                    return;
                }
            }
            else if(value > n->value && !n->next)
            {
                n->next = n->insert(value);
                return;
            }
        }
    }
}

void Set::del (int value) {
    for (Node* n = header->next; n; n->next = n->next) {
        if (n->next->value == value) {
            n->next = n->next->next;
            delete n;
            return;
        }
    }
}

ostream& operator << (ostream& os, const Set& b){
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

