/**
 * @author       Michael Boc <mikeboc@me.com>
 * @since        12/21/2017
 *
 * This class parses the raw SQL data to train the logrithmic equation
*/



import java.util.Hashtable;



public class DataTrainer {


    // DataTrainer Variables
    private float b0;
    private float b1;
    private float b2;
    private long charcount;
    private Hashmap<char, long> charmap;


    // Initialize base values
    public DataTrainer() {
        this.b0 = 0;
        this.b1 = 0;
        this.b2 = 0;
        this.charcount = 0;
        this.charmap = new Hashmap<char, long>();
    }


    /**
    * This method opens a file, and calculates the frequency that particular   * characters are found in examples of sql injection.
    *
    * @param filename:  a string to the location of the training data
    * @return           scanner object to read the opened file
    */
    private static Scanner openFile( String filename ) {
        Scanner result = null;
        try {
            InputStream stream = new FileInputStream( filename );
            scanner = new Scanner( stream );
        }
        catch ( FileNotFoundException fnfe ) {
            System.err.println( fnfe );
            System.err.println( "File \"" + fileName + "\" does not exist." );
            System.exit( 1 );
        }
        return scanner;
    }


    /**
    * This method opens a file, and calculates the frequency that particular   * characters are found in examples of sql injection.
    *
    * @param trainer:   the object whose hashmap will be filled
    * @param filepath:  a string to the location of the training data
    * @return           null
    */
    public void ParseData( DataTrainer trainer, String filepath ){

        // Opens the file
        Scanner data = openFile( filepath );


    }




}
