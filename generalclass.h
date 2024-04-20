#include<bits/stdc++.h>
#include<map>
using namespace std;
bool aborter = true; // used to control condition where user want to exit.or to make independent function depend on the first executed
int skipper;   //used for skipping lines in reading hotels.
int forairline,forhotel; // used to store price of airline and hotel to use later in other function.
double forcity;      //ratio of life expectancy in each city.

class User {   //deal with user i.e registration and login authentication.

  public:
string email,dateOfBirth,name;
string password, phoneNumber;
char alpha;
 void registerUser() // this prompt new user to enter their name their password and save this information
 {
      if (::aborter) {       //condition to be checked.

ofstream write("puthere.txt",ios::app);//create file called puthere.txt or if it exist append on it

    array<string,4>value; //individual information of user stored here ie array of strings
    string key;       //name of each individual user stored separately  here ie string
    correctusername:
        cout<<"please create your user name:";
        std::cin>>name;
        std::string s = name;
        if (s.find('*') != std::string::npos){   //check if * is found in user name.
            std::cout<<"Invalid user name * is not allowed \n please re-enter your name\n"; // if * found
            goto correctusername;            }
        else{
            name[0] = toupper(name[0]); //if not
            key = name;
            ; }

        cout<<"Create your Password :";
        cin>>password;
        cout<<"Enter your Phone number :";
        cin>>phoneNumber;
        cout<<"Your email address please";
        cin>>email;
        cout<<"Your Birth date please:";
        cin>>dateOfBirth;

    value[0] = password;  value[1] = phoneNumber;
    value[2] = email;  value[3] = dateOfBirth;
    write<<name<<" ";
    for (int i =0; i<4; i++)
    {
      write<<value[i]<<" ";
    }
    write<<endl;
write.close();
ifstream file("puthere.txt",ios::app);  // Open the input file to add raw data of new user


    map<char, map<string, vector<string>>> charMap;  // Create a nested map to store characters, words, and associated vectors of words
    string line;  // Variable to store each line read from the file
    string word;  // Variable to store each word extracted from the line
    char firstChar;  // Variable to store the first character of each line

    if (file.is_open()) {  // Check if the file was opened successfully
        while (getline(file, line)) {  // Read each line from the file
            if (line.length() >= 2) {  // Check if the line has a length of at least 2 characters
                firstChar = line[0];  // Extract the first character of the line
                istringstream iss(line);
                iss >> word;   // Extract the word from the line

                map<string, vector<string>>& wordMap = charMap[firstChar];  // Access the word map associated with the first character

               // Create a string stream to split the word into individual words
                vector<string> words((istream_iterator<string>(iss)), istream_iterator<string>());  // Split the word into individual words and store them in a vector

                wordMap[word] = words;  // Associate the vector of words with the word in the word map
            }
        }

        file.close();  // Close the file after reading

        ofstream write("database.txt");//open text file called database to store organized information of user

        for (const auto& entry : charMap) {  // Iterate over each character entry in the character map
            write << entry.first << endl;  // Write the current character

            const map<string, vector<string>>& wordMap = entry.second;  // Access the word map associated with the current character
            for (const auto& wordEntry : wordMap) {  // Iterate over each word entry in the word map
                write << wordEntry.first <<endl;  // Write the current word

                const vector<string>& words = wordEntry.second;  // Access the vector of words associated with the current word
                for (const auto& w : words) {  // Iterate over each word in the vector
                    write << w << " ";  // Print each word followed by a space
                }
                write <<endl;  // Print a newline character to separate the sets of words
            }
            write << endl;  // Print an extra newline character to separate the character sets
        }
        cout<<"Dear "<<name<<"! You are successfully registered as \nWestSideGroupTourAndTravelAgent User!!";
    }
     else {
        cout << "Failed to open the file." << endl;// Print an error message if the file fails to open
        ::aborter = false;
        exit(0);

        }

 }}
 int login() // to securely authenticate user info.
 {
     if (::aborter) //condition
     {


      ifstream file("puthere.txt",ios::app);  // Open the input file

    map<char, map<string, vector<string>>> charMap;  // Create a nested map to store characters, words, and associated vectors of words
    string line;  // Variable to store each line read from the file
    string word;  // Variable to store each word extracted from the line
    char firstChar;  // Variable to store the first character of each line

    if (file.is_open()) {  // Check if the file was opened successfully
            ::aborter = true;


        while (getline(file, line)) {  // Read each line from the file
            if (line.length() >= 2) {  // Check if the line has a length of at least 2 characters
                firstChar = line[0];  // Extract the first character of the line
                istringstream iss(line);
                iss >> word;   // Extract the word from the line

                map<string, vector<string>>& wordMap = charMap[firstChar];  // Access the word map associated with the first character

               // Create a string stream to split the word into individual words
                vector<string> words((istream_iterator<string>(iss)), istream_iterator<string>());  // Split the word into individual words and store them in a vector


                wordMap[word] = words;  // Associate the vector of words with the word in the word map

            }
        }

        file.close();  // Close the file after reading
        char your;
        string name, passer;

        namecorrect:
            cout<<"Please enter your User  name or 0 to exit \n Your choice : ";
            cin>>name;
            if(name == "0"){
                ::aborter = false; exit(0);
                }
            name[0] = toupper(name[0]);


           your = name[0];

              ::aborter = false;
            for (const auto& entry : charMap) {  // Iterate over each character entry in the character map
               if(your == entry.first)  //chek if first character of username already exist
               {
                const map<string, vector<string>>& wordMap = entry.second;// Access the word map associated with the current character
                for (const auto& wordEntry : wordMap)   // Iterate over each word entry in the word map
                {
                        if (name == wordEntry.first ) //check if username already exist
                        {

                            correctpassword:
                                cout<<"Please enter your Password or 0 to exit \n your choice :";
                                cin>>passer;
                                ::aborter = true;
                                const vector<string>& words = wordEntry.second;  // Access the vector of words associated with the current word
                            if (passer ==  words[0])  // Check if password is correct
                            {
                                ::aborter = true;
                                cout<<"\n Dear "<<name<<"!, you are successfully logged in to your account!";
                                break;
                            }
                            else if(passer == "0"){
                                                 ::aborter = false;
                                                  exit(0);
                                                }
                            else
                            {
                              cout<<"Incorrect password please try again!\n";
                              goto correctpassword;

                            }
                }
                else{cout<<"sorry! you are not registered yet \n or your user name is in correct \n Please try again \n "; goto namecorrect;}
            //::aborter = true;
            }
           }
    }
    }
    else {
        cout << "Failed to open the file." << endl;  // Print an error message if the file fails to open
          ::aborter = false;
        return 1;  // Return a non-zero value to indicate failure
    }
 }
return 0;}
};



