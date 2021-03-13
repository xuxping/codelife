
#include <vector>
template<typename T>
class Queue
{
private:
    
public:
    Queue(/* args */);
    Queue(const Queue &) = delete;
    Queue & operator=(Queue &) = delete;
    ~Queue();
};

template<typename T> Queue<T>::Queue(/* args */)
{
}

template<typename T> Queue<T>::~Queue()
{
}
