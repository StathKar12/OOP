#pragma once
#include "PlaneComponent_class.h"
int Max_Plane_Capacity = 400;
int Max_Passenger_Compartment_Capacity = 100;

class Plane :public Object{
  CargoBay CB;
  EquipmentCompartment *EC;
  PassengerCompartment *PC;
  int Number_of_Compartments;
  int passengers_limit;
  String Title;
public:
    Plane(const std::string& STR="",int passengers=0): Title(STR){
        passengers_limit = Max_Plane_Capacity;
        if(!passengers) passengers = rand()%(passengers_limit+1);
        else passengers = passengers%(passengers_limit+1);
        Number_of_Compartments = passengers/Max_Passenger_Compartment_Capacity;
        if(passengers%Max_Passenger_Compartment_Capacity) Number_of_Compartments++;
        PC=new PassengerCompartment[Number_of_Compartments];
        EC=new EquipmentCompartment[3];

    /**/}
    ~Plane(){
        delete[] PC;
        delete[] EC;
    /**/}
    virtual Plane* clone(){
        Plane* NewPlane = new Plane("",Number_of_Compartments*Max_Passenger_Compartment_Capacity);
        CargoBay *temp=CB.clone();
        NewPlane->CB = *temp;
        delete temp;
        EquipmentCompartment* temp1;
        PassengerCompartment* temp2;
        for(int i=0; i<Number_of_Compartments ;i++){
            if(i<3) {
                temp1=EC[i].clone();
                NewPlane->EC[i] = *temp1;
                delete temp1;
            /**/}
            temp2=PC[i].clone();
            NewPlane->PC[i] = *temp2;
          // delete[] temp2;
        /**/}
        NewPlane->Number_of_Compartments = Number_of_Compartments;
        NewPlane->passengers_limit = passengers_limit;
        String *temp3=Title.clone();
        NewPlane->Title = *temp3;
        delete temp3;
        NewPlane->id = this->id;
        return NewPlane;
    /**/}
    bool identical(const Plane& CurPlane) const{
        if(this == &CurPlane) return true;
        return false;
    /**/}
    bool equal(const Plane& CurPlane) const{
        if((CB.equal(CurPlane.CB))&&(Number_of_Compartments==CurPlane.Number_of_Compartments)){
            if((passengers_limit==CurPlane.passengers_limit)&&(Title.equal(CurPlane.Title))){
                for(int i=0; i<Number_of_Compartments ;i++){
                    if(i<3)if(!EC[i].equal(CurPlane.EC[i])) return false;
                    if(!PC[i].equal(CurPlane.PC[i])) return false;
                /**/}
                return true;
            /**/}
        /**/}
        return false;
    /**/}
    virtual String* toString(String* to_String=NULL){
        if(to_String == NULL) to_String = new String("\n-||\"Plane\"||------");
        else to_String->concat("-//\"Plane\"\\\\_");
        to_String = Object::toString(to_String);
        to_String->concat(Title,"\")","(\"");
        std::stringstream ss;
        std::string The_String;
        ss << Number_of_Compartments;
        ss >> The_String;
        to_String->concat(The_String,"_Number_of_Compartments||--","_");
        ss << passengers_limit;
        ss >> The_String;
        to_String->concat(The_String,"_passengers_limit||--\n","_");
        to_String = CB.toString(to_String);
        for(int i=0; i<3 ;i++){
            to_String = EC[i].toString(to_String);
        /**/}
        for(int i=0; i<Number_of_Compartments ;i++){
            to_String = PC[i].toString(to_String);
        /**/}
        return to_String;
    /**/}
    bool ready_check(){
        if(!CB.ready_check()) return false;
        for(int i=0; i<3 ;i++){
            if(!EC[i].ready_check()) return false;
        /**/}
        for(int i=0; i<Number_of_Compartments ;i++){
            if(!PC[i].ready_check()) return false;
        /**/}
        std::cout << "\nPlane ready to take off!\n";
        return true;
    /**/}
    void process(Employee* Emp){
        CB.process(Emp);
        for(int i=0; i<3 ;i++){
            EC[i].process(Emp);
        /**/}
        for(int i=0; i<Number_of_Compartments ;i++){
            PC[i].process(Emp);
        /**/}
    /**/}
};
void clone_encrypt_and_print(Object& CurObject){
          
            Object* Clone_Object = CurObject.clone();
            if(Clone_Object->equal(CurObject)) std::cout << "\nEqual\n";
            String* First_Object = CurObject.toString();
            String* Sub_Object = Clone_Object->toString();
            int length = First_Object->length();
            int times = rand()%(length+1)+12;
            while(times--){
                int random_char = rand()%93+33;
                Sub_Object->updateAt(rand()%(length+1),(char)random_char);
            }
            First_Object->print("\n","\n");
            Sub_Object->print("\n","\n");
            Sub_Object->concat(*First_Object);
            std::cout << "\nLength: " << Sub_Object->length() << std::endl;
            int middle =Sub_Object->length()/2;
            if(Sub_Object->length()%2){
                if(Sub_Object->at(middle+1) != '\n') std::cout << "\nMiddle: " << Sub_Object->at(middle+1);
                else std::cout << "\nMiddle: " << '\\' << 'n' << std::endl;
            }
            else {
                if(Sub_Object->at(middle+1) != '\n') std::cout << "\nMiddle: + 0.5:" << Sub_Object->at(middle+1);
                else std::cout << "\nMiddle + 0.5: " << '\\' << 'n' << std::endl;
                if(Sub_Object->at(middle) != '\n') std::cout << "\nMiddle - 0.5: " << Sub_Object->at(middle);
                else std::cout << "\nMiddle - 0.5: " << '\\' << 'n' << std::endl;
            }
            Sub_Object->clear();
            std::cout << "\nClearing String...";
            std::cout << "\nLength: " << Sub_Object->length() << std::endl;
            delete First_Object;
            delete Sub_Object;
            delete Clone_Object;
}

