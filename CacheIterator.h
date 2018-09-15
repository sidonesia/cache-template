#ifndef INTERNAL_CACHE_ITERATOR_PROTECTOR
#define INTERNAL_CACHE_ITERATOR_PROTECTOR

#include "strkey.h"
#include "Exceptions.h"
#include "common_includes.h"
#include <map>
#include <list>
#include <iterator>

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
/*
 *
 * dont forget to write code to assign a
 * non_const iterator to a const_iterator
 *
 * */
using namespace std;

template <typename VALUE>
class CacheInternalIterator 
{
	
	list<CacheInternalIterator<VALUE>*>* _observerList;
	public:
		 CacheInternalIterator();
		 CacheInternalIterator(int type);
		 CacheInternalIterator
				 (
					int type , 
					map <const Key*,VALUE*,hashcode_compare>*  MapPtr,
					int start_or_end
				 );

		~CacheInternalIterator();
		
		/* 
		 *  compare if 2 operators are the same
		 *  */
		bool operator==(const CacheInternalIterator& CI);
		
		bool operator!=(const CacheInternalIterator& CI);
		/*
		 * incremenet the iterator to the next one
		 * */
		CacheInternalIterator
				operator++(int add);
		
		/*
		 * decrement the iterator to the previous one
		 * */
		CacheInternalIterator
				operator--(int take);
		
		CacheInternalIterator&
				operator++();
		
		CacheInternalIterator&
				operator--();
		
		/*
		 * assign to this iterator
		 * */

		CacheInternalIterator& 
				operator=( CacheInternalIterator input_type);
		
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
		typename map<const Key*,VALUE*,hashcode_compare>::iterator
			 getInternalMapIterator() const;
		
		typename map<const Key*,VALUE*,hashcode_compare>::reverse_iterator
			 getInternalReverseMapIterator() const;
		
		int   mapsize;
		int   getBeginOrEnd() const;
		int   getIteratorType() const;
	    const Key* getInternalKeyMapInterator() const;
		bool  getIsIteratorValid() {return isIteratorValid;}
		list<CacheInternalIterator<VALUE>*>* getList();
		
	private:
		typename map<const Key*,VALUE*,hashcode_compare>
							::iterator _current_map_iter;	
		
		typename map<const Key*,VALUE*,hashcode_compare>
							::reverse_iterator _current_rev_map_iter;

		typename map<const Key*,VALUE*,hashcode_compare>
							::const_iterator _current_const_map_iter;

		typename map<const Key*,VALUE*, hashcode_compare>
							::const_reverse_iterator _current_const_rev_map_iter;
		
		map<const Key*,VALUE*,hashcode_compare>*  _MapPtr;   
		int  currentHashCode;
		int  iterator_type;
		int  iterator_beginEnd;
		mutable bool isIteratorValid;
	protected:
};

#include "CacheIterator.tem"

#endif 
