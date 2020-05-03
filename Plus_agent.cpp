#include <iostream>
using namespace std;
#include<random>
#include <time.h>

#include "Plus_agent.h"
#include "World.h"

// agentul care merge sus, jos, stanga ,dreapta
Cautator::Position Plus_agent::choose_new_position(const World& w) const
{
    Position q(0,0);
    int n = w.get_number_of_rows();
    int m = w.get_number_of_cols();

    int X[2]= {1,-1};


    q=position;
    for(int i=0; i<=4; i++)
    {
        int j=rand()%2;
        q.row=position.row+X[j];
        if(q.row>=0 && q.row<n && q.column>=0 && q.column<m && (w.get_agent(q.row,q.column)->get_agent_type()=="T"||w.get_agent(q.row,q.column)))
        {

            return q;
        }
    }


    q=position;
    for(int i=0; i<=4; i++)
    {
        j=rand()%2;
        q.column=position.column+X[j];
        if(q.row>=0 && q.row<n && q.column>=0 && q.column<m && (w.get_agent(q.row,q.column)->get_agent_type()=="T"||w.get_agent(q.row,q.column)))
        {
            return q;
        }
    }

    for(int i=0; i<=1; i++)
        for(int j; j<=1; j++)
        {
            q.row=position.row+X[i];
            q.column=position.column+X[j];
            if(q.row>=0 && q.row<n && q.column>=0 && q.column<m &&(w.get_agent(q.row,q.column)->get_agent_type()=="T"||w.get_agent(q.row,q.column)))
            {

                return q;
            }
        }






}


