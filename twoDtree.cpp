/**
*
* twoDtree (pa3)
* slight modification of a Kd tree of dimension 2.
* twoDtree.cpp
* This file will be used for grading.
*
*/
#include "utility"
#include "twoDtree.h"
#include "stats.h"
#include <iostream>

/* given */
twoDtree::Node::Node(pair<int, int> ul, pair<int, int> lr, RGBAPixel a)
	:upLeft(ul), lowRight(lr), avg(a), left(NULL), right(NULL)
{}

/* given */
twoDtree::~twoDtree() {
	clear();
}

/* given */
twoDtree::twoDtree(const twoDtree & other) {
	copy(other);
}

/* given */
twoDtree & twoDtree::operator=(const twoDtree & rhs) {
	if (this != &rhs) {
		clear();
		copy(rhs);
	}
	return *this;
}
/**
* Constructor that builds a twoDtree out of the given PNG.
* Every leaf in the tree corresponds to a pixel in the PNG.
* Every non-leaf node corresponds to a rectangle of pixels
* in the original PNG, represented by an (x,y) pair for the
* upper left corner of the rectangle and an (x,y) pair for
* lower right corner of the rectangle. In addition, the Node
* stores a pixel representing the average color over the
* rectangle.
*
* Every node's left and right children correspond to a partition
* of the node's rectangle into two smaller rectangles. The node's
* rectangle is split by the horizontal or vertical line that
* results in the two smaller rectangles whose sum of squared
* differences from their mean is as small as possible.
*
* The left child of the node will contain the upper left corner
* of the node's rectangle, and the right child will contain the
* lower right corner.
*
* This function will build the stats object used to score the
* splitting lines. It will also call helper function buildTree.
*/
twoDtree::twoDtree(PNG & imIn) {
	height = imIn.height();
	width = imIn.width();
	stats s(imIn);
	root = buildTree(s, pair<int, int>(0, 0), pair<int, int>(width - 1, height - 1));
}


/**
* Private helper function for the constructor. Recursively builds
* the tree according to the specification of the constructor.
* @param s Contains the data used to split the rectangles
* @param ul upper left point of current node's rectangle.
* @param lr lower right point of current node's rectangle.
*/
twoDtree::Node * twoDtree::buildTree(stats & s, pair<int, int> ul, pair<int, int> lr) {
	Node* node = NULL;

	if (ul >= lr)
	{
		return new Node(ul, lr, s.getAvg(ul, lr));
	}
	else {

		node = new Node(ul, lr, s.getAvg(ul, lr));

		pair<int, int> new_ul = ul;
		pair<int, int> new_lr = lr;


		long min = LONG_MAX;
		long score;
		// vertical
		for (int x = ul.first; x < (lr.first - 1); x++)
		{

			score = s.getScore(ul, pair<int, int>(x, lr.second)) +
				s.getScore(pair<int, int>(x + 1, ul.second), lr);
			if (score <= min)
			{
				min = score;

				new_lr.first = x;
				new_lr.second = lr.second;

				new_ul.first = x + 1;
				new_ul.second = ul.second;
			}
		}


		for (int y = ul.second; y < (lr.second - 1); y++)
		{

			score = s.getScore(ul, pair<int, int>(lr.first, y)) +
				s.getScore(pair<int, int>(ul.first, y + 1), lr);
			if (score <= min)
			{
				min = score;
				new_ul.first = ul.second;
				new_ul.first = y + 1;

				new_lr.first = lr.first;
				new_lr.second = y;

				// p1 = lr.first;
				// p2 = y;

				// p3 = ul.second;
				// p4 = y+1;
				//std::cout<< "p1="<< p1 << " p2="<<p2<< " p3="<<p3<<" p4=" <<p4 <<" score="<< min <<"vertical split"<< endl;
			}
		}

		if (ul.first > new_lr.first || ul.second > new_lr.second)
		{
			return node;
		}

		if (new_ul.first > lr.first || new_ul.second > lr.second)
		{
			return node;
		}

		std::cout << "new_lr.first = " << new_lr.first << " new_lr.second = " << new_lr.second << " new_ul.first = " << new_ul.first << " new_ul.second = " << new_ul.second << endl;
		std::cout << "lr.first = " << lr.first << " lr.second = " << lr.second << " ul.first = " << ul.first << " ul.second = " << ul.second << "\n" << endl;
		if (new_lr >= lr || new_ul <= ul) //.first && p2 == l2.second && p3 == ul.first && p4 == ul.second)
		{
			return node;
		}

		node->left = buildTree(s, ul, new_lr);  //pair<int, int>(p1, p2));
		node->right = buildTree(s, new_ul, lr);  // pair<int, int>(p3,p4)

	}

	return node;
}


