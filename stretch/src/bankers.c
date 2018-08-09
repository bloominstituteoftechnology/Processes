#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <time.h>

#define BALANCE_FILE "balance.txt"

/**
 * Open the file containing the balance
 */
int open_balance_file(char *filename)
{
	return open(filename, O_CREAT|O_RDWR, 0644);
}

/**
 * Close the file containing the balance
 */
int close_balance_file(int fd)
{
	return close(fd);
}

/**
 * Write the balance to the file
 */
void write_balance(int fd, int balance)
{
  char buffer[1024];
  int size = sprintf(buffer, "%d", balance);   // Print the balance into a buffer
  ftruncate(fd, 0);                            // Truncate file to 0 bytes
  lseek(fd, 0, SEEK_SET);                      // Move r/w position to start
  int bytes_written = write(fd, buffer, size); // Now we write the new balance

	if (bytes_written < 0) {
		perror("write");
	}
}

/**
 * Read the balance from a file
 */
void read_balance(int fd, int *balance)
{
	char buffer[1024];
  lseek(fd, 0, SEEK_SET);                           // Move r/w position to start
  int bytes_read = read(fd, buffer, sizeof buffer); // Read the balance into a buffer
  buffer[bytes_read] = '\0';

	if (bytes_read < 0) {
		perror("read");
		return;
	}

  *balance = atoi(buffer); // Convert buffer to integer and store in balance
}

/**
 * Withdraw amount from balance
 */
void withdraw(int fd, int amount, int *balance)
{
  if (amount <= *balance)
  {
    *balance = *balance - amount;
    write_balance(fd, *balance);
    printf("Withdrew $%d, new balance $%d\n", amount, *balance);
  }
  else
  {
    printf("Only have $%d, can't withdraw $%d\n", amount, *balance);
  }
}

/**
 * Deposit amount into balance
 */
void deposit(int fd, int amount, int *balance){
  *balance = *balance + amount;
  write_balance(fd, *balance);
  printf("Deposited $%d, new balance $%d\n", amount, *balance);
}

/**
 * Get current balance
 */
void get_balance(int balance){
  printf("Checking balance, current balance $%d\n", balance);
}

/**
 * Returns a random amount between 0 and 999.
 */
int get_random_amount(void)
{
  return rand() % 1000;
}

/**
 * Returns a random amount between 1 and 3.
 */
int get_random_action(void){
  return rand() % 3 + 1;
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("usage: bankers numprocesses\n");
    exit(1);
  }
  else if (atoi(argv[1]) <= 0)
  {
    fprintf(stderr, "bankers: num processes must be greater than 0\n");
    exit(2);
  }

  int num_processes = atoi(argv[1]);
  int fd = open_balance_file(BALANCE_FILE);
  write_balance(fd, 10000);
	close_balance_file(fd);

  for (int i = 0; i < num_processes; i++) {
  	if (fork() == 0) {
      srand(getpid()); // "Seed" rand number generator to ensure unique values per process
      int amount = get_random_amount();
      int action = get_random_action();
      int bf = open_balance_file(BALANCE_FILE);
      int balance;
      flock(bf, LOCK_EX);
      read_balance(bf, &balance);

      switch (action)
      {
        case 1:
          withdraw(bf, amount, &balance);
          break;
        case 2:
          deposit(bf, amount, &balance);
          break;
        case 3:
          get_balance(balance);
          break;
        }

        close_balance_file(bf);
        flock(bf, LOCK_UN);
        exit(0); // Child process exits
    }
  }

  // Parent process: wait for all forked processes to complete
  for (int i = 0; i < num_processes; i++) {
  	wait(NULL);
  }

  return 0;
}
