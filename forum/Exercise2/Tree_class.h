#include "post_class.h"

class List{
    post* ThePost;
    List* Next=NULL;
    List* Previous=NULL;
public:
    List(post*);
    ~List();
    void  set_Next(List*)    ;
    void  set_Previous(List*);
    List* next()    ;
    List* previous();
    post* get_Post();
    void add_Post(post*) ;
    void print();
};

class Tree{
    string  creator   ;
    List*   Posts     ;
    Tree*   LEFTTree  ;
    Tree*   RIGHTTree ;
public:
    Tree();
    ~Tree();
    List* get_posts()  ;
    void enhance(Tree*);
    void add_Post(post*);
    Tree* get_Right();
    Tree* get_Left();
    string get_creator();
    void add_Left(post*);
    void add_Right(post*);
    void add_to_Tree(post*);
    void print();
};

