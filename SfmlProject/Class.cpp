#include "Header.h"
using namespace std;

class Player  //class of player
{
	string playerPassword="";
	string playerName="";
	char playerGender=' ';
	int playerShirtNo=0;
	int playerTotalRun=0;
	float playerRunAverage=0;
	int playerMatchPlayed=0;
	int playerTotalWickets=0;
	int playerIccRanking=0;

public:
	friend class team;
	Player(string password, string playerName, char gender, int shirtNo, int totalRun, int matchPlayed, int totalWickets, int iccRanking)
	{
		this->playerPassword = password;
		this->playerName = playerName;
		this->playerGender = gender;
		this->playerShirtNo = shirtNo;
		this->playerMatchPlayed = matchPlayed;
		this->playerTotalWickets = totalWickets;
		this->playerTotalRun = totalRun;
		if (matchPlayed == 0)
		{
			playerRunAverage = 0;
		}
		else
		{
			playerRunAverage = totalRun / matchPlayed;
		}
		this->playerIccRanking = iccRanking;
	}

	Player()
	{

	}

	virtual ~Player()
	{

	}

	friend void operator == (Player player1, Player player2)
	{
		player1.playerPassword = player2.playerPassword;
		player1.playerName = player2.playerName;
		player1.playerGender = player2.playerGender;
		player1.playerShirtNo = player2.playerShirtNo;
		player1.playerTotalRun = player2.playerTotalRun;
		player1.playerRunAverage = player2.playerRunAverage;
		player1.playerMatchPlayed = player2.playerMatchPlayed;
		player1.playerTotalWickets = player2.playerTotalWickets;
		player1.playerIccRanking = player2.playerIccRanking;
	}
};

class team
{
public:
	string teamName="";
	int teamIccRanking=0;
	int teamNoOfPlayers=0;
	int teamTotalMatchesWon=0;
	int teamTotalMatchesLost=0;
	string teamCaptain = "";
	string teamCoach="";
	string adminUsername="";
	string adminPassword="";
	int checkAccess = 0;
	int teamNo=0;

	Player* ptr;

	team(int teamNo)
	{
		this->teamNo = teamNo;
		string name = "data/team";
		name += to_string(teamNo);
		name += ".txt";
		ifstream file;
		file.open(name);
		file >> teamNoOfPlayers;
		file.close();
		ptr = new Player[teamNoOfPlayers];
		gainPlayerData();
	}

	~team()
	{
		sendPlayerData();
	}

