namespace s21 {

/* ------------------ CONSTRUSCTORS / DESTRUCTOR ---------------- */

template <typename value_type>
set<value_type>::set() : tree_{} {};

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const &items)
    : tree_{items} {};

template <typename value_type>
set<value_type>::set(const set &s) : tree_{s.tree_} {};

template <typename value_type>
set<value_type>::set(set &&s) : tree_{std::move(s.tree_)} {};

/* ------------------------ OPERATORS --------------------------- */

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set<value_type> &s) {
  tree_ = s.tree_;
  return *this;
};

template <typename value_type>
set<value_type> &set<value_type>::operator=(set<value_type> &&s) {
  tree_ = std::move(s.tree_);
  return *this;
};

/* ------------------------ BEGIN / END -------------------------- */

template <typename value_type>
typename set<value_type>::iterator set<value_type>::begin() {
  return iterator(tree_.Begin());
};

template <typename value_type>
typename set<value_type>::iterator set<value_type>::end() {
  return iterator(tree_.End());
};

/* ------------------------- CAPACITY ---------------------------- */

template <typename value_type>
bool set<value_type>::empty() {
  return tree_.Empty();
};

template <typename value_type>
typename set<value_type>::size_type set<value_type>::size() {
  return tree_.GetSize();
};

template <typename value_type>
typename set<value_type>::size_type set<value_type>::max_size() {
  return tree_.MaxSize();
};

/* ------------------------- MODIFIRE ---------------------------- */

template <typename value_type>
void set<value_type>::clear() {
  tree_.Clear();
};

template <typename value_type>
std::pair<typename set<value_type>::iterator, bool> set<value_type>::insert(
    const value_type &value) {
  node_type *tmp = tree_.Insert(value, value);
  iterator it(tmp);
  return std::pair(it, tmp);
};

template <typename value_type>
void set<value_type>::erase(iterator pos) {
  tree_.Erase(tree_.Find(*pos));
};

template <typename value_type>
void set<value_type>::swap(set<value_type> &other) {
  std::swap(tree_, other.tree_);
};

template <typename value_type>
void set<value_type>::merge(set<value_type> &other) {
  tree_.Merge(other.tree_);
}

/* ----------------------------- LOOKUP ------------------------------- */

template <typename value_type>
typename set<value_type>::iterator set<value_type>::find(const key_type &key) {
  return iterator(tree_.Find(key));
};

template <typename value_type>
bool set<value_type>::contains(const key_type &key) {
  return tree_.Find(key);
};

}  // namespace s21