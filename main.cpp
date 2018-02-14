#include <iostream>
#include "mytail.h"

using namespace std;

int main(int argc, char** argv) {
    
    TDATO a;
    a.cod = 1;
    a.name = "Ramón";  
    a.surname = "Negrillo Valdivia";
    
    TDATO b;
    b.cod = 2;
    b.name = "Yezer";  
    b.surname = "Gonzalez Mella";
    
    TDATO c;
    c.cod = 3;
    c.name = "Rayco";  
    c.surname = "Serpa Alemani";
    
    TDATO d;
    d.cod = 4;
    d.name = "Ana Maria";  
    d.surname = "Nesoya Marquez";
    
    mytail *v = new mytail();
    v->debug(false);
    v->push(a);
    v->push(b);
    v->push(c);
    //v->show();
    NODE aux = v->pop();
    v->pop();
    v->pop();
    v->pop();
    v->pop();
    v->show();
    v->clear();
    delete v;
    return 0;
}

