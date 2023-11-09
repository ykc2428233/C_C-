#include "mon.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Element* create_element(char* data)
{
  if(data)
  {
    Element* a = malloc(sizeof(*a));
    char* temp_name = malloc((strlen(data)+1) * sizeof(*temp_name));
    strncpy(temp_name, data, strlen(data));
    temp_name[strlen(data)] = '\0';
    a->name = temp_name;
    a->left_child = NULL; 
    a->right_child = NULL;
    
    return(a); 
  }
  else
  {
    return NULL;
  }
}

Element* create_left(Element* root, char* data)
{
  if(!(root->left_child) && data)
  {
    Element* a = create_element(data);
    
    root->left_child = a; 

    return(a); 
  }
  else
  {
    return NULL;
  }
}

Element* create_right(Element* root, char* data)
{
  if(!(root->right_child) && data)
  {
    Element* a = create_element(data);
    
    root->right_child = a; 

    return(a); 
  }
  else
  {
    return NULL;
  }
}


void free_tree(Element* root)
{
  if(root)
  {
    free(root->name);
    if(root->left_child)
    {
      free_tree(root->left_child);
    }
    if(root->right_child)
    {
      free_tree(root->right_child);
    }
    free(root);
  }
  else
  {
    free(root);
  }
}

int write_tree(FILE* f, Element* e)
{
  if(e && f)
  {
    fprintf(f, "{");
    if(e->left_child)
    {
      write_tree(f, e->left_child);
    }
    else
    {
      fprintf(f, "NULL ");
    }
    if(e->right_child)
    {
      write_tree(f, e->right_child);
    }
    else
    {
      fprintf(f, "NULL ");
    }
    fprintf(f, "%s}", e->name);
    return(0);
  }
  else
  {
    return(-1);
  }
}


// direct 0=right 1=left
Element* load_tree_func(char* tree_info, Element* parent, bool direct)
{
  const char* end_flag = "{NULL NULL";
  bool right = 0; //empty right sub
  bool left = 0; // empty left sub
  
  if(!tree_info)
  {
    return(NULL);
  }

  // find root
  int name_index = 0;
  int info_len = 0;
  if(tree_info)
  {
    info_len = strlen(tree_info);
    if(tree_info[info_len-1] == '\n')
    {
      info_len = info_len - 1;
    }
    if(info_len <= 10 || tree_info[0] != '{' || tree_info[info_len-1] != '}')
    {
      return(NULL);
    }
  }
  for(int i=info_len-2; i > 0; i--)
  {
    if(tree_info[i] == '}' || tree_info[i] == ' ')
    {
      name_index = i;
      break;
    }
  }
    
  Element* root; 
  
  char* name = malloc((info_len-2-name_index+1) * sizeof(*name));
  strncpy(name, tree_info+name_index+1, (info_len-2-name_index));
  name[info_len-2-name_index] = '\0';
  if(!parent)
  {
    root = create_element(name); // create root
  }
  else
  {
    if(!direct)
    {
      root = create_right(parent, name); // create root
    }
    else
    {
      root = create_left(parent, name); // create root
    }
  }
  free(name); 
 
  char* check_end = malloc((name_index+1) * sizeof(*check_end));
  strncpy(check_end, tree_info, name_index);
  check_end[name_index] = '\0';
  if(!check_end || !strcmp(end_flag, check_end)) // only root
  {
    free(check_end);
    return(root);
  }
  free(check_end);

  
  //find right sub
  int curly_count = 0;
  int right_start = 0;
  for(int i = name_index; i>=0; i--)
  {
    if(tree_info[name_index] == ' ')
    {
      right = 0;
      break;
    }
    if(tree_info[i] == '}')
    {
      curly_count++;
    }
    else if(tree_info[i] == '{')
    {
      curly_count--;
    }

    if(curly_count == 0)
    {
      right_start = i;
      right = 1;
      break;
    }
  }
  char* right_info = malloc((name_index-right_start+1+1) * sizeof(*right_info));
  if(right)
  {
     strncpy(right_info, tree_info+right_start, (name_index-right_start+1));
     right_info[name_index-right_start+1] = '\0';
     load_tree_func(right_info, root, 0);
  }
  free(right_info);

  //find left sub
  curly_count = 0;
  int left_start = 0;
  int left_end = 0;
  if(right)
  {
    left_end = right_start - 1;
  }
  else
  {
    left_end = name_index - 5;
  }
  for(int i = left_end; i>=0; i--)
  {
    if(tree_info[left_end] == ' ')
    {
      left = 0;
      break;
    }
    if(tree_info[i] == '}')
    {
      curly_count++;
    }
    else if(tree_info[i] == '{')
    {
      curly_count--;
    }

    if(curly_count == 0)
    {
      left_start = i;
      left = 1;
      break;
    }
  }
  char* left_info = malloc((left_end-left_start+1+1) * sizeof(*left_info));
  if(left)
  {
     strncpy(left_info, tree_info+left_start, (left_end-left_start+1));
     left_info[left_end-left_start+1] = '\0';
     load_tree_func(left_info, root, 1);
  }
  

  free(left_info);
  return(root);
}

Element* load_tree(FILE* f)
{
  if(f)
  {
    char* t_info = NULL;
    size_t len = 0;
    ssize_t size = 0;
    size = getline(&t_info, &len, f);
    if(size != -1)
    {
      Element* a = load_tree_func(t_info, NULL, 0);
      free(t_info);
      return(a);
    }
    else
    {
      free(t_info);
      return(NULL);
    }
  }
  else
  {
    return NULL;
  }
}
