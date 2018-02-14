/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mytail.h
 * Author: noc
 *
 * Created on 13 de febrero de 2018, 18:28
 */

#ifndef MYTAIL_H
#define MYTAIL_H

struct TDATO{
    int cod;
    std::string name;
    std::string surname;
};

class NODE{
public:
  TDATO mynode;
  NODE *next;
private:
};	

class mytail {
public:
    //Estandar
    mytail();
    mytail(const mytail& orig);
    virtual ~mytail();
    //Práctica
    void show();
    void add(TDATO &d);
    void remove();
    void removeat(int at);
    void clear();
    NODE& get(int i);
    void insert(TDATO &d, int at);
    int count();
    //Aux
    void debug(bool is_active);
    void dmsg(std::string message);
private:
    int length = 0;
    bool debug_flag = true;
    NODE* head_reference;
    NODE* find(int i);   
};

#endif /* MYTAIL_H */

