#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>

class Dynarray
{
    int *m_storage;
    std::size_t m_length;

public:
    using size_type = std::size_t;
    using value_type = int;
    using pointer = int *;
    using reference = int &;
    using const_pointer = const int *;
    using const_reference = const int &;
    static const size_type npos = static_cast<std::size_t>(-1);

    // Dynarray a;
    Dynarray() : m_storage(nullptr), m_length(0) {}

    // Dynarray a(n);
    explicit Dynarray(size_type n) : m_storage(new value_type[n]), m_length(n)
    {
        for (size_type i = 0; i != m_length; ++i)
        {
            m_storage[i] = 0;
        }
    }

    // Dynarray a(n, x);
    Dynarray(size_type n, value_type x) : m_storage(new value_type[n]), m_length(n)
    {
        for (size_type i = 0; i != m_length; ++i)
        {
            m_storage[i] = x;
        }
    }

    // Dynarray a(begin, end);
    Dynarray(const_pointer begin, const_pointer end) : m_storage(new value_type[end - begin]), m_length(end - begin)
    {
        for (size_type i = 0; i != m_length; ++i)
        {
            m_storage[i] = *(begin + i);
        }
    }

    Dynarray(const Dynarray &other) // copy constructor
        : m_storage(new value_type[other.m_length]), m_length(other.m_length)
    {
        for (size_type i = 0; i != other.size(); ++i)
        {
            m_storage[i] = other.at(i);
        }
    }

    Dynarray(Dynarray &&other) noexcept // move constructor
        : m_storage(other.m_storage), m_length(other.m_length)
    {
        other.m_storage = nullptr;
        other.m_length = 0;
    }

    Dynarray &operator=(const Dynarray &other) // copy assignment operator
    {
        if (this != &other)
        {
            pointer new_storage = new value_type[other.size()];
            try
            {
                for (size_type i = 0; i != other.size(); ++i)
                {
                    new_storage[i] = other.at(i);
                }
            }
            catch (...)
            {
                delete[] new_storage;
                throw;
            }

            delete[] m_storage;
            m_storage = new_storage;
            m_length = other.size();
        }
        return *this;
    }

    Dynarray &operator=(Dynarray &&other) noexcept // move assignment operator
    {
        if (this != &other)
        {
            delete[] m_storage;
            m_storage = other.m_storage;
            m_length = other.m_length;
            other.m_storage = nullptr;
            other.m_length = 0;
        }
        return *this;
    }

    int &operator[](size_type n) // subscript operator
    {
        return m_storage[n];
    }

    const int &operator[](size_type n) const
    {
        return m_storage[n];
    }

    // Relational operators
    friend bool operator==(const Dynarray &, const Dynarray &); // ==
    friend bool operator!=(const Dynarray &, const Dynarray &); // !=
    friend bool operator<(const Dynarray &, const Dynarray &);  // <
    friend bool operator>(const Dynarray &, const Dynarray &);  // >
    friend bool operator<=(const Dynarray &, const Dynarray &); // <=
    friend bool operator>=(const Dynarray &, const Dynarray &); // >=

    // Output operator
    friend std::ostream &operator<<(std::ostream &, const Dynarray &); // <<

    // Destructor
    ~Dynarray()
    {
        delete[] m_storage;
    }

    // a.size()
    size_type size() const
    {
        return m_length;
    }

    // a.empty()
    bool empty() const
    {
        return m_length == 0;
    }

    // a.at(n) both readable and modifiable
    reference at(size_type n)
    {
        if (n >= m_length)
        {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        else
        {
            return m_storage[n];
        }
    }

    // a.at(n) read-only
    const_reference at(size_type n) const
    {
        if (n >= m_length)
        {
            throw std::out_of_range{"Dynarray index out of range!"};
        }
        else
        {
            return m_storage[n];
        }
    }

    // a.find(x)
    size_type find(value_type x) const
    {
        for (size_type i = 0; i < m_length; ++i)
        {
            if (m_storage[i] == x)
            {
                return i;
            }
        }
        return npos;
    }

    // a.find(x, pos)
    size_type find(value_type x, size_type pos) const
    {
        for (size_type i = pos; i < m_length; ++i)
        {
            if (m_storage[i] == x)
            {
                return i;
            }
        }
        return npos;
    }
};

// ==
bool operator==(const Dynarray &lhs, const Dynarray &rhs)
{
    if (lhs.m_length != rhs.m_length)
    {
        return false;
    }
    else
    {
        for (std::size_t i = 0; i != lhs.m_length; ++i)
        {
            if (lhs[i] != rhs[i])
            {
                return false;
            }
        }
    }
    return true;
}

// !=
bool operator!=(const Dynarray &lhs, const Dynarray &rhs)
{
    return !(lhs == rhs);
}

// <
bool operator<(const Dynarray &lhs, const Dynarray &rhs)
{
    if (lhs.m_length < rhs.m_length)
    {
        for (std::size_t i = 0; i != lhs.m_length; ++i)
        {
            if (lhs[i] < rhs[i])
            {
                return true;
            }
            else if (lhs[i] > rhs[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        for (std::size_t i = 0; i != rhs.m_length; ++i)
        {
            if (lhs[i] < rhs[i])
            {
                return true;
            }
            else if (lhs[i] > rhs[i])
            {
                return false;
            }
        }
        return false;
    }
}

// >
bool operator>(const Dynarray &lhs, const Dynarray &rhs)
{
    return !((lhs == rhs) || (lhs < rhs));
}

// <=
bool operator<=(const Dynarray &lhs, const Dynarray &rhs)
{
    return !(lhs > rhs);
}

// >=
bool operator>=(const Dynarray &lhs, const Dynarray &rhs)
{
    return !(lhs < rhs);
}

// <<
std::ostream &operator<<(std::ostream &os, const Dynarray &d)
{
    if (d.empty())
    {
        return os << "[]";
    }
    else
    {
        os << '[' << d[0];
        for (std::size_t i = 1; i != d.m_length; ++i)
        {
            os << ", " << d[i];
        }
        os << ']';
    }
    return os;
}

#endif // DYNARRAY_HPP