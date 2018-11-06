//
//  DFA.cpp
//  DFA
//
//  Created by Jingxian Shi on 10/23/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#include "DFA.hpp"
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

DFA::DFA()
{
    
}

DFA::~DFA()
{
    
}

void DFA::addState(string state)
{
    states.push_back(state);
}

void DFA::addAlphabet(string alphabet)
{
    alphabets.push_back(alphabet);
}

void DFA::addTransition(string src, string alphabet, string destination)
{
    pair<string, string> temp(src, alphabet);
    
    transition.insert(make_pair(temp, destination));
}

void DFA::setCurrentState(string state)
{
    current_state = state;
}

string DFA::getCurrentState()
{
    return current_state;
}

void DFA::setStartState(string state)
{
    start_state = state;
}

void DFA::addAcceptedState(string state)
{
    accept_states.push_back(state);
}

void DFA::reset()
{
    current_state = start_state;
}

void DFA::display()
{
    cout << "---BEGIN DFA definition---" << endl;
    
    cout << "States: " << endl;
    for(int i = 0; i < states.size(); i++)
        cout << states[i] << " ";
    cout << endl;
    
    cout << "Alphabets: " << endl;
    for(int i = 0; i < alphabets.size(); i++)
        cout << alphabets[i] << " ";
    cout << endl;
    
    cout << "Transition Functions: " << endl;
    for(map<pair<string, string>, string>::iterator p = transition.begin(); p != transition.end(); p++)
    {
        cout << p->first.first << " " << p->first.second << " " << p->second << endl;
    }
    
    cout << "Start State: " << endl;
    cout << start_state << endl;
    
    cout << "Accepted States: " << endl;
    for(int i = 0; i < accept_states.size(); i++)
        cout << accept_states[i] << " ";
    cout << endl;
    
    cout << "---END DFA definition---" << endl;
}

bool DFA::isValid(string alphabet)
{
    return (find(alphabets.begin(), alphabets.end(), alphabet) != alphabets.end());
}

bool DFA::isAcceptedState(string state)
{
    return (find(accept_states.begin(), accept_states.end(), state) != accept_states.end());
}

void DFA::nextState(string alphabet)
{
    pair<string, string> temp;
    
    temp = make_pair(current_state, alphabet);
    
    map<pair<string, string>, string>::iterator p = transition.find(temp);
    
    current_state = p->second;
}
