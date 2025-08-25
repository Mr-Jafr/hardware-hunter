#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int ID_PC_Counter = 0;

class Technical_Details
{
protected:
	string processor;
	string graphics_card;
	string monitor;
	int ram;
	int storage;
};

class Computers_Details
{
protected:
	int ID;
	string computer_name;
	string type;
	double price;
};

//this class it main job is to make sure the user input is right
class Validtor
{
public:

	static double double_number_validtor()
	{
		string element;
		bool is_double = true;

		do
		{
			is_double = true;

			getline(cin, element);

			if (element.length() == 0)
			{
				return 0;
			}
			for (char c : element)
			{
				if (!(isdigit(c)) && !(c == '.'))
				{
					cout << "wrong input or invalid, try again with only numbers\n";
					is_double = false;
					break;
				}
			}
		} while (is_double == false);

		double number = stod(element);
		return number;
	}

	static int int_number_validtor()
	{
		string element;
		bool is_number = true;

		do
		{
			is_number = true;

			getline(cin, element);


			if (element.length() == 0)
			{
				return 0;
			}
			for (char c : element)
			{
				if (!(isdigit(c)))
				{
					cout << "wrong input or invalid, try again with only numbers\n";
					is_number = false;
					break;
				}
			}
		} while (is_number == false);

		int number = stoi(element);
		return number;
	}

	static char char_input_validator()
	{
		string element;
		bool is_valid_input = false;

		while (!is_valid_input) {
			getline(cin, element);

			if (element.length() == 0)
			{
				return 0;
			}
			else if (element.length() == 1)
			{
				is_valid_input = true;
			}
			else
			{
				return 'r';
			}
		}

		return element[0];
	}

	static bool is_emptyy()
	{
		if (ID_PC_Counter == 0)
		{
			cout << "There is no computers in the store\n";
			system("pause");
			system("cls");
			return false;
		}
		return true;
	}

};
//

//this class work only as a container for commaneds of the program
class Commands_Engine : protected Computers_Details, protected Technical_Details
{
protected:
	//the main add commaned
	static Commands_Engine add()
	{
		Commands_Engine temp_computers_detail;
		cout << "Add new Computer to the Store, enter it info\n---------------------\n";
		cout << "Computer Name : ";
		getline(cin, temp_computers_detail.computer_name);
		cout << "Type (Workstation or Gaming) : "; 
		getline(cin, temp_computers_detail.type);
		cout << "Price : ";
		temp_computers_detail.price = Validtor::double_number_validtor();

		cout << "Processor : ";
		getline(cin, temp_computers_detail.processor);
		cout << "Graphics Card : ";
		getline(cin, temp_computers_detail.graphics_card);
		cout << "Monitor : ";
		getline(cin, temp_computers_detail.monitor);
		cout << "Ram : ";
		temp_computers_detail.ram = Validtor::int_number_validtor();
		cout << "Storage : ";
		temp_computers_detail.storage = Validtor::int_number_validtor();

		ID_PC_Counter++;

		temp_computers_detail.ID = ID_PC_Counter;
		cout << "------------------------\ncomputer Add completed\n";
		system("pause");
		system("cls");

		returning_massage();

		return temp_computers_detail;
	}
	//

	//the main show commaned
	void show(vector<Commands_Engine> computers_list)
	{
		if (Validtor::is_emptyy())
		{
			cout << "the Computers in the Store\n";
			for (int i = 0; i < computers_list.size(); i++)
			{
				cout << "---------------------\n";
				cout << "Computer ID : " << computers_list[i].ID << endl;
				cout << "Computer Name : " << computers_list[i].computer_name << endl;
				cout << "type : " << computers_list[i].type << endl;
				cout << "price : " << computers_list[i].price << endl;
			}

			cout << "---------------------\n";
			cout << "choose a PC by ID to get more info.\npress 0 or just enter to cancel\nID: ";

			while (true)
			{
				int user_choice = Validtor::int_number_validtor();
				user_choice;
				if (user_choice == 0)
				{
					system("pause");
					system("cls");
					returning_massage();
					break;
				}
				else if (user_choice <= computers_list.size())
				{
					user_choice--;
					system("cls");
					cout << "the Computer Details\n";
					cout << "-------------------\n";
					cout << "Computer ID : " << computers_list[user_choice].ID << endl;
					cout << "Computer Name : " << computers_list[user_choice].computer_name << endl;
					cout << "type : " << computers_list[user_choice].type << endl;
					cout << "price : " << computers_list[user_choice].price << endl;

					cout << "components\n===================\n";

					cout << "Processor : " << computers_list[user_choice].processor << endl;
					cout << "Graphics Card : " << computers_list[user_choice].graphics_card << endl;
					cout << "Monitor : " << computers_list[user_choice].monitor << endl;
					cout << "Ram : " << computers_list[user_choice].ram << endl;
					cout << "Storage : " << computers_list[user_choice].storage << endl;

					cout << "-------------------\n";

					system("pause");
					system("cls");
					returning_massage();
					break;
				}
				cout << "wrong/invalid ID or input, try again" << endl;
			}
		}
	}
	//

