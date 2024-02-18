#include "product_data.h"

// Insert a new product
void insertProduct(vector<Product>& products, const Product& newProduct) {
    products.push_back(newProduct);
    cout<<"insert success"<<endl;
}

// Update existing product information
void updateProduct(vector<Product>& products, int id, const Product& updatedProduct) {
    for (auto& product : products) {
        if (product.id == id) {
            product = updatedProduct;
            break;
        }
    }
    cout<<"update success"<<endl;
}

// Delete the product
struct ProductIdMatcher {
    int id;
    ProductIdMatcher(int id) : id(id) {}
    bool operator()(const Product& product) const {
        return product.id == id;
    }
};
void deleteProduct(vector<Product>& products, int id) {
    products.erase(remove_if(products.begin(), products.end(), ProductIdMatcher(id)), products.end());
    cout<<"del success"<<endl;
}

// Find products based on ID
Product* findProductById(const vector<Product>& products, int id) {
    for (auto& product : products) {
        if (product.id == id) {
            Product* foundProduct = new Product(); // Create a new Product object using dynamic memory allocation
            *foundProduct = product; // Copy the found product information into a new object
            return foundProduct;
        }
    }
    return nullptr;
}

// Bubble Sort (in ascending order of price)
void bubbleSort(vector<Product>& products) {
    for (int i = 0; i < products.size() - 1; ++i) {
        for (int j = 0; j < products.size() - i - 1; ++j) {
            if (products[j].price > products[j + 1].price) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}


int main() {
    // Load product data
    vector<Product> products;
    loadProductData("product_data.txt", products);

    // Insert a new product
    Product newProduct;
    newProduct.id = 10001;
    newProduct.name = "Test Product";
    newProduct.price = 99.99;
    newProduct.category = "Test";
    insertProduct(products, newProduct);

    // Update existing product information
    int productIdToUpdate = 57353;
    Product updatedProduct;
    updatedProduct.id = productIdToUpdate;
    updatedProduct.name = "Updated Product";
    updatedProduct.price = 199.99;
    updatedProduct.category = "Updated";
    updateProduct(products, productIdToUpdate, updatedProduct);

    // Delete the product
    int productIdToDelete = 40374;
    deleteProduct(products, productIdToDelete);

    // Find products based on ID
    int productIdToFind = 34863;
    Product* foundProduct = findProductById(products, productIdToFind);
    if (foundProduct != nullptr) {
        cout << "Product found: " << foundProduct->name << endl;
    } else {
        cout << "Product not found." << endl;
    }

    // Test the time of bubbling sorting
    auto startBubbleSort = high_resolution_clock::now();
    bubbleSort(products);
    auto endBubbleSort = high_resolution_clock::now();
    auto durationBubbleSort = duration_cast<microseconds>(endBubbleSort - startBubbleSort);
    cout << "Bubble Sort Time: " << durationBubbleSort.count() << " microseconds" << endl;

    return 0;
}

