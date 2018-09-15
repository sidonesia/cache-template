#ifndef INTERNAL_CACHE_CONST_ITERATOR_PROTECTOR
#define INTERNAL_CACHE_CONST_ITERATOR_PROTECTOR

#include "strkey.h"
#include "Exceptions.h"
#include "common_includes.h"
#include "CacheIterator.h"
#include <map>
#include <iterator>
#include <list>
//#include "CacheIterHolder.h"

#define FOR_ITERATOR   1
#define CONST_FOR_ITER 2
#define REV_ITER       3
#define CONST_REV_ITER 4

#define START_ITER     1
#define BACKW_ITER	   2

/*
 * Dont forget to overload the -- ++ on both sides of the 
 * value 
 * */

using namespace std;

template <typename VALUE>
class CacheConstInternalIterator 
{
	list <CacheConstInternalIterator<VALUE>*>* _observerlist;

	public:
		 CacheConstInternalIterator();
		 CacheConstInternalIterator(CacheInternalIterator<VALUE> c);
		 CacheConstInternalIterator(int type);
		 CacheConstInternalIterator
				 (
					int type , 
					map <const Key*, VALUE*,hashcode_compare>*  MapPtr,
					int start_or_end
				 );
/*
		 CacheConstInternalIterator
				 (
					int type , 
					map <const Key*, VALUE*,hashcode_compare>*  MapPtr,
					//list <iterator_holder_t<VALUE> > lholder
					int start_or_end
				 );
*/
		~CacheConstInternalIterator();
		
		/* 
		 *  compare if 2 operators are the same
		 *  */
		bool operator==(const CacheConstInternalIterator& CI);
		
		bool operator!=(const CacheConstInternalIterator& CI);
		/*
		 * incremenet the iterator to the next one
		 * */
		CacheConstInternalIterator
				operator++(int add);
		
		/*
		 * incremenet to the next element
		 * */
		CacheConstInternalIterator&
				operator++();
		
		CacheConstInternalIterator&
				operator=(CacheConstInternalIterator const_iter);
		
		CacheConstInternalIterator&
				operator=(CacheInternalIterator<VALUE> non_const_iter);
		/*
		 * decrement the iterator to the previous one
		 * */
		CacheConstInternalIterator
				operator--(int take);
		
		CacheConstInternalIterator&
				operator--();
		/*
		 * assign to this iterator
		 * */
		
		//CacheConstInternalIterator::operator CacheInternalIterator<VALUE>();
		
		
		/*
		 * dereference this operator
		 * */
		VALUE& 
				operator*() const;
		
		/*
		 * we want to call a function out of this
		 * iterator
		 * */	
		
		VALUE*
				operator->() const ;

		/*
		 * will return if the iterator is
		 * valid or not
		 * */	
		void setIteratorStatus(bool status);
		bool getIteratorStatus();

		// get the internal map address
		map <const Key*,VALUE*, hashcode_compare>* 
			 getInternalMapAddress() const;

		// gets the internal map iterator
		typename map<const Key*,VALUE*,hashcode_compare>::const_iterator
			 getInternalMapIterator() const;
		
		typename map<const Key*,VALUE*,hashcode_compare>::const_reverse_iterator
			 getInternalReverseMapIterator() const;
	
		
		int  getIteratorType();
		int  getBeginOrEnd();
	    const Key* getInternalKeyMapInterator() const;
		list <CacheConstInternalIterator<VALUE>*>* getList();
		
	private:
		typename map<const Key*,VALUE*,hashcode_compare>
							::const_iterator _current_const_map_iter;

		typename map<const Key*,VALUE*, hashcode_compare>
							::const_reverse_iterator _current_const_rev_map_iter;
		
		map<const Key*,VALUE*,hashcode_compare>*  _MapPtr;   
		int  mapsize;
		int  currentHashCode;
		int  iterator_type; // determines if reverse const etc
		int  iterator_beginEnd; // determines if the iterator was end or begin
		bool isIteratorValid; // determines if the iterator is valid
	protected:
};

#include "CacheConstIterator.tem"

#endif 
