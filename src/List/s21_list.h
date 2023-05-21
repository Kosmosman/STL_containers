namespace ft {

template<typename T>
class list {
    public:
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;
    // или ,без инициализации
//    typedef ListIterator iterator;
//    typedef const ListIterator const_iterator;
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

    // push_front(begin(), value);

    void clear();
    void push_back(const_reference value);
    void pop_back();
    void push_front(const_reference value);
    void pop_front();
    void swap(list& other);
    void merge(list& other);
    void reverse();
    void unique();
    void sort();

     template <typename value_type>
     class ListIterator {
       public:
       ListIterator();
       ListIterator(Node* ptr) : ptr_(ptr);

         reference operator*() {
             return *ptr->_value
         }
         ListIterator operator--(int) {
             ptr_ = ptr_->prev_;
             return *this;
         }
         ListIterator operator++(int) {
             ptr_ = ptr_->next_;
             return *this;
         }

         ListIterator& operator--(int) {
             ptr_ = ptr_->prev_;
             return *this;
         }
         ListIterator& operator++(int) {
             ptr_ = ptr_->next_;
             return *this;
         }

         bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }
         bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }

     private:
         Node* ptr_ = nullptr;
         friend class list<T>;
     }

    template <typename value_type>
    class ListConstIterator : public ListIterator<T> {
    public:
        ListConstIterator(ListIterator<T> other) : ListIterator<T>(other) {}
        const T& operator*() { return ListIterator<T>::operator*(); }
    };
    };
};