class Solution {
public:
    void calc_lps(vector<int>&lps,string s){
        int i=1;
        int n = lps.size();
        int len=0;
        while(i<n){
            if(s[len]==s[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else {
                if(len==0){
                 lps[i] =0;
                 i++;
                }
                else{
                    len = lps[len-1];
                }
            }

        }
    }
    int strStr(string haystack, string needle) {
      vector<int>lps(needle.size(),0);
      calc_lps(lps,needle);
      int m = needle.size();
      int n = haystack.size();
      int j=0,i=0;
      while(i<n){
        if(haystack[i]==needle[j]){
            i++;
            j++;
            if(j==m){
                return i-j;
            }
        }
        else if(i < n && haystack[i]!=needle[j]){
             if(j==0){
                i++;
             }
             else{
                j=lps[j-1];
             }
        }
      }
      return -1;
       
    }
};