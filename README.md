Setups to run program:
1)
The file found at http://ourairports.com/data/ needs to be saved in project directory.
2)
The function LoadData in main, inserts only the large airports into the large_airport_lst.

Run the program:
1)
The menu options
(1) Create your profile
(2) Make a flight reservation
(3) Print confirmation
(4) Exit

2)
Program logic
A profile must be created first.
Then a reservation can be made with the client_nbr from the previous step. Valid airport codes most be entered (for example: 5360, 5388, 5433)
Then a confirmation can be printed, using the client_nbr from first step. The reservation associated with a client_nbr will be printed. Since a user can have multiple reservations. Next step, is to enter the reservation_nbr, this will print the reservation details.
Finally, the program can be exited by entering 4 or the steps 1,2,3 can be repeated.


Error Checking:
1)
No error checking is included in this version of the project.
2)
No checks are in place for retrieving from STL, so for example if a key is not in the program will crash.

