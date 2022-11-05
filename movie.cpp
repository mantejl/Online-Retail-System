#include "movie.h"
#include <sstream>
#include <iomanip>
#include <set>
#include "util.h"

using namespace std;

Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating) :
    Product("movie", name, price, qty), 
    genre_(genre),
    rating_(rating)
{

}

Movie::~Movie () {

}

set<std::string> Movie::keywords() const {
    set<string> movieKeywords = parseStringToWords(name_);
    movieKeywords.insert(convToLower(genre_)); 
    return movieKeywords; 
}

std::string Movie::displayString() const {
    string movieDisplay = ""; 
    movieDisplay = movieDisplay + name_ + "\n"; 
    movieDisplay = movieDisplay + "Genre: " + genre_ + " Rating: " + rating_ + "\n";
    string price = to_string(getPrice()); 
    string finalPrice = price.substr(0,5);  
    movieDisplay = movieDisplay + finalPrice + " " + to_string(getQty()) + " left."; 
    return movieDisplay; 
}

void Movie::dump(std::ostream& os) const {
    Product::dump(os); 
    os << genre_ << "\n" << rating_ << endl; 
}