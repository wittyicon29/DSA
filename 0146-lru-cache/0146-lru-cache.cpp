class LRUCache {
public:
    
    unordered_map<int, int> mp;
    int max1 =0;
    int count =0 ;
    unordered_map<int, int> mp2;
    queue<pair<int,int>> q;
    LRUCache(int capacity) {
        max1 = capacity;
    }
 
    
    int get(int key) {
        mp2[key] = count;
        q.push({key,count});
        count++;
        return mp.count(key) ? mp[key] : -1 ;
    }
    
    void put(int key, int value) {
        
        
        
        if(!mp.count(key) && mp.size() == max1){
            while(!mp.count(q.front().first) || mp2[q.front().first] != q.front().second){
                q.pop();
            }
            mp.erase(q.front().first);
            mp2.erase(q.front().first);
            q.pop();
        }
        mp[key] = value;
        q.push({key,count});
        mp2[key] = count;
        count++;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */