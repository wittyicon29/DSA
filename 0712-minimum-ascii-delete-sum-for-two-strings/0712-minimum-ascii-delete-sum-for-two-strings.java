class Solution {
    public int lcs(String s1, String s2, int i, int j,int [][] memo)
    {
        if(i>=s1.length())
        {
            int del=0;
            while(j<s2.length())
                del+=s2.charAt(j++);

            return del;
        }

        if(j>=s2.length())
        {
            int del=0;
            while(i<s1.length())
                del+=s1.charAt(i++);

            return del;
        }

        if(memo[i][j]!=-1)
            return memo[i][j];

        int ans=0;
        
        if(s1.charAt(i)==s2.charAt(j))
        {
            ans= lcs(s1,s2,i+1,j+1,memo);
        }
        else
        {
            ans= s1.charAt(i)+lcs(s1,s2,i+1,j,memo);

            ans=Math.min(ans,s2.charAt(j)+lcs(s1,s2,i,j+1,memo));
            ans= Math.min(ans,s1.charAt(i)+s2.charAt(j)+lcs(s1,s2,i+1,j+1,memo));
        }

        memo[i][j]=ans;
        return ans;

    }
    
    public int minimumDeleteSum(String s1, String s2) {
        
        int [][] memo= new int[s1.length()+1][s2.length()+1];

        for(int i=0;i<=s1.length();i++)
        {
            for(int j=0;j<=s2.length();j++)
            {
                memo[i][j]=-1;
            }
        }

        return lcs(s1,s2,0,0,memo);

    }
}