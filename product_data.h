#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <chrono>
using namespace std;
using namespace std::chrono; // Use the time namespace
class Product {
    public:
        int id;
        string name;
        double price;
        string category;
};
// The following two functions use templates in C++

template<typename Container>
void loadProductData(const string& filename, Container& products) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, name, priceStr, category;
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, priceStr, ',');
            getline(ss, category, ',');

            Product product;
            product.id = stoi(idStr);
            product.name = name;
            product.price = stod(priceStr);
            product.category = category;

            products.push_back(product); // Insert the product into the tail of the container, which is the tail plugging method
        }
        file.close();
    }
}

