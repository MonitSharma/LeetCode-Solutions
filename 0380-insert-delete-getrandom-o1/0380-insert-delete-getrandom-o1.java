class RandomizedSet {
 public:
  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (valToIndex.count(val))
      return false;

    valToIndex[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!valToIndex.count(val))
      return false;

    const int index = valToIndex[val];
    // Following two lines order are important when vals.size() == 1
    valToIndex[vals.back()] = index;
    valToIndex.erase(val);
    vals[index] = vals.back();
    vals.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    const int index = rand() % vals.size();
    return vals[index];
  }

 private:
  unordered_map<int, int> valToIndex;  // {val: index in vals}
  vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */