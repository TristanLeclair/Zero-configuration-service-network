#ifndef ZCS_STRUCTS_H
#define ZCS_STRUCTS_H

#include "status.h"
#include <time.h>

#define MAX_ATTRIBUTES 10

typedef struct {
  char attr_name[64];
  char value[64];
} zcs_attribute_t;

typedef void (*zcs_cb_f)(char *, char *);

typedef struct _zcs_node_t {
  char *name;
  enum Status status;
  time_t hearbeat_time;
  zcs_cb_f cback;
  struct _zcs_node_t *next;
  zcs_attribute_t attributes[MAX_ATTRIBUTES];
  int attr_len;
} zcs_node_t;

typedef struct _node_list_t {
  zcs_node_t *head;
  zcs_node_t *tail;
} node_list_t;

#endif
