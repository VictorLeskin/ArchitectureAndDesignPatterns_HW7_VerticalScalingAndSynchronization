///************************* OUTS HOMEWORK ****************************************

#include "cServerThread.hpp"
#include "cCommandsDeque.hpp"
#include "cExceptionsHandler.hpp"
#include "cException.hpp"
#include <thread>

using namespace std::chrono_literals;

cServerThread::cServerThread(cThreadSafeCommandsDeque* deque) : deque(deque)
{
    behaviour = [](cServerThread& s)
        {
            std::unique_ptr<iCommand> cmd;
            
            try 
            {
                if( true == s.deque->pop_front(cmd) )
                  cmd->Execute();

                if (true == s.deque->empty())
                {
                  if (false == s.iSoftStop)
                    std::this_thread::sleep_for(200ms);
                  else
                    s.iStop = true;
                }
            }
            catch (cException e)
            {
                s.handler->Handle(*cmd, e);
            }
        };

    t = std::thread(
        [](cServerThread& s)
        {
            while (!s.iStop)
            {
                s.behaviour(s);
            }
        },
        std::ref(*this)
    );
}
