#pragma once
#include "signal_slot.hpp"

class signal
{
public:
    void emit_signal()
    {
        std::string p = "this is a signal";

        signal_1(1, p);

        signal_2(2, p);

        signal_3(3, p);
    }

public:
    MySignal<int, std::string> signal_1;
    MySignal<int, std::string> signal_2;
    MySignal<int, std::string> signal_3;
};