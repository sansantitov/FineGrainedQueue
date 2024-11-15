# FineGrainedQueue
Решение по заданию 29.7.1 (модуль "Многопоточное программирование. Проектирование многопоточных структур данных")

# Команда
Александр Титов

# Основные черты решения 

Реализацию метода insertIntoMiddle(int value, int pos) для списка мелкогранулярной блокировкой.

Структура списка:

struct Node\
{           \
  int value; \
  Node* next; \
  std::mutex* node_mutex; \
};                         

class FineGrainedQueue \
{                      \
  Node* head;          \
  std::mutex* queue_mutex; \
};                          

Функция должна вставить узел с переданным значением value в позицию pos.

Чтобы не переусложнять реализацию, предполагается следующее: \
   очередь не пустая;\
   вставляется элемент в середину или конец списка;\
   вставку в начало списка не нужно рассматривать;\
   если pos больше длины списка, то нужно вставить элемент в конец списка.
