#  Notes for Howard
# the query generator requires _ if the name has a space in it
# as in: Howard_Stahl  when the data file has a name of: Howard Stahl
#
# query commands include:
# everyone
# exit - from the main
# quit - from the main
# Once you've read in the entire data file, your program will prompt the user and then wait for input, which will come in this format (not all modifiers are valid for all relationships; see the next section for details):
# available relationships commands:
# parents sons daughters siblings grandmother grandfather grandparents
# brothers sisters
# [name]'s [parent-modifier] [sibling-modifier] [relationship]
#
#   •    name is the name of a person in the database; the 's is optional.
#    •    parent-modifier is an optional relationship modifier; it can be either maternal or paternal.
# Your program should parse the query, execute it against your database, and then print the result, listing the people it found in alphabetical order. If an error occurs, it should print the error message instead. Finally, it should re-print the prompt and wait for more input. Repeat this loop until you reach the end of the input stream.
# The logic to parse and validate queries is written for you (see the Query.* files), but you'll need to write the functions that do the actual lookups within your database (see the Person.* files).
#
# the datafiles got changed here to accommodate the updated genders
# datafiles must list parents before their children
# 


# gender choices are MAN  WOMAN   NONBINARY  PREFERNOTTOANSWER
# via man   woman   nonbinary    prefernottoanswer
