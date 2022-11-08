#include "Dnode.h"
#include <cassert>

/* In all functions that have parameter as head_ptr, head_ptr is pointer of
 * list's head dnode<Item>. If list is empty, head_ptr is NULL. */

// The list_length() function returns the length of list
// Pre : None.
// Post : Number of dnode<Item>s in list is returned.
template <class Item> size_t list_length(const dnode<Item> *head_ptr);

// The list_search() function returns the pointer of dnode<Item> that exponent
// is exponent_target. There are two list_search() functions, first can change
// returned dnode<Item>'s member variables and second can't change. Pre : None.
// Post : Pointer of dnode<Item> that exponent is exponent_target is returned.
//        If there is not exist that dnode<Item> or list is empty, NULL is
//        returned.
template <class Item>
dnode<Item> *list_search(dnode<Item> *head_ptr, const Item &target);
template <class Item>
const dnode<Item> *list_search(const dnode<Item> *head_ptr, const Item &target);

// The list_locate() function returns the pointer of dnode<Item> that order is
// position in list. There are two list_locate() functions, first can change
// returned dnode<Item>'s member variables and second can't change. Pre :
// position > 0. Post : Pointer of dnode<Item> that order is position is
// returned.
//        If there is not exist that dnode<Item> or list is empty, NULL is
//        returned.
template <class Item>
dnode<Item> *list_locate(dnode<Item> *head_ptr, size_t position);
template <class Item>
const dnode<Item> *list_locate(const dnode<Item> *head_ptr, size_t position);

template <class Item>
dnode<Item> *list_locate_reverse(dnode<Item> *tail_ptr,
                                 size_t reverse_position);
template <class Item>
const dnode<Item> *list_locate_reverse(const dnode<Item> *tail_ptr,
                                       size_t reverse_position);

// The list_insert() function inserts the dnode<Item> behind the dnode<Item>
// that previous_ptr point to. That dnode<Item>'s coefficient is new_coefficient
// and exponent is new_exponent. If you want to insert the dnode<Item> front the
// head dnode<Item>, use list_head_insert() function. Pre : previous_ptr is not
// NULL. Post : The dnode<Item> is inserted behind the dnode<Item> that
// previous_ptr point to.
template <class Item>
void list_insert_after(dnode<Item> *&previous_ptr, const Item &new_data);

template <class Item>
void list_insert_before(dnode<Item> *&next_ptr, const Item &new_data);

template <class Item>
void list_insert_empty(dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr,
                       const Item &new_data);

// The list_head_insert() function inserts the dnode<Item> front the head
// dnode<Item>. That dnode<Item>'s coefficient is new_coefficient and exponent
// is new_exponent. Pre : None. Post : The dnode<Item> is inserted front the
// head dnode<Item>
//        and head_ptr point to this dnode<Item>.

// The list_remove() function removes the dnode<Item> behind the dnode<Item>
// that previous_ptr point to.
// Pre : previous_ptr is not NULL.
// Post : The dnode<Item> is removed behind the dnode<Item> that previous_ptr
// point to.
template <class Item> void list_remove(dnode<Item> *&target_ptr);

// The list_clear() function removes all dnode<Item>s in list.
// Pre : None.
// Post : List is empty. head_ptr is NULL.
template <class Item> void list_clear(dnode<Item> *&head_ptr);

// The list_copy() function copys(deep copy) the list.
// Pre : None.
// Post : head_ptr point to the head dnode<Item>
//        in the list that is copied from source_ptr.
//        If source_ptr is NONE, then head_ptr is NONE.
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
void list_insert_after(dnode<Item> *&previous_ptr, const Item &new_data) {
    assert(previous_ptr != NULL); // Precondition
    dnode<Item> *insert_ptr =
        new dnode<Item>(new_data, previous_ptr->get_link_fore(), previous_ptr);
    previous_ptr->set_link_fore(insert_ptr);

    if (insert_ptr->get_link_fore() == NULL)
        previous_ptr = insert_ptr;
}

template <class Item>
void list_insert_before(dnode<Item> *&next_ptr, const Item &new_data) {
    assert(next_ptr != NULL); // Precondition
    dnode<Item> *insert_ptr =
        new dnode<Item>(new_data, next_ptr, next_ptr->get_link_back());
    next_ptr->set_link_back(insert_ptr);

    if (insert_ptr->get_link_back() == NULL)
        next_ptr = insert_ptr;
}

template <class Item>
void list_insert_empty(dnode<Item> *&head_ptr, dnode<Item> *&tail_ptr,
                       const Item &new_data) {
    assert(head_ptr == NULL && tail_ptr == NULL);
    head_ptr = new dnode<Item>(new_data, NULL, NULL);
    tail_ptr = head_ptr;
}

template <class Item> void list_remove(dnode<Item> *&target_ptr) {
    assert(target_ptr != NULL); // Precondition
    dnode<Item> *previous_ptr = target_ptr->get_link_back();
    dnode<Item> *next_ptr = target_ptr->get_link_fore();
    dnode<Item> *remove_ptr = target_ptr;

    if (previous_ptr == NULL && next_ptr == NULL) {
        target_ptr = NULL;
    } else if ((previous_ptr == NULL)) {
        target_ptr = target_ptr->get_link_fore();
        target_ptr->set_link_back(NULL);
    } else if (next_ptr == NULL) {
        target_ptr = target_ptr->get_link_back();
        target_ptr->set_link_fore(NULL);
    } else {
        previous_ptr->set_link_fore(target_ptr->get_link_fore());
        next_ptr->set_link_back(target_ptr->get_link_back());
    }
    delete remove_ptr;
}

template <class Item> void list_clear(dnode<Item> *&head_ptr) {
    while (head_ptr != NULL)
        list_remove(head_ptr);
}

template <class Item>
void list_copy(const dnode<Item> *source_ptr, dnode<Item> *&head_ptr,
               dnode<Item> *&tail_ptr) {
    head_ptr = NULL;
    tail_ptr = NULL;
    if (source_ptr == NULL) // Source list is empty.
        return;
    list_insert_empty(head_ptr, tail_ptr, source_ptr->get_data());
    // deep copy the head node.
    source_ptr = source_ptr->get_link_fore();
    while (source_ptr != NULL) { // deep copy all nodes behind head node.
        list_insert_after(tail_ptr, source_ptr->get_data());
        source_ptr = source_ptr->get_link_fore();
    }
}
