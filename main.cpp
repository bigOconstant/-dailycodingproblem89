#include <iostream>
#include <cassert>

class Node {
public:
         int value;
	 Node* left;
	 Node* right;

	Node(int input){
		value = input;
		left = NULL;
		right = NULL;
	}
	void insert(int input) {
		if (input < this->value){
			if (this->left) {
				this->left->insert(input);
			}
			else {
				this->left = new Node(input);
				return;
			}
		}
		else if (input > this->value) {
			if (this->right) {
				this->right->insert(input);
			}
			else {
				this->right = new Node(input);
				return;
			}
		}
	}
};

bool tree_correct(Node input) {
	auto correct = true;
	if (input.left != NULL) {
		if (input.value < input.left->value) {
			return false;
		}
		else {
			correct = tree_correct(*input.left);
			if (!correct) {
				return false;
			}
		}
	}

	if (input.right != NULL) {
		if (input.value > input.right->value) {
			return false;
		} 
		else {
			correct = tree_correct(*input.right);
			if (!correct)
				return false;
		}
	}
	return correct;
}

int main()
{
    std::cout << "Creating test Tree\n"; 
	auto root = Node(5);
	root.insert(6);
	root.insert(4);
	root.insert(2);

	auto correct = tree_correct(root);
	assert(correct == 1);

	std::cout << "Inserting purposfully incorrect node"<<std::endl;
	root.right->right = new Node(1);
	correct = tree_correct(root);
	assert(correct == 0);
	std::cout <<"Test passed"<<std::endl;

}
