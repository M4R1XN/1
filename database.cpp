#include "database.h"
#include <stdexcept>
#include "Product.h"

Database::Database() : db(nullptr) {}

Database::~Database() {
    close();
}

void Database::open(const std::string& filename) {
    if (db) {
        throw std::runtime_error("База даних уже відкрита");
    }

    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
        throw std::runtime_error("Не вдалося відкрити базу даних: " + std::string(sqlite3_errmsg(db)));
    }
}


void Database::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

std::vector<Product> Database::getProducts() {
    std::vector<Product> products;
    char* errorMessage = nullptr;

    const char* sql = "SELECT name, quantity, price FROM products ORDER BY name ASC";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        throw std::runtime_error("Не вдалося виконати запит до бази даних: " + std::string(sqlite3_errmsg(db)));
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int quantity = sqlite3_column_int(stmt, 1);
        double price = sqlite3_column_double(stmt, 2);
        products.emplace_back(name, quantity, price);
    }

    sqlite3_finalize(stmt);
    return products;
}

void Database::addProduct(const Product& product) {
    char* errorMessage = nullptr;

    const char* sql = "INSERT INTO products (name, quantity, price) VALUES (?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        throw std::runtime_error("Не вдалося виконати запит до бази даних: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, product.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, product.getQuantity());
    sqlite3_bind_double(stmt, 3, product.getPrice());

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        throw std::runtime_error("Не вдалося додати товар до бази даних: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
}

void Database::editProduct(const Product& product) {
    char* errorMessage = nullptr;
    const char* sql = "UPDATE products SET quantity=?, price=? WHERE name=?";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        throw std::runtime_error("Не вдалося виконати запит до бази даних: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, product.getQuantity());
    sqlite3_bind_double(stmt, 2, product.getPrice());
    sqlite3_bind_text(stmt, 3, product.getName().c_str(), -1, SQLITE_TRANSIENT);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        throw std::runtime_error("Не вдалося відредагувати товар у базі даних: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
}

void Database::deleteProduct(const Product& product) {
    char* errorMessage = nullptr;
    const char* sql = "DELETE FROM products WHERE name=?";
    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        throw std::runtime_error("Не вдалося виконати запит до бази даних: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, product.getName().c_str(), -1, SQLITE_TRANSIENT);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        throw std::runtime_error("Не вдалося видалити товар з бази даних: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
}