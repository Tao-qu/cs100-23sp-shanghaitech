#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP 1

#include <cstddef>
#include <stdexcept>

class Dynarray
{
    int *m_storage;
    std::size_t m_length;

public:
    // Dynarray a;
    Dynarray() : m_storage(nullptr), m_length(0) {}

    // Dynarray a(n);
    explicit Dynarray(std::size_t n) : m_storage(new int[n]), m_length(n)
    {
        for (std::size_t i = 0; i != m_length; i++)
        {
            m_storage[i] = 0;
        }
    }

    // Dynarray a(n, x);
    Dynarray(std::size_t n, int x) : m_storage(new int[n]), m_length(n)
    {
        for (std::size_t i = 0; i != m_length; i++)
        {
            m_storage[i] = x;
        }
    }

    // Dynarray a(begin, end);
    Dynarray(const int *begin, const int *end) : m_storage(new int[end - begin]), m_length(end - begin)
    {
        for (std::size_t i = 0; i != m_length; i++)
        {
            m_storage[i] = *(begin + i);
        }
    }

    // Dynarray b = a;
    Dynarray(const Dynarray &other) : m_storage(new int[other.m_length]), m_length(other.m_length)
    {
        for (std::size_t i = 0; i != other.size(); i++)
        {
            m_storage[i] = other.at(i);
        }
    }

    // b = a
    Dynarray &operator=(const Dynarray &other)
    {
        if (this == &other)
        {
            return *this;
        }

        int *new_storage = new int[other.size()];
        try
        {
            for (std::size_t i = 0; i != other.size(); ++i)
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
        return *this;
    }

    // Destructor
    ~Dynarray()
    {
        delete[] m_storage;
    }

    // a.size()
    std::size_t size() const
    {
        return m_length;
    }

    // a.empty()
    bool empty() const
    {
        return m_length == 0;
    }

    // a.at(n) both readable and modifiable
    int &at(std::size_t n)
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
    const int &at(std::size_t n) const
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
};

#endif // DYNARRAY_HPP