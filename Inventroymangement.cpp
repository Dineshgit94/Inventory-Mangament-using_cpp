#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

class seller
{
    string username;
    string password;

public:
    seller(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    string getuserName()
    {
        return username;
    }

    string getpassword()
    {
        return password;
    }
};

class buyer
{
    string username;
    string password;

public:
    buyer(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    string getuserName()
    {
        return username;
    }

    string getpassword()
    {
        return password;
    }
};

class inventory
{
public:
    string Productname;
    int Quantity;
    int Price;
    int Id;

public:
    inventory(string Productname, int Quantity, int Price, int Id)
    {
        this->Productname = Productname;
        this->Quantity = Quantity;
        this->Price = Price;
        this->Id = Id;
    }
};

class InventoryManagementSystem
{
public:
    void start()
    {
        while (true)
        {
            cout << "\t\t\t---------------------------------------------INVENTORY MANAGEMENT------------------------------------------------------------" << endl;
            cout << "\t\t\t-----------------Profile services----------" << endl;
            cout << "\t\t\t-----------------Inventory services--------" << endl;
            cout << "\t\t\t-----------------Order services------------" << endl;
            cout << "\t\t\t---------------------------------------------INVENTORY MANAGEMENT--------------------------------------------------------------" << endl;
            cout << "\t\t\tEnter your Choice: ";
            int choice = getvalidatedinput();
            if (choice == 1)
            {
                profileServices();
            }
            else if (choice == 2)
            {
                inventoryServices();
            }
            else if (choice == 3)
            {
                orderServices();
            }
            else
            {
                cout << "\t\t\tInvalid choice. Exiting." << endl;
                break;
            }
        }
    }

private:
    vector<seller> sell;
    vector<buyer> buy;
    vector<inventory> inv;
    vector<inventory> cart;
    vector<inventory> item;
    int nextid = 1;

    void profileServices()
    {
        cout << "\t\t\t---------------------------------------INVENTORY MANAGEMENT----------------------------------------------" << endl;
        cout << "\t\t\t 1. SELLER" << endl;
        cout << "\t\t\t 2. BUYER" << endl;
        cout << "\t\t\tEnter your Choice: ";
        int choice = getvalidatedinput();
        if (choice == 1)
        {
            handleSeller();
        }
        else if (choice == 2)
        {
            handleBuyer();
        }
        else
        {
            cout << "\t\t\tInvalid choice." << endl;
        }
    }

    void handleSeller()
    {
        cout << "\t\t\t------------------------------------------SELLER CREDENTIALS--------------------------------------------" << endl;
        cout << "\t\t\t 1. Register" << endl;
        cout << "\t\t\t 2. Login" << endl;
        cout << "\t\t\tEnter your Choice: ";
        int choice=getvalidatedinput();
        if (choice == 1)
        {
            registerseller();
        }
        else if (choice == 2)
        {
            if (loginseller())
            {
                inventoryServices();
            }
        }
        else
        {
            cout << "\t\t\tInvalid choice." << endl;
        }
    }

    void handleBuyer()
    {
        cout << "\t\t\t-----------------------------------------BUYER CREDENTIALS----------------------------------------------" << endl;
        cout << "\t\t\t 1. Register" << endl;
        cout << "\t\t\t 2. Login" << endl;
        cout << "\t\t\tEnter your Choice: ";
        int choice = getvalidatedinput();
        if (choice == 1)
        {
            registerbuyer();
        }
        else if (choice == 2)
        {
            if (loginbuyer())
            {
                orderServices();
            }
        }
        else
        {
            cout << "\t\t\tInvalid choice." << endl;
        }
    }

    void registerseller()
    {
        string username, password;
        cout << "\t\t\tEnter UserName: ";
        cin >> username;
        cout << "\t\t\tEnter Password: ";
        cin >> password;
        sell.push_back(seller(username, password));
        cout << "\n\t\t\tUser Registered Successfully\n";
    }

    void registerbuyer()
    {
        string username, password;
        cout << "\t\t\tEnter UserName: ";
        cin >> username;
        cout << "\t\t\tEnter Password: ";
        cin >> password;
        buy.push_back(buyer(username, password));
        cout << "\n\t\t\tUser Registered Successfully\n";
    }

    bool loginseller()
    {
        string username, password;
        cout << "\t\t\tEnter UserName: ";
        cin >> username;
        cout << "\t\t\tEnter Password: ";
        cin >> password;
        int valid = authenticateseller(username, password);
        if (valid >= 0)
        {
            cout << "\n\t\t\tLogged in Successfully\n";
            return true;
        }
        else
        {
            cout << "\n\t\t\tInvalid credentials\n";
            return false;
        }
    }

    bool loginbuyer()
    {
        string username, password;
        cout << "\t\t\tEnter UserName: ";
        cin >> username;
        cout << "\t\t\tEnter Password: ";
        cin >> password;
        int valid = authenticatebuyer(username, password);
        if (valid >= 0)
        {
            cout << "\n\t\t\tLogged in Successfully\n";
            return true;
        }
        else
        {
            cout << "\n\t\t\tInvalid credentials\n";
            return false;
        }
    }

