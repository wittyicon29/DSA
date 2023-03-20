class WordDictionary{
    private List<String> res;
    public WordDictionary() {
        this.res = new ArrayList<>();
    }
    public void addword(String word) {
        this.res.add(word);
    }
    public boolean search(String word) {
        for(String w : this.res){
            if(match(w,word)){
                return true;
            }
        }
        return false;
    }
    public boolean match(String word, String word2) {
        if(word.length() != word2.length()){
            return false;
        }
        for(int i = 0; i < word.length(); i++){
            if(word.charAt(i) != '.' && word.charAt(i) != word2.charAt(i)){
                return false;
            }
        }
        return true;
    }
}

/*Using Hashset */
class WordDictionary {
    private Set<String> memory;

    public WordDictionary() {
        memory = new HashSet<>();
    }
    
    public void addWord(String word) {
        memory.add(word);
    }
    
    public boolean search(String word) {
        if(memory.contains(word))
            return true;
        if(word.contains("."))  {
            for(String storedWord : memory){
                if(storedWord.length() != word.length())
                    continue;   
                for(int i = 0; i < storedWord.length(); i++){
                    char c1 = storedWord.charAt(i);
                    char c2 = word.charAt(i);
                    if(c2 != '.' && c1 != c2){
                        break;
                    }
                    if(i == storedWord.length() - 1){
                        return true;
                    }
                }
            } 
        }  
        return false;   
    }
}

/*Using Tree DFS */
class TrieNode {
    Map<Character, TrieNode> children;
    boolean isWord;
    
    public TrieNode() {
        children = new HashMap<>();
        isWord = false;
    }
}

class WordDictionary {
    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }

    public void addWord(String word) {
        TrieNode node = root;
        // Traverse the trie for each character in the word
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            // If the current node does not have a child with character c,
            // create a new node and add it as a child of the current node
            if (!node.children.containsKey(c)) {
                node.children.put(c, new TrieNode());
            }
            // Move to the child node corresponding to character c
            node = node.children.get(c);
        }
        // Mark the last node as a word node
        node.isWord = true;
    }

    public boolean search(String word) {
        return searchHelper(root, word, 0);
    }

    private boolean searchHelper(TrieNode node, String word, int index) {
        // If we have reached the end of the word,
        // check if the current node is a word node
        if (index == word.length()) {
            return node.isWord;
        }
        char c = word.charAt(index);
        if (c == '.') {
            // If the current character is a dot, we need to check all children of the current node
            // recursively by skipping over the dot character and moving to the next character of the word
            for (TrieNode child : node.children.values()) {
                if (searchHelper(child, word, index + 1)) {
                    return true;
                }
            }
            // If no child node matches the remaining characters of the word,
            // return false
            return false;
        } else {
            // If the current character is not a dot, move to the child node
            // corresponding to that character and continue recursively
            TrieNode child = node.children.get(c);
            if (child == null) {
                // If there is no child node corresponding to the current character,
                // return false
                return false;
            }
            return searchHelper(child, word, index + 1);
        }
    }
}