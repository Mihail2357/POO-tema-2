#ifndef EYE_AGENT_H
#define EYE_AGENT_H


#include "World.h"
#include "Cautator.h"


class Eye_agent :public Cautator
{
public:
    Eye_agent(const Position &p) : Cautator(p) {}
    string get_agent_type()const
    {
        return "E";
    }
    Position choose_new_position(const World& w) const;
};


#endif
