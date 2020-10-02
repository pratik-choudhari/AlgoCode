#include<iostream>
#include<cstring>
using namespace std;

#define MAX 26

struct Node
{
    struct Node *children[MAX];
    bool isEndOfWord;

    Node()
    {

	    isEndOfWord = false;

	    for (int i = 0; i < MAX; i++)
	        children[i] = NULL;
    }
};

class Trie
{
	Node * root;

public:
	Trie()
	{
		root = new Node;
	}

	Node * sendRoot()
	{
		return root;
	}

	void insert(string s)
	{
		Node *pCrawl = root;
	    for (int i = 0; i < s.length(); i++)
	    {
	        int index = s[i] - 'a';
	        if (!pCrawl->children[index])
	            pCrawl->children[index] = new Node;

	        pCrawl = pCrawl->children[index];
	    }
	    pCrawl->isEndOfWord = true;
	}

	bool search(string s)
	{
	    Node *pCrawl = root;

	    for (int i = 0; i < s.length(); i++)
	    {
	        int index = s[i] - 'a';
	        if (!pCrawl->children[index])
	            return false;

	        pCrawl = pCrawl->children[index];
	    }

	    return (pCrawl != NULL && pCrawl->isEndOfWord);
	}

	bool isEmpty(Node * root)
	{
	    for (int i = 0; i < MAX; i++)
	        if (root->children[i])
	            return false;
	    return true;
	}

	Node * remove(Node * root, string s, int deapth = 0)
	{
		if(root == NULL)
			return root;

		if(deapth == s.length())
		{
			if(root->isEndOfWord)
				root->isEndOfWord = false;

			if(isEmpty(root))
			{
				delete root;
				root = NULL;
			}

			return root;
		}
		else
		{
			int idx = s[deapth] - 'a';
			root->children[idx] = remove(root->children[idx], s, deapth + 1);

			if(isEmpty(root) and !root->isEndOfWord)
			{
				delete(root);
				root = NULL;
			}

			return root;
		}
	}
};

int main()
{
	string keys[] = { "the", "a", "hello", "any", "by","long", "their", "hero", "aeroplane","live" };
    int n = 10;
    Trie root;
    for (int i = 0; i < n; i++)
        root.insert(keys[i]);
    if(root.search("the"))
    	cout << "Yes 'the' is present \n";
    else
    	cout << "No 'the' is not present \n";


    if(root.search("hello"))
    	 cout << "Yes 'hello' is present \n";
    else
    	 cout << "No 'hello' is not present \n";


    root.remove(root.sendRoot(), "heroplane");


    if(root.search("heroplane"))
    	 cout << "Yes 'heroplane' is present \n";
    else
		 cout << "No 'heroplane' is absent\n";
	return 0;
}
