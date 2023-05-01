#pragma once
#include <iostream>
#include "Object_class.h"

class String: public Object{
        std::string The_string;
    public:
        String(const std::string& STR=""): The_string(STR){}
        ~String(){}
        bool identical(const String& CurString) const{
            if(this == &CurString) return true;
            return false;
        /**/}
        bool equal(const String& CurString) const{
            if((The_string.compare(CurString.The_string) == 0)&&(Object::equal(CurString))) return true;
            return false;
        /**/}
        bool equal(const std::string CurString) const{
            if(The_string.compare(CurString) == 0) return true;
            return false;
        /**/}
        virtual String* clone(){
            String* NewString = new String(The_string);
            NewString->id = this->id;
            return NewString;
        /**/}
        int length() const { return The_string.length();}
        void clear(){ The_string.clear();}
        void concat(const String& Sec_string,const std::string& last="",const std::string& first=""){
            The_string += first+Sec_string.The_string+last;
        /**/}
        void concat(const std::string& Sec_string,const std::string& last="",const std::string& first=""){
            The_string += first+Sec_string+last;
        /**/}
        char at(int pos) const { return The_string.at(pos);}
        void updateAt(int pos,const char NewChar) { The_string.replace(pos,1,1,NewChar);}
        void print(const std::string last="",const std::string first="") const {
             std::cout << first << The_string << last;
        /**/}
        virtual String* toString(String* to_String=NULL){
            if(to_String == NULL) to_String = new String;
            to_String->concat(The_string,"\"}-","-{\"");
            to_String = Object::toString(to_String);
            return to_String;
        /**/}
};

String* Object::toString(String* to_String=NULL){
            std::string s_id;
            std::stringstream ss;
            ss << id;
            ss >> s_id;
            if(to_String == NULL) to_String = new String;
            to_String->concat(s_id,"|_","_|ID-");
            return to_String;
}
