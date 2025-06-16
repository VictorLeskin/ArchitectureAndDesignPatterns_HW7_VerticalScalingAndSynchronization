///************************* OUTS HOMEWORK ****************************************

#include <gtest/gtest.h>

#include "VerticalScalingAndSynchronization.hpp"
#include "cServerThread.hpp"
#include "cCommandsDeque.hpp"
#include "cStopCommand.hpp"

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
  //Test_VerticalScalingAndSynchronization t;
}

TEST_F(test_VerticalScalingAndSynchronization, test_)
{
  // create n thread. Each of them use a IoC container 
  // in thread_local IoC test_Multithreading::Test_Multithreading::t0;
  // in own scope but with different factory methods. 
  // The variable is declared with thread_local attribute, so let's hope
  // that compiler/linker will do a real work.

  //thread1();
  //thread2();

  

  cThreadSafeCommandsDeque deque1;
  cThreadSafeCommandsDeque deque2;

  cServerThread t1(&deque1);
  cServerThread t2(&deque2);

  std::unique_ptr<iCommand> softStopCmd1(new cSoftStopCommand(&t1));
  std::unique_ptr<iCommand> softStopCmd2(new cSoftStopCommand(&t2));

  deque1.push_back(softStopCmd1);
  deque2.push_back(softStopCmd2);

  t1.join();
  t2.join();
}
