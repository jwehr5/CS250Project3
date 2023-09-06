#include "Book.h"


Book::Book() : next(nullptr)
{
} // end default constructor


Book::Book(const std::string& theTitle) : title(theTitle), next(nullptr)
{
} // end constructor


Book::Book(const std::string& theTitle, Book* nextBookPtr) :
                title(theTitle), next(nextBookPtr)
{
} // end constructor


void Book::setTitle(const std::string& theTitle)
{
   title = theTitle;
} // end setItem


void Book::setNext(Book* nextBookPtr)
{
   next = nextBookPtr;
} // end setNext


std::string Book::getTitle() const
{
   return title;
} // end getItem


Book* Book::getNext() const
{
   return next;
} // end getNext
