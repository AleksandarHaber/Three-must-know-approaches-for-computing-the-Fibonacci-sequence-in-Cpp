// this code implements three approaches for computing the Fibonacci sequence
// webpage tutorial explaining this code: 
// https://aleksandarhaber.com/three-must-know-methods-for-computing-fibonacci-sequences-in-c/
// Author: Aleksandar Haber 
// date: December 2022

#include<iostream>
#include<vector>
// this library is necessary for timing the code
#include <chrono>

using namespace std;
typedef unsigned long int uint;

// first approach - use pure recursion
uint fibonacciRecursion(uint n)
{
	if (n<2)
	{
		return n;
	}	
		return fibonacciRecursion(n-1)+fibonacciRecursion(n-2);
}

// second approach - use vectors

uint fibonacciVector(uint n)
{
	vector<uint> fibonacci;
	
	fibonacci.push_back(0);
	fibonacci.push_back(1);
	
	for (uint i=2; i<=n; i++)
	{
		fibonacci.push_back(fibonacci[i-1]+fibonacci[i-2]);
		
	}
	
	return fibonacci.back();
}


// third approach - use vectors, recursion, and memoization to optimize the code

const int NOT_INCLUDED=-999;
const int DIM=10000;
vector<int> memoizationVector(DIM,NOT_INCLUDED);

uint fibonacciMemoization(uint n)
{
	if (n<2)
	{ 
		return n;
	}
	if (memoizationVector[n]!=NOT_INCLUDED)
	{
		return memoizationVector[n];
	}
	else
	{
		unsigned int fibonacciVector_n=fibonacciMemoization(n-1)+fibonacciMemoization(n-2);
		memoizationVector[n]=fibonacciVector_n;
		return 	fibonacciVector_n;
	}
	
}

int main()
{
	uint n=30;
	
	clock_t startTime, endTime;
	
	// solution computed by using fibonacciRecursion(n)
	uint fibonacciRecursionResult;
	// solution computed by using fibonacciVector(n)
	uint fibonacciVectorResult;
	// solution computed by fibonacciMemoization(n)
	uint fibonacciMemoizationResult;
	 
	
	// declare everything here in order not to include time for reserving the memory space for variables
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	auto fibonacciRecursionResultTime=chrono::duration_cast<chrono::nanoseconds> (end-start).count();
	auto fibonacciVectorResultTime=chrono::duration_cast<chrono::nanoseconds> (end-start).count();
	auto fibonacciMemoizationResultTime=chrono::duration_cast<chrono::nanoseconds> (end-start).count();
	
	
	// compute the solution by using the fibonacciRecursion(n)
	start = chrono::steady_clock::now();
	fibonacciRecursionResult = fibonacciRecursion(n);
	end = chrono::steady_clock::now();
	fibonacciRecursionResultTime=chrono::duration_cast<chrono::nanoseconds> (end-start).count();
	
	
	// compute the solution by using the fibonacciVector(n)
	start = chrono::steady_clock::now();
	fibonacciVectorResult = fibonacciVector(n);
	end = chrono::steady_clock::now();
	fibonacciVectorResultTime=chrono::duration_cast<chrono::nanoseconds> (end-start).count();
		
	// compute the solution by using the fibonacciMemoization(n)
	start = chrono::steady_clock::now();
	fibonacciMemoizationResult = fibonacciMemoization(n);
	end = chrono::steady_clock::now();
	fibonacciMemoizationResultTime=chrono::duration_cast<chrono::nanoseconds> (end-start).count();
		
	
	
	cout<<"Fibonacci sequence of n="<<n<< " by using recursion is: "<<fibonacciRecursionResult<< ". Time: " << fibonacciRecursionResultTime  << " nanoseconds"<<endl;
	cout<<"Fibonacci sequence of n="<<n<< " by using vectors (STL) is: "<<fibonacciVectorResult<< ". Time: " << fibonacciVectorResultTime  << " nanoseconds"<<endl;
	cout<<"Fibonacci sequence of n="<<n<< " by using memoization is: "<<fibonacciMemoizationResult<< ". Time: " << fibonacciMemoizationResultTime  << " nanoseconds"<<endl;
	
/*	cout<<"Memoization vector entries are: "<<endl;
	vector<int>::iterator printIterator;
	for(printIterator=memoizationVector.begin();printIterator!=memoizationVector.begin();printIterator++)
	{
		cout<<*printIterator<<endl;		
	}
*/

}
