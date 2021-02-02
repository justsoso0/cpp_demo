#include <iostream>
#include <string>

using namespace std;

enum DATA_TYPE
{
    DATA_NULL = 0,
    DATA_CHAR,
    DATA_UINT,
    DATA_UINT8,
    DATA_UINT16,
    DATA_UINT32,
    DATA_INT,
    DATA_FLOAT,
    DATA_DOUBLE,
};

class data_value
{
public:
    data_value()
    {
        data_type = DATA_TYPE::DATA_INT;
    }
    data_value(int type)
    {
        data_type = type;
    }
    void change_type(int type)
    {
        data_type = type;
    }
    void operator=(uint8_t state_)
    {
        data_type = DATA_TYPE::DATA_UINT8;
        value_8 = state_;
    }
    void operator=(uint16_t state_)
    {
        data_type = DATA_TYPE::DATA_UINT16;
        value_16 = state_;
    }
    void operator=(uint32_t state_)
    {
        data_type = DATA_TYPE::DATA_UINT32;
        value_32 = state_;
    }
    void operator=(int state_)
    {
        data_type = DATA_TYPE::DATA_INT;
        value_i = state_;
    }
    void operator=(float state_)
    {
        data_type = DATA_TYPE::DATA_FLOAT;
        value_f = state_;
    }
    void operator=(double state_)
    {
        std::cout << "........" << std::endl;
        data_type = DATA_TYPE::DATA_DOUBLE;
        value_d = state_;
    }
    void value(uint8_t &value)
    {
        value = value_8;
    }
    void value(uint16_t &value)
    {
        value = value_16;
    }
    void value(uint32_t &value)
    {
        value = value_32;
    }
    void value(int &value)
    {
        value = value_i;
    }
    void value(float &value)
    {
        value = value_f;
    }
    void value(double &value)
    {
        value = value_d;
    }

private:
    uint8_t value_8;
    uint16_t value_16;
    uint32_t value_32;
    int value_i;
    float value_f;
    double value_d;
    int data_type;
};

int main()
{
    data_value data_0;
    data_value data_1(DATA_TYPE::DATA_FLOAT);
    data_0 = 10;
    float a = 10.254;
    data_1 = a;
    int v_a;
    data_0.value(v_a);
    float v_f, v_f2;
    data_1.value(v_f);
    data_value data_2 = data_1;
    data_2.value(v_f2);

    std::cout << "data_0 value:" << v_a << std::endl;
    std::cout << "data_1 value:" << v_f << std::endl;
    std::cout << "data_2 value:" << v_f2 << std::endl;
    double b = 1.24578454;
    data_0 = b;

    double v_d;
    data_0.value(v_d);
    std::cout << "data_0 value:" << v_d << std::endl;
    return 0;
}