namespace s21 {
template <typename key_type, typename mapped_type>
map<key_type, mapped_type>::map() : tree_{} {};

template <typename key_type, typename mapped_type>
map<key_type, mapped_type>::map(
    std::initializer_list<value_type> const &items) {
  for (auto it : items) {
    tree_.Insert(it);
  }
};

template <typename key_type, typename mapped_type>
map<key_type, mapped_type>::map(const map &m) : tree_{m.tree_} {};

template <typename key_type, typename mapped_type>
map<key_type, mapped_type>::map(map &&m) : tree_{std::move(m.tree_)} {};

template <typename key_type, typename mapped_type>
map<key_type, mapped_type> &map<key_type, mapped_type>::operator=(
    const map &m) {
  tree_ = m.tree_;
  return *this;
};

template <typename key_type, typename mapped_type>
map<key_type, mapped_type> &map<key_type, mapped_type>::operator=(map &&m) {
  tree_ = std::move(m.tree_);
  return *this;
};

template <typename key_type, typename mapped_type>
mapped_type &map<key_type, mapped_type>::at(const key_type &key) {
  node_type *tmp = tree_.Find(value_type{key, mapped_type{}});
  if (!tmp) throw std::out_of_range("Map dosen't contain this elem!");
  return tmp->value.second;
};

template <typename key_type, typename mapped_type>
mapped_type &map<key_type, mapped_type>::operator[](const key_type &key) {
  node_type *tmp = tree_.Find(value_type{key, mapped_type{}});
  if (!tmp) {
    auto returned = tree_.Insert(value_type{key, mapped_type{}});
    return returned->value.second;
  };
  return tmp->value.second;
}

template <typename key_type, typename mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::begin() {
  return iterator{tree_.Begin()};
};

template <typename key_type, typename mapped_type>
typename map<key_type, mapped_type>::iterator
map<key_type, mapped_type>::end() {
  return iterator{tree_.End()};
};

template <typename key_type, typename mapped_type>
bool map<key_type, mapped_type>::empty() {
  return tree_.Empty();
};

template <typename key_type, typename mapped_type>
typename map<key_type, mapped_type>::size_type
map<key_type, mapped_type>::size() {
  return tree_.GetSize();
};

template <typename key_type, typename mapped_type>
typename map<key_type, mapped_type>::size_type
map<key_type, mapped_type>::max_size() {
  return tree_.MaxSize();
};

template <typename key_type, typename mapped_type>
void map<key_type, mapped_type>::clear() {
  tree_.Clear();
};

template <typename key_type, typename mapped_type>
std::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert(const value_type &value) {
  node_type *tmp = tree_.Insert(value);
  iterator it(tmp);
  return std::pair<iterator, bool>(it, tmp);
};

template <typename key_type, typename mapped_type>
std::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert(const key_type &key,
                                   const mapped_type &obj) {
  node_type *tmp = tree_.Insert(value_type{key, obj});
  iterator it(tmp);
  return std::pair<iterator, bool>(it, tmp);
};

template <typename key_type, typename mapped_type>
std::pair<typename map<key_type, mapped_type>::iterator, bool>
map<key_type, mapped_type>::insert_or_assign(const key_type &key,
                                             const mapped_type &obj) {
  node_type *tmp = tree_.Find(value_type{key, mapped_type{}});
  bool inserted{};
  if (tmp) {
    tmp->value.second = obj;
  } else {
    tmp = tree_.Insert(value_type{key, obj});
    inserted = true;
  }
  iterator it(tmp);
  return std::pair<iterator, bool>(it, inserted);
}

template <typename key_type, typename mapped_type>
void map<key_type, mapped_type>::erase(iterator pos) {
  tree_.Erase(tree_.Find(*pos));
};

template <typename key_type, typename mapped_type>
void map<key_type, mapped_type>::swap(map &other) {
  std::swap(tree_, other.tree_);
};

template <typename key_type, typename mapped_type>
void map<key_type, mapped_type>::merge(map &other) {
  tree_.Merge(other.tree_);
};

template <typename key_type, typename mapped_type>
bool map<key_type, mapped_type>::contains(const key_type &key) {
  return tree_.Find(value_type{key, mapped_type{}});
};

}  // namespace s21