/**
* Render returns a PNG image consisting of the pixels
* stored in the tree. may be used on pruned trees. Draws
* every leaf node's rectangle onto a PNG canvas using the
* average color stored in the node.
*/
PNG twoDtree::render() {
	PNG p(width, height);
	renderHelper(root, p);
	return p;
}

void twoDtree::renderHelper(Node* root, PNG &myPng) {
	if (root == NULL) {
		return;
	}
	if (!root->left && !root->right) {
		for (int y = root->upLeft.second; y <= root->lowRight.second; y++) {
			for (int x = root->upLeft.first; x <= root->lowRight.first; x++) {
				RGBAPixel *pixel = myPng.getPixel(x, y);
				//	pixel->r = root->avg.r;
				//	pixel->g = root->avg.g;
				//	pixel->b = root->avg.b;
				//	pixel->a = root->avg.a;

				*pixel = root->avg;
			}
		}
	}
	if (root->left != NULL) {
		renderHelper(root->left, myPng);
	}
	if (root->right != NULL) {
		renderHelper(root->right, myPng);
	}
}

/*
*  Prune function trims subtrees as high as possible in the tree.
*  A subtree is pruned (cleared) if at least pct of its leaves are within
*  tol of the average color stored in the root of the subtree.
*  Pruning criteria should be evaluated on the original tree, not
*  on a pruned subtree. (we only expect that trees would be pruned once.)
*
* You may want a recursive helper function for this one.
*/
void twoDtree::prune(double pct, int tol) {
	/* your code here */
}




/**
* Destroys all dynamically allocated memory associated with the
* current twoDtree class. Complete for PA3.
* You may want a recursive helper function for this one.
*/
void twoDtree::clear() {
	/* your code here */
	if (root == NULL) { return; }

	clear(root);
}

/**
* Destroys all dynamically allocated memory associated with the
* current twoDtree class. Complete for PA3.
* The recursive helper
*/
void twoDtree::clear(Node* root) {
	/* your code here */
	if (root->left != NULL) {
		clear(root->left);
	}
	else if (root->right != NULL) {
		clear(root->right);
	}

	delete root;
}

/**
* Copies the parameter other twoDtree into the current twoDtree.
* Does not free any memory. Called by copy constructor and op=.
* You may want a recursive helper function for this one.
* @param other The twoDtree to be copied.
*/
void twoDtree::copy(const twoDtree & orig) {
	this->height = orig.height;
	this->width = orig.width;
	Node* roots = new Node(orig.root->upLeft, orig.root->lowRight, orig.root->avg);
	copyHelper(roots, orig.root);
	//delete roots;
}

void twoDtree::copyHelper(Node* rootCurr, Node* rootOther) {
	if (rootOther->left == NULL && rootOther->right == NULL) {
		return;
	}
	if (rootOther->left != NULL) {
		Node* lchild = new Node(rootOther->left->upLeft, rootOther->left->lowRight, rootOther->left->avg);
		rootCurr->left = lchild;
		copyHelper(lchild, rootOther->left);
	}
	if (rootOther->right != NULL) {
		Node* rchild = new Node(rootOther->right->upLeft, rootOther->right->lowRight, rootOther->right->avg);
		rootCurr->right = rchild;
		copyHelper(rchild, rootOther->right);
	}
	//delete lchild;
	//delete rchild;
}
