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
void Set<value_type>::Erase(iterator pos){};

template <typename value_type>
void Set<value_type>::Swap(Set<value_type> &other){};

template <typename value_type>
void Set<value_type>::Merge(Set<value_type> &other){};

}  // namespace s21