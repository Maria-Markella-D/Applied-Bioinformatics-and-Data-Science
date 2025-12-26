#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char seq[ 10000 ], decision[ 2 ], seq5_3[10000], seq2[10000], seq3[10000], seq2_5_3[10000], seq3_5_3[10000], seq3_5[10000];
	char start_codon_DNA[10000]="ATG", finish_codon_1_DNA[3]="TAA", finish_codon_2_DNA[3]="TGA", finish_codon_3_DNA[3]="TAG";
	char start_codon_RNA[10000]="AUG", finish_codon_1_RNA[3]="UAA", finish_codon_2_RNA[3]="UGA", finish_codon_3_RNA[3]="UAG";
	int len1,len2, len3, found_it, found_it_1, found_it_2, DNA_flag, RNA_flag, found_it_3;
	int i, k, a, b, j;

while(1)
    {
        printf("\33[1m" "\n***Assumption: There are no intrones***\n" "\33[0m");
        printf("\nEnter a nucleotide sequence: \n");
        scanf("%s", seq);

        len1 = strlen( seq );
        len2 = strlen( start_codon_DNA );
        len3 = strlen( start_codon_RNA );

        /************** Έλεγχος μήκους αλληλουχίας **************/

        /************** Δεδομένου ότι ιδανικά θα θέλαμε να δούμε κωδικονια έναρξης και λήξης και μια τουλάχιστον τριπλέτα στην αλληλουχία για να πούμε ότι είναι κωδικοποιούσα, επιλέχτηκε το 9 (3+3+3) **************/
        if( len1 < 9 )
        {
            printf("It can't be a prokaryotic coding sequence sequence. Try again please!\n\n");
            exit(1);
        }
        /************** Τέλος ελέγχου μήκους αλληλουχίας **************/
        for (i=0; i<len1; i++)
        {
            if(seq[i]=='\0' || seq[i]=='|' || seq[i]=='-' || seq[i]=='3' || seq[i]=='5')
            {
                seq[i]=seq[i++];
            }

        }

        DNA_flag=1;
        RNA_flag=1;


        /************** Έλεγχος είδους αλληλουχίας (DNA/RNA) **************/
        for (i=0; i<len1; i++)
        {
            if(seq[i]!='A' && seq[i]!='T' && seq[i]!='G' && seq[i]!='C')
            {
                DNA_flag=0;
            }
            if(seq[i]!='A' && seq[i]!='U' && seq[i]!='G'&& seq[i]!='C')
            {
                RNA_flag=0;
            }
        }
        /************** Τέλος ελέγχου είδους αλληλουχίας (DNA/RNA) **************/


        printf("\ndna %d\n",DNA_flag);
        printf("\nrna %d\n",RNA_flag);


        /************** Δημιουργία-προετοιμασία αλληλουχιών για το πλαίσιο 2 και 3 (προσανατολισμός 5'3') **************/
        for(i=0; i<len1-1; i++)
        {
            seq2[i]=seq[i+1];
        }

        for(i=0; i<len1-2; i++)
        {
            seq3[i]=seq[i+2];
        }
        /************** Τέλος Δημιουργίας-προετοιμασίας αλληλουχιών **************/


        printf("\nWhat is th direction of the sequence that you provided to us?\n");
        printf("Please enter '1' if the sequence has a 5' -> 3' direction\n");
        printf("Please enter '2' if the sequence has a 3' -> 5' direction\n");
        scanf("%s", decision);


        /************** ΠΡΟΣΑΝΑΤΟΛΙΣΜΟΣ 3'5' **************/
        if(decision[0]=='2')
        {
            /************** RNA **************/
            if(RNA_flag==1)
            {
                printf("\33[4m" "\33[1m" "\nTest for the given sequence with destination 5' - 3' instead of 3' - 5'" "\33[0m:\n");

                /************** Μετατροπή της αλληλουχίας 3'5' σε 5'3' **************/
                len1 = strlen( seq );
                for(i=0; i<len1; i++)
                {
                    for(j=len1-1; j>0; j--)
                    {
                        seq5_3[j-i]=seq[i];
                    }
                }

                printf("\nThe given sequence with destination 3' -> 5' is: \n");

                for(i=0; i<len1 ; i++)
                {
                    printf("%c", seq[i]);
                }

                printf("\n\nThe given sequence with destination 5' -> 3' is: \n");

                for(i=0; i<len1 ; i++)
                {
                    printf("%c", seq5_3[i]);
                }

            /************** Τέλος Μετατροπής σε 5'3' **************/


            /************** Δημιουργία-προετοιμασία αλληλουχιών για το πλαίσιο 2 και 3 (στη νέα αλληλουχία με προσανατολισμό 5'3') **************/
                for(i=0; i<len1-1; i++)
                {
                    seq2_5_3[i]=seq5_3[i+1];
                }

                for(i=0; i<len1-2; i++)
                {
                    seq3_5_3[i]=seq5_3[i+2];
                }
            /************** Τέλος Δημιουργίας-προετοιμασίας αλληλουχιών **************/

            /************** Έλεγχος για το 1ο πλαίσιο **************/
            /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\n\nFrame 1" "\33[0m:\n");
                len1 = strlen( seq5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len3-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len3 ; k++ )
                    {
                        if(seq5_3[ i+k ] != start_codon_RNA[ k ])
                        {
                            found_it = 0;
                        }

                         if( seq5_3[ i+k ] != finish_codon_1_RNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_2_RNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_3_RNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3 );
                        printf("Start Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Stop Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
                /************** Τέλος ελέγχου για το 1ο πλαίσιο **************/


                /************** Έλεγχος για το 2ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 2" "\33[0m:\n");
                len1 = strlen( seq2_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len3-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len3 ; k++ )
                    {
                        if(seq2_5_3[ i+k ] != start_codon_RNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_1_RNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_2_RNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_3_RNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4 );
                        printf("Start Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1 == 1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4 );
                        printf("Stop Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 2ο πλαίσιο **************/

            /************** Έλεγχος για το 3ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 3" "\33[0m:\n");
                len1 = strlen( seq3_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len3-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len3 ; k++ )
                    {
                        if(seq3_5_3[ i+k ] != start_codon_RNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_1_RNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_2_RNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_3_RNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5 );
                        printf("Start Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Stop Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 3ο πλαίσιο **************/

            }
            /************** Τέλος RNA **************/


            /************** DNA **************/
            if(DNA_flag==1)
            {
                printf("\33[4m" "\33[1m" "\nTest for the given sequence with destination 5' - 3' instead of 3' - 5'" "\33[0m:\n");

                /************** Μετατροπή της αλληλουχίας 3'5' σε 5'3' **************/
                len1 = strlen( seq );
                for(i=0; i<len1; i++)
                {
                    for(j=len1-1; j>0; j--)
                    {
                        seq5_3[j-i]=seq[i];
                    }
                }

                printf("\nThe given sequence with destination 3' -> 5' is: \n");

                for(i=0; i<len1 ; i++)
                {
                    printf("%c", seq[i]);
                }

                printf("\n\nThe given sequence with destination 5' -> 3' is: \n");

                for(i=0; i<len1 ; i++)
                {
                    printf("%c", seq5_3[i]);
                }

            /************** Τέλος Μετατροπής σε 5'3' **************/


            /************** Δημιουργία-προετοιμασία αλληλουχιών για το πλαίσιο 2 και 3 (στη νέα αλληλουχία με προσανατολισμό 5'3') **************/
                for(i=0; i<len1-1; i++)
                {
                    seq2_5_3[i]=seq5_3[i+1];
                }

                for(i=0; i<len1-2; i++)
                {
                    seq3_5_3[i]=seq5_3[i+2];
                }
            /************** Τέλος Δημιουργίας-προετοιμασίας αλληλουχιών **************/

            /************** Έλεγχος για το 1ο πλαίσιο **************/
                printf("\nWe have a DNA sequence\n");

                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 1" "\33[0m:\n");
                len1 = strlen( seq5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                         if( seq5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Start Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Stop Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 1ο πλαίσιο **************/


            /************** Έλεγχος για το 2ο πλαίσιο **************/

                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 2" "\33[0m:\n");
                len1 = strlen( seq2_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq2_5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Start Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1 == 1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Stop Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 2ο πλαίσιο **************/

            /************** Έλεγχος για το 3ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 3" "\33[0m:\n");
                len1 = strlen( seq3_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq3_5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Start Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Stop Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 3ο πλαίσιο **************/
                /************** Έλεγχος για την συμπληρωματική αλληλουχία 3ων σταδίων **************/
                printf("\33[4m" "\33[1m" "\nTest for the complementary sequence with destination (5' - 3')" "\33[0m:\n");
                /************** Δημιουργία συμπληρωματικής αλληλουχίας (Κατεύθυνση πλέον 5'3') **************/
                len1 = strlen( seq5_3 );
                for(i=0; i<len1; i++)
                {
                    if(seq[i]=='A')
                    {
                        seq5_3[i]='T';
                    }
                    if(seq[i]=='T')
                    {
                        seq5_3[i]='A';
                    }
                    if(seq[i]=='G')
                    {
                        seq5_3[i]='C';
                    }
                    if(seq[i]=='C')
                    {
                        seq5_3[i]='G';
                    }
                }
            /************** Τέλος δημιουργίας συμπληρωματικής αλληλουχίας **************/


            printf("\nThe given sequence with destination 3' -> 5' is: \n");

            for(i=0; i<len1 ; i++)
            {
                printf("%c", seq[i]);
            }

            printf("\n\nThe complementary sequence with destination 5' -> 3' is: \n");

            for(i=0; i<len1 ; i++)
            {
                printf("%c", seq5_3[i]);
            }

            /************** Τέλος Μετατροπής σε 5'3' **************/


            /************** Δημιουργία-προετοιμασία αλληλουχιών για το πλαίσιο 2 και 3 (στη νέα αλληλουχία με προσανατολισμό 5'3') **************/
            for(i=0; i<len1-1; i++)
            {
                seq2_5_3[i]=seq5_3[i+1];
            }

            for(i=0; i<len1-2; i++)
            {
                seq3_5_3[i]=seq5_3[i+2];
            }
            /************** Τέλος Δημιουργίας-προετοιμασίας αλληλουχιών **************/

            /************** Έλεγχος για το 1ο πλαίσιο **************/

                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\n\nFrame 1" "\33[0m:\n");
                len1 = strlen( seq5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                         if( seq5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Start Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Stop Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 1ο πλαίσιο **************/


            /************** Έλεγχος για το 2ο πλαίσιο **************/

                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 2" "\33[0m:\n");
                len1 = strlen( seq2_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq2_5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Start Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1 == 1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Stop Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 2ο πλαίσιο **************/

            /************** Έλεγχος για το 3ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 3" "\33[0m:\n");
                len1 = strlen( seq3_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq3_5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Start Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Stop Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
                /************** Τέλος ελέγχου για το 3ο πλαίσιο **************/
            }
            /************** Τέλος DNA **************/
        }
        /************** Τέλος ΠΡΟΣΑΝΑΤΟΛΙΣΜΟΣ 3'5' **************/



        /************** ΠΡΟΣΑΝΑΤΟΛΙΣΜΟΣ 5'3' **************/
        if(decision[0]=='1')
        {


            /************** RNA **************/
            if(RNA_flag==1)
            {
            /************** Έλεγχος για το 1ο πλαίσιο **************/
                printf("\nWe have a RNA sequence.\n");
                printf("\33[4m" "\33[1m" "\nTest for the given sequence with destination (5' - 3')" "\33[0m:\n");

                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 1" "\33[0m:\n");
                len1 = strlen( seq );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len3-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len3 ; k++ )
                    {
                        if(seq[ i+k ] != start_codon_RNA[ k ])
                        {
                            found_it = 0;
                        }

                         if( seq[ i+k ] != finish_codon_1_RNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq[ i+k ] != finish_codon_2_RNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq[ i+k ] != finish_codon_3_RNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Start Codon: '%c%c%c'\n", seq[i], seq[i+1], seq[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3 );
                        printf("Stop Codon: '%c%c%c'\n", seq[i], seq[i+1], seq[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
                /************** Τέλος ελέγχου για το 1ο πλαίσιο **************/


                /************** Έλεγχος για το 2ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 2" "\33[0m:\n");
                len1 = strlen( seq2 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len3-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len3 ; k++ )
                    {
                        if(seq2[ i+k ] != start_codon_RNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq2[ i+k ] != finish_codon_1_RNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq2[ i+k ] != finish_codon_2_RNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq2[ i+k ] != finish_codon_3_RNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Start Codon: '%c%c%c'\n", seq2[i], seq2[i+1], seq2[i+2]  );
                        b=0;
                    }

                    if(found_it_1 == 1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Stop Codon: '%c%c%c'\n", seq2[i], seq2[i+1], seq2[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 2ο πλαίσιο **************/

            /************** Έλεγχος για το 3ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 3" "\33[0m:\n");

                len1 = strlen( seq3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len3-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len3 ; k++ )
                    {
                        if(seq3[ i+k ] != start_codon_RNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq3[ i+k ] != finish_codon_1_RNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq3[ i+k ] != finish_codon_2_RNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq3[ i+k ] != finish_codon_3_RNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Start Codon: '%c%c%c'\n", seq3[i], seq3[i+1], seq3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5 );
                        printf("Stop Codon: '%c%c%c'\n", seq3[i], seq3[i+1], seq3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("\nWe didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 3ο πλαίσιο **************/
            }
            /************** Τέλος RNA **************/


            /************** DNA **************/
            if(DNA_flag==1)
            {

            /************** Έλεγχος για το 1ο πλαίσιο **************/
                printf("\nWe have a DNA sequence.\n");
                printf("\33[4m" "\33[1m" "\nTest for the given sequence with destination (5' - 3')" "\33[0m:\n");
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 1" "\33[0m:\n");

                len1 = strlen( seq );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                         if( seq[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+1 ,  i+3 );
                        printf("Start Codon: '%c%c%c'\n", seq[i], seq[i+1], seq[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d  \n", i+1, i+3 );
                        printf("Stop Codon: '%c%c%c'\n", seq[i], seq[i+1], seq[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 1ο πλαίσιο **************/


            /************** Έλεγχος για το 2ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 2" "\33[0m:\n");
                len1 = strlen( seq2 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 =1 ;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq2[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq2[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq2[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq2[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+2 ,  i+4 );
                        printf("Start Codon: '%c%c%c'\n", seq2[i], seq2[i+1], seq2[i+2]  );
                        b=0;
                    }

                    if(found_it_1 == 1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4 );
                        printf("Stop Codon: '%c%c%c'\n", seq2[i], seq2[i+1], seq2[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
                /************** Τέλος ελέγχου για το 2ο πλαίσιο **************/


            /************** Έλεγχος για το 3ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 3" "\33[0m:\n");len1 = strlen( seq3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5 );
                        printf("Start Codon: '%c%c%c'\n", seq3[i], seq3[i+1], seq3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Stop Codon: '%c%c%c'\n", seq3[i], seq3[i+1], seq3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
                /************** Τέλος ελέγχου για το 3ο πλαίσιο **************/

/************** Έλεγχος για την συμπληρωματική αλληλουχία 3ων σταδίων **************/
                printf("\33[4m" "\33[1m" "\nTest for the complementary sequence with destination (5' - 3')" "\33[0m:\n");
                /************** Δημιουργία συμπληρωματικής αλληλουχίας (Κατεύθυνση πλέον 3'5') **************/
                len1 = strlen( seq );
                for(i=0; i<len1; i++)
                {
                    if(seq[i]=='A')
                    {
                        seq3_5[i]='T';
                    }
                    if(seq[i]=='T')
                    {
                        seq3_5[i]='A';
                    }
                    if(seq[i]=='G')
                    {
                        seq3_5[i]='C';
                    }
                    if(seq[i]=='C')
                    {
                        seq3_5[i]='G';
                    }
                }
            /************** Τέλος δημιουργίας συμπληρωματικής αλληλουχίας **************/

            /************** Μετατροπή της αλληλουχίας 3'5' σε 5'3' **************/
            len1 = strlen( seq3_5 );
            for(i=0; i<len1; i++)
            {
                for(j=len1-1; j>0; j--)
                {
                    seq5_3[j-i]=seq3_5[i];
                }
            }

            printf("\nThe complementary sequence with destination 3' -> 5' is: \n");

            for(i=0; i<len1 ; i++)
            {
                printf("%c", seq3_5[i]);
            }

            printf("\n\nThe complementary sequence with destination 5' -> 3' is: \n");

            for(i=0; i<len1 ; i++)
            {
                printf("%c", seq5_3[i]);
            }

            /************** Τέλος Μετατροπής σε 5'3' **************/


            /************** Δημιουργία-προετοιμασία αλληλουχιών για το πλαίσιο 2 και 3 (στη νέα αλληλουχία με προσανατολισμό 5'3') **************/
            for(i=0; i<len1-1; i++)
            {
                seq2_5_3[i]=seq5_3[i+1];
            }

            for(i=0; i<len1-2; i++)
            {
                seq3_5_3[i]=seq5_3[i+2];
            }
            /************** Τέλος Δημιουργίας-προετοιμασίας αλληλουχιών **************/

            /************** Έλεγχος για το 1ο πλαίσιο **************/

                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\n\nFrame 1" "\33[0m:\n");
                len1 = strlen( seq5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                         if( seq5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Start Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+1 , i+3);
                        printf("Stop Codon: '%c%c%c'\n", seq5_3[i], seq5_3[i+1], seq5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 1ο πλαίσιο **************/


            /************** Έλεγχος για το 2ο πλαίσιο **************/

                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 2" "\33[0m:\n");
                len1 = strlen( seq2_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq2_5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq2_5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Start Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1 == 1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+2 , i+4);
                        printf("Stop Codon: '%c%c%c'\n", seq2_5_3[i], seq2_5_3[i+1], seq2_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
            /************** Τέλος ελέγχου για το 2ο πλαίσιο **************/

            /************** Έλεγχος για το 3ο πλαίσιο **************/
                /************** Για το formatting της printf βοηθήθηκα από το: https://www.youtube.com/watch?v=Pe6sMipTx5k **************/
                printf("\33[4m" "\33[1m" "\nFrame 3" "\33[0m:\n");
                len1 = strlen( seq3_5_3 );
                a=1;
                b=1;

                for( i=0 ;  i < len1-(len2-1) ; i=i+3 )
                {
                    found_it   = 1;
                    found_it_1 = 1;
                    found_it_2 = 1;
                    found_it_3 = 1;

                    for( k=0 ; k < len2 ; k++ )
                    {
                        if(seq3_5_3[ i+k ] != start_codon_DNA[ k ])
                        {
                            found_it = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_1_DNA[ k ])
                        {
                            found_it_1 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_2_DNA[ k ])
                        {
                            found_it_2 = 0;
                        }

                        if( seq3_5_3[ i+k ] != finish_codon_3_DNA[ k ])
                        {
                            found_it_3 = 0;
                        }
                    }

                    if( found_it == 1 )
                    {
                        a=1;
                        printf("\nPossible Start Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Start Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2]  );
                        b=0;
                    }

                    if(found_it_1==1 || found_it_2 == 1 || found_it_3==1 )
                    {
                        printf("\nPossible Stop Codon: \n");
                        printf("Possition: %d - %d \n", i+3 , i+5);
                        printf("Stop Codon: '%c%c%c'\n", seq3_5_3[i], seq3_5_3[i+1], seq3_5_3[i+2] );
                        a=0;

                        if (b==0 && a==0)
                        {
                            printf("\nThus, it is a simple/typical prokaryotic coding sequence\n");
                        }

                        if (b==1 && a==0)
                        {
                            printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                        }

                        b=1;
                    }
                }

                if (a==1 && b==0)
                {
                    printf("\nThus, it is not a simple/typical prokaryotic coding sequence\n");
                }

                if (a==1 && b==1)
                {
                    printf("We didn't find anything\n");
                }
                /************** Τέλος ελέγχου για το 3ο πλαίσιο **************/
            }
            /************** Τέλος DNA **************/
        }
        /************** Τέλος ΠΡΟΣΑΝΑΤΟΛΙΣΜΟΣ 5'3' **************/

    }
    /************** Τέλος While **************/

    a=1;
    b=1;
}
/************** ΤΕΛΟΣ **************/
