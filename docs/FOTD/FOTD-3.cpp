#include <iostream>
#include <cmath>

using namespace std;

double root(int num);

int main()
   {
      int input;
      
      cout << "Enter number: ";
      cin >> input;
      
      cout << endl << "Root: " << root(input) << endl << endl;
      
      system("pause");
      
      return 0;
   }
   
double root(int num)
   {
      if(num > 0)
         {
            return sqrt(num);
         }
      else
         {
            return 0;
         }
   }
