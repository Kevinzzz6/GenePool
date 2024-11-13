#include "GenePool.h"
#include "Person.h"
#include "TSVFile.h"
#include <string>


namespace cs32
{

GenePool::GenePool() : isLoaded( false )
{
    
}

// has this GenePool been loaded with data?
bool GenePool::loaded() const
{
    return( false );
}

// clear this GenePool of all its data
void GenePool::clear()
{
    if (loaded())
    {
        while (!people.empty())
        {
            Person * p = people.back();
            people.pop_back();
            delete( p );
        }
    }
    isLoaded = false;
}

// read the TSVFile, inflate the database and return the number of records read
int GenePool::load( const std::string& filePath )
{
    isLoaded = true;
    TSVFile file( this );
    int recordCount = file.readFile( filePath );
    if (recordCount == 0)
    {
        isLoaded = false;
        // i suppose you could throw an exception to communicate no records read...
    }
    // once everyone is loaded individually, then establish the additional relationships
    //      namely siblings, grandparents and children
    findEveryonesSiblings();
    findEveryonesGrandparents();
    findEveryonesChildren();
    return( recordCount );
}

// TODO establish every person's grandparents - grandfathers and grandmothers - in the database,
//      if they are known
void   GenePool::findEveryonesGrandparents() const
{

}

// TODO establish every person's siblings - brothers and sisters - in the database,
//      if they are known
void GenePool::findEveryonesSiblings() const
{

}

// TODO establish every person's children - sons and daughters - in the database,
//      if they are known
void GenePool::findEveryonesChildren() const
{

}

// TODO this operation gets called over and over, once per line of data in the tsv data file
//      from the map parameter, this operation should create a new Person and add it to the 
//      people vector
void GenePool::tsvData( std::map< std::string, std::string > row )
{
    
}

// Converts a string (like "man") into one of the Gender enumerated values (like Gender::MAN)
Gender GenePool::toGender( std::string value ) const
{
    Gender result( Gender::PREFERNOTTOANSWER );
    if (value == "man")
    {
        result = Gender::MAN;
    }
    else if (value == "woman" )
    {
        result = Gender::WOMAN;
    }
    else if (value == "nonbinary" )
    {
        result = Gender::NONBINARY;
    }
    return( result );
}

// Clean it up
GenePool::~GenePool()
{
    while (!people.empty())
    {
        Person * p = people.back();
        people.pop_back();
        delete( p );
    }
}

// Returns a set with all the people in the database, if the database has been loaded with data
std::set<cs32::Person*> GenePool::everyone() const
{
    std::set< Person * > set;
    if (loaded())
    {
        for( std::vector< Person * >::const_iterator iter = people.begin(); iter != people.end(); iter++)
        {
            Person * p = *iter;
            set.insert( p );
        }
    }
    return( set );
}

// Find a person in the database by name, if the database has been loaded with data
// Return nullptr if there is no such person
cs32::Person* GenePool::find(const std::string& name) const
{
    Person * result = nullptr;
    if (loaded())
    {
        for( std::vector< Person * >::const_iterator iter = people.begin(); iter != people.end(); iter++)
        {
            Person * p = *iter;
            if (p->getName() == name)
            {
                result = p;
                break;
            }
        }
    }
    return( result );
}

}
