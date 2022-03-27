#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
  public:
  QueueArray();
  QueueArray(int capacity);

  void enqueue(T item);
  T dequeue();
    
};

template <typename T>
 void QueueArray<T>::enqueue(T item) {
  QueueArray<T>::push_back(item);
}

template <typename T>
 QueueArray<T>::QueueArray(int capacity) {
  this->array = new T[capacity];
  this->capacity = capacity;
  this->front = this->back = -1; 
  this->size = 0;
}

template <typename T>
T QueueArray<T>::dequeue() {
  return QueueArray<T>::pop_front(); 
}
