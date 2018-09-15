#ifndef CACHE_EXCPETIONS_PROTECTOR_H
#define CACHE_EXCPETIONS_PROTECTOR_H

#include <exception>
#include "common_includes.h"

class IteratorOutOfBoundsException 
{
	public:
			IteratorOutOfBoundsException() {};
			~IteratorOutOfBoundsException() {};
					
};


class MissingKeyException
{
	public:
			MissingKeyException() {};
			~MissingKeyException() {};
};

class InvalidIteratorUsageException 
{
	public:
			InvalidIteratorUsageException() {};
			~InvalidIteratorUsageException() {};
};


#endif
