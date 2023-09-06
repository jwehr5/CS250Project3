/*
	Jayden Wehr
	BookPile.cpp

*/

#include "BookPile.h"
#include <string>
#include <iostream>
using namespace std;

BookPile::BookPile() {

	headBookPtr = nullptr;
	numberOfBooks = 0;
}

BookPile::BookPile(const BookPile& aBookPile) {

	Book* newBookPtr;
	Book* bookInFrontPtr;

	//Check to see if aBookPile is empty.
	if (aBookPile.headBookPtr == nullptr) {
		headBookPtr = nullptr;
	}
	else {
		//Copy the first book before moving on with the rest of the pile.
		newBookPtr = new Book(aBookPile.headBookPtr->getTitle());
		newBookPtr->setNext(headBookPtr);
		headBookPtr = newBookPtr;
		numberOfBooks++;

		Book* curBookPtr = aBookPile.headBookPtr->getNext();
		while (curBookPtr != nullptr) {

			newBookPtr = new Book(curBookPtr->getTitle());
			bookInFrontPtr = getPointerInFront(curBookPtr->getTitle());
			bookInFrontPtr->setNext(newBookPtr);
			curBookPtr = curBookPtr->getNext();
			numberOfBooks++;

		}
	}


}

BookPile::~BookPile() {
	clear();

}

int BookPile::getTitleLength(string bookTitle) {

	return bookTitle.size();
}

Book* BookPile::getPointerInFront(string bookTitle) {

	//If the book is at the beginning of the list, then return headBookPtr
	if (headBookPtr->getTitle() == bookTitle) {
		return headBookPtr;
	}

	Book* curBookPtr = headBookPtr;
	
	while (curBookPtr->getNext() != nullptr) {

		if (curBookPtr->getNext()->getTitle() == bookTitle) {
			break;
		}

		curBookPtr = curBookPtr->getNext();
	}

	return curBookPtr;
}


bool BookPile::removeBook(string bookTitle) {

	bool didRemove = false;

	//Check To make sure the book is in the pile.
	if (findBook(bookTitle) == -1) {
		return didRemove;
	}

	//Check to see if the book we want to remove is the head book.
	 if (headBookPtr->getTitle() == bookTitle) {

		Book* delPtr = headBookPtr;
		headBookPtr = headBookPtr->getNext();
		delete delPtr;

		numberOfBooks--;
		didRemove = true;
	}
	//The book we want to remove is elsewhere in the pile.
	else {
		Book* bookPtr = getPointerInFront(bookTitle);
		Book* delPtr = bookPtr->getNext();
		bookPtr->setNext(delPtr->getNext());
		delete delPtr;

		numberOfBooks--;
		didRemove = true;
	}

	return didRemove;
}

bool BookPile::removeBook(int bookPosition) {

	bool didRemove = false;

	//Get the title of the book.
	string bookTitle = getBook(bookPosition);

	didRemove = removeBook(bookTitle);


	return didRemove;
}

bool BookPile::addBook(string bookTitle) {

	bool didAdd = false;

	//Check to make sure the book is not already in the pile and that the book title is not an empty string.
	if (findBook(bookTitle) == -1 && !bookTitle.empty()) {

		//If its the first book, then we can put it in without doing any comparisons.
		if (numberOfBooks == 0) {
			Book* newBookPtr = new Book(bookTitle);
			newBookPtr->setNext(headBookPtr);
			headBookPtr = newBookPtr;

			numberOfBooks++;
			didAdd = true;
			return didAdd;

		}//end-if

		/*Do a comparison with the first book only. If the book were adding in has a longer title
		 than what headBook points to, then headBook will point to the new book were adding.
		*/
		if (getTitleLength(headBookPtr->getTitle()) <= getTitleLength(bookTitle)) {
			Book* newBookPtr = new Book(bookTitle);
			newBookPtr->setNext(headBookPtr);
			headBookPtr = newBookPtr;

			numberOfBooks++;
			didAdd = true;

		}
		else {

			//Go through each of the books and do a comparison with each until we find the right spot.
			Book* curBookPtr = headBookPtr;
			while (curBookPtr->getNext() != nullptr) {

				if (getTitleLength(curBookPtr->getTitle()) > getTitleLength(bookTitle) &&
					getTitleLength(curBookPtr->getNext()->getTitle()) <= getTitleLength(bookTitle)) {

					Book* newBookPtr = new Book(bookTitle);
					newBookPtr->setNext(curBookPtr->getNext());
					curBookPtr->setNext(newBookPtr);

					numberOfBooks++;
					didAdd = true;
					break;

				}

				curBookPtr = curBookPtr->getNext();
			}

		}// end-if/else

	}// end-if

	

	
	return didAdd;
}

int BookPile::findBook(string bookTitle) {

	int currentBookPosition = 1;
	bool foundBook = false;
	Book* curBookPtr = headBookPtr;
	while (curBookPtr != nullptr) {

		if (curBookPtr->getTitle() == bookTitle) {
			foundBook = true;
			break;
		}

		currentBookPosition++;
		curBookPtr = curBookPtr->getNext();
	}

	if (foundBook) {
		return currentBookPosition;
	}
	else {
		return -1;
	}

}

void BookPile::displayPile() {

	//Check to see if the pile is empty
	if (numberOfBooks == 0) {
		cout << "Book Pile is Empty" << endl;
	}

	Book* curBookPtr = headBookPtr;
	
	int i = 1;
	while (curBookPtr != nullptr) {

		cout << i << ". " << curBookPtr->getTitle() << " (" << getTitleLength(curBookPtr->getTitle()) << ")" << endl;
		curBookPtr = curBookPtr->getNext();
		i++;
	}

}

string BookPile::getBook(int bookPosition) {

	string bookTitle = "";
	
	//If bookPosition is an invalid position then go ahead and return empty string.
	if (bookPosition < 1 || bookPosition > numberOfBooks) {
		return bookTitle;
	}

	int currentBookPosition = 1;
	Book* curBookPtr = headBookPtr;

	while (curBookPtr != nullptr) {

		bookTitle = curBookPtr->getTitle();
		if (currentBookPosition == bookPosition) {
			break;
		}
		
		curBookPtr = curBookPtr->getNext();
		currentBookPosition++;
	}

	return bookTitle;
}

bool BookPile::renameBook(string oldName, string newName) {

	bool didRename = false;

	//Check to make sure that the old book is in the pile and that its not empty string.
	if (findBook(oldName) > -1 && !oldName.empty()) {

		//If oldName has the same number of characters as newName, then we don't neeed to worry about reordering the books.
		if (getTitleLength(oldName) == getTitleLength(newName)) {
			Book* bookPtr = getPointerInFront(oldName);
			bookPtr->getNext()->setTitle(newName);

			didRename = true;
		}
		//Remove the old book and then re-add to the pile with the new name.
		else {
			removeBook(oldName);
			addBook(newName);

			didRename = true;

		}// end-if/else
		
	}// end-if


	return didRename;
}

int BookPile::bookCount() {

	return numberOfBooks;
}

void BookPile::clear() {

	Book* delPtr;

	//Back up each book with delPtr before moving headBookPtr to the next book.
	while (headBookPtr != nullptr) {
		delPtr = headBookPtr;
		headBookPtr = headBookPtr->getNext();
		delete delPtr;
	}

	numberOfBooks = 0;

}