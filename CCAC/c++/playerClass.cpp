//
//  playerClass.cpp
//  
//
//  Created by Morgan Visnesky on 9/21/18.
//
//
// Write a class that represents a player in a game.  The player should have a name, password, experience
// points, an inventory array of four strings, and a location x,y. Your class should have mutator and accessor
// methods for all variables. For example: setName(), getName(). It should have a suitable display method.
// Mutators and accessors should be public but all variables should be private. To implement get inventory, use
// string * getInv();  Use the scope resolution operator to implement larger methods such as display().  Use in
// class methods for shorter methods such as setName(), getName().
//
//
//
//


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;


class player
{
public:
    void setName(string newName)
    {
        name = newName;
    }
    
    string getName()
    {
        return name;
    }
    
    void setPassword(string newPW)
    {
        password = newPW;
    }
    
    string getPassword()
    {
        return password;
    }
    
    void setXP(int newXP)
    {
        XP = newXP;
    }
    
    int getXP()
    {
        return XP;
    }
    
    void setInventory(string item1, string item2, string item3, string item4)
    {
        inventory[0] = item1;
        inventory[1] = item2;
        inventory[2] = item3;
        inventory[3] = item4;
    }
    
    string getInventory()
    {
        return inventory[0];
    }
    
    void setPosition(int xVal, int yVal)
    {
        xValue = xVal;
        yValue = yVal;
    }
    
    string getPosition()
    {
        cout << "(" << xValue << ", " << yValue << ")";
        return "";
    }
    
    
private:
    
    string name;
    string password;
    int XP;
    string inventory[4];
    int position;
    int xValue;
    int yValue;
    
    
};

int main(void)
{
    player morgan, bill, mary;
    
    morgan.setName("Morgan");
    morgan.setPassword("bigcowboyhat");
    morgan.setXP(100);
    morgan.setInventory("magic flute", "magic drums", "magic tambourine", "magic flask");
    morgan.setPosition(1234, 5678);
    
    bill.setName("Bill");
    bill.setPassword("willdanceforhoagies");
    bill.setXP(1000);
    bill.setPosition(10, 9078);
    
    mary.setName("Mary");
    mary.setPassword("iluvprogramming");
    mary.setXP(10000);
    mary.setPosition(354, 16725);
    
    cout << endl << "Player Info - " << endl;
    cout << "Name: " << morgan.getName() << endl;
    cout << "Password: " << morgan.getPassword() << endl;
    cout << "Experience: " << morgan.getXP() << endl;
    cout << "Position: " << morgan.getPosition() << endl;
    cout << "Inventory: " << endl << morgan.getInventory() << endl;
    
    cout << endl << "Player Info - " << endl;
    cout << "Name: " << bill.getName() << endl;
    cout << "Password: " << bill.getPassword() << endl;
    cout << "Experience: " << bill.getXP() << endl;
    cout << "Position: " << bill.getPosition() << endl;
    cout << "Inventory: " << bill.getInventory() << endl;
    
    cout << endl<< "Player Info - " << endl;
    cout << "Name: " << mary.getName() << endl;
    cout << "Password: " << mary.getPassword() << endl;
    cout << "Experience: " << mary.getXP() << endl;
    cout << "Position: " << mary.getPosition() << endl;
    cout << "Inventory: " << mary.getInventory() << endl;
    
    
    system("pause");
}
