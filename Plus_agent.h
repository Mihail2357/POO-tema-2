#ifndef PLUS_AGENT_H
#define PLUS_AGENT_H


#include "World.h"
#include "Cautator.h"



class Plus_agent :public Cautator
{
public:
    Plus_agent(const Position &p) : Cautator(p) {}
    string get_agent_type()const
    {
        return "P";
    }
    Position choose_new_position(const World& w) const;
};


#endif
