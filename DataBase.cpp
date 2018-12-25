//
// Created by vered on 21/12/18.
//

#include "DataBase.h"
#include "equalBindCommand.h"
#include "equalCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ODSCommand.h"
#include "connectCommand.h"
#include "VarCommand.h"
#include "sleepCommand.h"
#include "printCommand.h"

void DataBase::helpSetSymbol(const string &key, double value) {

    symbols[key] = value;
    for (map<string, vector<string>>::iterator it = bindsVar.begin(); it != bindsVar.end(); ++it) {
        if (!key.compare(it->first)) {
            for (int i = 0; i < it->second.size(); i++) {
                string sec = it->second[i];
                it->second[i] = "";
                if (isSymbol(sec)) {
                    helpSetSymbol(sec, value);
                }
                it->second[i] = sec;
            }
        }
    }
}

void DataBase::closeSockets() {
    for (int i = sockets.size(); i > 0; --i) {
        close(sockets[i]);
        sockets.pop_back();
    }
}

void DataBase::createCommands() {
    commands["="] = new equalCommand(this);
    commands["bind"] = new equalBindCommand(this);
    commands["while"] = new WhileCommand(this);
    commands["if"] = new IfCommand(this);
    commands["openDataServer"] = new ODSCommand(this);
    commands["connect"] = new ConnectCommand(this);
    commands["var"] = new VarCommand(this);
    commands["sleep"] = new sleepCommand(this);
    commands["print"] = new printCommand(this);
}

bool DataBase::isInXML(const string &str) {
    map<string, int>::iterator it = xmlSymbol.find(str);
    if (it != xmlSymbol.end()) {
        return true;
    }
    return false;
}


bool DataBase::isCommand(const string &sym) {
    map<string, Command *>::iterator it = commands.find(sym);
    if (it != commands.end()) {
        return true;
    }
    return false;
}


bool DataBase::isSymbol(const string &sym) {
    map<string, double>::iterator it = symbols.find(sym);
    if (it != symbols.end()) {
        return true;
    }
    return false;
}

bool DataBase::isBind(const string &sym) {
    map<string, string>::iterator it = binds.find(sym);
    if (it != binds.end()) {
        return true;
    }
    return false;
}

bool DataBase::isBindVar(const string &sym) {
    map<string, vector<string> >::iterator it = bindsVar.find(sym);
    if (it != bindsVar.end()) {
        return true;
    }
    return false;
}


map<string, double> DataBase::getSend() {
    map<string, double> temp;
    temp[send.begin()->first] = send.begin()->second;
    send.erase(send.begin());
    return temp;
}

void DataBase::addBindVar(const string &left, const string &right) {

    if (isBindVar(left)) {
        bindsVar[left].push_back(right);
    } else {
        vector<string> temp = {right};
        bindsVar[left] = temp;
    }
    if (isBindVar(right)) {
        bindsVar[right].push_back(left);
    } else {
        vector<string> temp = {left};
        bindsVar[right] = temp;
    }

    setSymbol(left, getSymbolValue(right));
}

