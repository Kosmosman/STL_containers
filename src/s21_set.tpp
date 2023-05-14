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

template <typename value_type>
Set<value_type>::iterator &Set<value_type>::iterator::operator++(
    Set<value_type>::iterator &pos){

};

template <typename value_type>
Set<value_type>::referensce Set<value_type>::SetIterator::operator->(){};

/* ------------------------- MODIFIRE ------------------------   ---- */

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
  for (auto it = other.Begin(); it != other.End(); it++) {
    Insert(it.iterator_node_);
  }
};

}  // namespace s21