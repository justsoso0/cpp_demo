#include <iostream>
#include <string>
#include <vector>

//auto的自动类型推断发生在编译期，所以使用auto并不会造成程序运行时效率的降低,编译的时候，就会把auto变量转换为相应的变量类型。

//注1：auto声明的变量必须要初始化，否则编译器不能判断变量的类型。
//注2：auto不能被声明为返回值，auto不能作为形参，auto不能被修饰为模板参数

int main()
{
    // 数据类型的赋值
    // double a = 10;
    // auto b = a;
    // std::cout << "b'type:" << typeid(b).name() << std::endl
    //           << "b'value:" << b << std::endl;
    // int c;
    // auto d = c;
    // std::cout << "d'type:" << typeid(d).name() << std::endl
    //           << "d'value:" << d << std::endl;

    //----------------------//
    // int a = 10;
    // auto b = a;
    // auto c = b;
    // std::cout << "b'type:" << typeid(b).name() << std::endl
    //           << "b'value:" << b << std::endl;
    // std::cout << "c'type:" << typeid(c).name() << std::endl
    //           << "c'value:" << c << std::endl;

    //auto代替复杂的数据类型
    // std::vector<int> a_v;
    // int i;
    // for (i = 0; i < 10; i++)
    //     a_v.push_back(i);
    // std::cout << "a_temp:";
    // for (auto a_temp = a_v.begin(); a_temp != a_v.end(); a_temp++)
    //     std::cout << "num:" << *a_temp << ",address:" << &a_temp << ",a_v address:" << a_temp.base() << std::endl;

    //decltype和auto的配合使用
    // int a = 10;
    // auto b = a;
    // decltype(b) c = a;
    // std::cout << "b'type:" << typeid(b).name() << std::endl
    //           << "b'value:" << b << std::endl;
    // std::cout << "c'type:" << typeid(c).name() << std::endl
    //           << "c'value:" << c << std::endl;

    //auto自动推导类型时的规则
    //如果初始化表达式是引用，则去除引用语义。
    // int a = 10;
    // int &b = a;
    // auto c = b; //这里的auto代表int
    // auto &d = b;
    // c = 20;
    // std::cout << "a'type:" << typeid(a).name() << std::endl
    //           << "a'value:" << a << std::endl;
    // std::cout << "b'type:" << typeid(b).name() << std::endl
    //           << "b'value:" << b << std::endl;
    // std::cout << "c'type:" << typeid(c).name() << std::endl
    //           << "c'value:" << c << std::endl;
    // d = 30;
    // std::cout << "a'type:" << typeid(a).name() << std::endl
    //           << "a'value:" << a << std::endl;
    // std::cout << "b'type:" << typeid(b).name() << std::endl
    //           << "b'value:" << b << std::endl;
    // std::cout << "d'type:" << typeid(d).name() << std::endl
    //           << "d'value:" << d << std::endl;

    //如果初始化表达式为const或volatile（或者两者兼有），则除去const/volatile语义
    // const int a = 10;
    // auto b = a;       //b的类型为int而非const int（去除const）
    // const auto c = a; //此时c的类型为const int
    // b = 100;          //合法
    // // c1 = 100;          //非法,无法修改

    //如果auto关键字带上&号，则不去除const语意。
    // const int a = 10;
    // auto &b = a; //b的类型为const int
    // b = 100;     //非法,无法修改

    //初始化表达式为数组时，auto关键字推导类型为指针。
    // int a[3] = {1, 2, 3};
    // auto b = a;
    // std::cout << "b'type:" << typeid(b).name() << std::endl
    //           << "b'value:" << b << std::endl;
    // std::cout << "b[0]'type:" << typeid(b[0]).name() << std::endl
    //           << "b[0]'value:" << b[0] << std::endl;
    // //若表达式为数组且auto带上&，则推导类型为数组类型。
    // auto &c = a;
    // std::cout << "c'type:" << typeid(c).name() << std::endl
    //           << "c'value:" << c << std::endl;
    // std::cout << "c'type:" << typeid(c[0]).name() << std::endl
    //           << "c'value:" << c[0] << std::endl;

    //易错写法
    // auto a = 10, b = 20, c = 30; //正确，数据类型统一，都是int型
    // // auto a = 10, b = 20, c = 30.24;//错误，变量数据类型不统一
    // std::cout << "a'type:" << typeid(a).name() << std::endl
    //           << "a'value:" << a << std::endl;
    // std::cout << "b'type:" << typeid(b).name() << std::endl
    //           << "b'value:" << b << std::endl;
    // std::cout << "c'type:" << typeid(c).name() << std::endl
    //           << "c'value:" << c << std::endl;

    // std::cout << sizeof(auto) << std::endl;        //错误
    // std::cout << typeid(auto).name() << std::endl; //错误

    return 0;
}