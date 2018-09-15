#ifndef COMMON_INCLUDE_H
#define COMMON_INCLUDE_H

// c++ includes
#include <iostream>
#include <string>
// c includes
#include <stdlib.h>
#include <string.h>

// application includes
#include "key.h"

// all namespace includes
using namespace std;

// all global hash defines
#define ITERATOR  			   1
#define REVERSE_ITERATOR 	   2
#define CONST_ITERATOR 		   3
#define CONST_REVERSE_ITERATOR 4

// all global functions

/*
 *  hash code functor to be used
 *  for map compares
 */
struct hashcode_compare
{
	bool operator () (const Key* lKey,const Key* rKey) const
	{
		return (lKey->hashCode() < rKey->hashCode());
	}
};

#endif
