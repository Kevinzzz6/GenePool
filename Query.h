#ifndef QUERY_H
#define QUERY_H

#include "Enums.h"
#include "GenePool.h"
#include "Person.h"
#include <string>

// This file provides query parsing and execution
// CS 32 students should not need to make any changes here

namespace cs32
{

class Query
{
private:
    std::string mName;
    std::string mRelationship;
    
    void read_term(std::istream& stream, std::string& term);

public:
    Query();
    Query(const std::string& text);
    Query(const std::string& name, const std::string& relationship);
    
    // runs this query against the GenePool parameter provided
    // returns the set of Person matching the desired relationship
    std::set< cs32::Person * > run(const cs32::GenePool& pool) const;
    // prints this Query in textual form:   Howard's parents
    std::string to_string() const;
};

}

#endif
