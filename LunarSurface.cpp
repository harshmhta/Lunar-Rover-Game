#include "LunarSurface.h"
//const int ROWS = 15, COLS = 40;
//char board[ROWS][COLS];	


LunarSurface::LunarSurface()
{
  
}

LunarSurface::~LunarSurface()
{
    
}

bool LunarSurface::readBoardFile(string filename)
{
    ifstream file(filename);
  bool a=file.is_open();
  if(a)
  {
    //2D array
      char check;
      string line;
      int j=0;
      while(getline(file,line))
      {
        
         for(int i=0;i<line.length();i++)
         {
           //cout<<line[i];
           check=line[i];
          board[j][i]=check;
         }
         //cout<<endl;
       j++;
      }
      
      //Checking board
      
      for(int i=0;i<ROWS;i++)
      {
        for(int j=0;j<COLS;j++)
        {
          check=board[i][j];
          if(!(check==' '||check=='X'||check=='F'||check=='$'||check=='-'))
          {
              return false;
          }
        }

      }
      
      //Hiding the stuff
      
      /* */
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
          cout<<board[i][j]<<"  ";
        }
        cout<<endl;
      }
      
      /*while(file>>check)
      {
          
          /*if(!(check==' '||check=='X'||check=='F'||check=='$'||check=='-'))
          {
              return false;
          }
      }*/
      
  }
  return true;
}
char LunarSurface::getBoardUnit(int row, int col)
{
  return board[row][col];
}
void LunarSurface::setBoardUnit(int row, int col, char inChg)
{
  board[row][col]=inChg;
}


//Replaced By draw Grid later
void LunarSurface::printBoard()
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
          cout<<board[i][j]<<"  ";
        }
        cout<<endl;
      }
      
}