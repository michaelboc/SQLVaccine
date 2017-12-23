/**
 * @author       Michael Boc <mikeboc@me.com>
 * @since        12/23/2017
 *
 * This script builds the database that will store the training data.
*/


DROP DATABASE IF EXISTS SQLTrain;


-- Database to hold the frequency of a found words in dangerous queries
CREATE TABLE wordcount(
    word        varchar(20)         PRIMARY KEY,
    frequency   bigint unsigned
);

-- Procedure to update the word count table
DELIMITER $$
CREATE PROCEDURE updatefeq(IN word varchar(20))
BEGIN
    INSERT INTO wordcount values(word, 1)
        ON DUPLICATE KEY UPDATE frequency = frequency + 1;
END $$

-- Prodecure to provide the probability of the provided word
CREATE PROCEDURE findprob(IN word varchar(20), OUT prob()
