class SmallestInfiniteSet {
public:
    set<int>st;
    int curr;
    SmallestInfiniteSet() {
     curr=1;
    }
    
    int popSmallest() {
       if(st.size()){
           int firselem = *st.begin();
               st.erase(st.begin());
               return firselem;
       }
        curr = curr+1;
        return curr-1;
    }
    
    void addBack(int num) {
        if(curr>num){
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */