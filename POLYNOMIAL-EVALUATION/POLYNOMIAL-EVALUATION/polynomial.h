#pragma once

#include<iostream>
#include"Term.h"
using namespace std;

class polynomial
{
public:
	Term* head, *tail;

	polynomial() : head(NULL), tail(NULL) {}

	void insert	(Term* NewTerm) {//sorted
		

		if (!head) { //first node
			head = tail = NewTerm;
		}
		else if (head->exponent >= NewTerm->exponent) {
			NewTerm->next = head;
			head = NewTerm;
		}
		else if (tail->exponent <= NewTerm->exponent) {
			tail->next = NewTerm;
			tail = NewTerm;
		}
		else
		{
			Term* current = head;

			  while (current->next && current->next->exponent > NewTerm->exponent) {

				current = current->next;
			  }
			
			NewTerm->next = current->next;
			current->next = NewTerm;
		}
	}

	void display() {
		if (!head) {
			cout << "\n List is Empty! ";
			return;
		}
		else
		{
			Term* temp = head; // 3x^2 + 2x +1
			while(temp != NULL) {// -3x^2 + 2x -1

				if (temp != head && temp->cofficient>=0) {
					(temp->sign) ? cout << "+" : cout << "-";
				}
					cout << temp->cofficient << "x^" << temp->exponent << " ";
			}
		}

	}

	void operator + (polynomial& poly) {// 3x^2 + 2x +1
	/*	polynomial result; /// -3x^2 + 2x -1
		Term* t1 = head;
		Term* t2 = poly.head;

		while (t1 || poly.head) {
			Term* NewTerm = new Term;
			if (t1 && (!poly.head || (t1->exponent) > poly.head->exponent)) {
				NewTerm = t1;
				t1 = t1->next;
			}
		}*/

		Term* temp = this->head; 
			Term* Newtemp = poly.head;

		while (temp) {
			while (Newtemp) {
				if (Newtemp->exponent >= temp->exponent|| Newtemp->exponent < temp->exponent) {
					Term* term = Newtemp;
					insert(temp);
				}
				else if () {

				}
				else {

				}
				Newtemp = Newtemp->next;
			}
			temp = temp->next;
		}
		

	}

	void operator - (polynomial& poly) {

	}

	void operator * (polynomial& poly) {

	}

	void operator / (polynomial& poly) {

	}


};

