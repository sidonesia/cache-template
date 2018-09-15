#ifndef CACHEITERATORTAG_PROTECTOR
#define CACHEITERATORTAG_PROTECTOR

// this is just an example

#include "CacheIterator.h" 
#include "CacheConstIterator.h" 

template<typename VALUE>
class CacheIteratorTags
{
	public:
		typedef CacheInternalIterator<VALUE> iterator;
		typedef CacheInternalIterator<VALUE> reverse_iterator;
		typedef CacheConstInternalIterator<VALUE> const_iterator;
		typedef CacheConstInternalIterator<VALUE> const_reverse_iterator;
};

#endif
