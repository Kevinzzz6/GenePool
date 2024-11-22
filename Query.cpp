#include "Query.h"

#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>

// This file provides query parsing and execution.
// You can edit it if you want, but you shouldn't need to.

namespace cs32
{

// Construct a query by parsing text
Query::Query(const std::string& text)
{
    std::istringstream stream(text);
    std::string term;
    
    read_term(stream, mName);
    
    // The everyone command is a special case:
    if (mName == "everyone")
    {
        if(stream >> term)
        {
            throw std::invalid_argument("Too many terms in query.");
        }
        
        mName = "Everyone";
        mRelationship = "everyone";
    }
    else
    {
        // Translate underscores to spaces
        std::replace(mName.begin(), mName.end(), '_', ' ');
        // Remove the possesive 's
        size_t pos = mName.length() - 2;
        if (mName.find("'s", pos) == pos)
        {
            mName = mName.substr(0, pos);
        }
        
        read_term(stream, term);
        mRelationship = term;
        if(stream >> term)
        {
            throw std::invalid_argument("Too many terms in query.");
        }
    }
}

Query::Query( )
{
    this->mName         = "";
    this->mRelationship = "";
}

// Construct a query directly
Query::Query(const std::string& name, const std::string& relationship)
{
    this->mName         = name;
    this->mRelationship = relationship;
}

// Helper function that throws an error if a read fails
void Query::read_term(std::istream& stream, std::string& term) {
    if (!(stream >> term)) {
        throw std::invalid_argument("Too few terms in query.");
    }
}


// Run a query against a gene pool
std::set< cs32::Person * > Query::run(const cs32::GenePool& pool) const
{
    std::set<cs32::Person*> result;
    if (mRelationship == "everyone") {
        result = pool.everyone();
    }
    else
    {
        Person* person = pool.find(mName);
        if (person == nullptr)
        {
            throw std::invalid_argument("No such person: " + mName);
        }
        else if (mRelationship == "parents")
        {
            result =( person->parents() );
        }
        else if (mRelationship == "brothers")
        {
            result = person->brothers();
        }
        else if (mRelationship == "children")
        {
            result = person->children();
        }
        else if (mRelationship == "daughters")
        {
            result = person->daughters();
        }
        else if (mRelationship == "father")
        {
            Person* father = person->getFather();
            
            if(father != nullptr)
            {
                result.insert(father);
            }
            result = result;
        }
        else if (mRelationship == "grandfathers")
        {
            result = person->grandfathers();
        }
        else if (mRelationship == "grandmothers")
        {
            result = person->grandmothers();
        }
        else if (mRelationship == "grandparents")
        {
            result = person->grandparents();
        }
        else if (mRelationship == "mother")
        {
            Person* mother = person->getMother();
            if(mother != nullptr)
            {
                result.insert(mother);
            }
            result = result;
        }
        else if (mRelationship == "siblings")
        {
            result = person->siblings();
        }
        else if (mRelationship == "sisters")
        {
            result = person->sisters();
        }
        else if (mRelationship == "sons")
        {
            result = person->sons();
        }
        else
        {
            throw std::invalid_argument("Unknown relationship: " + mRelationship);
        }
    }
    return result;
}

// Generate a query string:
std::string Query::to_string() const
{
    std::string result = mName + "'s ";
    result += mRelationship;
    return( result );
}

}

