//
// Created by Amos on 2020/04/24.
//
#include <iostream>
#include <map>
#include <deque>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }

        for (auto it = reference.begin(); it != reference.end(); ++it) {
            if (*it == key) {
                reference.erase(it);
                break;
            }
        }

        reference.push_back(key);
        return m[key];
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m.erase(key);

            for (auto it = reference.begin(); it != reference.end(); ++it) {
                if (*it == key) {
                    reference.erase(it);
                    break;
                }
            }
        }

        if (m.size() >= capacity) {
            int evict_target = reference.front();
            reference.pop_front();
            m.erase(evict_target);
        }

        m[key] = value;
        reference.push_back(key);
    }

private:
    // key (value, access count)
    map<int, int> m;
    deque<int> reference;
    int capacity;
};

int main() {
    LRUCache *lruCache;

    /*
    lruCache = new LRUCache(2);
    lruCache->put(1, 1);
    lruCache->put(2, 2);
    cout << lruCache->get(1) << ' '; // 1
    lruCache->put(3, 3);
    cout << lruCache->get(2) << ' '; // -1
    lruCache->put(4, 4);
    cout << lruCache->get(1) << ' '; // -1
    cout << lruCache->get(3) << ' '; // 3
    cout << lruCache->get(4) << ' '; // 4
    cout << '\n';
    delete lruCache;

    lruCache = new LRUCache(2);
    lruCache->put(2, 1);
    lruCache->put(1, 1);
    cout << lruCache->get(2) << ' ';
    lruCache->put(4, 1);
    cout << lruCache->get(1) << ' ';
    cout << lruCache->get(2) << ' ';
    cout << '\n';
    delete lruCache;
    */

    lruCache = new LRUCache(2);
    lruCache->put(2, 1);
    lruCache->put(1, 1);
    lruCache->put(2, 3);
    lruCache->put(4, 1);
    cout << lruCache->get(1) << ' ';
    cout << lruCache->get(2) << ' ';
    cout << '\n';
    delete lruCache;

    return 0;
}
