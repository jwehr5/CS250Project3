/*
	Jayden Wehr
	BookPile.h

*/

#ifndef BOOKPILE_H
#define BOOKPILE_H

#include "Book.h"
using namespace std;

class BookPile {

private:
	Book* headBookPtr;
	int numberOfBooks;

	/**
	* getTitleLength takes in a given book title and returns the number of characters that the title has.
	*
	* @param bookTitle This is the title of the book.
	* @return The number of characters that the book has.
	* @pre bookTitle must not be empty string.
	**/
	int getTitleLength(string bookTitle);

	/**
	* getPointerInFront returns a pointer to the book in front of the book that is passed in the parameter.
	* 
	* @param bookTitle This is the title of the book.
	* @return A pointer to the book that is in front of the book passed in the parameter. 
	* @pre bookTitle must be in the pile of books.
	**/
	Book* getPointerInFront(string bookTitle);

public:
	BookPile();
	BookPile(const BookPile& aBookPile);
	~BookPile();

	/**
	* removeBook removes a book from the pile using the title of the book.
	* 
	* @param bookTitle This is the title of the book.
	* @return true if the book was successfully removed.
	* @return false if the book was unable to be removed.
	* @pre bookTitle must be in the pile of books.
	**/
	bool removeBook(string bookTitle);

	/**
	* removeBook removes a book from the pile using the postion of the book starting from 1.
	* 
	* @param bookPosition This is the position of the book in the pile.
	* @return true if the book was successfully removed.
	* @return false if the book was unable to be removed.
	* @pre bookPosition must be a valid position in the pile of books.
	**/
	bool removeBook(int bookPosition);

	/**
	* addBook adds a book to the pile depending on how many characters are in the title. A book cannot
	  be below a book with a shorter title.
	*
	* @param bookTitle This is the title of the book.
	* @return true if the book was successfully added to the pile.
	* @return false if the book was unable to be added.
	* @pre bookTitle must not already be in the pile or be an empty string.
	**/
	bool addBook(string bookTitle);

	/**
	* findBook finds a book using the title and returns the position of that book.
	* 
	* @param bookTitle. This is the title of the book.
	* @return the positon of the book in the pile.
	* @return -1 if the book was not able to be found.
	* @pre bookTitle must be in the pile of books.
	**/
	int findBook(string bookTitle);

	/**
	* displayPile displays the pile of books.
	* 
	* @pre There must be at least 1 book in the pile.
	**/
	void displayPile();

	/**
	* getBook finds a book using the position of the book in the pile.
	* 
	* @param bookPosition. This is the position of the book in the pile.
	* @return the title of the book
	* @return empty string if the book was unable to be found.
	* @pre bookPosition must be a valid position.
	**/
	string getBook(int bookPosition);

	/**
	* renameBook finds an existing book in the pile and renames it.
	* 
	* @param oldName This is the name of the book that will be replaced.
	* @param newName This is the name that will replace the name of the old book.
	* @return true if the book was successfully renamed.
	* @return false if the book was not able to be renamed.
	* @pre oldName must be in the pile of books and not be empty string.
	**/
	bool renameBook(string oldName, string newName);

	/**
	* bookCount returns the number of books in the pile.
	* 
	* @return the number of books in the pile.
	* @pre There must be at least 1 book in the pile.
	**/
	int bookCount();

	/**
	* clear removes all the books from the pile.
	* 
	* @pre There must be at least 1 book in the pile.
	**/
	void clear();
	
};



#endif 

