#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h> 
#include <vector>
#include "product.h"

class Database {
private:
    sqlite3* db;
public:
    Database();
    ~Database();
    void open(const std::string& filename = "inventory.db");
    void close();
    std::vector<Product> getProducts();
    void addProduct(const Product& product);
    void editProduct(const Product& product);
    void deleteProduct(const Product& product);
};

#endif 
