#include <iostream>
#include <time.h>
#include<random>


using namespace std;

#include "Eye_agent.h"
#include "World.h"


Cautator::Position Eye_agent::choose_new_position(const World& w) const
{
    Position p(0,0);
    Position q(0,0);

    Position border1(position.row-3,position.column-3),border2(position.row+3,position.column+3);
    int n = w.get_number_of_rows();
    int m = w.get_number_of_cols();
    //fixam limitele arei vizuale a agentului
    bool ok = false;
    int i=border1.row,j;
    //cautam comoara in zona vizibila
    while(!ok && i<=border2.row)
    {
        j=border1.column;
        p.row = i;
        while(!ok && j<=border2.column)
        {
            p.column = j;
            if(p.row>=0 && p.row<n && p.column>=0 && p.column<m && !(p==position))
                if(w.get_agent(p.row,p.column)->get_agent_type()=="T")
                    ok=true;
            j++;
        }
        i++;
    }
    if(ok)
    {
        q=position;
        if(position.row>p.row)
            q.row=position.row-1;
        else if(position.row<p.row)
            q.row=position.row+1;            //ne apropiem de comoara cu cate o casuta pe coloana si una pe linie daca este nevoie

        if(position.column>p.column)
            q.column=position.column-1;
        else if(position.column<p.column)
            q.column=position.column+1;



        if(w.get_agent(q.row,q.column)->get_agent_type()=="G")
            if(w.get_agent(position.row,q.column)->get_agent_type()!="G")        //daca nu este liber ne apropiem doar pe linie sau doar pe coloana
                q.row=position.row;
            else if(w.get_agent(q.row,position.column)->get_agent_type()!="G")
                q.column=position.column;
            else
                ok=false;
    }                     //daca nu merge nici asa, incercam alfel

    if(!ok)
    {
        while(w.get_agent(q.row,q.column)->get_agent_type()=="G"|| i+j=0||q.row<0 || q.row>=n || q.column<0 || q.column>=m)
        {
            int X[3]= {0,-1,1};
            i= rand()%3;
            j= rand()%3;
            q.row = position.row+X[i];
            q.column = position.column+X[j];
        }
    }



    return q;
}
