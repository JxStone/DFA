/**********************************************************************
*  DFA
**********************************************************************/

Course: COMP3040
Name:Jingxian Shi

m1_6b m1_6c m1_6f are defined machines from Homework #2 1.6 b, c, f
m1_6_in.txt is the sample input file that contains 3 ACCEPT and 3 NOT ACCEPT examples for the defined machines
m1_6_out.txt is the sample output file

DFA was pretty easy to implement using the map data structure for transition functions. Though I encountered a problem when trying to define a machine for the example provided. The symbol "." in the expression "a*.c" matches any character except a newline character. The alphabet however is not provided though. Since I match each character within the input string with the alphabet of the defined machine, does that mean I need to list all possible character in the machine definition?

Another problem I had was the flags (-h -d -v). I have not encountered these before and I had trouble separating the verbose output from the non-verbose output. I was hoping that I could get some tutorial on defining flags. In my code I just displayed all the definitions and transitions as input is processed.
