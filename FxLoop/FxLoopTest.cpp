#include "FxLoop.h"
#include <omp.h> // Include OpenMP

//////////////////////////////////////////////////////////////////////
//
// Compile options needed: /GX
//
//    Opless.cpp -- Illustrates the defining the < operator to sort vectors
//
// Functions:
//
//    operator< - Vector comparison operator.
//
//    vector::begin - Returns an iterator to start traversal of the vector.
//
//    vector::end - Returns an iterator for the last element of the vector.
//
//    vector::iterator - Traverses the vector.
//
//    vector::push_back - Appends (inserts) an element to the end of a
//                        vector, allocating memory for it if necessary.
//
//    sort algorithm - Sorts the vector.
//
// Written by Tom Campbell
// of Microsoft Corporation
// Copyright (c) 1996 Microsoft Corporation. All rights reserved.
//////////////////////////////////////////////////////////////////////

// The debugger can't handle symbols more than 255 characters long.
// STL often creates symbols longer than that.
// When symbols are longer than 255 characters, the warning is disabled.
#pragma warning(disable:4786)

#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
using namespace std;


//bool HasNotReachedUpperBound (FxLoop& _myFxLoop) {
//	bool bTest;
//	bTest = _myFxLoop.HasNotReachedUpperbound();
//	return bTest;
//}


int analyze(vector<FxLoop>& _MyFxLoops) {
	vector<FxLoop>::iterator myFxLoopsIter;
	
	FxLoop myFxLoop;

//    for (
//			myFxLoopsIter =  _MyFxLoops.begin(); 
//			myFxLoopsIter != _MyFxLoops.end(); 
//			myFxLoopsIter++) 
//	{
			//cout << myFxLoopsIter->NumberOfSteps  << "\t"
			//	 << myFxLoopsIter->iCurrentValue  << "\t"
			//	 << myFxLoopsIter->Name << endl;
//    }
    cout << "work" << endl;

	return 0;
}


// FxLoops will be sorted by NumberOfSteps, not by Name.
bool operator<(const FxLoop& x, const FxLoop& y)
{
    return x.NumberOfSteps < y.NumberOfSteps;

	// Problem child
    //return x.GetNumberOfSteps() < y.GetNumberOfSteps();
}


// FxLoops will be sorted by NumberOfSteps, not by Name.
bool operator==(const FxLoop& x, const FxLoop& y)
{
    return x.NumberOfSteps == y.NumberOfSteps;
}

void TestParallel()
{
   float sum = 0.0f;
   int i;
   int count = 200;
   #pragma omp parallel
   {
      #pragma omp for lastprivate(i) reduction(+: sum) 
      for (i = 0; i < count; ++i) 
      {
         sum += 1;
         int j = omp_get_thread_num();
         printf_s("Thread:  %d, Sum:  %f\n", j, sum);
      }
   }

   printf_s("Sum:  %f\n", sum);
}

// Define a template class for a vector of FxLoops.
typedef vector<FxLoop, allocator<FxLoop> > NAMEVECTOR;


void TP2()
{

   // Declare a dynamically allocated vector of FxLoops.
   NAMEVECTOR myFxLoops;

   // Create a pseudo-random vector of players and NumberOfStepss.
   myFxLoops.push_back(FxLoop(0, 1, 1, "Karen Palmer"));
   myFxLoops.push_back(FxLoop(0, 2, 1, "Ada Campbell"));

   unsigned int totalSteps = 1;

   //#pragma omp parallel reduction(*: totalSteps)
   {

      // Iterator is used to loop through the vector.
      NAMEVECTOR::iterator theIterator2;

      int i;
      int Size = myFxLoops.size();

      theIterator2 = myFxLoops.begin();
      #pragma omp for
      for (i=0; i<Size; i++)
      {
         {
            int j = omp_get_thread_num();
            int steps = theIterator2->GetNumberOfSteps();
            totalSteps *= steps;
            printf_s("__Thread:  %d, Steps:  %d\n", j, steps);
         }
         theIterator2++;
      }

      // This is apparently what it takes:  have the omp for within an omp parallel!!
      #pragma omp parallel
      {
         #pragma omp for
         for (i=0; i<totalSteps; i++)
         {
            analyze(myFxLoops);
            int j = omp_get_thread_num();
            printf_s("__Thread:  %d\n", j);
         }
      }

   }
   printf_s("Total Steps:  %d", totalSteps);







   printf_s("\nEnd TP2\n");
}

