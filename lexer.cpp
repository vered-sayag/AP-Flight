//
// Created by vered on 17/12/18.
//

#include "lexer.h"

vector<string> lexer(string filename) {

    list<string> oper = {"=", "+", "*", ",", "(", ")", "-", "/", "<", ">", "&", "|", "!", "}", "{"};
    list<string> output1;
    list<string> output2;
    std::smatch m;
    string s;
    vector<string> out;

    regex r("\\S+");
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (getline(myfile, s)) {
            // Search again and again
            while (std::regex_search(s, m, r)) {
                string s2 = m[0];
                output1.push_back(s2);

                // remove everything until after this match, and search again
                s = m.suffix().str();
            }// next match

            for (std::list<string>::iterator op = oper.begin(); op != oper.end(); ++op) {
                for (std::list<string>::iterator it = output1.begin(); it != output1.end(); ++it) {

                    if (!(regex_match((*it), regex("^.*[" + (*op) + "].*$"))) ||
                        (regex_match((*it), regex("^\".*\"$")))) {
                        output2.push_back((*it));
                        continue;
                    }
                    string s2 = (*it);
                    while (std::regex_search(s2, m, regex("[" + (*op) + "]")) &&
                           !(regex_match(s2, regex("^\".*\"$")))) {

                        if ((s2.substr(0, m.position(0))).compare("")) {
                            output2.push_back(s2.substr(0, m.position(0)));
                        }
                        output2.push_back((*op));
                        s2 = m.suffix().str();
                    }
                    if (s2.compare("")) {
                        output2.push_back(s2);
                    }
                }
                output1.clear();
                for (std::list<string>::iterator it = output2.begin(); it != output2.end(); ++it) {
                    output1.push_back((*it));
                }
                output2.clear();
            }

            for (std::list<string>::iterator it = output1.begin(); it != output1.end(); ++it) {
                out.push_back((*it));
            }
            output1.clear();
        }
    }
    myfile.close();
    return out;
}
