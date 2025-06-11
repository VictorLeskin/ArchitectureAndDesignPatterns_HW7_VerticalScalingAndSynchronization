///************************* OUTS HOMEWORK ****************************************
#ifndef VERTICALSCALINGANDSYNCHRONIZATION_HPP
#define VERTICALSCALINGANDSYNCHRONIZATION_HPP

#include <memory>

class iCommand;
class cCommandsDeque;
class cExceptionsHandler;

class VerticalScalingAndSynchronization
{
public:
	void run();

	// interface 
	void push_back(std::unique_ptr<iCommand>& command);

	cCommandsDeque& getCommandsDeque() { return *commands; }

	void set(cExceptionsHandler* h) { handler = h; };

	static thread_local cCommandsDeque commandsDeque;

protected:
	cExceptionsHandler* handler = nullptr;
	cCommandsDeque *commands = nullptr;

};

#endif //#ifndef VERTICALSCALINGANDSYNCHRONIZATION_HPP
