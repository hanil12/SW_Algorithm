#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬
// 순차, 선택, 삽입, 버블 : n^2
// heap sort, quick sort, merge sort : n x logn

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIndex = left;
	int rightIndex = mid + 1;

	vector<int> temp;
}

void MergeSort(vector<int>& v, int left, int right)
{
	// 기저
	if(left >= right)
		return;

	int mid = (left + right) / 2;

	// 분할정복

	// Divide
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	// Conquer
	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v = { 55,30,15,100,1,5,70 };

	std::stable_sort(v.begin(), v.end()); // merge sort
	std::partial_sort(v.begin(), v.begin() + 3, v.end()); // heap sort
	std::sort(v.begin(), v.end());

	return 0;
}