	//the main delete commaned and it sub functions
	vector<Commands_Engine> deletee(vector<Commands_Engine> computers_list)
	{
		if (Validtor::is_emptyy())
		{
			delete_output_function(computers_list, 0, false);

			cout << "---------------------\n";
			cout << "choose a PC by ID to Delete it.\npress 0 or just enter to cancel\nID: ";

			while (true)
			{
				int user_choice = Validtor::int_number_validtor();
				user_choice;
				if (user_choice == 0)
				{
					system("pause");
					system("cls");
					returning_massage();
					return computers_list;
				}
				else if (user_choice <= computers_list.size())
				{
					user_choice--;
					computers_list.erase(computers_list.begin() + user_choice);
					ID_PC_Counter--;

					for (int i = user_choice; i < ID_PC_Counter; i++)
					{
						int j = i + 1;
						computers_list[i].ID = j;

					}
					cout << "the computer has been deleted\n";
					system("pause");
					system("cls");
					returning_massage();
					return computers_list;
				}
				cout << "wrong/invalid ID or input, try again" << endl;
			}
		}
		system("cls");
		returning_massage();
		return computers_list;
	}

	void delete_output_function(vector<Commands_Engine> computers_list, int user_choice, bool decider_for_details)
	{
		edit_output_function(computers_list, user_choice, decider_for_details);
	}
	//


	//the main edit commaned and it sub functions
	vector<Commands_Engine> edit(vector<Commands_Engine> computers_list)
	{
		if (Validtor::is_emptyy())
		{
			edit_output_function(computers_list, 0, false);

			cout << "---------------------\n";
			cout << "choose a PC by ID to Edit it info.\npress 0 or just enter to cancel\nID: ";

			while (true)
			{
				int user_choice = Validtor::int_number_validtor();
				user_choice;
				if (user_choice == 0)
				{
					system("pause");
					system("cls");
					returning_massage();
					return computers_list;
				}
				else if (user_choice <= computers_list.size())
				{
					system("cls");

					user_choice--;
					edit_output_function(computers_list, user_choice, true);

					computers_list[user_choice] = edit_input_function(user_choice);
					cout << "---------------------\nthe Computer Details has been updated\n";
					system("pause");
					system("cls");
					returning_massage();
					return computers_list;
				}
				cout << "wrong/invalid ID or input, try again" << endl;
			}
		}
		system("pause");
		system("cls");
		returning_massage();
		return computers_list;
	}

	static Commands_Engine edit_input_function(int user_choice)
	{
		Commands_Engine temp_computers_detail;
		cout << "---------------------\nEnter the new info\n---------------------\n";
		cout << "Computer Name : ";
		getline(cin, temp_computers_detail.computer_name);
		cout << "Type : ";
		getline(cin, temp_computers_detail.type);
		cout << "Price : ";
		temp_computers_detail.price = Validtor::double_number_validtor();

		cout << "Processor : ";
		getline(cin, temp_computers_detail.processor);
		cout << "Graphics Card : ";
		getline(cin, temp_computers_detail.graphics_card);
		cout << "Monitor : ";
		getline(cin, temp_computers_detail.monitor);
		cout << "Ram : ";
		temp_computers_detail.ram = Validtor::int_number_validtor();
		cout << "Storage : ";
		temp_computers_detail.storage = Validtor::int_number_validtor();

		temp_computers_detail.ID = ++user_choice;

		return temp_computers_detail;
	}

