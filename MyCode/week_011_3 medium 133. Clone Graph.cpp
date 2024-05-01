// https://leetcode.com/problems/clone-graph/description/

class Solution {
public:
	int startValue = 0;
	Node* firstNode = nullptr;
	map<int, Node*> nodeMap = map<int, Node*>();
	map<int, Node*>::iterator iter;

	Node* cloneGraph(Node* node) {
		if (node == nullptr)
			return node;

		if (node->val == startValue)
			return firstNode;

		iter = nodeMap.find(node->val);

		// 있으면 그냥 쓰고 없으면 구현하고
		Node* newNode = nullptr;
		if (iter == nodeMap.end())
		{
			newNode = new Node(node->val);
			newNode->neighbors.clear();
			nodeMap[node->val] = newNode; //등록
		}
		else
		{
			newNode = nodeMap.find(node->val)->second;
		}

		if (startValue == 0)
		{
			startValue = node->val;
			firstNode = newNode;
		}
		
		for (auto single : node->neighbors)
		{
			iter = nodeMap.find(single->val);
			if (iter == nodeMap.end()) //없으면
				newNode->neighbors.push_back(cloneGraph(single));
			else
				newNode->neighbors.push_back(iter->second);
		}

		return newNode;
	}
};