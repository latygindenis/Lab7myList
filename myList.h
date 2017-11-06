//
// Created by Денис on 06.11.2017.
//

#ifndef LAB7MYLIST_MYLIST_H
#define LAB7MYLIST_MYLIST_H


#include <iostream>
using namespace std;

template <class Data, int kol=0> class myList {
    class elem
    {
    public:
        Data d;
        elem *next;
        elem(Data dat = 0){d = dat; next = 0;}
    };
    elem *lstart, *lend;
public:
    myList(){lstart = 0; lend = 0;}

    virtual ~myList() {
        while (lstart != 0)
        {
            elem *pv = lstart;
            pv = pv->next;
            delete lstart;
            lstart = pv;
        }
    }

    void add(Data d) {
        elem *pv = new elem(d);
        if (lend == 0) {
            lstart = lend = pv;
        } else {
            lend->next = pv;
            lend = pv;
        }
    }
    void add_por(Data d)
    {
        elem *pv = new elem(d);
        elem *old = lstart;
        if (lend == 0) { //Если нет элементов в списке
            lstart = lend = pv;
        }
        else if (lstart->d >= pv->d){ //Добавление в начало
            pv->next = lstart;
            lstart = pv;
        }
        else if (lend->d <= pv ->d){ //Добавление в конец
            lend->next = pv;
            pv->next = 0;
            lend = pv;
        }
        else{ //Добавление "посередине"
            while (pv->d > old->next->d)
            {
                old = old->next;
            }
            pv->next = old->next;
            old->next = pv;
        }
    }
    void print() {
        elem *pv = lstart;
        cout<<"list: ";
        while (pv){
            cout<<pv->d<<" ";
            pv = pv->next;
        }
        cout<<endl;
    }
};

#endif //LAB7MYLIST_MYLIST_H
