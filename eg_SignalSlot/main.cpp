#include "sign.hpp"
#include "slot.hpp"

int main()
{
    signal *signal_t = new signal();
    slot *slot_t = new slot();
    signal_t->signal_1.connect(slot_t, &slot::play_slot_1);
    signal_t->signal_1.connect(slot_t, &slot::play_slot_2);

    signal_t->signal_2.connect(slot_t, &slot::play_slot_3);
    signal_t->signal_3.connect(slot_t, &slot::play_slot_3);

    signal_t->emit_signal();
    return 0;
}