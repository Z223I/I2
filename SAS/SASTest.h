// MoneyTest.h
#ifndef MONEYTEST_H
#define MONEYTEST_H

#include <cppunit/extensions/HelperMacros.h>

class MoneyTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( MoneyTest );
  CPPUNIT_TEST( test_binary_search_A );
  CPPUNIT_TEST( test_binary_search_B );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testEqual );
  CPPUNIT_TEST( testAdd );
  CPPUNIT_TEST( testAddThrow );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void test_binary_search_A();
  void test_binary_search_B();
  void testConstructor();
  void testEqual();
  void testAdd();
  void testAddThrow();
};

#endif  // MONEYTEST_H
