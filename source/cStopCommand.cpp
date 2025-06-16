///************************* OUTS HOMEWORK ****************************************

#include "cStopCommand.hpp"
#include "cException.hpp"
#include "cServerThread.hpp"

void cAbortCommand::Execute()
{
	throw(cException("not implemented"));
}

void cSoftStopCommand::Execute()
{
	s->stopSoft();
}

void cHardStopCommand::Execute()
{
	s->stopHard();
}

