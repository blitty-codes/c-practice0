#include "data.h"

int main(int argc, char **argv)
{
    int opt;
    LIST users;
    DATA user;
    FILE *db;

    initializeList(&users);

    if(!(db=fopen(argv[1], "r")))
    {
        printf("File (%s) can't be open\n", argv[1]);
        return 1;
    }

    readDataFile(db, &users);
    fclose(db);

    do
    {
        printf("1. Add user to list\n2. Read list\n3. Save users in db\n0. Exit\nOption: ");
        scanf("%d", &opt);
        fflush(stdin);
        switch (opt)
        {
            case 0:
                printf("Adieu.\n");
                break;

            case 1:
                printf("\nName: ");
                scanf("%s", user.name);
                fflush(stdin);
                printf("Last Name: ");
                scanf("%s", user.last_name);
                fflush(stdin);
                printf("Years: ");
                scanf("%d", &user.years);
                printf("\n");

                saveDataList(&users, user);
                break;
            
            case 2:
                readList(users);
                break;

            case 3:
                if(!(db=fopen(argv[1], "w")))
                {
                    printf("File (%s) can't be open\n", argv[1]);
                    return 1;
                }

                saveDataFile(db, users);
                fclose(db);
                printf("\nSaved db\n");
                break;

            default:
                printf("That option does not exist.\n");
        }
    } while (opt);
}