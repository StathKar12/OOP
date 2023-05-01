#include <iostream>
#include "Tree_class.h"


//LIST
List::List(post* CurrPost){
    ThePost = CurrPost->get_post();
}

List::~List(){
    //delete ThePost;
    delete Next;
    delete Previous;
}

void List::set_Next(List* NextList){
    Next = NextList;
}

void List::set_Previous(List* PreviousList){
    Previous = PreviousList;
}

List* List::next(){
    return Next;
}

List* List::previous(){
    return Previous;
}

post* List::get_Post(){
    return ThePost;
}


void List::add_Post(post* CurrPost){
    List* temp = Next;
    Next = new List(CurrPost);
    Next->set_Next(temp);
    Next->set_Previous(this);
    if(temp == NULL) return;
    temp = Next->next();
    temp->set_Previous(Next);
}

void List::print(){
    ThePost->printPost();
    if(Next != NULL) Next->print();
}

//TREE
Tree::~Tree(){
    delete LEFTTree;
    delete RIGHTTree;
    delete Posts;
}


Tree::Tree(){
    creator   ="NULL";
    Posts     = NULL ;
    LEFTTree  = NULL ;
    RIGHTTree = NULL ;
}

void Tree::add_Post(post* CurrPost){
    if(Posts == NULL){
        Posts = new List(CurrPost);
        creator = CurrPost->get_creator();
        return;
    }
    Posts->add_Post(CurrPost);
}

Tree* Tree::get_Right(){
    return RIGHTTree;
}

void Tree::add_Right(post* NewPost){
    RIGHTTree = new Tree;
    RIGHTTree->add_Post(NewPost);
}

Tree* Tree::get_Left(){
    return LEFTTree;
}

void Tree::add_Left(post* NewPost){
    LEFTTree = new Tree;
    LEFTTree->add_Post(NewPost);
}

string Tree::get_creator(){
    return creator;
}

void Tree::add_to_Tree(post* NewPost){
    if(Posts == NULL) {add_Post(NewPost); return;}
    string NewCreator = NewPost->get_creator();
    if(NewCreator.compare(creator) == 0){
        add_Post(NewPost);
    } else if(NewCreator.compare(creator) > 0){
        if(RIGHTTree == NULL)
            add_Right(NewPost);
        else
            RIGHTTree->add_to_Tree(NewPost);
    } else {
        if(LEFTTree == NULL)
            add_Left(NewPost);
        else
            LEFTTree->add_to_Tree(NewPost);
    }
}

List* Tree::get_posts(){
    return Posts;
}

void Tree::enhance(Tree* NewTree){
    List* NewPosts = NewTree->get_posts();
    while(NewPosts != NULL){
        add_to_Tree(NewPosts->get_Post());
        NewPosts = NewPosts->next();
    }
    if(NewTree->get_Left() != NULL) enhance(NewTree->get_Left());
    if(NewTree->get_Right() != NULL) enhance(NewTree->get_Right());
}

void Tree::print(){
    if(LEFTTree != NULL) LEFTTree->print();
    if(RIGHTTree != NULL) RIGHTTree->print();
    cout << "Creator: " << creator << endl;
    if(Posts != NULL) Posts->print();
}
