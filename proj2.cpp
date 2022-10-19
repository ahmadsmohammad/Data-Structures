#include<iostream>
#include<fstream>
#include<string>

#include "intsllist.h"

using namespace std;


int main()
{
    IntSLList chicken;
    ifstream myin;
    myin.open("ints.txt");

    int num;
    string letter;

    while(myin>>num)
    {
        myin >> letter;
        if (letter == "a")
        {
                chicken.insertInOrder(num);
                cout <<'('<<letter<<')'<<num;
                chicken.printAll();
        }

        else if (letter == "d")
        {
                cout <<'('<<letter<<')'<<num;
                chicken.deleteVal(num);
                chicken.printAll();

        }
        else if (letter == "D")
        {
                cout <<'('<<letter<<')'<<num;
                chicken.deleteAllVal(num);
                chicken.printAll();

        }

    }

    chicken.clearList();

}
                                                                                                                                                                                                                                                                   