#pragma once
#include <cstdlib>
#include <sstream>
#include "Object_class.h"
#include "String_class.h"
#include "Employees_class.h"
int Sub_PassengerCompartment_Producing_Probability = 1;

class Employee;
class PlaneComponent: public Object{
    public:
        PlaneComponent(){}
        ~PlaneComponent(){}
        virtual PlaneComponent* clone()=0;
        bool identical(const PlaneComponent& CurPL) const{
            if(this == &CurPL) return true;
            return false;
        /**/}
        bool equal(const PlaneComponent& CurPL) const{
            if(Object::equal(CurPL)) return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            to_String = Object::toString(to_String);
            return to_String;
        /**/}
        virtual bool ready_check()=0;
        virtual void process(Employee* Emp)=0;

};

class PassengerCompartment: public PlaneComponent{
        PassengerCompartment* SubComp;
        String works_done;
    public:
        PassengerCompartment(bool WithSubComp=true): works_done("000"){
            SubComp=NULL;
            if(WithSubComp){
                if(Sub_PassengerCompartment_Producing_Probability==1){
                    SubComp = new PassengerCompartment(false);
                /**/}
                else if(rand()%Sub_PassengerCompartment_Producing_Probability){
                    SubComp = new PassengerCompartment();
                /**/}
            /**/}
        /**/}
        ~PassengerCompartment(){if(SubComp != NULL) delete SubComp;}
        virtual PassengerCompartment* clone(){
            PassengerCompartment* NewPassComp = new PassengerCompartment(false);
            String *temp=works_done.clone();
            NewPassComp->works_done = *temp;
            delete temp;
            NewPassComp->Object::id = Object::id;
            if(SubComp != NULL)
            {
                PassengerCompartment *temp=SubComp->clone();
                NewPassComp->SubComp =temp;
              //  delete[] temp;
            }
            return NewPassComp;
        /**/}
        bool identical(const PassengerCompartment& CurPassComp) const{
            if(this == &CurPassComp) return true;
            return false;
        /**/}
        bool equal(const PassengerCompartment& CurPassComp) const{
            if((SubComp == NULL)&&(CurPassComp.SubComp == NULL)){
                if((works_done.equal(CurPassComp.works_done))&&(PlaneComponent::equal(CurPassComp)))return true;
            }else if(SubComp!=NULL){
                if((works_done.equal(CurPassComp.works_done))&&(SubComp->equal(*CurPassComp.SubComp))&&(PlaneComponent::equal(CurPassComp))) return true;
            /**/}
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            if(to_String == NULL) to_String = new String("\n-||\"Passenger Compartment\"||------");
            else to_String->concat("-//\"Passenger Compartment\"\\\\_");
            to_String = PlaneComponent::toString(to_String);
            to_String->concat(works_done,"_works done_||--\n");
            if(SubComp != NULL) to_String = SubComp->toString(to_String);
            return to_String;
        /**/}
        virtual bool ready_check(){
            if(works_done.equal("101"))toString()->print("...\"Passenger Compartment OK!\"\n","\n");
            else return false;
            if(SubComp != NULL){
                if(SubComp->ready_check()) return true;
                return false;
            /**/}
            return true;
        /**/}
        virtual void process(Employee* Emp){
            Emp->workOn(PC,works_done);
            Emp->report(PC);
            if(SubComp != NULL) SubComp->process(Emp);
        /**/}
};

class PrivateCompartment: public PlaneComponent{
    public:
        PrivateCompartment(){}
        ~PrivateCompartment(){}
        virtual PrivateCompartment* clone()=0;
        bool identical(const PrivateCompartment& CurPrivateComp) const{
            if(this == &CurPrivateComp) return true;
            return false;
        /**/}
        bool equal(const PrivateCompartment& CurPrivateComp) const{
            if(PlaneComponent::equal(CurPrivateComp))return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            to_String = PlaneComponent::toString(to_String);
            return to_String;
        /**/}
        virtual bool ready_check()=0;
        virtual void process(Employee* Emp)=0;
};

class EquipmentCompartment: public PrivateCompartment{
        String works_done;
    public:
        EquipmentCompartment(): works_done("000"){}
        ~EquipmentCompartment(){}
        virtual EquipmentCompartment* clone(){
            EquipmentCompartment* NewEquipComp = new EquipmentCompartment;
            String *temp=works_done.clone();
            NewEquipComp->works_done =*temp;
            delete temp;
            NewEquipComp->Object::id = Object::id;
            return NewEquipComp;
        /**/}
        bool identical(const EquipmentCompartment& CurEquipComp) const{
            if(this == &CurEquipComp) return true;
            return false;
        /**/}
        bool equal(const EquipmentCompartment& CurEquipComp) const{
            if((works_done.equal(CurEquipComp.works_done))&&(PlaneComponent::equal(CurEquipComp)))return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            if(to_String == NULL) to_String = new String("\n-||\"Equipment Compartment\"||------");
            else to_String->concat("-//\"Equipment Compartment\"\\\\_");
            to_String = PrivateCompartment::toString(to_String);
            to_String->concat(works_done,"_works done_||--\n");
            return to_String;
        /**/}
        virtual bool ready_check(){
            if(works_done.equal("110")){
                toString()->print("...\"Equipment Compartment OK!\"\n","\n");
                return true;
            /**/}
            return false;
        /**/}
        virtual void process(Employee* Emp){
            Emp->workOn(EC,works_done);
            Emp->report(EC);
        /**/}
};

class CargoBay: public PrivateCompartment{
        EquipmentCompartment Equipment;
        String works_done;
    public:
        CargoBay(): works_done("000"){}
        ~CargoBay(){}
        virtual CargoBay* clone(){
            CargoBay* NewCargoBay = new CargoBay();
            EquipmentCompartment*temp=Equipment.clone();
            NewCargoBay->Equipment = *temp;
            delete temp;
            String *temp2=works_done.clone();
            NewCargoBay->works_done = *temp2;
            delete temp2;
            NewCargoBay->Object::id = Object::id;
            return NewCargoBay;
        /**/}
        bool identical(const CargoBay& CurCargoBay) const{
            if(this == &CurCargoBay) return true;
            return false;
        /**/}
        bool equal(const CargoBay& CurCargoBay) const{
            if((works_done.equal(CurCargoBay.works_done))&&(Equipment.equal(CurCargoBay.Equipment))&&(PlaneComponent::equal(CurCargoBay)))return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            if(to_String == NULL) to_String = new String("\n-||\"Cargo Bay\"||------");
            else to_String->concat("-//\"Cargo Bay\"\\\\_");
            to_String = PrivateCompartment::toString(to_String);
            to_String->concat(works_done,"_works done_||--\n");
            to_String = Equipment.toString(to_String);
            return to_String;
        /**/}
        virtual bool ready_check(){
            if(works_done.equal("111")){
                toString()->print("...\"Cargo Bay OK!\"\n","\n");
                return true;
            /**/}
            return false;
        /**/}
        virtual void process(Employee* Emp){
            Emp->workOn(CB,works_done);
            Emp->report(CB);
            Equipment.process(Emp);
        /**/}
};