void MyAnalyze(int i, int j)
{
   int k = i + j;
   printf_s("i = %d, j = %d, k = %d\n", i, j, k);
}

void MyMethod( FxLoop &firstLoop, FxLoop &secondLoop ) 
{
   #pragma omp parallel
   {
      #pragma omp for
	   for (int i=firstLoop.iStart; i<firstLoop.iStop; i+=firstLoop.iStep)
	   {
	      for (int j=secondLoop.iStart; j<secondLoop.iStop; j+=secondLoop.iStep)
	      {
	         MyAnalyze(i, j);
	      }
	   }
   }
}

void MyTest()
{
   FxLoop firstLoop(1, 10, 1, "First");
   FxLoop secondLoop(1, 5, 1, "Second");

   MyMethod(firstLoop, secondLoop);
}

void MyMethod2( FxLoop &firstLoop, FxLoop &secondLoop ) 
{
   #pragma omp parallel for  // This is shorthand notation.
   for (int i=firstLoop.iStart; i<firstLoop.iStop; i+=firstLoop.iStep)
   {
      for (int j=secondLoop.iStart; j<secondLoop.iStop; j+=secondLoop.iStep)
      {
         MyAnalyze(i, j);
      }
   }
   // Is there a simple way to get data back out?  Like the reduction clause?  Can the data be summed, etc. to a class variable?
}

void MyTest2()
{
   FxLoop firstLoop(1, 10, 1, "First");
   FxLoop secondLoop(1, 5, 1, "Second");

   MyMethod2(firstLoop, secondLoop);
}

void MSTest()
{
   #pragma omp parallel for  // This is shorthand notation.
   for (int i=1; i<6; i++)
   {
      cout << "Hello World!\n";
   }
}

void main()
{

   //MyTest();  // Long version
   MyTest2();   // Shorthand version 
   MSTest();   // For Microsoft

}

void main2()
{
   //TestParallel();

   TP2();

   // Declare a dynamically allocated vector of FxLoops.
   NAMEVECTOR myFxLoops;

   // Create a pseudo-random vector of players and NumberOfStepss.
   myFxLoops.push_back(FxLoop(0, 1, 1, "Karen Palmer"));
   myFxLoops.push_back(FxLoop(0, 2, 1, "Ada Campbell"));

   unsigned int totalSteps = 1;

   //#pragma omp parallel reduction(*: totalSteps)
   {

      // Iterator is used to loop through the vector.
      NAMEVECTOR::iterator theIterator2;

      int i;
      int Size = myFxLoops.size();

      theIterator2 = myFxLoops.begin();
      #pragma omp for
      for (i=0; i<Size; i++)
      {
         {
            int j = omp_get_thread_num();
            int steps = theIterator2->GetNumberOfSteps();
            totalSteps *= steps;
            printf_s("Thread:  %d, Steps:  %d\n", j, steps);
         }
         theIterator2++;
      }

   }
   printf_s("Total Steps:  %d", totalSteps);
   printf_s("\n\nNext OMP");

   #pragma omp parallel num_threads(4)
   {

      // Iterator is used to loop through the vector.
      NAMEVECTOR::iterator theIterator2;

      unsigned int i;

      for (i=0, theIterator2 = myFxLoops.begin(); i<myFxLoops.size(); i++, theIterator2++)
      {
         //#pragma omp single  // Block to be executed by only one thread.  It works.
         {
            // This cout does work.
            //cout << theIterator2->NumberOfSteps  << "\t" << theIterator2->GetNumberOfSteps() << endl;
            analyze(myFxLoops);
            int j = omp_get_thread_num();
            printf_s("ParallelTest: Hello from thread %d, %d\n", j, theIterator2->GetNumberOfSteps());
         }
      }

   }

}
