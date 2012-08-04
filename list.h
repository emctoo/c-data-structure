#include <stdlib.h>
#include <string.h>

struct _node_t {
	struct _node_t *next;
	char *str;
}

typedef struct _node_t node_t;

node_t *list_alloc(char *str);