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
        Node* prev;
        Node* next;
    };


    // void insert(int value) {
    //     Node* newNode = new Node; // Allocate memory for a new node
    //     newNode->value = value;
    //     newNode->next = head;
    //     head = newNode;
    // }

    // void printList() {
    //     Node* current = head;
    //     while (current != NULL) {
    //         cout << current->data << " ";
    //         current = current->next;
    //     }
    //     cout << endl;
    // }
    // нужна функция init struct Node


    size_type size;
    Node* headNode;
    Node* teilNode;
    Node* endNode;

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
};
};