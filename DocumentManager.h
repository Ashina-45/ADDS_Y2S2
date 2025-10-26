#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
private:
    struct Document {
        std::string name;
        int id = 0;
        int license_limit = 0;
        int borrowed_count = 0;
    };

    std::unordered_map<int, Document> docs_;
    std::unordered_map<std::string, int> name_to_id_;
    std::unordered_set<int> patrons_;
    std::unordered_map<int, std::unordered_set<int>> loans_;

public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(const std::string& name) const;
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
};

#endif