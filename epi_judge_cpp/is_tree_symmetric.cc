#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
bool check_and_mirror(const unique_ptr<BinaryTreeNode<int>>& tree, const unique_ptr<BinaryTreeNode<int>>& mirror_tree) {
  if( tree == NULL && mirror_tree == NULL )
    return true;
  if(tree->data == mirror_tree->data) {
    return (true && check_and_mirror(tree->left,mirror_tree->right) && check_and_mirror(tree->right, mirror_tree->left));
  }
  else return false;
}

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  if(tree == NULL)
    return true;

  return check_and_mirror(tree->right,tree->left);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
