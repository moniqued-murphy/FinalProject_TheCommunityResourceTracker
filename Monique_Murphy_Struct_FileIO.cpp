//@author Monique Murphy
//@author Aaron South
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Item
{
    string name;
    int quantity;
};

// Function 1: findItem - to find the index of an item in the inventory
int findItem(vector<Item> inventory, string itemName)
{
    for (int i = 0; i <inventory.size(); i++)
    {
        // compare item to what the user is searching for
        if (inventory[i].name == itemName)
        {
            return i; // return the position of the item in the vector
        }
    }
    return -1; // return -1 if the item is not found
}

// Function 2: addItem - to add a new item and its quantity to the inventory
void addItem(vector<Item>& inventory, string itemName, int quantity)
{
   int index = findItem(inventory, itemName);

   if (index == -1)
   {
    Item newItem;
    newItem.name = itemName;
    newItem.quantity = quantity;
    // item is not found, add to the inventory
    inventory.push_back(newItem);
   } 
   else 
   {
    // item is found, update the quantity
   inventory[index].quantity += quantity;
   }
}

// Function 3: distributeItem - to distribute an item and update the quantity
void distributeItem(vector<Item>& inventory, string itemName, int quantity)
{
    int index = findItem(inventory, itemName);

    if (index == -1)
    {
        cout << "Item not found in inventory." << endl;
    }
    else
    {
        if (inventory[index].quantity < quantity)
        {
            cout << "Not enough stock" << endl;
        } 
        else {
            inventory[index].quantity -= quantity;
            cout << "Item distributed!" << endl;
        }
    }
}
// Function 4: displayInventory - to display the current inventory of items and quantities
void displayInventory(vector<Item> inventory)
{
    cout << "Current Inventory:" << endl;
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i].name << ": " << inventory[i].quantity << endl;
    }
}
// Function 5: saveInventory - to save the inventory to a file
void saveInventory(vector<Item> inventory)
{
    // Open a file for writing
    ofstream outFile;
    outFile.open("inventory.txt");

    // Check if the file was opened successfully
    if (!outFile)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Write the inventory to the file
    for (int i = 0; i < inventory.size(); i++)
    {
        outFile << inventory[i].name << " " << inventory[i].quantity << endl;
    }
    // Close the file
    outFile.close();
}
// Function 6: loadInventory - to load the inventory from a file
void loadInventory(vector<Item>& inventory)
{
    // Open a file for reading
    ifstream inFile;
    inFile.open("inventory.txt");

    // Check if the file was opened successfully
    if (!inFile)
    {
        cout << "Error opening file for reading." << endl;
        return;
    }

    // Read the inventory from the file
    string itemName;
    int quantity;
    while (inFile >> itemName >> quantity)
    {
        Item newItem;
        newItem.name = itemName;
        newItem.quantity = quantity;
        inventory.push_back(newItem);
    }
    // Close the file
    inFile.close();
} 

int main()
{
    
    // Initialize vector
   vector<Item> inventory;
    // Load inventory from file
    loadInventory(inventory);

    int choice;

    // 2. Start a menu loop using while
    while (true) 
    {
        // Display the menu options 
        cout << "1. Add Item" << endl;
        cout << "2. Distribute Item" << endl;
        cout << "3. Display Inventory" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // 3. Use switch or if/else to handle user choices
        if (choice == 1)
        {
            string itemName;
            int quantity;
            cout << "Enter item name: ";
            cin >> itemName;
            cout << "Enter quantity: ";
            cin >> quantity;
            addItem(inventory, itemName, quantity);
        }
        else if (choice == 2)
        {
            string itemName;
            int quantity;
            cout << "Enter Item name: ";
            cin >> itemName;
            cout << "Enter quantity: ";
            cin >> quantity;
            distributeItem(inventory, itemName, quantity);
        }
        else if (choice == 3)
        {
            displayInventory(inventory);
        }
        else if (choice == 4)
        {
            // Save inventory to file before exiting
            saveInventory(inventory);
            // exit the loop
            break; 
        }
    }  
}