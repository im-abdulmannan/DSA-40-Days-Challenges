#include <string>
using namespace std;

class MyHashTable
{
private:
    int size;
    string *keys;
    string *values;

public:
    MyHashTable(int size)
    {
        this->size = size;
        this->keys = new string[size];
        this->values = new string[size];
    }

    void add(string key, string value)
    {
        int index = get_hash(key);

        while (keys[index] != " " && keys[index] != key)
        {
            index = (index + 1) % size;
        }

        keys[index] = key;
        values[index] = value;
    }

    string get(string key)
    {
        int index = get_hash(key);

        while (keys[index] != " ")
        {
            if (keys[index] == key)
            {
                return values[index];
            }
            index = (index + 1) % size;
        }

        return " ";
    }

    int get_hash(string key)
    {
        int hash = 0;

        for (char c : key)
        {
            hash += (int)c;
        }

        return hash % size;
    }
};
