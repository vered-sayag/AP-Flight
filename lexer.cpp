
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

            //TODO - strings
            int i,j,k;
            int sum =0;
            for (i = 0; i < s.length(); i++) {
                if (s[i] == '\"')sum++;
            }

            if (sum % 2 != 0) {
                throw invalid_argument("Bad quotation marks!");
            }

            for (i = 0; i < s.length(); i++) {
                if (s[i] != ' ')break;
            }
            for ( k = i; i < s.length(); ) {
                if (s[i] == '\"') {
                    if (i != k) {
                        output2.push_back(s.substr(k, i - k));
                        k = i;
                    }

                    i++;
                    while (s[i] != '\"') {
                        i++;
                    }
                    output2.push_back(s.substr(k, i + 1 - k));
                    i++;
                    k = i;

                }else {
                   i++;
                }
            }
            if (k!=i){
                output2.push_back(s.substr(k,i-k));
            }
            //end

            // Search again and again
            for (std::list<string>::iterator it = output2.begin(); it != output2.end(); ++it) {
                string s1 = (*it);

                if ((regex_match((*it), regex("^\".*\"$")))) {
                    output1.push_back((*it));
                    continue;
                }
                while (std::regex_search(s1, m, r)) {

                    string s2 = m[0];
                    output1.push_back(s2);

                    // remove everything until after this match, and search again
                    s1 = m.suffix().str();
                }// next match
            }
            output2.clear();

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
    } else {
        throw invalid_argument("cant open file " + filename);
    }
    myfile.close();
    return out;
}
