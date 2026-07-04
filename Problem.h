#ifndef PROBLEM_H
#define PROBLEM_H

#include<string>

class Problem{
private:
    std::string name;
    std::string platform;
    std::string topic;
    std::string difficulty;
    bool solved;
    int revCount;
    std::string link;

public: 
    Problem();
    Problem(const std::string &name,const std::string &platform,const std::string &topic,const std::string &difficulty,bool solved,int revCount,const std::string &link);
    Problem(const std::string& name,const std::string& platform,const std::string& topic,const std::string& difficulty,const std::string& link);
    void display() const;
    std::string serialize() const;
    void deserialize(const std::string& line);
    const std::string& getName() const;
    const std::string& getPlatform() const;
    const std::string& getTopic() const;
    const std::string& getDifficulty() const;
    const std::string& getLink() const;
    bool isSolved() const;
    int getRevisionCount() const;
    void markSolved();
    void incrementRevision();
};

#endif
