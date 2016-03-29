#include <iostream>

using namespace std;

const int MAX_ITER = 1000;
const double ERROR = 0.0;

double getRoot(double, double, int);
double power(double, int);

int main()
   {
      double input, precision, root;
      int numRoots, count;
      
      //Input values
      cout << "Enter value: ";
      cin >> input;
      cout << "Enter number of roots: ";
      cin >> numRoots;
      cout << "Enter precision: ";
      cin >> precision;
      
      //Calculate and output each root, or output "error" if the
      //root could not be computed
      for(count = 2; count < numRoots + 2; count++)
         {
            root = getRoot(input,precision,count);
            
            cout << endl << "Root " << count << ": ";
            
            if(root != ERROR)
               {
                  cout << root;
               }
            else
               {
                  cout << "error";
               }
         }
      
      //End the program
      cout << endl << endl;
      system("pause");
      
      return 0;
   }
   
double getRoot(double seed, double precision, int root)
   {
      bool neg = false;
      int count = 0;
      double high = seed, low = 0, mid, test;
      
      //All roots of zero are 0, so return an error
      if(seed == 0)
         {
            return ERROR;
         }
	  //Test if the value is less than zero
      else if(seed < 0)
         {
         	//Make the value positive
            seed = -seed;
            high = seed;
            
            //If the root is odd, as in a squre root (2)
            //would be even, and return an error if it's not,
            //as you can't take an even root of a negative number
            if(root % 2 != 0)
               {
                  neg = true;
               }
            else
               {
                  return ERROR;
               }
         }
        
      //If the number is less than one, set it to one. This is to allow
      //the bianary search to work for numbers less than 1, as the squre
      //root of a number between zero and one will be larger than itself.
      if(high < 1)
         {
            high = 1;
         }
      
      //Make sure that if the search takes more than the maximum number of
      //iterations, the program does not go into an infinite loop.
      while(count < MAX_ITER)
         {
         	//Set the midrange value and calcuate the test value.
            mid = (high + low) / 2;
            test = power(mid,root);
            
            //If the test value is within a precision of the correct value,
            //return it as the night answer (and negative if it was origionally
            //negative.
            if(test <= seed + precision && test >= seed - precision)
               {
                  if(neg)
                     {
                        return -mid;
                     }
                  else
                     {
                        return mid;
                     }
               }
            //If the value is not correct, test if it is above or below the correct
            //value. If it above, set the new testing range to the upper half of the
            //previousone, and if it is below, set it it to the lower half.
            else if(test > seed + precision)
               {
                  high = mid;
               }
            else
               {
                  low = mid;
               }

            count++;
         }
         
         //Finally, if the while loop ended without returning a correclty value, return
         //an error, as it means that the number took more than the maximum number of iterations
         //to compute.
         return ERROR;
   }
   
double power(double seed, int pow)
   {
   	  //If the power is one, simply return the initial value.
      if(pow == 1) {
      	return seed;
      //If the value is more than one, return the intial value mulitplied by
      //the return of the funtion with one less power value. This will cause
      //the funciton to recursively call itself, and build a chain of multiplication
      //that gives the correct power.
	  } else {
	  	return seed * power(seed,pow - 1);
	  }
   }
   
   
   
   
   
   
   
   
   
   
   
