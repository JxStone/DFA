//
//  main.cpp
//  DFA
//
//  Created by Jingxian Shi on 10/15/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <fstream>
#include "DFA.hpp"

using namespace std;

void init(DFA& dfa, ifstream& fin)
{
    string state;
    string alphabet;
    string src;
    string destination;
    string start_state;
    string accepted_state;
    
    fin >> state >> state;
    
    while(state.find("Alphabets") == string::npos)
    {
        dfa.addState(state);
        fin >> state;
    }
    
    fin >> alphabet;
    
    while(alphabet.find("Transitions") == string::npos)
    {
        dfa.addAlphabet(alphabet);
        fin >> alphabet;
    }
    
    fin >> src;
    
    while(src.find("Start") == string::npos)
    {
        fin >> alphabet >> destination >> ws;
        dfa.addTransition(src, alphabet, destination);
        fin >> src;
    }
    
    fin >> start_state;
    dfa.setStartState(start_state);
    
    fin >> accepted_state >> accepted_state;
    
    while(!fin.eof())
    {
        dfa.addAcceptedState(accepted_state);
        fin >> accepted_state;
    }
}

int main(int argc, const char * argv[])
{
    DFA dfa;
    string currentState;
    string c;
    string inputString;
    ifstream fin;
    bool failed = false;
    
    fin.open(argv[1]);
    
    if(fin.fail())
    {
        cout << "Failed to open input file" << endl;
        exit(1);
    }
    else
    {
        init(dfa, fin);
        dfa.display();
        
        while(getline(cin, inputString))
        {
            dfa.reset();
            
            failed = false;

            currentState = dfa.getCurrentState();
            
            for(int i = 0; i < inputString.length(); i++)
            {
                c = inputString[i];
                if(dfa.isValid(c))
                {
                    currentState = dfa.getCurrentState();
                    cout << "Current State: " << currentState;
                    cout << " Symbol: " << c << " -> ";
                    dfa.nextState(c);
                    
                    currentState = dfa.getCurrentState();
                    cout << "New State: " << currentState << endl;
                }
                else
                {
                    cout << "Invalid alphabet: " << c << endl;
                    failed = true;
                    break;
                }
            }
            
            if(!failed)
            {
                if(dfa.isAcceptedState(currentState))
                    cout << inputString << " --> ACCEPTED" << endl;
                else
                    cout << inputString << " --> NOT ACCEPTED" << endl;
            }
            else
                cout << inputString << " --> NOT ACCEPTED" << endl;
        }
        
    }
    
    return 0;
}
