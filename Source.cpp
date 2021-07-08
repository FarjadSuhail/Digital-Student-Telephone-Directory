#include<iostream>
using namespace std;



template <class T>
class Node
{
public:
	Node* next;
	char first[20];
	char last[20];
	char tel[20];
	char roll_no[10];

};


struct record
{
	char first[20];
	char last[20];
	char tel[20];
	char roll_no[10];
};







template <class T>
class LLARDT
{
	Node <T>* First;

public:
	LLARDT()
	{

		First = 0;
	}

	void insert(record a) //insert the node at the end.
	{
		Node<T>* temp = new Node<T>;

		int i = 0;
		for (; a.last[i] != '\0'; i++)
		{
			temp->last[i] = a.last[i];
		}
		temp->last[i] = '\0';


		i = 0;
		for (; a.first[i] != '\0'; i++)
		{
			temp->first[i] = a.first[i];
		}
		temp->first[i] = '\0';


		i = 0;
		for (; a.tel[i] != '\0'; i++)
		{
			temp->tel[i] = a.tel[i];
		}
		temp->tel[i] = '\0';


		i = 0;
		for (; a.roll_no[i] != '\0'; i++)
		{
			temp->roll_no[i] = a.roll_no[i];
		}
		temp->roll_no[i] = '\0';


		temp->next = NULL;


		if (First == 0)
		{
			First = temp;
		}

		else
		{
			Node<T>* curr = First;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}

	}


	bool delete_record()
	{
		Node <T>* curr = First;
		Node <T>* prev = 0;
		Node <T>* temp = 0;


		char abc[10];
		cout << endl << "Enter to Delete" << endl;
		cin >> abc;

		int sizeofsearch = strlen(abc);
		bool flag = true;

		if (curr == NULL)
		{
			cout << "Directory is Empty!";
			return 0;
		}


		while (curr != NULL)
		{
			int sizeofgiven = strlen(curr->last);

			if (sizeofsearch == sizeofgiven)
			{

				for (int i = 0; abc[i] != '\0'; i++)
				{
					flag = true;
					if (abc[i] != curr->last[i] && (abc[i] + 32) != curr->last[i] && (abc[i] - 32) != curr->last[i])
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					break;
				}

			}
			sizeofgiven = strlen(curr->first);

			if (sizeofsearch == sizeofgiven)
			{
				int sizeofgiven = strlen(curr->first);


				if (sizeofsearch == sizeofgiven)
				{
					for (int i = 0; abc[i] != '\0'; i++)
					{
						flag = true;

						if (abc[i] != curr->first[i] && (abc[i] + 32) != curr->first[i] && (abc[i] - 32) != curr->first[i])
						{
							flag = false;
							break;
						}
					}

					if (flag)
					{
						break;
					}

				}
			}


			sizeofgiven = strlen(curr->tel);

			if (sizeofsearch == sizeofgiven)
			{

				for (int i = 0; abc[i] != '\0'; i++)
				{
					flag = true;

					if (abc[i] != curr->tel[i])
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					break;
				}

			}


			else
			{
				prev = curr;
				curr = curr->next;
			}
		}


		if (curr == NULL)
		{
			cout << "Directory is Empty!";
			return 0;
		}

		if (curr == First)
		{
			First = First->next;
			delete curr;
		}
		else
		{
			prev->next = curr->next;
			delete curr;
		}
		return 0;
	}



	~LLARDT()
	{
		Node<T>* curr = First;

		while (curr != NULL)
		{
			First = First->next;
			delete curr;
			curr = First;
		}

	}



	void print()
	{
		Node<T>* curr = First;

		if (curr == NULL)
		{
			cout << "Directory is Empty" << endl;
		}
		while (curr != NULL)
		{
			cout << "Name : " << curr->first << " " << curr->last << endl;
			cout << "Roll No. : " << curr->roll_no << endl;
			cout << "Telephone No. : " << curr->tel << endl;
			curr = curr->next;
			cout << endl << endl << "-------------------------------" << endl << endl;

		}

	}


