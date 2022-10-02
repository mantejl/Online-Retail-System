#include <sstream>
#include <iomanip>
#include <set>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string name, double price, int qty, const std::string ISBN, const std::string author) :
    Product("book", name, price, qty), 
    isbn_(ISBN),
    author_(author)
{

}

Book::~Book() {

}

set<std::string> Book::keywords() const {
    set<string> name = parseStringToWords(name_);
    set<string> author = parseStringToWords(author_); 
    set<string> bookKeywords = setUnion(name,author);
    set<string>::iterator itr; 
    bookKeywords.insert(isbn_); 
    return bookKeywords; 
}

std::string Book::displayString() const {
    string bookDisplay = ""; 
    bookDisplay = bookDisplay + name_ + "\n"; 
    bookDisplay = bookDisplay + "Author: " + author_ + " ISBN: " + isbn_ + "\n"; 
    string price = to_string(getPrice()); 
    string finalPrice = price.substr(0,5); 
    bookDisplay = bookDisplay + finalPrice + " " + to_string(getQty()) + " left."; 
    return bookDisplay; 
}

void Book::dump(std::ostream& os) const {
    Product::dump(os); 
    os << isbn_ << "\n" << author_ << endl; 
}