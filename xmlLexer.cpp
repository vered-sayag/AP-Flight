//
// Created by vered on 24/12/18.
//

#include "xmlLexer.h"
map<string, int> xmlLexer(string filename) {

    int index = 0;
    string s;
    smatch m;
    map <string, int> xml;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (getline(myfile, s)) {
            if (std::regex_search(s, m, regex ("<node>.*</node>"))) {
                s = m[0];
                s.erase(s.begin(), s.begin() + 6);
                s.erase(s.end() - 7, s.end());
                xml[s] = index++;
            }
        }
    }
    return xml;
}