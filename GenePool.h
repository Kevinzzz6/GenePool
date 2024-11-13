#ifndef GENEPOOL_H
#define GENEPOOL_H

#include <string>
#include <map>
#include <vector>
#include "Person.h"
#include "DataCollectorCallback.h"

namespace cs32
{

// This is the database class you need to implement
// It stores a collection of people and supports lookup by name
// It reads people from a TSV file provided to the load method

class GenePool : public cs32::DataCollectorCallback
{
private:
    // Member Variables
    bool isLoaded;
    std::vector< cs32::Person * > people;
    
    // TODO establish every person's grandparents - grandfathers and grandmothers - in the database,
    //      if they are known
    void   findEveryonesSiblings() const;
    // TODO establish every person's siblings - brothers and sisters - in the database,
    //      if they are known
    void   findEveryonesGrandparents() const;
    // TODO establish every person's children - sons and daughters - in the database,
    //      if they are known
    void   findEveryonesChildren() const;
public:
    GenePool();
    
    // read the TSVFile, inflate the database and return the number of records read
    int load(const std::string& filePath);
    // has this GenePool been loaded with data?
    bool   loaded() const;
    
    // Clean it up
    ~GenePool();
    
    // clear this GenePool of all its data
    void   clear();
    // Converts a string (like "man") into one of the Gender enumerated values (like Gender::MAN)
    Gender toGender( std::string value ) const;

    // Returns a set with all the people in the database, if the database has been loaded with data
    std::set< cs32::Person * > everyone() const;
    
    // Find a person in the database by name, if the database has been loaded with data
    // Return nullptr if there is no such person
    cs32::Person * find(const std::string& name) const;
    
    // TODO this operation gets called over and over, once per line of data in the tsv data file
    //      from the map parameter, this operation should create a new Person and add it to the 
    //      people vector
    virtual void tsvData( std::map< std::string, std::string > row );
};

}

#endif
