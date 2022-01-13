#include <bits/stdc++.h>
using namespace std;

class Singleton
{
    private:
        string name;
        Singleton(const string name): name(name){}
        static Singleton* singleton_;
        // static mutex mutex_;
    public:
        static Singleton* getInstance(const string& name);
        void printName()
        {
            cout << name << endl;
        }
};

Singleton* Singleton::singleton_ = nullptr;
// mutex Singleton::mutex_;

Singleton* Singleton::getInstance(const string& name)
{
    // lock_guard<mutex> lock(mutex_);
    if(singleton_ == nullptr)
        singleton_ = new Singleton(name);
    return singleton_;
}

void foo()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* sing = Singleton::getInstance("Shubham");
    sing->printName();
}

void bar()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* sing = Singleton::getInstance("Yadav");
    sing->printName();
}

int main(void)
{
    // Singleton* sing = Singleton::getInstance("Shubham");
    // Singleton* sing2 = Singleton::getInstance("Yadav");
    // sing->printName();
    // sing2->printName();
    thread t1(foo);
    thread t2(bar);
    t1.join();
    t2.join();
    return 0;
}