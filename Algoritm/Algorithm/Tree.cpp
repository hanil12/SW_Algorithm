#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

// - 선형자료구조 : vector, list, stack, queue
// - 비선형자료구조 : tree, graph

// Tree
// 1. 계층구조를 표현할 때 자주 쓰인다.
// -> 부모와 자식이 있다.
// -> Root Node : 최상위 부모 => 모든 트리에 대해서 단 하나의 루트노드만 존재한다.
// -> Leaf Node : 최하위 자식
// 
// 2. 트리는 잘라도 서브트리다.
// -> 재귀적으로 자식을 타고 들어갈 수 있다.

// 트리의 종류
// 1. 이진트리
// 2. 포화이진트리
// 3. 완전이진트리
// 4. 이진탐색트리
// 5. 힙트리
// 6. 자가균형이진탐색트리

struct Node
{
	Node(string name)
	: data(name)
	{

	}

	string data;
	vector<Node*> children;
};

Node* CreateTree()
{
	Node* root = new Node("게임팀");

	// 프로그래밍팀
	{
		Node* node = new Node("프로그래밍팀");
		root->children.push_back(node);

		{
			Node* leaf = new Node("서버");
			node->children.push_back(leaf);
		}

		{
			Node* leaf = new Node("클라이언트");
			node->children.push_back(leaf);
		}

		{
			Node* leaf = new Node("엔진");
			node->children.push_back(leaf);
		}
	}

	// 기획팀
	{
		Node* node = new Node("기획팀");
		root->children.push_back(node);

		{
			Node* leaf = new Node("스토리");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("밸런스");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("시스템");
			node->children.push_back(leaf);
		}
	}

	// 아트팀
	{
		Node* node = new Node("아트팀");
		root->children.push_back(node);
		{
			Node* leaf = new Node("캐릭터모델");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("배경");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("UI");
			node->children.push_back(leaf);
		}
	}

	return root;
}

void PrintTree(Node* node, int depth = 0)
{
	for (int i = 0; i < depth; i++)
	{
		cout << " - ";
	}

	cout << node->data << endl;
	for (int i = 0; i < node->children.size(); i++)
	{
		PrintTree(node->children[i], depth + 1);
	}
}

int main()
{
	Node* root = CreateTree();
	PrintTree(root);

	return 0;
}