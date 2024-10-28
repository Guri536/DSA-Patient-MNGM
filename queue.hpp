// #include<bits/stdc++.h>
// #include"linked_list.hpp"
using namespace std;

template<typename type>
class m_queue : private linked_list<type> {
public:

    template<typename ...ARGS>
    void enque(ARGS ...args) { (enque(args), ...); }

    void enque(type val) {
        this->append(val);
    }
    type* deque() {
        if (this->is_empty()) { throw invalid_argument("Queue is Empty"); }
        type* temp = (*this)[0];
        typename linked_list<type>::Iterator iter = this->begin();
        this->head = iter->link;
        this->_size--;
        return temp;
    }
    type* seek() {
        if (this->is_empty()) { throw invalid_argument("Queue is Empty"); }
        return (*this)[0];
    }
    void print() {
        this->linked_list<type>::print();
    }
    void println() {
        print();
        std::println();
    }

    int size() { return this->linked_list<type>::size(); }

    bool is_empty() { return this->linked_list<type>::is_empty(); }

    void clear() { this->linked_list<type>::clear(); }
};