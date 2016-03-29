#include <iostream>

using namespace std;

double toPower(double base, int pow);

int main()
   {
      double val;
      int pow;
      
      cout << "Enter value: ";
      cin >> val;
      cout << "Enter power: ";
      cin >> pow;
      
      cout << endl << val << " to power " << pow << " is " << toPower(val, pow) << "." << endl << endl;
      
      system("pause");
      
      return 0;
   }
   
double toPower(double base, int pow)
   {
      int counter = 0;
      double result = 1;
      
      if(pow > 0)
         {
            for(counter; counter < pow; counter++)
               {
                  result *= base;
               }
         }
      else
         {
            result = 1 / toPower(base, -pow);
         }
      
      return result;
   }
   
   
   
   
   
   
