#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node ** forward;
    Node(int data, int level)
	{
		this->data = data;
		this->forward = new Node * [level + 1];

		for(int i = 0 ; i <= level; i++)
			this->forward[i] = NULL;
	}
};

class skipList
{
	Node * header;
	int MAXLEVEL;
	int level;
	float p;

public:

	skipList(int mlevel, float prob)
	{
		p = prob;
		MAXLEVEL = mlevel;

		header = new Node(-1, MAXLEVEL);
	}

	int randomLevel()
	{
		float r = (float)rand()/RAND_MAX;
	    int level = 0;
	    while (r < p && level < MAXLEVEL)
	    {
	        level++;
	        r = (float)rand()/RAND_MAX;
	    }
	    return level;
	}


	void insert(int data)
	{
		Node * current = header;
        Node * update[MAXLEVEL + 1];
        for(int i = 0; i <= MAXLEVEL; i++)
			update[i] = NULL;
        for (int i = level; i >= 0; i--)
	    {
            while (current->forward[i] != NULL && current->forward[i]->data < data)
	            current = current->forward[i];

	        update[i] = current;
	    }

	    current = current->forward[0];
        if(current == NULL or current->data != data)
	    {
	    	int rlevel = randomLevel();

	    	if(rlevel > level)
	    	{
	    		for(int i = level + 1; i <= rlevel; i++)
	    		{
	    			update[i] = header;
	    		}

	    		level = rlevel;
	    	}

	    	Node * newnode = new Node(data, rlevel);

	    	for(int i = 0; i <= rlevel; i++)
	    	{
	    		newnode->forward[i] = update[i]->forward[i];
	    		update[i]->forward[i] = newnode;
	    	}

	    }
	 }

	    void displayList()
	    {
	    	cout<<"\n*****Skip List*****\n";
		    for (int i=0;i<=level;i++)
		    {
		        Node *node = header->forward[i];
		        cout << "Level " << i << ": ";

		        while (node != NULL)
		        {
		            cout << node->data<<" ";
		            node = node->forward[i];
		        }

		        cout << "\n";
		     }
	    }

	    void search(int data)
		{
		    Node *current = header;

		    for(int i = level; i >= 0; i--)
		    {
		        while(current->forward[i] &&
		               current->forward[i]->data < data)
		            current = current->forward[i];

		    }

		    current = current->forward[0];

		    if(current and current->data == data)
		        cout<<"Found data: "<<data<<"\n";
		    else
		    	cout<<"ERROR data NOT FOUND \n";
		}

		void deleteNode(int k)
		{
			Node * current = header;

			Node * update[MAXLEVEL + 1];

			for(int i = 0; i <= MAXLEVEL; i++)
				update[i] = NULL;

			for(int i = level; i >= 0; i--)
			{
				while(current->forward[i] != NULL  and current->forward[i]->data < k)
				{
					current = current->forward[i];
				}

				update[i] = current;
			}

			current = current->forward[0];

			if(current != NULL and current->data == k)
		    {

		        for(int i=0;i<=level;i++)
		        {
		            if(update[i]->forward[i] != current)
		                break;

		            update[i]->forward[i] = current->forward[i];
		        }


		        while(level>0 && header->forward[level] == 0)
		            level--;


		         cout<<"Successfully deleted data "<<k<<"\n";
		    }
		}


};


int main()
{
	srand((unsigned)time(0));

    skipList lst(3, 0.5);
    lst.insert(2);
    lst.insert(8);
    lst.insert(10);
    lst.insert(19);
    lst.insert(17);
    lst.insert(26);
    lst.insert(21);
    lst.insert(27);
    lst.insert(32);
    lst.displayList();


    lst.search(17);

    lst.deleteNode(17);
    lst.displayList();
	return 0;
}

