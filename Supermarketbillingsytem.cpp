#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() {
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t________________________________________________________\n";
    cout << "\t\t\t\t                                                        \n";
    cout << "\t\t\t\t  Supermarket Main Menu                             \n";
    cout << "________________________________________________________________\n";
    cout << "\t\t\t\t                                                        \n";
    cout << "\t\t\t\t| 1) Administrator   |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\t\t\t\t| 2) Buyer           |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\t\t\t\t| 3) Exit            |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\n\t\t\t\t|                    |\n";
    cout << "\n\t\t\t Please Select ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email  \n";
        cin >> email;
        cout << "\t\t\t Password     \n";
        cin >> password;

        if (email == "shrey@email.com" && password == "shrey@123") {
            administrator();
        }
        else {
            cout << "Invalid email/password";
        }
        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "Please select from the given options";
    }

    goto m;
}

void shopping::administrator() {
m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\n\n\t\t\t_____1) Add the product________|";
    cout << "\n\n\n\t\t\t|                              |";
    cout << "\n\n\n\t\t\t_____2) Modify the product_____|";
    cout << "\n\n\n\t\t\t|                              |";
    cout << "\n\n\n\t\t\t_____3) Delete the product_____|";
    cout << "\n\n\n\t\t\t|                              |";
    cout << "\n\n\n\t\t\t_____4) Back to main menu______|";

    cout << "\n\n\t Please enter your choice ";
    cin >> choice;

    switch (choice) {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice";
    }

    goto m;
}

void shopping::buyer() {
m:
    int choice;
    cout << "\t\t\t 1) Buyer      \n";
    cout << "                     \n";
    cout << "\t\t\t1) Buy product \n";
    cout << "                     \n";
    cout << "\t\t\t2) Go back     \n";
    cout << "\t\t\t Enter your choice :";
    cin >> choice;

    switch (choice) {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid choice";
    }

    goto m;
}

void shopping::add() {
m:
    fstream data;
    int c;
    int token = 0;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout << "\n\n Name of the product ";
    cin >> pname;
    cout << "\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Discount on product";
    cin >> dis;

    data.open("database.txt", ios::in | ios::app);

    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else {
        while (data >> c >> pname >> price >> dis) {
            if (c == pcode) {
                token++;
            }
        }
        data.close();
    }

    if (token == 1)
        goto m;
    else {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }

    cout << "\n\n\t\t Record inserted ";
}

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);

        while (data >> c >> pname >> price >> dis) {
            if (pkey == c) {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product :";
                cin >> pname;
                cout << "\n\t\t Price :";
                cin >> p;
                cout << "\n\t\t Discount: ";
                cin >> d;
                data1 << " " << c << " " << pname << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited ";
                token++;
            }
            else {
                data1 << " " << c << " " << pname << " " << price << " " << dis << "\n";
            }
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File doesn't exist ";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);
        while (data >>pcode>> pname >> price >> dis) {
            if (pcode == pkey) {
                cout << "\n\nt Product deleted successfully";
                token++;
            }
            else {
                data1 << " " <<pcode<< " " << pname << " " << price << " " << dis << "\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|______________________________________________________\n";
    cout << "ProNo\t\tName\tPrice\n";
    cout << "\n\n_______________________________________________________\n";
    while (data >> pcode >> pname >> price >> dis) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
    }
    data.close();
}

void shopping::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty Database";
    }
    else {
        data.close();
        list();
        cout << "\n______________________________________________\n";
        cout << "\n                                              \n";
        cout << "\n             Please Place the order           \n";
        cout << "\n______________________________________________\n";
        do {
        m:
            cout << "\n\nEnter Product Code: ";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity :";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If yes, then press 'y', else press 'n'";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t______________________________RECEIPT__________________________\n";
        cout << "\nProduct No\t product Name\t product quantity\tprice\tAmount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            while (data >> pcode >> pname >> price >> dis) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    total += amount;
                    cout << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\n";
                }
            }
            data.close();
        }
    }
    cout << "\n\n__________________________________________________";
    cout << "\n Total Amount : " << total;
}

int main() {
    shopping s;
    s.menu();
    return 0;
}
