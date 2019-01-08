#include <malloc.h>
#include <iostream>
#include <stack>
#include <queue>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
#include<string.h>
using namespace std;

typedef char ElemType;
struct TNode 
{
	ElemType data;
	struct TNode *left;
	struct TNode *right;
};
typedef TNode*  BinTree;

//先序遍历创建二叉树
void CreateTreeNode(BinTree &T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;  
	else
	{
		T = (BinTree)malloc(sizeof(TNode));
		//if (!*T)
		//exit(OVERFLOW); //内存分配失败则退出。
		(T)->data = ch;
		CreateTreeNode(T->left);
		CreateTreeNode(T->right);   
	}
}



// 先序遍历(递归)
void PreOrderTraversal(BinTree BT) {
	if (BT) {
		printf("%c →", BT->data);
		PreOrderTraversal(BT->left);
		PreOrderTraversal(BT->right);
	}
}


// 中序遍历(递归)
void InOrderTraversal(BinTree BT) {
	if (BT) {
		InOrderTraversal(BT->left);
		printf("%c →", BT->data);
		InOrderTraversal(BT->right);
	}
}


// 后序遍历(递归)
void PostOrderTraversal(BinTree BT) {
	if (BT) {
		PostOrderTraversal(BT->left);
		PostOrderTraversal(BT->right);
		printf("%c →", BT->data);
	}
}


// 先序遍历
void PreOrderTraversal_(BinTree BT) {

	if (!BT) {
		printf("空树...\n");
		return;
	}

	std::stack<BinTree> sBT;
	BinTree T = BT;

	while (T || !sBT.empty()) {
		while (T) {
			printf("%c →", T->data);
			sBT.push(T);
			T = T->left;
		}
		T = sBT.top();
		sBT.pop();
		T = T->right;
	}
	printf("\n");
}

// 中序遍历
void InOrderTraversal_(BinTree BT) {

	if (!BT) {
		printf("空树...\n");
		return;
	}

	std::stack<BinTree> sBT;
	BinTree T = BT;

	while (T || !sBT.empty()) {
		while (T) {
			sBT.push(T);
			T = T->left;
		}
		T = sBT.top();
		sBT.pop();
		printf("%c →", T->data);
		T = T->right;
	}
	printf("\n");
}

// 后序遍历
void PostOrderTraversal_(BinTree BT) {

	if (!BT) {
		printf("空树...\n");
		return;
	}

	std::stack<BinTree> sBT;
	BinTree T = BT;
	sBT.push(T);
	sBT.push(T);
	while (!sBT.empty()) {
		T = sBT.top();
		sBT.pop();
		if (!sBT.empty() && T == sBT.top()) {
			if (T->right) {
				sBT.push(T->right);
				sBT.push(T->right);
			}
			if (T->left) {
				sBT.push(T->left);
				sBT.push(T->left);
			}
		}
		else {
			printf("%c →", T->data);
		}
	}

	printf("\n");
}




// 二叉树的结点数
int NumOfTNode(BinTree BT) {
	if (!BT) {
		return 0;
	}
	else {
		return 1 + NumOfTNode(BT->left) + NumOfTNode(BT->right);
	}
}


// 二叉树的深度
int DepthOfBinTree(BinTree BT) {
	if (BT) {
		return DepthOfBinTree(BT->left) > DepthOfBinTree(BT->right) ? DepthOfBinTree(BT->left) + 1 : DepthOfBinTree(BT->right) + 1;
	}
	else {
		return 0;
	}
}

// 二叉树的叶子结点数
int NumOfLeafNode(BinTree BT) {
	if (!BT) {
		return 0;
	}
	else if (BT->left == NULL && BT->right == NULL) {
		return 1;
	}
	else {
		return NumOfLeafNode(BT->left) + NumOfLeafNode(BT->right);
	}
}


// 输出叶子结点
void printLeafNode(BinTree BT) {
	if (BT) {
		if (BT->left == NULL && BT->right == NULL) {
			printf("%c ", BT->data);
		}
		printLeafNode(BT->left);
		printLeafNode(BT->right);
	}
}


