#include <iostream> // all tasks
#include <map> // task 1
#include <set> // task 2
#include <queue> // task 3
#include <stack> // task 4
#include <vector> // task 5

/*TASK 1: Managing Products with: std::map*/


void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

void addingNewProduct(std::map<std::string, int> inventory){
    std::string newProduct;
    int productAmount;
    std::cout << "What product do you want to add? \n";
    std::cin >> newProduct;
    std::cout << "How many " <<newProduct<< " do you have? \n";
    std::cin >> productAmount;
    inventory[newProduct]= productAmount;

    std::cout << "Here you have the new inventory";
    displayInventory(inventory);
    return;

}



/*Task 2: Tracking Unique Products with std::set*/

void displayCategories(const std::set<std::string>& categories) {
    std::cout <<"Product Categories:\n";
    for (const auto& category : categories) {
        std::cout << "- "<< category << "\n";
    }
    std::cout << std:: endl;
}

void addingCategories(std::set<std::string>& productCategories){
    std::string category;
    std::cout << "Enter new category: ";
    std::cin >> category;
    productCategories.insert(category);
    displayCategories(productCategories);
}

/*Task 3: Processing Orders with std::queue */
void processOrders(std::queue<std::string>& orders){
    while(!orders.empty()){
        std::cout << "Processing " << orders.front() << std::endl;
        orders.pop();
    }
}
/*Task 4: Handling Restocks with std::stack*/
void processRestocks(std::stack<std::pair<std::string, int>>& restocks){
    while(!restocks.empty()){
        auto item = restocks.top();
        std::cout <<"Restockin " << item.second << " units of " << item.first <<std::endl;
        restocks.pop();
    }
}
/*Task 5: Storing Customer Purchases with std::vector */
void displayCart(const std::vector<std::string>& cart){
    std::cout << "Items in customer cart:\n";
    for (const auto& item : cart){
        std::cout << "- " << item << "\n";
    }
    std::cout << std::endl;
}

void addToCart(std::vector<std::string>& cart, const std::string& item) {
    cart.push_back(item);
}


int main() {
/*TASK 1*/
    std::map<std::string, int> inventory;
    addingNewProduct(inventory);

/*TASK 2*/
    std::set<std::string> productCategories;

    // Adding categories
    productCategories.insert("Electronics");
    productCategories.insert("Accessories");
    productCategories.insert("Peripherals");

    displayCategories(productCategories);
    addingCategories(productCategories);

/*TASK 3*/
    std::queue<std::string> orders;

    // Adding orders
    orders.push("Order#1: Laptop");
    orders.push("Order#2: Mouse");
    orders.push("Order#3: Keyboard");
    processOrders(orders);
/*TASK 4*/
    std::stack<std::pair<std::string, int>> restocks;

    // Adding restock batches
    restocks.push({"Mouse", 10});
    restocks.push({"Laptop", 2});
    restocks.push({"Keyboard", 5});

    processRestocks(restocks);
/*TASK 5*/
    std::vector<std::string> customerCart;

    // Adding items to cart
    addToCart(customerCart, "Laptop");
    addToCart(customerCart, "Mouse");
    addToCart(customerCart, "Keyboard");
    displayCart(customerCart);
    
    return 0;
}