    int authenticateseller(string username, string password)
    {
        for (int i = 0; i < sell.size(); i++)
        {
            if (sell[i].getuserName() == username && sell[i].getpassword() == password)
            {
                return i;
            }
        }
        return -1;
    }

    int authenticatebuyer(string username, string password)
    {
        for (int i = 0; i < buy.size(); i++)
        {
            if (buy[i].getuserName() == username && buy[i].getpassword() == password)
            {
                return i;
            }
        }
        return -1;
    }

    void inventoryServices()
    {
        if(loginseller())
        {
        cout << "\t\t\t---------------------------------------- INVENTORY SERVICES FOR SELLER -----------------------------------" << endl;
        cout << "\t\t\t 1. Add Items" << endl;
        cout << "\t\t\t 2. Update Items" << endl;
        cout << "\t\t\t 3. Delete Items" << endl;
        cout << "\t\t\t 4. View Inventory" << endl;
        cout << "\t\t\tEnter your Choice: ";
        int choice =getvalidatedinput();
        if (choice == 1)
        {
            additems();
        }
        else if (choice == 2)
        {
            updateitems();
        }
        else if (choice == 3)
        {
            deleteitems();
        }
        else if (choice == 4)
        {
            viewinventory();
        }
        else
        {
            cout << "\t\t\tInvalid choice." << endl;
        }
    }
    else
    cout<<"\t\t\t INVALID CREDENTIALS"<<endl;
    }

    void additems()
    {
        int price, quantity;
        string product;
        cout << "\t\t\tEnter the Product Name: ";
        cin >> product;
        cout << "\t\t\tEnter the Quantity: ";
        quantity =getvalidatedinput();
        cout << "\t\t\tEnter the Price: ";
        price =getvalidatedinput();
        inv.push_back(inventory(product, quantity, price, nextid++));
        char ch;
        cout << "\t\t\tAdd more Items (Y/N): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            additems();
        }
    }

    void viewinventory() {
    if (inv.empty()) {
        cout << "\t\t\tInventory is Empty" << endl;
        return;
    }
    cout << "\t\t\t-----------------ITEMS PRESENT IN INVENTORY-------------------" << endl;
    cout << left << setw(20) << "Product ID" << setw(20) << "Product Name" << setw(20) << "Quantity" << setw(20) << "Price" << endl;
    for (int i = 0; i < inv.size(); i++) {
        cout << left << setw(20) << inv[i].Id;
        cout << left << setw(20) << inv[i].Productname;
        cout << left << setw(20) << inv[i].Quantity;
        cout << left << setw(20) << inv[i].Price << endl;
    }
}


    void deleteitems()
    {
        int id;
        cout << "\t\t\tEnter Id Number to Delete: ";
      id =getvalidatedinput();
        for (int i = 0; i < inv.size(); i++)
        {
            if (inv[i].Id == id)
            {
                inv.erase(inv.begin() + i);
                cout << "\t\t\tItem with ID " << id << " Deleted\t\t\t";
                return;
            }
        }
        cout << "\t\t\tEnter Valid ID";
    }

    void updateitems()
    {
       int price,quantity,id;
      
       cout<<"\t\t\t Choose which need to be changed"<<endl;
       cout<<"\t\t\t 1. Price"<<endl;
       cout<<"\t\t\t 2. Quantity"<<endl;
       cout<<"\t\t\t 3. Both"<<endl;
       int choice = getvalidatedinput();
       if(choice == 1)
       {
         cout<<"\t\t\t Enter the ID of the Item to be Updated"<<endl;
          id = getvalidatedinput();
             cout<<"\t\t\t Enter the New Price: "<<endl;
            price=getvalidatedinput();
          for(int i = 0;i<inv.size();i++)
       {
            if(inv[i].Id==id)
            {
                inv[i].Price=price;
                return;
            }
       }
       }
       else if(choice == 2)
       {
            cout<<"\t\t\t Enter the ID of the Item to be Updated: ";
          id = getvalidatedinput();
             cout<<"\t\t\t Enter the New Quantity: ";  
            quantity=getvalidatedinput();
          for(int i = 0;i<inv.size();i++)
       {
            if(inv[i].Id==id)
            {
                inv[i].Quantity=quantity;
                return;
            }
       } 
       }
       else if (choice == 3)

       {
         cout<<"\t\t\t Enter the ID of the Item to be Updated: ";
          id = getvalidatedinput();
          cout<<"\t\t\t Enter the New Price: ";
              price=getvalidatedinput();
           cout<<"\t\t\t Enter the New Quantity: ";   
       quantity=getvalidatedinput();
               
          for(int i = 0;i<inv.size();i++)
       {
            if(inv[i].Id==id)
            {
                inv[i].Price=price;
                inv[i].Quantity=quantity;
                return;
            }
       }
     }
     else{
        cout<<"\t\t\t Enter a Valid Choice"<<endl;
     }
 }

