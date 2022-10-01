#include "mydatastore.h"
#include "user.h"
#include "util.h"
#include <iomanip>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

MyDataStore::MyDataStore() {}

MyDataStore::~MyDataStore() {
    // delete products and users 
    for (int i = 0; i < products.size(); i++) {
        delete products[i]; 
    }

    for (int i = 0; i < user.size(); i++) {
        delete user[i]; 
    }

}

void MyDataStore::addProduct(Product* p) {
    set<string> keys = p->keywords();
    set<string>::iterator itr;
    set<Product*> prod;
    for (itr = keys.begin(); itr != keys.end(); itr++) {
        if (keyword.find(*itr) == keyword.end()) {
            keyword.insert(make_pair(*itr, prod));
        }
        keyword[*itr].insert(p);
    }
    products.push_back(p);
}

void MyDataStore::addUser(User* u) { 
    users.insert(make_pair(u->getName(), u)); 
    user.push_back(u); 
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    set<Product*> keys;
    vector<string>::iterator it;
    for (it = terms.begin(); it != terms.end(); ++it) {
        if (keyword.find(*it) != keyword.end()) {
            if (type == 0) {
                keys = setIntersection(keys,keyword[*it]);
            } else if (type == 1) {
                keys = setUnion(keys,keyword[*it]);
            }
        }
    }

    vector<Product*> finished(keys.begin(),keys.end()); 
    sort(finished.begin(), finished.end(), ProdNameSort());
    matches = finished; 
    return matches;
}

void MyDataStore::addToCart(string name, Product* p) {
    if (users.find(name) == users.end()) {
        cout << "Invalid request" << endl;
        return;
    }
    if (userCart.find(name) == userCart.end()) {
        vector<Product*> product;
        userCart.insert(make_pair(name, product));
    }
    userCart[name].push_back(p);
}

void MyDataStore::buyCart(string user) {
    vector<Product*>::iterator it;
    if (userCart.find(user) == userCart.end()) {
        cout << "Invalid username" << endl;
        return;
    }
    for (it = userCart[user].begin(); it != userCart[user].end(); ++it) {
        if ((users[user]->getBalance() > (*it)->getPrice()) && ((*it)->getQty() > 0)) {
            (*it)->subtractQty(1);
            users[user]->deductAmount((*it)->getPrice());
            userCart[user].erase(it);
        }
    }
}

string MyDataStore::viewCart(string user) {
    vector<Product*>::iterator it;
    string output = "";
    if (userCart.find(user) == userCart.end()) {
        return "Invalid username";
    }
    for (it = userCart[user].begin(); it != userCart[user].end(); ++it) {
        int i = 1;
        output = "Item " + to_string(i) + "\n";
        output = output + (*it)->displayString();
        i++;
    }
    return output;
}

void MyDataStore::dump(std::ostream& ofile) {}