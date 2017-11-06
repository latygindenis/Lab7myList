#include <iostream>
#include "myList.h"

int main() {
    string str = "Hello";
    myList <string> myList_string;
    myList_string.add_por(str);
    myList_string.print();
    myList <int> myList_int;
    myList <float> myList_float;
    myList <char> myList_char;
    myList_float.add_por(2);
    myList_float.add_por(1);
    myList_float.add_por(0.5);
    myList_float.add_por(1.5);
    myList_float.add_por(100);
    myList_float.add_por(-100);
    myList_float.print();
    return 0;
}