#pragma once
#include <memory>

template <typename T>
class BinarySearchTree {
    struct Node { T key; std::unique_ptr<Node> l,r; Node(T k):key(k){} };
    std::unique_ptr<Node> root;
public:
    void push(const T& k){ root = ins(std::move(root),k);}    
    bool search(const T& k) const { return find(root.get(),k);}    
    void pop(const T& k){ root = del(std::move(root),k);}    
private:
    static std::unique_ptr<Node> ins(std::unique_ptr<Node> n,const T& k){ if(!n) return std::make_unique<Node>(k); if(k<n->key) n->l=ins(std::move(n->l),k); else if(k>n->key) n->r=ins(std::move(n->r),k); return n;}    
    static bool find(const Node* n,const T& k){ if(!n) return false; if(k==n->key) return true; return k<n->key?find(n->l.get(),k):find(n->r.get(),k);}    
    static Node* min(Node* n){ while(n&&n->l) n=n->l.get(); return n;}    
    static std::unique_ptr<Node> del(std::unique_ptr<Node> n,const T& k){ if(!n) return nullptr; if(k<n->key){ n->l=del(std::move(n->l),k); return n;} if(k>n->key){ n->r=del(std::move(n->r),k); return n;} if(!n->l) return std::move(n->r); if(!n->r) return std::move(n->l); Node* m=min(n->r.get()); n->key=m->key; n->r=del(std::move(n->r),m->key); return n;}    
};
