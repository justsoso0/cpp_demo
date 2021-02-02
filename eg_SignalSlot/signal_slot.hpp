#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <boost/signals2.hpp>

template <typename... Args>
class Slot_Base
{
public:
    virtual void emitSignal(Args...) = 0;
    virtual ~Slot_Base() {}
};

template <typename Tobject, typename... Args>
class Slot : public Slot_Base<Args...>
{
    typedef void (Tobject::*Tfunc)(Args...);

public:
    Slot(Tobject *pobject, Tfunc p)
    {
        m_pobject = pobject;
        m_pf = p;
    }

    void emitSignal(Args... a)
    {
        (m_pobject->*m_pf)(a...);
    }

private:
    Tobject *m_pobject;
    Tfunc m_pf;
};

template <typename... Args>
class MySignal
{
public:
    template <typename Tobject>
    void connect(Tobject *pclass, void (Tobject::*pFunc)(Args...))
    {
        connects_slot.push_back(new Slot<Tobject, Args...>(pclass, pFunc));
    }

    void operator()(Args... p)
    {
        for (int i = 0; i < connects_slot.size(); i++)
        {
            connects_slot[i]->emitSignal(p...);
        }
    }

private:
    std::vector<Slot_Base<Args...> *> connects_slot;
};
