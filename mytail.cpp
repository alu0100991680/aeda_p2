#include <string>
#include <iostream>
#include "mytail.h"

using namespace std;

//==================
//Métodos estandares
//==================

mytail::mytail() {
}

mytail::mytail(const mytail& orig) {
}

mytail::~mytail() {
}

//================
//Métodos práctica
//================

NODE * mytail::find(int at){
    NODE *n = this->head_reference;
    for(int i=0;i<at;i++){
        n = n->next;
    }
    return n;
}

NODE& mytail::get(int i){
    this->dmsg("F:GET->" + std::to_string(i));
    NODE *d = this->find(i);
    return *d;
}

int mytail::count() {
    this->dmsg("F:COUNT");
    return this->length;
}

void mytail::show() {
    this->dmsg("F:SHOW");
    this->dmsg("F:SHOW:Lista de objectos");
    if (length==0){ this->dmsg("F:SHOW:Vacia"); }
    
    cout << "--------" << endl;
    for (int i=0; i<this->length; i++){
        NODE *current_ = this->find(i);
        this->dmsg("F:SHOW:Objecto->" + std::to_string(i));
        cout << "Next->" << current_->next << endl;
        cout << current_->mynode.cod << endl;
        cout << current_->mynode.name << endl;
        cout << current_->mynode.surname << endl << endl;
    }
}

void mytail::clear(){
    this->dmsg("F:CLEAR");
    int fullcontent = this->length;
    for (int i=0;i<fullcontent;i++){
        this->removeat(0);
    }
    this->length = 0;
}

void mytail::push(TDATO &d) {
    this->dmsg("F:ADD");
    this->insert(d, 0);
}

 NODE& mytail::pop() {
    this->dmsg("F:REMOVE");
    NODE *c_aux = nullptr;
    if(0<this->length){
        NODE *aux = this->find(this->length-1);
        c_aux = new NODE(); // Hacemos una copia antes de borrarlo
        c_aux->mynode.cod = aux->mynode.cod;
        c_aux->mynode.name = aux->mynode.name;
        c_aux->mynode.surname = aux->mynode.surname;
        this->removeat(this->length-1);
    }
    return *c_aux;
}

void mytail::insert(TDATO &d, int at){
    this->dmsg("F:INSERT->" + std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        NODE *m = new NODE();
        m->mynode.cod = d.cod;
        m->mynode.name = d.name;
        m->mynode.surname = d.surname; 

        if (at<this->length){
            NODE *n = this->find(at);
            m->next = n; 

        }
        
        if (0<at){
            NODE *p = this->find(at-1);
            p->next = m;
        }
        
        if (at==0){
            this->head_reference = m;
        }
        
        this->length++;
    }
}

void mytail::removeat(int at){
    this->dmsg("F:REMOVEAT->" + std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        NODE *c = this->find(at);
        if(0<at){
            NODE *p = this->find(at-1);
            NODE *n = nullptr;
            if (at+1<this->length){        
                n= this->find(at+1);
            }
            p->next = n;
        }else{
            this->head_reference = c->next;
        }

        delete c;
        this->length--;
    }
}

//===========
//Métodos Aux
//===========

void mytail::debug(bool is_active){
    this->debug_flag = is_active;
}

void mytail::dmsg(std::string message){
    if (this->debug_flag==true){
        cout << message << endl;
    }
}
