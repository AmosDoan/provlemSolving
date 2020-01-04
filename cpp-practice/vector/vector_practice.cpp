#include <iostream>
#include <vector>

#include <string.h>

const int NumOfUser = 6;

using namespace std;

struct UserInfo
{
    char acUserName[21];
    int Level;
    int Exp;
};

class GameRoomUser
{
    public :
        GameRoomUser()
        {
        }
        ~GameRoomUser()
        {
        }

        bool AddUser(UserInfo& tUserInfo);
        bool DelUser(char *pcUserName);
        UserInfo& GetUserOfName(char *pcName);
        UserInfo& GetUserOfLastOrder();
        bool BanUser(int OrderNum);
        void Clear();

    private :
        bool IsEmpty() const
        {
            return (Users.size() == 0);
        }

        bool IsFull() const
        {
            return (Users.size() > NumOfUser);
        }

        int getUserNumber() const
        {
            return Users.size();
        }

        vector<UserInfo> Users;
        char acMasterUserName[21];
};

bool GameRoomUser::AddUser(UserInfo& tUserInfo)
{
    int UserNum = getUserNumber();
    cout << "Number of User : " << UserNum << endl;
    if(IsFull())
    {
        cout << "6명 초과" << endl;
        return false;
    }

    if(IsEmpty())
    {
        strncpy(acMasterUserName, tUserInfo.acUserName, 
                sizeof(tUserInfo.acUserName));
        cout << "방장 : " << acMasterUserName << endl;
    }
    Users.push_back(tUserInfo);
    return true;
}

int main(int argc, char **argv)
{
    GameRoomUser game;
    UserInfo first {"DohanKim", 25, 30};

    game.AddUser(first);

    return 0;
}
