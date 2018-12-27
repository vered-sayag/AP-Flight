
#include "TCPThread.h"

void* thread_Connect(void* arg){
    int sockfd;
    struct ConnectParams* params = (struct ConnectParams*) arg;


    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    params->data->addSocket(sockfd);

    int len = params->IP.size();
    char char_array[len + 1];
    strcpy(char_array, params->IP.c_str());
    server = gethostbyname(char_array);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(params->port);


    // connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (true){
        if (params->data->sendNotEmpty()){

            // parameters to send
            map <string, double> toSend = params->data->getSend();
            string path = params->data->getBind(toSend.begin()->first);
            double value = toSend.begin()->second;

            // creating the message
            string message = "set " + path+ " " + to_string(value) + "\r\n";

            ssize_t n;

            // Send message to the server
            n = write(sockfd, message.c_str(), message.length());

            if (n < 0) {
                break;
            }
        }
    }
    /* Now ask for a message from the user, this message
       * will be read by server
    */


    return nullptr;
}

vector <string> splitByComma(string str) {
   vector <string> output;
    regex r("[^,]+");
    std::smatch m;
    str= str.substr(0,str.size()-2);
    while (regex_search(str, m, r)) {
        string s2 = m[0];
        output.push_back(s2);

        // remove everything until after this match, and search again
        str = m.suffix().str();
    }
    return output;
}

void setInputSymbols(const string &line, DataBase *data) {
    vector <string> vecLine = splitByComma(line);
    map <string, string>::iterator it = data->getBindIter();
    for (it; it != data->getBindIterEnd() ; ++it) {
        if (data->isInXML(it->second)) {
            data->setSymbol(it->first, stod(vecLine[data->getXml(it->second)]));
        }
    }
}

void* thread_OpenDataserver(void* arg) {
    struct openDataServerParams* params = (struct openDataServerParams*) arg;

    int socketFd; // main socket fileDescriptor
    int newsockfd; // new socket fileDescriptor
    int clilen;

    struct sockaddr_in serv_addr, cli_addr;

    //creating socket object
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    //if creation faild
    if (socketFd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    params->data->addSocket(socketFd);

    //Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET; // tcp server
    serv_addr.sin_addr.s_addr = INADDR_ANY; //server ip (0.0.0.0 for all incoming connections)
    serv_addr.sin_port = htons(params->port); //init server port

    //bind the host address using bind() call
    if (bind(socketFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //if binding faild
        perror("ERROR on binding");
        exit(1);
    }


    //start listening for the clients using the main socket
    listen(socketFd,1);
    clilen = sizeof(cli_addr);


    //accept actual connection from the client
    newsockfd = accept(socketFd, (struct sockaddr*)&cli_addr, (socklen_t*)&clilen);



    params->data->addSocket(newsockfd);


    //if connections with the client failed
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }


    string dataStr;

    while(true)
    {
        char buf[1024];
        int numBytesRead = recv(newsockfd, buf, sizeof(buf), 0);


        if (numBytesRead > 0)
        {
            for (int i=0; i<numBytesRead; i++)
            {
                char c = buf[i];
                if (c == '\n')
                {
                    if (dataStr.length() > 0)
                    {
                        params->data->conect();
                        setInputSymbols(dataStr, params->data);
                        //this_thread::sleep_for(chrono::milliseconds(1000/params->NumToSec));
                        dataStr = "";
                    }
                }
                else dataStr += c;
            }
        }
        else
        {
            break;
        }
    }

    return nullptr;
}
