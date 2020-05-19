##sliding window approach 

Time Complexity : O(26*len(s)) 

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>ans;
        vector<int>p_hash(26,0);
        vector<int>s_hash(26,0);
        
        int window = p.size();
        int len = s.size();

        if(len<window) return ans;
        
        int left = 0, right = 0 ;
        while(right<window){
            p_hash[p[right]-'a'] +=1 ;
            s_hash[s[right++]-'a'] +=1;
        }
        
        right = right -1;
        
        while(right<len){
            if(p_hash == s_hash){
                ans.push_back(left);
            }
            right+=1;
            if(right!=len){
                s_hash[s[right]-'a'] +=1;
            }
            s_hash[s[left]-'a'] -=1;
            left +=1;
        }
        return ans;
        
    }
};
