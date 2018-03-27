// MoneyTest.cpp

#include "StdAfx.h"
#include <cppunit/config/SourcePrefix.h>
#include "SAS.h"
#include "SASTest.h"

#include <array>
using namespace std;

void print_array(int arr[], uint start, uint stop) {
    for (uint i=start; i<=stop; i++) {
        if (i < stop) {
            cout << arr[i] << ", ";
        } else {
            cout << arr[i] << endl;
        }
    }

}

bool compare_subarrays(int arr1[], int arr2[], uint start, uint stop) {
    bool b_equal = true;
    uint i;

    for (i=start; i<=stop; i++) {
        if (arr1[i] != arr2[i]) {
            b_equal = false;
            break;
        }
    }

    return b_equal;
}

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( MoneyTest );


void 
MoneyTest::setUp()
{
}


void 
MoneyTest::tearDown()
{
}

#define OAKSdfjOIJEFWF
#ifdef OAKSdfjOIJEFWF
void 
MoneyTest::testConstructor()
{
  // Set up
  const std::string currencyFF( "FF" );
  const double longNumber = 1234.5678;

  // Process
  Money money( longNumber, currencyFF );

  // Check
  CPPUNIT_ASSERT_EQUAL( longNumber, money.getAmount() );
  CPPUNIT_ASSERT_EQUAL( currencyFF, money.getCurrency() );
}


void
MoneyTest::test_binary_search_A()
{
  Money::MyArray numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int findMe = 4;
  int indexOfMe = 3;

  Money money;
  money = Money();

  int index;
  index = money.binary_search(numbers, findMe);

  if (index != indexOfMe) {
    cout << "index: " << index << endl;
    cout << "indexOfMe: " << indexOfMe << endl;
  }
  CPPUNIT_ASSERT(index == indexOfMe);
}


void
MoneyTest::test_binary_search_B()
{
  Money::MyArray numbers = { 1, 2, 4, 5, 7, 9, 10, 13, 15, 18 };
  int findMe = 18;
  int indexOfMe = 9;

  Money money;
  money = Money();

  int index;
  index = money.binary_search(numbers, findMe);

  if (index != indexOfMe) {
    cout << "index: " << index << endl;
    cout << "indexOfMe: " << indexOfMe << endl;
  }
  CPPUNIT_ASSERT(index == indexOfMe);
}

void
MoneyTest::test_bubble_sort_A()
{
    Money::MyArray5 unsorted = {5, 1, 4, 2, 8};
    Money::MyArray5 sorted =   {1, 2, 4, 5, 8};
    Money::MyArray5 result = unsorted;

    Money money;
    money = Money();

    result = money.bubble_sort(unsorted);

    CPPUNIT_ASSERT(result == sorted);
}

