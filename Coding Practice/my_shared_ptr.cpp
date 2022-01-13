typedef unsigned int uint;

template<typename T>
class my_shared_ptr
{
    T* ptr;
    uint* ref_cnt;
    public:
        my_shared_ptr(): ptr(nullptr), ref_cnt(new uint()){}
        my_shared_ptr(const my_shared_ptr& obj)
        {
            this->ptr = obj.ptr;
            this->ref_cnt = obj.ref_cnt;
            if(obj.ref_cnt != nullptr)
            {
                (*this-ref_cnt)++;
            }
        }
        my_shared_ptr& operator=(const my_shared_ptr& obj)
        {
            this->ptr = obj.ptr;
            this->ref_cnt = obj.ref_cnt;
            if(obj.ref_cnt != nullptr)
            {
                (*this-ref_cnt)++;
            }
        }

        my_shared_ptr(my_shared_ptr&& obj)
        {
            this->ptr = obj.ptr;
            this->ref_cnt = obj.ref_cnt;
            obj.ptr = nullptr;
            obj.ref_cnt = nullptr;
        }
        my_shared_ptr& operator=(my_shared_ptr&& obj)
        {
            __cleanUp__();

            this->ptr = obj.ptr;
            this->ref_cnt = obj.ref_cnt;
            obj.ptr = nullptr;
            obj.ref_cnt = nullptr;
        }

        uint get_count() const
        {
            return *refCount; // *this->refCount
        }
        
        T* operator->(void)
        {
            return this->ptr;
        }

        T& operator*(void)
        {
            return this->ptr;
        }
        
        ~my_shared_ptr() // destructor
        {
            __cleanup__();
        }

    private:
        void __cleanup__()
        {
            (*refCount)--;
            if (*refCount == 0)
            {
                if (nullptr != ptr)
                    delete ptr;
                delete refCount;
            }
        }
}