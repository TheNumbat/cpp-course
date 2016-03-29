#include <iostream>

using namespace std;

bool isPrime(int val);

int main() 
   {
      int input;
      
      cout << "Enter value: ";
      cin >> input;
      
      if(isPrime(input))
         {
            cout << endl << input << " is prime." << endl << endl;
         }
      else
         {
            cout << endl << input << " is not prime." << endl << endl;
         }
         
      system("pause");
      
      return 0;
   }
   
bool isPrime(int val)
   {
      int count;
      
      for(count = 2; count <= (val / 2); count++)
         {
            if(val % count == 0)
               {
                  return false;
               }
         }
         
      return true;
   }
