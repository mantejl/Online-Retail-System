#include "clothing.h"
#include <sstream>
#include <iomanip>
#include <set>
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand) : 
    Product("clothing", name, price, qty), 
    size_(size), 
    brand_(brand)
{

}

Clothing::~Clothing() {

}

set<std::string> Clothing::keywords() const {
    set<string> name = parseStringToWords(name_);
    set<string> brand = parseStringToWords(brand_); 
    set<string> clothingKeywords = setUnion(name,brand); 
    return clothingKeywords; 
}

std::string Clothing::displayString() const {
    string clothingDisplay = ""; 
    clothingDisplay = clothingDisplay + name_ + "\n"; 
    clothingDisplay = clothingDisplay + "Size: " + size_ + " Brand: " + brand_ + "\n"; 
    string price = to_string(getPrice()); 
    string finalPrice = price.substr(0,5);  
    clothingDisplay = clothingDisplay + finalPrice + " " + to_string(getQty()) + " left."; 
    return clothingDisplay;
}

void Clothing::dump(std::ostream& os) const {
    Product::dump(os); 
    os << size_ << "\n" << brand_ << endl; 
}