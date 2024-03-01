#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }

    return ans;
}

vector<int> iterativePreorder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
    }
    return ans;
}

vector<int> iterativeInorder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    Node *temp = root;
    stack<Node *> st;

    while (true)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.size() == 0)
                break;
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

vector<int> iterativePostorder1(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

vector<int> iterativePostorder2(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    stack<Node *> st;
    Node *curr = root;
    Node *temp;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;

            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }
    return ans;
}

vector<int> singleTraversal(Node *root)
{
    vector<int> pre, in, post;
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    return pre;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->right->right = new Node(50);

    cout << "\nRecursive Preorder: ";
    preOrder(root);

    cout << "\nRecursive Inorder: ";
    inOrder(root);

    cout << "\nRecursive Postorder: ";
    postOrder(root);

    cout << "\nLevel Order: ";
    vector<vector<int>> ans1 = levelOrder(root);
    for (int i = 0; i < ans1.size(); i++)
    {
        for (int j = 0; j < ans1[i].size(); j++)
        {
            cout << ans1[i][j] << " ";
        }
    }

    cout << "\nIterative Preorder: ";
    vector<int> ans2 = iterativePreorder(root);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    cout << "\nIterative Inorder: ";
    ans2 = iterativeInorder(root);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    cout << "\nIterative Postorder 1 : ";
    ans2 = iterativePostorder1(root);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    cout << "\nIterative Postorder 2 : ";
    ans2 = iterativePostorder2(root);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    cout << "\nPreorder traversal from single traversal: ";
    ans2 = singleTraversal(root);                       
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    return 0;
}