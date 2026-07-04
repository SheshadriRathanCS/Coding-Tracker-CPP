#include "Tracker.h"
#include<iostream>
#include<string>

void displayMenu(){
    std::cout << "\n";
    std::cout << "========== Coding Tracker ==========\n";
    std::cout << "1. Add Problem\n";
    std::cout << "2. Delete Problem\n";
    std::cout << "3. Search Problem\n";
    std::cout << "4. Display All Problems\n";
    std::cout << "5. Display Statistics\n";
    std::cout << "6. Display Revision Problems\n";
    std::cout << "7. Mark Problem as Solved\n";
    std::cout << "8. Increment Revision Count\n";
    std::cout << "9. Exit\n";
    std::cout << "====================================\n";
    std::cout << "Enter your choice: ";
}

int main(){
    Tracker tracker;
    tracker.loadFromFile("Problems.txt");
    while (true){
        displayMenu();
        int choice;
        if (!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        switch (choice)
        {
            case 1:
            {
                std::cin.ignore();
                std::cout<<"Enter Problem Name : ";
                std::string name;
                std::getline(std::cin,name);
                if(tracker.searchProblem(name)!=nullptr){
                    std::cout<<"Problem already exists .\n";
                    break;
                }
                std::cout<<"Enter Platform : ";
                std::string platform;
                std::getline(std::cin,platform);
                std::cout<<"Enter Topic : ";
                std::string topic;
                std::getline(std::cin,topic);
                std::cout<<"Enter Difficulty : ";
                std::string difficulty;
                std::getline(std::cin,difficulty);
                std::cout<<"Enter problem link : ";
                std::string link;
                std::getline(std::cin,link);
                Problem problem(name,platform,topic,difficulty,link);
                tracker.addProblem(problem);
                tracker.saveToFile("Problems.txt");
                std::cout << "\nProblem added successfully!\n";
                break;
            }
            case 2 :
            {
                std::cin.ignore();
                std::string name;
                std::cout << "Enter Problem Name: ";
                std::getline(std::cin, name);
                if(tracker.deleteProblem(name)){
                    tracker.saveToFile("Problems.txt");
                    std::cout << "Problem deleted successfully!\n";
                }
                else std::cout<<"Problem not found.\n";
                break;
            }
            case 3 :
            {
                std::cin.ignore();
                std::cout << "Enter Problem Name: ";
                std::string name;
                std::getline(std::cin,name);
                Problem* problem=tracker.searchProblem(name);
                if(problem!=nullptr){
                    problem->display();
                }
                else std::cout<<"Problem not found !\n";
                break;
            }
            case 4:
            {
                tracker.displayAllProblems();
                break;
            }
            case 5 :
            {
                tracker.displayStatistics();
                break;
            }
            case 6 : 
            {
                tracker.displayRevisionProblems();
                break;
            }
            case 7 :
            {
                std::cin.ignore();
                std::cout<<"Enter Problem Name : ";
                std::string name;
                std::getline(std::cin,name);
                if(tracker.markProblemSolved(name)){
                    tracker.saveToFile("Problems.txt");
                    std::cout<<"Marked Successfully .\n";
                }
                else std::cout<<"Problem Not Found\n";
                break;
            }
            case 8 :
            {
                std::cin.ignore();
                std::cout<<"Enter Problem Name : ";
                std::string name;
                std::getline(std::cin,name);
                if(tracker.incrementProblemRevision(name)){
                    tracker.saveToFile("Problems.txt");
                    std::cout<<"Incremented Successfully.\n";
                }
                else std::cout<<"Problem Not Found\n";
                break;
            }
            case 9:
            {
                tracker.saveToFile("Problems.txt");
                std::cout << "Thank you for using Coding Tracker!\n";
                return 0;
            }
            default : 
            {
                std::cout << "Invalid choice! Please try again.\n";
                break;
            }
        }

    }
    return 0;
}