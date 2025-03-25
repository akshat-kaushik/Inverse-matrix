#include<stdio.h>
#include<math.h>

#define ROW 3
#define COL 3

int main()
{
    int i , j , d1 , d2 , d3 , cofactor[9];
    int matrix[ROW][COL] , determinant , adj[ROW][COL];
    int result , tempa , tempb ;
    int nomi , denomi , inverse[ROW][COL];

    printf("ENTER ELEMENTS OF MATRIX\n");
    for(i=0 ; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            printf("Matrix[%d%d]",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
    
    d1 = matrix[0][0]*((matrix[1][1]*matrix[2][2])-(matrix[2][1]*matrix[1][2]));
    d2 = matrix[0][1]*((matrix[1][0]*matrix[2][2])-(matrix[2][0]*matrix[1][2]));
    d3 = matrix[0][2]*((matrix[1][0]*matrix[2][1])-(matrix[2][0]*matrix[1][1]));

    determinant = d1 - d2 + d3 ;//TO FIND DETERMINANT
    if(determinant==0)//IF DETERMINENT IS ZERO NO SOLUTION POSSIBLE
    {
        printf("IT'S NOT INVERTABLE\n");
        return 1;
    }

    //TO FIND CO-FACTOR OF MATRIX
    cofactor[0] = (pow(-1,1+1))*((matrix[1][1]*matrix[2][2])-(matrix[2][1]*matrix[1][2]));
    cofactor[1] = (pow(-1,1+2))*((matrix[1][0]*matrix[2][2])-(matrix[2][0]*matrix[1][2]));
    cofactor[2] = (pow(-1,1+3))*((matrix[1][0]*matrix[2][1])-(matrix[2][0]*matrix[1][1]));
    cofactor[3] = (pow(-1,2+1))*((matrix[0][1]*matrix[2][2])-(matrix[2][1]*matrix[0][2]));
    cofactor[4] = (pow(-1,2+2))*((matrix[0][0]*matrix[2][2])-(matrix[2][0]*matrix[0][2]));
    cofactor[5] = (pow(-1,2+3))*((matrix[0][0]*matrix[2][1])-(matrix[2][0]*matrix[0][1]));
    cofactor[6] = (pow(-1,3+1))*((matrix[0][1]*matrix[1][2])-(matrix[1][1]*matrix[0][2]));
    cofactor[7] = (pow(-1,3+2))*((matrix[0][0]*matrix[1][2])-(matrix[1][0]*matrix[0][2]));
    cofactor[8] = (pow(-1,3+3))*((matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]));
    
    //TO FIND ADJACENT OF CO-FACTOR MATRIX
    adj[0][0] = cofactor[0] ;
    adj[0][1] = cofactor[3] ;
    adj[0][2] = cofactor[6] ;
    adj[1][0] = cofactor[1] ;
    adj[1][1] = cofactor[4] ;
    adj[1][2] = cofactor[7] ;
    adj[2][0] = cofactor[2] ;
    adj[2][1] = cofactor[5] ;
    adj[2][2] = cofactor[8] ;

    printf("INVERSE MATRIX:\n");
    
    for(i=0 ; i<3 ; i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            //IF DENOMINATOR IS ZERO 0 THEN IT WILL RETURN NUMINATOR
            if (determinant==0)
            {
                result = adj[i][j] ;
                goto label1;
            }
            tempa = adj[i][j];
            tempb = determinant;
            //TO FIND THE HCF (HIGHEST COMMON FACTOR)
            /*
                Working :
                a=12 , b=8 
                a%b = 12/8 = its remainder which is 4
                then 
                a=8 , b=4
                a%b = 8/4 = its remainder will be zero(0)
                so HCF = 4
            */
            label1:
            {
                result = tempa % tempb ;
                tempa = tempb ;
                tempb = result ;
            }
            if (result==0)
            {
                nomi = adj[i][j] / tempa;
                denomi = determinant / tempa;
                if(nomi==0)
                {
                    printf("%d   \t",nomi);
                }
                else if(denomi==1)
                {
                    printf("%d   \t",nomi);
                }
                else
                {
                    printf("%d/%d\t",nomi,denomi);
                }
            }
            else
            {
                goto label1;
            }
        }
        printf("\n");
    }
    return 0;
}