	void adminLogin()
	{
		string name;
		string password;
		string phoneNumber;
		int passwordCheck;
		int otp;
		int otpCheck;
		int checkAccess = 0;
		int choice = 0;
		cout << "Please enter your name : ";
		cin >> name;
		if (name == adminUsername)
		{
			cout << "Please enter your password : ";
			cin >> password;
			if (password == adminPassword)
			{
				checkAccess = 1;
			}
			else
			{
				passwordCheck = 0;
				while (password != adminPassword)
				{
					cout << "\nYour entered password is wrong, please input it again : ";
					cin >> adminPassword;
					passwordCheck++;
					if (passwordCheck == 5)
					{
						cout << "\nYou forget your password!\n";
						cout << "\nPlease enter your phoneNumber where we will send OTP, input that OTP to recover your account : ";
						cin >> phoneNumber;
						otp = rand() % 1000;
						cout << "The otp " << otp << " send to " << phoneNumber << " phone number.";
						cout << "\nPlease enter otp to recover your account : ";
						cin >> otpCheck;
						if (otpCheck == otp)
						{
							cout << "\nHi " << adminUsername << ", This is your password : " << adminPassword;
							password = adminPassword;
						}
						else
						{
							cout << "\nNow your account is temporarily banned.\n If you want to recover it,"
								<< " contact to our support team to our office at Fast Nuces cfd.Thank you.\n";
						}
					}
				}
				if (password == adminPassword)
				{
					checkAccess = 1;
				}
			}
		}
		else
		{
			cout << "\n\nNo such name exist\n\n";
		}
		if (checkAccess == 1)
		{
			cout << "\nWelcome to the admin portal.\n";
			displayTeam();
			while (true)
			{

				cout << "\n1) Add player\n2) Remove Player\n3) Update Admin\n" <<
					"4) Update Player\n5) Update Captain\n6) Update Coach\n" <<
					"7) Serach By Shirt And Display\n8) Search By ICC Ranking And Display\n" <<
					"9) Output player of specific runs\n10) Output player of specific wickets\n" <<
					"11) Output player of specific match played\n12) Delete Duplicate\n" << 
					"13) Output all data of team\n14)Set all values to default\n15)Exit from program\n";

				cout << "\n\nPlease enter your choice to proceed : ";
				cin >> choice;
				cout << endl;
				switch (choice)
				{
				case 1:
				{
					ptr = addPlayer();
					break;
				}
				case 2:
				{
					ptr = removePlayer();
					break;
				}
				case 3:
				{
					updateAdmin();
					break;
				}
				case 4:
				{
					updatePlayer();
					break;
				}
				case 5:
				{
					updateCaptain();
					break;
				}
				case 6:
				{
					updateCoach();
					break;
				}
				case 7:
				{
					searchByShirtAndDisplay();
					break;
				}
				case 8:
				{
					searchByrankingAndDisplay();
					break;
				}
				case 9:
				{
					particularRuns();
					break;
				}
				case 10:
				{
					particularWickets();
					break;
				}
				case 11:
				{
					particularMatchPlayed();
					break;
				}
				case 12:
				{
					ptr = deleteDuplicate();
					break;
				}
				case 13:
				{
					displayTeam();
					break;
				}
				case 14:
				{
					defaultList();
					break;
				}
				case 15:
				{
					return;
					break;
				}
				default:
				{
					cout << "\n\nInvalid input\n\n";
					break;
				}
				}
			}
		}
	}