    void orderServices()
    {   if(loginbuyer())
    {
        cout << "\t\t\t--------------------- WELCOME TO ORDER SERVICES ---------------------------" << endl;
        cout << "\t\t\t 1. VIEW INVENTORY" << endl;
        cout << "\t\t\t 2. ADD TO CART" << endl;
        cout << "\t\t\t 3. VIEW CART" << endl;
        cout << "\t\t\t 4. EMPTY CART" << endl;
        cout << "\t\t\t 5. BUY ITEMS" << endl;
        cout << "\t\t\tEnter Your Choice: ";
        int choice =getvalidatedinput();
        if (choice == 1)
        {
            viewinventory();
        }
        else if (choice == 2)
        {
            Addtocart();
        }
        else if (choice == 3)
        {
            viewcart();
        }
        else if (choice == 4)
        {
            emptycart();
        }
        else if (choice == 5)
        {
            buyitems();
        }
        else
        {
            cout << "\t\t\tEnter a Valid choice";
        }
    }
    else
    cout<<"\t\t\t INVALID CREDENTIALS"<<endl;
    }

    void Addtocart()
    {
        int id, quantity;
        cout << "\t\t\tEnter the ID of the Product: ";
       id =getvalidatedinput();
        cout << "\t\t\tEnter the Required Quantity: ";
       quantity =getvalidatedinput();
        for (int i = 0; i < inv.size(); i++)
        {
            if (inv[i].Id == id)
            {
                if (inv[i].Quantity >= quantity)
                {
                    cart.push_back(inventory(inv[i].Productname, quantity, inv[i].Price, id));
                   
                    cout << "\t\t\tItems added to cart successfully" << endl;
                }
                else
                {
                    cout << "\t\t\tThe selected item is out of stock" << endl;
                }
                return;
            }
        }
        cout << "\t\t\tSelect Valid ID" << endl;

        char ch;
        cout << "\t\t\tAdd more Items (Y/N): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            Addtocart();
        }
    }

    void viewcart()
    {
        if (cart.empty())
        {
            cout << "\t\t\tCurrently You Don't Have any items in cart" << endl;
            return;
        }
        cout << "\t\t\t-----------------ITEMS PRESENT IN CART-------------------" << endl;
        cout <<left<< setw(20) << "Product ID" << setw(20) << "Product Name" << setw(20) << "Quantity" << setw(20) << "Price" << endl;
        for (int i = 0; i < cart.size(); i++)
        {
            cout<<left  <<setw(20) << cart[i].Id;
            cout<<left<<setw(20) << cart[i].Productname;
            cout<<left <<setw(20) << cart[i].Quantity;
            cout <<left<<setw(20) << cart[i].Price << endl;
        }
    }

    void emptycart()
    {
        cart.clear();
        cout << "\t\t\tCart is now empty" << endl;
    }

    void buyitems()
{
    int id, quantity;
    cout << "\t\t\tEnter the ID of the Product: ";
     id =getvalidatedinput();
    cout << "\t\t\tEnter the Required Quantity: ";
   quantity =getvalidatedinput();

    bool itemFound = false;
    for (int i = 0; i < inv.size(); i++)
    {
        if (inv[i].Id == id)
        {
            itemFound = true;
            if (inv[i].Quantity >= quantity)
            {
                int price = quantity * inv[i].Price;
                item.push_back(inventory(inv[i].Productname, quantity, price, id));
                inv[i].Quantity -= quantity;

                cout << "\t\t\tHead to the Payment" << endl;
                cout << "\t\t\tPAYMENT PROCESSING" << endl;
                cout << "\t\t\tPAYMENT DONE" << endl;
                dispbill();
            }
            else
            {
                cout << "\t\t\tThe selected item is out of stock" << endl;
            }
            break;
        }
    }

    if (!itemFound)
    {
        cout << "\t\t\tSelect Valid ID" << endl;
    }

    char ch;
    cout << "\t\t\tAdd more Items (Y/N): ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        buyitems();
    }
}

void dispbill()
{
    if (item.empty())
    {
        cout << "\t\t\tYou Don't Have any items that have been Bought" << endl;
        return;
    }
    cout << "\t\t\t-----------------BILL-------------------" << endl;
    cout << left << setw(20) << "Product ID" << setw(20) << "Product Name" << setw(20) << "Quantity" << setw(20) << "Price" << endl;
    for (int i = 0; i < item.size(); i++)
    {
        cout <<left << setw(20) << item[i].Id;
        cout <<left << setw(20) << item[i].Productname;
        cout <<left << setw(20) << item[i].Quantity;
        cout <<left << setw(20) << item[i].Price << endl;
    }
    cout << "\t\t\tThank you for your purchase!" << endl; 
}
int getvalidatedinput() {
        int input;
        while (true) {
            cin >> input;
            if (cin.fail()) {
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "\t\t\tInvalid input. Please enter a number: ";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                return input;
            }
        }
    }
};

int main()
{
    InventoryManagementSystem inventory;
    inventory.start();
    return 0;
}
