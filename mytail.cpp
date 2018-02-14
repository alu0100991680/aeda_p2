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

void mytail::add(TDATO &d) {
    this->dmsg("F:ADD");

    NODE *n = new NODE();
    if (0<this->length){
        n->mynode.cod = d.cod;
        n->mynode.name = d.name;
        n->mynode.surname = d.surname;

        NODE *d = this->find(this->length-1);
        
        d->next = n;
        
    }else{
        //first
        n->mynode.cod = d.cod;
        n->mynode.name = d.name;
        n->mynode.surname = d.surname;
        n->next = nullptr;
        
        // Puntero head
        this->head_reference = n;
    }
    
    //Ampliamos el indicador de contenido
    this->length++;

}

void mytail::remove() {
    this->dmsg("F:REMOVE");
    if (0<this->length){
        //Creamos un vector y puntero asociado para volcar la nueva información
        //this->resize(-1);
            //Añadimos el nuevo dato a la cola

        //Ampliamos el indicador de contenido
        if(1<this->length){
            NODE *d = this->find(this->length-1);
            delete d->next;
            this->length--;
        }else{
            delete this->head_reference;
        }
    }
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
        this->remove();
    }
    this->length = 0;
}

void mytail::insert(TDATO &d, int at){
    this->dmsg("F:INSERT->" + std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        NODE *m = new NODE();
        m->mynode.cod = d.cod;
        m->mynode.name = d.name;
        m->mynode.surname = d.surname; 
        if (at==0){
            this->head_reference = m;
        }
        
        if (at<this->length){
            NODE *n = this->find(at);
            m->next = n; 

        }
        
        if (0<at){
            NODE *p = this->find(at-1);
            p->next = m;
        }
        
        this->length++;
    }
}

void mytail::removeat(int at){
    this->dmsg("F:REMOVEAT->" + std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        NODE *p = this->find(at-1);
        NODE *n = this->find(at+1);
        NODE *c = this->find(at);
        p->next = n;
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
