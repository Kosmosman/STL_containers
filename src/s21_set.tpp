namespace s21 {

/* ------------------------ OPERATORS --------------------------- */

template <typename value_type>
Set<value_type> &Set<value_type>::operator=(const Set<value_type> &s) {
  tree = s.tree;
  return *this;
};

template <typename value_type>
Set<value_type> &Set<value_type>::operator=(Set<value_type> &&s) {
  tree = std::move(s.tree);
  return *this;
};

/* ------------------------- MODIFIRE ---------------------------- */

template <typename value_type>
std::pair<typename Set<value_type>::iterator, bool> Set<value_type>::Insert(
    const value_type &value) {
  iterator it(tree.Insert(value, value));
  return std::pair(it, it);
};

template <typename value_type>
void Set<value_type>::Erase(iterator pos) {
  tree.Erase(pos.iterator_node_);
};

template <typename value_type>
void Set<value_type>::Swap(Set<value_type> &other) {
  std::swap(tree, other.tree);
};

template <typename value_type>
void Set<value_type>::Merge(Set<value_type> &other) {
  for (iterator it = other.begin(); it != other.end(); it++) {
    Insert(it.iterator_node_);
  }
};

/* ---------------------------- ITERATORS ------------------------------ */

template <typename value_type>
typename Set<value_type>::iterator &Set<value_type>::iterator::operator=(
    const iterator &it) {
  iterator_node_ = it.iterator_node_;
};

template <typename value_type>
typename Set<value_type>::iterator &Set<value_type>::iterator::operator=(
    iterator &&it) {
  iterator_node_ = it.iterator_node_;
  it.iterator_node_ = nullptr;
};

template <typename value_type>
typename Set<value_type>::iterator &Set<value_type>::iterator::operator++(){

};

template <typename value_type>
typename Set<value_type>::iterator &Set<value_type>::iterator::operator++() {
  if (iterator_node_) {
    if (iterator_node_->right) {
      iterator_node_ = iterator_node_->right;
      while (iterator_node_->left) iterator_node_ = iterator_node_->left;
    } else {
      while (iterator_node_->parent->parent != iterator_node_ &&
             iterator_node_->parent->key < iterator_node_->key) {
        iterator_node_ = iterator_node_->parent;
      }
      iterator_node_ = iterator_node_->parent;
    }
  }
  return *this;
};

template <typename value_type>
typename Set<value_type>::iterator &Set<value_type>::iterator::operator--() {
  if (iterator_node_) {
    if (iterator_node_->parent->parent == iterator_node_ &&
        iterator_node_->height == -1) {
      iterator_node_ = iterator_node_->parent;
      while (iterator_node_->right) iterator_node_ = iterator_node_->right;
    } else if (iterator_node_->left) {
      iterator_node_ = iterator_node_->left;
      while (iterator_node_->right) iterator_node_ = iterator_node_->right;
    } else {
      while (iterator_node_->parent->key > iterator_node_->key) {
        iterator_node_ = iterator_node_->parent;
      }
      iterator_node_ = iterator_node_->parent;
    }
  }
  return *this;
};

}  // namespace s21