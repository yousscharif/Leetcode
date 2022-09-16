#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

struct Entry
{
    int key;
    int value;
    Entry(int k, int v)
    {
        this->key = k;
        this->value = v;
    }
};

typedef list<Entry>::iterator iter;

class MyHashMap
{
public:
    int size = 1e4;
    int a = 7;
    vector<list<Entry> > hashMap;
    iter it;

    MyHashMap()
    {
        hashMap.resize(size); // initialize size
    }

    int hashCode(int key)
    {
        return a * key % size; // hash function
    }

    iter search(int key)
    {
        int idx = hashCode(key);
        list<Entry> &curr = hashMap[idx];
        for (it = curr.begin(); it != curr.end(); it++)
        {
            if (it->key == key)
            {
                return it;
            }
        }
        return it;
    }

    void put(int key, int value)
    {
        int idx = hashCode(key);
        list<Entry> &curr = hashMap[idx];
        it = search(key);
        if (it == curr.end())
        {
            curr.push_back(Entry(key, value));
        }
        else
        {
            it->value = value;
        }
    }

    int get(int key)
    {
        int idx = hashCode(key);
        list<Entry> &curr = hashMap[idx];
        it = search(key);
        if (it == curr.end())
        {
            return -1;
        }
        return it->value;
    }

    void remove(int key)
    {
        int idx = hashCode(key);
        list<Entry>& curr = hashMap[idx];
        it = search(key);
        if (it != curr.end()){
            curr.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    MyHashMap *obj = new MyHashMap();
    obj->put(1, 10);
    obj->put(2,20);
    obj->put(1,69);
    obj->remove(1);
    int param_2 = obj->get(1);
    cout << param_2;

}
