static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        if(h.size()==1) return h[0];
        vector<int> prevSmall;
        vector<int> nextSmall;
        stack<int> st1,st2;
\
        for(int i=0;i<h.size();i++)
        {
            while(!st1.empty() and h[st1.top()]>=h[i]) st1.pop();
            prevSmall.push_back(st1.empty()?-1:st1.top());
            st1.push(i);
        }

        for(int i=h.size()-1;i>=0;i--)
        {
            while(!st2.empty() and h[st2.top()]>=h[i]) st2.pop();
            nextSmall.push_back(st2.empty()?h.size():st2.top());
            st2.push(i);
        }

        reverse(nextSmall.begin(),nextSmall.end());
        int maxArea=0;

        for(int i=0;i<h.size();i++)
            maxArea=max(maxArea,(nextSmall[i]-prevSmall[i]-1)*h[i]);
        return maxArea;
    }
};