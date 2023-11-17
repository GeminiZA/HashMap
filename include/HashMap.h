#ifndef HASHMAP_H
#define HASHMAP_H

#include <KeyList.h>
#include <vector>
#include <string>
#include <typeinfo>
#include <sstream>
#include <list>

template <typename KeyType, typename ValueType>
class HashMap
{
private:
    size_t cap = 1;
    KeyList<KeyType, ValueType> *map;
    size_t size;
    size_t hash(const KeyType &key, const size_t max)
    {
        return static_cast<size_t>(key) % max;
    }
    void resize()
    {
        if (size / cap > 0.9)
        {
            size_t new_cap = (cap + 1) * 2 - 1;
            KeyList<KeyType, ValueType> *temp = new KeyList<KeyType, ValueType>[new_cap];
            for (int i = 0; i < new_cap; i++)
            {
                temp[i] = KeyList<KeyType, ValueType>();
            }
            for (int i = 0; i < cap; i++)
            {
                while (!map[i].isEmpty())
                {
                    KeyType key = map[i].first_key();
                    ValueType val = map[i].get(key);
                    size_t pos = hash(key, new_cap);
                    temp[pos].set(key, val);
                    map[i].remove(key);
                }
            }
            delete[] map;
            map = temp;
            cap = new_cap;
        }
    }

public:
    HashMap()
    {
        size = 0;
        map = new KeyList<KeyType, ValueType>[1023];
        for (int i = 0; i < cap; i++)
        {
            map[i] = KeyList<KeyType, ValueType>();
        }
    }
    ~HashMap()
    {
        delete[] map;
    }
    void remove(const KeyType &key)
    {
        size_t i = hash(key, cap);
        map[i].remove(key);
    }
    void set(const KeyType &key, const ValueType &val)
    {
        size_t i = hash(key, cap);
        if (!map[i].contains(key))
        {
            map[i].set(key, val);
            ++size;
            resize();
        }
        else
        {
            map[i].set(key, val);
        }
    }
    ValueType get(const KeyType &key)
    {
        size_t i = hash(key, cap);
        KeyList<KeyType, ValueType> *curlist = &map[i];
        return curlist->get(key);
    }
    std::string toString()
    {
        std::stringstream ss;
        ss << "{" << std::endl;
        for (int i = 0; i < cap; i++)
        {
            if (map[i].size() > 0)
            {
                KeyType key = map[i].first_key();
                ValueType val = map[i].get(key);
                ss << "\t" << key << ": " << val << "," << std::endl;
            }
        }
        ss << "}";
        return ss.str();
    }
};

template <typename ValueType>
class HashMap<std::string, ValueType>
{
private:
};

#endif