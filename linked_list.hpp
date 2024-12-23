#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include<bits/stdc++.h>
using namespace std;

class hasId {
public:
    virtual int getId() const = 0;
    virtual ~hasId() {}
};

template<typename data_type>
struct _node {
    data_type data{};
    _node<data_type>* link = nullptr;
    _node(data_type value) : data(value) {}
    _node(data_type value, _node<data_type>* _link) : data(value), link(_link) {}
    ~_node() {
        if (link != nullptr)
            delete link;
    }
    data_type operator*() { return data; }
};

template<typename s_data_type>
struct linked_list {
public:
    typedef _node<s_data_type> node;
    typedef s_data_type dt;
    int _size{};
    node* head = nullptr;
    node* last = nullptr;

    struct Iterator {
    private:
        node* ptr;
    public:
        Iterator(node* _ptr) : ptr(_ptr) {}
        dt* operator*() { return &(ptr->data); }
        node* operator->() { return ptr; }
        Iterator* operator++() { ptr = ptr->link; return this; }
        Iterator* operator++(int) { return ++ * this; }
        bool operator!=(Iterator check) { return !(&(*ptr) == &(*check.ptr)); }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(last); }

    template<typename ...Args> linked_list(Args ...arg) { (append(arg), ...); }
    template<typename ...Args> void appends(Args ...arg) { (append(arg), ...); }

    dt* operator[](const int index) {
        linked_list::Iterator iter = begin();
        for (int i{ index }; i > 0; i--) { iter++; }
        return *iter;
    }

    void append(const dt value) {
        if (this->head == nullptr) {
            head = new node(value);
            last = head;
        }
        else {
            last->link = new node(value);
            last = last->link;
        }
        _size++;
    }

    void prepend(const dt value) {
        head = new node(value, head);
        _size++;
    }

    void end_update() noexcept {
        while (last->link != nullptr) { last = last->link; }
    }

    int size() { return _size; }

    template<typename>
    friend ostream& operator<<(ostream&, dt&);

    template <typename T, typename N = void>
    struct check : false_type {};

    template <typename T>
    struct check<T, void_t<decltype(std::declval<std::ostream&>() << std::declval<T&>())>> : std::true_type {};

    template<typename T = void>
    auto print() noexcept -> enable_if<check<dt>::value, T>::type {
        std::print("{} ", "{");
        for (linked_list::Iterator iter = begin(); iter != nullptr; iter++) {
            cout << **iter; cout << (iter->link == nullptr ? " " : ", ");
        }
        std::print("{}", "}");
    }

    template<typename T = void>
    auto print() noexcept -> enable_if<!check<dt>::value, T>::type {
        std::print("No Return Type for ");
        cout << typeid(dt).name();
    }

    void println() {
        print();
        std::println();
    }

    void insert(const int index, const dt value) {
        node* temp = new node(value);
        linked_list::Iterator iter = begin();
        for (int i{}; i < index - 1; i++) { iter++; }
        temp->link = (index == 0 ? head : iter->link);
        (index == 0 ? head : iter->link) = temp;
        end_update();
        _size++;
    }

    void replace(const int index, const dt value) {
        linked_list::Iterator iter = begin();
        for (int i{}; i < index; i++) { iter++; }
        iter->data = value;
    }

    void clear() noexcept {
        delete head;
        head = nullptr;
        last = nullptr;
        _size = 0;
    }

    /// @brief Returns the Index of the value if found, if not in list, returns -1
    /// @param val The value to be found
    /// @param skip Default: 0 =>If multiple of the same element exists, then the no. of skips will correspond to which one of the duplicates will be send back
    /// @return int
    int find(const dt value, int skip = 0) {
        int index{};
        for (linked_list::Iterator iter{ begin() }; iter != nullptr; iter++, index++) {
            if (*iter == value && skip-- == 0) {
                return index;
            }
        }
        return -1;
    }

    template<typename T = dt>
    typename enable_if<is_base_of<hasId, T>::value, int>::type
        searchById(int id) {
        int index{};
        for (linked_list::Iterator iter{ begin() }; iter != nullptr; iter++, index++) {
            if (iter->data.getId() == id) {
                return index;
            }
        }
        return -1;
    }

    void del(const dt value) {
        linked_list::Iterator iter{ begin() };
        if (*iter == value) {
            head = iter->link;
        }
        else {
            while (iter->link->data != value) { iter++; }
            node* temp = iter->link;
            iter->link = iter->link->link;
        }
        _size--;
        end_update();
    }
    void delin(const int indexa, const int indexb = 1) {
        linked_list::Iterator iter{ begin() };
        for (int i{};i < indexa - 1;i++) { iter++; }
        linked_list::Iterator iter2{ iter->link };
        for (int i{};i < indexb - (indexa != 0 ? 1 : 2);i++) { iter2++; }
        (indexa == 0 ? head : iter->link) = iter2->link;
        _size -= indexb;
        end_update();
    }

    bool is_empty() { return (head == nullptr ? true : false); }
};

#endif