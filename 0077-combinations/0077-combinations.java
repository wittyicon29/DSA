class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> subset = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        //Step1
		helper(1,n,ans,subset);
        
		//step2
        List<List<Integer>> finalAns = new ArrayList<>();
        for(List<Integer> list : ans){
            if(list.size()==k)
                finalAns.add(list);
        }
        return finalAns;
    }
     public void helper(int start, int n, List<List<Integer>> ans, List<Integer> subset)
    {
	//BASE CASE
        if(start>=n+1){
            ans.add(new ArrayList<>(subset));
            return;
        }
        
        //include
        subset.add(start);
        helper(start+1 ,n,ans,subset);
        
        //exclude
        subset.remove(subset.size()-1);
        helper(start+1,n,ans,subset);
    }
}