#include "Dnode.h"
#include <cassert>

/* This is DoublyLinkedList template function toolkit. The head_ptr is pointer
   of list's head node and tail_ptr is pointer of list's tail node. If list is
   empty, head_ptr and tail_ptr are NULL. */

// The list_length() function returns the length of list
// Pre : None.
// Post : The number of nodes in list is returned.
template <class Item> size_t list_length(const dnode<Item> *head_ptr);

// The list_search() function returns the pointer of node whose data_filed is
// target. There are two list_search() functions, first can change returned
// node's member variables and second can't change.
// Pre : None.
// Post : Pointer of node that exponent is exponent_target is returned.
//        If there is not exist that node or list is empty, NULL is returned.
template <class Item>
dnode<Item> *list_search(dnode<Item> *head_ptr, const Item &target);
template <class Item>
const dnode<Item> *list_search(const dnode<Item> *head_ptr, const Item &target);

// The list_locate() function returns the pointer of node whose forward order
// is position in list. There are two list_locate() functions, first can change
// returned node's member variables and second can't change.
// Pre : position > 0.
// Post : Pointer of node whose forward order is position is returned. If there
//        is not exist that node or list is empty, NULL is returned.
template <class Item>
dnode<Item> *list_locate(dnode<Item> *head_ptr, size_t position);
template <class Item>
const dnode<Item> *list_locate(const dnode<Item> *head_ptr, size_t position);

// The list_locate_reverse() function returns the pointer of node whose backward
// order is reverse_position in list. There are two list_locate_reverse()
// functions, first can change returned node's member variables and second can't
// change.
// Pre : position > 0.
// Post : Pointer of node whose backward order is reverse_position is returned.
//        If there is not exist that node or list is empty, NULL is returned.
template <class Item>
dnode<Item> *list_locate_reverse(dnode<Item> *tail_ptr,
                                 size_t reverse_position);
template <class Item>
const dnode<Item> *list_locate_reverse(const dnode<Item> *tail_ptr,
                                       size_t reverse_position);

// The list_insert_empty() function inserts the node in empty list. That node's
// data_field is new_data.
// Pre : The list is empty. So, head_ptr and tail_ptr are NULL.
// Post : The node is inserted in list. head_ptr and tail_ptr point to that
//        node. So they are call-by-reference.
template <class Item>
void list_insert_empty(dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr,
                       const Item &new_data);

// The list_insert_after() function inserts the node behind the node
// that previous_ptr points to. That node's data_field is new_data. If you want
// to insert the node front the head node, use list_head_before() function.
// Pre : previous_ptr is not NULL.
// Post : The node is inserted behind the node that previous_ptr point to.
//        If previous_ptr is tail_ptr, tail_ptr is updated. So, previous_ptr is
//        call-by-reference.
template <class Item>
void list_insert_after(dnode<Item> *&previous_ptr, const Item &new_data);

// The list_insert_before() function inserts the node front the node
// that next_ptr points to. That node's data_field is new_data. If you want
// to insert the node behind the tail node, use list_head_after() function.
// Pre : next_ptr is not NULL.
// Post : The node is inserted front the node that next_ptr point to.
//        If next_ptr is head_ptr, head_ptr is updated. So, next_ptr is
//        call-by-reference.
template <class Item>
void list_insert_before(dnode<Item> *&next_ptr, const Item &new_data);

// The list_remove() function removes the node that target_ptr points to.
// Pre : target_ptr is not NULL.
// Post : The node that target_ptr points to is removed. If target_ptr is
//        head_ptr, head_ptr is updated. If target_ptr is tail_ptr, tail_ptr is
//        updated. If this list only has one node, this list will become to
//        empty and target_ptr is assigned NULL.
template <class Item> void list_remove(dnode<Item> *&target_ptr);

// The list_clear() function removes all nodes in list.
// Pre : None.
// Post : The list is empty. head_ptr and tail_ptr are NULL.
template <class Item>
void list_clear(dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr);

// The list_copy() function copies(deep copy) the list.
// Pre : None.
// Post : The head_ptr points to the head node in the list that is copied from
//        source_ptr. The tail_ptr points to the tail node in the list that is
//        copied from source_ptr. If source_ptr is NULL, then head_ptr and
//        tail_ptr are NULL.
template <class Item>
void list_copy(const dnode<Item> *source_ptr, dnode<Item> *&head_ptr,
               dnode<Item> *&tail_ptr);

/* Implementation of function template */

template <class Item> size_t list_length(const dnode<Item> *head_ptr) {
    size_t answer = 0;
    const dnode<Item> *cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->get_link_fore())
        ++answer;
    return answer;
}

template <class Item>
dnode<Item> *list_search(dnode<Item> *head_ptr, const Item &target) {
    dnode<Item> *cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->get_link_fore())
        if (target == cursor->get_data())
            return cursor;
    return NULL;
}

