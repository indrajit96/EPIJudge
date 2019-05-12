#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

int flag = 1;
int height(const unique_ptr<BinaryTreeNode<int>>& tree) {
  int left_height = 0;
  int right_height = 0;
  if(tree == NULL)
    return 0;
  left_height = height(tree->left);
  right_height = height(tree->right);
  if(abs(left_height - right_height) > 1) {
    flag = 0;
  }

  if(left_height > right_height)
    return left_height + 1;
  else
    return right_height + 1;
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here
  height(tree);
  return flag; 
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
