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

    void join() 
    {
        t.join();
    }

    void stopSoft()
    {
      iSoftStop = true;
    }

    void stopHard()
    {
      iStop = true;
    }

protected:
    cThreadSafeCommandsDeque* deque;
    cExceptionsHandler* handler;
    std::thread t;
    std::function<void(cServerThread &)> behaviour;
    std::atomic_int iStop = false, iSoftStop = false;

};

#endif //#ifndef CSERVERTHREAD_HPP
