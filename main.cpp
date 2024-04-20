#include<bits/stdc++.h> //to include all libraries in cpp.
#include"generalClass.h" //to include the general class we created.
using namespace std;

int main()
{
    std::ifstream inputFile("destinations.txt"); // Open the file which have the destinations

    if (!inputFile.is_open()){
        std::cerr << "Error opening the file  here you go." << std::endl;
        exit(0);}
    int choice ;
    std::cout<<"Dear user welcome to WestSideGroupTourAndTravelAgent please enter \n 1 To LOGIN in to your account\n 2 to SIGNUP for WestSideGroup as NEW USER \n 0 to exit WSGTTA System "<<endl<<"your choice :";
    std::cin>> choice;

    User user;
    Destination destinations;

   switch (choice)
    {
    case 1:
        user.login();
        destinations.displayDestinations();
        destinations.displayAirlines();
        destinations.searchHotels();
        break;

        break;

    case 2:
        user.registerUser();
        destinations.displayDestinations();
        destinations.displayAirlines();
        destinations.searchHotels();
        break;

    case 0:
        exit(0);
        break;
    default:
        std::cout<<"incorrect choice";
        exit(0);
        break;
    }


    return 0;

}
