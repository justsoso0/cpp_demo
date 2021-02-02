
#include <iostream>

void first_func(char *str_c)
{
    str_c[5] = 'x';
}
void func(char *str, const char *str_c)
{
    str[5] = {'a'};
    char *str_temp = (char *)str_c;
    first_func(str_temp);
    // str_c[5] = {'4'};  //错误，该值不可被修改
    std::cout << "function str:" << str << std::endl;
    std::cout << "function str_temp:" << str_temp << std::endl;
    std::cout << "function str_c:" << str_c << std::endl;
}

int main()
{
    const int num_1 = 5;
    int const num_2 = 50; //两种方式都表明定义的变量的值不能被修改

    // num_1=20;num_2=10;  //错误
    int num = 3;
    // char buffer[num] = {'0', '1', '2'}; //错误用法
    char buff[num_1] = {'0', '1', '2', '3', '4'};
    std::cout << "buff:" << buff << std::endl;

    const int *ptr_1;
    int const *ptr_2;
    int a = 5;
    int b = 10;
    ptr_1 = &a; //可以修改指针的值
    // *ptr_2 = b;  //不可修改指针所指向的值

    int *const ptr_3 = &a; //必须进行初始化
    int c = 6;
    // ptr_3 = &b;  //错误，不可以修改指针的值
    *ptr_3 = c; //正确，可以修改指针所值向的值

    char str[5] = {'0', '1', '2', '3', '4'};
    char str_c[5] = {'0', '1', '2', '3', '4'};
    func(str, str_c);
    return 0;
}