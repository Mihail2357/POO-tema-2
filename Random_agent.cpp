#include <iostream>
using namespace std;
#include<random>
#include <time.h>

#include "Random_agent.h"
#include "World.h"


Cautator::Position Random_agent::choose_new_position(const World& w) const
{
    Position q(0,0);
    int i=0,j=0;
    bool ok=false;
    while(!ok)
    {
        int X[3]= {0,-1,1};
        i= rand()%3;
        j= rand()%3;
        q.row = position.row+X[i];
        q.column = position.column+X[j];

        if(q.row>=0 && q.row<n && q.column>=0 && q.column<m && (w.get_agent(q.row,q.column)->get_agent_type()=="T"||w.get_agent(q.row,q.column)))
        {
            return q;
            bool=true;
        }
    }
