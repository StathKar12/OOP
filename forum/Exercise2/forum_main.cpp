#include <iostream>
#include "forum_class.h"
#include <ctime>
#include <cstdlib>

#include <fstream>

using namespace std;

int main(void)
{
    srand(time(NULL));
    //post test1;
    //post test2;
    forum test3("Object Oriented Programming");
    test3.printforum();
    test3.printThread("Rules and Useful Informations");
    test3.print_sorted();
    return 0;
}
