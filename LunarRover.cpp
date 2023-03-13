#include "LunarRover.h"
//#include "LunarSurface.h"
#include "LunarSurface.cpp"
#include <iostream>

LunarRover::LunarRover(LunarSurface *inBoard)
{
    gameBoard=inBoard;
    rowPOS=-1;
    colPOS=-1;
    fuel=100;
    damage=0;
}

LunarRover::~LunarRover()
{
    
}

void LunarRover::n(){}

void LunarRover::drawGrid()
{
    cout<<"\n\n\n";
      //Formating 
      cout<<" "<<setw(5)<<" ";
        for(int j=0;j<COLS;j++)
        {
          cout<<setw(2)<<j<<"|";
        }
        cout<<endl;
       
      //Printing  board
      for(int i=0;i<ROWS;i++)
      {
        cout<<setw(5)<<i<<"|";
        for(int j=0;j<COLS;j++)
        {
          cout<<gameBoard->getBoardUnit(i,j)<<"  ";
        }
        cout<<endl;
      }
}

bool LunarRover::land(int row,int col)
{
    if(gameBoard->getBoardUnit(row,col) != 'X')
    {
        rowPOS=row;
        colPOS=col;
        setTempSurface(getPositionX(),getPositionY());
        gameBoard->setBoardUnit(row,col,'S');
        return true;
    }
    return false;
} 

int LunarRover::getDamage()
    {
            return damage;
    }
void LunarRover::setDamage(int newdmg)
{
    damage=newdmg;
}

int LunarRover::getPositionX()
{
    return rowPOS;
}
int LunarRover::getPositionY()
{
    return colPOS;
}
void LunarRover::setPosition(int newrow, int newcol)
{
    //setTempSurface(getPositionX(),getPositionY());
    
    gameBoard->setBoardUnit(getPositionX(),getPositionY(),getTempSurface(getPositionX(),getPositionY()));
    setTempSurface(newrow,newcol);
    gameBoard->setBoardUnit(newrow,newcol,'S');
    rowPOS=newrow;
    colPOS=newcol;
}

