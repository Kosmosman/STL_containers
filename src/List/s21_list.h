namespace ft {

template<typename T>
class list {
    public:
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;

    private:
    typedef struct Node
    {
        value_type value;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    // Node() : value(), prev(nullptr), next(nullptr) {}
    //   void init() {
    //     m_size = 0;
    //     m_head = nullptr;
    //     m_tail = nullptr;
    //     m_end = new Node();
    //     m_end->prev = nullptr;
    //     m_end->next = nullptr;
    // }

    size_type size = 0;
    Node* headNode = nullptr;
    Node* teilNode = nullptr;
    Node* endNode = nullptr;

    //В этой таблице перечислены основные 
    //публичные методы для взаимодействия с классом:
    public:
    list(); // конструктор по умолчанию, создает пустой список
    list(size_type n); // параметризованный конструктор, создает список размера n
    list(std::initializer_list<value_type> const& items); // конструктор списка инициализаторов, создает список, инициализированный с помощью std::initializer_list
    list(const list& l); // конструктор копирования
    list(list&& l); // конструктор перемещения
    ~list(); // деструктор
    list& operator=(list&& l); // Перегрузка оператора присваивания для движущегося объекта


public:
  const_reference front();
  const_reference back();

// const noexcept
  bool empty();
  size_type size();
  size_type max_size();
};
};