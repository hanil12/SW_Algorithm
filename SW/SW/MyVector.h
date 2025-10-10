#pragma once

template<typename T>
class MyVector
{
public:
    class iterator
    {
    public:
        iterator() : _data(nullptr) {}
        iterator(T* data) : _data(data) {}
        ~iterator() {}

        bool operator==(const iterator& other)
        {
            return _data == other._data;
        }

        bool operator!=(const iterator& other)
        {
            return !this->operator==(other);
        }

        iterator& operator++()
        {
            _data++;
            return *this;
        }

        iterator operator++(int)
        {
            iterator result;
            result = *this;
            
            _data++;

            return result;
        }

        T& operator*()
        {
            return *_data;
        }

    private:
        T* _data;
    };

public:
    MyVector() : _data(nullptr), _capacity(0), _size(0) {}
    ~MyVector()
    {
        if (_data != nullptr)
            delete[] _data;
    }

    void reserve(unsigned int newCapacity)
    {
        T* _new_data;
        _new_data = new T[newCapacity];

        for (int i = 0; i < _capacity; i++)
            _new_data[i] = _data[i];

        if (_data != nullptr)
            delete[] _data;

        _data = _new_data;
        _capacity = newCapacity;

    }

    void push_back(const T& value)
    {
        unsigned int _new_cap;
        T* _new_data;

        if (_size == _capacity)
        {
            _new_cap = (_capacity == 0) ? 1 : (2 * _capacity);
            _new_data = new T[_new_cap];

            for (int i = 0; i < _capacity; i++)
                _new_data[i] = _data[i];

            if (_data != nullptr)
                delete[] _data;

            _data = _new_data;

            _data[_size] = value;
            _capacity = _new_cap;
            _size++;
        }
        else
        {
            _data[_size] = value;
            _size++;
        }
    }

    void pop_back()
    {
        _size--;
    }

    T& operator[](unsigned int index)
    {

        return *(_data + index);
    }

    unsigned int size() { return _size; }
    unsigned int capacity() { return _capacity; }

    MyVector::iterator begin() { return MyVector::iterator(_data); }
    MyVector::iterator end() { return MyVector::iterator(_data + _size); }

private:
    T* _data;
    unsigned int _size;
    unsigned int _capacity;
};