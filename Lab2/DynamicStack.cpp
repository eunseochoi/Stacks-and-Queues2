#include "DynamicStack.hpp"
#include <iostream>
using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    items_ = new StackItem[16];
    capacity_ = 16;
    size_ = 0;
    init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    size_ = 0;
    
    if(capacity == 0)
    {
        items_ = new StackItem[16];
        capacity_ = 16;
        init_capacity_ = 16;
    }
        
    else
    {
        items_ = new StackItem[capacity];
        capacity_ = capacity;
        init_capacity_ = capacity;
    }
}

DynamicStack::~DynamicStack()
{
    delete[] items_;
    items_ = NULL;
}

bool DynamicStack::empty() const
{
    if (size_ == 0)
        return true;
    return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if(size_ < capacity_)
    {
        items_[size_] = value;
        size_++;
    }
    else
    {
        StackItem* copy = new StackItem[capacity_*2];
        
        for(int i = 0; i <= capacity_; i++)
            copy[i] = items_[i];
        
        copy[capacity_] = value;
        delete [] items_;
        items_ = copy;
        size_++;
    }
}

StackItem DynamicStack::pop()
{
    if(empty())
        return EMPTY_STACK;
    StackItem topOfStack = items_[size_ - 1];
    size_--;
    if(size_ <= capacity_/4)
    {
        int newCapacity = capacity_ / 2;
        if(newCapacity >= init_capacity_)
        {
            StackItem* copy = new StackItem[newCapacity];
            
            for(int index = 0; index < size_; index++)
                copy[index] = items_[index];
            
            delete [] items_;
            items_ = copy;
        }
    }
    return topOfStack;
}

StackItem DynamicStack::peek() const
{
    if(empty())
        return EMPTY_STACK;
    return items_[size_-1];
}

void DynamicStack::print() const
{
    for(int i = 0; i < size_; i++)
        cout << items_[i] << endl;
}