void cout_5(Money::MyArray5 _arr) {
    cout << "{";

    for (uint i=0; i<_arr.size(); i++) {
        cout << _arr[i];

        if (i < _arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}";
}

void
MoneyTest::test_insertion_sort_A()
{
//#define TEST_INSERTION_SORT_A
#ifdef TEST_INSERTION_SORT_A
    Money::MyArray5 unsorted = {5, 1, 4, 2, 8};
    Money::MyArray5 sorted =   {1, 2, 4, 5, 8};
    Money::MyArray5 result = unsorted;

    Money money;
    money = Money();

    result = money.insertion_sort(unsorted);

    if (result != sorted) {
        cout << "test_insertion_sort_A result: ";
        cout_5(result);
        cout << endl;
        cout << "sorted: ";
        cout_5(sorted);
        cout << endl;
    }
    CPPUNIT_ASSERT(result == sorted);
#endif
}

void
MoneyTest::test_merge_A()
{
#define TEST_MERGE_A
#if defined(TEST_MERGE_A)

#define ARRAY_SIZE 5
    Money::MyArray5 unsorted = {1, 4, 8, 2, 5};
    Money::MyArray5 sorted   = {1, 2, 4, 5, 8};
    Money::MyArray5 result   = {-1, -1, -1, -1, -1};

    Money money;
    money = Money();

    int start = 0;
    int middle = 2;
    int stop = 4;
    money.merge(unsorted, start, middle, stop);
    result = unsorted;

    if (result != sorted) {
        cout << endl << ">>>test_merge_A result: ";
        cout_5(result);
        cout << endl;
        cout << "sorted: ";
        cout_5(sorted);
        cout << endl;
    }
    CPPUNIT_ASSERT(result == unsorted); // Checking pass by reference.
    CPPUNIT_ASSERT(result == sorted);
#endif
}


void
MoneyTest::test_merge_sort_A()
{

    Money::MyArray5 unsorted = {5, 1, 4, 2, 8};
    Money::MyArray5 sorted =   {1, 2, 4, 5, 8};
    Money::MyArray5 result = unsorted;

    Money money;
    money = Money();

    uint start = 0;
    uint stop = unsorted.size() - 1;

    money.merge_sort(unsorted, start, stop);
    result = unsorted;

    if (result != sorted) {
        cout << "test_merge_sort_A result: ";
        cout_5(result);
        cout << endl;
        cout << "sorted: ";
        cout_5(sorted);
        cout << endl;
    }
    CPPUNIT_ASSERT(result == sorted);

}

//#define OIWEFJHOSIKDFJ
void
MoneyTest::test_qs_partition_A()
{

    int unpartitioned[] = {5, 1, 8, 2, 4};
    int partitioned[]   = {1, 2, 4, 5, 8};

    Money money;
    money = Money();

    uint array_size = sizeof(unpartitioned) / sizeof(unpartitioned[0]);
    
    uint start = 0;
    uint stop = array_size - 1;

    money.qs_partition(unpartitioned, start, stop);

    if ( !compare_subarrays(unpartitioned, partitioned, start, stop) ) {
        cout << endl << "test_qs_partition result: ";
        print_array(unpartitioned, start, stop);
        cout << endl;
        cout << "partitioned: ";
        print_array(partitioned, start, stop);
        cout << endl;
    }
    CPPUNIT_ASSERT(compare_subarrays(unpartitioned, partitioned, start, stop));

}

void
MoneyTest::test_qs_partition_B()
{

    int unpartitioned[] = {10, 80, 30, 90, 40, 50, 70};
    int partitioned[]   = {10, 30, 40, 50, 70, 90, 80};

    Money money;
    money = Money();

    uint array_size = sizeof(unpartitioned) / sizeof(unpartitioned[0]);
    
    uint start = 0;
    uint stop = array_size - 1;

    money.qs_partition(unpartitioned, start, stop);

    if ( !compare_subarrays(unpartitioned, partitioned, start, stop) ) {
        cout << endl << "test_qs_partition result: ";
        print_array(unpartitioned, start, stop);
        cout << endl;
        cout << "partitioned: ";
        print_array(partitioned, start, stop);
        cout << endl;
    }
    CPPUNIT_ASSERT(compare_subarrays(unpartitioned, partitioned, start, stop));

}


void
MoneyTest::testEqual()
{
  // Set up
  const Money money123FF( 123, "FF" );
  const Money money123USD( 123, "USD" );
  const Money money12FF( 12, "FF" );
  const Money money12USD( 12, "USD" );

  // Process & Check
  CPPUNIT_ASSERT( money123FF == money123FF );    // ==
  CPPUNIT_ASSERT( money12FF != money123FF );     // != amount
  CPPUNIT_ASSERT( money123USD != money123FF );   // != currency
  CPPUNIT_ASSERT( money12USD != money123FF );    // != currency and != amount
}


void 
MoneyTest::testAdd()
{
  // Set up
  const Money money12FF( 12, "FF" );
  const Money expectedMoney( 135, "FF" );

  // Process
  Money money( 123, "FF" );
  money += money12FF;

  // Check
  CPPUNIT_ASSERT_EQUAL( expectedMoney, money );           // add works
  CPPUNIT_ASSERT( &money == &(money += money12FF) );  // add returns ref. on 'this'.
}


void 
MoneyTest::testAddThrow()
{
  // Set up
  const Money money123FF( 123, "FF" );

  // Process
  Money money( 123, "USD" );
  CPPUNIT_ASSERT_THROW( money += money123FF, IncompatibleMoneyError );
}

#endif