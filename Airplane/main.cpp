#include <iostream>
#include <cstdlib>
#include <ctime>
#include "String_class.h"
#include "Plane_class.h"

using namespace std;

int main()
{

    srand(time(NULL));
    Plane ThePlane("Boeing 747",400);

    SecurityEmployee SecGuy("Steven");
    MaintenanceEmployee MainGuy("Sett");
    CleaningEmployee CleGuy("Martha");

    ThePlane.process(&SecGuy);
    ThePlane.process(&MainGuy);
    ThePlane.process(&CleGuy);
    
    clone_encrypt_and_print(ThePlane);
   
    return 0;
}
