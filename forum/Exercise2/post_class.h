#include <iostream>
#include <ctime>

using namespace std;

string createTXT(string="Text");

//POST
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
    string get_creator()  ;
    post* get_post()      ;
};
