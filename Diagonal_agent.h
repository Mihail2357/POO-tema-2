#ifndef DIAGONAL_AGENT_H
#define DIAGONAL_AGENT_H


#include "World.h"
#include "Cautator.h"



class Diagonal_agent :public Cautator
{
public:
    Diagonal_agent(const Position &p) : Cautator(p) {}
    string get_agent_type()const
    {
        return "D";
    }
    Position choose_new_position(const World& w) const;
};


#endif
