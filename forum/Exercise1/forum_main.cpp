#include <iostream>
#include "forum_class.h"
#include <ctime>
#include <cstdlib>

#include <fstream>

using namespace std;

void print_Random_Post_of_Forum(forum& Currforum,int mult){
    while(mult-- != 0){
     Currforum.printPost(rand()%Currforum.get_GLOBAL_ID()+1);
    }
}

int main(void)
{
    srand(time(NULL));
    //post test1;
    //post test2;
    forum test3("Object Oriented Programming");
    test3.printforum();
    test3.printThread("Rules and Useful Informations");
    print_Random_Post_of_Forum(test3,5);
    return 0;
}
