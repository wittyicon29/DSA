class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<String>();
            if(digits == null || digits.length() == 0){
                return result;
            }
            String[] map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            result.add("");
            for(int i = 0; i < digits.length(); i++){
                int x = Character.getNumericValue(digits.charAt(i));
                while(result.get(0).length() == i){
                    String t = result.remove(0);
                    for(char s : map[x].toCharArray()){
                        result.add(t + s);
                    }
                }
            }
            return result;
    }
}