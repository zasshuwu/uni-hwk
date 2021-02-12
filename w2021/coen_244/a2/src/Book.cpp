#include "Book.h"

// constructor, destructor

Book::Book(/* args */) 
{
    
}

Book::~Book() 
{
    
}

// publisher info

string Book::GetPublisher() const
{
    return this->publisher;
}

void Book::SetPublisher(string publisher) 
{
    this->publisher = publisher;
}

// number of pages

int Book::GetNumberOfPages() const
{
    return this->number_of_pages;
}

void Book::SetNumberOfPages(int number_of_pages) 
{
    this->number_of_pages = number_of_pages;
}

// print book information

void Book::PrintBookInfo() const
{
    cout << "Unique Identifier: " << GetUID() << endl;
    cout << "Title            : " << GetTitle() << endl;
    cout << "Author           : " << GetAuthor() << endl;
    cout << "Number of pages  : " << GetNumberOfPages() << endl;
    cout << "Published year   : " << GetPubYear() << endl;
    cout << "Published by     : " << GetPublisher() << endl;
    cout << endl;
}