/*
 * avl.cpp
 *
 *  Created on: 3 de nov de 2017
 *      Author: ramide
 */

#include <iostream>
#include "avl.h"

using namespace std;

// Execute com debug para ver que as chamadas de
//  BST::insert() e AVL::_insert() se alternam na pilha de execu��o.
//  BST::_insert() realiza a inser��o de fato, e na volta da recurs�o
//  AVL::_insert() verifica se est� balanceado e faz as rota��es se preciso.
BinaryTree::Node * AVLTree::_insert(Node *root, int key) {
	root = BinaryTree::_insert(root, key);

	root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::_remove(Node *root, int key) {
	root = BinaryTree::_remove(root, key);

	root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::_removeMax(Node *root, int & max) {
	root = BinaryTree::_removeMax(root, max);

	root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::rebalance(Node * node) {
	if (node == nullptr || balanced(node)) return node;

	if (leftHeavy(node)) {
		if (rightHeavy(node->left)) node->left = rotateLeft(node->left);
		
		node = rotateRight(node);
		
	} else { // rightHeavy
		if (leftHeavy(node->right)) node->right = rotateRight(node->right);
		
		node = rotateLeft(node);
	}

	ASSERT(balanced(node), "Rebalanceamento falhou!");
	return node;
}

// Realiza a rota��o a esquerda sobre "node" retornando a nova raiz

BinaryTree::Node * AVLTree::rotateLeft(Node * node) {
	Node * X = node;
	Node * R = node->right;
	Node * RL = node->right->left;

	X->right = RL;
	R->left = X;

	updateH(X); // Primeiro X,
	updateH(R); // Altura de L depedende de X

	node = R;
	return node;
}

// Realiza a rota��o a direita sobre "node" retornando a nova raiz

BinaryTree::Node * AVLTree::rotateRight(Node * node) {
    //TODO
	Node* X = node;
	Node* R = node->left;
	Node* RL = node->left->right;

	X->left = RL;
	R->right = X;

	updateH(X);
	updateH(R);

	node = R;
	return node;
}

void AVLTree::_show(Node * root) {
	if (root == nullptr)
		return;
    _show(root->left);
	cout << "(" << root->key << ", "
			<< root->height << ", "
			<< BF(root) << ") ";
    _show(root->right);
}

int AVLTree::_validate(Node * root, int &min, int &max) {
	int valid = BinaryTree::_validate(root, min, max);

	return valid && balanced(root);
}
