#include <boost/test/unit_test.hpp>
#include "main.h"

//BOOST_AUTO_TEST_SUITE(test_main)

BOOST_AUTO_TEST_CASE(test_valid_version) {
	BOOST_CHECK(asum(1, 1) == 2);
}