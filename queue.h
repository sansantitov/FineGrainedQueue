#pragma once
#include <mutex>



struct Node
{
    int _value;
    Node* _next;
    //std::mutex* _node_mutex;
    std::mutex* _node_mutex = new std::mutex;
};


class Queue
{
public:
    Queue();
    void insertIntoMiddle(int value, int pos);
    void push_back(int value);
    //int size();
    void show();
private:
    Node* _head;
    //Node* _end;
    //std::mutex* _queue_mutex;
    std::mutex* _queue_mutex = new std::mutex;
    int _size;
};


