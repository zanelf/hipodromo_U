#ifndef CONEJO_H
#define CONEJO_H
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class conejo 
{
private:
    char forma;
    int vel;
public:
    conejo(char,int);
    ~conejo();
    void C_vel(int);
    int get_vel();
    char get_forma();
    float correr();
};


#endif
