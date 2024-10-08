#include <stdio.h>
#include <conio.h>  // Pour _kbhit() et _getch()
#include <stdlib.h>


int debut = 0;

char StateTouche;

int life =1;
int size = 30;
int x =5;
int a;
int b;
int y=12;
int xFood=0;
int yFood=0;
int v=0;
char sizeSnake[1000];
int po = 0;
int matrixx[1000];
int matrixy[1000];
int avancée = 0;


//#########################
//#                       #
//#                 +     #
//#       +               #
//#                       #
//#  +         *          #
//#            *          #
//#      ******     +    #
//#                       #
//#########################

// pour crée le prgroma qui gere la taille il faut que je crée un tabelau qui prende la taille / par 10 snaleSize[size] puis il faut que chaque touche soit enregistrée et quand une nouvelle touche
// est tapée elle doit decalée tout la rangée puis aprée l'aog vas remonter selon les touche pour supprimer le * qui est hors taille du serpent pour mettre ' '

int matrix[10][25] = { {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},

                     };
void GameOver()
{
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||  GAME OVER  |||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||  Your score is %d  ||||||||||||||||\n",size);
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");

}

void Remove()
{
    if(avancée<(size/10))
    {
        matrix[5][12]=' ';

    }
    else
    {
        int X;
        int Y;
        X = matrixx[avancée-(size/10)] ;
        Y = matrixy[avancée-(size/10)];
        matrix[X][Y]=' ';
    }



}
void Affichage()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<25;j++)
        {
            printf("%c ",matrix[i][j]);
            if(j==24)
            {
                printf("\n");
            }
        }
}
//char z,char q, char s, char d, int score
void snake(char touche)
{

    if(debut==0)
    {
        matrix[5][12]='@';
        debut=1;

    }
    else
    {
        switch(touche)
        {
        case 'z':
            a=x;
            --x;
            matrixx[avancée]= x ;
            matrixy[avancée]= y;
            avancée++;

            if(matrix[x][y]=='+')
            {
                size += 10;
                v -= 1;
            }

            if(x==0|| matrix[x][y]=='*')
            {
                life=0;
                GameOver();
                break;
            }
            else
            {
                matrix[a][y]='*';
                matrix[x][y]='@';
                break;
            }

        case 's':
            a=x;
            ++x;
            matrixx[avancée]= x ;
            matrixy[avancée]= y;
            avancée++;


            if(matrix[x][y]=='+')
            {
                size += 10;
                v -= 1;
            }

            if(x==9|| matrix[x][y]=='*')
            {
                life=0;
                GameOver();
                break;
            }
            else
            {
                matrix[a][y]='*';
                matrix[x][y]='@';
                break;

            }
        case 'd':
            b=y;
            ++y;
            matrixx[avancée]= x ;
            matrixy[avancée]= y;
            avancée++;


            if(matrix[x][y]=='+')
            {
                size += 10;
                v -= 1;
            }

            if(y==25|| matrix[x][y]=='*')
            {
                life=0;
                GameOver();
                break;
            }
            else
            {

                matrix[x][b]='*';
                matrix[x][y]='@';
                break;
            }
        case 'q':
            b=y;
            --y;
            matrixx[avancée]= x ;
            matrixy[avancée]= y;
            avancée++;


            if(matrix[x][y]=='+')
            {
                size += 10;
                v -= 1;
            }

            if(y==0|| matrix[x][y]=='*')
            {
                life=0;
                GameOver();
                break;
            }
            else
            {
                matrix[x][b]='*';
                matrix[x][y]='@';
                break;
            }


        default:



        }
    }

    // Z pour monter, Q pour aller a gauche, d pour aller a droite et s pour descendre et si elle touche les bord allaros stop le jeu est print game over
    // Gerer la taille du serpent selon sont score
}

void food()
{

    xFood = rand()%7 +1 ;
    yFood = rand()%23 + 1;

    if(v<=5)
    {
        if(matrix[xFood][yFood]=='*')
        {
            xFood = rand()%7 +1 ;
            yFood = rand()%23 + 1;
        }else
        {
            matrix[xFood][yFood]='+';
            v=v+1;
        }
    }
    else
    {
        //matrix[xFood][yFood]=' ';
    }
    // il faut que ca soit plus grand que [0][**] et [**][25] et que il n'y est pas plus de 5 food sur la map
    // Crée une varaible Score pour afficher le score a la fin et l'enregeister dans un fichier txt pour faire une ledaear bord selon le nom du jouer

}

int main(void)
{
    while (life!=0)
    {
        if (_kbhit())
        {
            // Vérifie si une touche a été pressée

            //printf("Please enter a number: ");
            //scanf(" %c", &StateTouche);
            StateTouche = _getch(); // Récupère la touche pressée
            snake(StateTouche);
            printf("                                       Your score is : %d \n", size);
            Affichage();
            food(1);
            Remove();

        }
    }
    GameOver();
    return 0;
}