//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Sorting funciton prototypes
void bubbleSort(int[],int);
void selectionSort(int[],int);
void quickSort(int[],int,int);

//Will put random values between 10 and to into an array
void randomize(int[],int);

//Shows how to pass a two dimensional array to a function
void func(int[][10]);

int main() {

	srand(time(NULL));

	//MULTIDIMENTIONAL ARRAYS	

	//Declares a two dimensional array of integers of sizes 10 and 10, so it
	//can store up to 100 integers in total.
	int array2D[10][10];

	//Declares a tree dimensional array of integers of sizes 10, 10, and 10, so it
	//can store up to 1000 integers in total.
	int array3D[10][10][10];

	//Passing a multidimensional array is the same as a one dimensional array
	func(array2D);

	//Loop though all three dimentions of the 3D array using three nested loops
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 10; k++)
				array3D[i][j][k] = 0;

	//Output each value in the 3D Array
	cout << "3D Array: " << endl;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 10; k++)
				cout << array3D[i][j][k];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;


	//SORTING

	int sortArray[10];


	//Demonstrate Bubble Sort
	randomize(sortArray,10);

	cout << "Array: ";
	for(int i = 0; i < 10; i++)
		cout << sortArray[i] << " ";

	bubbleSort(sortArray,10);

	cout << endl << "Bubble Sort: ";
	for(int i = 0; i < 10; i++)
		cout << sortArray[i] << " ";
	cout << endl << endl;


	//Demonstrate selection sort
	randomize(sortArray,10);

	cout << "Array: ";
	for(int i = 0; i < 10; i++)
		cout << sortArray[i] << " ";

	selectionSort(sortArray,10);

	cout << endl << "Selection Sort: ";
	for(int i = 0; i < 10; i++)
		cout << sortArray[i] << " ";
	cout << endl << endl;


	//Demonstrate quick sort
	randomize(sortArray,10);

	cout << "Array: ";
	for(int i = 0; i < 10; i++)
		cout << sortArray[i] << " ";

	quickSort(sortArray,0,10);

	cout << endl << "Quick Sort: ";
	for(int i = 0; i < 10; i++)
		cout << sortArray[i] << " ";
	cout << endl << endl;


	//End program
	cout << endl;
	system("pause");
	
	return 0;
}

void func(int array[][10]) {
	//Do stuff with array
}

void bubbleSort(int array[], int size) {

	int temp;

	//See notes
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size - 1; j++)
			if(array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
}

void selectionSort(int array[], int size) {

	int temp, lowest;

	//See notes
	for(int i = 0; i < size - 1; i++) {
		lowest = i;
		for(int j = i; j < size; j++)
			if(array[j] < array[lowest])
				lowest = j;
		temp = array[i];
		array[i] = array[lowest];
		array[lowest] = temp;
	}
}

void quickSort(int arr[], int left, int right) {

	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
 
 	//See notes
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
				j--;
			if (i <= j) {
	            tmp = arr[i];
	            arr[i] = arr[j];
	            arr[j] = tmp;
	            i++;
				j--;
			}
	}
 
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

void randomize(int array[], int size) {
	for(int i = 0; i < size; i++)
		array[i] = rand() % 10;
}
