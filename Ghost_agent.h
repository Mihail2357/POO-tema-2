#ifndef GHOST_AGENT_H
#define GHOST_AGENT_H


#include "World.h"
#include "Cautator.h"
//agentul care marcheaza ca o casuta a fost explorata

class Ghost_agent :public Cautator
{
public:
    Ghost_agent(const Position &p) : Cautator(p) {}
    string get_agent_type()const
    {
        return "G";
    }
};


#endif
