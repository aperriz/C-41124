#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
    Set set1;
    Set set2;

    set1 += 1;
    set1 += 2;
    set1 += 3;
    set1.printSet();


    set2 += 3;
    set2 += 4;
    set2 += 5;
    set2.printSet();

    Set set3 = set1 + set2;
    set3.printSet();
    set3 -= 1;
    set3.printSet();

    Set set4 = set1 - set2;
    set4.printSet();

    Set set5 = set1 * set2;
    set5.printSet();
}