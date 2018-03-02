// MoneyTest.cpp

#include "StdAfx.h"
#include <cppunit/config/SourcePrefix.h>
#include "SAS.h"
#include "SASTest.h"

#include <array>
using namespace std;

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
    array<int, 5> unsorted = {5, 1, 4, 2, 8};
    array<int, 5> sorted =   {1, 2, 4, 5, 8};
    array<int, 5> result = unsorted;

    CPPUNIT_ASSERT(result == sorted);
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
