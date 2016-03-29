#include <iostream>

using namespace std;

const int VOLUME = 1;
const int SURFACE_AREA = 2;

double calcCube(double sidelen, int calcChoice);

int main()
   {
      double side;
      
      cout << "Enter side length: ";
      cin >> side;
      
      cout << endl << "Cube of length " << side << ": " << endl << "   Volume: " 
           << calcCube(side, VOLUME) << endl << "   Surface area: " << calcCube(side,SURFACE_AREA)
           << endl << endl;
      
      system("pause");
      
      return 0;
   }
   
double calcCube(double sideLen, int calcChoice)
   {
      switch(calcChoice)
         {
            case VOLUME:
               return sideLen * sideLen * sideLen;
               
            case SURFACE_AREA:
               return sideLen * sideLen * 6;
         }
   }