//层序遍历
void LevelOrderTraversal(BinTree &T) {
	if (NULL == T){
		cout << "这是空树" << endl;
		return;
	}
	queue<BinTree> Q;
	Q.push(T);
	while (!Q.empty())
	{
		cout << Q.front()->data << "→";
		if (Q.front()->left)
			Q.push(Q.front()->left);

		if (Q.front()->right)
			Q.push(Q.front()->right);

		Q.pop();
	}

}



//树形打印

void display(BinTree &root)
{
	if (root != NULL)
	{
		cout << root->data;
		if (root->left != NULL)
		{
			cout << '(';
			display(root->left);
		}
		if (root->right != NULL)
		{
			cout << ',';
			display(root->right);
			cout << ')';
		}
	}
}


//int j = 0;
void PrintTree(BinTree T, int layout)
{
	//char * array[20] = { "①", "②", "③", "④", "⑤", "⑥", "⑦", "⑧", "⑨", "⑩", "⑪", "⑫",
	//                     "⑬", "⑭", "⑮", "⑯", "⑰", "⑱", "⑲", "⑳"};
	int i = 0;

	if (T == NULL)
		return;
	PrintTree(T->right, layout + 1);
	for (i = 0; i < layout; i++)
	{
		printf("      ");
	}
	//printf("%s%c\n\n", array[j], T->data);
	printf("%c\n\n", T->data);
	//++j;
	PrintTree(T->left, layout + 1);
}



void adjust(int a)
{
	char cha[6][7] = { ">--+<", ">--+<", ">-+<", ">+<", "><", "<" };
	int k = 0;
	while (a)
	{
		a /= 10;
		k++;
	}
	printf("%s\n", cha[k]);
}


void shu(BinTree &p, int len)//数的形状len=0;
{
	int i;
	if (p != NULL)
	{
		shu(p->right, len + 1);
		for (i = 1; i <= 4 * len; i++)
		{
			if (i % 4 == 1)
				printf("|");
			else
				printf(" ");
		}
		printf("%c", p->data);
		adjust(p->data);
		shu(p->left, len + 1);
	}
}



int main(int argc, char **argv)
{
	cout << "按照先序遍历规则输入树，空用'#'表示：" << endl;
	cout << "请输入：";
	//测试二叉树：ABD##E##C#F##
	BinTree T;
	CreateTreeNode(T);

	cout << "---------------树形打印---------------" << endl;
	cout << "树形打印方式一: " << endl;
	//TreeDisplay(T);
	display(T);
	cout << endl;
	cout << endl;
	cout << "树形打印方式二: " << endl;
	int t = DepthOfBinTree(T);
	PrintTree(T, t);
	cout << "树形打印方式三: " << endl << endl;
	shu(T, 0);
	cout << endl;

	cout <<"------------递归遍历-----------" << endl;
	cout << "先序遍历递归实现: ";
	PreOrderTraversal(T);
	cout << endl;
	cout << "中序遍历递归实现: ";
	InOrderTraversal(T);
	cout << endl;
	cout << "后序遍历递归实现: ";
	PostOrderTraversal(T);
	cout << endl << endl;

	cout << "----------非递归遍历-----------" << endl;
	cout << "非递归先序遍历: ";
	PreOrderTraversal_(T);
	cout << "非递归中序遍历: ";
	InOrderTraversal_(T);
	cout << "非递归后序遍历: ";
	PostOrderTraversal_(T);

	cout << "层序遍历       : ";
	LevelOrderTraversal(T);
	cout << endl << endl;



	cout << "-----------其他属性----------" << endl;
	printf("二叉树的结点总数: %d\n", NumOfTNode(T));
	printf("二叉树的深度为  : %d\n", DepthOfBinTree(T));
	printf("叶子结点数为    : %d\n", NumOfLeafNode(T));
	printf("叶子结点为      : ");
	printLeafNode(T);


	cout << endl;
	return 0;
}
