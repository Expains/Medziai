#include <iostream>

using namespace std;
struct TreeNode{
    int data;        //Virsunes data
    TreeNode *left;  //Pointeris i kaire
    TreeNode *right; //Pointeris i desine
};
TreeNode* NewLeaf(int data){
    TreeNode* Leaf = new TreeNode();
    (*Leaf).data = data;
    Leaf ->left = Leaf->right = NULL;
    return Leaf;
}
TreeNode* Insert(TreeNode* root,int data){
    if(root == NULL){
        root = NewLeaf(data);
    }
    else if(data <= root -> data){
        root ->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
return root;
}
bool Search(TreeNode* root,int data){
    if(root == NULL) return false;
    else if(root ->data == data) return true;
    else if(data <= root -> data) return Search(root->left,data);
    else return Search(root->right,data);
}
void preorder(TreeNode* root){
    if (root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(TreeNode* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void inorder(TreeNode* root){
    if(root!=NULL){
        inorder(root -> left);
        cout<<root->data<<" ";
        inorder(root-> right);
    }
}
TreeNode* FindMin(TreeNode* root){
    if(root ->left != NULL)
        FindMin(root->left);
    return root;
}
TreeNode* DeleteLeaf(TreeNode* root,int data){
    if(root == NULL) cout<<"Elementas nerastas"<<endl;
    else if (data < root->data)
    root -> left = DeleteLeaf(root->left,data);
    else if(data > root->data)
    root -> right = DeleteLeaf(root->right,data);
    else
    {
        if(root->left == NULL && root ->right ==NULL){
            delete root;
            root = NULL;
        }
        else if (root -> left == NULL){
            TreeNode * temp = root;
            root = root -> right;
            delete temp;
        }
        else if (root -> right == NULL){
            TreeNode* temp = root;
            root = root-> left;
            delete temp;
        }
        else{
            TreeNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = DeleteLeaf(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    bool ciklas = true;
    int number,i,o,p,way;
    TreeNode* root;
    root = NULL;
    while(ciklas == true){
    cout<<"=========================================="<<endl;
    cout<<"                 Pasirinkimai             "<<endl;
    cout<<"=========================================="<<endl;
    cout<<"1. Sukurti medi/prideti elementu"<<endl;
    cout<<"2. Spausdinti medzio elementus preorder"<<endl;
    cout<<"3. Spausdinti medzio elementus postrder"<<endl;
    cout<<"4. Spausdinti medzio elementus inorder"<<endl;
    cout<<"5. Trinti medzio elementa"<<endl;
    cout<<"6. Ieskoti medyje norimo elemento"<<endl;
    cout<<"7. Isjungti programa"<<endl;
    cout<<"=========================================="<<endl;
    cin>>way;
    switch(way){
        case 1:
            cout<<"------------------------------------------"<<endl;
            cout<<"Ivesk is kiek elementu norite sukurti medi/kiek elementu prideti ";
            cin>>o;
            cout<<endl<<"------------------------------------------"<<endl;
            cout<<"Veskite elementu reiksmes"<<endl;
            cout<<"------------------------------------------"<<endl;
            for(i=0;i<o;i++){
            cin>>p;
            root = Insert(root,p);
            }
            break;
        case 2:
            cout<<"------------------------------------------"<<endl;
            preorder(root);
            cout<<endl<<"------------------------------------------"<<endl;
            break;
        case 3:
            cout<<"------------------------------------------"<<endl;
            postorder(root);
            cout<<endl<<"------------------------------------------"<<endl;
            break;
        case 4:
            cout<<"------------------------------------------"<<endl;
            inorder(root);
            cout<<endl<<"------------------------------------------"<<endl;
            break;
        case 5:
            cout<<"------------------------------------------"<<endl;
            cout<<"Veskite koki elementa norite istrinti ";
            inorder(root);
            cout<<endl<<"------------------------------------------"<<endl;
            cin>>number;
            DeleteLeaf(root,number);
            break;
        case 6:
            cout<<"------------------------------------------"<<endl;
            cout<<"Ivesk skaiciu kuri nori patikrinti ";
            cin>>number;
            cout<<"------------------------------------------"<<endl;
            if(Search(root,number)== true)
                cout<<"Elementas rastas"<<endl;
                else cout<<"Elemento nera medyje"<<endl;

            break;
        case 7:
            ciklas = false;
            break;
        default:
            cout<<"Nera tokio pasirinkimo"<<endl;
            break;
                }
    }
    return 0;
}
