//
//  TSVFile.cpp
//  GenePool
//
//  Created by Howard Stahl on 7/1/23.
//

#include "TSVFile.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

namespace cs32
{

TSVFile::TSVFile( DataCollectorCallback * callback, bool hasHeaders, bool combineQuotedFields ) : mCollector( callback ), mHasHeaders( hasHeaders ), mCombineQuotedFields( combineQuotedFields ), debug( false )
{
    
}


int TSVFile::readFile( std::string filePath )
{
    using namespace std;
    
    vector< std::string > headers;
    vector< std::string > row;
    string line, word, nextword;
    bool ignoreFirstLine = mHasHeaders;    // since it is headers
    int  count = 0;                        // count records read
    
    fstream file( filePath.c_str(), ios::in );
    if(file.is_open())
    {
        while(getline(file, line))
        {
            
            if (debug)
                cout << "---> line:" << line << endl;
            
            if (line.length() == 0 || startsWith( line, "#" ) == true)
            {
                if (debug)
                    cout << "         ignore " << endl;
            }
            else
            {
                row.clear();
                
                count = count + 1;
                
                stringstream stream(line);
                
                while(getline(stream, word, '\t'))
                {
                    // if combining quote fields, commas found inside
                    // the quotes are not treated as separators
                    if (mCombineQuotedFields)
                    {
                        if (startsWith(word, "\""))
                        {
                            if (debug)
                                cout << "---> combine quote" << endl;
                            
                            // erase first character which is a "
                            word.erase(0, 1);
                            getline( stream, nextword, ',' );
                            
                            word += ",";
                            word += nextword;
                            
                            // erase last character if it is a "
                            // the endline character \r might get in the way...
                            if (endsWith(word, "\""))
                            {
                                word.erase(word.size() - 1, 1);
                            }
                            else if (endsWith( word, "\"\r" ))
                            {
                                word.erase(word.size() - 2, 2);
                            }
                        }
                    }
                    row.push_back(word);
                }
                
                if (debug)
                {
                    for(size_t i=0; i < row.size(); i++)
                    {
                        cout << "row- i=" << i << " " << row[i] << " ";
                    }
                    cout << endl;
                }
                
                if (ignoreFirstLine && count == 1)
                {
                    for(size_t i=0; i < row.size(); i++)
                    {
                        headers.push_back( row[i] );
                        if (debug)
                        {
                            cout << "header---> " << row[i] << endl;
                        }
                    }
                }
                else
                {
                    // build a map with the data
                    std::map< string, string > rowOfData;
                    // if header and row has different sizes, be careful!
                    size_t max = row.size();
                    if (row.size() > headers.size() && headers.size() != 0)
                    {
                        max = headers.size();
                    }
                    for(size_t i=0; i < max; i++)
                    {
                        if (mHasHeaders)
                            rowOfData[ headers[i] ] = row[i];
                        else
                            rowOfData[ "field" + std::to_string( i ) ] = row[ i ];
                    }
                    // invoke the callback sharing the data on thkis line
                    mCollector->tsvData( rowOfData );
                }
            }
        }
        file.close();
        if (ignoreFirstLine)
        {
            // the count will be one off
            // since it is counting the header when it should not
            count--;
        }
    }
    else
    {
        cerr << "Could not open the file: " << filePath << endl;
        count = -1;
    }
    return( count );
}

// does s start with the prefix value?
bool TSVFile::startsWith( const std::string& s, const std::string& value ) const
{
    bool result = false;
    if (s.size() >= value.size())
    {
        // null value will always return true
        result = true;
        for( size_t i = 0; i < value.size(); i++ )
        {
            if (s.at(i) != value.at(i))
            {
                result = false;
                break;
            }
        }
    }
    return( result );
}

// does s end with the suffix value?
bool TSVFile::endsWith( const std::string& s, const std::string& value ) const
{
    bool result = false;
    if (s.size() >= value.size())
    {
        // null value always returns true
        if (value.size() == 0)
        {
            result = true;
        }
        else
        {
            // unlike startsWith, we cannot count down to 0
            // expecting to stop at -1 because a size_t value
            // cannot be less than zero
            result = true;
            size_t i = value.length() - 1;
            size_t j = s.length() - 1;
            while( true )
            {
                if (s.at(j) != value.at(i))
                {
                    result = false;
                    break;
                }
                if (i == 0 || j == 0)
                {
                    // stop the loop since every character has been processed
                    break;
                }
                i--;
                j--;
            }
        }
    }
    return( result );
}

}
