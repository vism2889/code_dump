//
//  pointerPPI.cpp
//  
//
//  Created by Morgan Visnesky on 10/13/18.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class WrapArrayShallow
{
private:
    char *pch;
public:
    WrapArrayShallow(const WrapArrayShallow &was);
    WrapArrayShallow & operator = (const WrapArrayShallow &was);
    //~WrapArrayShallow();
}

class WrapArrayDeep
{
private:
    char *pch;
public:
    WrapArrayDeep(const WrapArrayDeep &wad);
    WrapArrayDeep & operator =(const WrapArrayDeep &wad);
    //~WrapArrayDeep();
}

int main(void)
{
    int i = 7;
    int *pi;
    pi = &i;
    cout << endl << "This program section uses 3 variables" << endl;
    cout << "i = 7, pi a pointer to i and ppi a pointer to pi" << endl << endl;
    cout << "pi = " << pi << endl;
    cout << "dereference of pi = " << *pi << endl;
    cout << "address of pi = " << &pi << endl;
    cout << "address of i =  " << &i << endl << endl << endl;
    
    int **ppi;
    ppi = &pi;
    
    cout << "ppi = " << ppi << endl;
    cout << "dereference of ppi = " << *ppi << endl;
    cout << "address of ppi = " << &ppi << endl;
    cout << "double dereference of ppi =  " << **ppi << endl << endl << endl;
    
    cout << "This section of the program instantiates a wrapper class" << endl;
    cout << "for a dynamic array of 5 elements" << endl << endl;
    cout << "WRAPPER CLASSES -- WORK IN PROGRESS" << endl;
    system("pause");
}

class WrapArrayDeep{
    char *pch;
    WrapArrayDeep(){
        pch = new char[5];
        *pch = 97; //etc.
    }
    WrapArrayDeep(WrapArrayDeep &wad){
        // correct copy constructor.
    }
};

class WrapArrayShallow{
    char *pch;
    WrapArrayShallow(){
        pch = new char[5];
        *pch = 97; //etc.
    }
    WrapArrayShallow(WrapArrayShallow &wad){
        // INCORRECT copy constructor.
    }
};

