class Node{
    public:
    Node* links[26];
    int ew;
    int cp;
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
        ew=0;
        cp=1;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(!node->links[idx]){
                node->links[idx]=new Node();
            }
            node = node->links[idx];
            node->cp++;
        }
        node->ew++;
    }
    int countWordsEqualTo(string &word){
        Node* node = root;
         for(int i=0;i<word.size();i++){
             if(!node->links[word[i]-'a'])
                 return 0;
             node = node->links[word[i]-'a'];
         }
         return node->ew;
     }
};
 
class Solution {
    
public:
    static bool comp(pair<int,string> a, pair<int,string> b)
	{
		if(a.first == b.first)
			return a.second <b.second;
		return a.first > b.first;
	}
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie* trie = new Trie();
        for(int i=0;i<words.size();i++){
            trie->insert(words[i]);
        }
        map<string,int>mp;
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            mp.insert({words[i],trie->countWordsEqualTo(words[i])});
        }
        vector<pair<int,string>> str;
            for(auto j:mp){
                str.push_back({j.second,j.first});
            }
        sort(str.begin(),str.end(),comp);
        for(int i=0;i<str.size();i++){
            if(!k--)return ans;
                ans.push_back(str[i].second);
            
        }
        return ans;
    }
};