#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <time.h>

// This is the file where we store the balance
#define BALANCE_FILE "balance.txt"

/**
 * Open the file containing the balance
 */
int open_balance_file(char *filename)
{
	// This line returns an open "file descriptor" (a number, how Unix
	// tracks open files) for both reading and writing. If the file does
	// not exist, it is created with 0644 permissions.
	return open(filename, O_CREAT|O_RDWR, 0644);
}

/**
 * Close the file containing the balance
 */
int close_balance_file(int fd)
{
	// Close the file descriptor
	return close(fd);
}

/**
 * Write the balance to the file
 */
void write_balance(int fd, int balance)
{
	// Print the balance into a buffer
	char buffer[1024];
	int size = sprintf(buffer, "%d", balance);

	// We want to replace the balance in the file with a new balance. To
	// do that, we first truncate the file to 0 bytes size, then move
	// the current read/write position to the start of the file.
	ftruncate(fd, 0);
	lseek(fd, 0, SEEK_SET);

	// Now we write the new balance
	int bytes_written = write(fd, buffer, size);

	// Make sure nothing went wrong
	if (bytes_written < 0) {
		// What does perror do? man 3 perror
		perror("write");
	}
}

/**
 * Read the balance from a file
 */
void read_balance(int fd, int *balance)
{
	char buffer[1024];

	// Seek to the beginning of the file, just in case we're not there
	// already:
	lseek(fd, 0, SEEK_SET);

	// Read the balance into a buffer
	int bytes_read = read(fd, buffer, sizeof buffer);
	buffer[bytes_read] = '\0';

	// Error check
	if (bytes_read < 0) {
		perror("read");
		return;
	}

	// Convert buffer to integer and store in balance
	*balance = atoi(buffer);
}

/**
 * Returns a random amount between 0 and 999.
 */
int get_random_amount(void)
{
	// vvvvvvvvvvvvvvvvvv
	// !!!! IMPLEMENT ME:

	// Return a random number between 0 and 999 inclusive using rand()
	return rand() % 1000;

	// ^^^^^^^^^^^^^^^^^^
}

/**
 * Main
 */
int main(int argc, char **argv)
{
	// Parse the command line
	
	// vvvvvvvvvvvvvvvvvv
	// !!!! IMPLEMENT ME:

	// We expect the user to add the number of simulataneous processes
	// after the command name on the command line.
	//
	// For example, to fork 12 processes:
	//
	//  ./bankers 12

	// Check to make sure they've added one paramter to the command line
	// with argc. If they didn't specify anything, print an error
	// message to stderr, and exit with status 1:
	//
	// "usage: bankers numprocesses\n"
	if (argc < 2)
	{
		fprintf(stderr, "usage: bankers numprocesses\n");
        exit(1);
	}

	// Store the number of processes in this variable:
	// How many processes to fork at once
	int num_processes;
	const char *str_processes = argv[1];
	sscanf(str_processes, "%d", &num_processes);

	// Make sure the number of processes the user specified is more than
	// 0 and print an error to stderr if not, then exit with status 2:
	//
	// "bankers: num processes must be greater than 0\n"
	if (num_processes <= 0)
	{
		fprintf(stderr, "bankers: numprocesses must be greater than 0\n");
		exit(2);
	}

	// ^^^^^^^^^^^^^^^^^^

	// Start with $10K in the bank. Easy peasy.
	int fd = open_balance_file(BALANCE_FILE);
	write_balance(fd, 10000);
	close_balance_file(fd);

	// Rabbits, rabbits, rabbits!
	for (int i = 0; i < num_processes; i++) {
		if (fork() == 0) {
			// "Seed" the random number generator with the current
			// process ID. This makes sure all processes get different
			// random numbers:
			srand(getpid());

			// Get a random amount of cash to withdraw. YOLO.
			int amount = get_random_amount();

			// if the amount is even, deposit the money instead of withdrawing
			if (amount % 2 == 0){
				amount = amount * -1;
			}

			int balance;

			// vvvvvvvvvvvvvvvvvvvvvvvvv
			// !!!! IMPLEMENT ME

			// Open the balance file (feel free to call the helper
			// functions, above).
			int bf = open_balance_file(BALANCE_FILE);

			flock(bf, LOCK_EX);

			// Read the current balance
			read_balance(bf, &balance);

			// Try to withdraw money
			//
			// Sample messages to print:
			//
			// "Withdrew $%d, new balance $%d\n"
			// "Only have $%d, can't withdraw $%d\n"

			int would_be_new_balance = balance - amount;
			if (would_be_new_balance < 0)
			{
				printf("Only have $%d, can't withdraw $%d\n", balance, amount);
			}
			else
			{
				// sleep so Windows does not automatically schedule them all in order
				sleep(1);

				// if amount is divisible by zero, simply check the balance without changing it
				if (amount % 5 == 0)
				{
					int check_balance;
					read_balance(bf, &check_balance);
					printf("Checked balance, it is $%d\n", check_balance);
				}
				else
				{
					write_balance(bf, would_be_new_balance);

					int new_balance;
					read_balance(bf, &new_balance);

					// if the amount was negative, it was deposted. Else, it was withdrawn.
					if (amount < 0){
						printf("Deposited $%d, new balance $%d\n", amount * -1, new_balance);
					}
					else
					{
						printf("Withdrew $%d, new balance $%d\n", amount, new_balance);
					}
				}
			}

			flock(bf, LOCK_UN);

			// Close the balance file
			//^^^^^^^^^^^^^^^^^^^^^^^^^^
			close_balance_file(bf);

			// Child process exits
			exit(0);
		}
	}

	// Parent process: wait for all forked processes to complete
	for (int i = 0; i < num_processes; i++) {
		wait(NULL);
	}

	return 0;
}
