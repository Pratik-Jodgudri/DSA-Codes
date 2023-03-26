#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char letter;
    int freq;
    struct Node *left, *right;
    
    Node(char l, int f)
    {
        letter = l;
        freq = f;
        left = right = NULL;
    }
};

struct compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

void printcode(Node *root, string s);

void Huff(char a[], int f[], int n)
{
    priority_queue <Node *, vector<Node *>, compare> pq;
    for(int i = 0; i < n; i++)
        pq.push(new Node(a[i], f[i]));

    Node *lchild, *rchild;

    while(pq.size() != 1)
    {
        lchild = pq.top();
        pq.pop();
        rchild = pq.top();
        pq.pop();
        
        Node *temp = new Node('*', lchild->freq + rchild->freq);
        temp->left = lchild;
        temp->right = rchild;

        pq.push(temp);
    }

    printcode(pq.top(), " ");
}

void printcode(Node *root, string s)
{
    if(root->letter != '*')
        cout << root->letter << "->" << s << endl;
    else
    {
        printcode(root->left, s + "0");
        printcode(root->right, s + "1");
    }
}

int main()
{
    int n; // = 6
    cout << "Enter the no. of different characters: ";
    cin >> n;
    char a[n];  // = {'a', 'b', 'c', 'd', 'e', 'f'};
    int f[n]; // = {5, 9, 12, 13, 16, 45};
    
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the character " << i+1 << ": ";
        cin >> a[i];
        cout << "Enter frequency of character " << i+1 << ": ";
        cin >> f[i];
    }

    cout << "The Huffman codes are: " << endl;   
    Huff(a, f, n);

    return 0;
}