	void playerLogin()
	{
		srand(time(0));
		string playerName;
		string playerPassword;
		string phoneNumber;
		int passwordCheck;
		int otp;
		int otpCheck;
		int checkAccess = 0;
		int choice = 0;
		cout << "Please enter your name : ";
		cin >> playerName;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (playerName == ptr[i].playerName)
			{
				cout << "Please enter your password : ";
				cin >> playerPassword;
				if (playerPassword == ptr[i].playerPassword)
				{
					checkAccess = 1;
					break;
				}
				else
				{
					passwordCheck = 0;
					while (playerPassword != ptr[i].playerPassword)
					{
						cout << "\nYour entered password is wrong, please input it again : ";
						cin >> playerPassword;
						passwordCheck++;
						if (passwordCheck == 5)
						{
							cout << "\nYou forget your password!\n";
							cout << "\nPlease enter your phoneNumber where we will send OTP, input that OTP to recover your account : ";
							cin >> phoneNumber;
							otp = rand() % 1000;
							cout << "The otp " << otp << " send to " << phoneNumber << " phone number.";
							cout << "\nPlease enter otp to recover your account : ";
							cin >> otpCheck;
							if (otpCheck == otp)
							{
								cout << "\nHi " << ptr[i].playerName << ", This is your password : " << ptr[i].playerPassword;
								playerPassword = ptr[i].playerPassword;
							}
							else
							{
								cout << "\nNow your account is temporarily banned.\n If you want to recover it,"
									<< " contact to our support team to our office at Fast Nuces cfd.Thank you.\n";
								break;
							}
						}
					}
					if (playerPassword == ptr[i].playerPassword)
					{
						checkAccess = 1;
						break;
					}
				}
			}
			else
			{
				if (i == teamNoOfPlayers - 1)
				{
					cout << "\n\nNo such name exist\n\n";
				}
			}
		}
		if (checkAccess == 1)
		{
			cout << "\n\nWelcome to the player portal.\n";
			displayTeam();
			while (true)
			{
				cout << "\n1) Search Player by shirt number\n2) Search Player by Icc ranking"
					<< "\n3) Output player of specific runs\n4) Output player of specific wickets\n5) Output player of specific match played"
					<< "\n6) Output all data\n7)Exit from program";
				cout << "\n\nPlease enter your choice to proceed : ";

				cin >> choice;
				cout << endl;

				switch (choice)
				{
				case 1:
				{
					searchByShirtAndDisplay();
					break;
				}
				case 2:
				{
					searchByrankingAndDisplay();
					break;
				}
				case 3:
				{
					particularRuns();
					break;
				}
				case 4:
				{
					particularWickets();
					break;
				}
				case 5:
				{
					particularMatchPlayed();
					break;
				}
				case 6:
				{
					displayTeam();
					break;
				}
				case 7:
				{
					return;
					break;
				}
				default:
				{
					cout << "\n\nInvalid input\n\n";
					break;
				}
				}
			}
		}
	}

	void updateAdmin()
	{
		cout << "Please enter the new admin user name : ";
		cin >> adminUsername;
		cout << "Please enter the new admin password : ";
		cin >> adminPassword;
	}

	void updateCoach()
	{
		cout << "Please enter the name of coach : ";
		cin >> teamCoach;
	}

	void updateCaptain()
	{
		string newCaptain;
		cout << "Please enter your new captain name : ";
		cin >> newCaptain;

		teamCaptain = newCaptain;
	}

	Player* addPlayer()
	{
		int position, temp = 0;
		if (teamNoOfPlayers >= 15)
		{
			cout << "\nYou can't add new player because fifteen player seats are full.\n\n";
			return ptr;
		}
		cout << "Please enter the position at which you want to add new student : ";
		cin >> position;
		Player* resize = new Player[teamNoOfPlayers + 1];
		for (int i = 0; i < teamNoOfPlayers; i++)
		{
			if (i == position)
			{
				++temp;
				inputFix(resize, position);
				for (int j = 0; j < teamNoOfPlayers; ++j)
				{
					if (ptr[position].playerShirtNo == ptr[j].playerShirtNo)
					{
						if (i != position)
						{
						cout << "\nYou can't add player with same shirt number!\n";
						return ptr;
						}
					}
					if (ptr[position].playerName == ptr[i].playerName)
					{
						if (i != position)
						{
							cout << "\nYou can't add player with same name!\n";
							return ptr;
						}
					}
				}
			}
			if (temp == 0)
			{
				resize[i].playerGender = ptr[i].playerGender;
				resize[i].playerIccRanking = ptr[i].playerIccRanking;
				resize[i].playerMatchPlayed = ptr[i].playerMatchPlayed;
				resize[i].playerPassword = ptr[i].playerPassword;
				resize[i].playerName = ptr[i].playerName;
				resize[i].playerRunAverage = ptr[i].playerRunAverage;
				resize[i].playerShirtNo = ptr[i].playerShirtNo;
				resize[i].playerTotalRun = ptr[i].playerTotalRun;
				resize[i].playerTotalWickets = ptr[i].playerTotalWickets;
			}
			else
			{
				resize[i + 1].playerGender = ptr[i].playerGender;
				resize[i + 1].playerIccRanking = ptr[i].playerIccRanking;
				resize[i + 1].playerMatchPlayed = ptr[i].playerMatchPlayed;
				resize[i + 1].playerPassword = ptr[i].playerPassword;
				resize[i + 1].playerName = ptr[i].playerName;
				resize[i + 1].playerRunAverage = ptr[i].playerRunAverage;
				resize[i + 1].playerShirtNo = ptr[i].playerShirtNo;
				resize[i + 1].playerTotalRun = ptr[i].playerTotalRun;
				resize[i + 1].playerTotalWickets = ptr[i].playerTotalWickets;
			}
		}
		teamNoOfPlayers = teamNoOfPlayers + 1;
		delete[]ptr;
		ptr = NULL;
		cout << "\n\nYour player added successfully.\n\n";
		return resize;
	}

	Player* removePlayer(int shirtNo)
	{
		if (teamNoOfPlayers <= 11)
		{
			cout << "\nYou can't remove any player because every team must have at least eleven players.\n\n";
			return ptr;
		}
		int temp2 = 0;
		int found;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerShirtNo == shirtNo)
			{
				found = i;
				++temp2;
			}
		}
		if (temp2 != 0)
		{
			Player* resize = new Player[teamNoOfPlayers - 1];
			int temp2 = 1;
			for (int i = 0; i < teamNoOfPlayers; i++)
			{
				if (i < found)
				{
					resize[i].playerGender = ptr[i].playerGender;
					resize[i].playerIccRanking = ptr[i].playerIccRanking;;
					resize[i].playerMatchPlayed = ptr[i].playerMatchPlayed;
					resize[i].playerPassword = ptr[i].playerPassword;
					resize[i].playerName = ptr[i].playerName;
					resize[i].playerRunAverage = ptr[i].playerRunAverage;
					resize[i].playerShirtNo = ptr[i].playerShirtNo;
					resize[i].playerTotalRun = ptr[i].playerTotalRun;
					resize[i].playerTotalWickets = ptr[i].playerTotalWickets;
				}
				else if (i > found)
				{
					resize[i - temp2].playerGender = ptr[i].playerGender;
					resize[i - temp2].playerIccRanking = ptr[i].playerIccRanking;
					resize[i - temp2].playerMatchPlayed = ptr[i].playerMatchPlayed;
					resize[i - temp2].playerPassword = ptr[i].playerPassword;
					resize[i - temp2].playerName = ptr[i].playerName;
					resize[i - temp2].playerRunAverage = ptr[i].playerRunAverage;
					resize[i - temp2].playerShirtNo = ptr[i].playerShirtNo;
					resize[i - temp2].playerTotalRun = ptr[i].playerTotalRun;
					resize[i - temp2].playerTotalWickets = ptr[i].playerTotalWickets;
				}
			}
			teamNoOfPlayers = teamNoOfPlayers - 1;
			delete[]ptr;
			ptr = NULL;
			return resize;
		}
		else
		{
			cout << "No player of this shirt number found.\n";
			return ptr;
		}
	}

	Player* removePlayer()
	{
		if (teamNoOfPlayers <= 11)
		{
			cout << "\nYou can't remove any player because every team must have at least eleven players.\n";
			return ptr;
		}
		int shirtNo;
		cout << "Please enter the shirt number of player to remove player : ";
		cin >> shirtNo;
		int temp2 = 0;
		int found;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerShirtNo == shirtNo)
			{
				found = i;
				++temp2;
			}
		}
		if (temp2 != 0)
		{
			Player* resize = new Player[teamNoOfPlayers - 1];
			int temp2 = 1;
			for (int i = 0; i < teamNoOfPlayers; i++)
			{
				if (i < found)
				{
					resize[i].playerGender = ptr[i].playerGender;
					resize[i].playerIccRanking = ptr[i].playerIccRanking;;
					resize[i].playerMatchPlayed = ptr[i].playerMatchPlayed;
					resize[i].playerPassword = ptr[i].playerPassword;
					resize[i].playerName = ptr[i].playerName;
					resize[i].playerRunAverage = ptr[i].playerRunAverage;
					resize[i].playerShirtNo = ptr[i].playerShirtNo;
					resize[i].playerTotalRun = ptr[i].playerTotalRun;
					resize[i].playerTotalWickets = ptr[i].playerTotalWickets;
				}
				else if (i > found)
				{
					resize[i - temp2].playerGender = ptr[i].playerGender;
					resize[i - temp2].playerIccRanking = ptr[i].playerIccRanking;
					resize[i - temp2].playerMatchPlayed = ptr[i].playerMatchPlayed;
					resize[i - temp2].playerPassword = ptr[i].playerPassword;
					resize[i - temp2].playerName = ptr[i].playerName;
					resize[i - temp2].playerRunAverage = ptr[i].playerRunAverage;
					resize[i - temp2].playerShirtNo = ptr[i].playerShirtNo;
					resize[i - temp2].playerTotalRun = ptr[i].playerTotalRun;
					resize[i - temp2].playerTotalWickets = ptr[i].playerTotalWickets;
				}
			}
			teamNoOfPlayers = teamNoOfPlayers - 1;
			delete[]ptr;
			ptr = NULL;
			cout << "\n\nYour player removed successfully.\n\n";
			return resize;
		}
		else
		{
			cout << "No player of this shirt number found.\n";
			return ptr;
		}
	}

	Player* deleteDuplicate()
	{
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			for (int j = i + 1; j < teamNoOfPlayers; ++j)
			{
				if ((ptr[i].playerGender == ptr[j].playerGender) && (ptr[i].playerMatchPlayed == ptr[i].playerMatchPlayed) && (ptr[i].playerName == ptr[j].playerName))
				{
					if ((ptr[i].playerRunAverage == ptr[j].playerRunAverage) && (ptr[i].playerShirtNo == ptr[j].playerShirtNo) && (ptr[i].playerTotalRun == ptr[j].playerTotalRun))
					{
						if ((ptr[i].playerTotalWickets == ptr[j].playerTotalWickets))
						{
							ptr = removePlayer(ptr[i].playerShirtNo);
						}
					}
				}
			}
		}
		return ptr;
	}

	void searchByShirtAndDisplay()
	{
		int shirt;
		int found = -1;
		cout << "Please enter the shirt number of player of which you want to print data : ";
		cin >> shirt;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerShirtNo == shirt)
			{
				found = i;
			}
		}
		if (found == -1)
		{
			cout << "No player of this shirt number exist.\n";
			return;
		}
		outputFix(found, 0);
	}

	void searchByrankingAndDisplay()
	{
		int ranking;
		int found = -1;
		cout << "Please enter the ranking of player of which you want to print data : ";
		cin >> ranking;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerIccRanking == ranking)
			{
				found = i;
			}
		}
		if (found == -1)
		{
			cout << "No player of this ranking exist.\n";
			return;
		}
		outputFix(found, 0);
	}

	void updatePlayer()
	{
		int found = -1;
		int shirtNo;
		cout << "Please enter the shirt number to update student data : ";
		cin >> shirtNo;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerShirtNo == shirtNo)
			{
				found = i;
			}
		}
		if (found == -1)
		{
			cout << "No Player of such shirt number found.\n";
			return;
		}
		else
		{
			inputFix(ptr, found);
			cout << "\n\nYour player updated successfully.\n\n";
		}
	}

	void outputFix(int position, int check)
	{
		if (check == 0)
		{
			cout << "Name\t\t  Gender   Shirt number   Total run   Run average   Match played   Total wickets   Icc ranking\n";
			for (int i = 0; i < teamNoOfPlayers; ++i)
			{
				cout << setw(20) << left << ptr[position].playerName << setw(12) << left << ptr[position].playerGender << setw(14) << left <<
					ptr[position].playerShirtNo << setw(12) << left << ptr[position].playerTotalRun << setw(14) << left <<
					ptr[position].playerRunAverage << setw(15) << left << ptr[position].playerMatchPlayed
					<< setw(16) << left << ptr[position].playerTotalWickets << setw(10) << left << ptr[position].playerIccRanking << endl;
			}
		}
		else
		{
			for (int i = 0; i < teamNoOfPlayers; ++i)
			{
				cout << setw(20) << left << ptr[position].playerName << setw(12) << left << ptr[position].playerGender << setw(14) << left <<
					ptr[position].playerShirtNo << setw(12) << left << ptr[position].playerTotalRun << setw(14) << left <<
					ptr[position].playerRunAverage << setw(15) << left << ptr[position].playerMatchPlayed
					<< setw(16) << left << ptr[position].playerTotalWickets << setw(10) << left << ptr[position].playerIccRanking << endl;
			}
		}
	}

	void inputFix(Player* ptr, int position)
	{
		cout << "Please enter the gender of " << position + 1 << "th player : ";
		cin >> ptr[position].playerGender;
		cout << "Please enter the icc ranking of " << position + 1 << "th player : ";
		cin >> ptr[position].playerIccRanking;
		cout << "Please enter the match played of " << position + 1 << "th player : ";
		cin >> ptr[position].playerMatchPlayed;
		cout << "Please enter the password of " << position + 1 << "th player : ";
		cin >> ptr[position].playerPassword;
		cout << "Please enter the player name of " << position + 1 << "th player : ";
		cin >> ptr[position].playerName;
		cout << "Please enter the shirt number of " << position + 1 << "th player : ";
		cin >> ptr[position].playerShirtNo;
		cout << "Please enter the total run of " << position + 1 << "th player : ";
		cin >> ptr[position].playerTotalRun;
		cout << "Please enter the total wickets of " << position + 1 << "th player : ";
		cin >> ptr[position].playerTotalWickets;
		ptr[position].playerRunAverage = ptr[position].playerTotalRun / ptr[position].playerMatchPlayed;
	}

	void displayTeam()
	{
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerMatchPlayed == 0)
			{
				ptr[i].playerRunAverage = 0;
			}
			else
			{
				ptr[i].playerRunAverage = ptr[i].playerTotalRun / ptr[i].playerMatchPlayed;
			}
		}

		int least_index;
		float temp;
		for (int i = 0; i < teamNoOfPlayers - 1; i++)
		{
			least_index = i;
			for (int j = i + 1; j < teamNoOfPlayers; j++)
			{
				if (ptr[j].playerRunAverage < ptr[least_index].playerRunAverage)
					least_index = j;
			}
			temp = ptr[least_index].playerRunAverage;
			ptr[least_index].playerRunAverage = ptr[i].playerRunAverage;
			ptr[i].playerRunAverage = temp;
		}

		cout << "Name\t\t  Gender   Shirt number   Total run   Run average   Match played   Total wickets   Icc ranking\n";
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			cout << setw(20) << left << ptr[i].playerName << setw(12) << left << ptr[i].playerGender << setw(14) << left << ptr[i].playerShirtNo
				<< setw(12) << left << ptr[i].playerTotalRun << setw(14) << left << ptr[i].playerRunAverage << setw(15) << left << ptr[i].playerMatchPlayed
				<< setw(16) << left << ptr[i].playerTotalWickets << setw(10) << left << ptr[i].playerIccRanking << endl;
		}

		cout << "\nThis is your team name : " << teamName;
		cout << "\nThis is your team ICC ranking : " << teamIccRanking;
		cout << "\nThis is the number of players in your team : " << teamNoOfPlayers;
		cout << "\nThis is the total matches won by your team : " << teamTotalMatchesWon;
		cout << "\nThis is the total matches lose by your team : " << teamTotalMatchesLost;
		cout << "\nThis is your team captain : " << teamCaptain;
		cout << "\nThis is your team coach : " << teamCoach;
		cout << "\nThis is your team admin name : " << adminUsername << endl << endl;
	}

	void particularRuns()
	{
		int check = 0;
		int runs;
		cout << "Please enter run you want to show : ";
		cin >> runs;
		int temp = 0;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerTotalRun == runs)
			{
				if (temp == 0)
				{
					++temp;
				}
				outputFix(i, check);
				check++;
			}
		}
		if (temp == 0)
		{
			cout << "\n\nNo player with such runs exist.\n\n";
		}
	}

	void particularWickets()
	{
		int check = 0;
		int wickets;
		cout << "Please enter the wickets of player you want to show : ";
		cin >> wickets;
		int temp = 0;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerTotalWickets == wickets)
			{
				if (temp == 0)
				{
					++temp;
				}
				outputFix(i, check);
				check++;
			}
		}
		if (temp == 0)
		{
			cout << "\n\nNo player with such wickets number exist.\n\n";
		}
	}

	void particularMatchPlayed()
	{
		int check = 0;
		int matchPlayed;
		cout << "Please enter match playes you want to show : ";
		cin >> matchPlayed;
		int temp = 0;
		for (int i = 0; i < teamNoOfPlayers; ++i)
		{
			if (ptr[i].playerMatchPlayed == matchPlayed)
			{
				if (temp == 0)
				{
					++temp;
				}
				outputFix(i, check);
				check++;
			}
		}
		if (temp == 0)
		{
			cout << "\n\nNo player with such runs exist.\n\n";
		}
	}

	void sendPlayerData()
	{
		ofstream saveTeamData;
		string name = "data/team";
		name += to_string(teamNo);
		name += ".txt";
		saveTeamData.open(name);
		if (!saveTeamData.is_open())
		{
			cout << "Your file is unable to open!\n";
		}
		else
		{
			saveTeamData << teamNoOfPlayers;
			saveTeamData << endl;

			for(int i = 0; i < teamNoOfPlayers; ++i)
			{
				if (ptr[i].playerMatchPlayed == 0)
				{
					ptr[i].playerRunAverage = 0;
				}
				else
				{
					ptr[i].playerRunAverage = ptr[i].playerTotalRun / ptr[i].playerMatchPlayed;
				}
			}

			for (int i = 0; i < teamNoOfPlayers; ++i)
			{
				saveTeamData << ptr[i].playerPassword;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerName;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerGender;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerTotalRun;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerMatchPlayed;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerRunAverage;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerShirtNo;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerTotalWickets;
				saveTeamData << endl;
				saveTeamData << ptr[i].playerIccRanking;
				saveTeamData << endl;
				saveTeamData << endl;
			}
			saveTeamData << endl;
			saveTeamData << teamName;
			saveTeamData << endl;
			saveTeamData << teamIccRanking;
			saveTeamData << endl;
			saveTeamData << teamTotalMatchesWon;
			saveTeamData << endl;
			saveTeamData << teamTotalMatchesLost;
			saveTeamData << endl;
			saveTeamData << teamCaptain;
			saveTeamData << endl;
			saveTeamData << teamCoach;
			saveTeamData << endl;
			saveTeamData << adminUsername;
			saveTeamData << endl;
			saveTeamData << adminPassword;
			saveTeamData << endl;
			saveTeamData.close();
		}
	}

	void gainPlayerData()
	{
		ifstream gainTeamData;
		string name = "data/team";
		name += to_string(teamNo);
		name += ".txt";
		gainTeamData.open(name);
		if (!gainTeamData.is_open())
		{
			cout << "\nYour file is unable to open!\n";
		}
		else
		{
			gainTeamData >> teamNoOfPlayers;
			for (int i = 0; i < teamNoOfPlayers; ++i)
			{
				gainTeamData >> ptr[i].playerPassword;
				gainTeamData >> ptr[i].playerName;
				gainTeamData >> ptr[i].playerGender;
				gainTeamData >> ptr[i].playerTotalRun;
				gainTeamData >> ptr[i].playerMatchPlayed;
				gainTeamData >> ptr[i].playerRunAverage;
				gainTeamData >> ptr[i].playerShirtNo;
				gainTeamData >> ptr[i].playerTotalWickets;
				gainTeamData >> ptr[i].playerIccRanking;
			}
			gainTeamData >> teamName;
			gainTeamData >> teamIccRanking;
			gainTeamData >> teamTotalMatchesWon;
			gainTeamData >> teamTotalMatchesLost;
			gainTeamData >> teamCaptain;
			gainTeamData >> teamCoach;
			gainTeamData >> adminUsername;
			gainTeamData >> adminPassword;
			gainTeamData.close();
		}
	}

	void defaultList()

	{
		teamNoOfPlayers = 11;

		ptr[0] = { "8293","M.Awais",'M',1,20,20,1,1 };
		ptr[1] = { "6229","M.Ilyan",'M',2,20,20,1,2 };
		ptr[2] = { "9263","M.Ahmed",'M',3,20,20,1,3 };
		ptr[3] = { "5968","M.Sufyan",'M',4,20,20,1,4 };
		ptr[6] = { "4293","M.Sanan",'M',5,20,20,1,5 };
		ptr[4] = { "3625","M.Wasif",'M',6,20,20,1,6 };
		ptr[5] = { "1652","M.Waleed",'M',7,20,20,1,7 };
		ptr[7] = { "2497","M.Rijab",'M',8,20,20,1,8 };
		ptr[8] = { "7298","M.Bilal",'M',9,20,20,1,9 };
		ptr[9] = { "2356","M.Ayezad",'M',10,20,20,1,10 };
		ptr[10] = { "2343","M.Akram",'M',11,20,20,1,11 };

		teamTotalMatchesWon = 0;
		teamTotalMatchesLost = 0;
		teamCaptain == "M.Awais";
		teamCoach = "M.Awais";
		adminUsername = "M.Awais";
		adminPassword = "160490";
		teamIccRanking = 0;
		sendPlayerData();
	}

};

