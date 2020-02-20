//  Lab3_HPAir_Backtracking
//
//  Created by Monica Amezquita
//  Data Structures 211
//  Copyright © 2017 Monica Amezquita. All rights reserved.
//

/** ADT stack: Array-based implementation
 @file ArrayStack.h */

#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H

#include "StackInterface.h"
const int MAX_STACK = 50;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
    ItemType items[MAX_STACK];     // Array of stack items
    int            top;                                    // Index to top of stack
    
public:
    ArrayStack();                     // Default constructor
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
};  // end ArrayStack

#include "Stack.cpp"
#endif
