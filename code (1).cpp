#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node (int x){
        data=x;
        left=right=NULL;
    }
};
void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root){
    if (root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}
void levelorder(Node *root,vector<vector<int>>&v,int l){
    if(root==NULL)return;
    if(v.size()==l)v.push_back({root->data});
    else v[l].push_back(root->data);
    levelorder(root->left,v,l+1);
    levelorder(root->right,v,l+1);
}
void level(Node *root){
    queue<Node*>dq;
    dq.push(root);
    while(!dq.empty()){
        Node *temp=dq.front();
        dq.pop();
        cout<<temp->data<<" ";
        if (temp->left!=NULL)dq.push(temp->left);
        if(temp->right!=NULL)dq.push(temp->right);
    }
}
int main(){
    Node *root=new Node(10);
    Node *first=new Node(20);
    Node *second=new Node(30);
    Node *third=new Node(40);
    Node *four=new Node(50);
    root->left=first;
    root->right=second;
    first->left=third;
    first->right=four;
    Node *five=new Node(60);
    Node *six=new Node(70);
    second->left=five;
    second->right=six;
    //inorder(root);
    //cout<<"\n";
    // preorder(root);
    // cout<<"\n";
    // postorder(root);
    // vector<vector<int>>v;
    // levelorder(root,v,0);
    // for (int i=0;i<v.size();i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    // }
    level(root);
}