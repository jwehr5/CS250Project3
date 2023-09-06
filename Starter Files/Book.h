#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
   std::string title; // The book title
   Book* next; // Pointer to next book
   
public:
   Book();
   Book(const std::string& theTitle);
   Book(const std::string& theTitle, Book* nextBookPtr);
   void setTitle(const std::string& theTitle);
   void setNext(Book* nextBookPtr);
   std::string getTitle() const ;
   Book* getNext() const ;
}; // end Book

#endif