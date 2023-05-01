#include "forum_class.h"
#include <cstdlib>
#include <fstream>
#include <string>

int GLOBAL_ID = 0;
const int Nms_Max_Range = 415;
const int Txt_Max_Range = 65;
const int Txt_Max_Size = 5;
const int Txt_Min_Size = 2;
//CLASS POST

post::post(){
    time_t curtime = time(0);
    Title = createTXT();
    creator = createTXT("Name");
    CreationD = localtime(&curtime);
    id = ++GLOBAL_ID;
    Text = createTXT();
    printPost();
}

void post::printPost(){
  cout << "\n    Post's Title: " << Title
       << "\n    Post's Creator: " << creator
       << "\n    Post's unique ID: " << id
       << "\n    Date: " << CreationD->tm_mday
       << "/" << 1 + CreationD->tm_mon
       << "/" << 1900 + CreationD->tm_year
       << "  " << CreationD->tm_hour
       << ":" << CreationD->tm_min
       << ":" << CreationD->tm_sec
       << "\n\n    Post:: \"" << Text << "\"\n\n";
}

string createTXT(string Type){
    string TheText;
    if(!Type.compare("Name")){
        ifstream file;
        int range = rand()%Nms_Max_Range;
        file.open("names.txt");
        while((range-- != 0)&&(getline(file,TheText)));
        file.close();
        return TheText;
    }
    if(!Type.compare("Text")){
        ifstream file;
        int Tsize = Txt_Min_Size + rand()%Txt_Max_Size;
        file.open("texts.txt");
        while(Tsize-- != 0){
            string Currtxt;
            int range = rand()%Txt_Max_Range;
            while((range-- != 0)&&(getline(file,Currtxt)))if(range == 0){
                Currtxt.erase(Currtxt.end()-1);
                TheText.insert(0,Currtxt+' ');
                if(Tsize == 0) TheText.erase(TheText.end()-1);
            }
            file.seekg(0);
        }
        file.close();
        return TheText;
    }
}

post::~post(){
  cout << "\nPost number: \"" << id << "\" is about to be destroyed\n";
}

string post::get_Text(){
  return Text;
}

int post::get_ID(){
    return id;
}

//CLASS THREAD

thread::thread(){
    cout << "\nThread with subject: \"" << subject << "\" has just been created!\n";
    time_t curtime;
    subject = createTXT();
    creator = createTXT("Name");
    CreationD = localtime(&curtime);
    Posts = new post[GLOBAL_T_SIZE];
}

void thread::printThread(){
  cout << "\n    Thread's Subject: " << subject
       << "\n    Thread's Creator: " << creator
       << "\n    Date: " << CreationD->tm_mday
       << "/" << 1 + CreationD->tm_mon
       << "/" << 1900 + CreationD->tm_year
       << "  " << CreationD->tm_hour
       << ":" << CreationD->tm_min
       << ":" << CreationD->tm_sec << "\n\n    Posts: \n";
    for(int i = 0; i<GLOBAL_T_SIZE ;i++){
      cout << "    " << Posts[i].get_Text() <<"\n";
    }
    cout << endl;
}

string thread::get_subject(){
  return subject;
}

thread::~thread(){
    cout << "\nThread with subject: \"" << subject << "\" is about to be destroyed\n";
    delete[] Posts;
}

int thread::printPost(int id){
    int i;
    for(i = 0; i<GLOBAL_T_SIZE ;i++){
      if(id != Posts[i].get_ID()) {
        cout << "\nPost with id \"" << id << "\" found:\n";
        Posts[i].printPost();
        return 1;
      };
    }
    //while(i++ < GLOBAL_T_SIZE)if(id != Posts[i].get_ID());
    return 0;
}

void thread::set_subject(string subject){
    this->subject = subject;
}

//CLASS FORUM

void forum::printforum(){
  cout << "\nForums's Title: " << Title << "\n\nThreads: \n";
    for(int i = 0; i<GLOBAL_F_SIZE ;i++){
      cout << Threads[i].get_subject() <<"\n";
    }
    cout << endl;
}

forum::forum(const string& Title){
    cout << "Forum with title: \"" << Title << "\" has just been created!\n";
    this -> Title = Title;
    Threads = new thread[GLOBAL_F_SIZE];
    Threads[0].set_subject("Rules and Useful Informations");
}

forum::~forum(){
    cout << "Forum with title: \"" << Title << "\" is about to be destroyed\n";
    delete[] Threads;
}

void forum::printThread(string Title){
    int i = 0;
    while((i != GLOBAL_F_SIZE)&&(Title.compare(Threads[i++].get_subject()) != 0));
    if(i == GLOBAL_F_SIZE) {cout << "Thread \"" << Title << "\" wasn't found !!!\n"; return;}
    cout << "\nThread \"" << Title << "\" found:\n";
    Threads[--i].printThread();
}

void forum::printPost(int id){
    int i;
    for(i = 0; i<GLOBAL_F_SIZE ;i++){
        if(Threads[i].printPost(id)) return;
    }
    if(i == GLOBAL_F_SIZE) {cout << "Post with id \"" << id << "\" wasn't found !!!\n"; return;}
}

int forum::get_GLOBAL_ID(){
    return GLOBAL_ID;
}
