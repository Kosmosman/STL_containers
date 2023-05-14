namespace s21 {

/* ---------------- CONSTRUCTORS ------------------ */

template <typename K, typename V>
AvlTree<K, V>::AvlTree() noexcept : size_{0}, head_(nullptr){};

template <typename K, typename V>
AvlTree<K, V>::AvlTree(std::initializer_list<K> const& init) : AvlTree() {
  for (auto i : init) Insert(i, i);
};

template <typename K, typename V>
AvlTree<K, V>::AvlTree(const AvlTree<K, V>& other)
    : size_(other.size_), head_(nullptr) {
  if (other.head_) {
    head_ = new Node<K, V>();
    CopyTree(head_, other.head_);
  }
};

template <typename K, typename V>
AvlTree<K, V>::AvlTree(AvlTree<K, V>&& other) noexcept
    : size_(other.size_), head_(other.head_) {
  other.head_ = nullptr;
  other.size_ = 0;
}

/* ----------------- DESTRUCTOR ------------------- */

template <typename K, typename V>
AvlTree<K, V>::~AvlTree() {
  if (head_) Clear(head_);
};

/* ------------------- INSERT --------------------- */

/// @brief Добавление элемента в множество
template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::InnerInsert(Node<K, V>* node, const K& key,
                                       const V& value) {
  Node<K, V>* tmp = nullptr;
  if (key > node->key && node->right) InnerInsert(node->right, key, value);
  if (key < node->key && node->left) InnerInsert(node->left, key, value);
  if (!node->right && key > node->key) {
    node->right = new Node<K, V>{key, value, 0};
    tmp = node->right;
    ++size_;
  } else if (!node->left && key < node->key) {
    node->left = new Node<K, V>{key, value, 0};
    tmp = node->left;
    ++size_;
  }
  UpdateHeight(node);
  Balance(node, GetBalance(node));
  return tmp;
}

/// @brief Добавление первого элемента в множество
template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::Insert(const K& key, const V& value) {
  Node<K, V>* result = nullptr;
  if (!size_) {
    size_ = 1;
    head_ = new Node<K, V>{key, value, 0};
    result = head_;
  } else {
    result = InnerInsert(head_, key, value);
  }
  return result;
}

/// @brief Обход дерева с выбором режима взаимодействия
template <typename K, typename V>
void AvlTree<K, V>::Clear(Node<K, V>* node) {
  if (node->left) Clear(node->left);
  if (node->right) Clear(node->right);
  delete node;
}

/* --------------- BALANCE ------------------- */

/// @brief Проверка на необходимость балансировки дерева
template <typename K, typename V>
void AvlTree<K, V>::Balance(Node<K, V>* node, int diff) {
  if (diff == 2) {
    if (GetBalance(node->left) == -1) LeftRotate(node->left);
    RightRotate(node);
  } else if (diff == -2) {
    if (GetBalance(node->right) == 1) RightRotate(node->right);
    LeftRotate(node);
  }
}

/// @brief Правый поворот
template <typename K, typename V>
void AvlTree<K, V>::RightRotate(Node<K, V>* node) {
  SwapNode(node, node->left);
  Node<K, V>* buffer = node->right;
  node->right = node->left;
  node->right->parent = node;
  node->left = node->left->left;
  if (node->left) node->left->parent = node;
  node->right->left = node->right->right;
  node->right->right = buffer;
  if (node->right->right) node->right->right->parent = node->right;
  UpdateHeight(node->right);
  UpdateHeight(node);
}

/// @brief Левый поворот
template <typename K, typename V>
void AvlTree<K, V>::LeftRotate(Node<K, V>* node) {
  SwapNode(node, node->right);
  Node<K, V>* buffer = node->left;
  node->left = node->right;
  node->left->parent = node;
  node->right = node->right->right;
  if (node->right) node->right->parent = node;
  node->left->right = node->left->left;
  node->left->left = buffer;
  if (node->left->left) node->left->left->parent = node->left;
  UpdateHeight(node->left);
  UpdateHeight(node);
}

template <typename K, typename V>
void AvlTree<K, V>::UpdateHeight(Node<K, V>* node) {
  node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
}

template <typename K, typename V>
int AvlTree<K, V>::GetHeight(const Node<K, V>* node) const {
  return node ? node->height : -1;
}

template <typename K, typename V>
int AvlTree<K, V>::GetBalance(const Node<K, V>* node) const {
  return GetHeight(node->left) - GetHeight(node->right);
}

/* ------------------ ERACE ---------------------- */

/// @brief Поиск ключа и удаление листа
template <typename K, typename V>
void AvlTree<K, V>::Erase(Node<K, V>* node) {
  Node<K, V>* tmp = node;
  if (!node->left && !node->right) {
    tmp = node->parent;
    key == tmp->left->key ? tmp->left = nullptr : tmp->right = nullptr;
    delete node;
  } else if (!node->right) {
    SwapNode(node, node->left);
    node->height = 0;
    delete node->left;
    node->left = nullptr;
  } else if (!node->left) {
    SwapNode(node, node->right);
    node->height = 0;
    delete node->right;
    node->right = nullptr;
  } else {
    tmp = FindExtremum(tmp, GetBalance(tmp));
    SwapNode(node, tmp);
    InnerErase(tmp);
  }
  while (tmp) {
    UpdateHeight(tmp);
    Balance(tmp, GetBalance(tmp));
    tmp = tmp->parent;
  }
}

/* ---------------------- FIND ------------------------ */

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::Find(const K& key) {
  Node<K, V>* tmp = head_;
  bool check = false;
  return InnerFind(head_, key, check);
}

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::InnerFind(Node<K, V>* node, const K& key,
                                     bool& res) {
  if (node) {
    if (!res && key > node->key) node = InnerFind(node->right, key, res);
    if (!res && key < node->key) node = InnerFind(node->left, key, res);
    if (!res && node->key == key) res = true;
  } else {
    res = true;
  }
  return node;
}

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::FindExtremum(Node<K, V>* node, int balance) {
  Node<K, V>* tmp{};
  if (balance < 0) {
    tmp = node->right;
    while (tmp->left) tmp = tmp->left;
  } else {
    tmp = node->left;
    while (tmp->right) tmp = tmp->right;
  }
  return tmp;
}

template <typename K, typename V>
void AvlTree<K, V>::PrintTree() {
  std::queue<Node<K, V>*> q;
  if (head_) {
    q.push(head_);
    while (!q.empty()) {
      if (q.front()->left) q.push(q.front()->left);
      if (q.front()->right) q.push(q.front()->right);
      std::cout << q.front()->value << std::endl;
      q.pop();
    }
  }
}

/* -------------------- COPY AND SWAP ---------------------- */

template <typename K, typename V>
AvlTree<K, V>& AvlTree<K, V>::CopyTree(Node<K, V>* node,
                                       const Node<K, V>* other_node) {
  CopyNode(node, other_node);
  if (other_node->left) {
    node->left = new Node<K, V>();
    node->left->parent = node;
    CopyTree(node->left, other_node->left);
  }
  if (other_node->right) {
    node->right = new Node<K, V>();
    node->right->parent = node;
    CopyTree(node->right, other_node->right);
  }
  return *this;
}

template <typename K, typename V>
void AvlTree<K, V>::CopyNode(Node<K, V>* node, const Node<K, V>* other_node) {
  node->height = other_node->height;
  node->key = other_node->key;
  node->value = other_node->value;
}

template <typename K, typename V>
AvlTree<K, V>& AvlTree<K, V>::SwapTree(AvlTree<K, V>&& other_tree) {
  std::swap(head_, other_tree.head_);
  std::swap(size_, other_tree.size_);
  other_tree.Clear();
  return *this;
}

/// @brief Обмен ключ-значение между двумя узлами
template <typename K, typename V>
void AvlTree<K, V>::SwapNode(Node<K, V>* one, Node<K, V>* two) {
  K buffer_key = one->key;
  V buffer_value = one->value;
  one->key = two->key;
  one->value = two->value;
  two->key = buffer_key;
  two->value = buffer_value;
}

/* -------------------- BEGIN AND END ------------------------- */

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::Begin() {
  Node<K, V>* tmp = head_;
  if (head_) {
    while (tmp->left) tmp = tmp->left;
  }
  return tmp;
};

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::End() {
  Node<K, V>* tmp = head_;
  if (head_) {
    while (tmp->right) tmp = tmp->right;
  }
  return tmp;
};

};  // namespace s21
