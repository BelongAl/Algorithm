#include<iostream>
#include"sort.h"

int main()
{
	std::vector<int> test1{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> test2{ 9,8,7,6,5,4,3,2,1 };	
	std::vector<int> test3{ 3,8,1,4,0,2,76,3,6,23,44,67};

	Sort s;
	std::cout << "bubble sort------------" << std::endl;
	s.BubbleSort(test1);
	s.BubbleSort(test2);
	s.BubbleSort(test3);
	std::cout << "quick sort------------- " << std::endl;
	s.QuickSort(test1);
	s.QuickSort(test2);
	s.QuickSort(test3);
	std::cout << "non-recursion quick sort--- " << std::endl;
	s.QuickSort(test1);
	s.QuickSort(test2);
	s.QuickSort(test3);
	std::cout << "insert sort------------ " << std::endl;
	s.InsertSort(test1);
	s.InsertSort(test2);
	s.InsertSort(test3);
	std::cout << "shell sort------------- " << std::endl;
	s.ShellSort(test1);
	s.ShellSort(test2);
	s.ShellSort(test3);
	std::cout << "select sort------------ " << std::endl;
	s.SlectSort(test1);
	s.SlectSort(test2);
	s.SlectSort(test3);
	std::cout << "heap sort-------------- " << std::endl;
	s.HeapSort(test1);
	s.HeapSort(test2);
	s.HeapSort(test3);
	std::cout << "merge sort------------- " << std::endl;
	s.MergeSort(test1);
	s.MergeSort(test2);
	s.MergeSort(test3);
	std::cout << "bucket sort------------ " << std::endl;
	s.BucketSort(test1);
	s.BucketSort(test2);
	s.BucketSort(test3);
	std::cout << "stdradix sort---------- " << std::endl;
	s.StdradixSort(test1);
	s.StdradixSort(test2);
	s.StdradixSort(test3);
	std::cout << "non-recursive quick sort " << std::endl;
	s.NRqucikSort(test1);
	s.NRqucikSort(test2);
	s.NRqucikSort(test3);
	system("pause");
	return 0;
}