class Destination {
  public:
  void displayDestinations() //display the destination available
  {
      if(::aborter){
    int dest,usinp;
    ::aborter = true;
        cout<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n where you want to visit?\n \t please enter"
        <<"\n||*******************************************************************************************************************||"
        <<"\n|| 1:Agra       \t|| 2:Bangkok         \t|| 3:Beijing      \t||4:Berlin           \t||5:Cairo            ||"
        <<"\n|| 6:Cape Town  \t|| 7:Copenhagen      \t|| 8:Dubai        \t||9:Dubrovnikn       \t||10:Edinburg        ||"
        <<"\n|| 11:Florence  \t|| 12:Hanoi          \t|| 13:Havana      \t||14:Istanbul        \t||15:Jerusalem       ||"
        <<"\n|| 16:Kyiv      \t|| 17:Kyoto          \t|| 18:Lisbon      \t||19:Marrakech       \t||20:MExico          ||"
        <<"\n|| 21:Mumbai    \t|| 22:Nairobi        \t|| 23:Osaka       \t||24:Paris           \t||25:Prague          ||"
        <<"\n|| 26:Reykjavic \t|| 27:Rio de janerio \t|| 28:Rome        \t||29:St.petersburg   \t||30:Seoul           ||"
        <<"\n|| 31:Singapore \t|| 32:Stokholm       \t|| 33:Sydney      \t||t34:Tokyo          \t||35:Toront          ||"
        <<"\n|| 36:Vienna    \t|| 37:Zurich         \t||              0 TO EXIT FROM SYSTEM                                ||"
        <<"\n||*******************************************************************************************************************||\nYour choice:";
    cin>>usinp;
   double payment[37] ={0.7,0.9,0.89,1.2,0.5,0.55,1.0,0.75,0.93,0.87,1.1,1.6,1.4,1.5,0.67,0.7,0.8,0.9,1.3,0.89,0.789,2.0,0.77,0.98,0.79,0.55,0.67,0.88,0.98,0.65,0.89,1.4,1.7,1.34,1.0,2.0,1.32};
          ::forcity = payment[usinp-1];

    if(usinp == 0)
    {::aborter = false; exit(0);}
    ::skipper = (usinp-1) * 4;//to read hotels in display hotel function
    dest = usinp - 1 +(usinp - 1) * 5;//to read destination
    std::ifstream inputFile("destinations.txt"); // Open the file which have the destinations

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file  here you go." << std::endl;
        ::aborter = false;
        exit(0);

    }

    int linesToSkip = dest ;        //The number of lines you want to skip
    int linesToReadBetween = 5; // The number of lines you want to read between the skipped lines

    // Skip lines
    for (int i = 0; i < linesToSkip; ++i) {
        std::string line;
        if (!getline(inputFile, line)) {
            std::cerr << "SORRY!!We won\'t travel to that place." ;
            ::aborter = false;
            std::cout<<::aborter;
            exit(0);

        }
    }

    // Read and print the specified number of lines between skipped lines
    for (int i = 0; i < linesToReadBetween; ++i) {
        std::string line;
        if (getline(inputFile, line)) {
                ::aborter = true;
            std::cout << line << std::endl;
        } else {
            std::cerr << "Error reading the file!" << std::endl;
            ::aborter = false;
            exit(0);

        }
    }

    // Close the file
    inputFile.close();

  }
 // Member variables and functions for Destination class

}

