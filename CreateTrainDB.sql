/**
 * Author:      Michael Boc <mikeboc@me.com>
 * Version:     Feb-21-2017
 *
 * This script builds the database that will store the training data.
*/


DROP DATABASE IF EXISTS SQLTrain;
Create DATABASE SQLTrain;
USE SQLTrain;


-- Database to hold the frequency of a found words in dangerous queries
CREATE TABLE wordcount(
    word        varchar(20)         PRIMARY KEY,
    frequency   bigint unsigned
);


-- Procedure to update the word count table
DELIMITER $$
CREATE PROCEDURE updateFreq( IN word varchar(20) )
BEGIN
    INSERT INTO wordcount values(word, 1)
        ON DUPLICATE KEY UPDATE frequency = frequency + 1;
END $$
DELIMITER ;
