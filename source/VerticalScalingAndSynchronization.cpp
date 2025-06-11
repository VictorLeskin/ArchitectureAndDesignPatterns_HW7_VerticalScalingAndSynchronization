///************************* OUTS HOMEWORK ****************************************

#include "VerticalScalingAndSynchronization.hpp"

// interface 
#include "iCommand.hpp"
#include "cCommandsDeque.hpp"
#include "cException.hpp"
#include "cExceptionsHandler.hpp"

#include <atomic>

thread_local cCommandsDeque VerticalScalingAndSynchronization::commandsDeque;

void VerticalScalingAndSynchronization::push_back(std::unique_ptr<iCommand>& command)
{
  commands->push_back(command);
}

void VerticalScalingAndSynchronization::run()
{
  commands = &commandsDeque;

  std::atomic_int stop = false;
  while (!stop)
  {
    if (true == commands->empty())
      break;
    std::unique_ptr< iCommand> cmd = commands->pop_front();
    try
    {
      cmd->Execute();
    }
    catch (cException& e)
    {
      handler->Handle(*cmd, e);
    }
    catch (const std::exception&)
    {
      assert(nullptr == "Not processed operation");
    }
  }
}


