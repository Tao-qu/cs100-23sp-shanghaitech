#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>

class Polynomial
{
  // `m_coeffs` stores the coefficients.
  // Note: This is not the unique correct implementation.
  // For example, you may separate the constant term from others,
  // and store the constant term using another variable.
  std::vector<double> m_coeffs;

  static auto isZero(double x)
  {
    static constexpr auto eps = 1e-8;
    return x < eps && -x < eps;
  }

  // Remove trailing zeros, to ensure that the coefficient of the term with
  // the highest order is non-zero.
  // Note that a polynomial should have at least one term, which is the
  // constant. It should not be removed even if it is zero.
  // If m_coeffs is empty, adjust() should also insert a zero into m_coeffs.
  void adjust()
  {
    // YOUR CODE HERE
    if (m_coeffs.empty())
    {
      // If m_coeffs is empty, adjust() should also insert a zero into m_coeffs.
      m_coeffs.push_back(0.0);
    }
    else
    {
      // Remove trailing zeros.
      while (m_coeffs.size() > 1 && isZero(m_coeffs.back()))
      {
        m_coeffs.pop_back();
      }
    }
  }

  // Other members ...
  // Arithmetic operations
  // unary negation operator
  friend Polynomial operator-(const Polynomial &p)
  {
    std::vector<double> ans = {};
    for (int i = 0; i <= p.deg(); ++i)
    {
      ans.push_back(-p[i]);
    }
    return Polynomial(ans);
  }

public:
  // Constructors
  // Default constructor
  Polynomial() : m_coeffs({0.0}) {}

  // Copy constructor
  Polynomial(const Polynomial &other)
      : m_coeffs(other.m_coeffs) {}

  // Move constructor
  Polynomial(Polynomial &&other)
      : m_coeffs(std::move(other.m_coeffs))
  {
    other.m_coeffs = {0.0};
  }

  // Construct from a pair of InputIterators
  template <typename InputIterator>
  Polynomial(InputIterator begin, InputIterator end)
      : m_coeffs(begin, end) { adjust(); }

  // Construct from a const std::vector<double>
  explicit Polynomial(const std::vector<double> &coeffs)
      : m_coeffs(coeffs) { adjust(); }

  // Construct from a non-const rvalue
  explicit Polynomial(std::vector<double> &&coeffs)
      : m_coeffs(std::move(coeffs)) { adjust(); }

  // Operator overloading
  // Copy assignment operator
  Polynomial &operator=(const Polynomial &other)
  {
    if (this != &other)
    {
      m_coeffs = other.m_coeffs;
    }
    return *this;
  }

  // Move assignment operator
  Polynomial &operator=(Polynomial &&other) noexcept
  {
    if (this != &other)
    {
      m_coeffs = std::move(other.m_coeffs);
    }
    return *this;
  }

  // Subscript operator
  // operator[]
  const double &operator[](int i) const
  {
    return m_coeffs[i];
  }

  // Relational operators
  // operator==
  bool operator==(const Polynomial &other) const
  {
    if (deg() != other.deg())
    {
      return false;
    }
    for (int i = 0; i <= deg(); ++i)
    {
      if (!isZero(m_coeffs[i] - other[i]))
      {
        return false;
      }
    }
    return true;
  }

  // operator!=
  bool operator!=(const Polynomial &other) const
  {
    return !(*this == other);
  }

  // Evaluation
  // operator()
  double operator()(double x) const
  {
    double ans = 0;
    double xp_i = 1;
    for (int i = 0; i <= deg(); ++i)
    {
      ans += m_coeffs[i] * xp_i;
      xp_i *= x;
    }
    return ans;
  }

  // Arithmetic operations
  // Addition
  // operator+=
  Polynomial &operator+=(const Polynomial &other)
  {
    if (deg() < other.deg())
    {
      m_coeffs.resize(other.deg() + 1, 0);
    }
    for (int i = 0; i <= other.deg(); ++i)
    {
      m_coeffs[i] += other.m_coeffs[i];
    }
    adjust();
    return *this;
  }

  friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);

  // Subtraction
  // operator-=
  Polynomial &operator-=(const Polynomial &other)
  {
    return *this += -other;
  }

  friend Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs);

  // Multiple
  // operator*=
  Polynomial &operator*=(const Polynomial &other)
  {
    std::vector<double> ans_coeffs(deg() + other.deg() + 1, 0);
    for (int i = 0; i <= deg(); ++i)
    {
      for (int j = 0; j <= other.deg(); ++j)
      {
        ans_coeffs[i + j] += m_coeffs[i] * other.m_coeffs[j];
      }
    }
    Polynomial ans(ans_coeffs);
    *this = ans;
    return *this;
  }

  friend Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);

  // Destructor
  ~Polynomial() = default;

  // deg()
  int deg() const
  {
    return m_coeffs.size() - 1;
  }

  // setCoeff(i, c)
  void setCoeff(int i, double c)
  {
    if (i <= deg())
    {
      m_coeffs[i] = c;
      adjust();
    }
    else
    {
      m_coeffs.resize(i + 1, 0);
      m_coeffs[i] = c;
      adjust();
    }
  }

  // Derivatives and integrals
  // derivative()
  Polynomial derivative() const
  {
    Polynomial ans;
    for (int i = 0; i != deg(); ++i)
    {
      ans.setCoeff(i, (i + 1) * m_coeffs[i + 1]);
    }
    return ans;
  }

  // integral()
  Polynomial integral() const
  {
    Polynomial ans;
    for (int i = 0; i <= deg(); ++i)
    {
      ans.setCoeff(i + 1, m_coeffs[i] / (i + 1));
    }
    return ans;
  }
};

// Add non-member functions if you need.
// Arithmetic operations
// Addition
// operator+
Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs)
{
  return Polynomial(lhs) += rhs;
}

// Subtraction
// operator-
Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs)
{
  return Polynomial(lhs) -= rhs;
}

// Multiple
// operator*
Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs)
{
  return Polynomial(lhs) *= rhs;
}

#endif // POLYNOMIAL_HPP