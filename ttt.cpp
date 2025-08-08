#include<iostream>
#include<ctime>
using namespace std;
void createboard(char*spaces);
void computermove(char*spaces,char computer);
void playermove(char*spaces,char player);
bool checkwinner(char*spaces,char computer,char player);
bool checktie(char*spaces);
int main()
{
    int px=0;
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running=true;
    createboard(spaces);
    while(running)
    {
        playermove(spaces, player);
        createboard(spaces);
        if (checkwinner(spaces, player,computer))
        {
          running=false;
          break;
        }
        else if(checktie(spaces))
        {
          running=false;
          break;
        }

        computermove(spaces, computer);
        createboard(spaces);
        if(checkwinner(spaces, player, computer))
        {
          running=false;
          break;
        }
        else if(checktie(spaces))
        {
          running=false;
          break;
        }
    }
    
    std::cout<<"thanks for playing!\n";
    return 0;
} 
void playermove(char*spaces,char player) 
{
    int number;
    do{
    std::cout<<"enter any spot (1-9): ";
    std::cin>>number;
    number--;
    if(spaces[number]==' ')
 {
    spaces[number]=player;
    break;

 }
    } while (!number>0 || !number<8);

}
void computermove(char *spaces,char computer)
{   
    int number;
     srand(time(0));
     while(true)
     {
        number=rand() % 9;
        if(spaces[number]==' ')
        {
            spaces[number]=computer;
            break;
        }
     }

}
bool checkwinner(char *spaces,char player,char computer)
{
  if((spaces[0]==spaces[1]) && (spaces[1]==spaces[2]) && (spaces[0]!=' '))
  {
    spaces[0]==player?
    std::cout<<"YOU WIN!\n":
    std::cout<<"YOU LOOSE!\n";
  }
  else if((spaces[3]==spaces[4]) && (spaces[4]==spaces[5]) && (spaces[3]!=' '))
  {
    spaces[3] == player?
    std::cout<<"YOU WIN!\n":
    std::cout<<"YOU LOOSE\n";
  }
  else if((spaces[6]==spaces[7]) && (spaces[7]==spaces[8]) && (spaces[6]!=' '))
  {
    spaces[6]==player?
    std::cout<<"YOU WIN!\n":
    std::cout<<"YOU LOOSE\n";
  }
  else if((spaces[0]==spaces[3]) && (spaces[3]==spaces[6]) && (spaces[0]!=' '))
  {
    spaces[0]==player?
    std::cout<<"YOU WIN\n":
    std::cout<<"YOU LOOSE\n";
  }
  else if((spaces[1]==spaces[4]) && (spaces[4]==spaces[7]) && (spaces[1]!=' '))
  {
    spaces[1]==player?
    std::cout<<"YOU WIN!\n":
    std::cout<<"YOU LOOSE!";
  }
  else if((spaces[2]==spaces[5]) && (spaces[5]==spaces[8]) && (spaces[2]!=' '))
  {
    spaces[2]==player?
    std::cout<<"YOU WIN!\n":
    std::cout<<"YOU LOOSE!\n";
  }
  else if((spaces[0]==spaces[4]) && (spaces[4]==spaces[8]) && (spaces[0]!=' '))
  {
    spaces[0]==player?

        std:: cout<<"YOU WIN!\n":
    
        std::cout<<"YOU LOOSE!\n";
    
  }
  else if((spaces[2]==spaces[4]) && (spaces[4]==spaces[6]) && (spaces[2]!=' '))
  {
    spaces[2]==player?
    
        std::cout<<"YOU WIN!\n":
        std::cout<<"YOU LOOSE!\n";
    
  }
  else{
    return false;
  }
  return true;
}
bool checktie(char *spaces)
{
  for(int i=0;i<9;i++)
  {
     if(spaces[i]==' ')
    {
        return false;
    }
  }
  std::cout<<"IT's A TIE!\n";
  return true;
}
void createboard(char*spaces)
{
    
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
