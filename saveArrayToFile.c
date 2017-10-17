#include <stdio.h>
#include <time.h>

void generateNumbersToFile(FILE* f, unsigned int maxLines, unsigned int maxRows, unsigned int maxNumber){

    int i, numbers, counter = 0;

    for(numbers = 0; numbers < rand() % maxLines + 1; numbers++){
        for(i = 0; i < rand() % maxRows + 1; i++){
            fprintf(f , "%d ", rand() % maxNumber + 1);
            counter++;
        }
        fprintf(f, "#\n");
    }
    printf("Am generat %d numere, pe %d linii.\n", counter, numbers);
}

int main()
{

    unsigned int n, i, linesNumber = 0, numbers, biggestNumber = 0, nrNumbers = 0, fileNr = 0;
    char c;

    srand(time(NULL));


    FILE *f = fopen("saveit.txt", "a+");
    if (f == NULL){
        printf("Fisierul nu exista/nu a putut fi creat!\n");
        exit(1);
    }
    else{
        printf("Fisierul exista/a fost creat, urmeaza scrierea numerelor in el.\n");
    }

   generateNumbersToFile(f, 10000, 256, 250000);

    rewind(f);

    while( fscanf(f, "%d #", &fileNr) > 0){

        c = fgetc(f);
        if(c == '\n'){
           linesNumber++;
        }
        else
           nrNumbers++;

        if(fileNr > biggestNumber)
            biggestNumber = fileNr;
    }


    printf("Numar de linii in fisier: %d.\n", linesNumber);
    printf("Cel mai mare numar: %d.\n", biggestNumber);
    printf("Numarul numereleor: %d.\n", nrNumbers);

    return 0;
}
