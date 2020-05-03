#include <iostream>
using namespace std;
#include<random>
#include <time.h>

#include "Diagonal_agent.h"
#include "World.h"


Cautator::Position Diagonal_agent::choose_new_position(const World& w) const
{
    Position q(0,0);
    int n = w.get_number_of_rows();
    int m = w.get_number_of_cols();
    int X[2]= {1,-1};
    for(int y=0; y<=12; y++)
    {
        int i=rand()%2;
        int j=rand()%2;
        q.row=position.row+X[i];
        q.column=position.column+X[j];
        if(q.row>=0 && q.row<n && q.column>=0 && q.column<m && (w.get_agent(q.row,q.column)->get_agent_type()=="T"||w.get_agent(q.row,q.column)))
        {
            return q;    //inercam sa il facem sa mearga pe diagonala
        }
    }



    q=position;
    for(int i=0; i<=1; i++)
    {
        q.row=position.row+X[i];
        if(q.row>=0 && q.row<n && q.column>=0 && q.column<m &&(w.get_agent(q.row,q.column)->get_agent_type()=="T"||w.get_agent(q.row,q.column)))
        {

            return q;  // daca nu merge pe diagonala incercam stanga, dreapta, jos, sus;
        }
    }



    q=position;
    for(int i=0; i<=1; i++)
    {
        q.column=position.column+X[i];
        if(q.row>=0 && q.row<n && q.column>=0 && q.column<m && (w.get_agent(q.row,q.column)->get_agent_type()=="T"||w.get_agent(q.row,q.column)))
        {

            return q;
        }
    }

}

