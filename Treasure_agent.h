#ifndef TREASURE_AGENT_H
#define TREASURE_AGENT_H

#include "World.h"
#include "Cautator.h"


class Treasure_agent :public Cautator {
public:
	Treasure_agent(const Position &p) : Cautator(p){}
	string get_agent_type()const{ return "T";}
};


#endif
