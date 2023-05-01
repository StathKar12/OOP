#include <iostream>
#include <ctime>

using namespace std;

const int GLOBAL_F_SIZE = 3;
const int GLOBAL_T_SIZE = 3;

string createTXT(string="Text");

class post{
    int    id       ;
    string Title    ;
    string creator  ;
    string Text     ;
    tm*    CreationD;
public:
    post() ;
    ~post();
    void printPost()      ;
    string get_Text()     ;
    int get_ID()          ;
};

class thread{
    string subject  ;
    string creator  ;
    tm* CreationD   ;
    post*  Posts    ;
public:
    thread() ;
    ~thread();
    void printThread()  ;
    int printPost(int)  ;
    string get_subject();
    void set_subject(string);
};

class forum{
    string  Title  ;
    thread*  Threads;
public:
    forum(const string&) ;
    ~forum();
    void printforum();
    void printThread(string);
    void printPost(int);
    int get_GLOBAL_ID();
};
