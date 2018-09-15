#ifndef CACHEIMPL_H
#define CACHEIMPL_H

#include "cache.h"
#include "key.h"
#include "CacheIterator.h"
#include "CacheConstIterator.h"
#include "common_includes.h"
#include "CacheIterHolder.h"
#include <map>
#include <list>
#include <iostream>

using namespace std;

class KeyCompare
{
		public:
			bool operator()(const Key* k)	
			{
				return (k->hashCode() == _k->hashCode());	
			}
			KeyCompare(const Key* k):_k(k) {};
					
		
	private:
		const Key* _k;	
};

template <typename VALUE>
class CacheImpl : public Cache<VALUE>
{
		public:
		typedef typename CacheIteratorTags<VALUE>
					::iterator iterator;
					
		typedef typename CacheIteratorTags<VALUE>
					::reverse_iterator reverse_iterator;

		typedef typename CacheIteratorTags<VALUE>
					::const_iterator const_iterator;

		typedef typename CacheIteratorTags<VALUE>
					::const_reverse_iterator const_reverse_iterator;

		typedef pair<const Key*, VALUE*> KeyValuePair;

            CacheImpl(unsigned int capacity);
            void insert(const Key& k,const VALUE& v);
			reverse_iterator rend();
			const_iterator begin() const;

			const_iterator end() const;
			const_reverse_iterator rbegin() const;
			VALUE lookup(const Key& k);
			size_t size() const;
			size_t capacity() const;

			void clear();
			iterator begin();
			iterator end();
			reverse_iterator rbegin();
			const_reverse_iterator rend() const;
			std::string snapshot() const;
			
		private:
		    mutable map<const Key*, VALUE*, hashcode_compare> _map;
		    list<const Key*> _list;
			unsigned int _capacity;
			
};

#include "CacheImpl.tem"

#endif
