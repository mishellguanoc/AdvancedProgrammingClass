# Scenario
You have been hired by a small store to develop a simple inventory management system. The store keeps track of its products, processes customer orders, and maintains a history of returned items. Your task is to implement the system using C++ containers.

# Task 1: Managing Products with std::map
Use std::map<std::string, int> to store products in the inventory. The key is the product name, and the value is the quantity available.
Implement functions to:
Add a new product to the inventory.
Update the quantity of an existing product.
Display all available products.
# Task 2: Tracking Unique Products with std::set
Use std::set<std::string> to store unique product categories.
Implement functions to:
Add a new category.
Display all categories.
# Task 3: Processing Orders with std::queue
Use std::queue<std::string> to manage customer orders (FIFO processing).
Implement functions to:
Add a new order.
Process an order (remove from the queue).
# Task 4: Handling Restocks with std::stack
Use std::stack<std::pair<std::string, int>> to manage restocked items (LIFO processing).
Implement functions to:
Add a restock batch.
Process a restock batch.
# Task 5: Storing Customer Purchases with std::vector
Use std::vector<std::string> to keep track of items a customer purchases.
Implement functions to:
Add items to a customer’s cart.
Display the items in the cart.