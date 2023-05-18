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
  for (auto it : other) {
    Insert(it.iterator_node_);
  }
};

/* ---------------------------- ITERATOR ------------------------------ */

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
typename Set<value_type>::iterator Set<value_type>::iterator::operator++(int) {
  iterator tmp = *this;
  operator++();
  return tmp;
};

template <typename value_type>
typename Set<value_type>::reference Set<value_type>::iterator::operator*() {
  if (iterator_node_) return iterator_node_->key;
  static value_type empty_value = value_type{};
  return empty_value;
};

template <typename value_type>
typename Set<value_type>::const_reference
Set<value_type>::const_iterator::operator*() {
  if (SetConstIterator::iterator_node_)
    return SetConstIterator::iterator_node_->key;
  static value_type empty_value = value_type{};
  return empty_value;
};

template <typename value_type>
typename Set<value_type>::iterator Set<value_type>::iterator::operator--(int) {
  iterator tmp = *this;
  operator--();
  return tmp;
};

template <typename value_type>
typename Set<value_type>::iterator &Set<value_type>::iterator::operator++() {
  if (iterator_node_) iterator_node_ = iterator_node_->NextNode();
  return *this;
};

template <typename value_type>
typename Set<value_type>::iterator &Set<value_type>::iterator::operator--() {
  if (iterator_node_) iterator_node_ = iterator_node_->PreviousNode();
  return *this;
};

/* ------------------------- CONST ITERATOR ---------------------------- */

}  // namespace s21