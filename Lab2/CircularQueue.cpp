#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    items_ = new QueueItem[16];
    head_ = 0;
    tail_= 0;
    capacity_ = 16;
    size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
    items_ = new QueueItem(capacity);
    head_ = 0;
    tail_ = 0;
    capacity_ = capacity;
    size_ = 0;
}

CircularQueue::~CircularQueue()
{
    delete[] items_;
    items_ = NULL;
}

bool CircularQueue::empty() const
{
    if(size_ == 0)
        return true;
    return false;
}

bool CircularQueue::full() const
{
    if(size_ == capacity_)
        return true;
    return false;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if(!full())
    {
        items_[size_] = value;
        tail_ = size_;
        size_++;
        return true;
    }
    else return false;
}
QueueItem CircularQueue::dequeue()
{
    if(empty())
        return EMPTY_QUEUE;
    head_ ++;
    size_--;
    return items_[head_-1];
}

QueueItem CircularQueue::peek() const
{
    if(empty())
        return EMPTY_QUEUE;
    return items_[head_];
}

void CircularQueue::print() const
{
    if(empty())
        cout << "EMPTY QUEUE";
    for(int i = head_; i < tail_; i++)
        cout << items_[i] << endl;
}

