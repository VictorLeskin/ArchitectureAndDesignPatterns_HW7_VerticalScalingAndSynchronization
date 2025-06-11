///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "VerticalScalingAndSynchronization.hpp"

// gTest grouping class
class test_VerticalScalingAndSynchronization : public ::testing::Test
{
public:
  // additional class to access to member of tested class
  class Test_VerticalScalingAndSynchronization : public VerticalScalingAndSynchronization
  {
  public:
    // add here members for free access.
    using VerticalScalingAndSynchronization::VerticalScalingAndSynchronization; // delegate constructors
  };

};
 
TEST_F(test_VerticalScalingAndSynchronization, test_ctor )
{
  Test_VerticalScalingAndSynchronization t;
}

