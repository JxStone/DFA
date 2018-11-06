//
//  DFA.hpp
//  DFA
//
//  Created by Jingxian Shi on 10/23/18.
//  Copyright © 2018 Jingxian Shi. All rights reserved.
//

#ifndef DFA_hpp
#define DFA_hpp

#include <stdio.h>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

class DFA {
public:
    DFA();
    ~DFA();
    void addState(string state);
    void addAlphabet(string alphabet);
    void addTransition(string src, string alphabet, string destination);
    void setCurrentState(string state);
    string getCurrentState();
    void setStartState(string state);
    void addAcceptedState(string state);
    void nextState(string alphabet);
    void reset();
    void display();
    bool isValid(string alphabet);
    bool isAcceptedState(string state);
    
private:
    vector<string> states;
    vector<string> alphabets;
    map<pair<string, string>, string> transition;
    string start_state;
    string current_state;
    vector<string> accept_states;
};

#endif /* DFA_hpp */
