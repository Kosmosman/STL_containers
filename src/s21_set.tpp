namespace s21 {

/* ------------------ CONSTRUSCTORS / DESTRUCTOR ---------------- */

template <typename value_type>
Set<value_type>::Set() : tree{} {};

template <typename value_type>
Set<value_type>::Set(std::initializer_list<value_type> const &items)
    : tree{items} {};

template <typename value_type>
Set<value_type>::Set(const Set &s) : tree{s.tree} {};

template <typename value_type>
Set<value_type>::Set(Set &&s) : tree{std::move(s.tree)} {};

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

/* ------------------------ BEGIN / END -------------------------- */

template <typename value_type>
typename Set<value_type>::iterator Set<value_type>::begin() {
  return iterator(tree.Begin());
};

template <typename value_type>
typename Set<value_type>::iterator Set<value_type>::end() {
  return iterator(tree.End());
};

/* ------------------------- CAPACITY ---------------------------- */

template <typename value_type>
bool Set<value_type>::Empty() {
  return tree.Empty();
};

template <typename value_type>
typename Set<value_type>::size_type Set<value_type>::Size() {
  return tree.GetSize();
};

template <typename value_type>
typename Set<value_type>::size_type Set<value_type>::Max_size() {
  return tree.MaxSize();
};

/* ------------------------- MODIFIRE ---------------------------- */

template <typename value_type>
void Set<value_type>::Clear() {
  tree.Clear();
};

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

/* ----------------------------- LOOKUP ------------------------------- */

template <typename value_type>
typename Set<value_type>::iterator Set<value_type>::Find(const key_type &key) {
  return iterator(tree.Find(key));
};

template <typename value_type>
bool Set<value_type>::Contains(const key_type &key) {
  return tree.Find(key);
};

/* ---------------------------- ITERATOR ------------------------------ */

template <typename value_type>
Set<value_type>::SetIterator::SetIterator() : iterator_node_{nullptr} {};

template <typename value_type>
Set<value_type>::SetIterator::SetIterator(node_type *node)
    : iterator_node_{node} {};

template <typename value_type>
Set<value_type>::SetIterator::SetIterator(const iterator &other)
    : iterator_node_{other.iterator_node_} {};

template <typename value_type>
Set<value_type>::SetIterator::SetIterator(iterator &&other)
    : iterator_node_{other.iterator_node_} {
  other.iterator_node_ = nullptr;
};

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
bool Set<value_type>::iterator::operator!=(const iterator &it) {
  return iterator_node_ != it.iterator_node_;
};

template <typename value_type>
bool Set<value_type>::iterator::operator==(const iterator &it) {
  return iterator_node_ == it.iterator_node_;
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
  if (const_iterator::iterator_node_)
    return const_iterator::iterator_node_->key;
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