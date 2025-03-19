#include <iostream>
#include <vector>
#include <string>
using namespace std;

void eliminateLeftRecursion(string nonTerminal, vector<string> productions) {
    vector<string> alpha, beta;
    string newNonTerminal = nonTerminal + "'";
    
    for (string prod : productions) {
        if (prod[0] == nonTerminal[0]) {
            alpha.push_back(prod.substr(1)); 
        } else {
            beta.push_back(prod);
        }
    }
    
    if (!alpha.empty()) {
        cout << nonTerminal << " -> ";
        for (size_t i = 0; i < beta.size(); i++) {
            cout << beta[i] << newNonTerminal;
            if (i != beta.size() - 1) cout << " | ";
        }
        cout << endl;
        
        cout << newNonTerminal << " -> ";
        for (size_t i = 0; i < alpha.size(); i++) {
            cout << alpha[i] << newNonTerminal << " | ";
        }
        cout << "ε" << endl;
    } else {
        cout << nonTerminal << " -> ";
        for (size_t i = 0; i < productions.size(); i++) {
            cout << productions[i];
            if (i != productions.size() - 1) cout << " | ";
        }
        cout << endl;
    }
}

int main() {
    string nonTerminal = "A";
    vector<string> productions = {"Aa", "b", "Ac"};
    
    cout << "Original Grammar:" << endl;
    cout << nonTerminal << " -> ";
    for (size_t i = 0; i < productions.size(); i++) {
        cout << productions[i];
        if (i != productions.size() - 1) cout << " | ";
    }
    cout << endl << endl;
    
    cout << "Grammar after eliminating left recursion:" << endl;
    eliminateLeftRecursion(nonTerminal, productions);
    
    return 0;
}
