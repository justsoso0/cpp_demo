#include <iostream>
#include <array>

int main()
{

    std::array<char, 100> arr{"http://c.biancheng.net/stl"};

    std::cout << "array:" << &arr[0] << std::endl;

    std::array<char, 100> arr_data;
    arr_data[0] = 0;
    arr_data[1] = 1;
    arr_data[2] = 2;
    arr_data[3] = 3;
    arr_data[4] = 4;
    char num = arr_data[0];
    std::cout << "data:" << std::to_string(num) << std::endl;
    const int len = 10;
    std::array<char, len> arr_other;
}