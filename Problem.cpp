#include "Problem.h"
#include<iostream>
#include<iomanip>
#include<sstream>

constexpr int LINE_WIDTH=50;

Problem::Problem(): name(""),platform(""),topic(""),difficulty(""),solved(false),revCount(0),link(""){}

Problem::Problem(const std::string &name,const std::string &platform,const std::string &topic,const std::string &difficulty,bool solved,int revCount,const std::string &link):name(name),platform(platform),topic(topic),difficulty(difficulty),solved(solved),revCount(revCount),link(link){}

Problem::Problem(const std::string& name,const std::string& platform,const std::string& topic,const std::string& difficulty,const std::string& link):name(name),platform(platform),topic(topic),difficulty(difficulty),solved(false),revCount(0),link(link){}

void Problem::display() const{
    std::cout<<std::string(LINE_WIDTH,'-')<<std::endl;
    std::cout<<std::left<<std::setw(18)<<"Name"<<": "<<name<<std::endl;
    std::cout<<std::left<<std::setw(18)<<"Platform"<<": "<<platform<<std::endl;
    std::cout<<std::left<<std::setw(18)<<"Topic"<<": "<<topic<<std::endl;
    std::cout<<std::left<<std::setw(18)<<"Difficulty"<<": "<<difficulty<<std::endl;
    std::cout<<std::left<<std::setw(18)<<"Solved"<<": "<<((solved)?"Yes":"No")<<std::endl;
    std::cout<<std::left<<std::setw(18)<<"Revision Count"<<": "<<revCount<<std::endl;
    std::cout<<std::left<<std::setw(18)<<"Source Link"<<": "<<link<<std::endl;
    std::cout<<std::string(LINE_WIDTH,'-')<<std::endl;
}

std::string Problem::serialize() const{
    return name + "|" + platform + "|" + topic + "|" + difficulty + "|" + (solved?"1" : "0") + "|" + std::to_string(revCount) + "|" + link ;
}

void Problem::deserialize(const std::string& line){
    std::stringstream ss(line);
    std::string token;
    std::getline(ss,token,'|');
    name=token;
    std::getline(ss,token,'|');
    platform=token;
    std::getline(ss,token,'|');
    topic=token;
    std::getline(ss,token,'|');
    difficulty=token;
    std::getline(ss,token,'|');
    solved=(token=="1");
    std::getline(ss,token,'|');
    revCount=std::stoi(token);
    std::getline(ss,token,'|');
    link=token;
}

const std::string& Problem::getName() const{return name;}
const std::string& Problem::getPlatform() const{return platform;}
const std::string& Problem::getTopic() const{return topic;}
const std::string& Problem::getDifficulty() const{return difficulty;}
const std::string& Problem::getLink() const{return link;}
bool Problem::isSolved() const{return solved;}
int Problem::getRevisionCount() const{return revCount;}

void Problem::markSolved(){
    solved=true;
}

void Problem::incrementRevision(){
    revCount++;
}

