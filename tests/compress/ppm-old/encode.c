/* Encodes the input file. */
#include "stdio.h"
#include "model.h"
#include "arithcode.h"

void report_model(); /* Report back on stats collected from the model */

void report()
{
    double CR;

    fprintf( stderr, "PPM* : %ld bytes", cmpbytes );
    if (rawbytes != 0) {
	CR = (double) cmpbytes / (double) rawbytes;
	fprintf( stderr, ", %4.2f bpc, CF=%4.2f", CR*8, 1/CR );
    }
    fprintf( stderr, "\n");
    fprintf( stderr, "\n");
    /*report_model();*/
}

void encode_file(fp)
FILE *fp;
{
    int cc;

    init_symbols();


    startoutputingbits();
    startencoding();

    loadInput( fp, 0, NO_PRELOAD_LIMIT );
    rawbytes=lengthInput();

    while ((cc = getInput()) >= 0) {
	encode_symbol( cc, 0 );
    }
    encode_symbol( eof_symbol(), 0 );
    
    doneencoding();
    doneoutputingbits();
}

int main(argc,argv)
int argc;
char *argv[];
{
    argv++;
    argv++;
    if (argc > 2)
	init_arguments(argc,argv,3);

    encode_file( stdin );

    report();
    return 0;
}
