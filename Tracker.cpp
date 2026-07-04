#include "Tracker.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<map>

void Tracker::addProblem(const Problem& problem){
    problems.push_back(problem);
}

void Tracker::displayAllProblems() const{
    if(problems.empty()){
        std::cout<<"No problems to display"<<std::endl;
        return ;
    }
    for(const auto& problem : problems){
        problem.display();
    }
}

Problem* Tracker::searchProblem(const std::string& name){
    for(auto& problem : problems){
        if(problem.getName()==name)return &problem;
    }
    return nullptr;
}

bool Tracker::deleteProblem(const std::string& name){
    for(auto it=problems.begin();it!=problems.end();++it){
        if(it->getName()==name){
            problems.erase(it);
            return true;
        }
    }
    return false;
}

int Tracker::countProblems() const{
    return problems.size();
}

int Tracker::countSolvedProblems() const{
    int count=0;
    for(const auto& problem:problems){
        if(problem.isSolved())count++;
    }
    return count;
}

int Tracker::countByTopic(const std::string& topic) const
{
    int count = 0;
    for (const auto& problem : problems)
    {
        if (problem.getTopic() == topic)++count;
    }

    return count;
}

void Tracker::displayStatistics() const{
    std::cout<<std::string(10,'=')<<" STATISTICS "<<std::string(10,'=');
    std::cout<<std::endl;
    std::cout<<std::endl;
    int total=countProblems();
    int solvedProblems=countSolvedProblems();
    int unsolved=total-solvedProblems;
    std::cout<<std::left<<std::setw(20)<<"Total Problems "<<": "<<total<<std::endl;
    std::cout<<std::left<<std::setw(20)<<"Solved Problems "<<": "<<solvedProblems<<std::endl;
    std::cout<<std::left<<std::setw(20)<<"Unsolved Problems "<<": "<<unsolved<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Problems by Topic"<<std::endl;
    std::cout<<std::string(17,'-')<<std::endl;
    std::map<std::string,int> topicMap;
    for(const auto& problem : problems)topicMap[problem.getTopic()]++;
    for(const auto& it : topicMap)std::cout<<std::left<<std::setw(10)<<it.first<<": "<<it.second<<std::endl;
    std::cout<<std::endl;
}

void Tracker::displayRevisionProblems() const{
    if(problems.empty()){
        std::cout<<"No problems available."<<std::endl;
        return;
    }
    bool found=false;
    for(const auto& problem : problems){
        if(problem.isSolved() && problem.getRevisionCount()==0){
            found=true;
            problem.display();
        }
    }
    if(!found)std::cout<<"No problems currently need revision."<<std::endl;
}

void Tracker::saveToFile(const std::string& fileName) const{
    std::ofstream fout(fileName);
    if(!fout){
        std::cerr<<"Error opening file : "<<fileName<<'\n';
        return ;
    }
    for(const auto& problem : problems){
        fout<<problem.serialize()<<'\n';
    }
    fout.close();
}

void Tracker::loadFromFile(const std::string& fileName){
    std::ifstream fin(fileName);
    if(!fin){
        std::cerr<<"Error opening file : "<<fileName<<'\n';
        return ;
    }
    problems.clear();
    std::string line;
    while(std::getline(fin,line)){
        Problem problem;
        problem.deserialize(line);
        problems.push_back(problem);
    }
    fin.close();
}

bool Tracker::markProblemSolved(const std::string& name){
    Problem* problem = searchProblem(name);
    if(problem == nullptr)return false;
    problem->markSolved();
    return true;
}

bool Tracker::incrementProblemRevision(const std::string& name){
    Problem* problem = searchProblem(name);
    if(problem == nullptr)return false;
    problem->incrementRevision();
    return true;
}

