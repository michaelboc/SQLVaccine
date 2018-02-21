//
// Author:      Michael Boc <mikeboc@me.com>
// Version:     Feb-21-2018
// Filename:    DataTrainer.c
//
// This source file contains the implementation of a program, which will recieve
// training data populate a database, and use that database to generate
// parameters for the logarithmic regression formula.
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///


#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

#define BUFF_SIZE 256
#define DB_NAME "SQLTrain"


// This function reads a file with training data, and then uses the data to
// update a mySQL database. The training data should be examples of SQL
// injection techniques.
//
// Param:   dataFile    A file path to the SQL training data
// Param:   conn        A connection to a mySQL database
void readTrainData( char* filename, MYSQL* conn ) {
    // Create a buffer on the stack to store the training data
    FILE* dataFile = fopen( filename, "r" );
    unsigned char buffer[ BUFF_SIZE ];

    while( fgets( buffer, BUFF_SIZE, dataFile ) ) {
        // Delimit the input via whitespace to get the SQL keywords
        char* SQLToken = strtok( buffer, " " );
        while( SQLToken != NULL ) {
            // Build the query, and then execute it
            unsigned char query[ BUFF_SIZE ];
            sprintf( query, "CALL updateFreq(\"%s\");", SQLToken );
            if( mysql_query( conn, query ) ){
                // Print any errors, and quit program
                fprintf( stderr, "%s\n", mysql_error( conn ) );
                mysql_close( conn );
                exit( EXIT_FAILURE );
            }
            // Get the next SQL word
            SQLToken = strtok( NULL, " \n" );
        };
    }
}


// Main function
//
// Param:   arg[1]  filepath to the training data
// Param:   arg[2]  network path the the mySQL server
// Param:   arg[3]  username for the mySQL server
// Param:   arg[4]  password for the mySQL server
int main( int argc, char* argv[] ) {

    // Create the connection with the mySQL server
    MYSQL* conn = mysql_init( NULL );
    if( !mysql_real_connect(conn, argv[2], argv[3], argv[4], DB_NAME, 0, NULL,
                0) ) {
        // Print any errors, and quit program
        fprintf( stderr, "%s\n", mysql_error(conn) );
        mysql_close( conn );
        exit( EXIT_FAILURE );
    }

    // Read the file and update the database
    readTrainData( argv[1], conn );
    exit( EXIT_SUCCESS );
}
