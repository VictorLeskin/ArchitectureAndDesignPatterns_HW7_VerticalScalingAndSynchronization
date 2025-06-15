///************************* OUTS HOMEWORK ****************************************
#ifndef CSERVERTHREAD_HPP
#define CSERVERTHREAD_HPP

#include <functional>
#include <atomic>
#include <thread>

class cThreadSafeCommandsDeque;
class cExceptionsHandler;


class cServerThread
{
public:
    cServerThread(cThreadSafeCommandsDeque *deque);

    void stop() 
    {
        iStop = true;
    }

    void join() 
    {
        t.join();
    }

protected:
    cThreadSafeCommandsDeque* deque;
    cExceptionsHandler* handler;
    std::thread t;
    std::function<void(cServerThread &)> behaviour;
    std::atomic_int iStop = false;

};

#endif //#ifndef CSERVERTHREAD_HPP
