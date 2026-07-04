#ifndef TRACKER_H
#define TRACKER_H

#include"Problem.h"
#include<vector>
#include<string>

class Tracker {
private:
    std::vector<Problem> problems;

public:
    void addProblem(const Problem& problem);
    bool deleteProblem(const std::string& name);
    Problem* searchProblem(const std::string& name);
    void displayAllProblems() const;
    void displayRevisionProblems() const;
    int countProblems() const;
    int countSolvedProblems() const;
    void displayStatistics() const;
    int countByTopic(const std::string& topic) const;
    void saveToFile(const std::string& fileName) const;
    void loadFromFile(const std::string& fileName);
    bool markProblemSolved(const std::string& name);
    bool incrementProblemRevision(const std::string& name);
};

#endif