class Match {
private:
	string tournamentName;
	string commentators;
	string umpires;
	string matchType;
	string venue;
	string date;
public:
	Match()
	{}
	Match(string tournamentName, string commentators, string umpires, string matchType, string venue, string date)
	{
		this->date = date;
		this->venue = venue;
		this->matchType = matchType;
		this->tournamentName = tournamentName;
		this->commentators = commentators;
		this->umpires = umpires;
	}

	void setdate() {
		cout << "\nEnter Match date : ";
		cin >> date;
	}
	string getdate() {
		return date;
	}
	void setvenue() {
		cout << "\nEnter Match Venue : ";
		cin >> venue;
	}
	string getvenue() {
		return venue;
	}
	void setmatchType() {
		cout << "\nEnter Match type( ODI / T-20 / T-10 ) : ";
		cin >> matchType;
	}
	string getmatchType() {
		return matchType;
	}
	void setT_name() {
		cout << "\nEnter Tournament name : ";
		cin >> tournamentName;
	}
	string getT_name() {
		return tournamentName;
	}
	void setcommentators() {
		cout << "\nEnter Match Commentators : ";
		cin >> commentators;
	}
	string getcommentators() {
		return commentators;
	}

	void setumpires() {
		cout << "\nEnter Match Umpires : ";
		cin >> umpires;
	}
	string getumpires() {
		return umpires;
	}


