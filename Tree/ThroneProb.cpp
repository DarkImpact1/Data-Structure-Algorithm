// Leetcode throne problem 

class ThroneInheritance {
public:
    struct Node{
        string name;
        vector<Node*> children;
        Node(string s){
            name = s;
        }
    };

    Node* root = new Node("");
    map<string,Node*> mp;


    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        mp[kingName] = root; // keep track of king;
    }
    
    void birth(string parentName, string childName) {
        Node* par = mp[parentName]; // fetch the address of parent
        Node* newkid = new Node(childName); // create a node for child
        (par->children).push_back(newkid); // push the child in parent's child
        mp[childName] = newkid; // also keep track of new born child
    }
    
    void death(string name) {
        Node* nameAdd = mp[name];// fetch the address of name
        nameAdd->name = ""; // remove name 
        mp.erase(name); // since he is dead remove his name
    }

    void getOrder(vector<string>& ans, Node* root){
        if(root-> name != ""){
            ans.push_back(root->name);
        }
        vector<Node*> childrens = root->children;
        int numChild = childrens.size();
        for(int i=0; i<numChild; i++){
            getOrder(ans,childrens[i]);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        Node* current = root;
        getOrder(ans, root);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
