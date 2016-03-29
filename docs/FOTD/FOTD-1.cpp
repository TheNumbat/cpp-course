#include <iostream>

using namespace std;

const int MAIN_TITLE = 1;
const int SUB_TITLE = 2;
const int ERROR_TITLE = 3;

void printTitle(int titleChoice);

int main() 
   {
   
      printTitle(MAIN_TITLE);
      
      cout << endl << endl;
      
      printTitle(SUB_TITLE);
      
      cout << endl << endl;
      
      printTitle(ERROR_TITLE);
      
      system("pause");
      
      return 0;
      
   }

void printTitle(int titleChoice)
   {
   
   switch(titleChoice)
      {
         case MAIN_TITLE:
            cout << "MY PROGRAM MAIN TITLE" << endl;
            break;
            
         case SUB_TITLE:
            cout << "My Program SubTitle" << endl;
            break;
            
         case ERROR_TITLE:
            cout << "My Program Error Title" << endl;   
            break;
      }   
      
   }