	bool search()
	{
		bool flag = true;
		char abc[10];
		cout << endl << "Enter to Search" << endl;
		cin >> abc;
		int i = 0;

		int sizeofsearch = strlen(abc);

		Node<T>* curr = First;
		Node<T>* prev = 0;

		if (curr == NULL)
		{
			flag = false;
		}

		while (curr != NULL)
		{
			int sizeofgiven = strlen(curr->last);

			if (sizeofsearch == sizeofgiven)
			{

				for (int i = 0; abc[i] != '\0'; i++)
				{
					flag = true;
					if (abc[i] != curr->last[i] && (abc[i] + 32) != curr->last[i] && (abc[i] - 32) != curr->last[i])
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					curr = First;
					return flag;
				}

			}

			if (strlen(curr->first) == sizeofsearch)
			{
				int sizeofgiven = strlen(curr->first);

				for (int i = 0; abc[i] != '\0'; i++)
				{
					flag = true;

					if (abc[i] != curr->first[i] && (abc[i] + 32) != curr->first[i] && (abc[i] - 32) != curr->first[i])
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					curr = First;
					return flag;
				}

			}

			if (strlen(curr->tel) == sizeofsearch)
			{

				for (int i = 0; abc[i] != '\0'; i++)
				{
					flag = true;

					if (abc[i] != curr->tel[i])
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					curr = First;
					return flag;
				}


			}
			else
			{
				curr = curr->next;

			}
		}


		return flag;
	}


	void menu()
	{


		cout << "Enter '1' To Enter A New Record :  " << endl;
		cout << "Enter '2' To Delete A Record " << endl;
		cout << "Enter '3' To Search A Record " << endl;
		cout << "Enter '4' To Print existing Records " << endl;


	}
};










void main()
{


	//LLADT<int> L;
	//for (int i = 0; i < 10; i++)
	//	L.insert(i * 2);

	//cout << "Value at Center Node : " << L.valAtCenterNode();
	//cout << "\nRemoving: " << L.removefromPosition(6) << endl;
	//cout << "Value at Center Node : " << L.valAtCenterNode() << endl << endl;

	//if (L.remove(12))
	//	cout << "Removed" << endl << endl;
	//else
	//	cout << "No Removed" << endl << endl;

	//cout << "Nodes Printed in Reverse : ";
	//L.printBackward();

	//cout << endl << "--------------------------------------------------------------------";
	//cout << endl << endl;

	LLARDT<record> A;
	record a;


	cout << "Welcome To Digital Student Telephone Directory " << endl << endl;
	cout << "To Go Into Telephone directory Enter 'Y' or 'y' Else Enter 'N' to Exit" << endl;


	char x;
	cin >> x;

	while (x != 'N')
	{
		if (x == 'Y' || x == 'y')
		{
			A.menu();
			cout << endl;
			cout << "Enter Your Option Pliss!" << endl;
			int num;
			cin >> num;

			if (num == 1)
			{
				cout << "Enter First Name : ";
				cin >> a.first;

				cout << "Enter Last Name : ";
				cin >> a.last;

				cout << "Enter Tel Num : ";
				cin >> a.tel;

				cout << "Enter Roll_No : ";
				cin >> a.roll_no;

				A.insert(a);

			}


			else if (num == 2)
			{
				cout << "Enter Name or Telephone No. " << endl;
				A.delete_record();
			}


			else if (num == 3)
			{
				cout << "Enter Name or Telephone No. " << endl;
				if (A.search())
				{
					cout << "Record Found!";
				}
				else cout << "Record Not Found!";
			}


			else if (num == 4)
			{
				cout << endl;
				A.print();

				cout << endl;
			}

		}

		cout << endl << "To Stay Into the directory Enter 'Y' or 'y' Else Enter 'N'  to Exit" << endl;
		cin >> x;


	}


	system("pause");
}