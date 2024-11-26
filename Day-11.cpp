// i. Merge k Sorted Lists:  

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // This function merges two sorted lists into one sorted list
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        // If the first list is empty, just return the second list
        if(!l1)
            return l2;
        // If the second list is empty, just return the first list
        if(!l2)
            return l1;

        // Compare the first values in each list
        if(l1->val <= l2->val) {
            // If l1's value is smaller, connect it to the result of merging the rest of l1 with l2
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1; // Return the current node from l1
        } else {
            // If l2's value is smaller, connect it to the result of merging l1 with the rest of l2
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2; // Return the current node from l2
        }
        
        // This line won't be reached, but we put it here to avoid compiler warnings
        return NULL;
    }
    
    // This function divides the list of lists into two halves and merges them
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        // If there's only one list in this range, return it
        if(start == end)
            return lists[start];
        
        // If the range is invalid (start is greater than end), return nothing
        if(start > end)
            return NULL;
        
        // Find the middle point of the range
        int mid = start + (end - start) / 2;
        
        // Recursively divide and merge the left half of the range
        ListNode* l1 = partitionAndMerge(start, mid, lists);
        // Recursively divide and merge the right half of the range
        ListNode* l2 = partitionAndMerge(mid + 1, end, lists);
        
        // Merge the two halves together and return the result
        return mergeTwoSortedLists(l1, l2);
    }
    
    // This is the main function that merges all the k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Find out how many lists we have
        int n = lists.size();
        
        // If there are no lists, return nothing
        if(n == 0)
            return NULL;
        
        // Start the partitioning and merging process from the first to the last list
        return partitionAndMerge(0, n - 1, lists);
    }
};

// ***************************************************************************


// ii. LRU Cache:

// This is a class that helps us build an LRU Cache (Least Recently Used Cache)
class LRUCache {
public:
    // This is a doubly linked list (dll) that stores the keys in the order of usage.
    list<int> dll; // Think of it like a line of people where the front is the most recently used.

    // This is a map (like a dictionary) that connects a key to its position in the list and its value.
    map<int, pair<list<int>::iterator, int>> cache; // Key -> (position in the list, value)

    // This tells us how many items we can store in the cache.
    int capacity;
    
    // Constructor: This is called when we first create an LRUCache and sets its size.
    LRUCache(int capacity) {
        this->capacity = capacity; // Set the maximum size of the cache.
    }
    
    // This function updates the key to make it the most recently used one.
    void makeMostRecentlyUsed(int key) {
        // Remove the key from its current position in the list.
        dll.erase(cache[key].first);
        // Add the key to the front of the list because it's now the most recently used.
        dll.push_front(key);
        // Update the map so it knows where the key is in the list.
        cache[key].first = dll.begin();
    }
    
    // This function gets the value for a key if it exists in the cache.
    int get(int key) {
        // If the key isn't in the cache, return -1 (it means "not found").
        if (!cache.count(key))
            return -1;

        // If the key is found, make it the most recently used.
        makeMostRecentlyUsed(key);
        // Return the value associated with the key.
        return cache[key].second;
    }
    
    // This function adds a new key-value pair to the cache.
    void put(int key, int value) {
        // If the key is already in the cache:
        if (cache.count(key)) {
            // Update the value for the key.
            cache[key].second = value;
            // Make it the most recently used.
            makeMostRecentlyUsed(key);
        } else {
            // If it's a new key, add it to the front of the list.
            dll.push_front(key);
            // Add the key and its value to the map.
            cache[key] = {dll.begin(), value};
            // Decrease the capacity since we've added an item.
            capacity--;
        }
        
        // If we've gone over the maximum capacity:
        if (capacity < 0) {
            // Remove the least recently used key (the one at the back of the list).
            cache.erase(dll.back());
            // Remove it from the list too.
            dll.pop_back();
            // Increase the capacity back to reflect the removal.
            capacity++;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ***************************************************************************

// iii. LFU Cache:  

class LFUCache {
private:
    int cap; // This is the maximum number of items the cache can hold.
    int size; // This is how many items are currently in the cache.
    unordered_map<int, list<vector<int>>::iterator> mp; 
    // This keeps track of where each key is in the frequency lists.
    // It’s like a map that says: for this key, go to this location in the list.
    
    map<int, list<vector<int>>> freq; 
    // This organizes items by how often they are used (their frequency).
    // Each frequency has a list of items with that usage count.

public:
    // Constructor to set up the cache with a specific capacity.
    LFUCache(int capacity) {
        cap = capacity; // Store the maximum capacity.
        size = 0;       // Start with an empty cache.
    }
    
    // This function moves an item to a higher frequency group.
    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]); 
        // Find the current {key, value, frequency} for the given key.

        int value = vec[1]; // Get the value of the item.
        int f     = vec[2]; // Get the current frequency of the item.

        freq[f].erase(mp[key]); 
        // Remove the item from its current frequency list.

        if (freq[f].empty())
            freq.erase(f); 
        // If there are no more items at this frequency, remove the frequency.

        f++; // Increase the frequency by 1.

        freq[f].push_front(vector<int>({key, value, f})); 
        // Add the item to the new, higher frequency list.

        mp[key] = freq[f].begin(); 
        // Update the map to point to the new location of the item.
    }
    
    // This function retrieves the value for a given key.
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1; // If the key isn’t in the cache, return -1.

        auto &vec = (*(mp[key])); 
        // Get the current {key, value, frequency} for the key.

        int value = vec[1]; // Extract the value.

        makeMostFrequentlyUsed(key); 
        // Update the item's frequency since it was just used.

        return value; // Return the value to the user.
    }
    
    // This function adds or updates an item in the cache.
    void put(int key, int value) {
        if (cap == 0)
            return; // If the cache can’t hold anything, just return.

        if (mp.find(key) != mp.end()) {
            // If the key is already in the cache:
            auto &vec = (*(mp[key])); 
            vec[1] = value; // Update the value.
            makeMostFrequentlyUsed(key); 
            // Increase the frequency since it was just used.
        } else if (size < cap) {
            // If there’s room in the cache for a new item:
            size++; 
            // Increase the count of items in the cache.

            freq[1].push_front(vector<int>({key, value, 1})); 
            // Add the new item to the frequency list for frequency 1.

            mp[key] = freq[1].begin(); 
            // Update the map to point to this new item.
        } else {
            // If the cache is full, we need to remove the least frequently used item.
            auto &kaun_sa_list = freq.begin()->second; 
            // Get the list of items with the lowest frequency.

            int key_delete = (kaun_sa_list.back())[0]; 
            // Find the key of the item we’ll remove (the least recently used one in this frequency).

            kaun_sa_list.pop_back(); 
            // Remove the item from the list.

            if (kaun_sa_list.empty())
                freq.erase(freq.begin()->first); 
            // If the list is now empty, remove the frequency group.

            freq[1].push_front(vector<int>({key, value, 1})); 
            // Add the new item to the frequency list for frequency 1.

            mp.erase(key_delete); 
            // Remove the old key from the map.

            mp[key] = freq[1].begin(); 
            // Add the new key to the map.
        }
    }
};