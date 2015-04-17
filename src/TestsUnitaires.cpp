#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Shootemup

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test)
{
	BOOST_CHECK(42 == 42);
	// . . .
}