	void edit_output_function(vector<Commands_Engine> computers_list, int user_choice, bool decider_for_details)
	{
		if (decider_for_details == false)
		{
			for (int i = 0; i < computers_list.size(); i++)
			{
				cout << "---------------------\n";
				cout << "Computer ID : " << computers_list[i].ID << endl;
				cout << "Computer Name : " << computers_list[i].computer_name << endl;
				cout << "type : " << computers_list[i].type << endl;
				cout << "price : " << computers_list[i].price << endl;
			}
		}
		else if (decider_for_details == true)
		{
			cout << "the old info-------------------\n";
			cout << "Computer ID : " << computers_list[user_choice].ID << endl;
			cout << "Computer Name : " << computers_list[user_choice].computer_name << endl;
			cout << "type : " << computers_list[user_choice].type << endl;
			cout << "price : " << computers_list[user_choice].price << endl;

			cout << "components\n===================\n";

			cout << "Processor : " << computers_list[user_choice].processor << endl;
			cout << "Graphics Card : " << computers_list[user_choice].graphics_card << endl;
			cout << "Monitor : " << computers_list[user_choice].monitor << endl;
			cout << "Ram : " << computers_list[user_choice].ram << endl;
			cout << "Storage : " << computers_list[user_choice].storage << endl;
		}
	}
	//

	//the main find commaned and it sub functions
	void find(vector<Commands_Engine> computers_list)
	{
		if (Validtor::is_emptyy())
		{

			string type_to_find;
			double price_to_find;
			int pc_id;
			bool while_checker = true;

			vector<Commands_Engine> filtered_computers_list;

			do
			{
				cout << "Computer Finder\n-------------------\nChoose(T or P)\nFind by [T]ype\nFind by [P]rice\npress 0 or just enter to cancel\nFind by:";
				char user_choice = Validtor::char_input_validator();

				system("cls");

				switch (toupper(user_choice))
				{
				case 'T':
					//
					cout << "enter the type of computer you want: ";
					getline(cin, type_to_find);
					system("cls");

					if (is_there_type(computers_list, type_to_find))
					{
						cout << "The computers of type " << type_to_find << " in the store are\n----------------------\n";
						for (int i = 0; i < computers_list.size(); i++)
						{
							if (computers_list[i].type == type_to_find)
							{
								find_output_function(computers_list, i, false);
								filtered_computers_list.push_back(computers_list[i]);
							}
						}

						cout << "choose a PC by ID to get more info.\npress 0 to cancel\nID: ";

						do
						{

							pc_id = Validtor::int_number_validtor();

							if (pc_id == 0)
							{
								break;
							}
							else if (is_there_id(filtered_computers_list, pc_id))
							{
								break;
							}
							cout << "wrong input or ID, try again\n";
						} while (true);

						while_checker = false;
						system("pause");
						system("cls");
						returning_massage();
						break;
					}

					cout << "there is no computer of this type\n";
					system("pause");
					system("cls");
					break;
					//
				case 'P':
					//
					cout << "enter the price of computer you want: ";
					price_to_find = Validtor::double_number_validtor();
					system("cls");

					if (is_there_price(computers_list, price_to_find))
					{
						cout << "The computers of price " << price_to_find << " in the store are\n----------------------\n";
						for (int i = 0; i < computers_list.size(); i++)
						{
							if (computers_list[i].price <= price_to_find)
							{
								find_output_function(computers_list, i, false);
								filtered_computers_list.push_back(computers_list[i]);
							}
						}
						cout << "choose a PC by ID to get more info.\npress 0 to cancel\nID: ";

						do
						{
							pc_id = Validtor::int_number_validtor();

							if (pc_id == 0)
							{
								break;
							}
							else if (is_there_id(filtered_computers_list, pc_id))
							{
								break;
							}
							cout << "wrong input or ID, try again\n";
						} while (true);

						while_checker = false;
						system("pause");
						system("cls");
						returning_massage();
						break;
					}

					cout << "there is no computer of such price\n";
					system("pause");
					system("cls");
					break;
					//
				case '0':
					//
					while_checker = false;
					system("pause");
					system("cls");
					returning_massage();
					break;
				default:
					cout << "error. wrong input\n";
					system("pause");
					system("cls");
					break;
				}
			} while (while_checker);

		}
	}

