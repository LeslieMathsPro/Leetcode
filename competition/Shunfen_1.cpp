class Solution {
public:
    bool hasCycle(string graph) {
        hash_map<char, char> pairs;
        for (int i = 0; i < graph.size(); ++i) {
            if (i%5 == 0) {
                char l = graph[i];
                i += 2;
                char r = graph[i];
                pairs.insert(l, r); //(1,2) 
            }
        }
        // {(1,2), (2,3), (3,1)}
        hash_set<char> set;
        
    }
};