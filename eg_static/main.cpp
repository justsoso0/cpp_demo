
#include <iostream>

extern void msg();

int fun()
{
    static int count = 10; //在第一次进入这个函数的时候，变量a被初始化为10！并接着自减1，以后每次进入该函数，a
    return count--;        //就不会被再次初始化了，仅进行自减1的操作；在static发明前，要达到同样的功能，则只能使用全局变量：
}

class Text
{
public:
    static int fun()
    {
        //return num //错误，因为静态函数只能访问静态成员
        return count;
    }
    static int count;
    int num;
};

int Text::count = 0;

int count = 1;
char str2[10];

//类只能被实例一次的两种方式
class model_1
{
private:
    model_1()
    {
        std::cout << "构造" << std::endl;
        num = 10;
    }
    ~model_1()
    {
        std::cout << "析构" << std::endl;
    }
    int num;
    static model_1 locla_s;

public:
    static model_1 *getInstance()
    {
        return &locla_s;
    }
    void Print()
    {
        std::cout << num << std::endl;
    }
};
model_1 model_1::locla_s; //值得注意的地方

class model_2
{
private:
    static model_2 *local_instance;
    model_2()
    {
        std::cout << "构造" << std::endl;
    }
    ~model_2()
    {
        std::cout << "析构" << std::endl;
    }

public:
    static model_2 *getInstance()
    {
        if (local_instance == nullptr)
        {
            local_instance = new model_2();
            std::cout << "new 新空间" << std::endl;
        }
        else
        {
            std::cout << "空间不变" << std::endl;
        }
        return local_instance;
    }
    static void delete_local()
    {
        if (local_instance != nullptr)
            delete local_instance;
        else
        {
            std::cout << "空间已经删除" << std::endl;
        }
    }
};

model_2 *model_2::local_instance = nullptr; //值得注意的地方

int main()
{
    extern char a; // extern variable must be declared before use
    printf("%c ", a);
    // extern char b;
    // printf("%c ", b); //b被static隐藏，因此无法被全局编译
    (void)msg();
    printf("global\t\tlocal static\n");
    for (; count <= 10; ++count)
        printf("%d\t\t%d\n", count, fun());
    int c;
    static char str[10];
    char str3[10];
    printf("integer: %d; string: (begin)%s(end)\n", c++, str);
    printf("integer: %d; string: (begin)%s(end)\n", c++, str2);
    printf("integer: %d; string: (begin)%s(end)\n", c++, str3);

    Text t1;
    Text t2;

    t1.count = 100; //t1对象把static成员count改为100
    printf("t1.count: %d\n", t1.count);
    printf("t2.count: %d\n", t2.count);
    printf("Text.fun: %d\n", t1.fun());

    model_1 *m1 = model_1::getInstance();
    std::cout << m1 << std::endl;
    model_1 *m2 = model_1::getInstance();
    std::cout << m2 << std::endl;

    model_2 *m3 = model_2::getInstance();
    model_2 *m4 = model_2::getInstance();
    std::cout << m3 << std::endl;
    std::cout << m4 << std::endl;
    m3->delete_local();
    std::cout << m3 << std::endl;
    std::cout << m4 << std::endl;
    // model_2::delete_local(); //只能delete一次，

    return 0;
}