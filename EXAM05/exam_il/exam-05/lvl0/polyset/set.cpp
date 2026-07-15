#include "set.hpp"

set::set(searchable_bag &other) : bag(other)
{
}

set::set(const set &other) : bag(other.bag)
{
}

set &set::operator=(const set &other)
{
    if (this != &other)
        bag = other.bag;
    return *this;
}

set::~set()
{
}

bool set::has(int val) const
{
    return bag.has(val);
}

void set::insert(int val)
{
    if (!bag.has(val))
        bag.insert(val);
}

void set::insert(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        insert(arr[i]);
}

void set::print() const
{
    bag.print();
}

void set::clear()
{
    bag.clear();
}

const searchable_bag &set::get_bag() const
{
    return bag;
}