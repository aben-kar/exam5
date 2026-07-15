#pragma once

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
        const searchable_bag &getBag() const;
};