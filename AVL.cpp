#include "AVL.hpp"
AVL::AVL(Team *TEAM):height(0) {
	team = TEAM;
	left = NULL;
	right = NULL;
}

AVL::~AVL() {
	delete right;
	delete left;
}

AVL* AVL::add_Node(AVL *node, Team *TEAM) {
	if(node == NULL) {
		node = new AVL(TEAM);
		return node;
	}
	if(TEAM->get_Points() <= node->team->get_Points())
		node->left = add_Node(node->left, TEAM);
	else
		node->right = add_Node(node->right, TEAM);

	node->height = AVL::max_Height(AVL::get_Height(node->left), AVL::get_Height(node->right)) + 1;

	if(AVL::get_Height(node->left) - AVL::get_Height(node->right) > 1 && TEAM->get_Points() <= node->left->team->get_Points())
		return right_Rotation(node);
	if(AVL::get_Height(node->left) - AVL::get_Height(node->right) < -1 && TEAM->get_Points() > node->right->team->get_Points())
		return left_Rotation(node);
	if(AVL::get_Height(node->left) - AVL::get_Height(node->right) > 1 && TEAM->get_Points() > node->left->team->get_Points()) {
		node->left = left_Rotation(node->left);
		return right_Rotation(node);
	}
	if(AVL::get_Height(node->left) - AVL::get_Height(node->right) < -1 && TEAM->get_Points() < node->right->team->get_Points()) {
		node->right = right_Rotation(node->right);
		return left_Rotation(node);
	}

	return node;
}

AVL* AVL::right_Rotation(AVL *node) {
	AVL *tmp1 = node->left->right;
	node->left->right = node;
	AVL* tmp2 = node->left;
	node->left = tmp1;
	node->height = AVL::max_Height(AVL::get_Height(node->left), AVL::get_Height(node->right)) + 1;
	tmp2->height = AVL::max_Height(AVL::get_Height(tmp2->left), AVL::get_Height(tmp2->right)) + 1;
	return tmp2;
}

AVL* AVL::left_Rotation(AVL *node) {
	AVL *tmp1 = node->right->left;
	node->right->left = node;
	AVL *tmp2 = node->right;
	node->right = tmp1;
	node->height = AVL::max_Height(AVL::get_Height(node->left), AVL::get_Height(node->right)) + 1;
	tmp2->height = AVL::max_Height(AVL::get_Height(tmp2->left), AVL::get_Height(tmp2->right)) + 1;
	return tmp2;
}


int AVL::get_Height(AVL *avl) {
	if(avl == NULL)
		return -1;
	return avl->height;
}

int AVL::max_Height(int h1, int h2) {
	return (h1>h2) ? h1 : h2;
}

AVL* AVL::create_AVL(AVL* node,List* list) {
	if(list->get_Next() == NULL)
		return node;
	node = AVL::create_AVL(node, list->get_Next());
	cout<<list->get_Team()->get_Name()<<endl;
	node = node->add_Node(node, list->get_Team());
	return node;
}

void AVL::print_NIV2(ofstream &out) const {

	out<<"\n\nTHE LEVEL 2 TEAMS ARE: \n";
	out<<this->right->right->team->get_Name()<<endl;
	out<<this->right->left->team->get_Name()<<endl;
	out<<this->left->right->team->get_Name()<<endl;
	out<<this->left->left->team->get_Name();
}