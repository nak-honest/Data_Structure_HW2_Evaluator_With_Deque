#include <cstdlib>

template <class Item> class dnode {
  public:
    // Constructor
    dnode(const Item &init_data = Item(), dnode<Item> *init_link_fore = NULL,
          dnode<Item> *init_link_back = NULL);

    // member function
    void set_data(const Item &new_data) { data_filed = new_data; }
    void set_link_fore(dnode<Item> *new_link_fore) {
        link_fore = new_link_fore;
    }
    void set_link_back(dnode<Item> *new_link_back) {
        link_back = new_link_back;
    }
    Item get_data() const { return data_filed; }
    dnode<Item> *get_link_fore() { return link_fore; }
    const dnode<Item> *get_link_fore() const { return link_fore; }
    dnode<Item> *get_link_back() { return link_back; }
    const dnode<Item> *get_link_back() const { return link_back; }

  private:
    Item data_filed;
    dnode<Item> *link_fore;
    dnode<Item> *link_back;
};

template <class Item>
dnode<Item>::dnode(const Item &init_data, dnode<Item> *init_link_fore,
                   dnode<Item> *init_link_back) {
    data_filed = init_data;
    link_fore = init_link_fore;
    link_back = init_link_back;
}
