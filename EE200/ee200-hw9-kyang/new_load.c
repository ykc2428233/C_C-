// get line
char * tree_info = NULL;
size_t len = 0;
ssize_t s_len = 0;

s_len = getline(&tree_info, &len, f);

// direct 0=right 1=left
*Element _load_tree(char* tree_info, *Element parent, bool direct)
{
  const char* end_flag = "{NULL NULL";
  bool right = 0; //empty right sub
  bool left = 0; // empty left sub
  
  int info_len = strlen(tree_info);
  if(info_len == 0)
  {
    return(NULL);
  }

  // find root
  int name_index = 0;
  for(int i=info_len-2; i > 0; i--)
  {
    if(tree_info[i] == '}' || tree_info[i] == ' ')
    {
      name_index = i;
    }
  }
    
  char* name = malloc((info_len-2-name_index) * sizeof(*name));
  if(parent)
  {
    Element* root = create_element(name); // create root
  }
  else if(!direct)
  {
    Element* root = create_right(parent, name); // create root
  }
  else if(direct)
  {
    Element* root = create_left(parent, name); // create root
  }
  free(name);
  
  char* check_end = malloc(name_index * sizeof(*check_end));

  if(strcmp(end_flag, check_end)) // only root
  {
    return root;
  }
  
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
    else if
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
  if(right)
  {
     char* right_info = malloc((name_index-right_start+1) * sizeof(*char));
     strncpy(right_info, tree_info+right_start, (name_index-right_start+1));
     _load_tree(right_info, root, 0);
  }

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
    else if
    {
      curly_count--;
    }

    if(count == 0)
    {
      left_start = i;
      left = 1;
      break;
    }
  }
  if(left)
  {
     char* left_info = malloc((left_end-left_start+1) * sizeof(*char));
     strncpy(left_info, tree_info+left_start, (left_end-left_start+1));
     _load_tree(left_info, root, 1);
  }

  return(root);
}
