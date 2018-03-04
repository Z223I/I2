// Money.h
#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <array>
#include <stdexcept>
#include <cppunit/portability/Stream.h>    // or <iostream> if portability is not an issue

using namespace std;

class IncompatibleMoneyError : public std::runtime_error
{
public:
   IncompatibleMoneyError() : std::runtime_error( "Incompatible moneys" )
  {
  }
};


class Money
{
public:
  Money( double amount = 1, std::string currency = "USD" )
    : m_amount( amount )
    , m_currency( currency )
  {
  }

#define MAX_INTS 10

  typedef array<int, MAX_INTS> MyArray;
  typedef array<int, 5> MyArray5;

  int binary_search(MyArray ints, int number) {
    int start, stop, mid;

    start = 0;
    stop = ints.size() - 1;
    mid = ints.size() / 2;

    bool found = false;
    int index = -1;

    do {
      // start, stop and mid are known at the point for every iteration.
      if ((stop - start + 1) <= 3) {
        if (ints[start] == number) {
          found = true;
          index = start;
        }

        if (ints[mid]   == number) {
          found = true;
          index = mid;
        }

        if (ints[stop]  == number) {
          found = true;
          index = stop;
        }
      }

      if (ints[mid] > number) {
        // Look to the left half.
        stop = mid - 1;
      } else {
        // Look to the right half.
        start = mid;
      }

      // Update mid.
      mid = (start + stop) / 2;

    } while (!found);

    return index;
  }

  Money::MyArray5 bubble_sort(Money::MyArray5 _arr) {
    Money::MyArray5 arr = _arr;
    bool done;

    do {
      done = true;

      // Step thru the array.
      // We are checking two numbers at a time, so it is necessary to 
      // subtract 1 from the array size.
      for (uint i=0; i<arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
          int temp = arr[i];
          arr[i] = arr[i + 1];
          arr[i + 1] = temp;
          done = false;
        }

      }

    } while (!done);

    return arr;
  }

  Money::MyArray5 insertion_sort(Money::MyArray5 _arr) {
    Money::MyArray5 sorted = _arr;
    uint i, j;
    int key;

    for (i=1; i<sorted.size(); i++) {
      key = sorted[i];
      j = i - 1;

      // Insert key into beginning of array which is already sorted.
      while (j >= 0 && sorted[j] > key) {
        sorted[j + 1] = sorted[j];
        j -= 1;
      }
      sorted[j + 1] = key;
    }  // for i


    return sorted;
  }

  MyArray5 merge(MyArray5 _arr, uint start, uint middle, uint stop) {

    uint start1 = start;
    uint stop1  = middle;
    uint start2 = middle + 1;
    uint stop2  = stop;

    MyArray5 arr = { -1, -1, -1, -1, -1 };
    int arr_index = 0;
    while (start1 <= stop1 && start2 <= stop2) {

        if (_arr[start1] <= _arr[start2]) {
          arr[arr_index] = _arr[start1];
          start1++;
          arr_index++;
        } else {
          arr[arr_index] = _arr[start2];
          start2++;
          arr_index++;
        }
    }

    cout << endl;
    cout << "Step 1 finished." << endl;
    //cout << arr << endl; This doesn't compile.

    uint i;

    // Copy anything remaining in the left side array.
    for (i=start1; i <= stop1; i++) {
      arr[arr_index] = _arr[i];
      arr_index++;
    }

    // Copy anything remaining in the right side array.
    for (i=start2; i <= stop2; i++) {
      arr[arr_index] = _arr[i];
      arr_index++;
    }
    
    _arr = arr;

    return arr;
  }

  void merge_sort(Money::MyArray5& _arr) {
    Money::MyArray5 sorted = _arr;
    uint i, j;
    int key;

    for (i=1; i<sorted.size(); i++) {
      key = sorted[i];
      j = i - 1;

      // Insert key into beginning of array which is already sorted.
      while (j >= 0 && sorted[j] > key) {
        sorted[j + 1] = sorted[j];
        j -= 1;
      }
      sorted[j + 1] = key;
    }  // for i

  _arr = sorted;

    return;
  }

    double getAmount() const
  {
    return m_amount;
  }

  std::string getCurrency() const
  {
    return m_currency;
  }

  bool operator ==( const Money &other ) const
  {
    return m_amount == other.m_amount  &&  
           m_currency == other.m_currency;
  }

  bool operator !=( const Money &other ) const
  {
    return !(*this == other);
  }

  Money &operator +=( const Money &other )
  {
    if ( m_currency != other.m_currency )
      throw IncompatibleMoneyError();

    m_amount += other.m_amount;
    return *this;
  }

private:
  double m_amount;
  std::string m_currency;
};


// The function below could be prototyped as:
// inline std::ostream &operator <<( std::ostream &os, const Money &value )
// If you know that you will never compile on a platform without std::ostream
// (such as embedded vc++ 4.0; though even that platform you can use STLPort)
inline CPPUNIT_NS::OStream &operator <<( CPPUNIT_NS::OStream &os, const Money &value )
{
    return os << "Money< value =" << value.getAmount() << "; currency = " << value.getCurrency() << ">";
}


#endif
