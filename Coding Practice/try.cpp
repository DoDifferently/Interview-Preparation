#include <bits/stdc++.h>
using namespace std;

template <typename T>
class customizeStack
{
    vector<T> arr;
    std::mutex mtx;
    public:
        customizeStack()
        {

        }
        ~customizeStack()
        {

        }
        customizeStack(int siz)
        {
            arr.reserve(siz);
        }
        customizeStack(const customizeStack& other)
        {
            arr(other);
        }
        void insertAtEnd(T val)
        {
            mtx.lock();
            arr.push_back(val);
            mtx.unlock();
        }

        T& operator[](const int index)
        {
            return arr[index];
        }

        T popBack()
        {
            mtx.lock();
            int tmp = arr[arr.size()-1];
            arr.pop_back();
            mtx.unlock();
            return tmp;
        }

        bool bIsEmpty()
        {
            return arr.size() == 0;
        }
};

void func1(customizeStack<int>& stk)
{
    for(int i = 20; i < 40; ++i)
        stk.insertAtEnd(i);
}

void func2(customizeStack<int>& stk)
{
    for(int i = 70; i < 90; ++i)
        stk.insertAtEnd(i);
}

void func3(customizeStack<int>& stk)
{
    for(int i = 20; i < 40; ++i)
        cout << stk.popBack() << endl;
}

int main(void)
{
    customizeStack<int> stk;
    thread thread1(func1, std::ref(stk));
    thread thread2(func2, std::ref(stk));
    thread thread3(func3, std::ref(stk));

    thread1.join();
    thread2.join();
    thread3.join();
    return 0;
}