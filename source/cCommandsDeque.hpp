///************************* OUTS HOMEWORK ****************************************
#ifndef CCOMMANDSDEQUE_HPP
#define CCOMMANDSDEQUE_HPP

#include <deque>
#include <string>
#include <memory>
#include <optional>
#include <cassert>
#include <map>

#include "iCommand.hpp"
#include <mutex>

// A class of the deque of commands. It is just a wrapper of std::deque with pointers to commands.
// std::unique_ptr  helps us avoid problems with a memory allocation/freeing.
class cCommandsDeque
{
public:
	cCommandsDeque() {}

	bool empty() const { return commands.empty(); }
	std::unique_ptr< iCommand> pop_front() 
	{
		std::unique_ptr< iCommand> ret = std::move(commands.front());
		commands.pop_front();
		return ret;
	}
	void push_back(std::unique_ptr < iCommand > &command)
	{
		commands.push_back( std::move(command) );
	}

protected:	
	std::deque< std::unique_ptr<iCommand> > commands;
};

class cThreadSafeCommandsDeque : public cCommandsDeque
{ 
public:
	bool empty() const 
	{ 
		std::lock_guard<std::mutex> lock(m_mutex);
		return cCommandsDeque::empty();
	}

	bool pop_front(std::unique_ptr< iCommand> &ret)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (commands.empty())
			return false;
		ret = cCommandsDeque::pop_front();
		return true;
	}
	void push_back(std::unique_ptr < iCommand >& command)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		cCommandsDeque::push_back(command);
	}
protected:
	mutable std::mutex m_mutex;
};

#endif //#ifndef CCOMMANDSDEQUE_HPP
