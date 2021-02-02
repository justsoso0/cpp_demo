
#include <iostream>

//const和define的区别：预编译指令只是对值进行简单的替换，不能进行类型检查

//优点：1、可以保护被修饰的东西，防止意外修改，增强程序的健壮性
//     2、编译器通常不为普通const常量分配存储空间，而是将它们保存在符号表中，这使得它成为一个编译期间的常量，没有了存储与读内存的操作，使得它的效率也很高。

//作为全局变量防止被修改
const int count = 10;

//作为函数参数和返回值使用
const char *test(const char *str, const int num)
{
    std::cout << "this num:" << num << " is can not change" << std::endl;

    char *temp = "it is temp";
    str = temp;
    return str;
}

int main()
{
    //不可修改常量
    // const int num_1 = 3;
    // int const num_2 = 3; //两种方式都表明定义的变量的值不能被修改
    // // num_1=20;num_2=10;  //错误
    // const char *str = "abcdef";
    // str[3] = 'q';//错误
    // int num = 3;
    // char buffer[num] = {'0', '1', '2'};
    // std::cout << "buffer size:" << sizeof(buffer) << std::endl; //size为3
    // std::cout << "buffer:" << buffer << std::endl;              //超出3个字符后还有数据输出：012U�
    // char buff[num_1] = {'0', '1', '2'};
    // std::cout << "buff:" << sizeof(buff) << std::endl; //size为3
    // std::cout << "buff:" << buff << std::endl;         //输出也是3个数据：012

    // //常量指针:不能通过这个指针改变变量的值，但是还是可以通过其他的引用来改变变量的值的;
    // int temp = 10;
    // int const *num = &temp;
    // // const int *num = &temp;//两种定义都可以
    // // *num = 20;//错误
    // std::cout << "num ptr:" << num << std::endl;
    // std::cout << "num:" << *num << std::endl;
    // temp = 20;
    // std::cout << "num ptr:" << num << std::endl;
    // std::cout << "num:" << *num << std::endl;
    // //常量指针:指向的值不能改变，但是这并不是意味着指针本身不能改变，常量指针可以指向其他的地址。
    // int other = 20;
    // num = &other;
    // std::cout << "num ptr:" << num << std::endl;
    // std::cout << "num:" << *num << std::endl;

    //指针常量:指针本身是个常量，不能在指向其他的地址,但是地址中保存的数值是可以改变的，可以通过其他指向该地址的指针来修改
    // int temp = 10;
    // int *const num = &temp;
    // int other = 30;
    // // num = &other;//错误
    // temp = 20;
    // std::cout << "num ptr:" << num << std::endl;
    // std::cout << "num:" << *num << std::endl;
    // int *other_num = &temp;
    // *other_num = 30;
    // std::cout << "num ptr:" << num << std::endl;
    // std::cout << "num:" << *num << std::endl;

    // //指向常量的常指针:指针指向的位置不能改变并且也不能通过这个指针改变变量的值，但是依然可以通过其他的普通指针改变变量的值
    // int temp = 10;
    // const int *const num = &temp;
    // // int const *const num = &temp;//两种定义都可以
    // std::cout << "num ptr:" << num << std::endl;
    // std::cout << "num:" << *num << std::endl;
    // int *other = &temp;
    // *other = 20;
    // std::cout << "num ptr:" << num << std::endl;
    // std::cout << "num:" << *num << std::endl;

    // //作为函数参数与返回值使用
    // const char *para_str = "it is a parament";
    // const int num = 10;
    // const char *ret_str = test(para_str, num);
    // std::cout << "ret_str:" << ret_str << std::endl;

    char *p1 = "abc";
    char *p2 = "abc";
    const char *p3 = "abc";
    const char *p4 = "abc";

    std::cout << "p1:" << &p1[0] << std::endl;
    std::cout << "p2:" << &p2[0] << std::endl;
    std::cout << "p3:" << &p3[0] << std::endl;
    std::cout << "p4:" << &p4[0] << std::endl;
    return 0;
}