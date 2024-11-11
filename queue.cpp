#include "queue.h"
#include <iostream>
#include <thread>
#include <conio.h>



Queue::Queue() {
    //формируем _head со значением 0
    Node* newNode = new Node();
    newNode->_value = 0;
    newNode->_next = nullptr;
    _head = newNode;
    _size = 1;
}


void Queue::insertIntoMiddle(int value, int pos){

    /*
    Условие ТЗ:
    очередь не пустая,
    вставляется элемент в середину или конец списка, то есть вставку в начало списка не нужно рассматривать,
    если pos больше длины списка, то нужно вставить элемент в конец списка.
    */

    if (pos > _size) {
        _queue_mutex->lock();
        push_back(value);
        _queue_mutex->unlock();
        return;
    }

    Node* newNode = new Node();
    Node* prev;
    Node* cur;

    _queue_mutex->lock();
    prev = this->_head;

    newNode->_value = value;
    newNode->_next = nullptr;

    cur = _head;
    int cur_pos = 1;

    while (cur_pos < pos - 1) {
        prev = prev->_next;
        cur_pos++;
    }
    cur = prev->_next;
    prev->_node_mutex->lock();
    cur->_node_mutex->lock();
    _queue_mutex->unlock();
    prev->_next = newNode;
    newNode->_next = cur;
    prev->_node_mutex->unlock();
    cur->_node_mutex->unlock();
    _size++;
}
    
void Queue::push_back(int value){
    // создаем новый узел
    Node* node = new Node();
    node->_value = value;
    // в цикле ищем последний элемент списка
    Node* last = _head;
    while (last->_next != nullptr)
    {
        last = last->_next;
    }
    // Обновляем указатель next последнего узла на указатель на новый узел
    last->_next = node;
    _size++;
    return;
}

void Queue::show()
{

    Node* current = _head;
    while (current != nullptr)
    {
        std::cout << current->_value << std::endl;
        current = current->_next;
    }
    std::cout << std::endl;
}


