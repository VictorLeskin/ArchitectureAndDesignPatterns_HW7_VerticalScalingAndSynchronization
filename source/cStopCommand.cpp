///************************* OUTS HOMEWORK ****************************************

#include "cStopCommand.hpp"
#include <cException.hpp>

void cAbortCommand::Execute()
{
	throw(cException("not implemented"));
}

void cSoftStopCommand::Execute()
{
	throw(cException("not implemented"));
}

void cHardStopCommand::Execute()
{
	throw(cException("not implemented"));
}

