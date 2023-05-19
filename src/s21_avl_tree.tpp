namespace s21 {

/* -------- CONSTRUCTORS / DESTRUCTORS ---------- */

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
    CreateEnd();
    CopyTree(head_, other.head_);
  }
};

template <typename K, typename V>
AvlTree<K, V>::AvlTree(AvlTree<K, V>&& other) noexcept
    : size_(other.size_), head_(other.head_) {
  other.head_ = nullptr;
  other.size_ = 0;
}

template <typename K, typename V>
AvlTree<K, V>::~AvlTree() {
  Clear();
};

/* ------------------- OPERATORS --------------------- */

template <typename K, typename V>
AvlTree<K, V>& AvlTree<K, V>::operator=(const AvlTree<K, V>& other) {
  CopyTree(head_, other.head_);
};

template <typename K, typename V>
AvlTree<K, V>& AvlTree<K, V>::operator=(AvlTree<K, V>&& other) {
  SwapTree(other);
};

/* ------------------- INSERT --------------------- */

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::InnerInsert(Node<K, V>* node, const K& key,
                                       const V& value) {
  Node<K, V>* tmp = nullptr;
  if (key > node->key && node->right) InnerInsert(node->right, key, value);
  if (key < node->key && node->left) InnerInsert(node->left, key, value);
  if (!node->right && key > node->key) {
    node->right = new Node<K, V>{key, value, 0};
    node->right->parent = node;
    tmp = node->right;
    ++size_;
  } else if (!node->left && key < node->key) {
    node->left = new Node<K, V>{key, value, 0};
    node->left->parent = node;
    tmp = node->left;
    ++size_;
  }
  UpdateHeight(node);
  Balance(node, GetBalance(node));
  return tmp;
}

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::Insert(const K& key, const V& value) {
  Node<K, V>* result = nullptr;
  if (!size_) {
    size_ = 1;
    head_ = new Node<K, V>{key, value, 0};
    result = head_;
    CreateEnd();
  } else {
    result = InnerInsert(head_, key, value);
  }
  return result;
}

template <typename K, typename V>
void AvlTree<K, V>::Clear() {
  if (head_) {
    delete head_->parent;
    DeleteNodes(head_);
    head_ = nullptr;
  };
}

template <typename K, typename V>
void AvlTree<K, V>::DeleteNodes(Node<K, V>* node) {
  if (node->left) DeleteNodes(node->left);
  if (node->right) DeleteNodes(node->right);
  delete node;
}

/* --------------- BALANCE ------------------- */

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

template <typename K, typename V>
void AvlTree<K, V>::Erase(Node<K, V>* node) {
  Node<K, V>* tmp = node;
  if (size_ == 1) delete head_->parent;
  if (!node->left && !node->right) {
    tmp = node->parent;
    node->key == tmp->left->key ? tmp->left = nullptr : tmp->right = nullptr;
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
    Erase(tmp);
  }
  --size_;
  while (tmp->parent != head_) {
    UpdateHeight(tmp);
    Balance(tmp, GetBalance(tmp));
    tmp = tmp->parent;
  }
}

/* ---------------------- FIND ------------------------ */

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::Find(const K& key) {
  Node<K, V>* tmp{head_};
  while (tmp) {
    if (key == tmp->key)
      break;
    else if (key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
  }
  return tmp;
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

template <typename K, typename V>
void AvlTree<K, V>::SwapNode(Node<K, V>* one, Node<K, V>* two) {
  K buffer_key = one->key;
  V buffer_value = one->value;
  one->key = two->key;
  one->value = two->value;
  two->key = buffer_key;
  two->value = buffer_value;
}

/* ---------------------- CAPACITY --------------------------- */

template <typename K, typename V>
bool AvlTree<K, V>::Empty() const {
  return !head_;
};

template <typename K, typename V>
size_t AvlTree<K, V>::GetSize() const {
  return size_;
};

template <typename K, typename V>
size_t AvlTree<K, V>::MaxSize() const {
  return (std::numeric_limits<size_t>::max() / 2) / sizeof(V) / 10;
};

/* -------------------- BEGIN AND END ------------------------- */

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::Begin() {
  Node<K, V>* tmp = head_;
  if (head_) {
    while (tmp->left) {
      tmp = tmp->left;
    }
  }
  return tmp;
};

template <typename K, typename V>
Node<K, V>* AvlTree<K, V>::End() {
  return head_->parent;
};

template <typename K, typename V>
void AvlTree<K, V>::CreateEnd() {
  Node<K, V>* tmp = new Node<K, V>{head_->key, head_->value, -1};
  tmp->parent = head_;
  head_->parent = tmp;
}

/* ------------------------ NODE ------------------------------ */

template <typename K, typename V>
Node<K, V>::Node() : key(0), value(0), height(0){};

template <typename K, typename V>
Node<K, V>::Node(K o_key, V o_value, int o_height)
    : key{o_key}, value{o_value}, height{o_height} {};

template <typename K, typename V>
Node<K, V>* Node<K, V>::NextNode() {
  Node<K, V>* node = this;
  if (node->right) {
    node = node->right;
    while (node->left) node = node->left;
  } else {
    while (node->parent->parent != node && node->parent->key < node->key) {
      node = node->parent;
    }
    node = node->parent;
  }
  return node;
}

template <typename K, typename V>
Node<K, V>* Node<K, V>::PreviousNode() {
  Node<K, V>* node = this;
  if (node->parent->parent == node && node->height == -1) {
    node = node->parent;
    while (node->right) node = node->right;
  } else if (node->left) {
    node = node->left;
    while (node->right) node = node->right;
  } else {
    while (node->parent->key > node->key) {
      node = node->parent;
    }
    node = node->parent;
  }
  return node;
}

};  // namespace s21