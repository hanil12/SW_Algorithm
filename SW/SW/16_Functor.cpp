#include <iostream>

using namespace std;

// 함수 객체
// => 함수가 속성을 가질 수 있다.
struct Functor
{
	void operator()() // () 함수연산자 오버로딩
	{
		cout << a << endl;
		cout << "Hello World!" << endl;
	}

	int a;
};

struct Item
{
	void PrintItem()
	{
		cout << "ID : " << id << endl;
		cout << "PRICE : " << price << endl;
		cout << "TIER : " << tier << endl;
	}

	int id;
	int price;
	int tier;
};

// id가 5 Item 반환
Item* FindItem(Item items[], int size, int id)
{
	for (int i = 0; i < size; i++)
	{
		if(items[i].id == id)
			return &items[i];
	}

	return nullptr;
}

bool CheckID(Item* item)
{
	if(item->id == 3)
		return true;
	return false;
}

bool CheckPrice(Item* item)
{
	if(item->price == 300)
		return true;
	return false;
}

Item* FindItem_FuncPtr(Item items[], int size, bool(*fn)(Item* item))
{
	for (int i = 0; i < size; i++)
	{
		if (fn(&items[i]))
			return &items[i];
	}

	return nullptr;
}

// 함수 오버로딩을 사용하여
// Price로만 찾는 버전(Find함수, Functor 구현)

// Price, id 찾는 버전(Find함수, Functor 구현)

struct Functor_ItemID
{
	bool operator()(Item* item)
	{
		if(item->id == id)
			return true;
		return false;
	}

	int id;
};

struct Functor_ItemPrice
{
	bool operator()(Item* item)
	{
		if (item->price == price)
			return true;
		return false;
	}

	int price;
};

template<typename T>
Item* FindItem_Functor(Item items[], int size, T functor)
{
	for (int i = 0; i < size; i++)
	{
		if (functor(&items[i]))
			return &items[i];
	}

	return nullptr;
}

int main()
{
#pragma region 함수객체
	Functor functor;
	
	functor.a = 1;
	//functor();

	functor.a = 2;
	//functor();
#pragma endregion

	Item items[10];

	for (int i = 0; i < 10; i++)
	{
		items[i].id = i;
		items[i].price = 100 * i;
		items[i].tier = 10 - i;
	}

	Item* item = FindItem(items, 10, 5);
	if (item != nullptr)
	{
		item->PrintItem();
	}
	item = nullptr;

	item = FindItem_FuncPtr(items, 10, CheckPrice);
	if (item != nullptr)
	{
		item->PrintItem();
	}
	item = nullptr;

	// id가 2인 얘 찾기
	Functor_ItemID comparer;
	comparer.id = 2;
	item = FindItem_Functor<Functor_ItemID>(items, 10, comparer);
	item->PrintItem();

	// id가 3인 얘 찾기
	comparer.id = 3;
	item = FindItem_Functor<Functor_ItemID>(items, 10, comparer);
	item->PrintItem();

	Functor_ItemPrice comparer2;
	comparer2.price = 700;
	item = FindItem_Functor<Functor_ItemPrice>(items, 10, comparer2);
	item->PrintItem();

	return 0;
}