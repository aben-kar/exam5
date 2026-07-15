#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
private:
    searchable_bag &bag;

public:
    set(searchable_bag &other);
    set(const set &other);
    set &operator=(const set &other);
    ~set();

    bool has(int val) const;
    void insert(int val);
    void insert(int *arr, int size);
    void print() const;
    void clear();
    const searchable_bag &get_bag() const;
};

#endif

private:
    searchable &bag;
public:
    bool has(int val) const;
    void insert(int val);
    void insert(int *arr, int size);
    void print() const;
    void clear();
    const searchable_bag &getBag() const;



bool has(int val) const
{
    return bag.has(val);
}

void insert(int val)
{
    if (!bag.has(val))
        bag.insert(val);
}

void insert(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        insert(arr[i])
}

void print() const
{
    return bag.print();
}

void clear()
{
    return bag.clear();
}

const &Nameclass::nameclass () const    
    return bag;
