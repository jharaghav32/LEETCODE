class Node{
    public:
    Node* links[26];
    bool flag;
    Node(){
        for(int i=0;i<26;i++)
            links[i]=NULL;
        flag  = false;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(!node->links[idx]){
                node->links[idx]=new Node();
            }
            node= node->links[idx];
        }
        node->flag=true;
    }
    bool helper(string &word,int i,Node* node){
        if(!node) // here we check that for a  particular character its reference node exist or not if not
            // we return false so that it then check for the next character
            return false;
        if(i == word.size()){
            return node->flag;
        }
        if(word[i] != '.'){
            return helper(word,i+1,node->links[word[i]-'a']);
        }
        else
        {
            bool val = false;
            for(int j = 0 ; j < 26  ; j++){
                if(helper(word,i+1,node->links[j]))
                {  val= true;
                 break;
                }
            }
            return val;
        }
    }
    bool search(string word) {
        Node* node = root;
        return helper(word,0,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */