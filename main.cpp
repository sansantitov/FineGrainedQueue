#include <iostream>
#include "queue.h"
#include <future>


using namespace std;

int main()
{
    Queue queue;

    //формируем последовательность  1 - 9
    for (int i = 1; i < 9; i++) {
        queue.insertIntoMiddle(i, 1000);
    }
    queue.show();


    int i = 0;

    while (i < 20) {


        std::future<void> insert1 = std::async(std::launch::async, &Queue::insertIntoMiddle, &queue, 2, 2);
        std::future<void> insert3 = std::async(std::launch::async, &Queue::insertIntoMiddle, &queue, 1000, 1000);
        std::future<void> insert2 = std::async(std::launch::async, &Queue::insertIntoMiddle, &queue, 1, 2);

        insert1.wait();
        insert2.wait();
        insert3.wait();
        queue.show();
        std::cout << endl;
        i++;

    }
    return 0;
}
