///************************* OUTS HOMEWORK ****************************************

#include "cServerThread.hpp"
#include "cCommandsDeque.hpp"
#include "cExceptionsHandler.hpp"
#include "cException.hpp"

static void tr(cServerThread& s);

cServerThread::cServerThread(cThreadSafeCommandsDeque* deque) : deque(deque)
{
    behaviour = [](cServerThread& s)
        {
            std::unique_ptr<iCommand> cmd = s.deque->pop_front();
            try {
                cmd->Execute();
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