template <class Item>
const dnode<Item> *list_search(const dnode<Item> *head_ptr,
                               const Item &target) {
    const dnode<Item> *cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->get_link_fore())
        if (target == cursor->get_data())
            return cursor;
    return NULL;
}

template <class Item>
dnode<Item> *list_locate(dnode<Item> *head_ptr, size_t position) {
    assert(0 < position); // Precondition.

    dnode<Item> *cursor = head_ptr;
    size_t i;
    for (i = 1; (cursor != NULL && i < position); ++i)
        cursor = cursor->get_link_fore();
    return cursor;
}

template <class Item>
const dnode<Item> *list_locate(const dnode<Item> *head_ptr, size_t position) {
    assert(0 < position); // Precondition.

    const dnode<Item> *cursor = head_ptr;
    size_t i;
    for (i = 1; (cursor != NULL && i < position); ++i)
        cursor = cursor->get_link_fore();
    return cursor;
}

template <class Item>
dnode<Item> *list_locate_reverse(dnode<Item> *tail_ptr,
                                 size_t reverse_position) {
    assert(0 < reverse_position); // Precondition.

    dnode<Item> *cursor = tail_ptr;
    size_t i;
    for (i = 1; (cursor != NULL && i < reverse_position); ++i)
        cursor = cursor->get_link_back();
    return cursor;
}

template <class Item>
const dnode<Item> *list_locate_reverse(const dnode<Item> *tail_ptr,
                                       size_t reverse_position) {
    assert(0 < reverse_position); // Precondition.

    const dnode<Item> *cursor = tail_ptr;
    size_t i;
    for (i = 1; (cursor != NULL && i < reverse_position); ++i)
        cursor = cursor->get_link_back();
    return cursor;
}

template <class Item>
void list_insert_empty(dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr,
                       const Item &new_data) {
    assert(head_ptr == NULL && tail_ptr == NULL); // Precondition.
    head_ptr = new dnode<Item>(new_data, NULL, NULL);
    tail_ptr = head_ptr;
}

template <class Item>
void list_insert_after(dnode<Item> *&previous_ptr, const Item &new_data) {
    assert(previous_ptr != NULL); // Precondition
    dnode<Item> *insert_ptr =
        new dnode<Item>(new_data, previous_ptr->get_link_fore(), previous_ptr);
    previous_ptr->set_link_fore(insert_ptr);

    // If the previous_ptr is tail_ptr, previous_ptr is updated with insert_ptr.
    if (insert_ptr->get_link_fore() == NULL)
        previous_ptr = insert_ptr;
}

template <class Item>
void list_insert_before(dnode<Item> *&next_ptr, const Item &new_data) {
    assert(next_ptr != NULL); // Precondition
    dnode<Item> *insert_ptr =
        new dnode<Item>(new_data, next_ptr, next_ptr->get_link_back());
    next_ptr->set_link_back(insert_ptr);

    // If the next_ptr is head_ptr, next_ptr is updated with insert_ptr.
    if (insert_ptr->get_link_back() == NULL)
        next_ptr = insert_ptr;
}

template <class Item> void list_remove(dnode<Item> *&target_ptr) {
    assert(target_ptr != NULL); // Precondition
    dnode<Item> *previous_ptr = target_ptr->get_link_back();
    dnode<Item> *next_ptr = target_ptr->get_link_fore();
    dnode<Item> *remove_ptr = target_ptr;

    if (previous_ptr == NULL && next_ptr == NULL) {
        // This list has only one node.
        target_ptr = NULL;
    } else if ((previous_ptr == NULL)) {
        // The target_ptr is head_ptr.
        target_ptr = target_ptr->get_link_fore();
        target_ptr->set_link_back(NULL);
    } else if (next_ptr == NULL) {
        // The target_ptr is tail_ptr.
        target_ptr = target_ptr->get_link_back();
        target_ptr->set_link_fore(NULL);
    } else {
        // The target_ptr is normal node.
        previous_ptr->set_link_fore(target_ptr->get_link_fore());
        next_ptr->set_link_back(target_ptr->get_link_back());
    }

    delete remove_ptr; // Free the memory that remove_ptr points to.
}

template <class Item>
void list_clear(dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr) {
    while (head_ptr != NULL)
        list_remove(head_ptr);
    tail_ptr = NULL;
}

template <class Item>
void list_copy(const dnode<Item> *source_ptr, dnode<Item> *&head_ptr,
               dnode<Item> *&tail_ptr) {
    head_ptr = NULL;
    tail_ptr = NULL;
    if (source_ptr == NULL) // Source list is empty.
        return;

    // Insert the head node at empty list.
    list_insert_empty(head_ptr, tail_ptr, source_ptr->get_data());
    source_ptr = source_ptr->get_link_fore();
    while (source_ptr != NULL) { // deep copy all nodes behind head node.
        // The tail_ptr is updated in list_insert_after() function.
        list_insert_after(tail_ptr, source_ptr->get_data());
        source_ptr = source_ptr->get_link_fore();
    }
}
