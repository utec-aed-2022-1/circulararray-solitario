#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
  public:
  StackArray();
  StackArray(int capacity);

  void push(T item);
  T pop();
  T top();
};

template <typename T>
void StackArray<T>::push(T item) {
  StackArray<T>::push_back(item);
}

template <typename T>
T StackArray<T>::pop() {
  return StackArray<T>::pop_back(); 
}
