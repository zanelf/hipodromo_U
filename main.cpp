#include <ncurses.h>
#include "conejo.hpp"
#include<iostream>

int main(){
    srand (time(NULL));
    conejo bnnys = conejo(101,7);

    initscr();
    for(int i = 0;i<20;i++){
        erase();
        refresh();
        mvprintw(0,bnnys.correr(),"%c\n",bnnys.get_forma());
        mvprintw(1,bnnys.correr(),"%c\n",bnnys.get_forma());
        mvprintw(2,bnnys.correr(),"%c\n",bnnys.get_forma());

        getch();
         
    }
    endwin();
    return 0;
}