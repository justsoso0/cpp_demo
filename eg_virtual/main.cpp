
#include <iostream>
#include <string.h>

class virtu_base
{
public:
    // virtu_base();
    void func_own()
    {
        std::cout << "test msg:" << test_str.c_str() << std::endl;
    }
    virtual void func()
    {
        func_vir();
    }
    virtual void func_vir() = 0;
    std::string test_str;
};

class virtu_son1 : public virtu_base
{
    void func_vir()
    {
        std::cout << "virtual function son 1" << std::endl;
    }
    void func_son()
    {
        std::cout << "son 1 function" << std::endl;
    }
};

class virtu_son2 : public virtu_base
{
    void func_vir()
    {
        std::cout << "virtual function son 2" << std::endl;
    }
    void func_son()
    {
        std::cout << "son 2 function" << std::endl;
    }
};

int main()
{
    virtu_base *b = new virtu_son1();
    virtu_base *c = new virtu_son2();
    b->func();
    b->func_vir();
    c->func();
    c->func_vir();
    return 0;
}