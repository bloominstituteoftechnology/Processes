1.
    If two processes attempt to open the file at the same time, they may end up overwriting each other.
    If two processes withdraw money at the same time (or if one process withdraws money after the second one's already done the check to see if there's enough money and the second one then withdraws when there are insufficient funds), it could cause an amount to be withdrawn from the account that was more than the account could handle.

2.
- The first argument to open() is the name of the file that needs to be opened for reading/writing.
- The second argument (O_CREAT|O_RDWR) is an OR condition, so two different options:
    - O_CREAT says that if the file does not already exist, create one, set the group to the parent of file's directory, the user ID to be the user ID of the process making the call, and set the permissions of the file to whatever the third argument in this function is.
    - O_RDWR opens the file for reading and writing (pretty self-explanatory).
- The third argument sets the permissions for the file - the first 0 sets the number to be an octal constant, the subsequent numbers actually refer to permission flags/bits.  The order for unix permissions is user/group/all users and the permission levels are read (4), write (2), execute (1), so user can read and write, group can read, and all users can read.

3.
    "Only have $10000, can't withdraw $15"
    "Only have $10000, can't withdra $8"
    "Only have $9992, can't withdraw $29"
    "Only have $0, can't withdraw $22"

    And then when I fixed it so it actually did what it should:
    The first withdraw hits before the first deposit is made.

