

#ifndef AP3_DATABASE_H
#define AP3_DATABASE_H

#define XML_FILE_NAME "../generic_small.xml"

#include <string>
#include <map>
#include <vector>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>
#include <regex>
#include "xmlLexer.h"
#include "Command.h"
#include <list>
using namespace std;

class DataBase {
    map<string, Command *> commands;
    map<string, string> binds;
    map<string, double> symbols;
    list<map<string, double>> send;
    map<string, int> xmlSymbol;
    map<string, vector<string>> bindsVar;
    vector<int> sockets;
    pthread_mutex_t mutex;
    volatile bool conectOpenDataServer = false;

    void createCommands();

    void helpSetSymbol(const string &key, double value);

    void closeSockets();

public:
    DataBase() {
        createCommands();
        xmlSymbol = xmlLexer(XML_FILE_NAME);
        pthread_mutex_init(&mutex, nullptr);
    }

    void conect(){
        conectOpenDataServer = true;
    }

    bool isConect(){
        return conectOpenDataServer;
    }
    bool isInXML(const string &str);

    int getXml(const string &key) { return xmlSymbol[key]; }

    void addSocket(int sock) { sockets.push_back(sock); }

    bool isCommand(const string &sym);

    double getSymbolValue(const string &key) { return symbols[key]; }

    Command *getCommand(const string &key) { return commands[key]; }

    void addSymbol(const string &key, double value) { symbols[key] = value; }

    bool isSymbol(const string &sym);

    bool isBind(const string &sym);

    bool isBindVar(const string &sym);

    void setSymbol(const string &key, double value) {
        pthread_mutex_lock(&mutex);
        helpSetSymbol(key, value);
        pthread_mutex_unlock(&mutex);
    }

    void addBind(const string &key, const string &value) { binds[key] = value; }

    string getBind(const string &key) { return binds[key]; }

    map<string, string>::iterator getBindIter() { return binds.begin(); }

    map<string, string>::iterator getBindIterEnd() { return binds.end(); }

    void pushSend(const string &key, double value) {
        map<string,double > temp;
        temp[key] = value;
        send.push_back(temp);
    }

    map<string, double> getSend();

    void addBindVar(const string &left, const string &right);

    vector<string> getBindVars(string var) { return bindsVar[var]; }

    bool sendNotEmpty() { return !send.empty(); }

    ~DataBase() {
	closeSockets();       
	for (map<string, Command *>::iterator it = commands.begin(); it != commands.end(); ++it) {
            delete (it->second);
        }
        pthread_mutex_destroy(&mutex);
    }
};

#endif //AP3_DATABASE_H
