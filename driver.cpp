//#include "LunarSurface.cpp"
//#include "LunarSurface.h"
#include "LunarRover.h"
#include "LunarRover.cpp"
using namespace std;

int main()
{
    
  string line;
  ifstream myfile ("ascii.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
    
    bool a=0;
    cout<<"Loading Default Board File\n";
    LunarSurface land;
    LunarRover test(&land);
    
    a=land.readBoardFile("Proj3_board01.txt");
    while(!a)
    {
        string filename;
        cout<<"Either 'Proj3_board01.txt' doesn't exist or doesn't contain a valid board file\n\nSpecify a different board file: ";
        cin>>filename;
        a=land.readBoardFile(filename);
        
    }
    
    while(test.play()==1)
    {
      
    }

}