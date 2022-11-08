#include "DoubleLinkedList.h"

template <class Item> class deque {
  public:
    deque();
    deque(const deque<Item> &source);
    ~deque();
    void push_front(const Item &entry);
    void push_back(const Item &entry);
    void pop_front();
    void pop_back();
    void operator=(const deque<Item> &source);
    bool empty() const { return (count == 0); }
    Item front() const;
    Item rear() const;
    size_t size() const { return count; }

  private:
    dnode<Item> *front_ptr;
    dnode<Item> *rear_ptr;
    size_t count;
};

template <class Item> deque<Item>::deque() {
    count = 0;
    front_ptr = NULL;
    rear_ptr = NULL;
}

template <class Item> deque<Item>::deque(const deque<Item> &source) {
    count = source.count;
    list_copy(source.front_ptr, front_ptr, rear_ptr);
}

template <class Item> deque<Item>::~deque() { list_clear(front_ptr); }

template <class Item> void deque<Item>::push_front(const Item &entry) {
    if (empty()) {
        list_insert_empty(front_ptr, rear_ptr, entry);
    } else {
        list_insert_before(front_ptr, entry);
    }
    count++;
}

template <class Item> void deque<Item>::push_back(const Item &entry) {
    if (empty()) {
        list_insert_empty(front_ptr, rear_ptr, entry);
    } else {
        list_insert_after(rear_ptr, entry);
    }
    count++;
}

template <class Item> void deque<Item>::pop_front() {
    assert(!empty());
    list_remove(front_ptr);
    count--;
    if (empty())
        rear_ptr = NULL;
}

template <class Item> void deque<Item>::pop_back() {
    assert(!empty());
    list_remove(rear_ptr);
    count--;
    if (empty())
        front_ptr = NULL;
}

template <class Item> void deque<Item>::operator=(const deque<Item> &source) {
    if (this == &source)
        return;
    list_clear(front_ptr);
    list_copy(source.front_ptr, front_ptr, rear_ptr);
    count = source.count;
}

template <class Item> Item deque<Item>::front() const {
    assert(!empty());
    return front_ptr->get_data();
}

template <class Item> Item deque<Item>::rear() const {
    assert(!empty());
    return rear_ptr->get_data();
}
