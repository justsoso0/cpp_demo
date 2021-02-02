#pragma once
#include "signal_slot.hpp"

class slot
{
public:
    void play_slot_1(int index, std::string context)
    {
        std::cout << "slot_1:" << std::endl;
        std::cout << "index:" << index << ",context:" << context.c_str() << std::endl;
    }
    void play_slot_2(int index, std::string context)
    {
        std::cout << "slot_2:" << std::endl;
        std::cout << "index:" << index << ",context:" << context.c_str() << std::endl;
    }
    void play_slot_3(int index, std::string context)
    {
        std::cout << "slot_3:" << std::endl;
        std::cout << "index:" << index << ",context:" << context.c_str() << std::endl;
    }
};