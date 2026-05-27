//@author Monique Murphy
//@author Aaron South
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Funtion 1: findItem - to find the index of an item in the names vector
int findItem(vector<string> names, string itemName)
{
    for (int i = 0; i <names.size(); i++)
    {
        // compare item to what the user is searching for
        if (names[i] == itemName)
        {
            return i; // return the position of the item in the vector
        }
    }
    return -1; // return -1 if the item is not found
}

// Fruntion 2: addItem - to add a new item and its quantity to the vectors
void addItem(vector<string>& names, vector<int>& quantities, string itemName, int quantity)
{
   int index = findItem(names, itemName);

   if (index == -1)
   {
    // item is not found, add to the vectors
    names.push_back(itemName);
    quantities.push_back(quantity);
   } else 
   {
    // item is found, update the quantity
    quantities[index] += quantity;
   }
}

// Function 3: distributeItem - to distribute an item and update the quantity
void distributeItem(vector<string>& names, vector<int>& quantities, string itemName, int quantity)
{
    int index = findItem(names, itemName);

    if (index == -1)
    {
        cout << "Item not found in inventory." << endl;
    }
    else
    {
        if (quantities[index] < quantity)
        {
            cout << "Not enough stock" << endl;
        } else {
            quantities[index] -= quantity;
            cout << "Item disributed!" << endl;
        }
    }
}
// Function 4: displayInventory - to display the current inventory of items and quantities
void displayInventory(vector<string> names, vector<int> quantities)
{
    cout << "Current Inventory:" << endl;
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << ": " << quantities[i] << endl;
    }
}
int main()
{
    
    // 1. Initialize vectors
    vector<string> names; // Vector to store names
    vector<int> quantities; // Vector to store quantities

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
            addItem(names, quantities, itemName, quantity);
        }
        else if (choice == 2)
        {
            string itemName;
            int quantity;
            cout << "Enter Item name: ";
            cin >> itemName;
            cout << "Enter quantity: ";
            cin >> quantity;
            distributeItem(names, quantities, itemName, quantity);
        }
        else if (choice == 3)
        {
            displayInventory(names, quantities);
        }
        else if (choice == 4)
        {
            // exit the loop
            break; 
        }
    }  
}