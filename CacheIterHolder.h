#ifndef CACHEIMPL_HOLDER_H
#define CACHEIMPL_HOLDER_H

#include "CacheIterator.h"
#include "CacheConstIterator.h"
#include "common_includes.h"

using namespace std;

#define CONST 1
#define NON_C 2

/*
 * inline it, who cares not enough time
 */

template <typename VALUE>
class iterator_holder_t
{
	private :
		int iterator_type;
		CacheInternalIterator<VALUE>*      non_const_iter;
		CacheConstInternalIterator<VALUE>* const_iter;
	
	public :
		
		/* will get the iterators  type */
		int getIteratorType()
		{
			return iterator_type;
		}
		
		/* will set the const iterators */
		void setConstIter(CacheConstInternalIterator<VALUE>* c)
		{
			iterator_type = CONST;
			const_iter = c;
		}
		
		/* will set the iterators */
		void setIter(CacheInternalIterator<VALUE>* c)
		{
			iterator_type = NON_C;
			non_const_iter = c;
		}
		
		/* will get the hashcodes of the iterators */
		int getHashCode(int type)
		{
			if(type == CONST)		
				return const_iter->getInternalKeyMapInterator()->hashCode();		
			else
				return non_const_iter->getInternalKeyMapInterator()->hashCode();
		}
		
		/* will set the iterators status */
		void setIteratorStatus(bool isValid,int iterator_type)
		{
			if (iterator_type == CONST)
				const_iter->setIteratorStatus(isValid);
			else
				non_const_iter->setIteratorStatus(isValid);
		}
};
#endif
