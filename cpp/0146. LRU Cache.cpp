//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//Follow up:
//Could you do both operations in O(1) time complexity?
//
//Example:
//
//LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4
//


class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // 先查找哈希
        auto itr = m.find(key);
        if (itr == m.end())
            return -1;
        // 不论读写都需要将元素放到最前面
        l.splice(l.begin(), l, itr->second);
        m[key] = l.begin();
        
        return itr->second->second;
    }
    
    void put(int key, int value) {
        // 先查找哈希
        auto itr = m.find(key);
        if (itr != m.end())
            l.erase(itr->second); // 从链表中删除
        // 不论读写都需要将元素放到最前面
        l.push_front({key, value});
        m[key] = l.begin(); // hash要更新对应元素
        
        if (l.size() > cap) // 注意删除多余元素
        {
            m.erase(l.rbegin()->first);
            l.pop_back();
        }
    }
    
    int cap;
    list<pair<int, int>> l; // list方便将数字插入或移动到开始位置
    unordered_map<int, list<pair<int, int>>::iterator> m; // hash可以随机读写
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

