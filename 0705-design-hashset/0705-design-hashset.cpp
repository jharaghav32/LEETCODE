class MyHashSet {
public:
    vector<int>v;
    int n ;
    MyHashSet() {
        n = 1e6+1;
        v.resize(n);
    }
    
    void add(int key) {
        if(v[key]==0){
            v[key]=1;
        }
    }
    
    void remove(int key) {
        v[key]=0;
    }
    
    bool contains(int key) {
        if(v[key]==0)return false;
        return true;
    }
};
