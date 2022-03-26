#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>//PUSH BACK
void CircularArray<T>::push_back(T data) {  
  if(is_empty())
    front = back = 0;
  else
    back = next(back);
  
   array[back] = data;
}

template <class T>//POP FRONT 
T CircularArray<T>::pop_front() {
{
  int aux = array[front];
  for(int i=front;i<back;i++){
     array[i]=array[next(i)];   
  }
    array[back]=int (NULL);
    back= prev(back);
    return aux ;
}
template <class T>//IS _FULL    
bool CircularArray<T>::is_full() {
  return next(back) == front;
}
template <class T>//IS _EMPTY
bool CircularArray<T>::is_empty() {
  return (front == -1 && back == -1);
}


template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}
