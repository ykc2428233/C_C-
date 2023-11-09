/* mon.h
 * Library of functions for "Minimal object notation" (MON). */

#ifndef MON_H
#define MON_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct element_t {
  char* name;
  struct element_t* left_child;
  struct element_t* right_child;
} Element;


Element* create_element(char* data);
Element* create_left(Element* root, char* data);
Element* create_right(Element* root, char* data);

void free_tree(Element* root);
int write_tree(FILE*, Element* root);
Element* load_tree(FILE* f);
Element* load_tree_func(char* tree_info, Element* parent, bool d);

#endif

