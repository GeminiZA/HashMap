#ifndef KEYLIST_H
#define KEYLIST_H

#include <string>
#include <sstream>
#include <list>
#include <exception>

class ElementNotFoundException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Element not found in list";
    }
};

template <typename KeyType, typename ValueType>
class KeyList
{
private:
    std::list<std::pair<KeyType, ValueType>> list;

public:
    KeyList()
    {
        this->list = std::list<std::pair<KeyType, ValueType>>();
    }
    void set(const KeyType &key, const ValueType &val)
    {
        for (auto iter = this->list.begin(); iter != this->list.end(); ++iter)
        {
            if (iter->first == key)
            {
                iter->second = val;
                return;
            }
        }
        this->list.push_back(std::pair<KeyType, ValueType>(key, val));
    }
    KeyType first_key()
    {
        return list.front().first;
    }
    ValueType get(const KeyType &key)
    {
        for (auto iter = this->list.begin(); iter != this->list.end(); ++iter)
        {
            if (iter->first == key)
            {
                return iter->second;
            }
        }
        throw ElementNotFoundException();
    }
    bool contains(const KeyType &key)
    {
        for (auto iter = this->list.begin(); iter != this->list.end(); ++iter)
        {
            if (iter->first == key)
            {
                return true;
            }
        }
        return false;
    }
    void remove(const KeyType &key)
    {
        for (auto iter = this->list.begin(); iter != this->list.end(); ++iter)
        {
            if (iter->first == key)
            {
                this->list.erase(iter);
                return;
            }
        }
    }
    bool isEmpty()
    {
        return this->list.size() == 0;
    }
    size_t size()
    {
        return this->list.size();
    }
    std::string toString()
    {
        std::stringstream out;
        if (this->list.size() == 0)
            return "[]";
        out << "[";
        auto iter = this->list.begin();
        out << "<" << iter->first << ", " << iter->second << '>';
        for (++iter; iter != this->list.end(); ++iter)
        {
            out << ", <" << iter->first << ", " << iter->second << '>';
        }
        out << "]";
        return out.str();
    }
};

#endif