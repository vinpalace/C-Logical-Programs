#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>

using namespace std;

class Rover
{
    int x;
    int y;
    char orientation;


public:
    Rover();
    Rover(int, int, char);
    void rotateLeft();
    void rotateRight();
    void movePosition();
    void pingPosition();

};

Rover::Rover()
{
    x = 0;
    y = 0;

    orientation = 'N';
}

Rover::Rover(int positionX, int positionY, char direction)
{
    x = positionX;
    y = positionY;

    orientation = direction;
}


void Rover::rotateRight()
{
    if(orientation == 'N')
        orientation = 'E';
    else if(orientation == 'E')
        orientation = 'S';
    else if(orientation == 'S')
        orientation = 'W';
    else if(orientation == 'W')
        orientation = 'N';
}

void Rover::rotateLeft()
{
    if(orientation == 'N')
        orientation = 'W';
    else if(orientation == 'E')
        orientation = 'N';
    else if(orientation == 'S')
        orientation = 'E';
    else if(orientation == 'W')
        orientation = 'S';
}


void Rover::movePosition()
{
    if(orientation == 'N')
        y++;
    else if(orientation == 'E')
        x++;
    else if(orientation == 'S')
        y--;
    else if(orientation == 'W')
        x--;
}
void Rover::pingPosition()
{

    cout<<x<<" "<<y<<" "<<orientation;

}



int main()
{
    int x, y;
    char direction;

    cout<<"Enter DropZone coordinates"<<endl;
    cin>>x>>y>>direction;

    Rover curiosity(x, y, direction);

    cout<<endl;

    curiosity.pingPosition();

    string inputString;

    cout<<"Enter Command String... Standing By"<<endl;
    cin>>inputString;

    int i;

    for(i = 0; i < inputString.size(); i++)
    {
        if(inputString[i] == 'L')
            curiosity.rotateLeft();
        else if(inputString[i] == 'R')
            curiosity.rotateRight();
        else
            curiosity.movePosition();

    }

    curiosity.pingPosition();

    return 0;
}
