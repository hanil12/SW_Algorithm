#pragma once

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

class MyList
{
public:
	MyList()
		: _size(0)
	{
		_head = new Node{ 0, nullptr, nullptr };
		_head->next = _head;
		_head->prev = _head;

	}

	~MyList() { while (!_size) pop_back(); }

	void push_back(const int& value)
	{
		Node* _new_data = new Node{ value, _head, _head->prev };
		(_head->prev)->next = _new_data;
		_head->prev = _new_data;
		_size++;
	}

	void push_front(const int& value)
	{
		Node* _new_data = new Node{ value, _head->next, _head };
		(_head->next)->prev = _new_data;
		_head->next = _new_data;
		_size++;
	}

	void pop_back()
	{
		if (_size > 0) {
			Node* tail = _head->prev;
			(tail->prev)->next = _head;
			_head->prev = _head->prev->prev;
			delete tail;
			_size--;
		}
	}

	void pop_front()
	{
		if (_size > 0) {
			Node* first = _head->next;
			_head->next = first->next;
			first->next->prev = _head;
			delete first;
			_size--;
		}
	}

	// before는 삽입위치, value는 새로운 데이터
	void insert(Node* before, const int& value)
	{
		Node* p = new Node{ value, before->next, before };
		before->next = p;
		p->next->prev = p;
		_size++;
	}

	Node* at(unsigned int index)
	{
		Node* tmp = _head->next;
		for (int i = 0; i < index; i++)
			tmp = tmp->next;

		return tmp;
	}

	int& operator[](unsigned int index)
	{
		Node* tmp = _head->next;
		for (int i = 0; i < index; i++)
			tmp = tmp->next;

		return tmp->data;
	}

	unsigned int size() { return _size; }

private:
	Node* _head;
	unsigned int _size;
};