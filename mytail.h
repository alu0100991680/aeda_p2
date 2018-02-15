#ifndef MYTAIL_H
#define MYTAIL_H

struct TDATO{
    int cod;
    std::string name;
    std::string surname;
};

class TAILNODE{
public:
  TDATO mynode;
  TAILNODE *next;
private:
};	

class mytail {
public:
    mytail();
    mytail(const mytail& orig);
    virtual ~mytail();
    int count();
    void show();
    void clear();
    TAILNODE& pop();
    void push(TDATO &d);
    void debug(bool is_active);
private:
    int length = 0;
    bool debug_flag = false;
    TAILNODE* head_reference;
    TAILNODE* find(int i);   
    void removeat(int at);
    TAILNODE& get(int i);
    void insert(TDATO &d, int at);
    void dmsg(std::string message);
};

#endif /* MYTAIL_H */

