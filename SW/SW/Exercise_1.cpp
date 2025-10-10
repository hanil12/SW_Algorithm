#include <iostream>

using namespace std;

// 스무고개 만들기
// 1. 컴퓨터가 1~500까지 난수를 갖는다.
// 2. 사용자가 1~500까지의 수를 입력한다.
// 3. 이를 9번 안에 무조건 맞추는 방법은?
// 이진탐색
// 1 ^ 250 ^ 500 ...  * 1/2
// 250 ^ 375 ^ 500 ... * 1/2

// log2 500 
// => 시간복잡도 표기법(Big O)
// n개의 개수~~~
// 1. 상수 (배열의 인덱스접근)
// 2. logN (이진탐색)
// 3. N (배열 순회)
// 4. N * logN
// 5. N^2

int main()
{
	srand(time(nullptr)); // 현재시점부터 시작 => 씨드 심기
	
	// 어떤 시점에서 부터의 난수를 생성
	for (int i = 0; i < 10; i++)
	{
		cout << rand() << endl;
	}

	int aInt = 0;
	cin >> aInt;

	cout << aInt << endl;

	return 0;
}