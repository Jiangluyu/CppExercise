
#include<iostream>

class HuffNode {
public:
	virtual ~HuffNode() {}
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
	virtual HuffNode* getright() = 0;
	virtual HuffNode* getleft() = 0;
	virtual char getch() = 0;
};

class LeafNode :public HuffNode {
private:
	char ch;
	int wgt;
public:
	LeafNode(const char &ch, int wgt)
	{
		this->ch = ch;
		this->wgt = wgt;
	}
	int weight()
	{
		return wgt;
	}
	char value()
	{
		return ch;
	}
	bool isLeaf()
	{
		return true;
	}
	HuffNode* getright()
	{
		return NULL;
	}
	HuffNode* getleft()
	{
		return NULL;
	}
	char getch()
	{
		return ch;
	}

};
class IntlNode :public HuffNode {
private:
	int wgt;
	HuffNode* left;
	HuffNode* right;
public:
	IntlNode(HuffNode* l, HuffNode* r)
	{
		wgt = l->weight() + r->weight();
		left = l;
		right = r;
	}
	int weight()
	{
		return wgt;
	}
	bool isLeaf()
	{
		return false;
	}
	void setLeft(HuffNode* l)
	{
		left = l;
	}
	void setRight(HuffNode* r)
	{
		right = r;
	}
	HuffNode* getleft()
	{
		return left;
	}
	HuffNode* getright()
	{
		return right;
	}
	char getch()
	{
		return NULL;
	}
};
class Hufftree {
private:
	HuffNode * root;
public:
	Hufftree(char key, int value)
	{
		root = new LeafNode(key, value);
	}
	Hufftree(Hufftree *left, Hufftree* right)
	{
		root = new IntlNode(left->root, right->root);
	}
	~Hufftree() {}
	HuffNode* getroot()
	{
		return root;
	}
	int getweight()
	{
		return root->weight();
	}
	HuffNode* getright()
	{
		return root->getright();
	}
	HuffNode* getleft()
	{
		return root->getleft();
	}
};
