#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class RandomizedSet {
  public:
    // set<int> s;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        auto p = T.insert(val);
        return p.second;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        return T.erase(val);
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return *T.find_by_order(rand() % T.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */