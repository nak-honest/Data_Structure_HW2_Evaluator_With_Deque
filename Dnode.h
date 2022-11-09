#include <cstdlib>

/* This is the template class dnode. The dnode can store data whose type is
   Item. This node has two pointer that one points to next node and other points
   to previous node. */

template <class Item> class dnode {
  public:
    // Constructor
    dnode(const Item &init_data = Item(), dnode<Item> *init_link_fore = NULL,
          dnode<Item> *init_link_back = NULL);

    /* member functions */

    // The set_data() function sets data_filed value.
    // Pre : None.
    // Post : The data_filed is assigned with new_data.
    void set_data(const Item &new_data) { data_filed = new_data; }

    // The set_link_fore() function sets link_fore value. Then this node points
    // to in forward the node that is pointed by new_link_fore.
    // Pre : None.
    // Post : The link_fore is assigned with new_link_fore.
    void set_link_fore(dnode<Item> *new_link_fore) {
        link_fore = new_link_fore;
    }

    // The set_link_back() function sets link_back value. Then this node points
    // to in backward the node that is pointed by new_link_back.
    // Pre : None.
    // Post : The link_back is assigned with new_link_back.
    void set_link_back(dnode<Item> *new_link_back) {
        link_back = new_link_back;
    }

    // The get_data() function gets data_filed value.
    // Pre : None.
    // Post : The data_filed is returned.
    Item get_data() const { return data_filed; }

    // The get_link_fore() function gets link_fore value. There are two
    // get_link_fore() functions, first can change returned node's member
    // variables and second can't change.
    // Pre : None.
    // Post : The link_fore is returned.
    dnode<Item> *get_link_fore() { return link_fore; }
    const dnode<Item> *get_link_fore() const { return link_fore; }

    // The get_link_back() function gets link_back value. There are two
    // get_link_back() functions, first can change returned node's member
    // variables and second can't change.
    // Pre : None.
    // Post : The link_back is returned.
    dnode<Item> *get_link_back() { return link_back; }
    const dnode<Item> *get_link_back() const { return link_back; }

  private:
    /* member variables */
    Item data_filed;
    dnode<Item> *link_fore; // point to next node
    dnode<Item> *link_back; // point to previous node
};

template <class Item>
dnode<Item>::dnode(const Item &init_data, dnode<Item> *init_link_fore,
                   dnode<Item> *init_link_back) {
    data_filed = init_data;
    link_fore = init_link_fore;
    link_back = init_link_back;
}
