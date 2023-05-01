#pragma once
#include <sstream>
#include "String_class.h"

class String;
class Object{
    protected:
        int  id;
        void gen_id(){
            static int GLOBAL_ID = 0;
            id = ++GLOBAL_ID;
        /**/}
    public:
        Object(int I_D=-1){
            if(I_D == -1)
                gen_id();
            else
                id = I_D;
        /**/}
        virtual ~Object(){};
        virtual Object* clone()=0;
        bool identical(const Object& CurObject) const{
            if(this == &CurObject) return true;
            return false;
        /**/}
        bool equal(const Object& CurObject) const{
            if(id == CurObject.id) return true;
            return false;
        /**/}
        virtual String* toString(String*);
};
