#include <bits/stdc++.h>
#include <vector>
using namespace std;

class HashMap {
private:
  static const int hashGroups = 10;
  vector<list<pair<int, string>>> Map;

public:
  HashMap() { 
    Map.resize(hashGroups);
  }

  bool isEmpty();
  void insertInMap(int key, string value);
  void deleteFromMap(int key);
  bool searchMap(int key);
  int hashFunction(int key);
  void printMap();
};

bool HashMap::isEmpty() {
  for (auto &l : Map) {
    if (l.size())
      cout << "[INFO] Key not found" << endl;
      return false;
  }
      cout << "[INFO] Key found" << endl;
  return true;
}

int HashMap::hashFunction(int key) { return key % hashGroups; }

void HashMap::insertInMap(int key, string value) {
  int idx = hashFunction(key);
  auto &l = Map[idx];
  for(auto itr = l.begin() ; itr != l.end() ; itr++) {
    if(itr->first == key) {
      itr->second = value;
      cout << "[WARNING] YOU HAVE JUST REPLACED AN EXISITING KEY WITH A NEW VALUE" << endl;
      return;
    }
  }
  Map[idx].push_front({key, value});
}

void HashMap::deleteFromMap(int key) {
  int idx = hashFunction(key);
  auto &l = Map[idx];
  for(auto itr = l.begin() ; itr != l.end() ; itr++) {
    if(itr->first == key) {
      l.erase(itr);
      cout << "Successfully deleted the key " << key << endl;
      return;
    }
  }
}

bool HashMap::searchMap(int key) {
  int idx = hashFunction(key);
  for (auto &x : Map[idx]) {
    if (x.first == key)
      return true;
  }
  return false;
}

void HashMap::printMap() {
  for (auto &l : Map) {
    for (auto &x : l) {
      cout << x.first << ", " << x.second << endl;
    }
  }
}

int main() {
  HashMap hashmap;
  hashmap.insertInMap(1, "ankit");
  hashmap.insertInMap(2, "pnkit");
  hashmap.insertInMap(30, "meow");
  hashmap.insertInMap(11, "ankit");
  hashmap.insertInMap(223, "ranki");
  hashmap.insertInMap(3023, "meowpeop");
  hashmap.printMap();

  if (hashmap.searchMap(30))
    cout << "true found 30" << endl;
  else
    cout << "didn't find 30" << endl;

  hashmap.insertInMap(30, "peow");

  hashmap.deleteFromMap(30);
  hashmap.printMap();
  return 0;
}
