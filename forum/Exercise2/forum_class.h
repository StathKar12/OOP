#include "Tree_class.h"

const int GLOBAL_F_SIZE = 3;
const int GLOBAL_T_SIZE = 3;

//THREAD
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
    post* get_post(int)    ;
    post* get_posts()      ;
};

//FORUM
class forum{
    string  Title  ;
    thread*  Threads;
    Tree* TheTree;
public:
    forum(const string&) ;
    ~forum();
    void printforum();
    void printThread(string);
    void printPost(int);
    int get_GLOBAL_ID();
    void to_Tree(thread&,int);
    void  print_sorted();
};