	static void find_output_function(vector<Commands_Engine> computers_list, int pc_id, bool decider_for_details)
	{
		if (decider_for_details == false)
		{
			cout << "Computer ID : " << computers_list[pc_id].ID << endl;
			cout << "Computer Name : " << computers_list[pc_id].computer_name << endl;
			cout << "type : " << computers_list[pc_id].type << endl;
			cout << "price : " << computers_list[pc_id].price << endl;
			cout << "---------------------\n";
		}
		else if (decider_for_details == true)
		{
			cout << "The details of the computer you wanted\n";
			cout << "---------------------\n";
			cout << "Computer ID : " << computers_list[pc_id].ID << endl;
			cout << "Computer Name : " << computers_list[pc_id].computer_name << endl;
			cout << "type : " << computers_list[pc_id].type << endl;
			cout << "price : " << computers_list[pc_id].price << endl;

			cout << "components\n===================\n";

			cout << "Processor : " << computers_list[pc_id].processor << endl;
			cout << "Graphics Card : " << computers_list[pc_id].graphics_card << endl;
			cout << "Monitor : " << computers_list[pc_id].monitor << endl;
			cout << "Ram : " << computers_list[pc_id].ram << endl;
			cout << "Storage : " << computers_list[pc_id].storage << endl;
			cout << "---------------------\n";
		}
	}

	static bool is_there_type(vector<Commands_Engine> computers_list, string type_to_find)
	{
		int computer_counter = 0;

		for (int i = 0; i < computers_list.size(); i++)
		{
			if (computers_list[i].type == type_to_find)
			{
				computer_counter++;
			}
		}

		return computer_counter > 0;
	}

	static bool is_there_price(vector<Commands_Engine> computers_list, double price_to_find)
	{
		int computer_counter = 0;

		for (int i = 0; i < computers_list.size(); i++)
		{
			if (computers_list[i].price == price_to_find)
			{
				computer_counter++;
			}
		}

		return computer_counter > 0;
	}

	static bool is_there_id(vector<Commands_Engine> filtered_computers_list, int pc_id)
	{

		for (int i = 0; i < filtered_computers_list.size(); i++)
		{
			if (filtered_computers_list[i].ID == pc_id)
			{
				system("cls");
				cout << "---------------------\n";
				find_output_function(filtered_computers_list, i, true);
				return true;
			}
		}
		return false;
	}
	//

	//this functin is to be print a message when return to the main interface 
	static void returning_massage()
	{
		cout << "returning to the main interface, @_@\n";
		system("pause");
		system("cls");
	}
	//
};
//

//this class works as something like interface that let u use and choose the commaneds to work
class Computer_Program : public Commands_Engine
{
private:
	vector<Commands_Engine> computers_list;// this vector will containe all the computer the user entered
public:
	void Run_user_interFace()
	{
		cout << "Welcome in Hardwear Hunter app :)\n";
		bool program_switch = true;

		while (program_switch)
		{
			cout << "---------------------\n";
			cout << "Choose\n[A]dd new Computer to the store\n[S]how Computers in the store\n[D]elete a Computer from the store\n[E]idt a Computer info in the store\n[F]ind a spcifce  Computer in the store\n[C]lose the program\nYour Choice: ";
			char user_choice = Validtor::char_input_validator();

			switch (toupper(user_choice))
			{
			case 'A':
				system("cls");
				cout << "Add commaned $_$\n";
				system("pause");
				system("cls");
				computers_list.push_back(Commands_Engine::add());
				break;
			case 'S':
				system("cls");
				cout << "Show commaned *_*\n";
				system("pause");
				system("cls");
				show(computers_list);
				break;
			case 'D':
				system("cls");
				cout << "Delete commaned !_!\n";
				system("pause");
				system("cls");
				computers_list = deletee(computers_list);
				break;
			case'E':
				system("cls");
				cout << "Edit commaned %_%\n";
				system("pause");
				system("cls");
				computers_list = edit(computers_list);
				break;
			case 'F':
				system("cls");
				cout << "Find commaned ^_^\n";
				system("pause");
				system("cls");
				find(computers_list);
				break;
			case 'C':
				system("cls");
				cout << "Closing the program, bye\n";
				system("pause");
				system("cls");
				program_switch = false;
				break;
			default:
				cout << "error. wrong input\n";
				system("pause");
				system("cls");
				break;
			}

		}

	}
};

int main()
{
	Computer_Program object;

	object.Run_user_interFace();

	return 0;
}