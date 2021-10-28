#include <iostream>

using namespace std;

struct shoppingcartType
{
  string itemName; //name of each item
  double price; //price of each item
  int qty; //quantity of each item
};

struct loginData
{
  shoppingcartType shoppingcart[99]; //inherits all data from shoppingcartType
  string un; //username
  string pass; //password
  double total; //total price in shopping cart
};

loginData user[5]; //array of users (max 5 users)
int account_index; //index to determine which acount to use throughout the program
int user_counter = 0; //user index

char more; //to determine if they want "more" items or not
char correct; //to make sure item input is correct
int counter = 0; //item index

void login_system()
{
  char login_choice;
  char account_choice = 'n';
  char new_account;
  char forgot_pass;
  string password_attempt;

  //header of login page
  cout << "Welcome to the Login page of GamaCart!" << endl;
  cout << "Are you new here? (Create an account) (y/n) ";
  cin >> login_choice; //determines if he/she has an account or not
  cout << endl;

  //creating a new login
  newLogin:
  while (account_choice == 'n')
  {
    cout << "Enter new username: ";
    cin >> user[user_counter].un;
    cout << "Enter new password: ";
    cin >> user[user_counter].pass;
    cout << endl << "Is that correct? (y/n) ";
    cin >> account_choice;
    if (account_choice == 'y')
    {
      continue;
    }
    else if (account_choice == 'n')
    {
      goto newLogin;
    }
    cout << "Want to make another account? (y/n) ";
    cin >> new_account;
    /* if new_account == y, then we execute the while loop again and increment user_counter to create new account
       if new_account == n, then we exit the while loop
    */
    if (new_account == 'y')
    {
      cout << endl;
      account_choice = 'n';
      user_counter++; //increments the user Struct index to add more users later on (max 5 users)
      if (user_counter > 5)
      {
        user_counter = 0; //resets index of user Struct because
      }
      continue;
    }
    else if (new_account == 'n')
    {
      continue;
    }
    cout << endl;
  }

  //to display all usernames and let users choose which one is their account
  accountChoice:
  for (int i = 1; i <= 5; i++)
  {
    cout << i << ". " << user[i-1].un << endl;
  }

  int attempts = 3; //sets the number of attempts
  cout << "Which one are you? ";
  cin >> account_index;
  account_index -= 1;

  //for loop to ask for password
  for (int i = 0; i < 4; i++)
  {
    /* when the attempts == 0
       then we ask to either forget password or to make a new acccount

       when the attempts are still > 0
       then we keep asking for password */
    if (attempts == 0)
    {
      cout << "Forgot Password? (y/n)";
      cin >> forgot_pass;
      if (forgot_pass == 'y')
      {
        cout << "Enter new password: ";
        cin >> user[account_index].pass;
        goto accountChoice;
      }
      else if (forgot_pass == 'n')
      {
        cout << "Go make a new account!";
        login_choice = 'y';
        goto newLogin;
      }
    }
    else if (attempts > 0)
    {
      cout << "What is your Password? (" << attempts << " attempts left) ";
      cin >> password_attempt;
      if (password_attempt == user[account_index].pass)
      {
        cout << endl << "Congrats! You have successfully logged in!" << endl << endl;
        break;
        }
      else
      {
        cout << endl;
      }
      attempts--;
    }
  }
}


void GamaCart_program()
{
  cout << more;
  more = 'y';

  while (more != 'n')
  {
    /* asks items to add into the shopping cart using a while loop
       if variable "more" == y, then we keep adding items
    */
    cout << endl << "What item would you like to add? ";
    cin >> user[account_index].shoppingcart[counter].itemName;
    cout << endl << "How much is the price of that item? ";
    cin >> user[account_index].shoppingcart[counter].price;
    cout << endl << "How many would you like? ";
    cin >> user[account_index].shoppingcart[counter].qty;
    cout << endl << "You have just ordered " << user[account_index].shoppingcart[counter].qty << " " << user[account_index].shoppingcart[counter].itemName << "(s) with price Rp "
    << user[account_index].shoppingcart[counter].price << endl;
    cout << "Are you sure that is the correct item? (y/n) ";
    cin >> correct; //to make sure the item input is correct


    if (correct == 'y' || correct == 'Y')
    {
      user[account_index].total += user[account_index].shoppingcart[counter].price * user[account_index].shoppingcart[counter].qty;
      cout << endl;
      cout << "Your total is Rp " << user[account_index].total;
      cout << endl;
      cout << "Would you like to add more items? (y/n) ";
      cin >> more;
      counter++;
    }
    else
    {
      cout << endl << "Please re-enter item! " << endl;
      continue;
    }
    continue;
  }
}

void display_list()
{
  cout << "This is " << user[account_index].un << "'s shopping cart:" << endl;

  for (int i = 0; i <= (counter - 1); i++)
    {
      cout << i + 1 << ". " << user[account_index].shoppingcart[i].itemName << "....." << user[account_index].shoppingcart[i].price << " x "
      << user[account_index].shoppingcart[i].qty << endl;
    }

  cin.get();
  cout << endl << "Total: " << user[account_index].total << endl << endl;
  cout << "Thank you for using GamaCart!" << endl << endl;
  cin.get();
}

void display_item_from_list()
{
  int index;
  cout << "Which item index would you like to display? ";
  cin >> index;
  cin.get();
  cout << endl << user[account_index].shoppingcart[index - 1].itemName << " is that item" << endl << endl;
  cin.get();
}

//driver code
int main()
{
  int choice; //to determine what subprogram to call

  login:
  login_system();

  start: // goto label
  cout << "Welcome to GamaCart! A program to help total your shopping cart :D" << endl << endl;
  cout << "Let's add items into your cart!" << endl << endl;

  cout << "1. Make a GamaCart" << endl;
  cout << "2. Display your GamaCart" << endl;
  cout << "3. Display the nth item in your cart" << endl;
  cout << "4. Make/Use another account" << endl;
  cout << "5. End Program" << endl << endl;

  cout << "What would you like to do? ";
  cin >> choice;
  cout << endl;

  switch (choice)
  {
    case 1:
      GamaCart_program();
      cout << endl << "CONGRATS! Your GamaCart has been successfully updated"<< endl;
      goto start;
    break;
    case 2:
      display_list();
      goto start;
    break;
    case 3:
      display_item_from_list();
      goto start;
    case 4:
      goto login;
    case 5:
    end:
      cout << endl << "Bye Bye..." << endl;
    break;
  }
  exit:
  return 0;
}
