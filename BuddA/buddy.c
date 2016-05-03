/**
 * Buddy Allocator
 *
 * For the list library usage, see http://www.mcs.anl.gov/~kazutomo/list/
 */

/**************************************************************************
 * Conditional Compilation Options
 **************************************************************************/
#define USE_DEBUG 0

/**************************************************************************
 * Included Files
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "buddy.h"
#include "list.h"

/**************************************************************************
 * Public Definitions
 **************************************************************************/
#define MIN_ORDER 12
#define MAX_ORDER 20

/**************************************************************************
 * Public Types
 **************************************************************************/
typedef struct {
	struct list_head list;
	/* TODO: DECLARE NECESSARY MEMBER VARIABLES */
	unsigned int offset;
	unsigned int length;
} page_t;

/* memory area */
char g_memory[1<<MAX_ORDER];

page_t* free_list_head;

void buddy_init()
{
	free_list_head = (page_t*) malloc(sizeof(page_t));
	
	free_list_head->list.next=NULL;
	free_list_head->list.prev=NULL;
	
	free_list_head->offset = 0;
	free_list_head->length = 1 << MAX_ORDER;
}

unsigned int nearest_larger_pow_of_2(int size)
{
	unsigned int pow2 = 1 << MIN_ORDER;

	while (size <= pow2) {
		pow2 <<= 1;
	}
	
	return pow2;
}

void *buddy_alloc(int size)
{
	
	
	return NULL;
}

/**
 * Free an allocated memory block.
 *
 * Whenever a block is freed, the allocator checks its buddy. If the buddy is
 * free as well, then the two buddies are combined to form a bigger block. This
 * process continues until one of the buddies is not free.
 *
 * @param addr memory block address to be freed
 */
void buddy_free(void *addr)
{
	/* TODO: IMPLEMENT THIS FUNCTION */
}

/**
 * Print the buddy system status---order oriented
 *
 * print free pages in each order.
 */
void buddy_dump()
{
	
}
