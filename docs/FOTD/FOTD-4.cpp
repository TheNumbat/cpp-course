#include <iostream>

using namespace std;

int getMaxOfTwo(int num1, int num2);
int getMaxOfThree(int num1, int num2, int num3);

int main()
   {
      int num1, num2, num3;
      
      cout << "Enter number 1: ";
      cin >> num1;
      cout << "Enter number 2: ";
      cin >> num2;
      cout << "Enter number 3: ";
      cin >> num3;
      
      cout << endl << "Max of numbers 1 and 2: " << getMaxOfTwo(num1,num2) << endl << endl;
      cout << "Max of all numbers: " << getMaxOfThree(num1,num2,num3) << endl << endl;
      
      system("pause");
      
      return 0;
   }
   
int getMaxOfTwo(int num1, int num2)
   {
      if(num1 > num2)
         {
            return num1;
         }
      else
         {
            return num2;
         }
   }
   
int getMaxOfThree(int num1, int num2, int num3)
   {
      return getMaxOfTwo(getMaxOfTwo(num1,num2),num3);
   }
