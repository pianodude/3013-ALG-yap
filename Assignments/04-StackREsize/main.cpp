/////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin, Joshua Yap
// Email:            terry.griffin@msutexas.edu, joshyap92@yahoo.com
// Label:            L01
// Title:            Lecture 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Array based stack that can increase or half the size
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
	int* A;           // pointer to array of int's
	int size;         // current max stack size
	int top;          // top of stack 

public:
	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor no params
	 *
	 * Params:
	 *     - None
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack() {
		size = 10;
		A = new int[size];
		top = -1;
	}

	/**
	 * ArrayStack
	 *
	 * Description:
	 *      Constructor size param
	 *
	 * Params:
	 *     - int size
	 *
	 * Returns:
	 *     - NULL
	 */
	ArrayStack(int s) {
		size = s;
		A = new int[s];
		top = -1;
	}

	/**
	 * Public bool: Empty
	 *
	 * Description:
	 *      Stack empty?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = empty
	 */
	bool Empty() {
		return (top <= -1);
	}

	/**
	 * Public bool: Full
	 *
	 * Description:
	 *      Stack full?
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [bool] true = full
	 */
	bool Full() {
		return (top >= size - 1);
	}

	/**
	 * Public int: Peek
	 *
	 * Description:
	 *      Returns top value without altering the stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Peek() {
		if (!Empty()) {
			return A[top];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public int: Pop
	 *
	 * Description:
	 *      Returns top value and removes it from stack
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      [int] top value if any
	 */
	int Pop() {
		if (!Empty()) {
			return A[top--];
		}

		return -99; // some sentinel value
					// not a good solution
	}

	/**
	 * Public void: Print
	 *
	 * Description:
	 *      Prints stack to standard out
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void Print() {
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}

	/**
	 * Public bool: Push
	 *
	 * Description:
	 *      Adds an item to top of stack
	 *
	 * Params:
	 *      [int] : item to be added
	 *
	 * Returns:
	 *      [bool] ; success = true
	 */
	bool Push(int x) {
		if (Full()) {
			ContainerGrow();
		}
		if (!Full()) {
			A[++top] = x;
			return true;
		}

		return false;

	}

	/**
	 * Public void: ContainerGrow
	 *
	 * Description:
	 *      Increases the container capacity for the stack
	 *      by 1.75
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void ContainerGrow() {
		int newSize = size * 1.75;          // double size of original
		int* B = new int[newSize];          // allocate new memory

		for (int i = 0; i < size; i++) {    // copy values to new array
			B[i] = A[i];
		}

		delete[] A;                         // delete old array

		size = newSize;                     // save new size

		A = B;                             // reset array pointer

	}

	/**
	 * Public void: ContainerShrink
	 *
	 * Description:
	 *      Cuts the container capacity for the stack 
	 *      in half
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */
	void ContainerShrink()
	{
		int newSize = size / 2;
		int* C = new int[newSize];

		for (int j = 0; j < newSize; j++)
		{
			C[j] = A[j];
		}
		delete[] A;
		size = newSize;
		A = C;
	}
	/**
	 * Public bool: CheckResize
	 *
	 * Description:
	 *      Determines to use either to shrink or grow
	 *      the stack
	 *
	 * Params:
	 *      int maxSize passed by reference
	 *
	 * Returns:
	 *      true if either method is used
	 */
	bool CheckResize(int& maxSize)
	{
		if (top == ((size / 2) - 1))    //if top is just 1
		{								//below half of current size
			ContainerShrink();
			return true;
		}
		else if (Full()) {
			ContainerGrow();
			if (size > maxSize)
			{
				maxSize = size;			//if there is a new maxsize
				return true;
			}
		}
		else
		{
			return false;				//if no resize necessary
		}
	}
	/**
	 * Public int: getSize
	 *
	 * Description:
	 *      class accessor for size
	 *      
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      size from ArrayStack class
	 */
	int getSize()  //will call this method for the final size
	{
		return size;
	}


};



// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
	ArrayStack stack;				//using default



	ifstream infile;
	ofstream outfile;
	int maxSize=10;					// if stack capacity increases
	int resizeCount = 0;			// counter
	
	int entry;

	infile.open("nums.dat");        //change the files here
	outfile.open("result2.txt");

	//*while loop goes here*
	while (!infile.eof())			//end loop at end of file
	{
		infile >> entry;
		if (entry % 2 == 0)			//if the number is even...
		{
			stack.Push(entry);		//...push it
			if (stack.CheckResize(maxSize) == true)
			{
				resizeCount++;		//if it's full
			}
		}
		else
		{
			stack.Pop();			//..if its odd, pop the stack
			if (stack.CheckResize(maxSize) == true)
			{
				resizeCount++;		//if it's just half empty
			}
		}

		

	}

	//*end of loop goes here*
	outfile << "####################################################" << endl;
	outfile << '\t' << "Assignment 4 - Resizing the stack" << endl;
	outfile << '\t' << "CMPS 3013" << endl;
	outfile << '\t' << "Joshua Yap" << endl;
	outfile << endl;
	outfile << '\t' << "Max Stack Size: " << maxSize << endl;
	outfile << '\t' << "End Stack Size: " << stack.getSize() << endl;
	outfile << '\t' << "Stack Resized: " << resizeCount << " times" << endl;
	outfile << "####################################################" << endl;
	infile.close();   //close  files
	outfile.close();
	return 0;
}

//  #     #   ###     #           
//  #     #  #   #   ##           
//  #     # #     # # #           
//  ####### #     #   #           
//  #     # #     #   #           
//  #     #  #   #    #           
//  #     #   ###   #####         
                                
//   #####    ###     #    #####  
//  #     #  #   #   ##   #     # 
//        # #     # # #         # 
//   #####  #     #   #    #####  
//        # #     #   #         # 
//  #     #  #   #    #   #     # 
//   #####    ###   #####  #####  
                                
//  #     #                       
//   #   #    ##   #####          
//    # #    #  #  #    #         
//     #    #    # #    #         
//     #    ###### #####          
//     #    #    # #              
//     #    #    # #