void displayAirlines()
  {
      if(::aborter){
    int usinp,dest;
    cout<<"\n \tPlease prefer your airline"
        <<"\n[^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^]"
        <<"\n[1 Japan Airlines.\t2Singapore Airlines. \t3 Qatar Airways.     \t4 Korean Air. ]"
        <<"\n[5 Vistara.       \t6 All Nippon Airways.\t7 Ethiopian Airlines.\t8 Air India.  ]\n"
        <<"[\t 0 To exit from system                                                        ]"
        <<"\n[^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^]\n";
     int payair[8]={2000,2500,3600,2000,3900,1900,1250,1500};

        corr:

        std::cout<<"Your choice:";
        std::cin>>usinp;
        ::forairline = payair[usinp-1];

    if(usinp == 0)
    {::aborter = false; exit(0);}
    dest = usinp - 1;
    //::skipper = dest;

    std::ifstream inputFile("flight.txt"); // Open the file which have the destinations

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        ::aborter = false; exit(0);

    }

    int linesToSkip = dest ;        //The number of lines you want to skip
    int linesToReadBetween = 1; // The number of lines you want to read between the skipped lines

    // Skip lines
    for (int i = 0; i < linesToSkip; ++i) {
        std::string line;
        if (!getline(inputFile, line)) {
            std::cerr << "SORRY!!We won\'t travel by that air lines." << std::endl;
            goto corr;

        }
    }

    // Read and print the specified number of lines between skipped lines
    for (int i = 0; i < linesToReadBetween; ++i) {
        std::string line;
        if (getline(inputFile, line)) {
                int time,day,month,year,temp ;
                std::string timearound;
                std::cout<<"please arrenge your flight time !\n year:";
            ye:
                std::cin>>temp;
                if(temp == 2023 || temp == 2024)
                {
                    year = temp;

                }
                else{std::cout<<"Sorr'y we can't arrange flight in that year please reenter your choice\n year:";
                     goto ye;
                     }

            mo:
                std::cout<<"Month:";
                std::cin>>temp;
                if(temp<=12 && temp>=1)
                {
                    month = temp;

                }
                else{
                       std::cout<<"Incorrect month please re-enter your choice\n";
                       goto mo;
                    }

            da:
                std::cout<<"Day: ";
                std::cin>>temp;
                if(temp<=30 && temp>=1)
                {
                    day = temp;

                }
                else{
                     std::cout<<"Incorrect day please re-enter the choice!\n";
                     goto da;
                    }
            ti:
                std::cout<<" 1:Morning\n 2:Afternoon\n";
                std::cin>>time;
                if(time==1){
                    timearound = "Morning";

                          }
                else if(time == 2){
                         timearound = "Afternoon";
                                  }
                else{cout<<"error occurred re-enter\n"; goto ti; }


            std::cout <<"We will arrange your flight with "<< line << std::endl
                      <<"On "<<day<<"/"<<month<<"/"<<year<<" In the "<<timearound
                      <<"\nWe Wish you good flight with "<<line<<std::endl;
            ::aborter = true;


        } else {
            std::cerr << "Error We don't have such airline." << std::endl;
            goto corr;

        }
    }

    // Close the file
    inputFile.close();
  }
  else{::aborter = false; exit(0);}

  }



  void searchHotels()
  {   if(::aborter){
      struct Data {
    std::string line1;
    std::string line2;
    std::string line3;
    std::string line4;
            int line5;
};

    string filename = "hotels.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        ::aborter = false;
        exit(0);
    }
    int skipLines = ::skipper;

    std::string line;
    for (int i = 0; i < skipLines; ++i)
        std::getline(file, line);  // Skip lines

    Data data;
    std::getline(file, data.line1);
    std::getline(file, data.line2);
    std::getline(file, data.line3);
    std::getline(file, data.line4);




    // Print the stored lines
    std::cout <<"best hotels in " << data.line1 << std::endl;
    std::cout << "Hotel 1 : " << data.line2 << std::endl;
    std::cout << "Hotel 2: " << data.line3 << std::endl;
    std::cout << "Hotel 3: " << data.line4 << std::endl;

   int choice;
   std::cout<<"\t Where do you want to rest? \n";
   string hotels[4];
   hotelchoice:
       std::cout<<"\t your choice: ";
       std::cin>>choice;
       if(choice<=3 && choice>=1){
       hotels[0] = data.line1;
       hotels[1] = data.line2;
       hotels[2] = data.line3;
       hotels[3] = data.line4;
                                 }
        else{std::cout<<"incorrect choice please re-enter your choice\n";
             goto hotelchoice;
             }



    int payhot[3]={200,150,100};
    int days;
    std::cout<<"How many days you stay there?\n your choice";
    std::cin>>days;
    ::forhotel = payhot[choice]*days;
    double totalExpense;
    totalExpense = (::forcity * ::forairline) + (::forcity * ::forhotel);
    int checker;
    std::cout<<"your total expense is "<<totalExpense<<" USD. do you want to continue? \n 1:yes\t 2:no \n";
    std::cin>>checker;

    if(checker == 1)
    std::cout<<"Your room is reserved at :"<<hotels[choice]<<" for "<<days<<" days\n  Have a nice time";
    else
       std::cout<<"Your process is canceled have a good day";

file.close();

  }}



};