	void team1(int& score)
	{
		int temp = 0, b, count = 0;
		cout << "\n\nRuns Team 1 : ";
		for (int i = 0; i < 12; i++)
		{
			if (i % 3 == 0)
			{
				b = rand() % 2;
				if (b == 0)
				{
					cout << " OUT! ";
					count++;
					if (count == 10)
					{
						cout << " All players out ! ";
						break;
					}
					continue;

				}
				else
				{
					temp = rand() % 7;
				}
			}
			else
			{
				temp = rand() % 7;

			}
			cout << temp << " ";
			score = score + temp;

		}


	}

	void team2(int& score)
	{
		int temp = 0, b, count = 0;
		cout << "\n\nRuns Team 2 : ";

		for (int i = 0; i < 12; i++)
		{
			if (i % 3 == 0)
			{
				b = rand() % 2;
				if (b == 0)
				{
					cout << " OUT! ";

					count++;
					if (count == 10)
					{
						cout << " All players out ! ";
						break;
					}
					continue;
				}
				else
				{
					temp = rand() % 7;
				}
			}
			else
			{
				temp = rand() % 7;

			}
			cout << temp << " ";
			score = score + temp;
		}
	}

	int toss()
	{
		int choice, temp;

		cout << "\nPress 1 to do toss : ";
		cin >> choice;
		cout << "HEADS --- Team 1\nTAILS --- Team 2";
		temp = rand() % 2;

		if (temp == 0) {
			cout << "\n\nIts HEADS , Team 1 Won the Toss  ";
			return 0;
		}
		else {
			cout << "\n\nIts Tails , Team 2 Won the Toss  ";
			return 1;
		}

	}
	void winner(int score1, int score2) {
		if (score1 > score2)
		{
			cout << "\n\nTeam-1 is the winner" << endl;
		}
		else if (score1 < score2)
		{
			cout << "\n\nTeam-2 is the winner" << endl;
		}
		else {
			cout << "\n\nMatch has been drawn" << endl;
		}
	}
	void scheduleMatch() {
		Match obj1;

		ofstream myfile("abc.txt", ios::app
		);


		obj1.setdate();
		obj1.getdate();
		myfile << obj1.getdate() << endl;

		obj1.setvenue();
		obj1.getvenue();
		myfile << obj1.getvenue() << endl;

		obj1.setmatchType();
		obj1.getmatchType();
		myfile << obj1.getmatchType() << endl;

		obj1.setT_name();
		obj1.getT_name();
		myfile << obj1.getT_name() << endl;

		obj1.setcommentators();
		obj1.getcommentators();
		myfile << obj1.getcommentators() << endl;

		obj1.setumpires();
		obj1.getumpires();
		myfile << obj1.getumpires() << endl;

	}
};