#ifndef RANDOM_AGENT_H
#define RANDOM_AGENT_H

#include "World.h"
#include "Cautator.h"



class Random_agent :public Cautator
{
public:
    Random_agent(const Position &p) : Cautator(p) {}
    string get_agent_type()const
    {
        return "R";
    }
    Position choose_new_position(const World& w) const;
};


#endif
