#include <iostream>
#include <random>
using namespace std;


void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Lotto();
void Sort(int arr[], int size);
void SelectSort(int arr[], int size);
void BubbleSort(int arr[], int size);
bool find(int arr[], int size, int num);
void Shuffle(int arr[], int size, int count);

void Lotto()
{
    int arr[45] = {};
    for (int i = 0; i < 45; i++)
    {
        arr[i] = i + 1;
    }

    Shuffle(arr, 45, 10000);

    BubbleSort(arr, 7);

    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
}

void Shuffle(int arr[], int size, int count)
{
    for (int i = 0; i < count; i++)
    {
        int left = rand() % size;
        int right = rand() % size;

        Swap(arr[left], arr[right]);
    }
}

// 구현
// 순차정렬 : 시간복잡도 n^2
// [5][4][3][2][1] 
// [4][5][3][2][1] -> Swap
// [3][5][4][2][1] -> Swap
void Sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}

// 선택정렬 : best를 찾으면 그 때 스왑 => 시간복잡도 n^2
// [5][4][3][2][1] : best 0
// [5][4][3][2][1] : best 1
// [5][4][3][2][1] : best 2
// [5][4][3][2][1] : best 3
// [5][4][3][2][1] : best 4 -> Swap
// [1][4][3][2][5]
void SelectSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int best = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[j] < arr[best])
            {
                best = j;
            }
        }

        if (i != best)
        {
            Swap(arr[i], arr[best]);
        }
    }
}

// 버블정렬 : n^2
// [5][4][3][2][1] -> Swap
// [4][5][3][2][1] -> Swap
// [4][3][5][2][1] -> Swap
// [4][3][2][5][1] -> Swap
// [3][2][1]   [4][5]
void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr[j], arr[j+1]);
            }
        }
    }
}

bool find(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == num)
            return true;
    return false;
}

int main()
{
    Lotto();

    return 0;
}