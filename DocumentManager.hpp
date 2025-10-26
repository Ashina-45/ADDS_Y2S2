#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
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
    void addDocument(std::string name, int id, int license_limit) {
        auto it = docs_.find(id);
        if (it == docs_.end()) {
            docs_.emplace(id, Document{name, id, license_limit, 0});
        } else {
    
        }
        name_to_id_[name] = id;
    }

    void addPatron(int patronID) { patrons_.insert(patronID); }

    int search(const std::string& name) const {
        auto it = name_to_id_.find(name);
        return (it == name_to_id_.end()) ? 0 : it->second;
    }

    bool borrowDocument(int docid, int patronID) {
        if (!patrons_.count(patronID)) return false;
        auto it = docs_.find(docid);
        if (it == docs_.end()) return false;

        Document& d = it->second;
        if (d.borrowed_count >= d.license_limit) return false;
        auto& setRef = loans_[patronID];
        if (setRef.count(docid)) return false;
        setRef.insert(docid);
        ++d.borrowed_count;
        return true;
    }

    void returnDocument(int docid, int patronID) {
        auto pit = loans_.find(patronID);
        if (pit == loans_.end()) return;
        auto& setRef = pit->second;
        if (!setRef.erase(docid)) return;

        auto dit = docs_.find(docid);
        if (dit != docs_.end() && dit->second.borrowed_count > 0) {
            --(dit->second.borrowed_count);
        }
    }
};