void LunarRover::setTempSurface(int row,int col)
{
    surface= gameBoard->getBoardUnit(row,col);
    if(surface=='F'||surface=='$')
    {
        surface=' ';
    }
}
char LunarRover::getTempSurface(int row,int col)
{
    return surface;
}
void LunarRover::setFuel(int newfuel)
{
    fuel=newfuel;
}
int LunarRover::getFuel()
{
    return fuel;
}
int LunarRover::move (char direction)
{
    //cout<<"Which direction do you want to move (W,A,S,D)"<<endl;

    switch(direction)
    {

        case 'S':
        case 's':
        {
        if(gameBoard->getBoardUnit(getPositionX()+1,getPositionY())==' ')
                {
                    setFuel(getFuel()-2);
                    setPosition(getPositionX()+1,getPositionY());
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX()+1,getPositionY())=='-')
                {
                    setFuel(getFuel()-2);
                    setDamage(getDamage()+8);
                    setPosition(getPositionX()+1,getPositionY());
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX()+1,getPositionY())=='F')
                {
                    setFuel(getFuel()-2);
                    setFuel(100);
                    setPosition(getPositionX()+1,getPositionY());
                    return 0;
                }
                
                else if(gameBoard->getBoardUnit(getPositionX()+1,getPositionY())=='X')
                {
                    cout<<"You Crashed Game Over!";
                    setFuel(getFuel()-2);
                    return -1;
                    
                }
                else if(gameBoard->getBoardUnit(getPositionX()+1,getPositionY())=='$')
                {
                    cout<<"You WON!";
                    setFuel(getFuel()-2);
                    setPosition(getPositionX()+1,getPositionY());
                    return 1;
                    break;
                }
                break;
        }
    
        case 'w':
        case 'W':
        {
                if(gameBoard->getBoardUnit(getPositionX()-1,getPositionY())==' ')
                {
                    setFuel(getFuel()-2) ;
                    setPosition(getPositionX()-1,getPositionY());
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX()-1,getPositionY())=='F')
                {
                    setFuel(getFuel()-2) ;
                    setFuel(100);
                    setPosition(getPositionX()-1,getPositionY());
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX()-1,getPositionY())=='X')
                {
                    cout<<"You Crashed\nGame Over!\n";
                    setFuel(getFuel()-2);
                    return -1;
                }
                else if(gameBoard->getBoardUnit(getPositionX()-1,getPositionY())=='-')
                {
                    setFuel(getFuel()-2);
                    setDamage(getDamage()+8);
                    setPosition(getPositionX()-1,getPositionY());
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX()-1,getPositionY())=='$')
                {
                    cout<<"You WON!\n";
                    setFuel(getFuel()-2);
                    setPosition(getPositionX()-1,getPositionY());
                    return 1;
                    break;
                }
                break;
        }
        case 'd':
        case 'D':
        {
                if(gameBoard->getBoardUnit(getPositionX(),getPositionY()+1)==' ')
                {
                    setFuel(getFuel()-2);
                    setPosition(getPositionX(),getPositionY()+1);
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()+1)=='-')
                {
                    setFuel(getFuel()-2);
                    setDamage(getDamage()+8);
                    setPosition(getPositionX(),getPositionY()+1);
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()+1)=='F')
                {
                    setFuel(getFuel()-2);
                    setFuel(100);
                    setPosition(getPositionX(),getPositionY()+1);
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()+1)=='X')
                {
                    cout<<"You Crashed Game Over!";
                    setFuel(getFuel()-2);
                    return -1;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()+1)=='$')
                {
                    cout<<"You WON!";
                    setFuel(getFuel()-2);
                    setPosition(getPositionX(),getPositionY()+1);
                    return 1;
                    break;
                }
                break;
        }
        case 'a':
        case 'A':
        {
                if(gameBoard->getBoardUnit(getPositionX(),getPositionY()-1)==' ')
                {
                    setFuel(getFuel()-2);
                    setPosition(getPositionX(),getPositionY()-1);
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()-1)=='-')
                {
                    setFuel(getFuel()-2);
                    setDamage(getDamage()+8);
                    setPosition(getPositionX(),getPositionY()-1);
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()-1)=='F')
                {
                    setFuel(getFuel()-2);
                    setFuel(100);
                    setPosition(getPositionX(),getPositionY()-1);
                    return 0;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()-1)=='X')
                {
                    cout<<"You Crashed Game Over!";
                    setFuel(getFuel()-2);
                    return -1;
                }
                else if(gameBoard->getBoardUnit(getPositionX(),getPositionY()-1)=='$')
                {
                    cout<<"You WON!";
                    setFuel(getFuel()-2);
                    setPosition(getPositionX(),getPositionY()-1);
                    return 1;
                    
                    break;
                }
                break;
        }
        default:
        {
            cout<<"You entered a wrong direction\n";
        }
    }
}

bool LunarRover::play()
{
    cout<<"Board is loaded\nEnter the coordinates of landing (ROWS COLUMNS):\n";
    char a;
    do
    {
        int x;
        int y;
        
        cin>>x>>y;
        a=land(x,y);
        if(!a)
        {
            cout<<"Unable To Land Try Again (ROWS COLUMNS)\n";
        }
    }while(!a);
    drawGrid();



    int x;
    
    do{
        char d;
        cout<<"Which direction do you want to move (W,A,S,D)"<<endl;
        cin>>d;
        x=move(d);
        //cout<<"XPOS: "<<test.getPositionX()<<"YPOS: "<<test.getPositionY()<<endl;
       
        if (getFuel()==0) {
          cout<<"YOU RAN OUT OF FUEL"<<endl;
          x=-1;
          a=false;
        }
        else if (getDamage()==100) {
          cout<<"YOU TOOK TOO MUCH DAMAGE"<<endl;
          x=-1;
          a=false;
        }
        else if (x==1) {
           a=false;
        }
        else if (x==-1) {
          a=false;
        }
        else
        {
          a=true;
        }
        
        drawGrid();
        cout<<"\nYour Fuel: "<<getFuel()<<endl;
        cout<<"Your Damage: "<<getDamage()<<endl;
    }while(a);
    
    
    if(x == 1)
    {
      cout << "Do you want to play again?\n" ;
      cin>>a;
      if (a == 'Y'||'y'){
        return 1;
      }
      else {
        return 0 ;
      }
    }
    else
    {
      cout<<"\nYou Were So Close!!\n Play Again";
      cin>>a;
      if (a == 'Y'||'y'){
        return 1;
      }
      else {
        return 0 ;
      }
    }
}