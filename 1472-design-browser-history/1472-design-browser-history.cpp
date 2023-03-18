class Node{
    public:
    string val;
    Node* front;
    Node* back;
    Node(string url){
        val = url;
        front=NULL;
        back = NULL;
    }
};
class BrowserHistory {
public:
    Node* currptr;
    BrowserHistory(string homepage) {
       Node* ptr = new Node(homepage);
       currptr=ptr; 
    }
    
    void visit(string url) {
        Node* ptr = new Node(url);
        currptr->front=ptr;
        ptr->back=currptr;
        currptr=ptr;
    }
    
    string back(int steps) {
        while(steps--){
            if(currptr->back==NULL)return currptr->val;
            currptr=currptr->back;
        }
        return currptr->val;
    }
    
    string forward(int steps) {
        while(steps--){
            if(currptr->front==NULL)return currptr->val;
            currptr=currptr->front;
        }
        return currptr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */