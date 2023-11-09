#include "mon.h"

int main(int argc, char* argv[])
{
  /* This code should create the tree below:
   *            aardvark
   *             /   \
   *        baboon   zebra
   *        /   \
   * xylophone  yak
   */
  /*Element* a = create_element("aardvark");
  Element* b = create_left(a, "baboon");
  Element* x = create_left(b, "xylophone");
  Element* x_ = create_left(b, "xylophone_");
  Element* y = create_right(b, "yak");
  Element* y_ = create_right(b, "yak_");
  Element* z = create_right(a, "zebra");
  Element* no_ = create_element(NULL);

  create_left(x, NULL);

  FILE* f = fopen("final_sample.mon", "w");
  write_tree(f, a);
  if(f)
  {
    fclose(f);
  }
  free_tree(a);

  FILE* f2 = fopen("final_sample.mon", "r");
  Element* load = load_tree(f2);
  if(f2)
  {
    fclose(f2);
  }

  FILE* f3 = fopen("NULL.mon", "r");
  Element* load1 = load_tree(f3);

  FILE* f1 = fopen("final_test", "w");
  write_tree(f1, load);
  write_tree(NULL, load);
  if(f1)
  {
    fclose(f1);
  }
  free_tree(load);

  Element* L = create_element("left");
  create_left(L, "left_left");
  FILE* f_l = fopen("final_left.mon", "w");
  write_tree(f_l, L);
  if(f_l)
  {
    fclose(f_l);
  }
  free_tree(L);
  FILE* l_f_l = fopen("final_left.mon", "r");
  free_tree(load_tree(l_f_l));
  fclose(l_f_l);
  
  Element* R = create_element("right");
  create_right(R, "right_right");
  FILE* f_r = fopen("final_right.mon", "w");
  write_tree(f_r, R);
  if(f_r)
  {
    fclose(f_r);
  }
  free_tree(R);
  FILE* l_f_r = fopen("final_right.mon", "r");
  Element* R_t = load_tree(l_f_r);
  fclose(l_f_r);
  l_f_r = fopen("final_right_result.mon", "w");
  write_tree(l_f_r, R_t);
  fclose(l_f_r);
  free_tree(R_t);

  Element* RR = create_element("root");
  FILE* f_rr = fopen("final_root.mon", "w");
  write_tree(f_rr, RR);
  if(f_rr)
  {
    fclose(f_rr);
  }
  free_tree(RR);
  f_rr = fopen("final_root.mon", "r");
  Element* test_root = load_tree(f_rr);
  fclose(f_rr);
  f_rr = fopen("final_root_result.mon", "w");
  write_tree(f_rr, test_root);
  free_tree(test_root);
  fclose(f_rr);

  FILE* l_f_rr = fopen("final_root.mon", "r");
  free_tree(load_tree(l_f_rr));
  fclose(l_f_rr);

  load_tree_func(NULL, NULL, 0);
  free_tree(NULL);
  
//--------------------TEST TREE ---------------------------
  Element* new = create_element("new");
  Element* n_l = create_left(new, "new_l");
  Element* n_r = create_right(new, "new_r");
  Element* n_l_r = create_right(n_l, "new_l_r");
  Element* n_l_r_r = create_right(n_l_r, "new_l_r_r");
  Element* n_l_r_l = create_left(n_l_r, "new_l_r_l");
  Element* n_l_r_l_r = create_left(n_l_r_l, "new_l_r_l_r");
  FILE* f_test = fopen("test.mon", "w");
  write_tree(f_test, new);
  fclose(f_test);
  f_test = fopen("test.mon", "r");
  Element* new_test = load_tree(f_test);
  fclose(f_test);
  f_test = fopen("test_result.mon", "w");
  write_tree(f_test, new);
  fclose(f_test);
  free_tree(new);
  free_tree(new_test);*/
  FILE* root_test = fopen("root_test.mon", "r");
  Element* test_root = load_tree(root_test);
  printf("%s\n", test_root->name);
  fclose(root_test);
  return(0);
}

