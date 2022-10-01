#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "datastore.h"


class MyDataStore: public DataStore {
    public:
        MyDataStore(); 
        ~MyDataStore();
        void addProduct(Product* p); 
        void addUser(User* u); 
        void viewCart(std::string user); 
        void addToCart(std::string user, Product*); 
        void buyCart(std::string user); 
        std::vector<Product*> search(std::vector<std::string>& terms, int type); 
        void dump(std::ostream& ofile); 
    private:
        std::vector<Product*> matches; 
        std::vector<Product*> products; 
        std::vector<User*> user; 
        std::map<std::string, std::vector<Product*>> userCart; 
        std::map<std::string, std::set<Product*>> keyword; 
        std::map<std::string, User*> users; 
};

struct ProdNameSort {
    bool operator()(Product* p1, Product* p2) {
        return (p1->getName() < p2->getName());
    }
};

#endif