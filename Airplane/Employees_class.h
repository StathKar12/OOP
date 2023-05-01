#pragma once
#include "Object_class.h"
#include "String_class.h"
#include "PlaneComponent_class.h"

enum work_on_{CB,EC,PC};

class Employee: public Object{
    protected:
        String The_Name;
    public:
        Employee(const std::string& NAME=""): The_Name(NAME){};
        ~Employee(){}
        virtual void workOn(work_on_,String&)=0;
        virtual void report(work_on_)=0;
        virtual Employee* clone()=0;
        bool identical(const Employee& CurEmp) const{
            if(this == &CurEmp) return true;
            return false;
        /**/}
        bool equal(const Employee& CurEmp) const{
            if((The_Name.equal(CurEmp.The_Name))&&(Object::equal(CurEmp))) return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            to_String = Object::toString(to_String);
            to_String = The_Name.toString(to_String);
            return to_String;
        /**/}
};

class SecurityEmployee: public Employee {
    public:
        SecurityEmployee(const std::string& NAME=""): Employee(NAME){};
        ~SecurityEmployee(){}
        virtual void workOn(work_on_ Place,String& works){
            std::cout << "\nSecurity Employee \"";
            The_Name.print();
            switch(Place){
                case CB: works.updateAt(0,'1'); std::cout << "\" is working in  Cargo bay...\n"; break;
                case EC: works.updateAt(0,'1'); std::cout << "\" is working in  Equipment Compartment...\n"; break;
                case PC: works.updateAt(0,'1'); std::cout << "\" is working in  Passenger Compartment...\n"; break;
            /**/}
        /**/};
        virtual void report(work_on_ Place){
            std::cout << "\nSecurity Employee \"";
            The_Name.print();
            switch(Place){
                case CB: std::cout << "\" has finished working on Cargo bay... OK!\n"; break;
                case EC: std::cout << "\" has finished working on Equipment Compartment... OK!\n"; break;
                case PC: std::cout << "\" has finished working on Passenger Compartment... OK!\n"; break;
            /**/}
        /**/};
        virtual SecurityEmployee* clone(){
            SecurityEmployee* NewSec = new SecurityEmployee();
            NewSec->Employee::The_Name = Employee::The_Name;
            NewSec->id = Object::id;
            return NewSec;
        /**/}
        bool identical(const SecurityEmployee& CurSec) const{
            if(this == &CurSec) return true;
            return false;
        /**/}
        bool equal(const SecurityEmployee& CurSec) const{
            if(Employee::equal(CurSec)) return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            if(to_String == NULL) to_String = new String("\n-||\"Security Employee\"||------");
            else to_String->concat("-||Security Employee||");
            to_String = Employee::toString(to_String);
            to_String->concat("\n");
            return to_String;
        /**/}
};

class MaintenanceEmployee: public Employee {
    public:
        MaintenanceEmployee(const std::string& NAME=""): Employee(NAME){};
        ~MaintenanceEmployee(){}
        virtual void workOn(work_on_ Place,String& works){
            std::cout << "\nMaintenance Employee \"";
            The_Name.print();
            switch(Place){
                case CB: works.updateAt(1,'1'); std::cout << "\" is working in  Cargo bay...\n"; break;
                case EC: works.updateAt(1,'1'); std::cout << "\" is working in  Equipment Compartment...\n"; break;
                case PC: std::cout << "\" is having a break...\n"; break;
            /**/}
        /**/};
        virtual void report(work_on_ Place){
            std::cout << "\nMaintenance Employee \"";
            The_Name.print();
            switch(Place){
                case CB: std::cout << "\" has finished working on Cargo bay... OK!\n"; break;
                case EC: std::cout << "\" has finished working on Equipment Compartment... OK!\n"; break;
                case PC: std::cout << "\" didn't work on Passenger Compartment... OK!\n"; break;
            /**/}
        /**/};
        virtual MaintenanceEmployee* clone(){
            MaintenanceEmployee* NewMain = new MaintenanceEmployee();
            NewMain->Employee::The_Name = *Employee::The_Name.clone();
            NewMain->id = Object::id;
            return NewMain;
        /**/}
        bool identical(const MaintenanceEmployee& CurMain) const{
            if(this == &CurMain) return true;
            return false;
        /**/}
        bool equal(const MaintenanceEmployee& CurMain) const{
            if(Employee::equal(CurMain)) return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            if(to_String == NULL) to_String = new String("\n-||\"Maintenance Employee\"||------");
            else to_String->concat("-||Maintenance Employee||");
            to_String = Employee::toString(to_String);
            to_String->concat("\n");
            return to_String;
        /**/}
};

class CleaningEmployee: public Employee {
    public:
        CleaningEmployee(const std::string& NAME=""): Employee(NAME){};
        ~CleaningEmployee(){}
        virtual void workOn(work_on_ Place,String& works){
            std::cout << "\nCleaning Employee \"";
            The_Name.print();
            switch(Place){
                case CB: works.updateAt(2,'1'); std::cout << "\" is working in Cargo bay...\n"; break;
                case EC: std::cout << "\" is having a break...\n"; break;
                case PC: works.updateAt(2,'1'); std::cout << "\" is working in  Passenger Compartment...\n"; break;
            /**/}
        /**/};
        virtual void report(work_on_ Place){
            std::cout << "\nCleaning Employee \"";
            The_Name.print();
            switch(Place){
                case CB: std::cout << "\" worked on Cargo bay... OK!\n"; break;
                case EC: std::cout << "\" didn't work on Equipment Compartment... OK!\n"; break;
                case PC: std::cout << "\" worked on Passenger Compartment... OK!\n"; break;
            /**/}
        /**/};
        virtual CleaningEmployee* clone(){
            CleaningEmployee* NewCle = new CleaningEmployee();
            NewCle->Employee::The_Name = *Employee::The_Name.clone();
            NewCle->id = Object::id;
            return NewCle;
        /**/}
        bool identical(const CleaningEmployee& CurCle) const{
            if(this == &CurCle) return true;
            return false;
        /**/}
        bool equal(const CleaningEmployee& CurCle) const{
            if(Employee::equal(CurCle)) return true;
            return false;
        /**/}
        virtual String* toString(String* to_String=NULL){
            if(to_String == NULL) to_String = new String("\n-||\"Cleaning Employee\"||------");
            else to_String->concat("-||Cleaning Employee||");
            to_String = Employee::toString(to_String);
            to_String->concat("\n");
            return to_String;
        /**/}
};
