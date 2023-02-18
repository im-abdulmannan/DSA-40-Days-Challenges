#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *array = NULL;
    int size;
    int capacity;

public:
    DynamicArray()
    {
        size = 0;
        capacity = 1;
        array = new int[capacity];
    }

    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        array = new int[capacity];
        size = 0;
    }

    int getsize() { return size; }

    int getCapacity() { return capacity; }

    void insertValue(int value)
    {
        if (size == capacity)
        {
            growArray();
        }

        array[size] = value;
        size++;
    }

    void deleteValue()
    {
        array[size - 1] = 0;
        size--;

        if (size == (capacity / 2))
        {
            shrinkArray();
        }
    }

    void growArray()
    {
        int *temp = new int[capacity * 2];
        capacity = capacity * 2;

        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }

        delete[] array;
        array = temp;
    }

    void shrinkArray()
    {
        int *temp = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }

        delete[] array;
        array = temp;
    }

    void insertAtIndex(int index, int value)
    {
        if (size == capacity)
        {
            growArray();
        }

        for (int i = size - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }

        array[index] = value;
        size++;
    }

    void deleteAtIndex(int index)
    {
        for (int i = index; i < size; i++)
        {
            array[i] = array[i + 1];
        }

        array[size - 1] = 0;
        size--;

        if(size == (capacity / 2))
        {
            shrinkArray();
        }
    }
};