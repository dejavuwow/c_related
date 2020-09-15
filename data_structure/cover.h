#ifndef COVER_H
#define COVER_H

#include "set.h"

typedef struct KSet {
	void *key;
	Set set;
} KSet;

int cover(Set *members, Set *subsets, Set *convering);

#endif
