#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
struct un {
  int flag;
  int height;
};
struct un height(const unique_ptr<BinaryTreeNode<int>>& tree) {
  struct un left_node;
  struct un right_node;
  struct un node;

  if(tree == NULL) {
    node.flag = 1;
    node.height = 0;
    return node;
  }
  left_node = height(tree->left);
  right_node = height(tree->right);
  if((abs(left_node.height - right_node.height) <= 1)&&(left_node.flag && right_node.flag)) {
    node.flag = 1;
  }
  else{
   return {0,0};
  } 
  if(left_node.height > right_node.height)
    node.height = left_node.height + 1;
  else
    node.height = right_node.height + 1;
  return node;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  struct un node;
  // TODO - you fill in here
  node =  height(tree);
  return node.flag; 
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
