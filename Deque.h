#include "DoublyLinkedList.h"

/* This is template class deque. The deque is implemented by Doubly Linked List.
 * The deque can push and pop the items at both ends. */

template <class Item> class deque {
  public:
    // Default Constructor
    deque();

    // Copy Constructor
    deque(const deque<Item> &source);

    // Destructor
    ~deque();

    // The push_front() function inserts the item at front.
    // Pre : None.
    // Post : The node is inserted in front of list. The front_ptr points to
    //        this node. If list is empty, the rear_ptr points to this node
    //        together.
    void push_front(const Item &entry);

    // The push_back() function appends the item at rear.
    // Pre : None.
    // Post : The node is inserted in rear of list. The rear_ptr points to
    //        this node. If list is empty, the front_ptr points to this node
    //        together.
    void push_back(const Item &entry);

    // The pop_front() function removes the item at front.
    // Pre : The deque is not empty.
    // Post : The node is removed in front of list. The front_ptr is updated.
    //        If the list has only one node, then list is empty.
    void pop_front();

    // The pop_back() function removes the item at rear.
    // Pre : The deque is not empty.
    // Post : The node is removed in rear of list. The rear_ptr is updated.
    //        If the list has only one node, then list is empty.
    void pop_back();

    // The operator=() is assignment operator.
    // Pre : None.
    // Post : This deque is copied(deep copy) by source deque.
    void operator=(const deque<Item> &source);

    // The empty() function returns whether this deque is empty.
    // Pre : None.
    // Post : Whether this deque is empty is returned.
    bool empty() const { return (count == 0); }

    // The front() function returns first item, but doesn't remove that item.
    // Pre : The deque is not empty.
    // Post : The item in node that front_ptr points to is returned.
    Item front() const;

    // The rear() function returns last item, but doesn't remove that item.
    // Pre : The deque is not empty.
    // Post : The item in node that rear_ptr points to is returned.
    Item rear() const;

    // The size() function returns the number of items in deque.
    // Pre : None.
    // Post : The count is returned.
    size_t size() const { return count; }

  private:
    dnode<Item> *front_ptr; // point to the node that has the first item.
    dnode<Item> *rear_ptr;  // point to the node that has the last item.
    size_t count;           // the number of items.
};

template <class Item> deque<Item>::deque() {
    // empty deque
    count = 0;
    front_ptr = NULL;
    rear_ptr = NULL;
}

template <class Item> deque<Item>::deque(const deque<Item> &source) {
    count = source.count;
    list_copy(source.front_ptr, front_ptr, rear_ptr); // deep copy
}

template <class Item> deque<Item>::~deque() { list_clear(front_ptr, rear_ptr); }

template <class Item> void deque<Item>::push_front(const Item &entry) {
    if (empty()) { // The list is empty. So call list_insert_empty().
        list_insert_empty(front_ptr, rear_ptr, entry);
    } else { // The list is not empty. So call list_insert_before().
        list_insert_before(front_ptr, entry);
    }
    count++;
}

template <class Item> void deque<Item>::push_back(const Item &entry) {
    if (empty()) { // The list is empty. So call list_insert_empty().
        list_insert_empty(front_ptr, rear_ptr, entry);
    } else { // The list is not empty. So call list_insert_after().
        list_insert_after(rear_ptr, entry);
    }
    count++;
}

template <class Item> void deque<Item>::pop_front() {
    assert(!empty()); // Precondition.
    list_remove(front_ptr);
    count--;

    /* If this list becomes to empty, rear_ptr should be assigned with NULL.
       Because, list_remove(front_ptr) only update the front_ptr. */
    if (empty())
        rear_ptr = NULL;
}

template <class Item> void deque<Item>::pop_back() {
    assert(!empty()); // Precondition.
    list_remove(rear_ptr);
    count--;

    /* If this list becomes to empty, front_ptr should be assigned with NULL.
       Because, list_remove(rear_ptr) only update the rear_ptr. */
    if (empty())
        front_ptr = NULL;
}

template <class Item> void deque<Item>::operator=(const deque<Item> &source) {
    if (this == &source) // self-assignment.
        return;
    list_clear(front_ptr, rear_ptr); // Free the memory that original list used.
    list_copy(source.front_ptr, front_ptr, rear_ptr); // deep copy.
    count = source.count;
}

template <class Item> Item deque<Item>::front() const {
    assert(!empty()); // Precondition.
    return front_ptr->get_data();
}

template <class Item> Item deque<Item>::rear() const {
    assert(!empty()); // Precondition.
    return rear_ptr->get_data();
}
