class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        unordered_map<char,int>map;

        int l=0;
        int r=0;
        int n=s.length();
        int len=0;

        while(r<n){
            map[s[r]]++;

            if(map[s[r]]>2){
                while(l<r && map[s[r]]>2){
                    map[s[l]]--;
                    l++;
                }
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};